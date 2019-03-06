import ROOT, os
from ROOT import TFile
import subSample
import argparse
from eventSelectionSkimmer import isGoodEventAN17_094, isGoodEventEwkino, isGoodEventJana
from helpers import makeDirIfNeeded, progress

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--path',        action='store',         default='/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_Moriond2017-v1_tauSamples2016_v4')
argParser.add_argument('--subDir',      action='store',         default=0)
argParser.add_argument('--subJob',      action='store',         default=0)
argParser.add_argument('--analysis',    action='store',         default='ewkino')
argParser.add_argument('--isTest',      action='store',         default=False)

args = argParser.parse_args()

print '1'

subsample = subSample.subSample(args.path, int(args.subDir))
Chain = subsample.initChain(int(args.subJob))

print '3'

#Get hcounters
if subsample.group != 'SingleMuon':      hCounter = subsample.gethCounter()
if 'TChi' in subsample.group:            hCounterSUSY = subsample.gethCounterSUSY()

print'4'

#initialize new tree
print Chain.GetEntries()
output_tree = Chain.CloneTree(0)

print '5' 

#Fill new tree
for entry in xrange(Chain.GetEntries()):
    progress(entry, Chain.GetEntries())
    Chain.GetEntry(entry)
    
    if args.analysis == 'ewkino':
        if not isGoodEventEwkino(Chain):        continue
    elif args.analysis == 'tauAN':
        if not isGoodEventAN17_094(Chain):      continue
    elif args.analysis == 'Jana':
        if not isGoodEventJana(Chain):          continue
    
    output_tree.Fill()

if not args.isTest:
    #Create output file
    makeDirIfNeeded('/user/lwezenbe/public/trilep/tmp_'+subsample.group)
    output_file = TFile('/user/lwezenbe/public/trilep/tmp_'+subsample.group+'/'+subsample.group+'_'+ subsample.name+'_' +str(args.subDir)+'_'+str(args.subJob)+'.root', 'recreate')

    #Write
    output_tree.Write()
    if subsample.group != 'SingleMuon':      hCounter.Write()
    if 'TChi' in subsample.group:            hCounterSUSY.Write()

    #Close the file
    output_file.Close()



            
#MAIN BODY

#files_to_skim = subSample.createSampleList(args.sampleList)
#for group, f in samples_to_skim:
#    number_of_subdir = subprocess.check_output("/bin/ls -lA " + f + "/* | egrep -c '^-|^d'", shell=True, stderr=subprocess.STDOUT)
#    for subdir in xrange(number_of_subdir):
#        subsample = subSample(group, f, subdir)
#        nJobs = subsample.totalJobs
#        for job in nJobs:
#            launch 
