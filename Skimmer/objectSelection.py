import ROOT

def lepHasOverlap(Chain, index):

    order_of_flavors = [1, 0, 2]
    #Check the flavor of the lepton and initialize variables
    inputVec = ROOT.TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])

    #Loop over all leptons with a different flavor
    for l in xrange(Chain._nL):
        if l == index or Chain._lFlavor[l] in order_of_flavors[order_of_flavors.index(Chain._lFlavor[index]):]:            continue
        if not isLooseLightLeptonEwkino(Chain, l):                                             continue

        lVec = ROOT.TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

        dR = inputVec.DeltaR(lVec)
        if dR < .4:         return True

    return False


def isGoodMuonAN17_094(Chain, index):
    if Chain._lFlavor[index] != 1:              return False
    if Chain._lPt[index] < 23:                  return False
    elif abs(Chain._lEta[index]) > 2.1:         return False
    elif not Chain._lPOGMedium[index]:          return False
    elif Chain._relIso[index] > .15:            return False 
    elif Chain._dz[index] > .2:                 return False 
    elif abs(Chain._dxy[index]) > 0.045:        return False
    return True

def isGoodTauAN17_094(Chain, index):
    if Chain._lFlavor[index] != 2:              return False
    if Chain._lPt[index] < 20:                  return False 
    elif abs(Chain._lEta[index]) > 2.3:         return False
    elif not Chain._decayModeFinding[index]:    return False
    elif not Chain._tauMuonVetoLoose[index]:    return False
    elif not Chain._tauEleVetoLoose[index]:     return False
    return True

def isEwkLooseMuon(Chain, index):
    if(abs(Chain._dxy[index])>= 0.05 or abs(Chain._dz[index])>= 0.1 or Chain._3dIPSig[index] >= 8): return False    
    if Chain._miniIso[index] >= 0.4:    return False
    if Chain._lPt[index] <= 5 or abs(Chain._lEta[index]) >= 2.4:       return False
    return True #isLooseMuon From heavyNeutrino already included in basic muon cuts

def isEwkFOMuon(Chain, index):
    if not isEwkLooseMuon(Chain, index):       return False
    if Chain._lPt[index] <= 10:       return False
    return Chain._leptonMvaTTH[index] > -0.2 or (Chain._ptRatio[index] > 0.3 and Chain._closestJetCsvV2[index] < 0.3);

def isEwkTightMuon(Chain, index):
    if not isEwkFOMuon(Chain, index):       return False
    return Chain._leptonMvaTTH[index] > -0.2

def isEwkLooseElectron(Chain, index):
    if(abs(Chain._dxy[index])>= 0.05 or abs(Chain._dz[index])>= 0.1 or Chain._3dIPSig[index] >= 8): return False    
    if Chain._miniIso[index] >= 0.4:    return False
    if Chain._lPt[index] <= 7 or abs(Chain._lEta[index]) >= 2.5:       return False
    if Chain._lElectronMissingHits[index] > 1: return False
    if lepHasOverlap(Chain, index): return False
    return True #isLooseMuon From heavyNeutrino already included in basic muon cuts

def isEwkFOElectron(Chain, index):
    if not isEwkLooseElectron(Chain, index):       return False
    if Chain._lPt[index] <= 10:       return False
    if Chain._lElectronMissingHits[index] != 0: return False
    return Chain._leptonMvaTTH[index] > 0.5 or Chain._ptRatio[index] > 0.3 and Chain._closestJetCsvV2[index] < 0.3;

def isEwkTightElectron(Chain, index):
    if not isEwkFOElectron(Chain, index):       return False
    if not Chain._lElectronPassConvVeto[index]:       return False
    return Chain._leptonMvaTTH[index] > 0.5;

def isLooseLightLeptonEwkino(Chain, index):

    if Chain._lFlavor[index] == 0:              return isEwkLooseElectron(Chain, index) 
    elif Chain._lFlavor[index] == 1:              return isEwkLooseMuon(Chain, index) 
    elif Chain._lFlavor[index] == 2:              return False
    return False

