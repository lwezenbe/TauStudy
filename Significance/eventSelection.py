import ROOT
import objectSelection as objSel
import helpers

nTau = 0

def ptIsGood(Chain, lIndex):
    lPt = []
    for l in lIndex:
        lPt.append(Chain._lPt[l])

    sortedList = helpers.sortByOtherList(lIndex, lPt)
    lPt = sorted(lPt)
   
    #Look at leading lepton
    if Chain._lFlavor[sortedList[2]] == 1:
        if Chain._lFlavor[sortedList[1]] != 1 or Chain._lFlavor[sortedList[0]] != 1:
            if lPt[2] < 25:       return False
        elif lPt[2] < 25:         return False
    
    elif Chain._lFlavor[sortedList[2]] == 0:
        if lPt[2] < 20:           return False

    if Chain._lFlavor[sortedList[1]] == 1:
        if lPt[1] < 15:           return False
    else:
        if lPt[1] < 10:           return False

    if lPt[0] < 10:               return False

    return True     

def isGoodEvent(Chain, tau_iso_cut):
    
    #Select good leptons and save indices
    lIndex = []
    global nTau
    nTau = 0    
    for l in xrange(ord(Chain._nL)):
        if not objSel.isGoodLepton(Chain, l):                                   continue
        if Chain._lFlavor[l] == 2 and not tau_iso_cut[l]:                      continue
        lIndex.append(l)
        if Chain._lFlavor[l] == 2: nTau += 1

    #Keep only events with exactly 3 good leptons
    if len(lIndex) != 3:                                                        return False
   
    #Keep only events with 1 or 2 taus
    if nTau == 0 or nTau == 3:                                                  return False
 
    #Perform pt cuts
    if not ptIsGood(Chain, lIndex):                                             return False
#    lPt = []
#    for l in lIndex:
#        lPt.append(Chain._lPt[l])
#    
#    lPtSorted = sorted(lPt)
#    
#    if lPtSorted[0] < 10 or lPtSorted[1] < 15 or lPtSorted[2] < 25:             return False
    
    #Missing energy cut
    if Chain._met < 50.:                                                        return False

    #B-tag veto
    contains_B_Jet = False 
    for jet in xrange(ord(Chain._nJets)):
        if not objSel.isCleanJet(Chain, jet):                                   continue
        if Chain._jetCsvV2[jet]  > 0.8484:                                      contains_B_Jet = True
    
    if contains_B_Jet:                                                          return False

    return True  

def getNTau():
    return nTau
