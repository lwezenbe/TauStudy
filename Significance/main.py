import ROOT
from helpers_old import progress, getObjFromFile, makeDirIfNeeded, showBranch
from SusyXsec import xsec

#Constant luminosity
lumi = 35545.499064

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',          action='store',         default='DYJetsToLL_M-50')
argParser.add_argument('--subJob',              action='store',         default=0)
argParser.add_argument('--inputFile',           action='store',         default='inputFilesv3')
argParser.add_argument('--ele_cut_index',       action='store',         default='2')
argParser.add_argument('--mu_cut_index',        action='store',         default='1')
argParser.add_argument('--isTest',              action='store',         default=False)

args = argParser.parse_args()

#Load in samples
import Sample
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Significance/Data/'+args.inputFile+'.conf')
sample = Sample.getSampleFromList(sampleList, args.sampleName)

#Is this sample signal or background
isSignal = False
keywords = ['SMS', 'TChi', 'Slep', 'Snu']
for key in keywords:
    if key in sample.name:      isSignal = True

#Initialize chain
Chain = sample.initTree()

#If SUSY, load in the hCounterSUSY
if isSignal:
    hCounterSUSY = getObjFromFile(sample.path, 'hCounterSUSY')

#Initialize event selector
import eventSelector
evSel = eventSelector.eventSelector(Chain, int(args.ele_cut_index), int(args.mu_cut_index))

#Initialize histograms to save
#These consist of the total number of events that are left after performing the event selection
#Each bin represents a different Old MVA Iso working point
Single_Tau_Output = ROOT.TH1D('singletau', 'singletau', len(evSel.IsoWorkingPoints), 0, len(evSel.IsoWorkingPoints))
Di_Tau_Output = ROOT.TH1D('ditau', 'ditau', len(evSel.IsoWorkingPoints), 0, len(evSel.IsoWorkingPoints))
basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Histos'

#Determine if testrun so it doesn't need to calculate the number of events in the getEventRange (current bottleneck)
if args.isTest:
    eventRange = xrange(10000)
else:
    eventRange = sample.getEventRange(int(args.subJob))

#Start event loop
for entry in eventRange:
    
    progress(entry, len(eventRange))
    Chain.GetEntry(entry)
    if isSignal:
        if Chain._mChi1 != 150 or Chain._mChi2 != 250:      continue
    
    for WP in range(len(evSel.IsoWorkingPoints)):
       
        if not evSel.isGoodEvent(WP):           continue
        
        if isSignal:
            sample.xsec = xsec(Chain._mChi2)
            sample.hCount = hCounterSUSY.GetBinContent(hCounterSUSY.FindBin(Chain._mChi2, Chain._mChi1))
 
        #Fill histogram
        weightfactor = Chain._weight*((sample.xsec*lumi)/sample.hCount)
        print weightfactor
        if evSel.nTau == 1:
            Single_Tau_Output.Fill(WP+.5, weightfactor)
        elif evSel.nTau == 2:
            Di_Tau_Output.Fill(WP+.5, weightfactor) 

for i in range(len(evSel.IsoWorkingPoints)):
    print Single_Tau_Output.GetBinContent(i+1), Di_Tau_Output.GetBinContent(i+1)

if not args.isTest:
    #Save output
    makeDirIfNeeded(basefolder+'/'+sample.output)
    Single_Tau_Output.SaveAs(basefolder+'/'+sample.output+'/'+sample.name+'_singletau_'+args.ele_cut_index+'_'+args.mu_cut_index+'_subjob_'+str(args.subJob)+'.root')
    Di_Tau_Output.SaveAs(basefolder+'/'+sample.output+'/'+sample.name+'_ditau_'+args.ele_cut_index+'_'+args.mu_cut_index+'_subjob_'+str(args.subJob)+'.root')
