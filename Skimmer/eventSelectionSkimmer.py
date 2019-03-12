import ROOT
import objectSelectionSkimmer as objSel

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

def isGoodEventEwkino(Chain):
    
    #Select good leptons and save indices
    lIndex = []
    nTau = 0
    
    for l in xrange(ord(Chain._nL)):
        if Chain._lFlavor[l] != 2 and not objSel.isGoodLightLeptonSignificance(Chain, l):               continue
        if Chain._lFlavor[l] == 2 and not objSel.isGoodTauEwkino(Chain, l):                             continue
        lIndex.append(l)
        if Chain._lFlavor[l] == 2: nTau += 1

    #Keep only events with exactly 3 good leptons
    if len(lIndex) < 3:                                                        return False

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

#def isGoodEventJana(Chain):
#    nTau = 0
#    lIndex = []
#    for l in range(ord(Chain._nL)):
#        if objSel.isGoodLepJana(Chain, l):
#            lIndex.append(l)
#            if Chain._lFlavor[l] == 2:
#                nTau += 1.
#    
#    if len(lIndex) < 3:
#        return False
#    elif nTau < 1:
#        return False
#    else:
#        return True