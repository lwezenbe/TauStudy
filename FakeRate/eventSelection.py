import objectSelection
from ROOT import TLorentzVector

def isGoodBaseEvent(Chain, needPromptTau=False):
    
    nLooseTau = 0.
    lIndex = []
    for l in xrange(Chain._nL):
        if objectSelection.isGoodLightLep(Chain, l):    
            lIndex.append(l)
        elif objectSelection.isLooseTau(Chain, l, needPromptTau):
            lIndex.append(l)
            nLooseTau += 1.
    
    if len(lIndex) != 3:        return -1

    if nLooseTau != 1:          return -1

    #By now the first two should be light flavor and the third a tau since they were added last
    if Chain._lFlavor[lIndex[0]] != Chain._lFlavor[1]:          return -1
    if Chain._lCharge[lIndex[0]] == Chain._lCharge[lIndex[1]]:  return -1
    
    if Chain._met > 50:         return -1

    l1 = TLorentzVector()
    l2 = TLorentzVector()

    l1.SetPtEtaPhiE(Chain._lPt[lIndex[0]], Chain._lEta[lIndex[0]], Chain._lPhi[lIndex[0]], Chain._lE[lIndex[0]])
    l2.SetPtEtaPhiE(Chain._lPt[lIndex[1]], Chain._lEta[lIndex[1]], Chain._lPhi[lIndex[1]], Chain._lE[lIndex[1]])
    if abs((l1+l2).M()-91.19) > 15:     return -1

    return lIndex[2]
   
def isData(f): 
    list_of_datafiles = ['Data_2016', 'Data_2017', 'Data_2018'] 
    for dataf in list_of_datafiles: 
        if dataf in f:  return True 
    return False 
    
def passTriggers(Chain):
    #if Chain._passTrigger_e or Chain._passTrigger_ee or Chain._passTrigger_em or Chain._passTrigger_mm or Chain._passTrigger_m or Chain._passTrigger_mt: return True
    if Chain._passTrigger_e or Chain._passTrigger_m: return True
    return False
            