def isGoodLightLeptonEwkino(Chain, index):
    if Chain._lFlavor[index] == 0:              return isEwkTightElectron(Chain, index) 
    elif Chain._lFlavor[index] == 1:              return isEwkTightMuon(Chain, index) 
    elif Chain._lFlavor[index] == 2:              return False
    return False
    
def isGoodTauEwkino(Chain, index):
    
    if Chain._lFlavor[index] != 2:     return False
    if Chain._lPt[index] < 20:                  return False
    elif abs(Chain._lEta[index]) > 2.3:         return False
    elif not Chain._decayModeFinding[index]:    return False
    elif not Chain._lPOGVeto[index]:            return False
    elif lepHasOverlap(Chain, index):           return False
    elif not Chain._tauMuonVetoLoose[index]:    return False
    elif not Chain._tauEleVetoLoose[index]:     return False
    return True

def isTightTauEwkino(Chain, index):
    if not isGoodTauEwkino(Chain, index):       return False
    if not Chain._lPOGTight[index]:             return False
    return True

def isEwkLoose(Chain, index):
    if Chain._lFlavor[index] == 0:              return isEwkLooseElectron(Chain, index)
    elif Chain._lFlavor[index] == 1:              return isEwkLooseMuon(Chain, index)
    elif Chain._lFlavor[index] == 2:              return isGoodTauEwkino(Chain, index)
    return False

def isEwkTight(Chain, index):
    if Chain._lFlavor[index] == 0:              return isEwkTightElectron(Chain, index)
    elif Chain._lFlavor[index] == 1:              return isEwkTightMuon(Chain, index)
    elif Chain._lFlavor[index] == 2:              return isTightTauEwkino(Chain, index)
    return False


def slidingCut(Chain, index, low, high):
    slope = (high-low)/10.
    return min(low, max(high, low+slope*(Chain._lPt[index]-15.)))

def passingElectronMvaTightSusy(Chain, index):
    if(Chain._lPt[index] < 10):                 return False
    if(abs(Chain._lEta[index]) < 0.8):          return Chain._lElectronSummer16MvaGP[index] > slidingCut(Chain, index,  0.77,  0.52)
    elif (abs(Chain._lEta[index]) < 1.479):     return Chain._lElectronSummer16MvaGP[index] > slidingCut(Chain, index,  0.56,  0.11)
    else:                                       return Chain._lElectronSummer16MvaGP[index] > slidingCut(Chain, index,  0.48, -0.01)

def isGoodElectronJana(Chain, index):
    if Chain._lFlavor[index] != 0:                      return False
    if not passingElectronMvaTightSusy(Chain, index):    return False
    if Chain._lPt[index] < 10:  return False
    if Chain._relIso[index] > 0.1:    return False
    if abs(Chain._dxy[index]) > 0.05:    return False
    if abs(Chain._dz[index]) > 0.1:    return False
    if abs(Chain._3dIPSig[index]) > 4:    return False
    return True

def isGoodMuonJana(Chain, index):
    if Chain._lFlavor[index] != 1:                      return False
    if not Chain._lPOGTight[index]:    return False
    if Chain._relIso[index] > 0.1:    return False
    if abs(Chain._dxy[index]) > 0.05:    return False
    if abs(Chain._dz[index]) > 0.1:    return False
    if abs(Chain._3dIPSig[index]) > 4:    return False
    return True

def isGoodLepJana(Chain, index):
    if Chain._lFlavor[index] == 0 and not isGoodElectronJana(Chain, index):            return False
    if Chain._lFlavor[index] == 1 and not isGoodMuonJana(Chain, index):          return False
    if Chain._lFlavor[index] == 2 and not Chain._lPOGVeto[index]:            return False
    return True

def isCleanJet(Chain, index):

    if Chain._jetPt[index] < 25.:     return False
    if not Chain._jetIsTight[index]:   return False

    jetVec = ROOT.TLorentzVector()
    jetVec.SetPtEtaPhiE(Chain._jetPt[index], Chain._jetEta[index], Chain._jetPhi[index], Chain._jetE[index])

    for l in xrange(Chain._nL):
        lVec = ROOT.TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])
        if jetVec.DeltaR(lVec) < 0.4:
            return False

    return True

