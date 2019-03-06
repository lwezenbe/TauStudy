import ROOT, time
import argparse
from ROOT import TLorentzVector, TH1D
from numpy import zeros, savetxt
import Constants as cst
import Sample

def FillBlujEfficiency(Chain, sample, args):
    global totTau
    global passedTau
    global ptHistNum
    global ptHisDenom
    global etaHistNum
    global etaHistDenom
    for lepton in xrange(ord(Chain._nL)):
        
        if not Chain._lFlavor[lepton] == 2:                                      continue

        if not Chain._lIsPrompt[lepton]:                                         continue

        if Chain._lPt[lepton] < 20 or abs(Chain._lEta[lepton]) > 2.3:      continue

        genTauVec = TLorentzVector()
        genTauVec.SetPtEtaPhiE(Chain._lPt[lepton], Chain._lEta[lepton], Chain._lPhi[lepton], Chain._lE[lepton])

        totTau += 1.
        ptHistDenom.Fill(Chain._lPt[lepton], Chain._weight)
        etaHistDenom.Fill(Chain._lEta[lepton], Chain._weight)

        if not Chain._decayModeFinding[lepton]:                                   continue

        discriminator = []
        discriminator.append([Chain._lPOGVeto[lepton], Chain._lPOGLoose[lepton], Chain._lPOGMedium[lepton], Chain._lPOGTight[lepton], Chain._tauVTightMvaOld[lepton]])
        discriminator.append([Chain._tauVLooseMvaNew[lepton], Chain._tauLooseMvaNew[lepton], Chain._tauMediumMvaNew[lepton], Chain._tauTightMvaNew[lepton], Chain._tauVTightMvaNew[lepton]])
        iso = Chain._tauCombinedIsoDBRaw3Hits[lepton]
        discriminator.append([iso < 4.5, iso < 3.5, iso < 2.0, iso < 1.0, iso < 0.8])

        for discr in xrange(len(cst.discriminatorNames)):
            if discr == 2:
                workingPoints = cst.workingPointsCut
            else:
                workingPoints = cst.workingPointsMVA

            for WP in xrange(len(workingPoints)):
                if discriminator[discr][WP]:
                    passedTau[discr][WP] += 1.
                    ptHistNum[discr][WP].Fill(Chain._lPt[lepton], Chain._weight)
                    etaHistNum[discr][WP].Fill(Chain._lEta[lepton], Chain._weight)

def FillANEfficiency(Chain, sample, args):
    global totTau
    global passedTau
    global ptHistNum
    global ptHisDenom
    global etaHistNum
    global etaHistDenom
    for genlepton in xrange(ord(Chain._gen_nL)):
        if not Chain._gen_lFlavor[genlepton] == 2:                                      continue
        if not Chain._gen_lIsPrompt[genlepton]:                                         continue
        if Chain._gen_lPt[genlepton] < 20 or abs(Chain._gen_lEta[genlepton]) > 2.3:     continue
        genTauVec = TLorentzVector()
        genTauVec.SetPtEtaPhiE(Chain._gen_lPt[genlepton], Chain._gen_lEta[genlepton], Chain._gen_lPhi[genlepton], Chain._gen_lE[genlepton])

        #Find matching reco tau
        matchindex = 0
        minDeltaR = 999999
        for l in xrange(ord(Chain._nL)):
            if not Chain._lFlavor[l] == 2:                                              continue
            lVec = TLorentzVector()
            lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

            deltaR = lVec.DeltaR(genTauVec)
            if deltaR < minDeltaR:
                minDeltaR = deltaR
                matchindex = l
        if minDeltaR > .2:                                                               continue
        totTau += 1.
        ptHistDenom.Fill(Chain._gen_lPt[genlepton], Chain._weight)
        etaHistDenom.Fill(Chain._gen_lEta[genlepton], Chain._weight)

        if not Chain._decayModeFinding[matchindex]:                                      continue

        discriminator = []
        discriminator.append([Chain._lPOGVeto[matchindex], Chain._lPOGLoose[matchindex], Chain._lPOGMedium[matchindex], Chain._lPOGTight[matchindex], Chain._tauVTightMvaOld[matchindex]])
        discriminator.append([Chain._tauVLooseMvaNew[matchindex], Chain._tauLooseMvaNew[matchindex], Chain._tauMediumMvaNew[matchindex], Chain._tauTightMvaNew[matchindex], Chain._tauVTightMvaNew[matchindex]])
        iso = Chain._tauCombinedIsoDBRaw3Hits[matchindex]
        discriminator.append([iso < 4.5, iso < 3.5, iso < 2.0, iso < 1.0, iso < 0.8])

        for discr in xrange(len(cst.discriminatorNames)):
            if discr == 2:
                workingPoints = cst.workingPointsCut
            else:
                workingPoints = cst.workingPointsMVA

            for WP in xrange(len(workingPoints)):
                if discriminator[discr][WP]:
                    passedTau[discr][WP] += 1.
                    ptHistNum[discr][WP].Fill(Chain._gen_lPt[genlepton], Chain._weight)
                    etaHistNum[discr][WP].Fill(Chain._gen_lEta[genlepton], Chain._weight)

