from ROOT import TLorentzVector

def getFourVec(pt, eta, phi, E):
    vec = TLorentzVector()
    vec.SetPtEtaPhiE(pt, eta, phi, E)
    return vec

def isGoodMuon(Chain, lIndex):
    if Chain._lFlavor[lIndex] != 1:     return False
    elif not Chain._lEwkTight[lIndex]:  return False
    return True

def isGoodElectron(Chain, lIndex):
    if Chain._lFlavor[lIndex] != 0:     return False
    elif not Chain._lEwkTight[lIndex]:  return False
    return True

def isGoodLightLep(Chain, lIndex):
    #if not isGoodMuon(Chain, lIndex) and not isGoodElectron(Chain, lIndex):      return False
    if Chain._lFlavor[lIndex] == 2:       return False
    if not Chain._lEwkTight[lIndex]:      return False
    #if not Chain._lIsPrompt[lIndex]:      return False
    return True
    
def tauHasOverlap(Chain, index): 
 
    #Check the flavor of the lepton and initialize variables 
    hasOverlap = False 
    inputVec = getFourVec(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index]) 
 
    #Loop over all leptons with a different flavor and a different index 
    for l in xrange(Chain._nLight): 
        if l == index or Chain._lFlavor[l] == Chain._lFlavor[index]:            continue 
        if not Chain._lEwkLoose[l]:                                             continue 
 
        lVec = TLorentzVector() 
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l]) 
 
        dR = inputVec.DeltaR(lVec) 
        if dR < .4:         hasOverlap = True 
 
    return hasOverlap 

def isLooseTau(Chain, lIndex, needPrompt=False):    
    if Chain._lFlavor[lIndex] != 2:     return False
    if not Chain._decayModeFinding[lIndex]:     return False
    if not Chain._lPOGVeto[lIndex]:     return False
#    if not Chain._tauPOGVLoose2015[lIndex]:     return False
    if tauHasOverlap(Chain, lIndex):    return False
    if not Chain._tauMuonVetoLoose[lIndex]:     return False
    if not Chain._tauEleVetoLoose[lIndex]:     return False
    if needPrompt and Chain._tauGenStatus[lIndex] != 5: return False
    return True

def isTightTau(Chain, lIndex):
    if Chain._lFlavor[lIndex] != 2:     return False
    if not Chain._lPOGTight[lIndex]:     return False
#    if not Chain._tauPOGTight2015[lIndex]:     return False
    return True

def isFakeTau(Chain, lIndex):
    if Chain._lFlavor[lIndex] != 2:     return False
    if Chain._tauGenStatus[lIndex] != 6:        return False
    return True

def isCleanJet(Chain, index):

    if Chain._jetPt[index] < 25.:     return False

    if not Chain._jetIsTight[index]:     return False

    jetVec = TLorentzVector()
    jetVec.SetPtEtaPhiE(Chain._jetPt[index], Chain._jetEta[index], Chain._jetPhi[index], Chain._jetE[index])

    for l in xrange(Chain._nL):
        lVec = TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])
        if jetVec.DeltaR(lVec) < 0.4:
            return False

    return True

