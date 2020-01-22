import ROOT
import numpy as np

output_dir = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/Data'

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',          action='store',         default='DYJetsToLL_M-50',      help='Name of sample as specifiec in input file. Default is DYJetsToLL_M-50')
argParser.add_argument('--subJob',              action='store',         default=0,                      help='Index of subjob. Default is 0')
argParser.add_argument('--year',                action='store',         default='2016',                 help='Year of datataking (2016, 2017, 2018)')
argParser.add_argument('--inData',              action='store_true',                                    help='Perform closure test in data CR or not') 
argParser.add_argument('--isTest',              action='store_true',                                    help='Perform local run on limited number of events')
argParser.add_argument('--isCheck',             action='store_true',                                    help='Perform a check in the same CR as used in fake rate measurement') #Check needs to be finished

args = argParser.parse_args()
print 'Loading in samples'


if args.year == '2016':
    lumi = 35545.499064
elif args.year == '2017':
    lumi = 41859.4
else:
    lumi = 59970
#Load in samples

import Sample
if not args.isCheck:
    sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/Data/inputFiles_'+args.year+'.conf')
else:
    sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/inputFiles_'+args.year+'.conf')

#Get specific sample for this subjob
sample = Sample.getSampleFromList(sampleList, args.sampleName)

#Set output directory and filename
if args.inData:
    inData_Str = 'DATA'
else:
    inData_Str = 'MC'
output_dir = output_dir + '/'+ args.year + '/' + inData_Str+ '/' + sample.output + '/' + sample.name + '_subJob_'+ str(args.subJob) 

#Initialize chain
print 'Initializing chain'
if not args.isCheck:    Chain = sample.initTree()
else:    Chain = sample.initTree()
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

#Get pile-up reweighting
from puReweighting import getReweightingFunction
puReweighting     = getReweightingFunction(data="PU_2016_36000_XSecCentral")

print 'Getting things ready to start the event loop'

#Determine categories to fill
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
        if cat == "inData":
            tmp.append(histogram(cat+ '_ptTau', (20, 20., 90.), output_dir))
            tmp.append(histogram(cat+ '_etaTau', (10, -2.5, 2.5), output_dir))
            tmp.append(histogram(cat+ '_met', (10, 50., 100.), output_dir))
            tmp.append(histogram(cat+ '_Mll', (15, 75., 105.), output_dir))
        elif cat == "Categ_C" and "DYJets" in sample.output:
            tmp.append(histogram(cat+ '_ptTau', (20, 20., 90.), output_dir))
            tmp.append(histogram(cat+ '_etaTau', (10, -2.5, 2.5), output_dir))
            tmp.append(histogram(cat+ '_met', (10, 50., 100.), output_dir))
            tmp.append(histogram(cat+ '_Mll', (20, 65., 115.), output_dir))
        else:
            tmp.append(histogram(cat+ '_ptTau', (10, 20., 90.), output_dir))
            tmp.append(histogram(cat+ '_etaTau', (10, -2.5, 2.5), output_dir))
            tmp.append(histogram(cat+ '_met', (5, 50., 100.), output_dir))
            tmp.append(histogram(cat+ '_Mll', (15, 25., 130.), output_dir))
            
    else:
        tmp.append(histogram(cat+ '_ptTau', np.array([20., 25., 35., 50., 70., 100.]), output_dir, customBins=True))
        tmp.append(histogram(cat+ '_etaTau', np.array([0., 0.5, 1., 1.5, 2., 2.5]), output_dir, customBins=True))
        tmp.append(histogram(cat+ '_met', (10, 0., 100.), output_dir))
        tmp.append(histogram(cat+ '_Mll', (15, 75., 105.), output_dir))
    hist.append(tmp)

#Determine if testrun so it doesn't need to calculate the number of events in the getEventRange
if args.isTest:
    eventRange = xrange(100000)
    #eventRange = sample.getEventRange(int(args.subJob))
else:
    eventRange = sample.getEventRange(int(args.subJob))

import objectSelection
from helpers_old import progress, makeDirIfNeeded, showBranch

