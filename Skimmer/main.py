import ROOT, os
from ROOT import TFile
import subSample
import argparse
from eventSelection import isGoodEventAN17_094, isGoodEventEwkino, isGoodEventJana, isGoodEventFakeRate
from helpers_old import makeDirIfNeeded, progress, showBranch

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--path',        action='store',         default='/pnfs/iihe/cms/store/user/wverbeke/heavyNeutrino/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_MiniAOD2016v3_ext1-v2_singlelepton_MC_2016_v2')
argParser.add_argument('--subDir',      action='store',         default=0)
argParser.add_argument('--subJob',      action='store',         default=0)
argParser.add_argument('--year',        action='store',         default='2016')
argParser.add_argument('--skim',        action='store',         default='ewkino')
argParser.add_argument('--isTest',      action='store_true',         default=False)

args = argParser.parse_args()

subsample = subSample.subSample(args.path, int(args.subDir))
Chain = subsample.initChain(int(args.subJob))

#Create output file
output_dir = '/user/lwezenbe/public/ntuples/'+args.year+ '/'+args.skim+'_final/tmp_'+subsample.group
makeDirIfNeeded(output_dir)

output_file = TFile(output_dir+'/'+subsample.group+'_'+ subsample.name+'_' +str(args.subDir)+'_'+str(args.subJob)+'.root', 'recreate')
output_file.mkdir('blackJackAndHookers')
output_file.cd('blackJackAndHookers')

#Get hcounters
import eventSelection
isData = eventSelection.isData(subsample.group)
if not isData:      hCounter = subsample.getHist(int(args.subJob), 'hCounter')
if 'TChi' in subsample.group:            hCounterSUSY = subsample.getHist(int(args.subJob), 'hCounterSUSY')

#initialize new tree and delete unused branches
#branches_to_delete = ['HLT', 'Trigger', 'Flag', 'nLhe', 'IP', 'lElectron', 'leptonMva', 'relIso', 'miniIso', 'closestJet', 'lMuon', '_ph', 'HN']
branches_to_delete = ['HLT_IsoMu22','HLT_MET','HLT_PFMET', 'HLT_PFHT', 'HLT_CaloJet', 'nLhe', 'lMuon', '_ph', 'HN', 'deepTau', 'Flag']
for branch in branches_to_delete:
    Chain.SetBranchStatus('*'+branch+'*', 0)

output_tree = Chain.CloneTree(0)

if args.isTest:
    #eventRange= xrange(Chain.GetEntries())
    eventRange = xrange(5000)
else:
    eventRange= xrange(Chain.GetEntries())

#Fill new tree
for entry in eventRange:
    progress(entry, len(eventRange))
    Chain.GetEntry(entry)
    if args.skim == 'ewkino':
        if not isGoodEventEwkino(Chain):        continue
    elif args.skim == 'tauAN':
        if not isGoodEventAN17_094(Chain):      continue
    elif args.skim == 'FR':
        if not isGoodEventFakeRate(Chain):      continue
    elif args.skim == 'jana':
        if not isGoodEventJana(Chain):      continue
    output_tree.Fill()

output_file.cd('blackJackAndHookers')
#Write
output_tree.Write()
if not isData:      hCounter.Write()
if 'TChi' in subsample.group:            hCounterSUSY.Write()

#Close the file
output_file.Close()

