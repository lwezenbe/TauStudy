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
    if not Chain._lIsPrompt[lIndex]:      return False
    return True
    
def tauHasOverlap(Chain, index): 
 
    #Check the flavor of the lepton and initialize variables 
    hasOverlap = False 
    inputVec = getFourVec(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index]) 
 
    #Loop over all leptons with a different flavor and a different index 
    for l in xrange(ord(Chain._nLight)): 
        if l == index or Chain._lFlavor[l] == Chain._lFlavor[index]:            continue 
        if not Chain._lEwkLoose[l]:                                             continue 
 
        lVec = TLorentzVector() 
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l]) 
 
        dR = inputVec.DeltaR(lVec) 
        if dR < .4:         hasOverlap = True 
 
    return hasOverlap 
 
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

def isNonPromptLooseTau(Chain, lIndex):    
    if Chain._lFlavor[lIndex] != 2:     return False
    if geometricMatch(Chain, lIndex) != -1.:   return False
    if not Chain._decayModeFinding[lIndex]:     return False
    if not Chain._lPOGVeto[lIndex]:     return False
    if tauHasOverlap(Chain, lIndex):    return False
    if not Chain._tauMuonVetoLoose[lIndex]:     return False
    if not Chain._tauEleVetoLoose[lIndex]:     return False
    return True

def isTightTau(Chain, lIndex):
    if Chain._lFlavor[lIndex] != 2:     return False
    if not Chain._decayModeFinding[lIndex]:     return False
    if not Chain._lPOGTight[lIndex]:     return False
    if tauHasOverlap(Chain, lIndex):    return False
    if not Chain._tauMuonVetoLoose[lIndex]:     return False
    if not Chain._tauEleVetoLoose[lIndex]:     return False
    return True

def isCleanJet(Chain, index):

    if Chain._jetPt[index] < 25.:     return False

    if not Chain._jetIsTight[index]:     return False

    jetVec = TLorentzVector()
    jetVec.SetPtEtaPhiE(Chain._jetPt[index], Chain._jetEta[index], Chain._jetPhi[index], Chain._jetE[index])

    for l in xrange(ord(Chain._nL)):
        lVec = TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])
        if jetVec.DeltaR(lVec) < 0.4:
            return False

    return True

