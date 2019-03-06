import ROOT
from ROOT import TLorentzVector
import Sample
import numpy as np
import argparse

def getWeightFactor(xsec, _weight, lumi, hCount):
    weightfactor = _weight*((xsec*lumi)/hCount)

    return weightfactor

def makeHist(histInfo):
    h = TH1D(histInfo[0], histInfo[0], histInfo[1], histInfo[2], histInfo[3])
    return h

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--sampleName',  action='store',         default=None)
argParser.add_argument('--subJob',      action='store',         default=None)
argParser.add_argument('--inputFile',      action='store',         default='OldSamples')

args = argParser.parse_args()

lumi = 35545.499064

sampleList = Sample.createSampleList('/user/lwezenbe/private/PhD/Code/TauStudy/Efficiency/Data/'+args.inputFile+'.conf')
sample = Sample.getSampleFromList(sampleList, args.sampleName)
print sample.output
Chain = sample.initTree()
nEvents = [0., 0.]
print 'Chain initialized'
for entry in sample.getEventRange(int(args.subJob)):
#for entry in xrange(500):
    Chain.GetEntry(entry)
    nTau = 0
    lIndex = []
    lPt = []
    for l in xrange(ord(Chain._nL)):
        if Chain._lFlavor[l] is not 2 and not Chain._lEwkTight[l]:      continue
        if Chain._lFlavor[l] == 2 and (not Chain._lPOGLoose[l] or not Chain._decayModeFinding[l]):        continue
        lIndex.append(l)
        lPt.append(Chain._lPt[l])
        if Chain._lFlavor[l] == 2: nTau += 1
         
    if len(lIndex) is not 3:       continue
    
    if nTau == 0 or nTau == 3:              continue 
    
    tmp = [x for _,x in sorted(zip(lPt,lIndex))]
    lIndex = tmp

    if Chain._lPt[lIndex[0]] < 10 or Chain._lPt[lIndex[1]] < 15 or Chain._lPt[lIndex[2]] < 25:           continue

    lVec = []
    for i, l in enumerate(lIndex):
        lVec.append(TLorentzVector())
        lVec[i].SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

    if Chain._met < 50.:           continue
    
    containsB = False
    for jet in xrange(ord(Chain._nJets)):
        if Chain._jetPt[jet] < 25.:     continue
        ignoreJet = False
        jetVec = TLorentzVector()
        jetVec.SetPtEtaPhiE(Chain._jetPt[jet], Chain._jetEta[jet], Chain._jetPhi[jet], Chain._jetE[jet])
        for l in xrange(len(lIndex)):
            if jetVec.DeltaR(lVec[l]) < 0.4:   ignoreJet = True
        if not ignoreJet and Chain._jetCsvV2[jet]  > 0.8484:         containsB = True

    if containsB:       continue

    weightfactor = getWeightFactor(sample.xsec, Chain._weight, lumi, sample.hCount)

    if nTau == 1:       nEvents[0] += weightfactor
    if nTau == 2:       nEvents[1] += weightfactor

np.savetxt('/user/lwezenbe/private/PhD/Results/TauStudy/CheckBkgr/Histos/' + sample.name + '_' + sample.output+'_'+ args.subJob+'.dat', nEvents)
print 'Finished'
