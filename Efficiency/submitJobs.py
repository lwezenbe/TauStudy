import ROOT
import os
from Sample import createSampleList, getSampleFromList
import jobSubmitter as sub

sampleList = createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/inputFilesv3.conf')

def submitIso(sample):

#    if sample.name == 'WZJets':    
#        for subJob in xrange(sample.splitJobs):
#            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/Iso/"+sample.name+ "Eff_subjob_"+str(subJob)+".log"
#            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/IsoEfficiency.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --method=Bluj --inputFile=inputFilesv3'
#            sub.launchCream02(command, log, True, "IsoEff")

    if sample.name == 'DYJetsToLL_M-50':
        print sample.splitJobs
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/Iso/"+sample.name+ "FR_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/IsoFakeRate.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --method=Bluj --inputFile=inputFilesv3'
            sub.launchCream02(command, log, True, "IsoFR")

def submitLepDiscr(sample):
    
    if sample.name == 'WZJets':    
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/lepDiscr/"+sample.name+ "Eff_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/LightLepDiscrEff.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --inputFile=inputFilesv3'
            sub.launchCream02(command, log, True, "LightLepEff")

    if sample.name == 'DYJetsToLL_M-50':
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/lepDiscr/"+sample.name+ "FR_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/LightLepDiscrFR.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --inputFile=inputFilesv3'
            sub.launchCream02(command, log, True, "LightLepFR")
    
def submitAllCuts(sample):

    if sample.name == 'WZJets':    
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/All/"+sample.name+ "Eff_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/AllEfficiency.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --inputFile=inputFilesv3'
            sub.launchCream02(command, log, True, "AllEff")

    if sample.name == 'DYJetsToLL_M-50':
        for subJob in xrange(sample.splitJobs):
            log = "/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/log/All/"+sample.name+ "FR_subjob_"+str(subJob)+".log"
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/AllFakeRate.py --sample='+sample.name+ ' --subJob='+str(subJob)+ ' --inputFile=inputFilesv3'
            sub.launchCream02(command, log, True, "AllFR")


for sample in sampleList:
    submitIso(sample)
#    submitLepDiscr(sample)
#    submitAllCuts(sample)
