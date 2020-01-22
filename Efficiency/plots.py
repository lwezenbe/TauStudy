import ROOT, os, time
from ROOT import TFile, TCanvas, TGraphErrors
from plottingTools import plotROC, DrawHist, extraTextFormat, plotROCfromgraph
from helpers_old import getObjFromFile, loadtxtCstyle, makeDirIfNeeded, timeStampFolder
import numpy as np
from ROC import ROC
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('category',              action='store',         help='Print isolation or lepton discrimination. Enter "Iso", "LepDiscr" or "All')
argParser.add_argument('effName',               action='store',         help='Name of the efficiency sample subfolder')
argParser.add_argument('--effMethod',           action='store',         help='Name of the efficiency sample subfolder',           default='AN')
argParser.add_argument('frName',                action='store',         help='Name of the fakerate sample subfolder')
argParser.add_argument('--frMethod',            action='store',         help='Name of the fakerate sample subfolder',           default='AN')
argParser.add_argument('--usefulInfo',          action='store',         help='Add useful information in a txt file to the output folder',           default=None)

args = argParser.parse_args()

if args.category == 'LepDiscr':
    #Define the algorithms and their working points
    tau_id_algos = [('MuonDiscrMVA', ['Loose',  'Tight']),
                    ('MuonDiscrdeeptau', ['VVVLoose', 'VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight', 'VTight', 'VVTight']), 
                    ('ElectronDiscrMVA', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                    ('ElectronDiscrdeeptau', ['VVVLoose', 'VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight', 'VTight', 'VVTight'])]   #Change getTauLepDiscr() accordingly
else:
    #Define the algorithms and their working points
    tau_id_algos = [('oldMVA2017v2', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
            ('newMVA2017v2', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
            ('cut_based', ['VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight']),
            ('deeptau', ['VVVLoose', 'VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight', 'VTight', 'VVTight']),  #If you add more ID's, don't forget to change it in the getTauIDs() function in objectSelection as well
            ('oldMVA2015', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
            ('newMVA2015', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight'])]

samples = [args.effName, args.frName]
methods = [args.effMethod, args.frMethod]
basefolderInput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/'+args.category+'/Merged'
basefolderOutput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Plots/'+args.category
#basefolderInput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency_/Histos/'+args.category+'/Merged'
#basefolderOutput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency_/Plots/'+args.category

efficiencyOrfakerate = ['efficiency', 'fakerate']
efficiencyOrfakerateFile = ['Efficiency', 'FakeRate']

var = ['pt', 'eta']
xNames = [['p_{T}^{#tau} [GeV]', '|#eta|_{#tau}'],['p_{T}^{jet} [GeV]', '|#eta|^{jet}']]

#make output directory
makeDirIfNeeded(basefolderOutput)
makeDirIfNeeded(basefolderOutput+'/'+samples[0]+'-'+methods[0]+'_'+samples[1]+'-'+methods[1])
basefolderOutput = timeStampFolder(basefolderOutput+'/'+samples[0]+'-'+methods[0]+'_'+samples[1]+'-'+methods[1], args.usefulInfo)
makeDirIfNeeded(basefolderOutput+'/ROC')

#ROC
extraText = []
extraText.append(extraTextFormat("Efficiency: "+ samples[0]  +" MC"))
extraText.append(extraTextFormat("FR : "+samples[1]+" MC"))
extraText.append(extraTextFormat('p_{T}^{#tau} > 20 GeV, |#eta_{#tau}| < 2.3'))

ROC_graphs = []
for n, name in enumerate(tau_id_algos):
    if(args.category == 'Iso'):             ylabel = "jet -> #tau FR"
    elif(args.category == 'LepDiscr'and n < 2):      ylabel = "#mu -> #tau FR"
    elif(args.category == 'LepDiscr'and n > 1):      ylabel = "e -> #tau FR"
    else:                                   ylabel = "Fake Rate"

    tmproc = ROC(name[0])
    print name[0]
    tmproc.load_efficiency('roc_efficiency_'+name[0], basefolderInput + '/Efficiency/'+args.effMethod+'/' + samples[0]+ '/roc_efficiency_'+ name[0]+'.root') 
    tmproc.load_fakerate('roc_fakerate_'+name[0], basefolderInput + '/FakeRate/'+args.frMethod+'/' + samples[1]+ '/roc_fakerate_'+ name[0]+'.root') 

    ROC_graphs.append(tmproc.return_graph())
    #if args.category == 'LepDiscr': plotROCfromgraph(ROC_graphs[n], "Efficiency (%)", ylabel, (name[0]), basefolderOutput+"/ROC/ROC_"+name[0], False, True, extraText)

discr = [x[0] for x in tau_id_algos]
if not args.category == 'LepDiscr': 
    plotROCfromgraph(ROC_graphs,  "Efficiency (%)", ylabel, discr, basefolderOutput+"/ROC/ROC_All", '2016', False, True, extraText)
else:
    plotROCfromgraph(ROC_graphs[:2],  "Efficiency (%)", "#mu -> #tau FR", discr[:2], basefolderOutput+"/ROC/ROC_Muon", '2016', False, True, extraText)
    plotROCfromgraph(ROC_graphs[2:],  "Efficiency (%)", "e -> #tau FR", discr[2:], basefolderOutput+"/ROC/ROC_Electron", '2016', False, True, extraText)
    

from efficiency import efficiency
for v in var:
    for d in tau_id_algos:
        for categ, categName, method, Sample in zip(efficiencyOrfakerate, efficiencyOrfakerateFile, methods, samples):
#            if categ == 'efficiency': continue
            f = basefolderInput+ '/'+categName+ '/'+method+'/'+Sample+'/'+v+'_'+categ+'_'+d[0]+'.root'
            eff = efficiency(v+'_'+categ+'_'+d[0], f)
            tmp = []
            for i ,WP in enumerate(d[1]):
                tmp.append(eff.get_efficiency(i, 'efficiency' in categ))
            DrawHist(tmp, xNames[efficiencyOrfakerate.index(categ)][var.index(v)], categName, d[1], basefolderOutput+'/'+categ+'_'+v+'_'+d[0], '2016') 
