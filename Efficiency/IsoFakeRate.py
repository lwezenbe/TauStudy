import ROOT
import argparse
from ROOT import TLorentzVector, TH1D
from numpy import zeros, savetxt
import Constants as cst
import Sample
from helpers import progress, makeDirIfNeeded, showBranch
from objectSelection import findMatchLepton, lepHasOverlap 
from eventSelection import ZMassReconstructed

argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='DYJetsToLL_M-50') 
argParser.add_argument('--subJob',      action='store',         default=0) 
argParser.add_argument('--method',      action='store',         default='Bluj') 
argParser.add_argument('--inputFile',   action='store',         default='inputFiles') 
argParser.add_argument('--isTest',      action='store',         default=False) 
 
args = argParser.parse_args() 
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+ args.inputFile  +'.conf') 
sample = Sample.getSampleFromList(sampleList, args.sampleName)

branches = ["_nJets", "_jetPt", "_jetEta", "_jetPhi", "_jetE", 
        "_nL", "_lPt", "_lEta", "_lPhi", "_lE", 
        "_weight",
        "_decayModeFinding", "_lPOGVeto", "_lPOGLoose", "_lPOGMedium", "_lPOGTight", "_tauVTightMvaOld",
        "_tauVLooseMvaNew", "_tauLooseMvaNew", "_tauMediumMvaNew", "_tauTightMvaNew", "_tauVTightMvaNew",
        "_tauCombinedIsoDBRaw3Hits"]

print 'Initializing'
Chain = sample.initTree()

#################################################################################################
#####################################METHOD FUNCTIONS############################################
#depending on the method variable, the efficiency is calculated in one of the ways defined below#
#############Temporarily here because I didnt know what to do with it yet########################
#################################################################################################

def CalcANFakeRate(Chain, sample, args):
    global totJets
    global passedTau
    global ptHistNum
    global ptHisDenom
    global etaHistNum
    global etaHistDenom

    for jet in xrange(ord(Chain._nJets)):
       
        if Chain._jetPt[jet] < 20 or abs(Chain._jetEta[jet]) > 2.3:          continue
        
        totJets += 1.
        ptHistDenom.Fill(Chain._jetPt[jet], Chain._weight)
        etaHistDenom.Fill(Chain._jetEta[jet], Chain._weight)

        jetVec = TLorentzVector()
        jetVec.SetPtEtaPhiE(Chain._jetPt[jet], Chain._jetEta[jet], Chain._jetPhi[jet], Chain._jetE[jet])

        #Find matching reco tau
        matchindex = 0
        minDeltaR = 999999
        for l in xrange(ord(Chain._nL)):
            if not Chain._lFlavor[l] == 2:                                              continue
            
            if lepHasOverlap(Chain, l):                                           continue

            lVec = TLorentzVector()
            lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

            deltaR = lVec.DeltaR(jetVec)
            if deltaR < minDeltaR:
                minDeltaR = deltaR
                matchindex = l

        if minDeltaR > .3:                                                               continue

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
                    ptHistNum[discr][WP].Fill(Chain._jetPt[jet], Chain._weight)
                    etaHistNum[discr][WP].Fill(Chain._jetEta[jet], Chain._weight)

def CalcWillemFakeRate(Chain, sample, args):
    global totJets
    global passedTau
    global ptHistNum
    global ptHisDenom
    global etaHistNum
    global etaHistDenom

    for lepton in xrange(ord(Chain._nL)):

        if not Chain._lFlavor[lepton] == 2:                                     continue

        if Chain._lIsPrompt[lepton]:                                            continue

        if Chain._lPt[genlepton] < 20 or abs(Chain._lEta[genlepton] > 2.3):     continue

        totJets += 1.
        ptHistDenom.Fill(Chain._lPt[lepton], Chain._weight)
        etaHistDenom.Fill(Chain._lEta[lepton], Chain._weight)

        if not Chain._decayModeFinding[lepton]:                                 continue

        discriminator = []
        discriminator.append([Chain._lPOGVeto[matchindex], Chain._lPOGLoose[matchindex], Chain._lPOGMedium[matchindex], Chain._lPOGTight[matchindex], Chain._tauVTightMvaOld[matchindex]])
        discriminator.append([Chain._tauVLooseMvaNew[matchindex], Chain._tauLooseMvaNew[matchindex], Chain._tauMediumMvaNew[matchindex], Chain._tauTightMvaNew[matchindex], Chain._tauVTightMvaNew[matchindex]])
        iso = Chain._tauCombinedIsoDBRaw3Hits[matchindex]
        discriminator.append([iso < 4.5, iso < 3.5, iso < 2.0, iso < 1.0, iso < 0.8])

        for discr in xrange(len(cst.discriminatorNames)):
            if discr == discriminatorNames.index('Cut_Based'):
                workingPoints = cst.workingPointsCut
            else:
                workingPoints = cst.workingPointsMVA

            for WP in xrange(len(workingPoints)):
                if discriminator[discr][WP]:
                    passedTau[discr][WP] += 1.
                    ptHistNum[discr][WP].Fill(Chain._lPt[lepton], Chain._weight)
                    etaHistNum[discr][WP].Fill(Chain._lEta[lepton], Chain._weight)

