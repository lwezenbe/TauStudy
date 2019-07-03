import ROOT
import numpy as np

lumi = 36000

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',          action='store',         default='DYJetsToLL_M-50')
argParser.add_argument('--inData',              action='store',         default=None)
argParser.add_argument('--subJob',              action='store',         default=0)
argParser.add_argument('--year',                action='store',         default='2016')
argParser.add_argument('--isTest',              action='store',         default=False)

args = argParser.parse_args()

#Load in samples
import Sample
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/inputFiles_'+args.year+'.conf')
sample = Sample.getSampleFromList(sampleList, args.sampleName)

#Look if we're dealing with data or MC
import eventSelection
isData = eventSelection.isData(args.sampleName)

#Look if we're dealing with a prompt substraction sample
forPromptSubtraction = False
if args.inData and not isData:  forPromptSubtraction = True

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
    print len(eventRange)
    #eventRange = xrange(30000)
else:
    eventRange = sample.getEventRange(int(args.subJob))
    print len(eventRange)

import objectSelection
from helpers import progress, makeDirIfNeeded
#Loop over events
for entry in eventRange:

    progress(entry - eventRange[0], len(eventRange))
    Chain.GetEntry(entry)
    
    tau_index = eventSelection.isGoodBaseEvent(Chain, needPromptTau=forPromptSubtraction)
    if tau_index == -1: continue

    if not eventSelection.passTriggers(Chain):      continue

    tau_FV = objectSelection.getFourVec(Chain._lPt[tau_index], Chain._lEta[tau_index], Chain._lPhi[tau_index], Chain._lE[tau_index])
    tau_FV *= tauES.getES(Chain._tauDecayMode[tau_index])

    #Calculate weights    
    if not isData:      weightfactor = np.array([Chain._weight*((sample.xsec*lumi)/sample.hCount) for _ in range(2)]) #numerator, denominator
    else:       weightfactor = np.array([1., 1.]) #Numerator, denominator
    if forPromptSubtraction:    weightfactor *= -1. 

    if not isData:
        puWeight = puReweighting(Chain._nTrueInt)
        weightfactor *= puWeight

        weightfactor[0] *= tauSF.getSF(args.year, 'Tight')[0]
        weightfactor[1] *= tauSF.getSF(args.year, 'VLoose')[0]
    
    print weightfactor
    #Fill Fake Rate
    FR.fill_denominator((tau_FV.Pt(), abs(tau_FV.Eta())), weightfactor[1])
    if forPromptSubtraction: 
        FR.fill_numerator((tau_FV.Pt(), abs(tau_FV.Eta())), weightfactor[0])
    else:
        if objectSelection.isTightTau(Chain, tau_index):            
            FR.fill_numerator((tau_FV.Pt(), abs(tau_FV.Eta())), weightfactor[0])

#if not args.isTest:
if True:
    FR.writeFR()

