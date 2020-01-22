import subSample

#path = '/pnfs/iihe/cms/store/user/wverbeke/heavyNeutrino/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_Moriond2017_ext1-v2_ewkino2016MCList-v27'
path = '/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/SMS-TChiSlepSnu_tauenriched_x0p05_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_Spring16FS_miniAODv2_v0-v1_ewkinoSignalList_v28'

subsample = subSample.subSample(path, 0)

#Chain = subsample.initChain(0)
print subsample.filesInSubjob(2)
hCounter = subsample.getHist(2, 'hCounter')

