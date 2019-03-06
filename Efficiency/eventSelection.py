from ROOT import TLorentzVector

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

