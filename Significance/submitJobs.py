import ROOT
import os
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub


NUMBER_OF_ELE_WP = 6
NUMBER_OF_MU_WP = 3

sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Significance/Data/inputFiles.conf')

for sample in sampleList:
    for subJob in xrange(sample.splitJobs):
        for ele in range(NUMBER_OF_ELE_WP):
            for mu in range(NUMBER_OF_MU_WP):
                log = "/user/lwezenbe/private/PhD/Results/TauStudy/Significance/log/"+sample.name+ "_subjob_"+str(subJob)+"_ele_"+str(ele)+"_mu_"+str(mu)+".log"
                command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Significance/main.py --sampleName='+sample.name+ ' --subJob='+str(subJob) + ' --ele_cut_index='+str(ele) + ' --mu_cut_index='+str(mu)
                sub.launchCream02(command, log, False, 'SignificanceJob')
                #sub.runLocal(command, log) 

