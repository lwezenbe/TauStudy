import ROOT
import os, argparse
from ROOT import gROOT, TCanvas, TH1D, gStyle, TColor, TGraphErrors, TFile, TChain, TVector2, TLorentzVector
from numpy import zeros, sqrt, cos
import Constants as cst
from objectSelection import isGoodLepton, SingleMuonVeto, SingleElectronVeto, SingleLepVeto, TwoMuonVeto
from plottingCode import plotDataVSMC
from helpers import getObjFromFile
from progress import progress
import Sample

true = True
false = False

def getWeightFactor(xsec, _weight, hCount):
    weightfactor = _weight*((xsec*cst.LuminosityCtoG)/hCount)

    return weightfactor

def makeHist(histInfo):
    h = TH1D(histInfo[0], histInfo[0], histInfo[1], histInfo[2], histInfo[3])
    return h

def fillOverflow(h, val, weightfactor, hInfo):
    if(val > hInfo[3]):
        h.Fill(hInfo[3]-((hInfo[3]-hInfo[2])/(2*hInfo[1])), weightfactor)
    else:                                                      
        h.Fill(val, weightfactor)

def SetBranches(Chain, isData):
    Chain.SetBranchStatus("*",0)
    branches = ["_nL", "_nEle", "_nMu", "_nTau", 
                    "_lPt", "_lEta", "_lPhi", "_lE",
                    "_ptRel", "_ptRatio","_lPOGTight","_lPOGLoose", "_lPOGMedium", 
                    "_lCharge",
                    "_lFlavor",
                    "_metPhi", "_met",
                    "_dz", "_dxy",
                    "_lElectronPassConvVeto", "_lElectronMissingHits",
                    "_decayModeFinding", "_tauMuonVeto", "_tauEleVeto", 
                    "_relIso", "_tauCombinedIsoDBRaw3Hits",
                    "_passTrigger_mAN094"]
    if not isData:
            branches.append("_weight")

    for branch in branches:
            Chain.SetBranchStatus(branch, 1)

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',  action='store',         default=None)
argParser.add_argument('--subJob',      action='store',         default=None)

args = argParser.parse_args()

sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/RecoZmass/MuTauAN/subjobs/Data/inputFiles.conf')
sample = Sample.getSampleFromList(sampleList, args.sampleName)

print("\n Looping over all events in: " + sample.path)

#Create Histograms
listOfHist = []
for var in xrange(cst.NumberOfVar):
    listOfHist.append(makeHist(cst.varInfo[var]))
    listOfHist[var].Sumw2()
    
Chain = sample.initTree()

lIndex = zeros(cst.NumberOfLeptons, dtype=int)

