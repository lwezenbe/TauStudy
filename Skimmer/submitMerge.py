import ROOT, os, glob
import jobSubmitter as sub
from helpers import makeDirIfNeeded

baseFolderInput  = '/user/lwezenbe/public/trilep'
baseFolderOutput = '/user/lwezenbe/public/trilep/SkimmedTuples'

makeDirIfNeeded(baseFolderOutput)

list_of_folders = glob.glob(baseFolderInput+ '/tmp*')
for f in list_of_folders:
    log = baseFolderOutput + '/later.log'
    command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Skimmer/mergeTuples.py --f='+f+' --Input='+ baseFolderInput+ ' --Output=' +baseFolderOutput
    sub.launchCream02(command, log)

