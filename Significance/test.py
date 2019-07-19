def tauHasOverlap(Chain, index):

    #Check the flavor of the lepton and initialize variables 
    hasOverlap = False
    inputVec = TLorentzVector()
    inputVec.SetPtEtaPhiE(Chain._lPt[index], Chain._lEta[index], Chain._lPhi[index], Chain._lE[index])

    #Loop over all leptons with a different flavor and a different index 
    for l in xrange(ord(Chain._nLight)):
        if l == index or Chain._lFlavor[l] == Chain._lFlavor[index]:            continue
        if not Chain._lEwkLoose[l]:                                             continue

        lVec = TLorentzVector()
        lVec.SetPtEtaPhiE(Chain._lPt[l], Chain._lEta[l], Chain._lPhi[l], Chain._lE[l])

        dR = inputVec.DeltaR(lVec)
        if dR < .4:         hasOverlap = True

    return hasOverlap


#Load in samples
import Sample
#sample = Sample.Sample("DYJetsToLL_M-50", '/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_Moriond2017_ext1-v2_ewkino2016MCList-v28/190318_133550/0000/trilep_1.root', 'DYJets', 1, "6024")
#sample = Sample.Sample("DYJetsToLL_M-50", '/pnfs/iihe/cms/store/user/wverbeke/heavyNeutrino/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_Moriond2017_ext1-v2_ewkino2016MCList-v27/180925_111611/0000/trilep_1.root', 'DYJets', 1, "6024")
#sample = Sample.Sample("DYJetsToLL_M-50", '/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_Moriond2017_ext1-v2_tau_MC_trilepwOneTau_v2/190221_084926/0000/trilepWithSingletau_1.root', 'DYJets', 1, "6024")
#sample = Sample.Sample("DYJetsToLL_M-50", '/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_Moriond2017_ext1-v2_tau_MC_trilepwOneTau_v2/190221_084926/0000', 'DYJets', 1, "6024")
sample = Sample.Sample("DYJetsToLL_M-50", '/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_Moriond2017_ext1-v2_tauEfficiency2016_v2/190206_150950/0000/noskim_1.root',  'DYJets', 1, "6024")

print sample.name
lumi = 36000
#Initialize chain
Chain = sample.initTree()

import objectSelection
from helpers import progress

num = 0.
denom = 0.
for entry in xrange(Chain.GetEntries()):
    
    progress(entry, Chain.GetEntries())
    Chain.GetEntry(entry)

    weightfactor = 1.
    #weightfactor = Chain._weight*((sample.xsec*lumi)/sample.hCount)
    denom += weightfactor

#    lIndex = []
#    for l in xrange(ord(Chain._nL)):
#        if not objectSelection.isGoodLepton(Chain, l):      continue
##        if Chain._lFlavor[l] == 2:
##            if not Chain._lPOGVeto[l]:  continue
#        if Chain._lFlavor[l] == 2  and not Chain._lPOGTight[l]: continue        
#        #if Chain._lFlavor[l] == 2: continue        
#        lIndex.append(l)

    if ord(Chain._nTau) < 1: continue
    if ord(Chain._nL) < 3: continue
    #if Chain._nTau < 1: continue
#    if len(lIndex) != 3: continue
   
#    if Chain._met < 50: continue
 
    print ord(Chain._nL), ord(Chain._nLight), ord(Chain._nTau)
    #print Chain._lFlavor[lIndex[0]], Chain._lFlavor[lIndex[1]], Chain._lFlavor[lIndex[2]]
 
    num += weightfactor

print num, denom, num/denom
