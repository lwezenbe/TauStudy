//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct  4 11:36:36 2018 by ROOT version 6.10/02
// from TTree blackJackAndHookersTree/blackJackAndHookersTree
// found on file: WZTo3LNu.root
//////////////////////////////////////////////////////////

#ifndef WzTo3LNuTreeBranches_h
#define WzTo3LNuTreeBranches_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class WzTo3LNuTreeBranches {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   ULong64_t       _runNb;
   ULong64_t       _lumiBlock;
   ULong64_t       _eventNb;
   UChar_t         _nVertex;
   Float_t         _nTrueInt;
   Double_t        _weight;
   Double_t        _lheHTIncoming;
   Double_t        _ctauHN;
   UChar_t         _nLheWeights;
   Double_t        _lheWeight[110];   //[_nLheWeights]
   UChar_t         _nPsWeights;
   Double_t        _psWeight[1];   //[_nPsWeights]
   UChar_t         _ttgEventType;
   UChar_t         _zgEventType;
   Double_t        _gen_met;
   Double_t        _gen_metPhi;
   UChar_t         _gen_nPh;
   UInt_t          _gen_phStatus[10];   //[_gen_nPh]
   Double_t        _gen_phPt[10];   //[_gen_nPh]
   Double_t        _gen_phEta[10];   //[_gen_nPh]
   Double_t        _gen_phPhi[10];   //[_gen_nPh]
   Double_t        _gen_phE[10];   //[_gen_nPh]
   Int_t           _gen_phMomPdg[10];   //[_gen_nPh]
   Bool_t          _gen_phIsPrompt[10];   //[_gen_nPh]
   Double_t        _gen_phMinDeltaR[10];   //[_gen_nPh]
   Bool_t          _gen_phPassParentage[10];   //[_gen_nPh]
   UChar_t         _gen_nL;
   Double_t        _gen_lPt[20];   //[_gen_nL]
   Double_t        _gen_lEta[20];   //[_gen_nL]
   Double_t        _gen_lPhi[20];   //[_gen_nL]
   Double_t        _gen_lE[20];   //[_gen_nL]
   UInt_t          _gen_lFlavor[20];   //[_gen_nL]
   Int_t           _gen_lCharge[20];   //[_gen_nL]
   Int_t           _gen_lMomPdg[20];   //[_gen_nL]
   Bool_t          _gen_lIsPrompt[20];   //[_gen_nL]
   Double_t        _gen_lMinDeltaR[20];   //[_gen_nL]
   Bool_t          _gen_lPassParentage[20];   //[_gen_nL]
   Double_t        _gen_HT;
   Bool_t          _passMETFilters;
   Bool_t          _Flag_HBHENoiseFilter;
   Bool_t          _Flag_HBHENoiseIsoFilter;
   Bool_t          _Flag_EcalDeadCellTriggerPrimitiveFilter;
   Bool_t          _Flag_goodVertices;
   Bool_t          _Flag_globalTightHalo2016Filter;
   Bool_t          _Flag_ecalBadCalibFilter;
   Bool_t          _Flag_BadPFMuonFilter;
   Bool_t          _Flag_BadChargedCandidateFilter;
   Bool_t          _passTrigger_e;
   Bool_t          _HLT_Ele32_WPTight_Gsf;
   Int_t           _HLT_Ele32_WPTight_Gsf_prescale;
   Bool_t          _HLT_Ele35_WPTight_Gsf;
   Int_t           _HLT_Ele35_WPTight_Gsf_prescale;
   Bool_t          _HLT_Ele38_WPTight_Gsf;
   Int_t           _HLT_Ele38_WPTight_Gsf_prescale;
   Bool_t          _HLT_Ele40_WPTight_Gsf;
   Int_t           _HLT_Ele40_WPTight_Gsf_prescale;
   Bool_t          _passTrigger_ee;
   Bool_t          _HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
   Int_t           _HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale;
   Bool_t          _HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           _HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
   Bool_t          _passTrigger_eee;
   Bool_t          _HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
   Int_t           _HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale;
   Bool_t          _passTrigger_eem;
   Bool_t          _HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
   Int_t           _HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale;
   Bool_t          _HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ;
   Int_t           _HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ_prescale;
   Bool_t          _passTrigger_em;
   Bool_t          _HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ;
   Int_t           _HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ_prescale;
   Bool_t          _HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           _HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
   Bool_t          _HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           _HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
   Bool_t          _HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           _HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
   Bool_t          _HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;
   Int_t           _HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_prescale;
   Bool_t          _passTrigger_emm;
   Bool_t          _HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
   Int_t           _HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale;
   Bool_t          _HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ;
   Int_t           _HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_prescale;
   Bool_t          _passTrigger_et;
   Bool_t          _HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1;
   Int_t           _HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_prescale;
   Bool_t          _passTrigger_m;
   Bool_t          _HLT_IsoMu24;
   Int_t           _HLT_IsoMu24_prescale;
   Bool_t          _HLT_IsoMu24_eta2p1;
   Int_t           _HLT_IsoMu24_eta2p1_prescale;
   Bool_t          _HLT_IsoMu27;
   Int_t           _HLT_IsoMu27_prescale;
   Bool_t          _HLT_IsoMu30;
   Int_t           _HLT_IsoMu30_prescale;
   Bool_t          _HLT_Mu50;
   Int_t           _HLT_Mu50_prescale;
   Bool_t          _HLT_Mu55;
   Int_t           _HLT_Mu55_prescale;
   Bool_t          _passTrigger_mm;
   Bool_t          _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
   Int_t           _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale;
   Bool_t          _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
   Int_t           _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale;
   Bool_t          _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;
   Int_t           _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_prescale;
   Bool_t          _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;
   Int_t           _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_prescale;
   Bool_t          _HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8;
   Int_t           _HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8_prescale;
   Bool_t          _HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8;
   Int_t           _HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8_prescale;
   Bool_t          _passTrigger_mmm;
   Bool_t          _HLT_TripleMu_10_5_5_DZ;
   Int_t           _HLT_TripleMu_10_5_5_DZ_prescale;
   Bool_t          _HLT_TripleMu_5_3_3_Mass3p8to60_DZ;
   Int_t           _HLT_TripleMu_5_3_3_Mass3p8to60_DZ_prescale;
   Bool_t          _TripleMu_12_10_5;
   Bool_t          _passTrigger_mt;
   Bool_t          _HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1;
   Int_t           _HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_prescale;
   Bool_t          _HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1;
   Int_t           _HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_prescale;
   Bool_t          _HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1;
   Int_t           _HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1_prescale;
   Bool_t          _HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1;
   Int_t           _HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1_prescale;
   Bool_t          _HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;
   Int_t           _HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_prescale;
   Bool_t          _passTrigger_t;
   Bool_t          _HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;
   Int_t           _HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_prescale;
   UChar_t         _nL;
   UChar_t         _nMu;
   UChar_t         _nEle;
   UChar_t         _nLight;
   UChar_t         _nTau;
   Double_t        _lPt[7];   //[_nL]
   Double_t        _lEta[7];   //[_nL]
   Double_t        _lEtaSC[7];   //[_nLight]
   Double_t        _lPhi[7];   //[_nL]
   Double_t        _lE[7];   //[_nL]
   UInt_t          _lFlavor[7];   //[_nL]
   Int_t           _lCharge[7];   //[_nL]
   Double_t        _dxy[7];   //[_nL]
   Double_t        _dz[7];   //[_nL]
   Double_t        _3dIP[7];   //[_nL]
   Double_t        _3dIPSig[7];   //[_nL]
   Float_t         _lElectronMva[7];   //[_nLight]
   Float_t         _lElectronMvaHZZ[7];   //[_nLight]
   Float_t         _lElectronMvaFall17Iso[7];   //[_nLight]
   Float_t         _lElectronMvaFall17NoIso[7];   //[_nLight]
   Bool_t          _lElectronPassEmu[7];   //[_nLight]
   Bool_t          _lElectronPassConvVeto[7];   //[_nLight]
   Bool_t          _lElectronChargeConst[7];   //[_nLight]
   UInt_t          _lElectronMissingHits[7];   //[_nLight]
   Double_t        _leptonMvaSUSY16[7];   //[_nLight]
   Double_t        _leptonMvaTTH16[7];   //[_nLight]
   Double_t        _leptonMvaSUSY17[7];   //[_nLight]
   Double_t        _leptonMvaTTH17[7];   //[_nLight]
   Double_t        _leptonMvatZqTTV16[7];   //[_nLight]
   Double_t        _leptonMvatZqTTV17[7];   //[_nLight]
   Bool_t          _lHNLoose[7];   //[_nLight]
   Bool_t          _lHNFO[7];   //[_nLight]
   Bool_t          _lHNTight[7];   //[_nLight]
   Bool_t          _lEwkLoose[7];   //[_nL]
   Bool_t          _lEwkFO[7];   //[_nL]
   Bool_t          _lEwkTight[7];   //[_nL]
   Bool_t          _lPOGVeto[7];   //[_nL]
   Bool_t          _lPOGLoose[7];   //[_nL]
   Bool_t          _lPOGMedium[7];   //[_nL]
   Bool_t          _lPOGTight[7];   //[_nL]
   Bool_t          _lPOGLooseWOIso[7];   //[_nLight]
   Bool_t          _lPOGMediumWOIso[7];   //[_nLight]
   Bool_t          _lPOGTightWOIso[7];   //[_nLight]
   Bool_t          _tauMuonVeto[7];   //[_nL]
   Bool_t          _tauEleVeto[7];   //[_nL]
   Bool_t          _decayModeFindingNew[7];   //[_nL]
   Bool_t          _tauVLooseMvaNew[7];   //[_nL]
   Bool_t          _tauLooseMvaNew[7];   //[_nL]
   Bool_t          _tauMediumMvaNew[7];   //[_nL]
   Bool_t          _tauTightMvaNew[7];   //[_nL]
   Bool_t          _tauVTightMvaNew[7];   //[_nL]
   Bool_t          _tauVTightMvaOld[7];   //[_nL]
   Double_t        _tauAgainstElectronMVA6Raw[7];   //[_nL]
   Double_t        _tauCombinedIsoDBRaw3Hits[7];   //[_nL]
   Double_t        _tauIsoMVAPWdR03oldDMwLT[7];   //[_nL]
   Double_t        _tauIsoMVADBdR03oldDMwLT[7];   //[_nL]
   Double_t        _tauIsoMVADBdR03newDMwLT[7];   //[_nL]
   Double_t        _tauIsoMVAPWnewDMwLT[7];   //[_nL]
   Double_t        _tauIsoMVAPWoldDMwLT[7];   //[_nL]
   Double_t        _relIso[7];   //[_nLight]
   Double_t        _relIso0p4[7];   //[_nLight]
   Double_t        _relIso0p4MuDeltaBeta[5];   //[_nMu]
   Double_t        _miniIso[7];   //[_nLight]
   Double_t        _miniIsoCharged[7];   //[_nLight]
   Double_t        _ptRel[7];   //[_nLight]
   Double_t        _ptRatio[7];   //[_nLight]
   Double_t        _closestJetCsvV2[7];   //[_nLight]
   Double_t        _closestJetDeepCsv_b[7];   //[_nLight]
   Double_t        _closestJetDeepCsv_bb[7];   //[_nLight]
   UInt_t          _selectedTrackMult[7];   //[_nLight]
   Double_t        _lMuonSegComp[5];   //[_nMu]
   Double_t        _lMuonTrackPt[5];   //[_nMu]
   Double_t        _lMuonTrackPtErr[5];   //[_nMu]
   Bool_t          _lIsPrompt[7];   //[_nL]
   Int_t           _lMatchPdgId[7];   //[_nL]
   Int_t           _lMomPdgId[7];   //[_nL]
   UInt_t          _lProvenance[7];   //[_nL]
   UInt_t          _lProvenanceCompressed[7];   //[_nL]
   UInt_t          _lProvenanceConversion[7];   //[_nL]
   UChar_t         _nPh;
   Double_t        _phPt[8];   //[_nPh]
   Double_t        _phEta[8];   //[_nPh]
   Double_t        _phEtaSC[8];   //[_nPh]
   Double_t        _phPhi[8];   //[_nPh]
   Double_t        _phE[8];   //[_nPh]
   Bool_t          _phCutBasedLoose[8];   //[_nPh]
   Bool_t          _phCutBasedMedium[8];   //[_nPh]
   Bool_t          _phCutBasedTight[8];   //[_nPh]
   Double_t        _phMva[8];   //[_nPh]
   Double_t        _phRandomConeChargedIsolation[8];   //[_nPh]
   Double_t        _phChargedIsolation[8];   //[_nPh]
   Double_t        _phNeutralHadronIsolation[8];   //[_nPh]
   Double_t        _phPhotonIsolation[8];   //[_nPh]
   Double_t        _phSigmaIetaIeta[8];   //[_nPh]
   Double_t        _phSigmaIetaIphi[8];   //[_nPh]
   Double_t        _phHadronicOverEm[8];   //[_nPh]
   Bool_t          _phPassElectronVeto[8];   //[_nPh]
   Bool_t          _phHasPixelSeed[8];   //[_nPh]
   Bool_t          _phIsPrompt[8];   //[_nPh]
   Int_t           _phMatchMCPhotonAN15165[8];   //[_nPh]
   Int_t           _phMatchMCLeptonAN15165[8];   //[_nPh]
   Int_t           _phTTGMatchCategory[8];   //[_nPh]
   Double_t        _phTTGMatchPt[8];   //[_nPh]
   Double_t        _phTTGMatchEta[8];   //[_nPh]
   Int_t           _phMatchPdgId[8];   //[_nPh]
   UChar_t         _nJets;
   Double_t        _jetPt[20];   //[_nJets]
   Double_t        _jetPt_JECDown[20];   //[_nJets]
   Double_t        _jetPt_JECUp[20];   //[_nJets]
   Double_t        _jetSmearedPt[20];   //[_nJets]
   Double_t        _jetSmearedPt_JECDown[20];   //[_nJets]
   Double_t        _jetSmearedPt_JECUp[20];   //[_nJets]
   Double_t        _jetSmearedPt_JERDown[20];   //[_nJets]
   Double_t        _jetSmearedPt_JERUp[20];   //[_nJets]
   Double_t        _jetPt_Uncorrected[20];   //[_nJets]
   Double_t        _jetPt_L1[20];   //[_nJets]
   Double_t        _jetPt_L2[20];   //[_nJets]
   Double_t        _jetPt_L3[20];   //[_nJets]
   Double_t        _jetEta[20];   //[_nJets]
   Double_t        _jetPhi[20];   //[_nJets]
   Double_t        _jetE[20];   //[_nJets]
   Double_t        _jetCsvV2[20];   //[_nJets]
   Double_t        _jetDeepCsv_udsg[20];   //[_nJets]
   Double_t        _jetDeepCsv_b[20];   //[_nJets]
   Double_t        _jetDeepCsv_c[20];   //[_nJets]
   Double_t        _jetDeepCsv_bb[20];   //[_nJets]
   UInt_t          _jetHadronFlavor[20];   //[_nJets]
   Bool_t          _jetIsLoose[20];   //[_nJets]
   Bool_t          _jetIsTight[20];   //[_nJets]
   Bool_t          _jetIsTightLepVeto[20];   //[_nJets]
   Double_t        _jetNeutralHadronFraction[20];   //[_nJets]
   Double_t        _jetChargedHadronFraction[20];   //[_nJets]
   Double_t        _jetNeutralEmFraction[20];   //[_nJets]
   Double_t        _jetChargedEmFraction[20];   //[_nJets]
   Double_t        _jetHFHadronFraction[20];   //[_nJets]
   Double_t        _jetHFEmFraction[20];   //[_nJets]
   Double_t        _met;
   Double_t        _metRaw;
   Double_t        _metJECDown;
   Double_t        _metJECUp;
   Double_t        _metUnclDown;
   Double_t        _metUnclUp;
   Double_t        _metPhi;
   Double_t        _metRawPhi;
   Double_t        _metPhiJECDown;
   Double_t        _metPhiJECUp;
   Double_t        _metPhiUnclDown;
   Double_t        _metPhiUnclUp;
   Double_t        _metSignificance;

   // List of branches
   TBranch        *b__runNb;   //!
   TBranch        *b__lumiBlock;   //!
   TBranch        *b__eventNb;   //!
   TBranch        *b__nVertex;   //!
   TBranch        *b__nTrueInt;   //!
   TBranch        *b__weight;   //!
   TBranch        *b__lheHTIncoming;   //!
   TBranch        *b__ctauHN;   //!
   TBranch        *b__nLheWeights;   //!
   TBranch        *b__lheWeight;   //!
   TBranch        *b__nPsWeights;   //!
   TBranch        *b__psWeight;   //!
   TBranch        *b__ttgEventType;   //!
   TBranch        *b__zgEventType;   //!
   TBranch        *b__gen_met;   //!
   TBranch        *b__gen_metPhi;   //!
   TBranch        *b__gen_nPh;   //!
   TBranch        *b__gen_phStatus;   //!
   TBranch        *b__gen_phPt;   //!
   TBranch        *b__gen_phEta;   //!
   TBranch        *b__gen_phPhi;   //!
   TBranch        *b__gen_phE;   //!
   TBranch        *b__gen_phMomPdg;   //!
   TBranch        *b__gen_phIsPrompt;   //!
   TBranch        *b__gen_phMinDeltaR;   //!
   TBranch        *b__gen_phPassParentage;   //!
   TBranch        *b__gen_nL;   //!
   TBranch        *b__gen_lPt;   //!
   TBranch        *b__gen_lEta;   //!
   TBranch        *b__gen_lPhi;   //!
   TBranch        *b__gen_lE;   //!
   TBranch        *b__gen_lFlavor;   //!
   TBranch        *b__gen_lCharge;   //!
   TBranch        *b__gen_lMomPdg;   //!
   TBranch        *b__gen_lIsPrompt;   //!
   TBranch        *b__gen_lMinDeltaR;   //!
   TBranch        *b__gen_lPassParentage;   //!
   TBranch        *b__gen_HT;   //!
   TBranch        *b__passMETFilters;   //!
   TBranch        *b__Flag_HBHENoiseFilter;   //!
   TBranch        *b__Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b__Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b__Flag_goodVertices;   //!
   TBranch        *b__Flag_globalTightHalo2016Filter;   //!
   TBranch        *b__Flag_ecalBadCalibFilter;   //!
   TBranch        *b__Flag_BadPFMuonFilter;   //!
   TBranch        *b__Flag_BadChargedCandidateFilter;   //!
   TBranch        *b__passTrigger_e;   //!
   TBranch        *b__HLT_Ele32_WPTight_Gsf;   //!
   TBranch        *b__HLT_Ele32_WPTight_Gsf_prescale;   //!
   TBranch        *b__HLT_Ele35_WPTight_Gsf;   //!
   TBranch        *b__HLT_Ele35_WPTight_Gsf_prescale;   //!
   TBranch        *b__HLT_Ele38_WPTight_Gsf;   //!
   TBranch        *b__HLT_Ele38_WPTight_Gsf_prescale;   //!
   TBranch        *b__HLT_Ele40_WPTight_Gsf;   //!
   TBranch        *b__HLT_Ele40_WPTight_Gsf_prescale;   //!
   TBranch        *b__passTrigger_ee;   //!
   TBranch        *b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale;   //!
   TBranch        *b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
   TBranch        *b__passTrigger_eee;   //!
   TBranch        *b__HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;   //!
   TBranch        *b__HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale;   //!
   TBranch        *b__passTrigger_eem;   //!
   TBranch        *b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL;   //!
   TBranch        *b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale;   //!
   TBranch        *b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ;   //!
   TBranch        *b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ_prescale;   //!
   TBranch        *b__passTrigger_em;   //!
   TBranch        *b__HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ;   //!
   TBranch        *b__HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ_prescale;   //!
   TBranch        *b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
   TBranch        *b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
   TBranch        *b__HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b__HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
   TBranch        *b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_prescale;   //!
   TBranch        *b__passTrigger_emm;   //!
   TBranch        *b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL;   //!
   TBranch        *b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale;   //!
   TBranch        *b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ;   //!
   TBranch        *b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_prescale;   //!
   TBranch        *b__passTrigger_et;   //!
   TBranch        *b__HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1;   //!
   TBranch        *b__HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_prescale;   //!
   TBranch        *b__passTrigger_m;   //!
   TBranch        *b__HLT_IsoMu24;   //!
   TBranch        *b__HLT_IsoMu24_prescale;   //!
   TBranch        *b__HLT_IsoMu24_eta2p1;   //!
   TBranch        *b__HLT_IsoMu24_eta2p1_prescale;   //!
   TBranch        *b__HLT_IsoMu27;   //!
   TBranch        *b__HLT_IsoMu27_prescale;   //!
   TBranch        *b__HLT_IsoMu30;   //!
   TBranch        *b__HLT_IsoMu30_prescale;   //!
   TBranch        *b__HLT_Mu50;   //!
   TBranch        *b__HLT_Mu50_prescale;   //!
   TBranch        *b__HLT_Mu55;   //!
   TBranch        *b__HLT_Mu55_prescale;   //!
   TBranch        *b__passTrigger_mm;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_prescale;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_prescale;   //!
   TBranch        *b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8;   //!
   TBranch        *b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8_prescale;   //!
   TBranch        *b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8;   //!
   TBranch        *b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8_prescale;   //!
   TBranch        *b__passTrigger_mmm;   //!
   TBranch        *b__HLT_TripleMu_10_5_5_DZ;   //!
   TBranch        *b__HLT_TripleMu_10_5_5_DZ_prescale;   //!
   TBranch        *b__HLT_TripleMu_5_3_3_Mass3p8to60_DZ;   //!
   TBranch        *b__HLT_TripleMu_5_3_3_Mass3p8to60_DZ_prescale;   //!
   TBranch        *b__TripleMu_12_10_5;   //!
   TBranch        *b__passTrigger_mt;   //!
   TBranch        *b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1;   //!
   TBranch        *b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_prescale;   //!
   TBranch        *b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1;   //!
   TBranch        *b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_prescale;   //!
   TBranch        *b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1;   //!
   TBranch        *b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1_prescale;   //!
   TBranch        *b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1;   //!
   TBranch        *b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1_prescale;   //!
   TBranch        *b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_prescale;   //!
   TBranch        *b__passTrigger_t;   //!
   TBranch        *b__HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;   //!
   TBranch        *b__HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_prescale;   //!
   TBranch        *b__nL;   //!
   TBranch        *b__nMu;   //!
   TBranch        *b__nEle;   //!
   TBranch        *b__nLight;   //!
   TBranch        *b__nTau;   //!
   TBranch        *b__lPt;   //!
   TBranch        *b__lEta;   //!
   TBranch        *b__lEtaSC;   //!
   TBranch        *b__lPhi;   //!
   TBranch        *b__lE;   //!
   TBranch        *b__lFlavor;   //!
   TBranch        *b__lCharge;   //!
   TBranch        *b__dxy;   //!
   TBranch        *b__dz;   //!
   TBranch        *b__3dIP;   //!
   TBranch        *b__3dIPSig;   //!
   TBranch        *b__lElectronMva;   //!
   TBranch        *b__lElectronMvaHZZ;   //!
   TBranch        *b__lElectronMvaFall17Iso;   //!
   TBranch        *b__lElectronMvaFall17NoIso;   //!
   TBranch        *b__lElectronPassEmu;   //!
   TBranch        *b__lElectronPassConvVeto;   //!
   TBranch        *b__lElectronChargeConst;   //!
   TBranch        *b__lElectronMissingHits;   //!
   TBranch        *b__leptonMvaSUSY16;   //!
   TBranch        *b__leptonMvaTTH16;   //!
   TBranch        *b__leptonMvaSUSY17;   //!
   TBranch        *b__leptonMvaTTH17;   //!
   TBranch        *b__leptonMvatZqTTV16;   //!
   TBranch        *b__leptonMvatZqTTV17;   //!
   TBranch        *b__lHNLoose;   //!
   TBranch        *b__lHNFO;   //!
   TBranch        *b__lHNTight;   //!
   TBranch        *b__lEwkLoose;   //!
   TBranch        *b__lEwkFO;   //!
   TBranch        *b__lEwkTight;   //!
   TBranch        *b__lPOGVeto;   //!
   TBranch        *b__lPOGLoose;   //!
   TBranch        *b__lPOGMedium;   //!
   TBranch        *b__lPOGTight;   //!
   TBranch        *b__lPOGLooseWOIso;   //!
   TBranch        *b__lPOGMediumWOIso;   //!
   TBranch        *b__lPOGTightWOIso;   //!
   TBranch        *b__tauMuonVeto;   //!
   TBranch        *b__tauEleVeto;   //!
   TBranch        *b__decayModeFindingNew;   //!
   TBranch        *b__tauVLooseMvaNew;   //!
   TBranch        *b__tauLooseMvaNew;   //!
   TBranch        *b__tauMediumMvaNew;   //!
   TBranch        *b__tauTightMvaNew;   //!
   TBranch        *b__tauVTightMvaNew;   //!
   TBranch        *b__tauVTightMvaOld;   //!
   TBranch        *b__tauAgainstElectronMVA6Raw;   //!
   TBranch        *b__tauCombinedIsoDBRaw3Hits;   //!
   TBranch        *b__tauIsoMVAPWdR03oldDMwLT;   //!
   TBranch        *b__tauIsoMVADBdR03oldDMwLT;   //!
   TBranch        *b__tauIsoMVADBdR03newDMwLT;   //!
   TBranch        *b__tauIsoMVAPWnewDMwLT;   //!
   TBranch        *b__tauIsoMVAPWoldDMwLT;   //!
   TBranch        *b__relIso;   //!
   TBranch        *b__relIso0p4;   //!
   TBranch        *b__relIso0p4MuDeltaBeta;   //!
   TBranch        *b__miniIso;   //!
   TBranch        *b__miniIsoCharged;   //!
   TBranch        *b__ptRel;   //!
   TBranch        *b__ptRatio;   //!
   TBranch        *b__closestJetCsvV2;   //!
   TBranch        *b__closestJetDeepCsv_b;   //!
   TBranch        *b__closestJetDeepCsv_bb;   //!
   TBranch        *b__selectedTrackMult;   //!
   TBranch        *b__lMuonSegComp;   //!
   TBranch        *b__lMuonTrackPt;   //!
   TBranch        *b__lMuonTrackPtErr;   //!
   TBranch        *b__lIsPrompt;   //!
   TBranch        *b__lMatchPdgId;   //!
   TBranch        *b__lMomPdgId;   //!
   TBranch        *b__lProvenance;   //!
   TBranch        *b__lProvenanceCompressed;   //!
   TBranch        *b__lProvenanceConversion;   //!
   TBranch        *b__nPh;   //!
   TBranch        *b__phPt;   //!
   TBranch        *b__phEta;   //!
   TBranch        *b__phEtaSC;   //!
   TBranch        *b__phPhi;   //!
   TBranch        *b__phE;   //!
   TBranch        *b__phCutBasedLoose;   //!
   TBranch        *b__phCutBasedMedium;   //!
   TBranch        *b__phCutBasedTight;   //!
   TBranch        *b__phMva;   //!
   TBranch        *b__phRandomConeChargedIsolation;   //!
   TBranch        *b__phChargedIsolation;   //!
   TBranch        *b__phNeutralHadronIsolation;   //!
   TBranch        *b__phPhotonIsolation;   //!
   TBranch        *b__phSigmaIetaIeta;   //!
   TBranch        *b__phSigmaIetaIphi;   //!
   TBranch        *b__phHadronicOverEm;   //!
   TBranch        *b__phPassElectronVeto;   //!
   TBranch        *b__phHasPixelSeed;   //!
   TBranch        *b__phIsPrompt;   //!
   TBranch        *b__phMatchMCPhotonAN15165;   //!
   TBranch        *b__phMatchMCLeptonAN15165;   //!
   TBranch        *b__phTTGMatchCategory;   //!
   TBranch        *b__phTTGMatchPt;   //!
   TBranch        *b__phTTGMatchEta;   //!
   TBranch        *b__phMatchPdgId;   //!
   TBranch        *b__nJets;   //!
   TBranch        *b__jetPt;   //!
   TBranch        *b__jetPt_JECDown;   //!
   TBranch        *b__jetPt_JECUp;   //!
   TBranch        *b__jetSmearedPt;   //!
   TBranch        *b__jetSmearedPt_JECDown;   //!
   TBranch        *b__jetSmearedPt_JECUp;   //!
   TBranch        *b__jetSmearedPt_JERDown;   //!
   TBranch        *b__jetSmearedPt_JERUp;   //!
   TBranch        *b__jetPt_Uncorrected;   //!
   TBranch        *b__jetPt_L1;   //!
   TBranch        *b__jetPt_L2;   //!
   TBranch        *b__jetPt_L3;   //!
   TBranch        *b__jetEta;   //!
   TBranch        *b__jetPhi;   //!
   TBranch        *b__jetE;   //!
   TBranch        *b__jetCsvV2;   //!
   TBranch        *b__jetDeepCsv_udsg;   //!
   TBranch        *b__jetDeepCsv_b;   //!
   TBranch        *b__jetDeepCsv_c;   //!
   TBranch        *b__jetDeepCsv_bb;   //!
   TBranch        *b__jetHadronFlavor;   //!
   TBranch        *b__jetIsLoose;   //!
   TBranch        *b__jetIsTight;   //!
   TBranch        *b__jetIsTightLepVeto;   //!
   TBranch        *b__jetNeutralHadronFraction;   //!
   TBranch        *b__jetChargedHadronFraction;   //!
   TBranch        *b__jetNeutralEmFraction;   //!
   TBranch        *b__jetChargedEmFraction;   //!
   TBranch        *b__jetHFHadronFraction;   //!
   TBranch        *b__jetHFEmFraction;   //!
   TBranch        *b__met;   //!
   TBranch        *b__metRaw;   //!
   TBranch        *b__metJECDown;   //!
   TBranch        *b__metJECUp;   //!
   TBranch        *b__metUnclDown;   //!
   TBranch        *b__metUnclUp;   //!
   TBranch        *b__metPhi;   //!
   TBranch        *b__metRawPhi;   //!
   TBranch        *b__metPhiJECDown;   //!
   TBranch        *b__metPhiJECUp;   //!
   TBranch        *b__metPhiUnclDown;   //!
   TBranch        *b__metPhiUnclUp;   //!
   TBranch        *b__metSignificance;   //!

   WzTo3LNuTreeBranches(TTree *tree=0);
   virtual ~WzTo3LNuTreeBranches();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef WzTo3LNuTreeBranches_cxx
