import ROOT
import os, argparse
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--isCheck', action='store_true')
argParser.add_argument('--year', action='store', default = '2016')
argParser.add_argument('--inData', action='store_true')
argParser.add_argument('--runLocal', action='store_true')
args = argParser.parse_args()

if not args.isCheck:
    sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/Data/inputFiles_'+args.year+'.conf')
else:    
    sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/inputFiles_'+args.year+'.conf')


if args.isCheck:
    MCsamples=['DYJets']
else:
    MCsamples = ['DYJets', 'TT']

for sample in sampleList:
    if not args.inData:
        if not sample.output in MCsamples: continue
    for subJob in xrange(sample.splitJobs):
        log = "/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/ClosureTest/log/"+sample.name+ "_subjob_"+str(subJob)+".log"
        command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/closureTest.py --sampleName='+sample.name+ ' --subJob='+str(subJob) +' --year='+args.year
        if args.isCheck:        command += ' --isCheck'
        if args.inData:        command += ' --inData'
        if(args.runLocal):
            sub.runLocal(command, log)
        else:
            sub.launchCream02(command, log, False, 'ClosureTest_'+str(subJob))
