from plottingCode import plotDataVSMC
from helpers import getObjFromFile
import ROOT

legendNames = ['Single top', 'VV','W+jets', 't#bar{t}', 'DYJets']
folderNames = ['TT', 'VV', 'WJets' ,"ST", "DYJets"]
#legendNames = ["STJets", "TTJets", "DYJets"]
#folderNames = ["ST", "TT", "DYJets"]
varNames = ["muPt", "tauPt", "muEta", "tauEta", "MT", "MVis", "dPhi", 'PZetaAll', 'PZEtaVis', 'PZeta']
xnames = ["p_{T}^{#mu} [GeV]", "p_{T}^{#tau} [GeV]", "#eta_{#mu}", "#eta_{#tau}", "M_{T} [GeV]", "M_{vis} [GeV]", "#Delta #phi", "P_{#zeta}^{all}", "P_{#zeta}^{vis}", "P_{#zeta}"] 

for var, xn in zip(varNames, xnames):
    MChist = []
    for fn in folderNames:
        MChist.append(getObjFromFile("/user/lwezenbe/private/PhD/Results/TauStudy/RecoZmass/Histos/Merged/" + fn + "/" + var + ".root", var))

    DataHist = getObjFromFile("/user/lwezenbe/private/PhD/Results/TauStudy/RecoZmass/Histos/Merged/SingleMuon/"+var + ".root", var)

    plotDataVSMC(DataHist, MChist, xn, legendNames, "Full 2016 SingleMuon", "/user/lwezenbe/private/PhD/Results/TauStudy/RecoZmass/Plots/"+var) 
