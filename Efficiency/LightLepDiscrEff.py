import ROOT
import argparse
from ROOT import TLorentzVector, TH1D
from numpy import zeros, savetxt
import Constants as cst
import Sample
from helpers import makeDirIfNeeded, showBranch
import objectSelection as lepSel

argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='WZJets') 
argParser.add_argument('--subJob',      action='store',         default=None) 
argParser.add_argument('--method',      action='store',         default='AN')                           #Currently no use except for consistent file structure until next iteration 
argParser.add_argument('--inputFile',   action='store',         default='inputFiles') 
argParser.add_argument('--isTest',      action='store',         default=False) 
 
args = argParser.parse_args() 
 
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+args.inputFile+'.conf') 
sample = Sample.getSampleFromList(sampleList, args.sampleName)
print sample.output
Chain = sample.initTree()

#Whatever needs to be saved at the end
totTau = 1 
passedTau = [[0,0, 0, 0, 0], [0,0,0,0,0]]

ptHistDenom = TH1D("pt_efficiency_denom", "pt_efficiency_denom", 10, 20, 120)
etaHistDenom = TH1D("eta_efficiency_denom", "eta_efficiency_denom", 24, -2.4, 2.4)

ptHistNum = []
etaHistNum = []
for discr in cst.lightLepDiscriminatorNames:
    tmppt = []
    tmpeta = []
    if discr == 'MuonDiscr':
        workingPoints = cst.workingPointsMu
    else:
        workingPoints = cst.workingPointsEle
    for WP in workingPoints:
        tmppt.append(TH1D("pt_efficiency_num_"+ discr + "_" + WP, "pt_efficiency_num"+ discr + "_" + WP, 10, 20, 120))
        tmpeta.append(TH1D("eta_efficiency_num"+ discr + "_" + WP, "eta_efficiency_num"+ discr + "_" + WP, 24, -2.4, 2.4))
    ptHistNum.append(tmppt)
    etaHistNum.append(tmpeta)

if args.isTest:
    eventrange = xrange(5000)
else:
    eventrange = sample.getEventRange(int(args.subJob))

for entry in eventrange:
    Chain.GetEntry(entry)

    for lepton in xrange(ord(Chain._nL)):
        
        if not Chain._lFlavor[lepton] == 2:                                     continue

        if not Chain._lIsPrompt[lepton]:                                        continue
        
        if lepSel.lepHasOverlap(Chain, lepton):                                 continue
        if lepSel.findMatchLepton(Chain, lepton) != -1:                                 continue

        if not Chain._lMatchDecayedHadr[lepton]:                               
            print '----------------------------------'
            print '--------WEEWOO NEW EVENT---------'
            print '--------------------------------- \n'
            print entry, lepton
            print '\n ++++In principle this is gen++++'
            print showBranch(Chain._gen_lFlavor)
            print showBranch(Chain._gen_lIsPrompt)
            print showBranch(Chain._gen_lEta)
            print showBranch(Chain._gen_lPhi)
            print showBranch(Chain._lMomPdgId)
            print showBranch(Chain._gen_lDecayedHadr)
            print '\n ********Reco Bello********'
            print showBranch(Chain._lFlavor)
            print showBranch(Chain._lIsPrompt)
            print showBranch(Chain._lPOGLoose)
            print showBranch(Chain._lPt)
            print showBranch(Chain._lEta)
            print showBranch(Chain._lPhi)
            print showBranch(Chain._lMatchPdgId)
            print showBranch(Chain._lMatchPt)
            print showBranch(Chain._lMatchEta)
            print showBranch(Chain._lMatchPhi)
            print showBranch(Chain._lMatchDecayedHadr)
            print '\n'

        if not Chain._lMatchDecayedHadr[lepton]:                                continue          

        if Chain._lPt[lepton] < 20 or abs(Chain._lEta[lepton]) > 2.3:           continue
        
        if not Chain._lPOGLoose[lepton]:                                        continue

        if not Chain._decayModeFinding[lepton]:                                 continue
        
        genTauVec = TLorentzVector()
        genTauVec.SetPtEtaPhiE(Chain._lPt[lepton], Chain._lEta[lepton], Chain._lPhi[lepton], Chain._lE[lepton])

        totTau += 1.
        ptHistDenom.Fill(Chain._lPt[lepton], Chain._weight)
        etaHistDenom.Fill(Chain._lEta[lepton], Chain._weight)

        discriminatorEle = [Chain._tauEleVetoVLoose[lepton], Chain._tauEleVetoLoose[lepton], Chain._tauEleVetoMedium[lepton], Chain._tauEleVetoTight[lepton], Chain._tauEleVetoVTight[lepton]]
        discriminatorMu = [Chain._tauMuonVetoLoose[lepton], Chain._tauMuonVetoTight[lepton] ]

        
        for i, WP in enumerate(discriminatorMu):
            if WP:
                passedTau[0][i] += 1.
                ptHistNum[0][i].Fill(Chain._lPt[lepton], Chain._weight)
                etaHistNum[0][i].Fill(Chain._lEta[lepton], Chain._weight)

        for i, WP in enumerate(discriminatorEle):
            if WP:
                passedTau[1][i] += 1.
                ptHistNum[1][i].Fill(Chain._lPt[lepton], Chain._weight)
                etaHistNum[1][i].Fill(Chain._lEta[lepton], Chain._weight)

print passedTau, totTau
    
if not args.isTest:        
    basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/LepDiscr/'
    makeDirIfNeeded(basefolder)
    makeDirIfNeeded(basefolder + sample.output)
    makeDirIfNeeded(basefolder+sample.output+'/'+args.method)
    basefolder = basefolder + sample.output + '/' + args.method

    savetxt(basefolder+'/efficiency_totTau_subjob'+str(args.subJob)+'.dat', [totTau])
    savetxt(basefolder+'/efficiency_passedTau_subjob'+str(args.subJob)+'.dat', passedTau)
    ptHistDenom.SaveAs(basefolder+'/pt_efficiency_denom_subjob'+str(args.subJob)+'.root')
    etaHistDenom.SaveAs(basefolder+'/eta_efficiency_denom_subjob'+str(args.subJob)+'.root')
    for discr in cst.lightLepDiscriminatorNames:
        if discr == 'MuonDiscr':
            workingPoints = cst.workingPointsMu
        else:
            workingPoints = cst.workingPointsEle
        for WP in workingPoints:
            ptHistNum[cst.lightLepDiscriminatorNames.index(discr)][workingPoints.index(WP)].SaveAs(basefolder+'/pt_efficiency_num_'+discr+'_'+WP+'_subjob'+str(args.subJob)+'.root') 
            etaHistNum[cst.lightLepDiscriminatorNames.index(discr)][workingPoints.index(WP)].SaveAs(basefolder+'/eta_efficiency_num_'+discr+'_'+WP+'_subjob'+str(args.subJob)+'.root')

