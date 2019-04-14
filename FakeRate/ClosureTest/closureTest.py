import ROOT
import numpy as np

lumi = 35545.499064
output_dir = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/ClosureTest'

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',          action='store',         default='DYJetsToLL_M-50')
argParser.add_argument('--subJob',              action='store',         default=0)
argParser.add_argument('--inputFile',           action='store',         default='inputFiles')
argParser.add_argument('--isTest',              action='store',         default=False)
argParser.add_argument('--isCheck',             action='store',         default=False) #Check needs to be finished

args = argParser.parse_args()

#Load in samples
import Sample
if not args.isCheck:
    sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/'+args.inputFile+'.conf')
else:
    sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/'+args.inputFile+'.conf', skipFaultyFiles=True)
sample = Sample.getSampleFromList(sampleList, args.sampleName)
output_dir = output_dir + '/' + sample.output + '/' + sample.name + '_subJob_'+ str(args.subJob) 

#Initialize chain
Chain = sample.initTree()

#Initialize fake rate
from fakeRate import fakeRate
FR = fakeRate()

#Initialize histograms
from histogram import histogram
hist = []

#Initialize SF
from tauEnergyScale import tauEnergyScale
tauES = tauEnergyScale('2016', 'ReReco')

#Initialize output
if not args.isCheck:
    categories = ['Categ_C', 'Categ_D', 'Categ_E', 'Categ_F']
else:
    categories = ['Check']

hist = []
for cat in categories:
    tmp = []
    if not args.isCheck:
        tmp.append(histogram(cat+ '_pt_tau', (18, 20., 200.), output_dir))
        tmp.append(histogram(cat+ '_eta_tau', (10, -2.5, 2.5), output_dir))
        tmp.append(histogram(cat+ '_met', (10, 50., 300.), output_dir))
        tmp.append(histogram(cat+ '_Mll', (14, 0., 210.), output_dir))
    else:
        tmp.append(histogram(cat+ '_pt_tau', np.array([20., 25., 35., 50., 70., 100.]), output_dir, customBins=True))
        tmp.append(histogram(cat+ '_eta_tau', np.array([0., 0.5, 1., 1.5, 2., 2.5]), output_dir, customBins=True))
    hist.append(tmp)

#Determine if testrun so it doesn't need to calculate the number of events in the getEventRange (current bottleneck)
if args.isTest:
    eventRange = xrange(2000)
else:
    eventRange = sample.getEventRange(int(args.subJob))

import eventSelection
import objectSelection
from helpers import progress, makeDirIfNeeded
#Loop over events
for entry in eventRange:

    progress(entry, len(eventRange))
    Chain.GetEntry(entry)

    lIndex = eventSelection.getLepIndices(Chain)

    if len(lIndex) != 3: continue

    nLooseTau = eventSelection.numberOfTaus(Chain, lIndex)

    lVec = eventSelection.getFourVectors(Chain, tauES, lIndex)

    category = 0
    if not args.isCheck:
        if eventSelection.passedCategC(Chain, lIndex, nLooseTau):
            category = 0
            var = fill_single_tau_vars(Chain, lVec)
        elif eventSelection.passedCategD(Chain, lIndex, nLooseTau):
            category = 1
            var = fill_single_tau_vars(Chain, lVec)
        elif eventSelection.passedCategE(Chain, lIndex, nLooseTau):
            category = 2
            var = fill_single_tau_vars(Chain, lVec)
        elif eventSelection.passedCategF(Chain, lIndex, nLooseTau):
            category = 3
            var = fill_two_tau_vars(Chain, lVec)
        else:
            continue
    else:
        if not eventSelection.passedCheck(Chain, lIndex, nLooseTau, lVec):      continue


    #getting fake factor like this is probably overly complicated -> replace
    nTightTau = 0
    weights = []
    for i, l in enumerate(lIndex):
        if Chain._lFlavor[l] == 2:
            if Chain._lPOGTight[l]:
                weights.append(1.)
                nTightTau += 1.
            else:
                weights.append(FR.getFakeFactor(lVec[i].Pt(), abs(lVec[i].Eta())))

    fake_factor = -999.
    if nTightTau == 2:
        pass
    elif nTightTau == 1:
        if nLooseTau == 2: fake_factor = weights[0]*weights[1]
        elif nLooseTau == 1: pass
    elif nTightTau == 0:
        if nLooseTau == 2: fake_factor = -1.*weights[0]*weights[1]
        elif nLooseTau == 1: fake_factor = weights[0]

    weightfactor = Chain._weight*((sample.xsec*lumi)/sample.hCount)
    
    for v, h in zip(var, hist[category]):
        if isinstance(v, tuple):
            for _ in v:
                h.fill(_, weightfactor, fake_factor)
        else:
            h.fill(v, weightfactor, fake_factor)

if not args.isTest:
    for h in hist:
        for subh in h:
            subh.write_hist()
