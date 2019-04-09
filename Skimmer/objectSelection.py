import ROOT

def lepHasOverlap(Chain, index):

    #Check the flavor of the lepton and initialize variables
    inputVec = ROOT.TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])

    #Loop over all leptons with a different flavor
    for l in xrange(ord(Chain._nLight)):
        if l == index or Chain._lFlavor[l] == Chain._lFlavor[index]:            continue
        if not Chain._lEwkLoose[l]:                                             continue

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

def isGoodLightLeptonEwkino(Chain, index):
 
    if Chain._lFlavor[index] == 2:              return False
    if not Chain._lEwkTight[index]:             return False

    return True
    
def isGoodTauEwkino(Chain, index):
    
    if Chain._lPt[index] < 20:                  return False
    elif abs(Chain._lEta[index]) > 2.3:         return False
    elif not Chain._decayModeFinding[index]:    return False
    elif not Chain._lPOGVeto[index]:            return False
    elif lepHasOverlap(Chain, index):           return False
    #elif not Chain._tauMuonVetoLoose[index]:    return False
    #elif not Chain._tauEleVetoLoose[index]:     return False
    return True

def isGoodLepJana(Chain, index):
    if not Chain._lPOGVeto[index]:            return False
    return True

def isCleanJet(Chain, index):

    if Chain._jetPt[index] < 25.:     return False
    if not Chain._jetIsLoose[index]:   return False

    jetVec = ROOT.TLorentzVector()
    jetVec.SetPtEtaPhiE(Chain._jetPt[index], Chain._jetEta[index], Chain._jetPhi[index], Chain._jetE[index])

    for l in xrange(ord(Chain._nL)):
        lVec = ROOT.TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])
        if jetVec.DeltaR(lVec) < 0.4:
            return False

    return True

