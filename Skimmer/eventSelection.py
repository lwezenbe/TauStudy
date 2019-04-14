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
    for l in range(ord(Chain._nL)):
        if objSel.isGoodTauAN17_094(Chain, l):
            nTau += 1
    return nTau

def isGoodEventAN17_094(Chain):
    if selectMuonsAN17_094(Chain) < 1:          return False
    if selectTauAN17_094(Chain) < 1:            return False

    return True

def isGoodEventJana(Chain):
    lIndices = 0
    nTau = 0    
 
    for l in xrange(ord(Chain._nL)):
        if Chain._lFlavor[l] != 2 and not objSel.isGoodLightLeptonEwkino(Chain, l):               continue
        if Chain._lFlavor[l] == 2 and not objSel.isGoodTauEwkino(Chain, l):                             continue
        lIndices.append(l)
        if Chain._lFlavor[l] == 2: nTau += 1


def isGoodEventEwkino(Chain):
    
    #Select good leptons and save indices
    lIndices = []
    nTau = 0
    
    for l in xrange(ord(Chain._nL)):
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
    for jet in xrange(ord(Chain._nJets)):
        if not objSel.isCleanJet(Chain, jet):                                   continue
        if Chain._jetCsvV2[jet]  > 0.8484:                                      contains_B_Jet = True

    if contains_B_Jet:                                                          return False

    return True
