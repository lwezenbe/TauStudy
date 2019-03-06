import ROOT
import os
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub

sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/RecoZmass/MuTauAN/subjobs/Data/inputFiles.conf')

for sample in sampleList:
    for subJob in xrange(sample.splitJobs):
        log = "/user/lwezenbe/private/PhD/Results/TauStudy/RecoZmass/log/"+sample.name+ "_subjob_"+str(subJob)+".log"
        command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/RecoZmass/MuTauAN/subjobs/RecoZmass.py --sample='+sample.name+ ' --subJob='+str(subJob)
        sub.launchCream02(command, log) 
        #sub.runLocal(command, log) 



