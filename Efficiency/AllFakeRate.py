import ROOT
import argparse
from ROOT import TLorentzVector, TH1D
from numpy import zeros, savetxt
import Constants as cst
import Sample
from helpers import progress, makeDirIfNeeded
from objectSelection import lepHasOverlap, geometricMatch

argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='DYJetsToLL_M-50') 
argParser.add_argument('--subJob',      action='store',         default=0) 
argParser.add_argument('--method',      action='store',         default='Default') 
argParser.add_argument('--inputFile',   action='store',         default='inputFiles') 
argParser.add_argument('--isTest',      action='store',         default=False) 
 
args = argParser.parse_args() 
 
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+ args.inputFile  +'.conf') 
sample = Sample.getSampleFromList(sampleList, args.sampleName)

Chain = sample.initTree()

#################################################################################################
#####################################METHOD FUNCTIONS############################################
#depending on the method variable, the efficiency is calculated in one of the ways defined below#
#############Temporarily here because I didnt know what to do with it yet########################
#################################################################################################

def CalcFakeRate(Chain, sample, args):
    global totJets
    global passedTau
    global ptHistNum
    global ptHisDenom
    global etaHistNum
    global etaHistDenom

    for lepton in xrange(ord(Chain._nL)):

        if not Chain._lFlavor[lepton] == 2:                                     continue

        #if Chain._lIsPrompt[lepton]:                                            continue
        if geometricMatch(Chain, lepton) != -1:                                 continue
        #if lepHasOverlap(Chain, lepton):                                        continue

        if Chain._lPt[lepton] < 20 or abs(Chain._lEta[lepton] > 2.3):     continue

        genTauVec = TLorentzVector()
        genTauVec.SetPtEtaPhiE(Chain._lPt[lepton], Chain._lEta[lepton], Chain._lPhi[lepton], Chain._lE[lepton])

        totJets += 1.
        ptHistDenom.Fill(Chain._lPt[lepton], Chain._weight)
        etaHistDenom.Fill(Chain._lEta[lepton], Chain._weight)

        if lepHasOverlap(Chain, lepton):                                        continue
        if not Chain._decayModeFinding[lepton]:                                 continue
        if not Chain._tauEleVetoVLoose[lepton]:                                  continue
        if not Chain._tauMuonVetoLoose[lepton]:                                 continue

        discriminator = []
        discriminator.append([Chain._lPOGVeto[lepton], Chain._lPOGLoose[lepton], Chain._lPOGMedium[lepton], Chain._lPOGTight[lepton], Chain._tauVTightMvaOld[lepton]])
        discriminator.append([Chain._tauVLooseMvaNew[lepton], Chain._tauLooseMvaNew[lepton], Chain._tauMediumMvaNew[lepton], Chain._tauTightMvaNew[lepton], Chain._tauVTightMvaNew[lepton]])
        iso = Chain._tauCombinedIsoDBRaw3Hits[lepton]
        discriminator.append([iso < 4.5, iso < 3.5, iso < 2.0, iso < 1.0, iso < 0.8])

        for discr in xrange(len(cst.discriminatorNames)):
            if discr == cst.discriminatorNames.index('Cut_Based'):
                workingPoints = cst.workingPointsCut
            else:
                workingPoints = cst.workingPointsMVA

            for WP in xrange(len(workingPoints)):
                if discriminator[discr][WP]:
                    passedTau[discr][WP] += 1.
                    ptHistNum[discr][WP].Fill(Chain._lPt[lepton], Chain._weight)
                    etaHistNum[discr][WP].Fill(Chain._lEta[lepton], Chain._weight)


###########
#Main body#
###########

#Whatever needs to be saved at the end
totJets = 0.0
passedTau = zeros((3,5))

ptHistDenom = TH1D("pt_fakerate_denom", "pt_fakerate_denom", 10, 20, 120)
etaHistDenom = TH1D("eta_fakerate_denom", "eta_fakerate_denom", 24, -2.4, 2.4)

ptHistNum = []
etaHistNum = []
for discr in cst.discriminatorNames:
    tmppt = []
    tmpeta = []
    if discr == 'Cut_Based':
        workingPoints = cst.workingPointsCut
    else:
        workingPoints = cst.workingPointsMVA
    for WP in workingPoints:
        tmppt.append(TH1D("pt_efficiency_num_"+ discr + "_" + WP, "pt_efficiency_num"+ discr + "_" + WP, 10, 20, 120))
        tmpeta.append(TH1D("eta_efficiency_num"+ discr + "_" + WP, "eta_efficiency_num"+ discr + "_" + WP, 24, -2.4, 2.4))
    ptHistNum.append(tmppt)
    etaHistNum.append(tmpeta)

if args.isTest:
    eventRange = range(5000)
else:
    eventRange = sample.getEventRange(int(args.subJob))

#event loop
for entry in eventRange:
    Chain.GetEntry(entry)
    
    CalcFakeRate(Chain, sample, args)
   
print passedTau, totJets
     
if not args.isTest:
    #save
    basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/All/'
    makeDirIfNeeded(basefolder)
    makeDirIfNeeded(basefolder+sample.output)
    makeDirIfNeeded(basefolder+sample.output+'/'+args.method)
    basefolder = basefolder + sample.output +'/'+ args.method
    savetxt(basefolder+'/fakerate_totJets_'+sample.name + '_subjob'+str(args.subJob)+'.dat', [totJets])
    savetxt(basefolder+'/fakerate_passedTau_'+sample.name + 'subjob'+str(args.subJob)+'.dat', passedTau)
    ptHistDenom.SaveAs(basefolder+'/pt_fakerate_denom_'+sample.name + 'subjob'+str(args.subJob)+'.root')
    etaHistDenom.SaveAs(basefolder+'/eta_fakerate_denom_'+sample.name + 'subjob'+str(args.subJob)+'.root')
    for discr in cst.discriminatorNames:
        if discr == 'Cut_Based':
            workingPoints = cst.workingPointsCut
        else:
            workingPoints = cst.workingPointsMVA
        for WP in workingPoints:
            ptHistNum[cst.discriminatorNames.index(discr)][workingPoints.index(WP)].SaveAs(basefolder+'/pt_fakerate_num_'+discr+'_'+WP+'_'+sample.name + 'subjob'+str(args.subJob)+'.root') 
            etaHistNum[cst.discriminatorNames.index(discr)][workingPoints.index(WP)].SaveAs(basefolder+'/eta_fakerate_num_'+discr+'_'+WP+'_'+sample.name + 'subjob'+str(args.subJob)+'.root')

