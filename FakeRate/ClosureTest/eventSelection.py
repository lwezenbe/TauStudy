import objectSelection
from ROOT import TLorentzVector

def getLepIndices(Chain):
    
    lIndex = []
    for l in xrange(ord(Chain._nL)):
        if objectSelection.isGoodLightLep(Chain, l):    
            lIndex.append(l)
        elif objectSelection.isNonPromptLooseTau(Chain, l):
            lIndex.append(l)
    
    return lIndex
   
def numberOfTaus(Chain, lIndices):
    nTaus = 0
    for l in lIndices:
        if Chain._lFlavor[l] == 2:
            nTaus += 1
    return nTaus

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
    for jet in xrange(ord(Chain._nJets)):
        if not objectSelection.isCleanJet(Chain, jet):                                   continue
        if Chain._jetCsvV2[jet]  > 0.8484:                                      contains_B_Jet = True
    if contains_B_Jet:                                                               return False
    
    return True    

#def passedCategC(Chain, lIndices, nTau):
#    if not baseKinCuts(Chain):         return False
#    if nTau != 1:                   return False
#    if not isOSSF(Chain, lIndices[0], lIndices[1]):     return False
#    return True
#
#def passedCategD(Chain, lIndices, nTau):
#    if not baseKinCuts(Chain):         return False
#    if nTau != 1:                   return False
#    #At this point the first two leptons are light flavored since taus are filled last
#    if not isOSOF(Chain, lIndices[0], lIndices[1]):     return False
#    return True
#
#def passedCategE(Chain, lIndices, nTau):
#    if not baseKinCuts(Chain):         return False
#    if nTau != 1:                   return False
#    #At this point the first two leptons are light flavored since taus are filled last
#    if not isSSOF(Chain, lIndices[0], lIndices[1]) or not isSSSF(Chain, lIndices[0], lIndices[1]):     return False
#    return True
#
#def passedCategF(Chain, lIndices, nTau):
#    if not baseKinCuts(Chain):         return False
#    if not nTau == 2:                   return False
#    return True   

#def getCategory(Chain

def passedCheck(Chain, lIndices, nTau, lVec):
    if not nTau == 1:                   return False
    if not isOSSF(Chain, lIndices[0], lIndices[1]):     return False
    if Chain._met > 50: return False
    if abs(getMll(lVec[0], lVec[1]) - 91.19) > 15:      return False

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
