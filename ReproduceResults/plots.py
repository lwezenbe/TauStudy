import ROOT
from ROOT import TFile, TCanvas
from plottingCode import plotROC, DrawHist, extraTextFormat
from helpers import getObjFromFile, loadtxtCstyle
import numpy as np

#Messy code because I didn't understand certain things during writing, will clean up later

#Define Names used in GeneralTauEfficiency
SignalVarNames = ["lPt", "lEta", "lE", "dxy", "dz", "relIso", "tauAgainstElectronMVA6Raw", "tauCombinedIsoDBRaw3Hits", "ptRel", "ptRatio"]
SignalVarHistNames = ["lpt", "leta", "lE", "dxy", "dz", "reliso", "tauAgainstElectronMVA6Raw", "tauCombinedIsoDBRaw3Hits", "ptRel", "ptRatio"]
SignalxHistNames = ["P_{T} [GeV]", "#eta", "E [GeV]", "d_{xy} [cm]", "d_{z} [cm]", "reliso", "tauAgainstElectronMVA6Raw", "tauCombinedIsoDBRaw3Hits", "ptRel", "ptRatio"]
BkgrVarNames = ["jetPt", "jetEta", "jetE", "jetCsvV2"]
BkgrVarHistNames = ["jetpt", "jeteta", "jetE", "jetCsvV2"]
BkgrxHistNames = ["jet p_{T} [GeV]", "jet #eta", "jet E [GeV]", "jetCsvV2"]
discriminatorNames = ["OldMVA", "NewMVA", "CutBased"]
WPNames = ["VLoose", "Loose", "Medium", "Tight", "VTight"]
WPNamesCutBased = ["VVLoose", "VLoose","Loose", "Medium", "Tight"]
SignalBkgr = ["Signal", "Bkgr"]

#Load in all histograms
for n, hn, x in zip(SignalVarNames, SignalVarHistNames, SignalxHistNames):
    SignalVarHist = []
    SignalVarHist.append(getObjFromFile("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/SignalVar_" + n +".root", hn))
    DrawHist(SignalVarHist, x, ["Measured in Z->ll"],"/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/SignalVar_" + n)
for n, hn, x in zip(BkgrVarNames, BkgrVarHistNames, BkgrxHistNames):
    BkgrVarHist = []
    BkgrVarHist.append(getObjFromFile("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/BkgrVar_" + n +".root", hn))
    DrawHist(BkgrVarHist, x, ["Measured in QCD sample"],"/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/BkgrVar_" + n)
for sb in SignalBkgr:
    for discr in discriminatorNames:
        EfficiencyPtHist = []
        EfficiencyEtaHist = []
        for WP in WPNames : 
            EfficiencyPtHist.append(getObjFromFile("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/Efficiency"+sb+"_Pt_"+discr+"_"+WP+".root", "EfficiencyPtNum"+str(discriminatorNames.index(discr))+str(WPNames.index(WP))+str(SignalBkgr.index(sb))))
            EfficiencyEtaHist.append(getObjFromFile("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/Efficiency"+sb+"_Eta_"+discr+"_"+WP+".root", "EfficiencyEtaNum"+str(discriminatorNames.index(discr))+str(WPNames.index(WP))+str(SignalBkgr.index(sb))))
        if not discr == "CutBased" :
            DrawHist(EfficiencyPtHist, "p_{T} [GeV]", WPNames,  "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/"+sb+"_"+discr+"AsFuncOfPt")
            DrawHist(EfficiencyEtaHist, "#eta", WPNames,  "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/"+sb+"_"+discr+"AsFuncOfEta")
        else :     
            DrawHist(EfficiencyPtHist, "p_{T} [GeV]", WPNamesCutBased,  "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/"+sb+"_"+discr+"AsFuncOfPt")
            DrawHist(EfficiencyEtaHist, "#eta",WPNamesCutBased,  "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/"+sb+"_"+discr+"AsFuncOfEta")

#ROC
extraText = []
extraText.append(extraTextFormat("Efficiency: Z #rightarrow #tau #tau MC"))
extraText.append(extraTextFormat("FR : QCD multijet (not flat)"))
extraText.append(extraTextFormat("p_{T}^#tau > 20 GeV, #abs{#eta_#tau} < 2.3"))

for n in discriminatorNames:
    xdata = loadtxtCstyle("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencyROC_Signal"+ n +".dat")
    ydata = loadtxtCstyle("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencyROC_Bkgr"+ n +".dat")
    xerrors = loadtxtCstyle("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencyROCErrors_Bkgr"+ n +".dat")
    yerrors = loadtxtCstyle("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencyROCErrors_Bkgr"+ n +".dat")
    plotROC(xdata, ydata, "Efficiency (%)", "jet -> #tau FR",  "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/ROC/ROC_"+n, xerrors, yerrors, False, True, extraText)

