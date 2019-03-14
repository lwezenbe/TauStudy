import ROOT, os
from ROOT import TFile
import subSample
import argparse
from eventSelection import isGoodEventAN17_094, isGoodEventEwkino
from helpers import makeDirIfNeeded, progress, showBranch

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--path',        action='store',         default='/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_Moriond2017_ext2-v1_tau_MC_trilepwOneTau_v2')
argParser.add_argument('--subDir',      action='store',         default=0)
argParser.add_argument('--subJob',      action='store',         default=0)
argParser.add_argument('--analysis',    action='store',         default='ewkino')
argParser.add_argument('--isTest',      action='store',         default=False)

args = argParser.parse_args()

subsample = subSample.subSample(args.path, int(args.subDir))
Chain = subsample.initChain(int(args.subJob))

#Create output file
makeDirIfNeeded('/user/lwezenbe/public/ntuples/tmp_'+subsample.group)
output_file = TFile('/user/lwezenbe/public/ntuples/tmp_'+subsample.group+'/'+subsample.group+'_'+ subsample.name+'_' +str(args.subDir)+'_'+str(args.subJob)+'.root', 'recreate')
output_file.cd()

#Get hcounters
if subsample.group != 'SingleMuon':      hCounter = subsample.gethCounter()
if 'TChi' in subsample.group:            hCounterSUSY = subsample.gethCounterSUSY()

#initialize new tree
print Chain.GetEntries()
output_tree = Chain.CloneTree(0)
test=0

if args.isTest:
    eventRange = xrange(5000)
else:
    eventRange= xrange(Chain.GetEntries())

#Fill new tree
for entry in eventRange:
    progress(entry, len(eventRange))
    Chain.GetEntry(entry)
    
    if args.analysis == 'ewkino':
        if not isGoodEventEwkino(Chain):        

        
       #     print '----------------------------------'
       #     print '--------WEEWOO NEW EVENT---------'
       #     print '--------------------------------- \n'
       #     print entry, Chain._lumiBlock, Chain._eventNb
       #     print '\n ++++In principle this is gen++++'
       #     print 'Flavor:', showBranch(Chain._gen_lFlavor)
       #     print 'isPrompt:', showBranch(Chain._gen_lIsPrompt)
       #     print 'pt:', showBranch(Chain._gen_lPt)
       #     print 'eta:', showBranch(Chain._gen_lEta)
       #     print 'phi:',showBranch(Chain._gen_lPhi)
       #     print 'mom pdg:', showBranch(Chain._lMomPdgId)
       #     print 'decayed hard:',showBranch(Chain._gen_lDecayedHadr)
       #     print '\n ********Reco Bello********'
       #     print 'Flavor:', showBranch(Chain._lFlavor)
       #     print 'isPrompt:', showBranch(Chain._lIsPrompt)
       #     print 'IsVLoose:', showBranch(Chain._lPOGVeto)
       #     print 'IsLoose:', showBranch(Chain._lPOGLoose)
       #     print 'IsEwkTight:', showBranch(Chain._lEwkTight)
       #     print 'passMuonDiscr:', showBranch(Chain._tauMuonVetoLoose)
       #     print 'passEleDiscr:', showBranch(Chain._tauEleVetoLoose)
       #     print 'pt:', showBranch(Chain._lPt)
       #     print 'eta:',showBranch(Chain._lEta)
       #     print 'phi:',showBranch(Chain._lPhi)
       #     print 'match pdg:', showBranch(Chain._lMatchPdgId)
       #     print 'match pt:', showBranch(Chain._lMatchPt)
       #     print 'match eta:', showBranch(Chain._lMatchEta)
       #     print 'match phi:', showBranch(Chain._lMatchPhi)
       #     print 'match decayed hadr:', showBranch(Chain._lMatchDecayedHadr)
       #     print '\n'

            continue
    
    elif args.analysis == 'tauAN':
        if not isGoodEventAN17_094(Chain):      continue

    test+=1.

    
    output_tree.Fill()
print test
output_file.cd()
#Write
output_tree.Write()
if subsample.group != 'SingleMuon':      hCounter.Write()
if 'TChi' in subsample.group:            hCounterSUSY.Write()

#Close the file
output_file.Close()