def CalcBlujFakeRate(Chain, sample, args):
    global totJets
    global passedTau
    global ptHistNum
    global ptHisDenom
    global etaHistNum
    global etaHistDenom
    global testd
    global testn
    global testmu
    global testele
 
    for jet in xrange(ord(Chain._nJets)):
   
        if Chain._jetPt[jet] < 20 or abs(Chain._jetEta[jet]) > 2.3:                     continue

        jetVec = TLorentzVector()
        jetVec.SetPtEtaPhiE(Chain._jetPt[jet], Chain._jetEta[jet], Chain._jetPhi[jet], Chain._jetE[jet])

        #Find matching reco tau
        
        matchindex = 0
        minDeltaR = 999999
        for l in xrange(ord(Chain._nL)):
            if not Chain._lFlavor[l] == 2:                                              continue

            if Chain._lIsPrompt[l]:                                                     continue

            if lepHasOverlap(Chain, l):                                                 continue        
    
#            if findMatchLepton(Chain, l) != -1:                                         continue
            
            
            lVec = TLorentzVector()
            lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

            deltaR = lVec.DeltaR(jetVec)
            if deltaR < minDeltaR:
                minDeltaR = deltaR
                matchindex = l

        if minDeltaR > .3:                                                              continue
        
        testd += 1.
        if findMatchLepton(Chain, matchindex) != -1:          
            testn += 1.
            if Chain._gen_lFlavor[findMatchLepton(Chain, matchindex)] == 0:     
                testele += 1.
            if Chain._gen_lFlavor[findMatchLepton(Chain, matchindex)] == 1:     
                testmu += 1.
        
        if findMatchLepton(Chain, matchindex) != -1:                                   continue 
#        if ord(Chain._nLight) < 2:                                                      continue

        #if ord(Chain._nLight) < 2:
#        print matchindex, jet
#        Chain.Show(entry)  

        #if not ZMassReconstructed(Chain):                                              continue
        
        #if not ZMassReconstructed(Chain) and Chain._lPOGLoose[matchindex]: 
        #    print '----------------------------------'
        #    print '--------WEEWOO NEW EVENT---------'
        #    print '--------------------------------- \n'
        #    print entry, matchindex, jet
        #    print '\n ++++In principle this is gen++++'
        #    print showBranch(Chain._gen_lFlavor)
        #    print showBranch(Chain._gen_lIsPrompt)
        #    print showBranch(Chain._gen_lEta)
        #    print showBranch(Chain._gen_lPhi)
        #    print showBranch(Chain._lMomPdgId)
        #    print showBranch(Chain._gen_lDecayedHadr)
        #    print '\n ********Reco Bello********'
        #    print showBranch(Chain._lFlavor)
        #    print showBranch(Chain._lIsPrompt)
        #    print showBranch(Chain._lPOGLoose)
        #    print showBranch(Chain._lEta)
        #    print showBranch(Chain._lPhi)
        #    print showBranch(Chain._lMatchPdgId)
        #    print showBranch(Chain._lMatchDecayedHadr)
        #    print '\n #######Bring out your jets#######'
        #    print Chain._jetPt[jet], Chain._jetEta[jet], Chain._jetPhi[jet], '\n'
        #    print showBranch(Chain._jetEta)
        #    print showBranch(Chain._jetPhi)
                    
        #    if(ord(Chain._nMu) == 2 or ord(Chain._nEle)==2): Chain.Show(entry) 
        
        totJets += 1.
        
        ptHistDenom.Fill(Chain._jetPt[jet], Chain._weight)
        etaHistDenom.Fill(Chain._jetEta[jet], Chain._weight)

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
                    ptHistNum[discr][WP].Fill(Chain._jetPt[jet], Chain._weight)
                    etaHistNum[discr][WP].Fill(Chain._jetEta[jet], Chain._weight)


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

testn=0
testd=0
testmu=0
testele=0
#event loop

if args.isTest:
    eventRange = xrange(5000)
else:
    eventRange = sample.getEventRange(int(args.subJob))

for entry in eventRange:
    Chain.GetEntry(entry)
    if args.method == 'AN':             CalcANFakeRate(Chain, sample, args)
    elif args.method == 'Willem':       CalcWillemFakeRate(Chain, sample, args)
    elif args.method == 'Bluj':         CalcBlujFakeRate(Chain, sample, args)
    else:
        print('NOOO, GOD! NO, GOD, PLEASE, NO! NO! NO! ')
        time.sleep(2.5)
        print('NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!')
        time.sleep(1)
        print('Please enter proper method argument')
        exit()

print totJets, passedTau[0]

#save
if not args.isTest:
    basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/Iso/'
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
