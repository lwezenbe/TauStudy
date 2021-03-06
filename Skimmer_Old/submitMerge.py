import ROOT, os, glob
import jobSubmitter as sub
from helpers import makeDirIfNeeded

baseFolderInput  = '/user/lwezenbe/public/ntuples/2016/ewkino_Oldtrilep'
baseFolderOutput = '/user/lwezenbe/public/ntuples/2016/ewkino_Oldtrilep'

makeDirIfNeeded(baseFolderOutput)

list_of_folders = glob.glob(baseFolderInput+ '/tmp*')
for f in list_of_folders:
    log = baseFolderOutput + '/Log/'+ f.rsplit('/', 1)[1]+ '.log'
    command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Skimmer_Old/mergeTuples.py --f='+f+' --Input='+ baseFolderInput+ ' --Output=' +baseFolderOutput
    sub.launchCream02(command, log, True, 'Merge ' + f.rsplit('/', 1)[1])

