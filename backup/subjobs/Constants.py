from numpy import zeros
NumberOfLeptons = 2                       #Set constants
NumberOfSamples = 3
# QCDsamples = 0
# STsamples = 1
# TTsamples = 2
# WJetssamples = 3
# VVsamples = 4
# DYsamples = 5
STsamples = 0
TTsamples = 1
DYsamples = 2

NumberOfDYJetsSamples = 2
NumberOfTTJetsSamples = 1
NumberOfSTSamples = 4
NumberOfWJetsSamples = 5
NumberOfVVSamples = 6
NumberOfQCDSamples = 8
NumberOfSubSamples = [4, 1, 2]

LuminosityCtoG = 35545.499064                      #Inverse pb
#LuminosityCtoG = 21520.756571                      #Inverse pb
LuminosityFPlusCDG = 3104.509132 + 6815.95046 + 7540                      #Inverse pb

numberofbins = 50                      #Set hist parameters
firstbin = 0
lastbin = 200

#Indices used for variables
NumberOfVar     = 10
muPtInd         = 0
tauPtInd        = 1
muEtaInd        = 2
tauEtaInd       = 3
MTInd           = 4
MvisInd         = 5
DeltaPhiInd     = 6
PZetaAllInd     = 7
PZetaVisInd     = 8
PZetaInd        = 9
AllInd          = 10

#All var information needed for hist
varInfo = []
varInfo.append(["muPt", 20, 20, 80])
varInfo.append(["tauPt", 20, 20, 80]) 
varInfo.append(["muEta", 10, 0, 2.4]) 
varInfo.append(["tauEta", 10, 0, 2.4]) 
varInfo.append(["MT", 20, 0, 40]) 
varInfo.append(["MVis", 50, 0, 200]) 
varInfo.append(["dPhi", 10, 0, 6.3]) 
varInfo.append(["PZetaAll", 20, -40, 90]) 
varInfo.append(["PZEtaVis", 20, -40, 90]) 
varInfo.append(["PZeta", 20, -50, 90]) 

#General indices used in the ntuples
mu = 1
ele = 0
tau = 2

#Specific indices for the two leptons used in this analysis
Muon = 0
Tau = 1

pi = 3.14159265359

# FileNames[NumberOfSamples] = {"QCD_DiLep", "ST_DiLep", "TTJets_DiLep", "WJets_DiLep", "VV_DiLep", "DYJetsToLL_DiLep"};
FileNames = ["ST_DiLep", "TTJets_DiLep", "DYJetsToLL_DiLep"]
#FileNames = ["TTJets_DiLep", "DYJetsToLL_DiLep"]
FileNamesDY = ["DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16"]
FileNamesTT = ["TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16"]
FileNamesST = ["ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1_Summer16", "ST_t-channel_top_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1_Summer16", "ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_Summer16", "ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_Summer16"]
FileNamesWJets = ["W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16"]
FileNamesVV = ["WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_Summer16", "WZJToLLLNu_TuneCUETP8M1_13TeV-amcnlo-pythia8_Summer16", "WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_Summer16", "WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_Summer16","ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_Summer16", "ZZTo4L_13TeV-amcatnloFXFX-pythia8_Summer16"]
FileNamesQCD = ["QCD_HT100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16","QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16", "QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_Summer16"]

legendNames = ["STJets", "TTJets", "DYJets"]

FileNamesSub = [FileNamesST, FileNamesTT, FileNamesDY]

xsecWJets = [61526.7, 61526.7, 61526.7, 61526.7, 61526.7] #CHANGE THIS
xsecVV = [49.997, 4.42965, 10.71, 5.595, 3.22, 1.212]
xsecQCD = [27990000, 1712000, 347700, 32100, 6831, 1207, 119.9, 25.24]
