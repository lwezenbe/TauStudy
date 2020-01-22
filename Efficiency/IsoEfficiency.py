import ROOT, time
from ROOT import TLorentzVector, TH1D
from helpers_old import makeDirIfNeeded
import objectSelection as objSel
from efficiency import efficiency
import numpy as np
from ROC import ROC

#Parse arguments
import argparse
argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='WZJets') 
argParser.add_argument('--subJob',      action='store',         default=0) 
argParser.add_argument('--method',      action='store',         default='Bluj') 
argParser.add_argument('--inputFile',   action='store',         default='inputFilesv3') 
argParser.add_argument('--isTest',      action='store',         default=False) 
 
args = argParser.parse_args() 

#Get sample and initialize chain
import Sample
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+args.inputFile+'.conf') 
sample = Sample.getSampleFromList(sampleList, args.sampleName)
Chain = sample.initTree(needhCount=False)

#Define the algorithms and their working points
tau_id_algos = [('oldMVA2015', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('newMVA2015', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('oldMVA2017v2', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('newMVA2017v2', ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']),
                ('cut_based', ['VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight']),
                ('deeptau', ['VVVLoose', 'VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight', 'VTight', 'VVTight'])]   #If you add more ID's, don't forget to change it in the getTauIDs() function in objectSelection as well


#################################################################################################
#####################################METHOD FUNCTIONS############################################
#depending on the method variable, the efficiency is calculated in one of the ways defined below#
#############Temporarily here because I didnt know what to do with it yet########################
#################################################################################################

def FillBlujEfficiency(Chain, sample, args):
    global roc
    global ptHist
    global etaHist
    for lepton in xrange(Chain._nL):
        
        if not objSel.isGoodBaseTauIso(Chain, lepton):  continue
        if Chain._tauGenStatus[lepton] != 5:            continue
        
        for i in xrange(len(tau_id_algos)):
            roc[i].fill_eff_denominator(Chain._weight)
            ptHist[i].fill_denominator(Chain._lPt[lepton], Chain._weight)
            etaHist[i].fill_denominator(Chain._lEta[lepton], Chain._weight)

        DMfinding = objSel.getDMfinding(Chain, lepton)
        discriminators = objSel.getTauIDs(Chain, lepton) 

        for i, discr in enumerate(discriminators):
            if not DMfinding[i]: continue
            for j, WP in enumerate(discr):
                if WP:
                    roc[i].fill_eff_numerator(j, Chain._weight)
                    ptHist[i].fill_numerator(Chain._lPt[lepton], j, Chain._weight)
                    etaHist[i].fill_numerator(Chain._lEta[lepton], j, Chain._weight)

def FillANEfficiency(Chain, sample, args):
    global roc
    global ptHist
    global etaHist
    for genlepton in xrange(Chain._gen_nL):
        if not Chain._gen_lFlavor[genlepton] == 2:                                      continue
        if not Chain._gen_lIsPrompt[genlepton]:                                         continue
        if Chain._gen_lPt[genlepton] < 20 or abs(Chain._gen_lEta[genlepton]) > 2.3:     continue
        genTauVec = objSel.GetFourVec(Chain._gen_lPt[genlepton], Chain._gen_lEta[genlepton], Chain._gen_lPhi[genlepton], Chain._gen_lE[genlepton])

        #Find matching reco tau
        matchindex = objSel.tauMatchIndexIso(Chain, genTauVec, needFake = False)
        if matchindex == -1:    continue       
 
        for i in xrange(len(tau_id_algos)):
            roc[i].fill_eff_denominator(Chain._weight)
            ptHist[i].fill_denominator(Chain._gen_lPt[genlepton], Chain._weight)
            etaHist[i].fill_denominator(Chain._gen_lEta[genlepton], Chain._weight)

        DMfinding = objSel.getDMfinding(Chain, matchindex)
        discriminators = objSel.getTauIDs(Chain, matchindex) 

        for i, discr in enumerate(discriminators):
            if not DMfinding[i]: continue

            for j, WP in enumerate(discr):
                if WP:
                    roc[i].fill_eff_numerator(j, Chain._weight)
                    ptHist[i].fill_numerator(Chain._lPt[matchindex], j, Chain._weight)
                    etaHist[i].fill_numerator(Chain._lEta[matchindex], j, Chain._weight)

###########
#Main body#
###########

#Initialize output (Generalize this if needed)

basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/Iso/'
makeDirIfNeeded(basefolder)
makeDirIfNeeded(basefolder+sample.output)
makeDirIfNeeded(basefolder+sample.output+'/'+args.method)
basefolder = basefolder + sample.output + '/' + args.method

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

if not args.isTest:
#if True:
    #Save output
    for i in xrange(len(tau_id_algos)):
        roc[i].write(basefolder, str(args.subJob))
        ptHist[i].write(basefolder, str(args.subJob))
        etaHist[i].write(basefolder, str(args.subJob))


