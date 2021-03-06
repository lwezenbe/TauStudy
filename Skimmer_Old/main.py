import ROOT, os
from ROOT import TFile
import subSample
import argparse
from eventSelection import isGoodEventAN17_094, isGoodEventEwkino
from helpers import makeDirIfNeeded, progress, showBranch

argParser = argparse.ArgumentParser(description = "Argument parser")
#argParser.add_argument('--path',        action='store',         default='/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_MiniAOD2016v3_ext1-v2_ewkino2016MCList-v32')
argParser.add_argument('--path',        action='store',         default='/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_MiniAOD2016v3_v2_ewkino2016MCList-v32')
#argParser.add_argument('--path',        action='store',         default='/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_Moriond2017-v1_tau_MC_trilepwOneTau_v2')
argParser.add_argument('--subDir',      action='store',         default=0)
argParser.add_argument('--subJob',      action='store',         default=0)
argParser.add_argument('--analysis',    action='store',         default='ewkino')
argParser.add_argument('--isTest',      action='store',         default=False)

args = argParser.parse_args()

subsample = subSample.subSample(args.path, int(args.subDir))
Chain = subsample.initChain(int(args.subJob))

#Create output file
makeDirIfNeeded('/user/lwezenbe/public/ntuples/2016/ewkino_Oldtrilep/tmp_'+subsample.group)
output_file = TFile('/user/lwezenbe/public/ntuples/2016/ewkino_Oldtrilep/tmp_'+subsample.group+'/'+subsample.group+'_'+ subsample.name+'_' +str(args.subDir)+'_'+str(args.subJob)+'.root', 'recreate')
output_file.mkdir('blackJackAndHookers')
output_file.cd('blackJackAndHookers')

#Get hcounters
if subsample.group != 'SingleMuon':      hCounter = subsample.getHist(int(args.subJob), 'hCounter')
if 'TChi' in subsample.group:            hCounterSUSY = subsample.getHist(int(args.subJob), 'hCounterSUSY')
print type(Chain)
#initialize new tree and delete unused branches
branches_to_delete = ['HLT', 'Trigger', 'Flag', 'nLhe', 'IP', 'lElectron', 'leptonMva', 'lHN', 'relIso', 'miniIso', 'closestJet', 'lMuon', '_ph', 'HN']
for branch in branches_to_delete:
    Chain.SetBranchStatus('*'+branch+'*', 0)
output_tree = Chain.CloneTree(0)

if args.isTest:
    eventRange = xrange(10000)
else:
    eventRange= xrange(Chain.GetEntries())
print '2'
#Fill new tree
for entry in eventRange:
    progress(entry, len(eventRange))
    Chain.GetEntry(entry)
    if args.analysis == 'ewkino':
        if not isGoodEventEwkino(Chain):        continue
    elif args.analysis == 'tauAN':
        if not isGoodEventAN17_094(Chain):      continue
    output_tree.Fill()

output_file.cd('blackJackAndHookers')
#Write
if not args.isTest:
    output_tree.Write()
    if subsample.group != 'SingleMuon':      hCounter.Write()
    if 'TChi' in subsample.group:            hCounterSUSY.Write()

#Close the file
output_file.Close()

