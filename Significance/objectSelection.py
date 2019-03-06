import ROOT

def isGoodLepton(Chain, index):
    
    if Chain._lFlavor[index] != 2 and not Chain._lEwkTight[index]:      return False
    
    if Chain._lFlavor[index] == 2:
        if not Chain._decayModeFinding[index] or not Chain._tauEleVetoLoose[index] or not Chain._tauMuonVetoLoose[index]:        return False
    
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

def lepHasOverlap(Chain, index):

    #Check the flavor of the lepton and initialize variables
    hasOverlap = False
    inputVec = TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])

    #Loop over all leptons with a different flavor
    for l in xrange(ord(Chain._nL)):
        if l == index or Chain._lFlavor[l] == Chain._lFlavor[index]:            continue
        if not Chain._lEwkLoose[l]:                                             continue

        lVec = TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

        dR = inputVec.DeltaR(lVec)
        if dR < .4:         hasOverlap = True

    return hasOverlap
    