for entry in sample.getEventRange(int(args.subJob)):
    Chain.GetEntry(entry)
   
    if not sample.isData :
        weightfactor = getWeightFactor(sample.xsec, Chain._weight, sample.gethCount())
    else :
        weightfactor = 1

    if not Chain._passTrigger_mAN094:                                   continue

    # Select leptons
    minRelIso = [999999, 999999]
    for lepton in xrange(ord(Chain._nL)):
        if not isGoodLepton(Chain, lepton):                               continue
        if(Chain._lFlavor[lepton] == cst.mu and Chain._relIso[lepton] < minRelIso[cst.Muon]):
            minRelIso[cst.Muon] = Chain._relIso[lepton]
            lIndex[cst.Muon] = lepton
        if(Chain._lFlavor[lepton] == cst.tau and Chain._tauCombinedIsoDBRaw3Hits[lepton] < minRelIso[cst.Tau]):
            minRelIso[cst.Tau] = Chain._tauCombinedIsoDBRaw3Hits[lepton]
            lIndex[cst.Tau] = lepton

    #Event selection
    if(minRelIso[cst.Muon] == 999999 or minRelIso[cst.Tau] == 999999):           continue               #Remove events without tau and muon
    if(Chain._lCharge[lIndex[cst.Muon]] == Chain._lCharge[lIndex[cst.Tau]]):                 continue               #Remove same charge pairs
    
    lVec = []
    MetVec = TVector2()
    MuTransVec = TVector2()
    TauTransVec = TVector2()
    for whichlep in xrange(cst.NumberOfLeptons):
        vec = TLorentzVector()
        lVec.append(vec)
        lVec[whichlep].SetPtEtaPhiE(Chain._lPt[lIndex[whichlep]], Chain._lEta[lIndex[whichlep]], Chain._lPhi[lIndex[whichlep]], Chain._lE[lIndex[whichlep]])
    
    MetVec.SetMagPhi(Chain._met, Chain._metPhi);
    MuTransVec.SetMagPhi(Chain._lPt[lIndex[cst.Muon]], Chain._lPhi[lIndex[cst.Muon]])
    TauTransVec.SetMagPhi(Chain._lPt[lIndex[cst.Tau]], Chain._lPhi[lIndex[cst.Tau]])

    DeltaPhi                = abs(MetVec.DeltaPhi(MuTransVec))
    MT                      = sqrt(2*Chain._lPt[lIndex[cst.Muon]]*Chain._met*(1-cos(DeltaPhi)))

    MuTauBisector           = MuTransVec.Unit() + TauTransVec.Unit()
    MuTauBisector           = MuTauBisector.Unit()

    PZetaAll                = (MetVec + MuTransVec + TauTransVec)*MuTauBisector
    PZetaVis                = (MuTransVec + TauTransVec)*MuTauBisector
    PZeta                   = PZetaAll - .85*PZetaVis

    if(lVec[cst.Muon].DeltaR(lVec[cst.Tau]) < .5):                               continue

    if(TwoMuonVeto(Chain, lIndex[cst.Muon])):                                       continue

    if(SingleLepVeto(Chain, lIndex[cst.Muon])):                                     continue

    if(MT > 40):                                                         continue               #Remove W+jets events

    if(PZeta < -25):                                                     continue

    if not Chain._lPOGTight[lIndex[cst.Tau]]:                                        continue

    VectorSum = lVec[cst.Muon]+lVec[cst.Tau]
    Mvis = VectorSum.M()
    
    fillOverflow(listOfHist[cst.muPtInd], Chain._lPt[lIndex[cst.Muon]], weightfactor, cst.varInfo[cst.muPtInd])
    fillOverflow(listOfHist[cst.tauPtInd], Chain._lPt[lIndex[cst.Tau]], weightfactor, cst.varInfo[cst.tauPtInd])
    fillOverflow(listOfHist[cst.muEtaInd], Chain._lEta[lIndex[cst.Muon]], weightfactor, cst.varInfo[cst.muEtaInd])
    fillOverflow(listOfHist[cst.tauEtaInd], Chain._lEta[lIndex[cst.Tau]], weightfactor, cst.varInfo[cst.tauEtaInd])
    fillOverflow(listOfHist[cst.MTInd], MT, weightfactor, cst.varInfo[cst.MTInd])
    fillOverflow(listOfHist[cst.MvisInd], Mvis, weightfactor, cst.varInfo[cst.MvisInd])
    fillOverflow(listOfHist[cst.DeltaPhiInd], DeltaPhi, weightfactor, cst.varInfo[cst.DeltaPhiInd])
    fillOverflow(listOfHist[cst.PZetaAllInd], PZetaAll, weightfactor, cst.varInfo[cst.PZetaAllInd])
    fillOverflow(listOfHist[cst.PZetaVisInd], PZetaVis, weightfactor, cst.varInfo[cst.PZetaVisInd])
    fillOverflow(listOfHist[cst.PZetaInd], PZeta, weightfactor, cst.varInfo[cst.PZetaInd])

print("Done. Saving output.")

for var in xrange(cst.NumberOfVar):
    listOfHist[var].SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/RecoZmass/Histos/" + sample.output + "/" + cst.varInfo[var][0] + "_Hist_" + args.sampleName+"_"+args.subJob + ".root")
