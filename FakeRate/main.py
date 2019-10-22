import ROOT
import numpy as np

lumi = 35545.499064

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',          action='store',         default='DYJetsToLL_M-50',      help='Name of the sample. Default is DYJetsToLL_M-50')
argParser.add_argument('--subJob',              action='store',         default=0,                      help='Index of subjob. Default is 0')
argParser.add_argument('--year',                action='store',         default='2016',                 help='Year of datataking (2016, 2017, 2018)')
argParser.add_argument('--inData',              action='store_true',                                    help='Calculate fake rate in data DY CR')
argParser.add_argument('--isTest',              action='store_true',                                    help='Run a local test with limited number of events')

args = argParser.parse_args()

#Load in samples
import Sample
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/inputFiles_'+args.year+'.conf')
sample = Sample.getSampleFromList(sampleList, args.sampleName)

#Look if we're dealing with data or MC
import eventSelection
isData = eventSelection.isData(args.sampleName)

#Look if we're dealing with a prompt subtraction sample
forPromptSubtraction = False
if args.inData and not isData:  forPromptSubtraction = True

#Create a fakeRate object
import fakeRate
inData_str = None
if args.inData: inData_str = 'DATA'
else: inData_str = 'MC'
FR = fakeRate.fakeRate('fakeRate'+inData_str+args.year+'-'+args.sampleName+'_subJob' + str(args.subJob))

#import classes to reweight
from tauEnergyScale import tauEnergyScale
tauES = tauEnergyScale(args.year)

from tauIDSF import tauIDSF
tauSF = tauIDSF()

from puReweighting import getReweightingFunction
puReweighting     = getReweightingFunction(data="PU_2016_36000_XSecCentral")

#Initialize chain
Chain = sample.initTree()

#Determine if testrun so it doesn't need to calculate the number of events in the getEventRange (current bottleneck)
if args.isTest:
    eventRange = sample.getEventRange(int(args.subJob))
else:
    eventRange = sample.getEventRange(int(args.subJob))

import objectSelection
from helpers import progress, makeDirIfNeeded
#Loop over events
for entry in eventRange:

    progress(entry - eventRange[0], len(eventRange))
    Chain.GetEntry(entry)
    
    if not eventSelection.passTriggers(Chain):      continue
    
    tau_index = eventSelection.isGoodBaseEvent(Chain, needPromptTau=forPromptSubtraction)       #Need prompt taus for MC samples when measuring in data
    if tau_index == -1: continue

    tau_FV = objectSelection.getFourVec(Chain._lPt[tau_index], Chain._lEta[tau_index], Chain._lPhi[tau_index], Chain._lE[tau_index])
    tau_FV *= tauES.getES(Chain._tauDecayMode[tau_index])

    #Calculate weights    
    if not isData:      weightfactor = np.array([Chain._weight*((sample.xsec*lumi)/sample.hCount) for _ in range(2)]) #numerator, denominator
    else:       weightfactor = np.array([1., 1.]) #Numerator, denominator
    if forPromptSubtraction:    weightfactor *= -1. 

    if not isData:
        puWeight = puReweighting(Chain._nTrueInt)
        weightfactor *= puWeight

    #    weightfactor[0] *= tauSF.getSF(args.year, 'Tight')[0]
    #    weightfactor[1] *= tauSF.getSF(args.year, 'VLoose')[0]

    #Fill Fake Rate
    #If elif structure: if measured in data and MC sample for prompt subtraction, both numerator and denominator are always filled
    #else it looks if the tau is tight to fill the numerator
    FR.fill_denominator((tau_FV.Pt(), abs(tau_FV.Eta())), weightfactor[1])
    if forPromptSubtraction: 
        FR.fill_numerator((tau_FV.Pt(), abs(tau_FV.Eta())), weightfactor[0])
    elif objectSelection.isTightTau(Chain, tau_index):            
        FR.fill_numerator((tau_FV.Pt(), abs(tau_FV.Eta())), weightfactor[0])

print FR.get_numerator().GetSumOfWeights(), FR.get_denominator().GetSumOfWeights()
print FR.get_numerator().GetEntries(), FR.get_denominator().GetEntries()

#if not args.isTest:
if True:
    FR.writeFR()