#Loop over events
for entry in eventRange:
    
    #print progress and load in entry
    progress(entry-eventRange[0], len(eventRange))
    Chain.GetEntry(entry)

    #Check if event passed triggers
    if not eventSelection.passTriggers(Chain): continue
    
    #Select events with exactly 3 leptons
    lIndex = eventSelection.getLepIndices(Chain, not isData, needPromptTau)
    if len(lIndex) != 3: continue

    nLooseTau = eventSelection.numberOfTaus(Chain, lIndex)              #No selection on loose but not tight, this is all loose including the ones who are also tight
    nTightTau = eventSelection.numberOfTightTaus(Chain, lIndex)
    
    lVec = eventSelection.getFourVectors(Chain, tauES, lIndex)

    #Perform event selection for each category (all categories are mutually exclusive so only one applies here)
    #still no selection on loose but not tight, this happens in the fakerate.GetFakeWeight function
    #This is done to make the decision later if the event goes to observed or predicted
    #Events with two light leptons and more than 1 tau are discarded, even if only 1 tight tau
    category = 0 
    if not args.inData:
        if not args.isCheck:
            #OSSF light leptons and 1 loose tau 
            if eventSelection.passedCategC(Chain, lIndex, nLooseTau, nTightTau):
                category = 0
                var = eventSelection.fill_single_tau_vars(Chain, lVec)
           
            #OSOF light leptons and 1 loose tau 
            elif eventSelection.passedCategD(Chain, lIndex, nLooseTau, nTightTau):
                category = 1
                var = eventSelection.fill_single_tau_vars(Chain, lVec)
            
            #SSSF light leptons and 1 loose tau
            elif eventSelection.passedCategE(Chain, lIndex, nLooseTau, nTightTau):
                category = 2
                var = eventSelection.fill_single_tau_vars(Chain, lVec)
           
            #1 light lepton and 2 loose taus
            elif eventSelection.passedCategF(Chain, lIndex, nLooseTau, nTightTau):
                category = 3
                var = eventSelection.fill_two_tau_vars(Chain, lVec)
            
            else:
                continue
        
        #perform check
        else:
            if not eventSelection.passedCheck(Chain, lIndex, nLooseTau, lVec):      continue
            var = []
            var.append(lVec[2].Pt())
            var.append(abs(lVec[2].Eta()))
            var.append(Chain._met)
            var.append(eventSelection.getMll(lVec[0], lVec[1]))
    
    #CR in data event selection
    else:
        if not eventSelection.passedControlRegion(Chain, lIndex, nLooseTau, lVec):      continue
        var = eventSelection.fill_single_tau_vars(Chain, lVec)

    #
    #Getting ready to fill the histograms
    #
    #Determine if event is observed or predicted and calculate appropriate weight
    fake_factor = FR.getFakeWeight(Chain, lVec, lIndex, nLooseTau)


    #weightfactor to scale to lumi
    if not isData:  weightfactor = Chain._weight*((sample.xsec*lumi)/sample.hCount)
    else:       weightfactor = 1.
     
    #pu reweighting and tau ID weights
    if not isData:
        weightfactor *= puReweighting(Chain._nTrueInt)
        #print weightfactor*tauSF.getSF(args.year, 'Tight')[0],weightfactor*tauSF.getSF(args.year, 'VLoose')[0]

    #    if fake_factor == -999.:
    #        weightfactor *= tauSF.getSF(args.year, 'Tight')[0]
    #    else:
    #        weightfactor *= tauSF.getSF(args.year, 'VLoose')[0]

    #if category == 3 and var[3] < 75 and var[3] > 65:   print weightfactor, fake_factor
        
    #Fill histograms
    for v, h in zip(var, hist[category]):
        if isinstance(v, tuple):
            for _ in v:
                h.fill(_, weightfactor, fake_factor)
        else:
            h.fill(v, weightfactor, fake_factor)
    
for i, c in enumerate(categories):
    print c, hist[i][1].get_histogram().GetEntries(), hist[i][1].get_sideband().GetEntries(), hist[i][1].get_histogram().GetSumOfWeights(), hist[i][1].get_sideband().GetSumOfWeights()
    print c, hist[i][1].get_histogram().GetBinContent(7),  hist[i][1].get_sideband().GetBinContent(7)


#Write
if not args.isTest:
    for h in hist:
        for subh in h:
            subh.write_hist()
