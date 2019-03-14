import ROOT
import objectSelection as objSel
import helpers
from ROOT import TLorentzVector

class generalEventSelector(object):
    
    def __init__(self, Chain):
        self.Chain = Chain
        self.nTau = 0
        
        #Old MVA working points
        self.IsoWorkingPoints = (Chain._lPOGVeto, Chain._lPOGLoose, Chain._lPOGMedium, Chain._lPOGTight, Chain._tauVTightMvaOld)
        
        #Electron discrimination working points
        self.ElectronWorkingPoints = (None, Chain._tauEleVetoVLoose, Chain._tauEleVetoLoose, Chain._tauEleVetoMedium, Chain._tauEleVetoTight, Chain._tauEleVetoVTight)
        
        #Muon discrimination working points
        self.MuonWorkingPoints = (None, Chain._tauMuonVetoLoose, Chain._tauMuonVetoTight)
        
    def ptIsGood(self, lIndex):
        lPt = []
        for l in lIndex:
            lPt.append(self.Chain._lPt[l])
        
        sortedList = helpers.sortByOtherList(lIndex, lPt)
        lPt = sorted(lPt)

        #Look at leading lepton
        if self.Chain._lFlavor[sortedList[2]] == 1:
            if self.Chain._lFlavor[sortedList[1]] != 1 or self.Chain._lFlavor[sortedList[0]] != 1:
                if lPt[2] < 25:       return False
            elif lPt[2] < 25:         return False                                      #Change this back

        elif self.Chain._lFlavor[sortedList[2]] == 0:
            if lPt[2] < 20:           return False
        
        #Look at subleading lepton
        if self.Chain._lFlavor[sortedList[1]] == 1:
            if lPt[1] < 15:           return False
        else:
            if lPt[1] < 10:           return False

        #Look at trailing lepton
        if lPt[0] < 10:               return False

        #If two taus, ...
        if self.nTau == 2:
            for l in lIndex:
                if self.Chain._lFlavor[l] == 0:
                    if self.Chain._lPt[l] < 30: continue
                if self.Chain._lFlavor[l] == 1:
                    if self.Chain._lPt[l] < 25: continue
                    
        return True

    def passedInvariantMassCuts(self, lIndex):
        vec = []
        for l in lIndex:
            v = TLorentzVector()
            v.SetPtEtaPhiE(self.Chain._lPt[l], self.Chain._lEta[l], self.Chain._lPhi[l], self.Chain._lE[l])
            vec.append(v)
        Mlll = (vec[0] + vec[1] + vec[2]).M()
        if abs(Mlll-91.19) < 15 :  return False
        return True

    def isGoodEvent(self, iso_cut_index, ele_cut_index, mu_cut_index):

        #Select good leptons and save indices
        lIndex = []
        self.nTau = 0
        for l in xrange(ord(self.Chain._nL)):
            if not objSel.isGoodLepton(self.Chain, l):                                  continue

        #    print self.Chain._lFlavor[l]
            #Tau selection cuts
            if self.Chain._lFlavor[l] == 2:
                if not self.IsoWorkingPoints[iso_cut_index][l]:                         continue

                if ele_cut_index == 0:                                                  pass
                elif not self.ElectronWorkingPoints[ele_cut_index][l]:                  continue

                if mu_cut_index == 0:                                                   pass
                elif not self.MuonWorkingPoints[mu_cut_index][l]:                       continue

            lIndex.append(l)
            if self.Chain._lFlavor[l] == 2: self.nTau += 1
        
        #Keep only events with exactly 3 good leptons
        if len(lIndex) != 3:                                                            return False
        
        #Keep only events with 1 or 2 taus
        if self.nTau == 0 or self.nTau == 3:                                            return False

        #Perform pt cuts
        if not self.ptIsGood(lIndex):                                                   return False

        #Invariant mass cut
        if self.passedInvariantMassCuts(lIndex):                                        return False
        
        #Missing energy cut
        if self.Chain._met < 50.:                                                        return False

        #B-tag veto
        contains_B_Jet = False
        for jet in xrange(ord(self.Chain._nJets)):
            if not objSel.isCleanJet(self.Chain, jet):                                   continue
            if self.Chain._jetCsvV2[jet]  > 0.8484:                                      contains_B_Jet = True
        if contains_B_Jet:                                                               return False
        
        return True


class eventSelector(generalEventSelector):
    
    def __init__(self, Chain, ele_cut_index, mu_cut_index):
        super(eventSelector, self).__init__(Chain)
        self.ele_cut_index = ele_cut_index
        self.mu_cut_index = mu_cut_index

    def isGoodEvent(self, iso_cut_index):
        return super(eventSelector, self).isGoodEvent(iso_cut_index, self.ele_cut_index, self.mu_cut_index) 
