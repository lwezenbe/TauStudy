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
    if Chain._lFlavor[lIndex] == 2:       return False
    if not Chain._lEwkTight[lIndex]:      return False
    return True
    
def tauHasOverlap(Chain, index): 
    #Check the flavor of the lepton and initialize variables 
    hasOverlap = False 
    inputVec = TLorentzVector() 
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index]) 
 
    #Loop over all leptons with a different flavor and a different index 
    for l in xrange(Chain._nLight): 
        if l == index or Chain._lFlavor[l] == Chain._lFlavor[index]:            continue 
        if not Chain._lEwkLoose[l]:                                             continue 
 
        lVec = TLorentzVector() 
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l]) 
 
        dR = inputVec.DeltaR(lVec) 
        if dR < .4:         hasOverlap = True 
 
    return hasOverlap 

def isLooseTau(Chain, lIndex, needPromptTau=False):
    if Chain._lFlavor[lIndex] != 2:     return False
    if not Chain._decayModeFinding[lIndex]:     return False
    if not Chain._lPOGVeto[lIndex]:     return False
    if tauHasOverlap(Chain, lIndex):    return False
    if not Chain._tauMuonVetoLoose[lIndex]:     return False
    if not Chain._tauEleVetoLoose[lIndex]:     return False
    if needPromptTau and Chain._tauGenStatus[lIndex] != 5:     return False
    return True

def isTightTau(Chain, lIndex):
    if not isLooseTau(Chain, lIndex):     return False
    if not Chain._lPOGTight[lIndex]:           return False
    return True
