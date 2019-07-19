import ROOT
import argparse
from ROOT import TLorentzVector, TH1D
import numpy as np
import Sample
from helpers import makeDirIfNeeded, showBranch
import objectSelection as objSel
from efficiency import efficiency
from ROC import ROC

argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='WZJets') 
argParser.add_argument('--subJob',      action='store',         default=None) 
argParser.add_argument('--method',      action='store',         default='AN')                           #Currently no use except for consistent file structure until next iteration 
argParser.add_argument('--inputFile',   action='store',         default='inputFilesv3') 
argParser.add_argument('--isTest',      action='store',         default=False) 
 
args = argParser.parse_args() 
 
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+args.inputFile+'.conf') 
sample = Sample.getSampleFromList(sampleList, args.sampleName)
print sample.output
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
    roc.append(ROC('roc_efficiency_'+tau_id[0], tau_id[1]))
    ptHist.append(efficiency('pt_efficiency_'+tau_id[0], pt_bins, tau_id[1]))
    etaHist.append(efficiency('eta_efficiency_'+tau_id[0], eta_bins, tau_id[1]))

if args.isTest:
    eventrange = xrange(5000)
else:
    eventrange = sample.getEventRange(int(args.subJob))

for entry in eventrange:
    Chain.GetEntry(entry)

    for lepton in xrange(Chain._nL):
        if not objSel.isGoodBaseTau(Chain, lepton):     continue
        if Chain._tauGenStatus[lepton] != 5:    continue 
        
        if not Chain._lPOGLoose[lepton]:                                        continue
        if not Chain._decayModeFinding[lepton]:                                 continue

        for i in xrange(len(tau_id_algos)):
            roc[i].fill_eff_denominator(Chain._weight)
            ptHist[i].fill_denominator(Chain._lPt[lepton], Chain._weight)
            etaHist[i].fill_denominator(Chain._lEta[lepton], Chain._weight)

        discriminators = objSel.getTauLepDiscr(Chain, lepton) 

        for i, discr in enumerate(discriminators):
            for j, WP in enumerate(discr):
                if WP:
                    roc[i].fill_eff_numerator(j, Chain._weight)
                    ptHist[i].fill_numerator(Chain._lPt[lepton], j, Chain._weight)
                    etaHist[i].fill_numerator(Chain._lEta[lepton], j, Chain._weight)
        
    
if not args.isTest:        
    for i in xrange(len(tau_id_algos)):
        roc[i].write(basefolder, str(args.subJob))
        ptHist[i].write(basefolder, str(args.subJob))
        etaHist[i].write(basefolder, str(args.subJob))
