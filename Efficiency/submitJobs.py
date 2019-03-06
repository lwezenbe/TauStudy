import ROOT
import os
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub

sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/inputFiles.conf')

def submitIso(sample):

    if sample.name == 'WZJets':    
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/Iso/"+sample.name+ "_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/IsoEfficiency.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --method=Bluj --inputFile=inputFiles'
            sub.launchCream02(command, log, "IsoEff")

    if sample.name == 'DYJetsToLL_M-50':
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/Iso/"+sample.name+ "_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/IsoFakeRate.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --method=Bluj --inputFile=inputFiles'
            sub.launchCream02(command, log, "IsoFR")

def submitLepDiscr(sample):
    
    if sample.name == 'WZJets':    
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/lepDiscr/"+sample.name+ "_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/LightLepDiscrEff.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --inputFile=inputFiles'
            sub.launchCream02(command, log, "LightLepEff")

    if sample.name == 'DYJetsToLL_M-50':
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/lepDiscr/"+sample.name+ "_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/LightLepDiscrFR.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --inputFile=inputFiles'
            sub.launchCream02(command, log, "LightLepFR")
    
def submitAllCuts(sample):

    if sample.name == 'WZJets':    
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/All/"+sample.name+ "_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/AllEfficiency.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --inputFile=inputFiles'
            sub.launchCream02(command, log, "AllEff")

    if sample.name == 'DYJetsToLL_M-50':
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/All/"+sample.name+ "_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/AllFakeRate.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --inputFile=inputFiles'
            sub.launchCream02(command, log, "AllFR")


for sample in sampleList:
    submitAllCuts(sample)
