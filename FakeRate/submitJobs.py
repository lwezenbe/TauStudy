import ROOT
import os
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub
from helpers import makeDirIfNeeded

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--inData',              action='store',         default=None)
argParser.add_argument('--year',                action='store',         default='2016')

args = argParser.parse_args()


sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/inputFiles_'+args.year+'.conf')

makeDirIfNeeded("/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/log")

for sample in sampleList:
    if not args.inData and not 'DYJetsToLL_M-50' in sample.name: continue
   
    for subJob in xrange(sample.splitJobs):
        log = "/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/log/"+sample.name+ "_subjob_"+str(subJob)+".log"
        command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/main.py --sampleName='+sample.name+ ' --subJob='+str(subJob) + ' --year='+args.year
        if args.inData: command += ' --inData=True'
        sub.launchCream02(command, log, False, 'FakeRate_' + str(subJob))
