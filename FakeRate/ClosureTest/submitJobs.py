import ROOT
import os, argparse
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub

sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/inputFiles.conf')

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--isCheck', action='store', default = False)
args = argParser.parse_args()

for sample in sampleList:
    sample.initTree()
    for subJob in xrange(sample.splitJobs):
        log = "/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/ClosureTest/log/"+sample.name+ "_subjob_"+str(subJob)+".log"
        command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/closureTest.py --sampleName='+sample.name+ ' --subJob='+str(subJob) + ' --isCheck=' +args.isCheck
        sub.launchCream02(command, log, False, 'ClosureTest')

