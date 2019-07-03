import ROOT
import numpy as np

lumi = 35545.499064
output_dir = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/ClosureTest'

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',          action='store',         default='DYJets')
argParser.add_argument('--subJob',              action='store',         default=0)
argParser.add_argument('--inputFile',           action='store',         default='inputFiles')

args = argParser.parse_args()

#Load in samples
import Sample
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/'+args.inputFile+'.conf')
sample = Sample.getSampleFromList(sampleList, args.sampleName)

#Initialize chain
Chain = sample.initTree()

import eventSelection
import objectSelection
from helpers import progress, makeDirIfNeeded, showBranch
#Loop over events
for entry in xrange(5000):

    progress(entry, 5000)
    Chain.GetEntry(entry)
    
    for l in xrange(ord(Chain._nL)):
        if not objectSelection.isNonPromptLooseTau(Chain, l):   continue

        print '----------------------------------'
        print '--------WEEWOO NEW EVENT---------'
        print '--------------------------------- \n'
        print '\n ++++In principle this is gen++++'
        print l
        print 'Flavor:', showBranch(Chain._gen_lFlavor)
        print 'isPrompt:', showBranch(Chain._gen_lIsPrompt)
        print 'pt:', showBranch(Chain._gen_lPt)
        print 'eta:', showBranch(Chain._gen_lEta)
        print 'phi:',showBranch(Chain._gen_lPhi)
        print 'mom pdg:', showBranch(Chain._lMomPdgId)
        print 'decayed hadr:', showBranch(Chain._gen_lDecayedHadr)
        print '\n ********Reco Bello********'
        print 'Flavor:', showBranch(Chain._lFlavor)
        print 'isPrompt:', showBranch(Chain._lIsPrompt)
        print 'IsVLoose:', showBranch(Chain._lPOGVeto)
        print 'DM:', showBranch(Chain._tauDecayMode)
        print 'IsLoose:', showBranch(Chain._lPOGLoose)
        print 'IsEwkTight:', showBranch(Chain._lEwkTight)
        print 'passMuonDiscr:', showBranch(Chain._tauMuonVetoLoose)
        print 'passEleDiscr:', showBranch(Chain._tauEleVetoLoose)
        print 'pt:', showBranch(Chain._lPt)
        print 'eta:',showBranch(Chain._lEta)
        print 'phi:',showBranch(Chain._lPhi)
        print " "
