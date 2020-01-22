import ROOT
import os
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub
from helpers_old import makeDirIfNeeded

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--year',                action='store',         default='2016')
argParser.add_argument('--inData',              action='store_true')
argParser.add_argument('--runLocal',                action='store_true')

args = argParser.parse_args()


sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/inputFiles_'+args.year+'.conf')
makeDirIfNeeded("/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/log")

for sample in sampleList:
    if not args.inData and not 'DYJets' in sample.output: continue
   
    for subJob in xrange(sample.splitJobs):
        log = "/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/log/"+sample.name+ "_subjob_"+str(subJob)+".log"
        command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/main.py --sampleName='+sample.name+ ' --subJob='+str(subJob) + ' --year='+args.year
        if args.inData: command += ' --inData'
        if args.inData:
            inDataStr = "True"
        else:
            inDataStr = "False"
        if args.runLocal:
            sub.runLocal(command, log)
        else:
            sub.launchCream02(command, log, False, 'FR_'+inDataStr + "_"+ sample.name + str(subJob))

