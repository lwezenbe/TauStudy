import ROOT

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

def isGoodLightLeptonSignificance(Chain, index):
 
    if Chain._lFlavor[index] == 2:              return False
    if not Chain._lEwkTight[index]:             return False

    return True
    
def isGoodTauEwkino(Chain, index):
    
    if Chain._lPt[index] < 20:                  return False
    elif abs(Chain._lEta[index]) > 2.3:         return False
    elif not Chain._decayModeFinding[index]:    return False
    elif not Chain._lPOGVeto[index]:            return False
    elif not Chain._tauMuonVetoLoose[index]:    return False
    elif not Chain._tauEleVetoLoose[index]:     return False
    return True

def isGoodLepJana(Chain, index):
    if not Chain._lPOGMedium[index]:            return False
    return True

def isCleanJet(Chain, index):

    if Chain._jetPt[index] < 25.:     return False

    jetVec = ROOT.TLorentzVector()
    jetVec.SetPtEtaPhiE(Chain._jetPt[index], Chain._jetEta[index], Chain._jetPhi[index], Chain._jetE[index])

    for l in xrange(ord(Chain._nL)):
        lVec = ROOT.TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])
        if jetVec.DeltaR(lVec) < 0.4:
            return False

    return True

