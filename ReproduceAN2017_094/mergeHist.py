import ROOT, glob, subprocess
from helpers import getObjFromFile
from ROOT.TH1 import Clone

varNames = ["muPt", "tauPt", "muEta", "tauEta", "MT", "MVis", "dPhi", 'PZetaAll', 'PZEtaVis', 'PZeta']

samplesToMergeLocation = ["DYJets", 'DYJets_bkgr', "ST", "TT", "VV", "WJets", "QCD", "SingleMuon"]

for name in samplesToMergeLocation:
    for var in varNames:
        hist = []
        listOfFiles = glob.glob("/user/lwezenbe/private/PhD/Results/TauStudy/ReproduceAN2017_094/Histos/"+name+"/"+ var + "_Hist*.root")
        for f in listOfFiles:
            hist.append(getObjFromFile(f, var))
        mergedHist = None
        for h in hist:
            if(hist.index(h) == 0): mergedHist = h.Clone(var)
            else :  mergedHist.Add(h)

        mergedHist.SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproduceAN2017_094/Histos/Merged/"+name+"/"+var+".root")

        for f in listOfFiles:
            subprocess.check_output("rm "+f, shell=True, stderr = subprocess.STDOUT)
 
