import ROOT
import os
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub

sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Significance/Data/inputFiles.conf')

for sample in sampleList:
    for subJob in xrange(sample.splitJobs):
        log = "/user/lwezenbe/private/PhD/Results/TauStudy/Significance/log/"+sample.name+ "_subjob_"+str(subJob)+".log"
        command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Significance/main.py --sampleName='+sample.name+ ' --subJob='+str(subJob)
        sub.launchCream02(command, log, False, 'SignificanceJob')
        #sub.runLocal(command, log) 

