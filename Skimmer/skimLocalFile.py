import ROOT, os
from ROOT import TFile
import argparse
from eventSelection import isGoodEventAN17_094, isGoodEventEwkino, isGoodEventJana, isGoodEventFakeRate
from helpers import makeDirIfNeeded, progress, showBranch
from Sample import Sample

def boolToInt(b):
    if b:
        return 1
    else:
        return 0

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--path',        action='store',         default='/pnfs/iihe/cms/store/user/wverbeke/heavyNeutrino/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/crab_MiniAOD2018-v1_dilepton_MC_2018_v5')
argParser.add_argument('--year',        action='store',         default='2016')
argParser.add_argument('--skim',        action='store',         default='ewkino')
argParser.add_argument('--isTest',      action='store',         default=False)

args = argParser.parse_args()

sample_name = args.path.rsplit('/')[-1].rsplit('.')[0]
print sample_name
sample = Sample(sample_name, args.path, sample_name, 1, '1') #xsec not used here, so put to 1
Chain = sample.initTree()

#Create output file
output_dir = '/user/lwezenbe/public/ntuples/'+args.year+ '/'+args.skim+'_v5wDeepCsvInvMET'
makeDirIfNeeded(output_dir)

output_file = TFile(output_dir+'/'+sample.output+'.root', 'recreate')
output_file.mkdir('blackJackAndHookers')
output_file.cd('blackJackAndHookers')

#Get hcounters
import eventSelection
isData = eventSelection.isData(sample.name)
if not isData:      hCounter = sample.getHist('hCounter')
if 'TChi' in sample.name:            hCounterSUSY = sample.getHist('hCounterSUSY')

#initialize new tree and delete unused branches
#branches_to_delete = ['HLT', 'Trigger', 'Flag', 'nLhe', 'IP', 'lElectron', 'leptonMva', 'relIso', 'miniIso', 'closestJet', 'lMuon', '_ph', 'HN']
#branches_to_delete = ['HLT_IsoMu22','HLT_MET','HLT_PFMET', 'HLT_PFHT', 'HLT_CaloJet', 'nLhe', 'lMuon', '_ph', 'HN', 'deepTau', 'Flag']
#for branch in branches_to_delete:
#    Chain.SetBranchStatus('*'+branch+'*', 0)

output_tree = Chain.CloneTree(0)

#Add new branches
nl_max = 20
import numpy as np
_ewkLoose =  np.full((nl_max), False, dtype=bool)
_ewkTight =  np.full((nl_max), False, dtype=bool)
#output_tree.Branch('_ewkLoose', _ewkLoose, '_ewkLoose[_nL]/O')
#output_tree.Branch('_ewkTight', _ewkTight, '_ewkTight[_nL]/O')

if args.isTest:
    eventRange = xrange(250)
else:
    eventRange= xrange(Chain.GetEntries())

from objectSelection import isEwkLoose, isEwkTight

#output_file.cd('blackJackAndHookers')
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

    for l in xrange(Chain._nL):
        _ewkLoose[l] = isEwkLoose(Chain, l)
        _ewkTight[l] = isEwkTight(Chain, l)
    output_tree.Fill()

print  _ewkLoose
output_file.cd('blackJackAndHookers')
#Write
if not args.isTest:
    output_tree.Write()
    if not isData:      hCounter.Write()
    if 'TChi' in sample.name:            hCounterSUSY.Write()

#Close the file
output_file.Close()

