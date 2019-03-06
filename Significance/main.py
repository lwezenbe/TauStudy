import ROOT
import eventSelection
import Sample
import argparse
from helpers import progress, getObjFromFile
from SusyXsec import xsec

def getWeightFactor(xsec, _weight, lumi, hCount):
    weightfactor = _weight*((xsec*lumi)/hCount)

    return weightfactor

#Constant luminosity
lumi = 35545.499064

#Parse arguments
argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',  action='store',         default='SMS-TChiSlepSnu_x0p5')
argParser.add_argument('--subJob',      action='store',         default=0)
argParser.add_argument('--inputFile',   action='store',         default='inputFiles')
argParser.add_argument('--isTest',      action='store',         default=False)

args = argParser.parse_args()

#Load in samples
sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Significance/Data/'+args.inputFile+'.conf')
sample = Sample.getSampleFromList(sampleList, args.sampleName)

#Is this sample signal or background
isSignal = False
keywords = ['SMS', 'TChi', 'Slep', 'Snu']
for key in keywords:
    if key in sample.name:      isSignal = True

#Initialize chain
Chain = sample.initTree()

#Is SUSY, load in the hCounterSUSY
if isSignal:
    hCounterSUSY = getObjFromFile(sample.path, 'hCounterSUSY')

#Initialize histograms to save
#These consist of the total number of events that are left after performing the event selection
#Each bin represents a different final state with a different number of taus
Single_Tau_Output = ROOT.TH1D('singletau', 'singletau', 5, 0, 5)
Di_Tau_Output = ROOT.TH1D('ditau', 'ditau', 5, 0, 5)
basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Histos'

#Determine if testrun so it doesn't need to calculate the number of events in the getEventRange (current bottleneck)
if args.isTest:
    eventRange = xrange(5000)
else:
    eventRange = sample.getEventRange(int(args.subJob))

#Start event loop
for entry in eventRange:
    
    progress(entry, len(eventRange))
    Chain.GetEntry(entry)

    #Old MVA working points
    workingPoints = (Chain._lPOGVeto, Chain._lPOGLoose, Chain._lPOGMedium, Chain._lPOGTight, Chain._tauVTightMvaOld)

    for i, WP in enumerate(workingPoints):
        if not eventSelection.isGoodEvent(Chain, WP):           continue
        nTau = eventSelection.getNTau()
       
        if isSignal:
            if Chain._mChi1 != 200 or Chain._mChi2 != 300:      continue
            sample.xsec = xsec(Chain._mChi2)
#            print entry, i, Chain._mChi1, Chain._mChi2, sample.xsec
            sample.hCount = hCounterSUSY.GetBinContent(hCounterSUSY.FindBin(Chain._mChi2, Chain._mChi1))
 
        #Fill histogram
        weightfactor = Chain._weight*((sample.xsec*lumi)/sample.hCount)
        if nTau == 1:
            Single_Tau_Output.AddBinContent(i+1, weightfactor)
        elif nTau == 2:
            Di_Tau_Output.AddBinContent(i+1, weightfactor) 

if not args.isTest:
    #Save output
    Single_Tau_Output.SaveAs(basefolder+'/'+sample.output+'_singletau_subjob_'+str(args.subJob)+'.root')
    Di_Tau_Output.SaveAs(basefolder+'/'+sample.output+'_ditau_subjob_'+str(args.subJob)+'.root')
