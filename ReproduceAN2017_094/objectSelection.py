import ROOT
from ROOT import TLorentzVector
import Constants as cst

true = True
false = False

def isGoodLepton(Chain, index):
    if Chain._lFlavor[index] == cst.mu:
        if(Chain._lPt[index] > 23 and abs(Chain._lEta[index]) < 2.1 and Chain._lPOGMedium[index] and Chain._relIso[index] < .15 and Chain._dz[index] < .2 and abs(Chain._dxy[index]) < 0.045):  
            return true

    if Chain._lFlavor[index] == cst.tau:
        if(Chain._lPt[index] > 20 and abs(Chain._lEta[index]) < 2.3 and Chain._decayModeFinding[index] and Chain._tauMuonVetoTight[index] and Chain._tauEleVetoLoose[index]):   
            return true

    return false                                   #If electron or tau doesnt pass

def SingleElectronVeto(Chain, index):                                                         #If bool is true, veto the event
    if(Chain._lPt[index] < 10 or abs(Chain._lEta[index]) > 2.5):     return false
    if(abs(Chain._dxy[index]) > .045 or Chain._dz[index] > .2):      return false
    if not Chain._lPOGMedium[index]:                           return false
    if not Chain._lElectronPassConvVeto[index]:               return false
    if(Chain._lElectronMissingHits[index] > 1):                return false
    if(Chain._relIso[index] > .3):                             return false
    return true

def SingleMuonVeto(Chain, index):                                                             #If bool is true, veto the event
    if(Chain._lPt[index] < 10 or abs(Chain._lEta[index]) > 2.4):     return false
    if(abs(Chain._dxy[index]) > .045 or Chain._dz[index] > .2):      return false
    if not Chain._lPOGMedium[index]:                           return false
    if(Chain._relIso[index] > .3):                             return false
    return true

def SingleLepVeto(Chain, index):                                                              #If bool is true, veto the event                                                                 
    for lepton in xrange(ord(Chain._nLight)):
        if lepton == index:                                                  continue
        if(Chain._lFlavor[lepton] == cst.mu and not SingleMuonVeto(Chain, lepton)):           continue
        if(Chain._lFlavor[lepton] == cst.ele and not SingleElectronVeto(Chain, lepton)):      continue 
        return true
    return false

def TwoMuonVeto(Chain, index):
    if int(ord(Chain._nMu)) - 1 < 2:                                      return false
    muToBeChecked = []                                                                    #Select Muons (listed first in entry)
    for lepton in xrange(ord(Chain._nMu)):
        if lepton == index:                                      continue
        if(Chain._lPt[lepton] < 15 or abs(Chain._lEta[lepton]) > 2.4):       continue
        if(abs(Chain._dxy[lepton]) > .045 or Chain._dz[lepton] > .2):        continue
        if not Chain._lPOGMedium[lepton]:                             continue
        if(Chain._relIso[lepton] > .3):                                continue
        muToBeChecked.append(lepton)

    if(len(muToBeChecked) < 2):                   return false

    muOneVec = ROOT.TLorentzVector()
    muTwoVec = ROOT.TLorentzVector()
    for muOne in xrange(len(muToBeChecked)-1):        
	for muTwo in range(muOne + 1, len(muToBeChecked)):
            if(Chain._lCharge[muToBeChecked[muOne]] == Chain._lCharge[muToBeChecked[muTwo]]):    continue
            muOneVec.SetPtEtaPhiE(Chain._lPt[muToBeChecked[muOne]], Chain._lEta[muToBeChecked[muOne]], Chain._lPhi[muToBeChecked[muOne]], Chain._lE[muToBeChecked[muOne]])
            muTwoVec.SetPtEtaPhiE(Chain._lPt[muToBeChecked[muTwo]], Chain._lEta[muToBeChecked[muTwo]], Chain._lPhi[muToBeChecked[muTwo]], Chain._lE[muToBeChecked[muTwo]])
            if(muOneVec.DeltaR(muTwoVec) < .15):                                     continue
            return true
    return false

def geometricMatch(Chain, index):
    out_index = None
    inputVec = TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])

    minDeltaR = 9999999.
    for l in xrange(ord(Chain._gen_nL)):
        if Chain._gen_lFlavor[l] != Chain._lFlavor[index]:                      continue
        if not Chain._gen_lIsPrompt[l]:                                         continue

        lVec = TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._gen_lPt[l], Chain._gen_lEta[l], Chain._gen_lPhi[l], Chain._gen_lE[l])

        dR = inputVec.DeltaR(lVec)
        if dR < minDeltaR:
            out_index = l
            minDeltaR = dR

    if minDeltaR < .3:
        return out_index
    else:
        return -1

