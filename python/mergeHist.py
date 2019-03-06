import ROOT, glob
from helpers import getObjFromFile

samplesToMergeLocation = ["DYJets", "ST", "TT", "SingleMuon"]

for name in samplesToMergeLocation:
    hist = []
    listOfFiles = glob.glob("/user/lwezenbe/private/PhD/Results/TauStudy/RecoZmass/Histos/"+name+"/*.root")
    for f in listOfFiles:
        hist.append(f, "ZmassHist" + name)
    
    mergedHist = None
    for h in hist:
        if(hist.index(h) == 0): mergedHist = Clone(h)
        else :  mergedHist.Add(h)

    mergedHist.SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/RecoZmass/Histos/Merged/"+name+".root")

