import ROOT
import numpy as np

lumi = 35545.499064
output_dir = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/Data'

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',          action='store',         default='DYJetsToLL_M-50')
argParser.add_argument('--subJob',              action='store',         default=0)
argParser.add_argument('--year',                action='store',         default='2016')
argParser.add_argument('--isTest',              action='store',         default='')
argParser.add_argument('--isCheck',             action='store',         default='') #Check needs to be finished
argParser.add_argument('--inData',              action='store',         default='') 

args = argParser.parse_args()
print 'Loading in samples'

#Load in samples
import Sample
if not args.isCheck:
    sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/Data/inputFiles_'+args.year+'.conf')
else:
    sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/inputFiles_'+args.year+'.conf')

sample = Sample.getSampleFromList(sampleList, args.sampleName)
if args.inData:
    inData_Str = 'DATA'
else:
    inData_Str = 'MC'
output_dir = output_dir + '/'+ args.year + '/' + inData_Str+ '/' + sample.output + '/' + sample.name + '_subJob_'+ str(args.subJob) 

#Initialize chain
print 'Initializing chain'
if not args.isCheck:    Chain = sample.initTree()
else:    Chain = sample.initTree(needhCount=False)
print 'Chain initialized'

#Initialize fake rate
from fakeRate import fakeRate
FR = fakeRate(inData_Str, args.year)

#Check if sample is data and if we will need a prompt tau (for prompt contribution to data)
import eventSelection
isData = eventSelection.isData(args.sampleName)
needPromptTau = args.inData and not isData

#Initialize SF
from tauEnergyScale import tauEnergyScale
tauES = tauEnergyScale(args.year)

from tauIDSF import tauIDSF
tauSF = tauIDSF()

from puReweighting import getReweightingFunction
puReweighting     = getReweightingFunction(data="PU_2016_36000_XSecCentral")

print 'Getting things ready to start the event loop'
#Initialize output
if not args.inData:
    if not args.isCheck:
        categories = ['Categ_C', 'Categ_D', 'Categ_E', 'Categ_F']
    else:
        categories = ['Check']
else:
    categories = ['inData']

#Initialize histograms
from histogram import histogram
hist = []

for cat in categories:
    tmp = []
    if not args.isCheck:                        #This is done both if inData and not
        tmp.append(histogram(cat+ '_ptTau', (20, 20., 90.), output_dir))
        tmp.append(histogram(cat+ '_etaTau', (10, -2.5, 2.5), output_dir))
        tmp.append(histogram(cat+ '_met', (30, 0., 300.), output_dir))
        tmp.append(histogram(cat+ '_Mll', (15, 75., 105.), output_dir))
    else:
        tmp.append(histogram(cat+ '_ptTau', np.array([20., 25., 35., 50., 70., 100.]), output_dir, customBins=True))
        tmp.append(histogram(cat+ '_etaTau', np.array([0., 0.5, 1., 1.5, 2., 2.5]), output_dir, customBins=True))
    hist.append(tmp)

#Determine if testrun so it doesn't need to calculate the number of events in the getEventRange (current bottleneck)
if args.isTest:
    eventRange = xrange(5000)
else:
    eventRange = sample.getEventRange(int(args.subJob))

import objectSelection
from helpers import progress, makeDirIfNeeded, showBranch
#Loop over events
for entry in eventRange:

    progress(entry-eventRange[0], len(eventRange))
    Chain.GetEntry(entry)

    lIndex = eventSelection.getLepIndices(Chain, needPromptTau)

    if len(lIndex) != 3: continue

    nLooseTau = eventSelection.numberOfTaus(Chain, lIndex)
    nTightTau = eventSelection.numberOfTightTaus(Chain, lIndex)
    
    lVec = eventSelection.getFourVectors(Chain, tauES, lIndex)

    category = 0 
    if not args.inData:
        if not args.isCheck:
            if eventSelection.passedCategC(Chain, lIndex, nLooseTau, nTightTau):
                category = 0
                var = eventSelection.fill_single_tau_vars(Chain, lVec)
            elif eventSelection.passedCategD(Chain, lIndex, nLooseTau, nTightTau):
                category = 1
                var = eventSelection.fill_single_tau_vars(Chain, lVec)
            elif eventSelection.passedCategE(Chain, lIndex, nLooseTau, nTightTau):
                category = 2
                var = eventSelection.fill_single_tau_vars(Chain, lVec)
            elif eventSelection.passedCategF(Chain, lIndex, nLooseTau, nTightTau):
                category = 3
                var = eventSelection.fill_two_tau_vars(Chain, lVec)
            else:
                continue
        else:
            if not eventSelection.passedCheck(Chain, lIndex, nLooseTau, lVec):      continue
            var = []
            var.append(lVec[2].Pt())
            var.append(lVec[2].Eta())
    else:
        if not eventSelection.passedControlRegion(Chain, lIndex, nLooseTau, lVec):      continue
        var = eventSelection.fill_single_tau_vars(Chain, lVec)

    fake_factor = FR.getFakeWeight(Chain, lVec, lIndex, nLooseTau)

    if not args.isCheck and not isData:  weightfactor = Chain._weight*((sample.xsec*lumi)/sample.hCount)
    else:       weightfactor = 1.

    if not isData:
        weightfactor *= puReweighting(Chain._nTrueInt)
        if fake_factor == -999.:
            weightfactor *= tauSF.getSF(args.year, 'Tight')[0]
        else:
            weightfactor *= tauSF.getSF(args.year, 'VLoose')[0]

    #print weightfactor    
    for v, h in zip(var, hist[category]):
        if isinstance(v, tuple):
            for _ in v:
                h.fill(_, weightfactor, fake_factor)
        else:
            h.fill(v, weightfactor, fake_factor)

print hist[0][0].get_histogram().GetSumOfWeights()

if not args.isTest:
    for h in hist:
        for subh in h:
            subh.write_hist()
