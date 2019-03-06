import ROOT, os, time
from ROOT import TFile, TCanvas, TGraphErrors
from plottingTools import plotROC, DrawHist, extraTextFormat
from helpers import getObjFromFile, loadtxtCstyle, makeDirIfNeeded
import numpy as np
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('category',              action='store',         help='Print isolation or lepton discrimination. Enter "Iso", "lepDiscr" or "All')
argParser.add_argument('effName',               action='store',         help='Name of the efficiency sample subfolder')
argParser.add_argument('--effMethod',           action='store',         help='Name of the efficiency sample subfolder',           default='AN')
argParser.add_argument('frName',                action='store',         help='Name of the fakerate sample subfolder')
argParser.add_argument('--frMethod',            action='store',         help='Name of the fakerate sample subfolder',           default='AN')

args = argParser.parse_args()

samples = [args.effName, args.frName]
methods = [args.effMethod, args.frMethod]
basefolderInput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/'+args.category+'/Merged'
basefolderOutput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Plots/'+args.category


if(args.category == 'Iso' or args.category == 'All'):
    discriminatorNames = ['OldMVA', 'NewMVA', 'Cut_Based']
    workingPointsMVA = ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']
    workingPointsCut = ['VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight']
elif(args.category == 'LepDiscr'):
    discriminatorNames = ['MuonDiscr', 'ElectronDiscr']
    workingPointsEle = ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']
    workingPointsMu = ['Loose', 'Tight']

efficiencyOrfakerate = ['efficiency', 'fakerate']
efficiencyOrfakerateFile = ['Efficiency', 'FakeRate']

var = ['pt', 'eta']
xNames = [['p_{T}^{#tau} [GeV]', '#abs{#eta}_{#tau}'],['p_{T}^{jet} [GeV]', '#abs{#eta}^{jet}']]

efficiencyROC = np.loadtxt(basefolderInput + '/Efficiency/'+args.effMethod+'/' + samples[0]+ '/efficienciesROC.dat')
efficiencyErrorsROC = np.loadtxt(basefolderInput+ '/Efficiency/'+ args.effMethod+'/'+samples[0]+ '/efficienciesErrorsROC.dat')

fakerateROC = np.loadtxt(basefolderInput+'/FakeRate/'+args.frMethod+'/'+samples[1]+'/fakeratesROC.dat')
fakerateErrorsROC = np.loadtxt(basefolderInput+'/FakeRate/'+args.frMethod+'/'+samples[1]+'/fakeratesErrorsROC.dat')

#make output directory
timestamp = time.strftime("%Y%m%d_%H%M%S")
makeDirIfNeeded(basefolderOutput)
makeDirIfNeeded(basefolderOutput+'/'+samples[0]+'-'+methods[0]+'_'+samples[1]+'-'+methods[1])
makeDirIfNeeded(basefolderOutput+'/'+samples[0]+'-'+methods[0]+'_'+samples[1]+'-'+methods[1]+'/'+timestamp)
basefolderOutput = basefolderOutput+'/'+samples[0]+'-'+methods[0]+'_'+samples[1]+'-'+methods[1]+'/'+timestamp
makeDirIfNeeded(basefolderOutput+'/ROC')

#ROC
extraText = []
#extraText.append(extraTextFormat("Efficiency: Z #rightarrow #tau #tau MC"))
#extraText.append(extraTextFormat("FR : QCD multijet (not flat) MC"))
extraText.append(extraTextFormat("Efficiency: "+ samples[0]  +" MC"))
extraText.append(extraTextFormat("FR : "+samples[1]+" MC"))
extraText.append(extraTextFormat('p_{T}^{#tau} > 20 GeV, |#eta_{#tau}| < 2.3'))

flatXerror = []
flatYerror = []
for n, name in enumerate(discriminatorNames):
    if(args.category == 'Iso'):             ylabel = "jet -> #tau FR"
    elif(args.category == 'LepDiscr'and n == 0):      ylabel = "#mu -> #tau FR"
    elif(args.category == 'LepDiscr'and n == 1):      ylabel = "e -> #tau FR"
    else:                                   ylabel = "Fake Rate"
    xdata = efficiencyROC[n]
    xdata = xdata.flatten('C')
    xerrors = efficiencyErrorsROC[n].flatten('C')
    if args.category == 'LepDiscr' and n == 0:  
        xdata = xdata[:2]                #temporary fix to the shorter number of muon discr
        xerrors = xerrors[:2]
    flatXerror.append(xerrors)
    ydata = fakerateROC[n]
    ydata = ydata.flatten('C')
    yerrors = fakerateErrorsROC[n].flatten('C')
    if args.category == 'LepDiscr' and n == 0:
        ydata = ydata[:2]
        yerrors = yerrors[:2]
    flatYerror.append(yerrors)
    plotROC(xdata, ydata, "Efficiency (%)", ylabel, name, basefolderOutput+"/ROC/ROC_"+name, xerrors, yerrors, False, True, extraText)

if not args.category == 'LepDiscr': plotROC(efficiencyROC, fakerateROC, "Efficiency (%)", ylabel, discriminatorNames, basefolderOutput+"/ROC/ROC_All", flatXerror, flatYerror,False, True, extraText)

for v in var:
    for categ, categName, method, Sample in zip(efficiencyOrfakerate, efficiencyOrfakerateFile, methods, samples):
        for d in discriminatorNames:
            if d == 'Cut_Based':                workingPoints = workingPointsCut
            elif d == 'MuonDiscr':              workingPoints = workingPointsMu
            elif d == 'ElectronDiscr':          workingPoints = workingPointsEle
            else:                               workingPoints = workingPointsMVA
            tmp = []
            for WP in workingPoints:
                tmp.append(getObjFromFile(basefolderInput+ '/'+categName+'/'+method+'/'+Sample+'/'+v+'_'+categ+'_'+d+'_'+WP+'.root', v+'_'+categ+'_'+d+'_'+WP))
            DrawHist(tmp, xNames[efficiencyOrfakerate.index(categ)][var.index(v)], categName, workingPoints, basefolderOutput+'/'+categ+'_'+v+'_'+d) 
