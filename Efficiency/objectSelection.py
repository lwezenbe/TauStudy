import ROOT
from ROOT import TLorentzVector

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

def isEwkLooseLepton(Chain, index):
    if Chain._lFlavor[index] == 0: return isEwkLooseElectron(Chain, index)
    elif Chain._lFlavor[index] == 1: return isEwkLooseMuon(Chain, index)
    else:
        return False

def findMatchLepton(Chain, index):
    out_index = None
    inputVec = TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])

    minDeltaR = 9999999.
    for l in xrange(Chain._gen_nL):
        if Chain._gen_lFlavor[l] == Chain._lFlavor[index]:                      continue
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

def geometricMatch(Chain, index):
    out_index = None
    inputVec = TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])

    minDeltaR = 9999999.
    for l in xrange(Chain._gen_nL):
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


def getFourVec(pt, eta, phi, E):
    vec = TLorentzVector()
    vec.SetPtEtaPhiE(pt, eta, phi, E)
    return vec

def lepHasOverlap(Chain, index):

    #Check the flavor of the lepton and initialize variables
    hasOverlap = False
    inputVec = TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])

    #Loop over all leptons with a different flavor
    for l in xrange(Chain._nL):
        if l == index or Chain._lFlavor[l] == Chain._lFlavor[index]:            continue
        if not isEwkLooseLepton(Chain, l):                                             continue

        lVec = getFourVec(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

        dR = inputVec.DeltaR(lVec)
        if dR < .4:         hasOverlap = True

    return hasOverlap

def tauMatchIndexIso(Chain, objectVec, needFake = None):
    minDeltaR = 0.3
    matchindex = 0
    for l in xrange(Chain._nLight, Chain._nL):
        if not isGoodBaseTauIso(Chain, l): continue       
        if geometricMatch(Chain, l) != -1:      continue
        if needFake is not None:
            if needFake == False:
                if Chain._tauGenStatus[l] != 5: continue 
            else:
                if Chain._tauGenStatus[l] != 6: continue 
                
        lVec = getFourVec(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

        deltaR = lVec.DeltaR(objectVec)
        if deltaR < minDeltaR:
            minDeltaR = deltaR
            matchindex = l

    if minDeltaR < 0.3: return matchindex
    else: return -1        


def isGoodBaseTau(Chain, index):
    if Chain._lFlavor[index] != 2:          return False
    if Chain._lPt[index] < 20 or abs(Chain._lEta[index]) > 2.3:            return False
    if lepHasOverlap(Chain, index):                                        return False
    return True

def isFakeTau(Chain, index):
    if Chain._lFlavor[index] != 2:          return False
    if Chain._lPt[index] < 20 or abs(Chain._lEta[index]) > 2.3:            return False
    if Chain._tauGenStatus[index] == 5:            return False
    return True

def isGoodBaseTauIso(Chain, index):
    if not isGoodBaseTau(Chain, index):         return False
#    if Chain._tauGenStatus[index] < 5:            return False
#    if findMatchLepton(Chain, index) != -1:            return False
    return True

def getTauIDs(Chain, lepton):
    iso = Chain._tauCombinedIsoDBRaw3Hits[lepton]
    discriminators = (
                    [Chain._tauPOGVLoose2015[lepton], Chain._tauPOGLoose2015[lepton], Chain._tauPOGMedium2015[lepton], Chain._tauPOGTight2015[lepton], Chain._tauPOGVTight2015[lepton]],
                    [Chain._tauVLooseMvaNew2015[lepton], Chain._tauLooseMvaNew2015[lepton], Chain._tauMediumMvaNew2015[lepton], Chain._tauTightMvaNew2015[lepton], Chain._tauVTightMvaNew2015[lepton]],
                    [Chain._lPOGVeto[lepton], Chain._lPOGLoose[lepton], Chain._lPOGMedium[lepton], Chain._lPOGTight[lepton], Chain._tauPOGVTight2017v2[lepton]],
                    [Chain._tauVLooseMvaNew2017v2[lepton], Chain._tauLooseMvaNew2017v2[lepton], Chain._tauMediumMvaNew2017v2[lepton], Chain._tauTightMvaNew2017v2[lepton], Chain._tauVTightMvaNew2017v2[lepton]],
                    [iso < 4.5, iso < 3.5, iso < 2.0, iso < 1.0, iso < 0.8], 
                    [Chain._tauVVVLooseDeepTauVsJets[lepton], Chain._tauVVLooseDeepTauVsJets[lepton], Chain._tauVLooseDeepTauVsJets[lepton], Chain._tauLooseDeepTauVsJets[lepton], Chain._tauMediumDeepTauVsJets[lepton], Chain._tauTightDeepTauVsJets[lepton], Chain._tauVTightDeepTauVsJets[lepton], Chain._tauVVTightDeepTauVsJets[lepton]]) 
                    
    return discriminators
    
def getDMfinding(Chain, lepton):
    DMfinding = (Chain._decayModeFinding[lepton], Chain._decayModeFindingNew[lepton], Chain._decayModeFinding[lepton], Chain._decayModeFindingNew[lepton], Chain._decayModeFinding[lepton], Chain._decayModeFindingNew[lepton])
    return DMfinding

def getTauLepDiscr(Chain, lepton):
    discriminators = ( [Chain._tauMuonVetoLoose[lepton], Chain._tauMuonVetoTight[lepton] ],
                    [Chain._tauVLooseDeepTauVsMu[lepton], Chain._tauLooseDeepTauVsMu[lepton], Chain._tauMediumDeepTauVsMu[lepton], Chain._tauTightDeepTauVsMu[lepton]],
                    [Chain._tauEleVetoVLoose[lepton], Chain._tauEleVetoLoose[lepton], Chain._tauEleVetoMedium[lepton], Chain._tauEleVetoTight[lepton], Chain._tauEleVetoVTight[lepton]],
                    [Chain._tauVVVLooseDeepTauVsEle[lepton], Chain._tauVVLooseDeepTauVsEle[lepton], Chain._tauVLooseDeepTauVsEle[lepton], Chain._tauLooseDeepTauVsEle[lepton], Chain._tauMediumDeepTauVsEle[lepton], Chain._tauTightDeepTauVsEle[lepton], Chain._tauVTightDeepTauVsEle[lepton], Chain._tauVVTightDeepTauVsEle[lepton]])
    return discriminators
