import ROOT
import argparse
from ROOT import TLorentzVector, TH1D
import Sample
from helpers import progress, makeDirIfNeeded, showBranch
from efficiency import efficiency
import objectSelection as objSel
from ROC import ROC
import numpy as np

argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='DYJetsToLL_M-50') 
argParser.add_argument('--subJob',      action='store',         default=0) 
argParser.add_argument('--method',      action='store',         default='AN') 
argParser.add_argument('--inputFile',   action='store',         default='inputFilesv3') 
argParser.add_argument('--isTest',      action='store',         default=False) 
 
args = argParser.parse_args() 
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+args.inputFile+'.conf') 
sample = Sample.getSampleFromList(sampleList, args.sampleName)
Chain = sample.initTree(needhCount=False)

basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/LepDiscr/'
makeDirIfNeeded(basefolder)
makeDirIfNeeded(basefolder + sample.output)
makeDirIfNeeded(basefolder+sample.output+'/'+args.method)
basefolder = basefolder + sample.output + '/' + args.method

#Define the algorithms and their working points
tau_id_algos = [('MuonDiscrMVA', ['Loose',  'Tight']),
                #('MuonDiscrdeeptau', ['VVVLoose', 'VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight', 'VTight', 'VVTight']), 
                ('MuonDiscrdeeptau', ['VLoose', 'Loose', 'Medium', 'Tight']), 
                ('ElectronDiscrMVA', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('ElectronDiscrdeeptau', ['VVVLoose', 'VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight', 'VTight', 'VVTight'])]   #Change getTauLepDiscr() accordingly

#Whatever needs to be saved at the end
pt_bins = np.linspace(20, 120, 11)
eta_bins = np.linspace(-2.4, 2.4, 25)

roc = []
ptHist = []
etaHist = []
for tau_id in tau_id_algos:
    roc.append(ROC('roc_fakerate_'+tau_id[0], tau_id[1]))
    ptHist.append(efficiency('pt_fakerate_'+tau_id[0], pt_bins, tau_id[1]))
    etaHist.append(efficiency('eta_fakerate_'+tau_id[0], eta_bins, tau_id[1]))

if args.isTest:
    eventrange = xrange(5000)
else:
    eventrange = sample.getEventRange(int(args.subJob))
    
for entry in eventrange:
    
    Chain.GetEntry(entry)
    for lep in xrange(Chain._gen_nL):

        if Chain._gen_lPt[lep] < 20 or abs(Chain._gen_lEta[lep]) > 2.3 or Chain._gen_lFlavor[lep] == 2:          continue

        lightLepVec = objSel.getFourVec(Chain._gen_lPt[lep], Chain._gen_lEta[lep], Chain._gen_lPhi[lep], Chain._gen_lE[lep])

        #Find matching reco tau
        matchindex = 0
        minDeltaR = 999999
        for l in xrange(Chain._nL):
            if not Chain._lFlavor[l] == 2:                                              continue

            lVec = objSel.getFourVec(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

            deltaR = lVec.DeltaR(lightLepVec)
            if deltaR < minDeltaR:
                minDeltaR = deltaR
                matchindex = l

        if minDeltaR > .3:                                                               continue
        if Chain._tauGenStatus[matchindex] > 4:                                                 continue
        if not Chain._decayModeFinding[matchindex]:                                      continue
        if not Chain._lPOGLoose[matchindex]:                                             continue
#        print entry, minDeltaR, Chain._tauGenStatus[matchindex], Chain._tauDecayMode[matchindex], Chain._tauEleVetoLoose[matchindex], Chain._tauMuonVetoLoose[matchindex]
        
        discriminators = objSel.getTauLepDiscr(Chain, matchindex) 
        
        if Chain._gen_lFlavor[lep] == 0:  
            selected_discriminators = discriminators[2:] #Only electron discr
            hist_indices = (2, 3)
        elif Chain._gen_lFlavor[lep] == 1:  
            selected_discriminators = discriminators[:2] #Only Muon discr
            hist_indices = (0, 1)

        for i in hist_indices:
            roc[i].fill_misid_denominator(Chain._weight)
            ptHist[i].fill_denominator(Chain._lPt[matchindex], Chain._weight)
            etaHist[i].fill_denominator(Chain._lEta[matchindex], Chain._weight)

        for i, discr in zip(hist_indices, selected_discriminators):
            for j, WP in enumerate(discr):
                if WP:
                    roc[i].fill_misid_numerator(j, Chain._weight)
                    ptHist[i].fill_numerator(Chain._lPt[matchindex], j, Chain._weight)
                    etaHist[i].fill_numerator(Chain._lEta[matchindex], j, Chain._weight)
        
#if not args.isTest:
if True:
    #Save
    for i in xrange(len(tau_id_algos)):
        roc[i].write(basefolder, str(args.subJob))
        ptHist[i].write(basefolder, str(args.subJob))
        etaHist[i].write(basefolder, str(args.subJob))

