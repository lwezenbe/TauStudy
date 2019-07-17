import ROOT, os, glob
import jobSubmitter as sub
from helpers import makeDirIfNeeded

import argparse
argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--year',        action='store',         default='2016')
argParser.add_argument('--skim',        action='store',         default='FR')
argParser.add_argument('--dataIncluded',        action='store',         default=None)

args = argParser.parse_args()

baseFolderInput  = '/user/lwezenbe/public/ntuples/'+args.year+'/'+args.skim
baseFolderOutput = '/user/lwezenbe/public/ntuples/'+args.year+'/'+args.skim

def isData(f):
    list_of_datafiles = ['SingleMuon', 'SingleElectron', 'DoubleMuon', 'DoubleEG', 'MuonEG']
    for dataf in list_of_datafiles:
        if dataf in f:  return True
    return False

makeDirIfNeeded(baseFolderOutput)

list_of_folders = glob.glob(baseFolderInput+ '/tmp_*')
for f in list_of_folders:
    if isData(f):       continue
    makeDirIfNeeded(baseFolderOutput + '/Log')
    log = baseFolderOutput + '/Log/'+ f.rsplit('/', 1)[1]+ '.log'
    command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Skimmer/mergeTuples.py --f='+f+' --Output=' +baseFolderOutput
    sub.launchCream02(command, log, False, 'Merge_' + f.rsplit('/', 1)[1])

if args.dataIncluded:
    makeDirIfNeeded(baseFolderOutput + '/Log')
    log = baseFolderOutput + '/Log/data.log'
    command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Skimmer/mergeData.py --year='+args.year + ' --skim='+args.skim
    sub.launchCream02(command, log, False, 'Merge_Data')