WzTo3LNuTreeBranches::WzTo3LNuTreeBranches(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("WZTo3LNu.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("WZTo3LNu.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("WZTo3LNu.root:/blackJackAndHookers");
      dir->GetObject("blackJackAndHookersTree",tree);

   }
   Init(tree);
}

WzTo3LNuTreeBranches::~WzTo3LNuTreeBranches()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t WzTo3LNuTreeBranches::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t WzTo3LNuTreeBranches::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void WzTo3LNuTreeBranches::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("_runNb", &_runNb, &b__runNb);
   fChain->SetBranchAddress("_lumiBlock", &_lumiBlock, &b__lumiBlock);
   fChain->SetBranchAddress("_eventNb", &_eventNb, &b__eventNb);
   fChain->SetBranchAddress("_nVertex", &_nVertex, &b__nVertex);
   fChain->SetBranchAddress("_nTrueInt", &_nTrueInt, &b__nTrueInt);
   fChain->SetBranchAddress("_weight", &_weight, &b__weight);
   fChain->SetBranchAddress("_lheHTIncoming", &_lheHTIncoming, &b__lheHTIncoming);
   fChain->SetBranchAddress("_ctauHN", &_ctauHN, &b__ctauHN);
   fChain->SetBranchAddress("_nLheWeights", &_nLheWeights, &b__nLheWeights);
   fChain->SetBranchAddress("_lheWeight", _lheWeight, &b__lheWeight);
   fChain->SetBranchAddress("_nPsWeights", &_nPsWeights, &b__nPsWeights);
   fChain->SetBranchAddress("_psWeight", _psWeight, &b__psWeight);
   fChain->SetBranchAddress("_ttgEventType", &_ttgEventType, &b__ttgEventType);
   fChain->SetBranchAddress("_zgEventType", &_zgEventType, &b__zgEventType);
   fChain->SetBranchAddress("_gen_met", &_gen_met, &b__gen_met);
   fChain->SetBranchAddress("_gen_metPhi", &_gen_metPhi, &b__gen_metPhi);
   fChain->SetBranchAddress("_gen_nPh", &_gen_nPh, &b__gen_nPh);
   fChain->SetBranchAddress("_gen_phStatus", _gen_phStatus, &b__gen_phStatus);
   fChain->SetBranchAddress("_gen_phPt", _gen_phPt, &b__gen_phPt);
   fChain->SetBranchAddress("_gen_phEta", _gen_phEta, &b__gen_phEta);
   fChain->SetBranchAddress("_gen_phPhi", _gen_phPhi, &b__gen_phPhi);
   fChain->SetBranchAddress("_gen_phE", _gen_phE, &b__gen_phE);
   fChain->SetBranchAddress("_gen_phMomPdg", _gen_phMomPdg, &b__gen_phMomPdg);
   fChain->SetBranchAddress("_gen_phIsPrompt", _gen_phIsPrompt, &b__gen_phIsPrompt);
   fChain->SetBranchAddress("_gen_phMinDeltaR", _gen_phMinDeltaR, &b__gen_phMinDeltaR);
   fChain->SetBranchAddress("_gen_phPassParentage", _gen_phPassParentage, &b__gen_phPassParentage);
   fChain->SetBranchAddress("_gen_nL", &_gen_nL, &b__gen_nL);
   fChain->SetBranchAddress("_gen_lPt", _gen_lPt, &b__gen_lPt);
   fChain->SetBranchAddress("_gen_lEta", _gen_lEta, &b__gen_lEta);
   fChain->SetBranchAddress("_gen_lPhi", _gen_lPhi, &b__gen_lPhi);
   fChain->SetBranchAddress("_gen_lE", _gen_lE, &b__gen_lE);
   fChain->SetBranchAddress("_gen_lFlavor", _gen_lFlavor, &b__gen_lFlavor);
   fChain->SetBranchAddress("_gen_lCharge", _gen_lCharge, &b__gen_lCharge);
   fChain->SetBranchAddress("_gen_lMomPdg", _gen_lMomPdg, &b__gen_lMomPdg);
   fChain->SetBranchAddress("_gen_lIsPrompt", _gen_lIsPrompt, &b__gen_lIsPrompt);
   fChain->SetBranchAddress("_gen_lMinDeltaR", _gen_lMinDeltaR, &b__gen_lMinDeltaR);
   fChain->SetBranchAddress("_gen_lPassParentage", _gen_lPassParentage, &b__gen_lPassParentage);
   fChain->SetBranchAddress("_gen_HT", &_gen_HT, &b__gen_HT);
   fChain->SetBranchAddress("_passMETFilters", &_passMETFilters, &b__passMETFilters);
   fChain->SetBranchAddress("_Flag_HBHENoiseFilter", &_Flag_HBHENoiseFilter, &b__Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("_Flag_HBHENoiseIsoFilter", &_Flag_HBHENoiseIsoFilter, &b__Flag_HBHENoiseIsoFilter);
   fChain->SetBranchAddress("_Flag_EcalDeadCellTriggerPrimitiveFilter", &_Flag_EcalDeadCellTriggerPrimitiveFilter, &b__Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("_Flag_goodVertices", &_Flag_goodVertices, &b__Flag_goodVertices);
   fChain->SetBranchAddress("_Flag_globalTightHalo2016Filter", &_Flag_globalTightHalo2016Filter, &b__Flag_globalTightHalo2016Filter);
   fChain->SetBranchAddress("_Flag_ecalBadCalibFilter", &_Flag_ecalBadCalibFilter, &b__Flag_ecalBadCalibFilter);
   fChain->SetBranchAddress("_Flag_BadPFMuonFilter", &_Flag_BadPFMuonFilter, &b__Flag_BadPFMuonFilter);
   fChain->SetBranchAddress("_Flag_BadChargedCandidateFilter", &_Flag_BadChargedCandidateFilter, &b__Flag_BadChargedCandidateFilter);
   fChain->SetBranchAddress("_passTrigger_e", &_passTrigger_e, &b__passTrigger_e);
   fChain->SetBranchAddress("_HLT_Ele32_WPTight_Gsf", &_HLT_Ele32_WPTight_Gsf, &b__HLT_Ele32_WPTight_Gsf);
   fChain->SetBranchAddress("_HLT_Ele32_WPTight_Gsf_prescale", &_HLT_Ele32_WPTight_Gsf_prescale, &b__HLT_Ele32_WPTight_Gsf_prescale);
   fChain->SetBranchAddress("_HLT_Ele35_WPTight_Gsf", &_HLT_Ele35_WPTight_Gsf, &b__HLT_Ele35_WPTight_Gsf);
   fChain->SetBranchAddress("_HLT_Ele35_WPTight_Gsf_prescale", &_HLT_Ele35_WPTight_Gsf_prescale, &b__HLT_Ele35_WPTight_Gsf_prescale);
   fChain->SetBranchAddress("_HLT_Ele38_WPTight_Gsf", &_HLT_Ele38_WPTight_Gsf, &b__HLT_Ele38_WPTight_Gsf);
   fChain->SetBranchAddress("_HLT_Ele38_WPTight_Gsf_prescale", &_HLT_Ele38_WPTight_Gsf_prescale, &b__HLT_Ele38_WPTight_Gsf_prescale);
   fChain->SetBranchAddress("_HLT_Ele40_WPTight_Gsf", &_HLT_Ele40_WPTight_Gsf, &b__HLT_Ele40_WPTight_Gsf);
   fChain->SetBranchAddress("_HLT_Ele40_WPTight_Gsf_prescale", &_HLT_Ele40_WPTight_Gsf_prescale, &b__HLT_Ele40_WPTight_Gsf_prescale);
   fChain->SetBranchAddress("_passTrigger_ee", &_passTrigger_ee, &b__passTrigger_ee);
   fChain->SetBranchAddress("_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL", &_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL, &b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale", &_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale, &b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale);
   fChain->SetBranchAddress("_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   fChain->SetBranchAddress("_passTrigger_eee", &_passTrigger_eee, &b__passTrigger_eee);
   fChain->SetBranchAddress("_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL", &_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL, &b__HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL);
   fChain->SetBranchAddress("_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale", &_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale, &b__HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale);
   fChain->SetBranchAddress("_passTrigger_eem", &_passTrigger_eem, &b__passTrigger_eem);
   fChain->SetBranchAddress("_HLT_Mu8_DiEle12_CaloIdL_TrackIdL", &_HLT_Mu8_DiEle12_CaloIdL_TrackIdL, &b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL);
   fChain->SetBranchAddress("_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale", &_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale, &b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale);
   fChain->SetBranchAddress("_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ", &_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ, &b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ);
   fChain->SetBranchAddress("_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ_prescale", &_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ_prescale, &b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ_prescale);
   fChain->SetBranchAddress("_passTrigger_em", &_passTrigger_em, &b__passTrigger_em);
   fChain->SetBranchAddress("_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ", &_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ, &b__HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ);
   fChain->SetBranchAddress("_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ_prescale", &_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ_prescale, &b__HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ_prescale);
   fChain->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   fChain->SetBranchAddress("_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   fChain->SetBranchAddress("_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   fChain->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL", &_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL, &b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_prescale", &_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_prescale, &b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_prescale);
   fChain->SetBranchAddress("_passTrigger_emm", &_passTrigger_emm, &b__passTrigger_emm);
   fChain->SetBranchAddress("_HLT_DiMu9_Ele9_CaloIdL_TrackIdL", &_HLT_DiMu9_Ele9_CaloIdL_TrackIdL, &b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL);
   fChain->SetBranchAddress("_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale", &_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale, &b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale);
   fChain->SetBranchAddress("_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ", &_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ, &b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ);
   fChain->SetBranchAddress("_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_prescale", &_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_prescale, &b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_prescale);
   fChain->SetBranchAddress("_passTrigger_et", &_passTrigger_et, &b__passTrigger_et);
   fChain->SetBranchAddress("_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", &_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1, &b__HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1);
   fChain->SetBranchAddress("_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_prescale", &_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_prescale, &b__HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_prescale);
   fChain->SetBranchAddress("_passTrigger_m", &_passTrigger_m, &b__passTrigger_m);
   fChain->SetBranchAddress("_HLT_IsoMu24", &_HLT_IsoMu24, &b__HLT_IsoMu24);
   fChain->SetBranchAddress("_HLT_IsoMu24_prescale", &_HLT_IsoMu24_prescale, &b__HLT_IsoMu24_prescale);
   fChain->SetBranchAddress("_HLT_IsoMu24_eta2p1", &_HLT_IsoMu24_eta2p1, &b__HLT_IsoMu24_eta2p1);
   fChain->SetBranchAddress("_HLT_IsoMu24_eta2p1_prescale", &_HLT_IsoMu24_eta2p1_prescale, &b__HLT_IsoMu24_eta2p1_prescale);
   fChain->SetBranchAddress("_HLT_IsoMu27", &_HLT_IsoMu27, &b__HLT_IsoMu27);
   fChain->SetBranchAddress("_HLT_IsoMu27_prescale", &_HLT_IsoMu27_prescale, &b__HLT_IsoMu27_prescale);
   fChain->SetBranchAddress("_HLT_IsoMu30", &_HLT_IsoMu30, &b__HLT_IsoMu30);
   fChain->SetBranchAddress("_HLT_IsoMu30_prescale", &_HLT_IsoMu30_prescale, &b__HLT_IsoMu30_prescale);
   fChain->SetBranchAddress("_HLT_Mu50", &_HLT_Mu50, &b__HLT_Mu50);
   fChain->SetBranchAddress("_HLT_Mu50_prescale", &_HLT_Mu50_prescale, &b__HLT_Mu50_prescale);
   fChain->SetBranchAddress("_HLT_Mu55", &_HLT_Mu55, &b__HLT_Mu55);
   fChain->SetBranchAddress("_HLT_Mu55_prescale", &_HLT_Mu55_prescale, &b__HLT_Mu55_prescale);
   fChain->SetBranchAddress("_passTrigger_mm", &_passTrigger_mm, &b__passTrigger_mm);
   fChain->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
   fChain->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale);
   fChain->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
   fChain->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale);
   fChain->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8);
   fChain->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_prescale", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_prescale, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_prescale);
   fChain->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8);
   fChain->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_prescale", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_prescale, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_prescale);
   fChain->SetBranchAddress("_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8", &_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8, &b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8);
   fChain->SetBranchAddress("_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8_prescale", &_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8_prescale, &b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8_prescale);
   fChain->SetBranchAddress("_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8", &_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8, &b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8);
   fChain->SetBranchAddress("_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8_prescale", &_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8_prescale, &b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8_prescale);
   fChain->SetBranchAddress("_passTrigger_mmm", &_passTrigger_mmm, &b__passTrigger_mmm);
   fChain->SetBranchAddress("_HLT_TripleMu_10_5_5_DZ", &_HLT_TripleMu_10_5_5_DZ, &b__HLT_TripleMu_10_5_5_DZ);
   fChain->SetBranchAddress("_HLT_TripleMu_10_5_5_DZ_prescale", &_HLT_TripleMu_10_5_5_DZ_prescale, &b__HLT_TripleMu_10_5_5_DZ_prescale);
   fChain->SetBranchAddress("_HLT_TripleMu_5_3_3_Mass3p8to60_DZ", &_HLT_TripleMu_5_3_3_Mass3p8to60_DZ, &b__HLT_TripleMu_5_3_3_Mass3p8to60_DZ);
   fChain->SetBranchAddress("_HLT_TripleMu_5_3_3_Mass3p8to60_DZ_prescale", &_HLT_TripleMu_5_3_3_Mass3p8to60_DZ_prescale, &b__HLT_TripleMu_5_3_3_Mass3p8to60_DZ_prescale);
   fChain->SetBranchAddress("_TripleMu_12_10_5", &_TripleMu_12_10_5, &b__TripleMu_12_10_5);
   fChain->SetBranchAddress("_passTrigger_mt", &_passTrigger_mt, &b__passTrigger_mt);
   fChain->SetBranchAddress("_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1", &_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1, &b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1);
   fChain->SetBranchAddress("_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_prescale", &_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_prescale, &b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_prescale);
   fChain->SetBranchAddress("_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1", &_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1, &b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_prescale", &_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_prescale, &b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_prescale);
   fChain->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1);
   fChain->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1_prescale", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1_prescale, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1_prescale);
   fChain->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1);
   fChain->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1_prescale", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1_prescale, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1_prescale);
   fChain->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_prescale", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_prescale, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_prescale);
   fChain->SetBranchAddress("_passTrigger_t", &_passTrigger_t, &b__passTrigger_t);
   fChain->SetBranchAddress("_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr", &_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr, &b__HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
   fChain->SetBranchAddress("_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_prescale", &_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_prescale, &b__HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_prescale);
   fChain->SetBranchAddress("_nL", &_nL, &b__nL);
   fChain->SetBranchAddress("_nMu", &_nMu, &b__nMu);
   fChain->SetBranchAddress("_nEle", &_nEle, &b__nEle);
   fChain->SetBranchAddress("_nLight", &_nLight, &b__nLight);
   fChain->SetBranchAddress("_nTau", &_nTau, &b__nTau);
   fChain->SetBranchAddress("_lPt", _lPt, &b__lPt);
   fChain->SetBranchAddress("_lEta", _lEta, &b__lEta);
   fChain->SetBranchAddress("_lEtaSC", _lEtaSC, &b__lEtaSC);
   fChain->SetBranchAddress("_lPhi", _lPhi, &b__lPhi);
   fChain->SetBranchAddress("_lE", _lE, &b__lE);
   fChain->SetBranchAddress("_lFlavor", _lFlavor, &b__lFlavor);
   fChain->SetBranchAddress("_lCharge", _lCharge, &b__lCharge);
   fChain->SetBranchAddress("_dxy", _dxy, &b__dxy);
   fChain->SetBranchAddress("_dz", _dz, &b__dz);
   fChain->SetBranchAddress("_3dIP", _3dIP, &b__3dIP);
   fChain->SetBranchAddress("_3dIPSig", _3dIPSig, &b__3dIPSig);
   fChain->SetBranchAddress("_lElectronMva", _lElectronMva, &b__lElectronMva);
   fChain->SetBranchAddress("_lElectronMvaHZZ", _lElectronMvaHZZ, &b__lElectronMvaHZZ);
   fChain->SetBranchAddress("_lElectronMvaFall17Iso", _lElectronMvaFall17Iso, &b__lElectronMvaFall17Iso);
   fChain->SetBranchAddress("_lElectronMvaFall17NoIso", _lElectronMvaFall17NoIso, &b__lElectronMvaFall17NoIso);
   fChain->SetBranchAddress("_lElectronPassEmu", _lElectronPassEmu, &b__lElectronPassEmu);
   fChain->SetBranchAddress("_lElectronPassConvVeto", _lElectronPassConvVeto, &b__lElectronPassConvVeto);
   fChain->SetBranchAddress("_lElectronChargeConst", _lElectronChargeConst, &b__lElectronChargeConst);
   fChain->SetBranchAddress("_lElectronMissingHits", _lElectronMissingHits, &b__lElectronMissingHits);
   fChain->SetBranchAddress("_leptonMvaSUSY16", _leptonMvaSUSY16, &b__leptonMvaSUSY16);
   fChain->SetBranchAddress("_leptonMvaTTH16", _leptonMvaTTH16, &b__leptonMvaTTH16);
   fChain->SetBranchAddress("_leptonMvaSUSY17", _leptonMvaSUSY17, &b__leptonMvaSUSY17);
   fChain->SetBranchAddress("_leptonMvaTTH17", _leptonMvaTTH17, &b__leptonMvaTTH17);
   fChain->SetBranchAddress("_leptonMvatZqTTV16", _leptonMvatZqTTV16, &b__leptonMvatZqTTV16);
   fChain->SetBranchAddress("_leptonMvatZqTTV17", _leptonMvatZqTTV17, &b__leptonMvatZqTTV17);
   fChain->SetBranchAddress("_lHNLoose", _lHNLoose, &b__lHNLoose);
   fChain->SetBranchAddress("_lHNFO", _lHNFO, &b__lHNFO);
   fChain->SetBranchAddress("_lHNTight", _lHNTight, &b__lHNTight);
   fChain->SetBranchAddress("_lEwkLoose", _lEwkLoose, &b__lEwkLoose);
   fChain->SetBranchAddress("_lEwkFO", _lEwkFO, &b__lEwkFO);
   fChain->SetBranchAddress("_lEwkTight", _lEwkTight, &b__lEwkTight);
   fChain->SetBranchAddress("_lPOGVeto", _lPOGVeto, &b__lPOGVeto);
   fChain->SetBranchAddress("_lPOGLoose", _lPOGLoose, &b__lPOGLoose);
   fChain->SetBranchAddress("_lPOGMedium", _lPOGMedium, &b__lPOGMedium);
   fChain->SetBranchAddress("_lPOGTight", _lPOGTight, &b__lPOGTight);
   fChain->SetBranchAddress("_lPOGLooseWOIso", _lPOGLooseWOIso, &b__lPOGLooseWOIso);
   fChain->SetBranchAddress("_lPOGMediumWOIso", _lPOGMediumWOIso, &b__lPOGMediumWOIso);
   fChain->SetBranchAddress("_lPOGTightWOIso", _lPOGTightWOIso, &b__lPOGTightWOIso);
   fChain->SetBranchAddress("_tauMuonVeto", _tauMuonVeto, &b__tauMuonVeto);
   fChain->SetBranchAddress("_tauEleVeto", _tauEleVeto, &b__tauEleVeto);
   fChain->SetBranchAddress("_decayModeFindingNew", _decayModeFindingNew, &b__decayModeFindingNew);
   fChain->SetBranchAddress("_tauVLooseMvaNew", _tauVLooseMvaNew, &b__tauVLooseMvaNew);
   fChain->SetBranchAddress("_tauLooseMvaNew", _tauLooseMvaNew, &b__tauLooseMvaNew);
   fChain->SetBranchAddress("_tauMediumMvaNew", _tauMediumMvaNew, &b__tauMediumMvaNew);
   fChain->SetBranchAddress("_tauTightMvaNew", _tauTightMvaNew, &b__tauTightMvaNew);
   fChain->SetBranchAddress("_tauVTightMvaNew", _tauVTightMvaNew, &b__tauVTightMvaNew);
   fChain->SetBranchAddress("_tauVTightMvaOld", _tauVTightMvaOld, &b__tauVTightMvaOld);
   fChain->SetBranchAddress("_tauAgainstElectronMVA6Raw", _tauAgainstElectronMVA6Raw, &b__tauAgainstElectronMVA6Raw);
   fChain->SetBranchAddress("_tauCombinedIsoDBRaw3Hits", _tauCombinedIsoDBRaw3Hits, &b__tauCombinedIsoDBRaw3Hits);
   fChain->SetBranchAddress("_tauIsoMVAPWdR03oldDMwLT", _tauIsoMVAPWdR03oldDMwLT, &b__tauIsoMVAPWdR03oldDMwLT);
   fChain->SetBranchAddress("_tauIsoMVADBdR03oldDMwLT", _tauIsoMVADBdR03oldDMwLT, &b__tauIsoMVADBdR03oldDMwLT);
   fChain->SetBranchAddress("_tauIsoMVADBdR03newDMwLT", _tauIsoMVADBdR03newDMwLT, &b__tauIsoMVADBdR03newDMwLT);
   fChain->SetBranchAddress("_tauIsoMVAPWnewDMwLT", _tauIsoMVAPWnewDMwLT, &b__tauIsoMVAPWnewDMwLT);
   fChain->SetBranchAddress("_tauIsoMVAPWoldDMwLT", _tauIsoMVAPWoldDMwLT, &b__tauIsoMVAPWoldDMwLT);
   fChain->SetBranchAddress("_relIso", _relIso, &b__relIso);
   fChain->SetBranchAddress("_relIso0p4", _relIso0p4, &b__relIso0p4);
   fChain->SetBranchAddress("_relIso0p4MuDeltaBeta", _relIso0p4MuDeltaBeta, &b__relIso0p4MuDeltaBeta);
   fChain->SetBranchAddress("_miniIso", _miniIso, &b__miniIso);
   fChain->SetBranchAddress("_miniIsoCharged", _miniIsoCharged, &b__miniIsoCharged);
   fChain->SetBranchAddress("_ptRel", _ptRel, &b__ptRel);
   fChain->SetBranchAddress("_ptRatio", _ptRatio, &b__ptRatio);
   fChain->SetBranchAddress("_closestJetCsvV2", _closestJetCsvV2, &b__closestJetCsvV2);
   fChain->SetBranchAddress("_closestJetDeepCsv_b", _closestJetDeepCsv_b, &b__closestJetDeepCsv_b);
   fChain->SetBranchAddress("_closestJetDeepCsv_bb", _closestJetDeepCsv_bb, &b__closestJetDeepCsv_bb);
   fChain->SetBranchAddress("_selectedTrackMult", _selectedTrackMult, &b__selectedTrackMult);
   fChain->SetBranchAddress("_lMuonSegComp", _lMuonSegComp, &b__lMuonSegComp);
   fChain->SetBranchAddress("_lMuonTrackPt", _lMuonTrackPt, &b__lMuonTrackPt);
   fChain->SetBranchAddress("_lMuonTrackPtErr", _lMuonTrackPtErr, &b__lMuonTrackPtErr);
   fChain->SetBranchAddress("_lIsPrompt", _lIsPrompt, &b__lIsPrompt);
   fChain->SetBranchAddress("_lMatchPdgId", _lMatchPdgId, &b__lMatchPdgId);
   fChain->SetBranchAddress("_lMomPdgId", _lMomPdgId, &b__lMomPdgId);
   fChain->SetBranchAddress("_lProvenance", _lProvenance, &b__lProvenance);
   fChain->SetBranchAddress("_lProvenanceCompressed", _lProvenanceCompressed, &b__lProvenanceCompressed);
   fChain->SetBranchAddress("_lProvenanceConversion", _lProvenanceConversion, &b__lProvenanceConversion);
   fChain->SetBranchAddress("_nPh", &_nPh, &b__nPh);
   fChain->SetBranchAddress("_phPt", _phPt, &b__phPt);
   fChain->SetBranchAddress("_phEta", _phEta, &b__phEta);
   fChain->SetBranchAddress("_phEtaSC", _phEtaSC, &b__phEtaSC);
   fChain->SetBranchAddress("_phPhi", _phPhi, &b__phPhi);
   fChain->SetBranchAddress("_phE", _phE, &b__phE);
   fChain->SetBranchAddress("_phCutBasedLoose", _phCutBasedLoose, &b__phCutBasedLoose);
   fChain->SetBranchAddress("_phCutBasedMedium", _phCutBasedMedium, &b__phCutBasedMedium);
   fChain->SetBranchAddress("_phCutBasedTight", _phCutBasedTight, &b__phCutBasedTight);
   fChain->SetBranchAddress("_phMva", _phMva, &b__phMva);
   fChain->SetBranchAddress("_phRandomConeChargedIsolation", _phRandomConeChargedIsolation, &b__phRandomConeChargedIsolation);
   fChain->SetBranchAddress("_phChargedIsolation", _phChargedIsolation, &b__phChargedIsolation);
   fChain->SetBranchAddress("_phNeutralHadronIsolation", _phNeutralHadronIsolation, &b__phNeutralHadronIsolation);
   fChain->SetBranchAddress("_phPhotonIsolation", _phPhotonIsolation, &b__phPhotonIsolation);
   fChain->SetBranchAddress("_phSigmaIetaIeta", _phSigmaIetaIeta, &b__phSigmaIetaIeta);
   fChain->SetBranchAddress("_phSigmaIetaIphi", _phSigmaIetaIphi, &b__phSigmaIetaIphi);
   fChain->SetBranchAddress("_phHadronicOverEm", _phHadronicOverEm, &b__phHadronicOverEm);
   fChain->SetBranchAddress("_phPassElectronVeto", _phPassElectronVeto, &b__phPassElectronVeto);
   fChain->SetBranchAddress("_phHasPixelSeed", _phHasPixelSeed, &b__phHasPixelSeed);
   fChain->SetBranchAddress("_phIsPrompt", _phIsPrompt, &b__phIsPrompt);
   fChain->SetBranchAddress("_phMatchMCPhotonAN15165", _phMatchMCPhotonAN15165, &b__phMatchMCPhotonAN15165);
   fChain->SetBranchAddress("_phMatchMCLeptonAN15165", _phMatchMCLeptonAN15165, &b__phMatchMCLeptonAN15165);
   fChain->SetBranchAddress("_phTTGMatchCategory", _phTTGMatchCategory, &b__phTTGMatchCategory);
   fChain->SetBranchAddress("_phTTGMatchPt", _phTTGMatchPt, &b__phTTGMatchPt);
   fChain->SetBranchAddress("_phTTGMatchEta", _phTTGMatchEta, &b__phTTGMatchEta);
   fChain->SetBranchAddress("_phMatchPdgId", _phMatchPdgId, &b__phMatchPdgId);
   fChain->SetBranchAddress("_nJets", &_nJets, &b__nJets);
   fChain->SetBranchAddress("_jetPt", _jetPt, &b__jetPt);
   fChain->SetBranchAddress("_jetPt_JECDown", _jetPt_JECDown, &b__jetPt_JECDown);
   fChain->SetBranchAddress("_jetPt_JECUp", _jetPt_JECUp, &b__jetPt_JECUp);
   fChain->SetBranchAddress("_jetSmearedPt", _jetSmearedPt, &b__jetSmearedPt);
   fChain->SetBranchAddress("_jetSmearedPt_JECDown", _jetSmearedPt_JECDown, &b__jetSmearedPt_JECDown);
   fChain->SetBranchAddress("_jetSmearedPt_JECUp", _jetSmearedPt_JECUp, &b__jetSmearedPt_JECUp);
   fChain->SetBranchAddress("_jetSmearedPt_JERDown", _jetSmearedPt_JERDown, &b__jetSmearedPt_JERDown);
   fChain->SetBranchAddress("_jetSmearedPt_JERUp", _jetSmearedPt_JERUp, &b__jetSmearedPt_JERUp);
   fChain->SetBranchAddress("_jetPt_Uncorrected", _jetPt_Uncorrected, &b__jetPt_Uncorrected);
   fChain->SetBranchAddress("_jetPt_L1", _jetPt_L1, &b__jetPt_L1);
   fChain->SetBranchAddress("_jetPt_L2", _jetPt_L2, &b__jetPt_L2);
   fChain->SetBranchAddress("_jetPt_L3", _jetPt_L3, &b__jetPt_L3);
   fChain->SetBranchAddress("_jetEta", _jetEta, &b__jetEta);
   fChain->SetBranchAddress("_jetPhi", _jetPhi, &b__jetPhi);
   fChain->SetBranchAddress("_jetE", _jetE, &b__jetE);
   fChain->SetBranchAddress("_jetCsvV2", _jetCsvV2, &b__jetCsvV2);
   fChain->SetBranchAddress("_jetDeepCsv_udsg", _jetDeepCsv_udsg, &b__jetDeepCsv_udsg);
   fChain->SetBranchAddress("_jetDeepCsv_b", _jetDeepCsv_b, &b__jetDeepCsv_b);
   fChain->SetBranchAddress("_jetDeepCsv_c", _jetDeepCsv_c, &b__jetDeepCsv_c);
   fChain->SetBranchAddress("_jetDeepCsv_bb", _jetDeepCsv_bb, &b__jetDeepCsv_bb);
   fChain->SetBranchAddress("_jetHadronFlavor", _jetHadronFlavor, &b__jetHadronFlavor);
   fChain->SetBranchAddress("_jetIsLoose", _jetIsLoose, &b__jetIsLoose);
   fChain->SetBranchAddress("_jetIsTight", _jetIsTight, &b__jetIsTight);
   fChain->SetBranchAddress("_jetIsTightLepVeto", _jetIsTightLepVeto, &b__jetIsTightLepVeto);
   fChain->SetBranchAddress("_jetNeutralHadronFraction", _jetNeutralHadronFraction, &b__jetNeutralHadronFraction);
   fChain->SetBranchAddress("_jetChargedHadronFraction", _jetChargedHadronFraction, &b__jetChargedHadronFraction);
   fChain->SetBranchAddress("_jetNeutralEmFraction", _jetNeutralEmFraction, &b__jetNeutralEmFraction);
   fChain->SetBranchAddress("_jetChargedEmFraction", _jetChargedEmFraction, &b__jetChargedEmFraction);
   fChain->SetBranchAddress("_jetHFHadronFraction", _jetHFHadronFraction, &b__jetHFHadronFraction);
   fChain->SetBranchAddress("_jetHFEmFraction", _jetHFEmFraction, &b__jetHFEmFraction);
   fChain->SetBranchAddress("_met", &_met, &b__met);
   fChain->SetBranchAddress("_metRaw", &_metRaw, &b__metRaw);
   fChain->SetBranchAddress("_metJECDown", &_metJECDown, &b__metJECDown);
   fChain->SetBranchAddress("_metJECUp", &_metJECUp, &b__metJECUp);
   fChain->SetBranchAddress("_metUnclDown", &_metUnclDown, &b__metUnclDown);
   fChain->SetBranchAddress("_metUnclUp", &_metUnclUp, &b__metUnclUp);
   fChain->SetBranchAddress("_metPhi", &_metPhi, &b__metPhi);
   fChain->SetBranchAddress("_metRawPhi", &_metRawPhi, &b__metRawPhi);
   fChain->SetBranchAddress("_metPhiJECDown", &_metPhiJECDown, &b__metPhiJECDown);
   fChain->SetBranchAddress("_metPhiJECUp", &_metPhiJECUp, &b__metPhiJECUp);
   fChain->SetBranchAddress("_metPhiUnclDown", &_metPhiUnclDown, &b__metPhiUnclDown);
   fChain->SetBranchAddress("_metPhiUnclUp", &_metPhiUnclUp, &b__metPhiUnclUp);
   fChain->SetBranchAddress("_metSignificance", &_metSignificance, &b__metSignificance);
   Notify();
}

Bool_t WzTo3LNuTreeBranches::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void WzTo3LNuTreeBranches::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t WzTo3LNuTreeBranches::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef WzTo3LNuTreeBranches_cxx
