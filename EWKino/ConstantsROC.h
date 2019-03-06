const int       NumberOfDiscr = 3;              //Define constants
const int       NumberOfWP = 5;
const int       NumberOfFracComp = 2;
const int       NumberOfSamples = 2;
const int	    NumberOfLeptonDiscr = 3;

const int       MVA_Old = 0;
const int       MVA_New = 1;
const int       Cut_based = 2;

const int       VLoose_MVA = 0;                  //Old Discriminators
const int       Loose_MVA = 1;
const int       Medium_MVA = 2;
const int       Tight_MVA = 3;
const int       VTight_MVA = 4;

const int       VVLoose_Cut = 0;
const int       VLoose_Cut = 1;
const int       Loose_Cut = 2;
const int       Medium_Cut = 3;
const int       Tight_Cut = 4;

const int       Background = 1;
const int       Signal = 0;

const int	    EleDiscr = 0;
const int	    MuDiscr = 1;
const int	    BothLepDiscr = 2;

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
   Bool_t          _Flag_BadPFMuonFilter;
   Bool_t          _Flag_BadChargedCandidateFilter;
   Bool_t          _Flag_globalTightHalo2016Filter;
   Bool_t          _passTrigger_e;
   Bool_t          _HLT_Ele27_WPTight_Gsf;
   Int_t           _HLT_Ele27_WPTight_Gsf_prescale;
   Bool_t          _HLT_Ele105_CaloIdVT_GsfTrkIdT;
   Int_t           _HLT_Ele105_CaloIdVT_GsfTrkIdT_prescale;
   Bool_t          _HLT_Ele115_CaloIdVT_GsfTrkIdT;
   Int_t           _HLT_Ele115_CaloIdVT_GsfTrkIdT_prescale;
   Bool_t          _HLT_IsoMu24;
   Int_t           _HLT_IsoMu24_prescale;
   Bool_t          _HLT_IsoTkMu24;
   Int_t           _HLT_IsoTkMu24_prescale;
   Bool_t          _HLT_IsoMu22;
   Int_t           _HLT_IsoMu22_prescale;
   Bool_t          _HLT_IsoTkMu22;
   Int_t           _HLT_IsoTkMu22_prescale;
   Bool_t          _passTrigger_ee;
   Bool_t          _HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           _HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
   Bool_t          _HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           _HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
   Bool_t          _HLT_DoubleEle33_CaloIdL_GsfTrkIdVL;
   Int_t           _HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale;
   Bool_t          _passTrigger_eee;
   Bool_t          _HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
   Int_t           _HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale;
   Bool_t          _passTrigger_eem;
   Bool_t          _HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
   Int_t           _HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale;
   Bool_t          _passTrigger_em;
   Bool_t          _HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL;
   Int_t           _HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_prescale;
   Bool_t          _HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           _HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
   Bool_t          _HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Int_t           _HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_prescale;
   Bool_t          _HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ;
   Int_t           _HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_prescale;
   Bool_t          _HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL;
   Int_t           _HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_prescale;
   Bool_t          _passTrigger_emm;
   Bool_t          _HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
   Int_t           _HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale;
   Bool_t          _passTrigger_et;
   Bool_t          _HLT_Ele22_eta2p1_WPLoose_GSF_LooseIsoPFtau20_SingleL1;
   Int_t           _HLT_Ele22_eta2p1_WPLoose_GSF_LooseIsoPFtau20_SingleL1_prescale;
   Bool_t          _HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30;
   Int_t           _HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_prescale;
   Bool_t          _HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1;
   Int_t           _HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_prescale;
   Bool_t          _HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20;
   Int_t           _HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_prescale;
   Bool_t          _passTrigger_m;
   Bool_t          _HLT_Mu50;
   Int_t           _HLT_Mu50_prescale;
   Bool_t          _HLT_TkMu50;
   Int_t           _HLT_TkMu50_prescale;
   Bool_t          _HLT_Mu45_eta2p1;
   Int_t           _HLT_Mu45_eta2p1_prescale;
   Bool_t          _passTrigger_mm;
   Bool_t          _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
   Int_t           _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale;
   Bool_t          _HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;
   Int_t           _HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale;
   Bool_t          _HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;
   Int_t           _HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale;
   Bool_t          _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
   Int_t           _HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale;
   Bool_t          _HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL;
   Int_t           _HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale;
   Bool_t          _HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL;
   Int_t           _HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale;
   Bool_t          _HLT_Mu30_TkMu11;
   Int_t           _HLT_Mu30_TkMu11_prescale;
   Bool_t          _passTrigger_mmm;
   Bool_t          _HLT_TripleMu_12_10_5;
   Int_t           _HLT_TripleMu_12_10_5_prescale;
   Bool_t          _passTrigger_mt;
   Bool_t          _HLT_IsoMu19_eta2p1_LooseIsoPFTau20;
   Int_t           _HLT_IsoMu19_eta2p1_LooseIsoPFTau20_prescale;
   UChar_t         _nL;
   UChar_t         _nMu;
   UChar_t         _nEle;
   UChar_t         _nLight;
   UChar_t         _nTau;
   Double_t        _lPt[8];   //[_nL]
   Double_t        _lEta[8];   //[_nL]
   Double_t        _lEtaSC[8];   //[_nLight]
   Double_t        _lPhi[8];   //[_nL]
   Double_t        _lE[8];   //[_nL]
   UInt_t          _lFlavor[8];   //[_nL]
   Int_t           _lCharge[8];   //[_nL]
   Double_t        _dxy[8];   //[_nL]
   Double_t        _dz[8];   //[_nL]
   Double_t        _3dIP[8];   //[_nL]
   Double_t        _3dIPSig[8];   //[_nL]
   Float_t         _lElectronMva[8];   //[_nLight]
   Float_t         _lElectronMvaHZZ[8];   //[_nLight]
   Float_t         _lElectronMvaFall17Iso[8];   //[_nLight]
   Float_t         _lElectronMvaFall17NoIso[8];   //[_nLight]
   Bool_t          _lElectronPassEmu[8];   //[_nLight]
   Bool_t          _lElectronPassConvVeto[8];   //[_nLight]
   Bool_t          _lElectronChargeConst[8];   //[_nLight]
   UInt_t          _lElectronMissingHits[8];   //[_nLight]
   Double_t        _leptonMvaSUSY16[8];   //[_nLight]
   Double_t        _leptonMvaTTH16[8];   //[_nLight]
   Double_t        _leptonMvaSUSY17[8];   //[_nLight]
   Double_t        _leptonMvaTTH17[8];   //[_nLight]
   Double_t        _leptonMvatZqTTV16[8];   //[_nLight]
   Double_t        _leptonMvatZqTTV17[8];   //[_nLight]
   Bool_t          _lHNLoose[8];   //[_nLight]
   Bool_t          _lHNFO[8];   //[_nLight]
   Bool_t          _lHNTight[8];   //[_nLight]
   Bool_t          _lEwkLoose[8];   //[_nL]
   Bool_t          _lEwkFO[8];   //[_nL]
   Bool_t          _lEwkTight[8];   //[_nL]
   Bool_t          _lPOGVeto[8];   //[_nL]
   Bool_t          _lPOGLoose[8];   //[_nL]
   Bool_t          _lPOGMedium[8];   //[_nL]
   Bool_t          _lPOGTight[8];   //[_nL]
   Bool_t          _lPOGLooseWOIso[8];   //[_nLight]
   Bool_t          _lPOGMediumWOIso[8];   //[_nLight]
   Bool_t          _lPOGTightWOIso[8];   //[_nLight]
   Bool_t          _tauMuonVeto[8];   //[_nL]
   Bool_t          _tauEleVeto[8];   //[_nL]
   Bool_t          _decayModeFindingNew[8];   //[_nL]
   Bool_t          _tauVLooseMvaNew[8];   //[_nL]
   Bool_t          _tauLooseMvaNew[8];   //[_nL]
   Bool_t          _tauMediumMvaNew[8];   //[_nL]
   Bool_t          _tauTightMvaNew[8];   //[_nL]
   Bool_t          _tauVTightMvaNew[8];   //[_nL]
   Bool_t          _tauVTightMvaOld[8];   //[_nL]
   Double_t        _tauAgainstElectronMVA6Raw[8];   //[_nL]
   Double_t        _tauCombinedIsoDBRaw3Hits[8];   //[_nL]
   Double_t        _tauIsoMVAPWdR03oldDMwLT[8];   //[_nL]
   Double_t        _tauIsoMVADBdR03oldDMwLT[8];   //[_nL]
   Double_t        _tauIsoMVADBdR03newDMwLT[8];   //[_nL]
   Double_t        _tauIsoMVAPWnewDMwLT[8];   //[_nL]
   Double_t        _tauIsoMVAPWoldDMwLT[8];   //[_nL]
   Double_t        _relIso[8];   //[_nLight]
   Double_t        _relIso0p4[8];   //[_nLight]
   Double_t        _relIso0p4MuDeltaBeta[6];   //[_nMu]
   Double_t        _miniIso[8];   //[_nLight]
   Double_t        _miniIsoCharged[8];   //[_nLight]
   Double_t        _ptRel[8];   //[_nLight]
   Double_t        _ptRatio[8];   //[_nLight]
   Double_t        _closestJetCsvV2[8];   //[_nLight]
   Double_t        _closestJetDeepCsv_b[8];   //[_nLight]
   Double_t        _closestJetDeepCsv_bb[8];   //[_nLight]
   UInt_t          _selectedTrackMult[8];   //[_nLight]
   Double_t        _lMuonSegComp[6];   //[_nMu]
   Double_t        _lMuonTrackPt[6];   //[_nMu]
   Double_t        _lMuonTrackPtErr[6];   //[_nMu]
   Bool_t          _lIsPrompt[8];   //[_nL]
   Int_t           _lMatchPdgId[8];   //[_nL]
   Int_t           _lMomPdgId[8];   //[_nL]
   UInt_t          _lProvenance[8];   //[_nL]
   UInt_t          _lProvenanceCompressed[8];   //[_nL]
   UInt_t          _lProvenanceConversion[8];   //[_nL]
   UChar_t         _nPh;
   Double_t        _phPt[9];   //[_nPh]
   Double_t        _phEta[9];   //[_nPh]
   Double_t        _phEtaSC[9];   //[_nPh]
   Double_t        _phPhi[9];   //[_nPh]
   Double_t        _phE[9];   //[_nPh]
   Bool_t          _phCutBasedLoose[9];   //[_nPh]
   Bool_t          _phCutBasedMedium[9];   //[_nPh]
   Bool_t          _phCutBasedTight[9];   //[_nPh]
   Double_t        _phMva[9];   //[_nPh]
   Double_t        _phRandomConeChargedIsolation[9];   //[_nPh]
   Double_t        _phChargedIsolation[9];   //[_nPh]
   Double_t        _phNeutralHadronIsolation[9];   //[_nPh]
   Double_t        _phPhotonIsolation[9];   //[_nPh]
   Double_t        _phSigmaIetaIeta[9];   //[_nPh]
   Double_t        _phSigmaIetaIphi[9];   //[_nPh]
   Double_t        _phHadronicOverEm[9];   //[_nPh]
   Bool_t          _phPassElectronVeto[9];   //[_nPh]
   Bool_t          _phHasPixelSeed[9];   //[_nPh]
   Bool_t          _phIsPrompt[9];   //[_nPh]
   Int_t           _phMatchMCPhotonAN15165[9];   //[_nPh]
   Int_t           _phMatchMCLeptonAN15165[9];   //[_nPh]
   Int_t           _phTTGMatchCategory[9];   //[_nPh]
   Double_t        _phTTGMatchPt[9];   //[_nPh]
   Double_t        _phTTGMatchEta[9];   //[_nPh]
   Int_t           _phMatchPdgId[9];   //[_nPh]
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
   Double_t        _mChi1;
   Double_t        _mChi2;

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
   TBranch        *b__Flag_BadPFMuonFilter;   //!
   TBranch        *b__Flag_BadChargedCandidateFilter;   //!
   TBranch        *b__Flag_globalTightHalo2016Filter;   //!
   TBranch        *b__passTrigger_e;   //!
   TBranch        *b__HLT_Ele27_WPTight_Gsf;   //!
   TBranch        *b__HLT_Ele27_WPTight_Gsf_prescale;   //!
   TBranch        *b__HLT_Ele105_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b__HLT_Ele105_CaloIdVT_GsfTrkIdT_prescale;   //!
   TBranch        *b__HLT_Ele115_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b__HLT_Ele115_CaloIdVT_GsfTrkIdT_prescale;   //!
   TBranch        *b__HLT_IsoMu24;   //!
   TBranch        *b__HLT_IsoMu24_prescale;   //!
   TBranch        *b__HLT_IsoTkMu24;   //!
   TBranch        *b__HLT_IsoTkMu24_prescale;   //!
   TBranch        *b__HLT_IsoMu22;   //!
   TBranch        *b__HLT_IsoMu22_prescale;   //!
   TBranch        *b__HLT_IsoTkMu22;   //!
   TBranch        *b__HLT_IsoTkMu22_prescale;   //!
   TBranch        *b__passTrigger_ee;   //!
   TBranch        *b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
   TBranch        *b__HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b__HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
   TBranch        *b__HLT_DoubleEle33_CaloIdL_GsfTrkIdVL;   //!
   TBranch        *b__HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale;   //!
   TBranch        *b__passTrigger_eee;   //!
   TBranch        *b__HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;   //!
   TBranch        *b__HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale;   //!
   TBranch        *b__passTrigger_eem;   //!
   TBranch        *b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL;   //!
   TBranch        *b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale;   //!
   TBranch        *b__passTrigger_em;   //!
   TBranch        *b__HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b__HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_prescale;   //!
   TBranch        *b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
   TBranch        *b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_prescale;   //!
   TBranch        *b__HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b__HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_prescale;   //!
   TBranch        *b__HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL;   //!
   TBranch        *b__HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_prescale;   //!
   TBranch        *b__passTrigger_emm;   //!
   TBranch        *b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL;   //!
   TBranch        *b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale;   //!
   TBranch        *b__passTrigger_et;   //!
   TBranch        *b__HLT_Ele22_eta2p1_WPLoose_GSF_LooseIsoPFtau20_SingleL1;   //!
   TBranch        *b__HLT_Ele22_eta2p1_WPLoose_GSF_LooseIsoPFtau20_SingleL1_prescale;   //!
   TBranch        *b__HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30;   //!
   TBranch        *b__HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_prescale;   //!
   TBranch        *b__HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1;   //!
   TBranch        *b__HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_prescale;   //!
   TBranch        *b__HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20;   //!
   TBranch        *b__HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_prescale;   //!
   TBranch        *b__passTrigger_m;   //!
   TBranch        *b__HLT_Mu50;   //!
   TBranch        *b__HLT_Mu50_prescale;   //!
   TBranch        *b__HLT_TkMu50;   //!
   TBranch        *b__HLT_TkMu50_prescale;   //!
   TBranch        *b__HLT_Mu45_eta2p1;   //!
   TBranch        *b__HLT_Mu45_eta2p1_prescale;   //!
   TBranch        *b__passTrigger_mm;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale;   //!
   TBranch        *b__HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ;   //!
   TBranch        *b__HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL;   //!
   TBranch        *b__HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale;   //!
   TBranch        *b__HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL;   //!
   TBranch        *b__HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale;   //!
   TBranch        *b__HLT_Mu30_TkMu11;   //!
   TBranch        *b__HLT_Mu30_TkMu11_prescale;   //!
   TBranch        *b__passTrigger_mmm;   //!
   TBranch        *b__HLT_TripleMu_12_10_5;   //!
   TBranch        *b__HLT_TripleMu_12_10_5_prescale;   //!
   TBranch        *b__passTrigger_mt;   //!
   TBranch        *b__HLT_IsoMu19_eta2p1_LooseIsoPFTau20;   //!
   TBranch        *b__HLT_IsoMu19_eta2p1_LooseIsoPFTau20_prescale;   //!
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
   TBranch        *b__mChi1;   //!
   TBranch        *b__mChi2;   //!

TTree * Tree;

TString FileName[2];
Double_t m1 = 0;
Double_t m2 = 0;
Bool_t  isSignal = false;
Double_t    nPromptTaus = 0;