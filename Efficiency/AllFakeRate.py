import ROOT
import argparse
from ROOT import TLorentzVector, TH1D
import Sample
from helpers import progress, makeDirIfNeeded
import numpy as np
import objectSelection as objSel
from efficiency import efficiency
from ROC import ROC

argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='DYJetsToLL_M-50') 
argParser.add_argument('--subJob',      action='store',         default=0) 
argParser.add_argument('--method',      action='store',         default='Default') 
argParser.add_argument('--inputFile',   action='store',         default='inputFilesv3') 
argParser.add_argument('--isTest',      action='store',         default=False) 
 
args = argParser.parse_args() 
 
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+ args.inputFile  +'.conf') 
sample = Sample.getSampleFromList(sampleList, args.sampleName)

Chain = sample.initTree(needhCount=False)

#Define the algorithms and their working points
tau_id_algos = [('oldMVA', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('newMVA', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('cut_based', ['VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight'])]   #If you add more ID's, don't forget to change it in the getTauIDs() function in objectSelection as well

#################################################################################################
#####################################METHOD FUNCTIONS############################################
#depending on the method variable, the efficiency is calculated in one of the ways defined below#
#############Temporarily here because I didnt know what to do with it yet########################
#################################################################################################

def CalcFakeRate(Chain, sample, args):
    global roc
    global ptHist
    global etaHist

    for lepton in xrange(Chain._nL):

        if not objSel.isFakeTau(Chain, lepton):     continue

        for i in xrange(len(tau_id_algos)):
            roc[i].fill_misid_denominator(Chain._weight)
            ptHist[i].fill_denominator(Chain._lPt[lepton], Chain._weight)
            etaHist[i].fill_denominator(Chain._lEta[lepton], Chain._weight)

        if objSel.lepHasOverlap(Chain, lepton):                                        continue
        if not Chain._tauEleVetoVLoose[lepton]:                                  continue
        if not Chain._tauMuonVetoLoose[lepton]:                                 continue

        DMfinding = objSel.getDMfinding(Chain, lepton)
        discriminators = objSel.getTauIDs(Chain, lepton) 

        for i, discr in enumerate(discriminators):
            if not DMfinding[i]: continue

            for j, WP in enumerate(discr):
                if WP:
                    roc[i].fill_misid_numerator(j, Chain._weight)
                    ptHist[i].fill_numerator(Chain._lPt[lepton], j, Chain._weight)
                    etaHist[i].fill_numerator(Chain._lEta[lepton], j, Chain._weight)

###########
#Main body#
###########

#Whatever needs to be saved at the end
pt_bins = np.linspace(20, 120, 11)
eta_bins = np.linspace(-2.4, 2.4, 25)

basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/All/'
makeDirIfNeeded(basefolder)
makeDirIfNeeded(basefolder+sample.output)
makeDirIfNeeded(basefolder+sample.output+'/'+args.method)
basefolder = basefolder + sample.output + '/' + args.method

roc = []
ptHist = []
etaHist = []
for tau_id in tau_id_algos:
    roc.append(ROC('roc_fakerate_'+tau_id[0], tau_id[1]))
    ptHist.append(efficiency('pt_fakerate_'+tau_id[0], pt_bins, tau_id[1]))
    etaHist.append(efficiency('eta_fakerate_'+tau_id[0], eta_bins, tau_id[1]))

if args.isTest:
    eventRange = range(5000)
else:
    eventRange = sample.getEventRange(int(args.subJob))

#event loop
for entry in eventRange:
    Chain.GetEntry(entry)
    
    CalcFakeRate(Chain, sample, args)
     
if not args.isTest:
    #save
    for i in xrange(len(tau_id_algos)):
        roc[i].write(basefolder, str(args.subJob))
        ptHist[i].write(basefolder, str(args.subJob))
        etaHist[i].write(basefolder, str(args.subJob))
