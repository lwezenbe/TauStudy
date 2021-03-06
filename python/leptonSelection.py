import ROOT
from ROOT import TLorentzVector

def lepHasOverlap(Chain, index, isGen = False):
    
    #Check the flavor of the lepton and initialize variables
    hasOverlap = False
    inputVec = TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])
    
    #Loop over all leptons with a different flavor
    for l in xrange(ord(Chain._nL)):
        if l == index or Chain._lFlavor[l] == Chain._lFlavor[index]:            continue
        if not Chain._lPOGLoose[l]:                                             continue

        lVec = TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

        dR = inputVec.DeltaR(lVec)
        if dR < .4:         hasOverlap = True
    
    return hasOverlap
        
def matchHasOverlap(Chain, index):            #Only works for taus at the moment
    hasOverlap = False
    inputVec = TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lMatchPt[index], Chain._lMatchEta[index], Chain._lMatchPhi[index], Chain._lMatchE[index])
    
    for l in xrange(ord(Chain._gen_nL)):
        if l == index or Chain._gen_lFlavor == 2:      continue

        lVec = TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._gen_lPt[l], Chain._gen_lEta[l], Chain._gen_lPhi[l], Chain._gen_lE[l])

        dR = inputVec.DeltaR(lVec)
        if dR < .4:         hasOverlap = True

    return hasOverlap

def findMatchLepton(Chain, index):
    out_index = None
    inputVec = TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])
    
    minDeltaR = 9999999.
    for l in xrange(ord(Chain._gen_nL)):
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

def ZMassReconstructed(Chain):
    
    bestMassDiff = 9999999.
    #Start looping over the first leptons
    for l1 in xrange(ord(Chain._nL)-1):
        if not Chain._lPOGTight[l1] or Chain._lFlavor[l1] == 2: continue
        l1Vec = TLorentzVector()
        l1Vec.SetPtEtaPhiE(Chain._lPt[l1], Chain._lEta[l1], Chain._lPhi[l1], Chain._lE[l1])
        
        #Start looping over the second lepton    
        for l2 in xrange(l1+1, ord(Chain._nL)):
            if(not Chain._lPOGTight[l2] or Chain._lFlavor[l2] == 2):                        continue
            if(Chain._lFlavor[l1] != Chain._lFlavor[l2]):                                   continue
            
            l2Vec = TLorentzVector()
            l2Vec.SetPtEtaPhiE(Chain._lPt[l2], Chain._lEta[l2], Chain._lPhi[l2], Chain._lE[l2])
            mass = (l1Vec + l2Vec).M()
            
            if(abs(mass - 91.1876)< bestMassDiff):
                bestMassDiff = abs(mass - 91.1876)
            
            #print l1, l2, mass, bestMassDiff
            
    if bestMassDiff < 10.:      return True
    
    return False
