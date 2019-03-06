import ROOT, time
import argparse
from ROOT import TLorentzVector, TH1D
from numpy import zeros, savetxt
import Constants as cst
import Sample
from helpers import makeDirIfNeeded, showBranch
from objectSelection import geometricMatch, matchHasOverlap, lepHasOverlap, findMatchLepton

argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='WZJets') 
argParser.add_argument('--subJob',      action='store',         default=0) 
argParser.add_argument('--method',      action='store',         default='Bluj') 
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

def FillBlujEfficiency(Chain, sample, args):
    global totTau
    global passedTau
    global ptHistNum
    global ptHisDenom
    global etaHistNum
    global etaHistDenom
    for lepton in xrange(ord(Chain._nL)):
        
        if not Chain._lFlavor[lepton] == 2:                                      continue

        #if not Chain._lIsPrompt[lepton]:                                         continue
        #if Chain._lMatchPdgId[lepton] == 22:                                         continue
    
        #if not Chain._lMatchDecayedHadr[lepton]:                                 continue
        #
        #if lepHasOverlap(Chain, lepton):                                       continue
        if geometricMatch(Chain, lepton) == -1:                                       continue


        if False:
            print '----------------------------------'
            print '--------WEEWOO NEW EVENT---------'
            print '--------------------------------- \n'
            print entry, lepton, matchHasOverlap(Chain, lepton), Chain._lumiBlock, Chain._eventNb
            print '\n ++++In principle this is gen++++'
            print 'Flavor:', showBranch(Chain._gen_lFlavor)
            print 'isPrompt:', showBranch(Chain._gen_lIsPrompt)
            print 'pt:', showBranch(Chain._gen_lPt)
            print 'eta:', showBranch(Chain._gen_lEta)
            print 'phi:',showBranch(Chain._gen_lPhi)
            print 'mom pdg:', showBranch(Chain._lMomPdgId)
            print 'decayed hard:',showBranch(Chain._gen_lDecayedHadr)
            print '\n ********Reco Bello********'
            print 'Flavor:', showBranch(Chain._lFlavor)
            print 'isPrompt:', showBranch(Chain._lIsPrompt)
            print 'IsLoose:', showBranch(Chain._lPOGLoose)
            print 'pt:', showBranch(Chain._lPt)
            print 'eta:',showBranch(Chain._lEta)
            print 'phi:',showBranch(Chain._lPhi)
            print 'match pdg:', showBranch(Chain._lMatchPdgId)
            print 'match pt:', showBranch(Chain._lMatchPt)
            print 'match eta:', showBranch(Chain._lMatchEta)
            print 'match phi:', showBranch(Chain._lMatchPhi)
            print 'match decayed hadr:', showBranch(Chain._lMatchDecayedHadr)
            print '\n'


        if Chain._lPt[lepton] < 20 or abs(Chain._lEta[lepton]) > 2.3:            continue

        #if ord(Chain._nLight) < 1:                                               continue

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
        if not Chain._gen_lDecayedHadr[genlepton]:                                      continue
        genTauVec = TLorentzVector()
        genTauVec.SetPtEtaPhiE(Chain._gen_lPt[genlepton], Chain._gen_lEta[genlepton], Chain._gen_lPhi[genlepton], Chain._gen_lE[genlepton])

        #Find matching reco tau
        matchindex = 0
        minDeltaR = 999999
        for l in xrange(ord(Chain._nL)):
            if not Chain._lFlavor[l] == 2:                                              continue

            #if not Chain._lIsPrompt[l]:                                                 continue
#            if Chain._lMatchPdgId[l] == 22:                                             continue
#            if not Chain._lMatchDecayedHadr[l]:                                         continue

            if lepHasOverlap(Chain, l):                                                 continue
#            if findMatchLepton(Chain, l) != -1:                                         continue
    

            lVec = TLorentzVector()
            lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

            deltaR = lVec.DeltaR(genTauVec)
            if deltaR < minDeltaR:
                minDeltaR = deltaR
                matchindex = l
        if minDeltaR > .3:                                                               continue
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
    if args.method == 'AN':             FillANEfficiency(Chain, sample, args)
    elif args.method == 'Bluj':         FillBlujEfficiency(Chain, sample, args)
    else:                               
        print('NOOO, GOD! NO, GOD, PLEASE, NO! NO! NO! ')        
        time.sleep(2.5)
        print('NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!')
        time.sleep(1)
        print('Please enter proper method argument')
        exit()

print passedTau, totTau

if not args.isTest:
    #Save output
    basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/Iso/'
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



