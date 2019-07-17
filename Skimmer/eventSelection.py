import ROOT
import objectSelection as objSel
from helpers import showBranch

def selectMuonsAN17_094(Chain):
    nMu = 0
    for l in range(ord(Chain._nL)):
        if objSel.isGoodMuonAN17_094(Chain, l):
            nMu += 1
    return nMu


def selectTauAN17_094(Chain):
    nTau = 0
    for l in range(Chain._nL):
        if objSel.isGoodTauAN17_094(Chain, l):
            nTau += 1
    return nTau

def isGoodEventAN17_094(Chain):
    if selectMuonsAN17_094(Chain) < 1:          return False
    if selectTauAN17_094(Chain) < 1:            return False

    return True

def isGoodEventJana(Chain):
    lIndices = []
    nTau = 0    
 
    for l in xrange(Chain._nL):
        if not objSel.isGoodLepJana(Chain, l):        continue
        lIndices.append(l)
        if Chain._lFlavor[l] == 2: nTau += 1

    if len(lIndices) < 3:       return False
    elif nTau < 1:              return False
    return True

def isGoodEventFakeRate(Chain):
    #Select good leptons and save indices
    lIndices = []
    nTau = 0
    
    for l in xrange(Chain._nL):
        if Chain._lFlavor[l] != 2 and not objSel.isGoodLightLeptonEwkino(Chain, l):               continue
        if Chain._lFlavor[l] == 2 and not objSel.isGoodTauEwkino(Chain, l):                             continue
        lIndices.append(l)
        if Chain._lFlavor[l] == 2: nTau += 1

    #Keep only events with exactly 3 good leptons
    if len(lIndices) != 3:                                                       return False

    if nTau != 1:                                                               return False

    #Missing energy cut
#    if Chain._met > 50.:                                                        return False

    l1 = ROOT.TLorentzVector()
    l2 = ROOT.TLorentzVector()

    l1.SetPtEtaPhiE(Chain._lPt[lIndices[0]], Chain._lEta[lIndices[0]], Chain._lPhi[lIndices[0]], Chain._lE[lIndices[0]])
    l2.SetPtEtaPhiE(Chain._lPt[lIndices[1]], Chain._lEta[lIndices[1]], Chain._lPhi[lIndices[1]], Chain._lE[lIndices[1]])
    if abs((l1+l2).M()-91.19) > 15:     return False

    return True

def isGoodEventEwkino(Chain):
    
    #Select good leptons and save indices
    lIndices = []
    nTau = 0
    
    for l in xrange(Chain._nL):
        if Chain._lFlavor[l] != 2 and not objSel.isGoodLightLeptonEwkino(Chain, l):               continue
        if Chain._lFlavor[l] == 2 and not objSel.isGoodTauEwkino(Chain, l):                             continue
        lIndices.append(l)
        if Chain._lFlavor[l] == 2: nTau += 1

    #Keep only events with exactly 3 good leptons
    if len(lIndices) < 3:                                                       return False

    if nTau < 1:                                                               return False

    #Missing energy cut
    if Chain._met < 50.:                                                        return False

    #B-tag veto
    contains_B_Jet = False
    for jet in xrange(Chain._nJets):
        if not objSel.isCleanJet(Chain, jet):                                   continue
        if Chain._jetCsvV2[jet]  > 0.8484:                                      contains_B_Jet = True

    if contains_B_Jet:                                                          return False

    return True

def isData(f): 
    list_of_datafiles = ['Data_2016', 'Data_2017', 'Data_2018', 'SingleMuon', 'SingleElectron', 'DoubleMuon', 'DoubleEG', 'MuonEG'] 
    for dataf in list_of_datafiles: 
        if dataf in f:  return True 
    return False 
    
