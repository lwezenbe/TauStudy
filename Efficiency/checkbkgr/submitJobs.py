import ROOT
import os
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub

sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/OldSamples.conf')

for sample in sampleList:
    for subJob in xrange(sample.splitJobs):
        log = "/user/lwezenbe/private/PhD/Results/TauStudy/CheckBkgr/log/"+sample.name+ "_subjob_"+str(subJob)+".log"
        command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/checkbkgr/SelectEvents.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --inputFile=OldSamples'
        sub.launchCream02(command, log)

