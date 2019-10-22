import objectSelection
from ROOT import TLorentzVector

def getLepIndices(Chain, isMC, needPromptTau=False):
    
    lIndex = []
    for l in xrange(Chain._nL):
        if objectSelection.isGoodLightLep(Chain, l, isMC):    
            lIndex.append(l)
        elif objectSelection.isLooseTau(Chain, l, needPromptTau):
            lIndex.append(l)
    
    return lIndex
   
def numberOfTaus(Chain, lIndices):
    nTaus = 0
    for l in lIndices:
        if Chain._lFlavor[l] == 2:                      #All tau in lIndices are already skimmed for being VLoose Taus
            nTaus += 1
    return nTaus

def numberOfTightTaus(Chain, lIndices):
    nTaus = 0
    for l in lIndices:
        if Chain._lFlavor[l] == 2 and objectSelection.isTightTau(Chain, l):
            nTaus += 1
    return nTaus

#
#Function used for closure tests in MC to see if the event has the correct number of fakes
#
def isCorrectNumberOfFakes(Chain, lIndices, nLooseTau, nTightTau):
    #If only one tau, required to be fake
    if nLooseTau == 1:
        if not objectSelection.isFakeTau(Chain, lIndices[2]):        return False
    
    #If two taus, split up according to how many tight
    elif nLooseTau == 2:
        if nTightTau == 0:
            if not objectSelection.isFakeTau(Chain, lIndices[1]):        return False
            if not objectSelection.isFakeTau(Chain, lIndices[2]):        return False
        elif nTightTau == 1:
            for l in lIndices[1:]:
                if not objectSelection.isTightTau(Chain, l) and not objectSelection.isFakeTau(Chain, l):    return False
        elif nTightTau == 2:
            nFake = 0
            for l in lIndices[1:]:
                if objectSelection.isFakeTau(Chain, l):    nFake += 1
            if nFake < 1:       return False
    
    return True
            

def getFourVectors(Chain, tauES, lIndices):
    vec = []

    for i, l in enumerate(lIndices):
        vec.append(objectSelection.getFourVec(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l]))
        if Chain._lFlavor[l] == 2:
            vec[i] *= tauES.getES(Chain._tauDecayMode[l])

    return vec

def isOSSF(Chain, l1, l2):
    if Chain._lFlavor[l1] != Chain._lFlavor[l2]:  return False
    if Chain._lCharge[l1] == Chain._lCharge[l2]:  return False
    return True    
 
def isOSOF(Chain, l1, l2):
    if Chain._lFlavor[l1] == Chain._lFlavor[l2]:  return False
    if Chain._lCharge[l1] == Chain._lCharge[l2]:  return False
    return True    

def isSSSF(Chain, l1, l2):
    if Chain._lFlavor[l1] != Chain._lFlavor[l2]:  return False
    if Chain._lCharge[l1] != Chain._lCharge[l2]:  return False
    return True
    
def isSSOF(Chain, l1, l2):
    if Chain._lFlavor[l1] == Chain._lFlavor[l2]:  return False
    if Chain._lCharge[l1] != Chain._lCharge[l2]:  return False
    return True

def baseKinCuts(Chain):
    if Chain._met < 50: return False
    
    contains_B_Jet = False
    for jet in xrange(Chain._nJets):
        if not objectSelection.isCleanJet(Chain, jet):                                  continue
        if (Chain._jetDeepCsv_b[jet] + Chain._jetDeepCsv_bb[jet]) > 0.2219:   contains_B_Jet = True
    if contains_B_Jet:                                                               return False
    
    
    return True    

def passedCategC(Chain, lIndices, nLooseTau, nTightTau):
    if not baseKinCuts(Chain):         return False
    if nLooseTau != 1:                   return False
    if not isCorrectNumberOfFakes(Chain, lIndices, nLooseTau, nTightTau):       return False
    if not isOSSF(Chain, lIndices[0], lIndices[1]):     return False
 
    return True

def passedCategD(Chain, lIndices, nLooseTau, nTightTau):
    if not baseKinCuts(Chain):         return False
    if nLooseTau != 1:                   return False
    if not isCorrectNumberOfFakes(Chain, lIndices, nLooseTau, nTightTau):       return False
    #At this point the first two leptons are light flavored since taus are filled last
    if not isOSOF(Chain, lIndices[0], lIndices[1]):     return False
    return True

def passedCategE(Chain, lIndices, nLooseTau, nTightTau):
    if not baseKinCuts(Chain):         return False
    if nLooseTau != 1:                   return False
    #At this point the first two leptons are light flavored since taus are filled last
    if not isCorrectNumberOfFakes(Chain, lIndices, nLooseTau, nTightTau):       return False
    if not isSSOF(Chain, lIndices[0], lIndices[1]) or not isSSSF(Chain, lIndices[0], lIndices[1]):     return False
    
    return True

def passedCategF(Chain, lIndices, nLooseTau, nTightTau):
    if not baseKinCuts(Chain):         return False
    if not nLooseTau == 2:                   return False
    if not isCorrectNumberOfFakes(Chain, lIndices, nLooseTau, nTightTau):       return False
    return True   

def passedCheck(Chain, lIndices, nTau, lVec):
    if not nTau == 1:                   return False
    if not isOSSF(Chain, lIndices[0], lIndices[1]):     return False
    if Chain._met > 50: return False
    if abs(getMll(lVec[0], lVec[1]) - 91.19) > 15:      return False
    return True

def passedControlRegion(Chain, lIndices, nTau, lVec):
    if nTau != 1:          return False

    #By now the first two should be light flavor and the third a tau since they were added last
    if not isOSSF(Chain, lIndices[0], lIndices[1]):     return False
    
    if Chain._met < 50:         return False

    l1 = objectSelection.getFourVec(Chain._lPt[lIndices[0]], Chain._lEta[lIndices[0]], Chain._lPhi[lIndices[0]], Chain._lE[lIndices[0]])
    l2 = objectSelection.getFourVec(Chain._lPt[lIndices[1]], Chain._lEta[lIndices[1]], Chain._lPhi[lIndices[1]], Chain._lE[lIndices[1]])
    if abs((l1+l2).M()-91.19) > 15:     return False

    return True

def getMll(l1, l2):
    return (l1 + l2).M() 

def fill_single_tau_vars(Chain, lVec):
    var = []
    var.append(lVec[2].Pt())
    var.append(lVec[2].Eta())
    var.append(Chain._met)
    var.append(getMll(lVec[0], lVec[1]))
    return var

def fill_two_tau_vars(Chain, lVec):
    var = []
    var.append((lVec[1].Pt(), lVec[2].Pt()))
    var.append((lVec[1].Eta(), lVec[2].Eta()))
    var.append(Chain._met)
    var.append(getMll(lVec[1], lVec[2]))
    return var

def passTriggers(Chain):
    if Chain._passTrigger_e or Chain._passTrigger_ee or Chain._passTrigger_em or Chain._passTrigger_mm or Chain._passTrigger_m or Chain._passTrigger_mt or Chain._passTrigger_et: return True
    return False

def isData(f): 
    list_of_datafiles = ['Data_2016', 'Data_2017', 'Data_2018'] 
    for dataf in list_of_datafiles: 
        if dataf in f:  return True 
    return False 
