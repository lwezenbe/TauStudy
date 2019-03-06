import ROOT
import argparse
from ROOT import TLorentzVector, TH1D
from numpy import zeros, savetxt
import Constants as cst
import Sample
from helpers import progress, makeDirIfNeeded
import leptonSelection as lepSel

argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='DYJetsToLL_M-50') 
argParser.add_argument('--subJob',      action='store',         default=0) 
argParser.add_argument('--method',      action='store',         default='AN') 
argParser.add_argument('--inputFile',   action='store',         default='inputFiles') 
argParser.add_argument('--isTest',      action='store',         default=False) 
 
args = argParser.parse_args() 
print 'start'
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+args.inputFile+'.conf') 
sample = Sample.getSampleFromList(sampleList, args.sampleName)
print sample.output
Chain = sample.initTree()
print 'initialized'
#Whatever needs to be saved at the end
totLightLep = [0.0, 0.0]
passedTau = [[0., 0., 0. , 0., 0.], [0.,0.,0.,0.,0.]]

ptHistDenom = TH1D("pt_fakerate_denom", "pt_fakerate_denom", 10, 20, 120)
etaHistDenom = TH1D("eta_fakerate_denom", "eta_fakerate_denom", 24, -2.4, 2.4)

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
    for lep in xrange(ord(Chain._gen_nL)):

            if Chain._gen_lPt[lep] < 20 or abs(Chain._gen_lEta[lep]) > 2.3 or Chain._gen_lFlavor[lep] == 2:          continue

            lightLepVec = TLorentzVector()
            lightLepVec.SetPtEtaPhiE(Chain._gen_lPt[lep], Chain._gen_lEta[lep], Chain._gen_lPhi[lep], Chain._gen_lE[lep])

            #Find matching reco tau
            matchindex = 0
            minDeltaR = 999999
            for l in xrange(ord(Chain._nL)):
                if not Chain._lFlavor[l] == 2:                                              continue

                lVec = TLorentzVector()
                lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

                deltaR = lVec.DeltaR(lightLepVec)
                if deltaR < minDeltaR:
                    minDeltaR = deltaR
                    matchindex = l

            if minDeltaR > .3:                                                               continue
            
            if Chain._lIsPrompt[matchindex]:                                                 continue
            if not Chain._decayModeFinding[matchindex]:                                      continue
            if not Chain._lPOGLoose[matchindex]:                                             continue

            totLightLep[Chain._gen_lFlavor[lep]] += 1.
            ptHistDenom.Fill(Chain._gen_lPt[lep], Chain._weight)
            etaHistDenom.Fill(Chain._gen_lEta[lep], Chain._weight)

            discriminatorEle = [Chain._tauEleVetoVLoose[matchindex], Chain._tauEleVetoLoose[matchindex], Chain._tauEleVetoMedium[matchindex], Chain._tauEleVetoTight[matchindex], Chain._tauEleVetoVTight[matchindex]]
            discriminatorMu = [Chain._tauMuonVetoLoose[matchindex], Chain._tauMuonVetoTight[matchindex] ]
           
            if Chain._gen_lFlavor[lep] == 1: 
                for i, WP in enumerate(discriminatorMu):
                    if WP:
                        passedTau[0][i] += 1.
                        ptHistNum[0][i].Fill(Chain._lPt[matchindex], Chain._weight)
                        etaHistNum[0][i].Fill(Chain._lEta[matchindex], Chain._weight)

            if Chain._gen_lFlavor[lep] == 0: 
                for i, WP in enumerate(discriminatorEle):
                    if WP:
                        passedTau[1][i] += 1.
                        ptHistNum[1][i].Fill(Chain._lPt[matchindex], Chain._weight)
                        etaHistNum[1][i].Fill(Chain._lEta[matchindex], Chain._weight)

print passedTau, totLightLep 

if not args.isTest:
    #Create File structure
    basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/LepDiscr/'
    makeDirIfNeeded(basefolder)
    makeDirIfNeeded(basefolder + sample.output)
    makeDirIfNeeded(basefolder+sample.output+'/'+args.method)
    basefolder = basefolder + sample.output + '/' + args.method

    #Save
    savetxt(basefolder+'/fakerate_totJets_'+sample.name + '_subjob'+str(args.subJob)+'.dat', totLightLep)
    savetxt(basefolder+'/fakerate_passedTau_'+sample.name + 'subjob'+str(args.subJob)+'.dat', passedTau)
    ptHistDenom.SaveAs(basefolder+'/pt_fakerate_denom_'+sample.name + 'subjob'+str(args.subJob)+'.root')
    etaHistDenom.SaveAs(basefolder+'/eta_fakerate_denom_'+sample.name + 'subjob'+str(args.subJob)+'.root')
    for discr in cst.lightLepDiscriminatorNames:
        if discr == 'MuonDiscr':
            workingPoints = cst.workingPointsMu
        else:
            workingPoints = cst.workingPointsEle
        for WP in workingPoints:
            ptHistNum[cst.lightLepDiscriminatorNames.index(discr)][workingPoints.index(WP)].SaveAs(basefolder+'/pt_fakerate_num_'+discr+'_'+WP+'_'+sample.name + 'subjob'+str(args.subJob)+'.root') 
            etaHistNum[cst.lightLepDiscriminatorNames.index(discr)][workingPoints.index(WP)].SaveAs(basefolder+'/eta_fakerate_num_'+discr+'_'+WP+'_'+sample.name + 'subjob'+str(args.subJob)+'.root')

