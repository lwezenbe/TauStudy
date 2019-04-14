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
print '1'
#Load in samples
import Sample
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/'+args.inputFile+'.conf', skipFaultyFiles=True)
sample = Sample.getSampleFromList(sampleList, args.sampleName)
print '2'
import fakeRate
FR = fakeRate.fakeRate('fakeRate_subJob_' + str(args.subJob))
print '3'
from tauEnergyScale import tauEnergyScale
tauES = tauEnergyScale('2016', 'ReReco')
print '4'
#Initialize chain
Chain = sample.initTree(needhCount=False)
print '5'
#Determine if testrun so it doesn't need to calculate the number of events in the getEventRange (current bottleneck)
if args.isTest:
    eventRange = xrange(20000)
else:
    #eventRange = xrange(200000)
    eventRange = sample.getEventRange(int(args.subJob))
print '6'
import eventSelection
import objectSelection
from helpers import progress, makeDirIfNeeded
#Loop over events
for entry in eventRange:

    progress(entry, len(eventRange))
    Chain.GetEntry(entry)
    
    tau_index = eventSelection.isGoodBaseEvent(Chain)
    if tau_index == -1: continue

    FR.fill_denominator((Chain._lPt[tau_index]*tauES.getES(Chain._tauDecayMode[tau_index]), abs(Chain._lEta[tau_index])))

    if objectSelection.isTightTau(Chain, tau_index):            
        FR.fill_numerator((Chain._lPt[tau_index]*tauES.getES(Chain._tauDecayMode[tau_index]), abs(Chain._lEta[tau_index])))

if not args.isTest:
    FR.writeFR()
    #Save output
#    makeDirIfNeeded(output_dir)
#    makeDirIfNeeded(output_dir+'/'+sample.output)
#    fakeRate_num.SaveAs(output_dir+'/'+sample.output+'/fakeRate_num_subjob_'+str(args.subJob)+'.root')
#    fakeRate_denom.SaveAs(output_dir+'/'+sample.output+'/fakeRate_denom_subjob_'+str(args.subJob)+'.root')

