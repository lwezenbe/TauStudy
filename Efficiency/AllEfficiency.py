import ROOT, time
import argparse
from ROOT import TLorentzVector, TH1D
from numpy import zeros, savetxt
import Constants as cst
import Sample
from helpers import makeDirIfNeeded, progress
from objectSelection import lepHasOverlap, geometricMatch

argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='WZJets') 
argParser.add_argument('--subJob',      action='store',         default=0) 
argParser.add_argument('--method',      action='store',         default='Default') 
argParser.add_argument('--inputFile',   action='store',         default='inputFiles') 
argParser.add_argument('--isTest',      action='store',         default=False) 
 
args = argParser.parse_args() 
 
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+args.inputFile+'.conf') 
sample = Sample.getSampleFromList(sampleList, args.sampleName)
print sample.output
Chain = sample.initTree()

#################################################################################################
#####################################METHOD FUNCTIONS############################################
#depending on the method variable, the efficiency is calculated in one of the ways defined below#
#############Temporarily here because I didnt know what to do with it yet########################
#################################################################################################

def FillEfficiency(Chain, sample, args):
    global totTau
    global passedTau
    global ptHistNum
    global ptHisDenom
    global etaHistNum
    global etaHistDenom
    for lepton in xrange(ord(Chain._nL)):
        
        if not Chain._lFlavor[lepton] == 2:                                      continue

#        if not Chain._lIsPrompt[lepton]:                                         continue
        if geometricMatch(Chain, lepton) == -1:                                  continue

        if Chain._lPt[lepton] < 20 or abs(Chain._lEta[lepton]) > 2.3:            continue
        
        #if lepHasOverlap(Chain, lepton):                                         continue
        
        #if not Chain._lMatchDecayedHadr[lepton]:                                 continue

        totTau += 1.
        ptHistDenom.Fill(Chain._lPt[lepton], Chain._weight)
        etaHistDenom.Fill(Chain._lEta[lepton], Chain._weight)

        #if lepHasOverlap(Chain, lepton):                                         continue
        if not Chain._decayModeFinding[lepton]:                                  continue
        #if not Chain._tauEleVetoLoose[lepton]:                                   continue
        if not Chain._tauMuonVetoLoose[lepton]:                                  continue

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


###########
#Main body#
###########

#Initialize output (Generalize this if needed)
totTau = 0.
passedTau = zeros((3,5))

ptHistDenom = TH1D("pt_efficiency_denom", "pt_efficiency_denom", 10, 20, 120)
etaHistDenom = TH1D("eta_efficiency_denom", "eta_efficiency_denom", 24, -2.4, 2.4)

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
    eventRange = xrange(5000)
else:
    eventRange = sample.getEventRange(int(args.subJob))

#Start Loop
for entry in eventRange: 
    Chain.GetEntry(entry) 
  
    progress = progress(entry, len(eventRange))
 
    FillEfficiency(Chain, sample, args)
   
print passedTau, totTau
 
if not args.isTest:
    #Save output
    basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/All/'
    makeDirIfNeeded(basefolder)
    makeDirIfNeeded(basefolder+sample.output)
    makeDirIfNeeded(basefolder+sample.output+'/'+args.method)
    basefolder = basefolder + sample.output + '/' + args.method
    savetxt(basefolder+'/efficiency_totTau_subjob'+str(args.subJob)+'.dat', [totTau])
    savetxt(basefolder+'/efficiency_passedTau_subjob'+str(args.subJob)+'.dat', passedTau)
    ptHistDenom.SaveAs(basefolder+'/pt_efficiency_denom_subjob'+str(args.subJob)+'.root')
    etaHistDenom.SaveAs(basefolder+'/eta_efficiency_denom_subjob'+str(args.subJob)+'.root')
    for discr in cst.discriminatorNames:
        if discr == 'Cut_Based':
            workingPoints = cst.workingPointsCut
        else:
            workingPoints = cst.workingPointsMVA
        for WP in workingPoints:
            ptHistNum[cst.discriminatorNames.index(discr)][workingPoints.index(WP)].SaveAs(basefolder+'/pt_efficiency_num_'+discr+'_'+WP+'_subjob'+str(args.subJob)+'.root') 
            etaHistNum[cst.discriminatorNames.index(discr)][workingPoints.index(WP)].SaveAs(basefolder+'/eta_efficiency_num_'+discr+'_'+WP+'_subjob'+str(args.subJob)+'.root')



