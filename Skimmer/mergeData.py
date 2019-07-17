import ROOT
import glob
from helpers import makeDirIfNeeded

list_of_datafiles = ['SingleMuon', 'SingleElectron', 'DoubleMuon', 'DoubleEG', 'MuonEG']


import argparse
argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--year',        action='store',         default='2016')
argParser.add_argument('--skim',        action='store',         default='ewkino')

args = argParser.parse_args()

output_folder = '/storage_mnt/storage/user/lwezenbe/public/ntuples/'+args.year+ '/' + args.skim +'/tmp_Data'
makeDirIfNeeded(output_folder)

event_information_set = set()

for f_name in list_of_datafiles:    
    file_list =  glob.glob('/storage_mnt/storage/user/lwezenbe/public/ntuples/'+args.year+ '/' + args.skim +'/tmp_'+f_name+'/*.root')
    for i, sub_f_name in enumerate(file_list):
        print sub_f_name
        f = ROOT.TFile(sub_f_name)
        c = f.Get('blackJackAndHookers/blackJackAndHookersTree')
       
        output_file = ROOT.TFile(output_folder +'/'+ sub_f_name.split('/')[-1], 'recreate')
        output_file.mkdir('blackJackAndHookers')
        output_file.cd('blackJackAndHookers')
        output_tree = c.CloneTree(0)
        
        for entry in xrange(c.GetEntries()):
            c.GetEntry(entry)
            event_information = (c._runNb, c._lumiBlock, c._eventNb)
            if event_information in event_information_set:      continue
            else:
                event_information_set.add(event_information)
                output_tree.Fill()        

        output_file.cd('blackJackAndHookers')
        output_file.Write()

        f.Close()
        output_file.Close()

import os
os.system('hadd -f '+output_folder+'/../Data_'+args.year+'.root '+output_folder + '/*.root')
os.system('rm -r '+output_folder)
for d in list_of_datafiles:
    os.system('rm -r '+output_folder + '/../tmp_'+d)
    
