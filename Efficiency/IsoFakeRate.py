import ROOT
import argparse
from ROOT import TLorentzVector, TH1D
import numpy as np
import Sample
from helpers import progress, makeDirIfNeeded, showBranch
import objectSelection as objSel
from efficiency import efficiency
from ROC import ROC

argParser = argparse.ArgumentParser(description = "Argument parser") 
argParser.add_argument('--sampleName',  action='store',         default='DYJetsToLL_M-50') 
argParser.add_argument('--subJob',      action='store',         default=0) 
argParser.add_argument('--method',      action='store',         default='Bluj') 
argParser.add_argument('--inputFile',   action='store',         default='inputFilesv3') 
argParser.add_argument('--isTest',      action='store',         default=False) 
 
args = argParser.parse_args() 
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+ args.inputFile  +'.conf') 
sample = Sample.getSampleFromList(sampleList, args.sampleName)

print 'Initializing'
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

def CalcANFakeRate(Chain, sample, args):
    global roc
    global ptHist
    global etaHist

    for jet in xrange(Chain._nJets):
       
        if Chain._jetPt[jet] < 20 or abs(Chain._jetEta[jet]) > 2.3:          continue
        
        jetVec = objSel.getFourVec(Chain._jetPt[jet], Chain._jetEta[jet], Chain._jetPhi[jet], Chain._jetE[jet])

        #Find matching reco tau
        matchindex = objSel.tauMatchIndexIso(Chain, jetVec)
        if matchindex != 1 and Chain._tauGenStatus[matchindex] == 5:         continue   

        for i in xrange(len(tau_id_algos)):
            roc[i].fill_misid_denominator(CHain._weight)
            ptHist[i].fill_denominator(Chain._jetPt[jet], Chain._weight)
            etaHist[i].fill_denominator(Chain._jetEta[jet], Chain._weight)

        DMfinding = objSel.getDMfinding(Chain, matchindex)
        discriminators = objSel.getTauIDs(Chain, matchindex)

        for i, discr in enumerate(discriminators):
            if not DMfinding[i]: continue
            for j, WP in enumerate(discr):
                if WP:
                    passedTau[i][j] += 1.
                    ptHist[i].fill_numerator(Chain._lPt[matchindex], j, Chain._weight)
                    etaHist[i].fill_numerator(Chain._lEta[matchindex], j, Chain._weight)

def CalcBlujFakeRate(Chain, sample, args):
    global roc
    global ptHist
    global etaHist
 
    for jet in xrange(Chain._nJets):
   
        if Chain._jetPt[jet] < 20 or abs(Chain._jetEta[jet]) > 2.3:                     continue

        jetVec = objSel.getFourVec(Chain._jetPt[jet], Chain._jetEta[jet], Chain._jetPhi[jet], Chain._jetE[jet])

        #Find matching reco tau
        matchindex = objSel.tauMatchIndexIso(Chain, jetVec, needFake=True)
        if matchindex == -1:    continue       
 
        for i in xrange(len(tau_id_algos)):
            roc[i].fill_misid_denominator(Chain._weight)
            ptHist[i].fill_denominator(Chain._jetPt[jet], Chain._weight)
            etaHist[i].fill_denominator(Chain._jetEta[jet], Chain._weight)

        DMfinding = objSel.getDMfinding(Chain, matchindex)
        discriminators = objSel.getTauIDs(Chain, matchindex)

        for i, discr in enumerate(discriminators):
            if not DMfinding[i]: continue
            for j, WP in enumerate(discr):
                if WP:
                    roc[i].fill_misid_numerator(j, Chain._weight)
                    ptHist[i].fill_numerator(Chain._lPt[matchindex], j, Chain._weight)
                    etaHist[i].fill_numerator(Chain._lEta[matchindex], j, Chain._weight)


###########
#Main body#
###########

#Whatever needs to be saved at the end
pt_bins = np.linspace(20, 120, 11)
eta_bins = np.linspace(-2.4, 2.4, 25)

basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/Iso/'
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

#Get range of events in subjob
if args.isTest:
    eventRange = xrange(5000)
else:
    eventRange = sample.getEventRange(int(args.subJob))

#begin event loop
for entry in eventRange:
    Chain.GetEntry(entry)
    if args.method == 'AN':             CalcANFakeRate(Chain, sample, args)
    elif args.method == 'Bluj':         CalcBlujFakeRate(Chain, sample, args)
    else:
        print('NOOO, GOD! NO, GOD, PLEASE, NO! NO! NO! ')
        time.sleep(2.5)
        print('NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!')
        time.sleep(1)
        print('Please enter proper method argument')
        exit()

#save
if not args.isTest:
    for i in xrange(len(tau_id_algos)):
        roc[i].write(basefolder, str(args.subJob))
        ptHist[i].write(basefolder, str(args.subJob))
        etaHist[i].write(basefolder, str(args.subJob))
