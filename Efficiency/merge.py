import ROOT, glob, os
from ROOT import TFile, TCanvas
from plottingTools import plotROC, DrawHist, extraTextFormat
from helpers import getObjFromFile, loadtxtCstyle, progress, makeDirIfNeeded
import numpy as np
import argparse

def merge(effOrmisid, sampleName, method, category):
    if category == 'LepDiscr':
        basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/LepDiscr'
        #Define the algorithms and their working points
        tau_id_algos = [('MuonDiscrMVA', ['Loose',  'Tight']),
                        ('MuonDiscrdeeptau', ['VVVLoose', 'VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight', 'VTight', 'VVTight']), 
                        ('ElectronDiscrMVA', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                        ('ElectronDiscrdeeptau', ['VVVLoose', 'VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight', 'VTight', 'VVTight'])]   #Change getTauLepDiscr() accordingly

    else:
        #Define the algorithms and their working points
        tau_id_algos = [('oldMVA2015', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('newMVA2015', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('oldMVA2017v2', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('newMVA2017v2', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('cut_based', ['VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight']),
                ('deeptau', ['VVVLoose', 'VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight', 'VTight', 'VVTight'])]   #If you add more ID's, don't forget to change it in the getTauIDs() function in objectSelection as well

        basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/'+category
        #basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency_/Histos/'+category
    
    if effOrmisid == 'efficiency':    
        folder = 'Efficiency'
    elif effOrmisid == 'fakerate':
        folder = 'FakeRate'

    #Save efficiencies
    makeDirIfNeeded(basefolder+'/Merged')
    makeDirIfNeeded(basefolder+'/Merged/'+folder)
    makeDirIfNeeded(basefolder+'/Merged/'+folder+'/'+method)
    makeDirIfNeeded(basefolder+'/Merged/'+folder+'/'+method+'/'+sampleName)

    for tau_id in tau_id_algos:
        os.system('hadd -f ' + basefolder + "/Merged/"+folder+"/"+ method+'/'+sampleName+'/roc_'+effOrmisid+'_'+tau_id[0]+'.root '+ basefolder + '/'+sampleName + '/'+method+'/roc_'+effOrmisid+'_'+ tau_id[0]+'_*.root')
        eta_files = glob.glob(basefolder + '/' + sampleName + '/' + method + '/eta_efficiency_'+tau_id[0] +'_*.root')
        os.system('hadd -f ' + basefolder+'/Merged/'+folder+'/'+method+'/'+ sampleName+'/eta_'+effOrmisid+'_'+tau_id[0]+'.root '+ basefolder + '/' + sampleName + '/' + method + '/eta_'+effOrmisid+'_'+tau_id[0] +'_*.root')
        pt_files = glob.glob(basefolder + '/' + sampleName + '/' + method + '/eta_efficiency_'+tau_id[0] +'_*.root')
        os.system('hadd -f ' + basefolder+'/Merged/'+folder+'/'+method+'/'+ sampleName+'/pt_'+effOrmisid+'_'+tau_id[0]+'.root '+ basefolder + '/' + sampleName + '/' + method + '/pt_'+effOrmisid+'_'+tau_id[0] +'_*.root')
#    os.system('rm '+basefolder + '/'+sampleName + '/'+method+'/*.root')    

merge('efficiency', 'WZ', 'Bluj', 'Iso')
merge('fakerate', 'DYJets', 'Bluj', 'Iso')
#merge('efficiency', 'WZ', 'AN', 'LepDiscr')
#merge('fakerate', 'DYJets', 'AN', 'LepDiscr')
#merge('efficiency', 'WZ', 'Default', 'All')
#merge('fakerate', 'DYJets', 'Default', 'All')
