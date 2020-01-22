import ROOT

def isGoodBaseEvent(Chain):

    nLooseTau = 0.
    lIndex = []
    for l in xrange(Chain._nL):
        if isGoodLightLep(Chain, l):
            lIndex.append(l)
        elif isLooseTau(Chain, l):
            lIndex.append(l)
            nLooseTau += 1.
    returnFalse = False
    if len(lIndex) != 3:        returnFalse = True

    if nLooseTau != 1:          returnFalse = True

    return lIndex, nLooseTau, returnFalse

def isGoodLightLep(Chain, lIndex):
    if Chain._lFlavor[lIndex] == 2:       return False
    if not Chain._lEwkTight[lIndex]:      return False
    return True

def tauHasOverlap(Chain, index):

    #Check the flavor of the lepton and initialize variables 
    hasOverlap = False 
    inputVec = getFourVec(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index]) 
 
    #Loop over all leptons with a different flavor and a different index 
    for l in xrange(Chain._nLight): 
        if l == index or Chain._lFlavor[l] == Chain._lFlavor[index]:            continue 
        if not Chain._lEwkLoose[l]:                                             continue 
 
        lVec = ROOT.TLorentzVector() 
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l]) 
 
        dR = inputVec.DeltaR(lVec) 
        if dR < .4:         hasOverlap = True 
 
    return hasOverlap 

def getFourVec(pt, eta, phi, E):
    vec = ROOT.TLorentzVector()
    vec.SetPtEtaPhiE(pt, eta, phi, E)
    return vec


def isLooseTau(Chain, lIndex):    
    if Chain._lFlavor[lIndex] != 2:     return False
#    if not Chain._decayModeFinding[lIndex]:     return False
#    if not Chain._lPOGVeto[lIndex]:     return False
    if not Chain._tauPOGVLoose2015[lIndex]:     return False
    if tauHasOverlap(Chain, lIndex):    return False
    if not Chain._tauMuonVetoLoose[lIndex]:     return False
    if not Chain._tauEleVetoLoose[lIndex]:     return False
    return True
 
