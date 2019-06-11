import ROOT
import numpy as np

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',          action='store',         default='DYJetsToLL_M-50')
argParser.add_argument('--subJob',              action='store',         default=0)
argParser.add_argument('--inputFile',           action='store',         default='inputFiles')
argParser.add_argument('--isTest',              action='store',         default=False)

args = argParser.parse_args()

#Load in samples
import Sample
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/'+args.inputFile+'.conf')
sample = Sample.getSampleFromList(sampleList, args.sampleName)

import fakeRate
FR = fakeRate.fakeRate('fakeRate_subJob_' + str(args.subJob))

from tauEnergyScale import tauEnergyScale
tauES = tauEnergyScale('2016', 'ReReco')

#Initialize chain
Chain = sample.initTree(needhCount=False)

#Determine if testrun so it doesn't need to calculate the number of events in the getEventRange (current bottleneck)
if args.isTest:
    eventRange = xrange(30000)
else:
    eventRange = sample.getEventRange(int(args.subJob))
    print len(eventRange)

import eventSelection
import objectSelection
from helpers import progress, makeDirIfNeeded
#Loop over events
for entry in eventRange:

    progress(entry - eventRange[0], len(eventRange))
    Chain.GetEntry(entry)
    
    tau_index = eventSelection.isGoodBaseEvent(Chain)
    if tau_index == -1: continue

    tau_FV = objectSelection.getFourVec(Chain._lPt[tau_index], Chain._lEta[tau_index], Chain._lPhi[tau_index], Chain._lE[tau_index])
    tau_FV *= tauES.getES(Chain._tauDecayMode[tau_index])
    
    FR.fill_denominator((tau_FV.Pt(), abs(tau_FV.Eta())), Chain._weight)

    if objectSelection.isTightTau(Chain, tau_index):            
        FR.fill_numerator((tau_FV.Pt(), abs(tau_FV.Eta())), Chain._weight)

if not args.isTest:
    FR.writeFR()

