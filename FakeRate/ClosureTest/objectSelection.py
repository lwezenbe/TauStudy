from ROOT import TLorentzVector

def getFourVec(pt, eta, phi, E):
    vec = TLorentzVector()
    vec.SetPtEtaPhiE(pt, eta, phi, E)
    return vec

def lepHasOverlap(Chain, index):

    order_of_flavors = [1, 0, 2]
    #Check the flavor of the lepton and initialize variables
    inputVec = TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])

    #Loop over all leptons with a different flavor
    for l in xrange(Chain._nL):
        if l == index or Chain._lFlavor[l] in order_of_flavors[order_of_flavors.index(Chain._lFlavor[index]):]:            continue
        if not isLooseLightLeptonEwkino(Chain, l):                                             continue

        lVec = TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

        dR = inputVec.DeltaR(lVec)
        if dR < .4:         return True

    return False

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

def isGoodLightLep(Chain, index, isMC):
    if isMC and not Chain._lIsPrompt[index]:    return False
    if Chain._lFlavor[index] == 0:              return isEwkTightElectron(Chain, index) 
    elif Chain._lFlavor[index] == 1:              return isEwkTightMuon(Chain, index) 
    elif Chain._lFlavor[index] == 2:              return False
    return False
    
def tauHasOverlap(Chain, index): 
 
    #Check the flavor of the lepton and initialize variables 
    hasOverlap = False 
    inputVec = getFourVec(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index]) 
 
    #Loop over all leptons with a different flavor and a different index 
    for l in xrange(Chain._nLight): 
        if l == index or Chain._lFlavor[l] == Chain._lFlavor[index]:            continue 
        if not isLooseLightLeptonEwkino(Chain, l):                                             continue 
 
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

