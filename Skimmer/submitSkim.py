import ROOT, subprocess
import subSample
import jobSubmitter as sub
from helpers_old import makeDirIfNeeded

import argparse
argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--year',        action='store',         default='2016')
argParser.add_argument('--skim',        action='store',         default='FR')
argParser.add_argument('--analysis',        action='store',         default='ewkino')

args = argParser.parse_args()

files_to_skim = subSample.createSampleList('Data/'+args.analysis+'_'+args.year+'.conf')
makeDirIfNeeded('/user/lwezenbe/public/ntuples/'+args.year+'/'+args.skim+'/Log')

for f in files_to_skim:
    number_of_subdir = int(subprocess.check_output("/bin/ls -lA " + f + "/* | egrep -c '^-|^d'", shell=True, stderr=subprocess.STDOUT))
    for subdir in xrange(number_of_subdir):
        subsample = subSample.subSample(f, subdir)
        nJobs = len(subsample.arrangeFilesInSubjobs())
        for job in xrange(nJobs):
            log = '/user/lwezenbe/public/ntuples/'+args.year+'/'+args.skim+'/Log/'+subsample.group+'_'+subsample.name+ '_'+ str(subdir)+ '_' +str(job)+'.log'   #temporary lazy log
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Skimmer/main.py --path='+f+' --subDir='+ str(subdir)+ ' --subJob=' +str(job) + ' --skim=' + args.skim + ' --year='+args.year
            name = subsample.group+'_'+subsample.name+ '_'+ str(subdir)+ '_' +str(job)
            sub.launchCream02(command, log, False, str(job)+ '_'+args.skim+'_' + name)

