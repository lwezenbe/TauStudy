import ROOT
from helpers import progress, getObjFromFile, makeDirIfNeeded, showBranch
from SusyXsec import xsec

#Constant luminosity
lumi = 35545.499064

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',          action='store',         default='SMS-TChiSlepSnu_x0p5')
argParser.add_argument('--subJob',              action='store',         default=0)
argParser.add_argument('--inputFile',           action='store',         default='inputFiles')
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

#Initialize histograms to save
#These consist of the total number of events that are left after performing the event selection
#Each bin represents a different Old MVA Iso working point
Single_Tau_Output = ROOT.TH1D('singletau', 'singletau', 5, 0, 5)
Di_Tau_Output = ROOT.TH1D('ditau', 'ditau', 5, 0, 5)
basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Histos'

#Initialize event selector
import eventSelector
evSel = eventSelector.eventSelector(Chain, int(args.ele_cut_index), int(args.mu_cut_index))

#Determine if testrun so it doesn't need to calculate the number of events in the getEventRange (current bottleneck)
if args.isTest:
    eventRange = xrange(2000)
else:
    eventRange = sample.getEventRange(int(args.subJob))

print Chain.GetEntries()
test = 0
test2=0
test3=0
#Start event loop
for entry in eventRange:
    
    progress(entry, len(eventRange))
    Chain.GetEntry(entry)
    
    for WP in range(len(evSel.IsoWorkingPoints)):
       
        if WP == 0 and False:
            print '----------------------------------'
            print '--------WEEWOO NEW EVENT---------'
            print '--------------------------------- \n'
            print '\n ++++In principle this is gen++++'
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
        
        if not evSel.isGoodEvent(WP):           continue
        if WP == 0: 
            test += 1.
        if isSignal:
            if Chain._mChi1 != 150 or Chain._mChi2 != 250:      continue
            sample.xsec = xsec(Chain._mChi2)
            sample.hCount = hCounterSUSY.GetBinContent(hCounterSUSY.FindBin(Chain._mChi2, Chain._mChi1))
 
        #Fill histogram
        weightfactor = Chain._weight*((sample.xsec*lumi)/sample.hCount)
        if evSel.nTau == 1:
            Single_Tau_Output.Fill(WP+.5, weightfactor)
        elif evSel.nTau == 2:
            Di_Tau_Output.Fill(WP+.5, weightfactor) 

print Single_Tau_Output.GetBinContent(1), Di_Tau_Output.GetBinContent(1), test

if not args.isTest:
    #Save output
    makeDirIfNeeded(basefolder+'/'+sample.output)
    Single_Tau_Output.SaveAs(basefolder+'/'+sample.output+'/'+sample.name+'_singletau_'+args.ele_cut_index+'_'+args.mu_cut_index+'_subjob_'+str(args.subJob)+'.root')
    Di_Tau_Output.SaveAs(basefolder+'/'+sample.output+'/'+sample.name+'_ditau_'+args.ele_cut_index+'_'+args.mu_cut_index+'_subjob_'+str(args.subJob)+'.root')
