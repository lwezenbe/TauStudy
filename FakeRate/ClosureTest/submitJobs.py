import ROOT
import os, argparse
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--isCheck', action='store', default = '')
argParser.add_argument('--year', action='store', default = '2016')
argParser.add_argument('--inData', action='store', default = '')
args = argParser.parse_args()

if not args.isCheck:
    sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/Data/inputFiles_'+args.year+'.conf')
else:    
    sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/inputFiles_'+args.year+'.conf')

MCsamples = ['DYJetsToLL_M-50', 'TTJets']

for sample in sampleList:
    if not args.inData:
        if not MCsamples[0] in sample and not MCsamples[1] in sample: continue
    for subJob in xrange(sample.splitJobs):
        log = "/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/ClosureTest/log/"+sample.name+ "_subjob_"+str(subJob)+".log"
        command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/closureTest.py --sampleName='+sample.name+ ' --subJob='+str(subJob) + ' --isCheck=' +str(args.isCheck) +' --year='+args.year + ' --inData='+args.inData
        sub.launchCream02(command, log, False, 'ClosureTest_'+str(subJob))
