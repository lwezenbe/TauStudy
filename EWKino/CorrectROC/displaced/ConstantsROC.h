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
   UInt_t          _ttgEventType;
   UInt_t          _zgEventType;
   Double_t        _gen_met;
   Double_t        _gen_metPhi;
   UInt_t          _gen_nPh;
   UInt_t          _gen_phStatus[10];   //[_gen_nPh]
   Double_t        _gen_phPt[10];   //[_gen_nPh]
   Double_t        _gen_phEta[10];   //[_gen_nPh]
   Double_t        _gen_phPhi[10];   //[_gen_nPh]
   Double_t        _gen_phE[10];   //[_gen_nPh]
   Int_t           _gen_phMomPdg[10];   //[_gen_nPh]
   Bool_t          _gen_phIsPrompt[10];   //[_gen_nPh]
   Double_t        _gen_phMinDeltaR[10];   //[_gen_nPh]
   Bool_t          _gen_phPassParentage[10];   //[_gen_nPh]
   UInt_t          _gen_nL;
   Double_t        _gen_pdgID[50];   //[_gen_nL]
   Double_t        _gen_lPt[50];   //[_gen_nL]
   Double_t        _gen_lEta[50];   //[_gen_nL]
   Double_t        _gen_lPhi[50];   //[_gen_nL]
   Double_t        _gen_lE[50];   //[_gen_nL]
   UInt_t          _gen_lFlavor[50];   //[_gen_nL]
   Int_t           _gen_lCharge[50];   //[_gen_nL]
   Int_t           _gen_lMomPdg[50];   //[_gen_nL]
   Double_t        _gen_vertex_x[50];   //[_gen_nL]
   Double_t        _gen_vertex_y[50];   //[_gen_nL]
   Double_t        _gen_vertex_z[50];   //[_gen_nL]
   Bool_t          _gen_lIsPrompt[50];   //[_gen_nL]
   Double_t        _gen_lMinDeltaR[50];   //[_gen_nL]
   Bool_t          _gen_lPassParentage[50];   //[_gen_nL]
   Double_t        _gen_HT;
   UInt_t          _nL;
   Double_t        _pvX;
   Double_t        _pvY;
   Double_t        _pvZ;
   Double_t        _pvXErr;
   Double_t        _pvYErr;
   Double_t        _pvZErr;
   UInt_t          _nMu;
   UInt_t          _nEle;
   UInt_t          _nLight;
   UInt_t          _nTau;
   UInt_t          _nVFit;
   UInt_t          _nGoodLeading;
   UInt_t          _nGoodDisplaced;
   UInt_t          _lIndex[13];   //[_nL]
   Double_t        _vertices[1][12];   //[_nVFit]
   Double_t        _lDisplaced[1][24];   //[_nVFit]
   UInt_t          _lHasTrigger[13];   //[_nL]
   Double_t        _lPt[13];   //[_nL]
   Double_t        _lEta[13];   //[_nL]
   Double_t        _lEtaSC[8];   //[_nLight]
   Double_t        _lPhi[13];   //[_nL]
   Double_t        _lE[13];   //[_nL]
   UInt_t          _lFlavor[13];   //[_nL]
   Int_t           _lCharge[13];   //[_nL]
   Double_t        _dxy[13];   //[_nL]
   Double_t        _dz[13];   //[_nL]
   Double_t        _3dIP[13];   //[_nL]
   Double_t        _3dIPSig[13];   //[_nL]
   Double_t        _2dIP[13];   //[_nL]
   Double_t        _2dIPSig[13];   //[_nL]
   Int_t           _lSimType[13];   //[_nL]
   Int_t           _lSimExtType[13];   //[_nL]
   Int_t           _lSimFlavour[13];   //[_nL]
   Float_t         _lElectronMva[8];   //[_nLight]
   Bool_t          _lElectronPassEmu[8];   //[_nLight]
   Bool_t          _lLooseCBwoIsolationwoMissingInnerhitswoConversionVeto[13];   //[_nL]
   Bool_t          _lPOGVeto[13];   //[_nL]
   Bool_t          _lPOGLoose[13];   //[_nL]
   Bool_t          _lPOGMedium[13];   //[_nL]
   Bool_t          _lPOGTight[13];   //[_nL]
   Bool_t          _lpassConversionVeto[13];   //[_nL]
   Double_t        _eleNumberInnerHitsMissing[13];   //[_nL]
   Bool_t          _lGlobalMuon[13];   //[_nL]
   Bool_t          _lTrackerMuon[13];   //[_nL]
   Double_t        _lInnerTrackValidFraction[13];   //[_nL]
   Double_t        _lGlobalTrackNormalizeChi2[13];   //[_nL]
   Double_t        _lCQChi2Position[13];   //[_nL]
   Double_t        _lCQTrackKink[13];   //[_nL]
   Double_t        _muonSegComp[6];   //[_nMu]
   UInt_t          _lNumberOfMatchedStation[13];   //[_nL]
   UInt_t          _lNumberOfValidPixelHits[13];   //[_nL]
   UInt_t          _muNumberInnerHits[13];   //[_nL]
   UInt_t          _lTrackerLayersWithMeasurement[13];   //[_nL]
   Int_t           _muDTStationsWithValidHits[13];   //[_nL]
   Int_t           _muCSCStationsWithValidHits[13];   //[_nL]
   Int_t           _muRPCStationsWithValidHits[13];   //[_nL]
   Int_t           _muMuonStationsWithValidHits[13];   //[_nL]
   Double_t        _lMuTime[13];   //[_nL]
   Double_t        _lMuTimeErr[13];   //[_nL]
   Double_t        _lMuRPCTime[13];   //[_nL]
   Double_t        _lMuRPCTimeErr[13];   //[_nL]
   Int_t           _lMuTimenDof[13];   //[_nL]
   Int_t           _lMuRPCTimenDof[13];   //[_nL]
   Bool_t          _lEleIsEB[13];   //[_nL]
   Bool_t          _lEleIsEE[13];   //[_nL]
   Double_t        _lEleSuperClusterOverP[13];   //[_nL]
   Double_t        _lEleEcalEnergy[13];   //[_nL]
   Double_t        _lElefull5x5SigmaIetaIeta[13];   //[_nL]
   Double_t        _lEleDEtaInSeed[13];   //[_nL]
   Double_t        _lEleDeltaPhiSuperClusterTrackAtVtx[13];   //[_nL]
   Double_t        _lElehadronicOverEm[13];   //[_nL]
   Double_t        _lEleInvMinusPInv[13];   //[_nL]
   Double_t        _relIso[8];   //[_nLight]
   Double_t        _puCorr[13];   //[_nL]
   Double_t        _absIso03[13];   //[_nL]
   Double_t        _absIso04[13];   //[_nL]
   Double_t        _sumNeutralHadronEt04[13];   //[_nL]
   Double_t        _sumChargedHadronPt04[13];   //[_nL]
   Double_t        _sumPhotonEt04[13];   //[_nL]
   Double_t        _sumNeutralHadronEt03[13];   //[_nL]
   Double_t        _sumChargedHadronPt03[13];   //[_nL]
   Double_t        _sumPhotonEt03[13];   //[_nL]
   Double_t        _trackIso[13];   //[_nL]
   Double_t        _ecalIso[13];   //[_nL]
   Double_t        _hcalIso[13];   //[_nL]
   Double_t        _deltaBIso[13];   //[_nL]
   Double_t        _ecalPFClusterIso[13];   //[_nL]
   Double_t        _hcalPFClusterIso[13];   //[_nL]
   Double_t        _ptRel[8];   //[_nLight]
   Double_t        _ptRatio[8];   //[_nLight]
   UInt_t          _selectedTrackMult[8];   //[_nLight]
   Bool_t          _tauMuonVeto[13];   //[_nL]
   Bool_t          _tauEleVeto[13];   //[_nL]
   Bool_t          _decayModeFindingNew[13];   //[_nL]
   Bool_t          _tauVLooseMvaNew[13];   //[_nL]
   Bool_t          _tauLooseMvaNew[13];   //[_nL]
   Bool_t          _tauMediumMvaNew[13];   //[_nL]
   Bool_t          _tauTightMvaNew[13];   //[_nL]
   Bool_t          _tauVTightMvaNew[13];   //[_nL]
   Bool_t          _tauVTightMvaOld[13];   //[_nL]
   Double_t        _closestJetCsvV2[8];   //[_nLight]
   Double_t        _closestJetDeepCsv_b[8];   //[_nLight]
   Double_t        _closestJetDeepCsv_bb[8];   //[_nLight]
   UInt_t          _lGenIndex[13];   //[_nL]
   UInt_t          _lMatchType[13];   //[_nL]
   Bool_t          _lIsPrompt[13];   //[_nL]
   Bool_t          _lIsPromptFinalState[13];   //[_nL]
   Bool_t          _lIsPromptDecayed[13];   //[_nL]
   Int_t           _lMatchPdgId[13];   //[_nL]
   UInt_t          _lProvenance[13];   //[_nL]
   UInt_t          _lProvenanceCompressed[13];   //[_nL]
   Double_t        _lMatchPt[13];   //[_nL]
   Double_t        _lMatchEta[13];   //[_nL]
   Double_t        _lMatchPhi[13];   //[_nL]
   Double_t        _lMatchVertexX[13];   //[_nL]
   Double_t        _lMatchVertexY[13];   //[_nL]
   Double_t        _lMatchVertexZ[13];   //[_nL]
   UInt_t          _nPh;
   Double_t        _phPt[12];   //[_nPh]
   Double_t        _phEta[12];   //[_nPh]
   Double_t        _phEtaSC[12];   //[_nPh]
   Double_t        _phPhi[12];   //[_nPh]
   Double_t        _phE[12];   //[_nPh]
   Bool_t          _phCutBasedLoose[12];   //[_nPh]
   Bool_t          _phCutBasedMedium[12];   //[_nPh]
   Bool_t          _phCutBasedTight[12];   //[_nPh]
   Double_t        _phMva[12];   //[_nPh]
   Double_t        _phRandomConeChargedIsolation[12];   //[_nPh]
   Double_t        _phChargedIsolation[12];   //[_nPh]
   Double_t        _phNeutralHadronIsolation[12];   //[_nPh]
   Double_t        _phPhotonIsolation[12];   //[_nPh]
   Double_t        _phSigmaIetaIeta[12];   //[_nPh]
   Double_t        _phSigmaIetaIphi[12];   //[_nPh]
   Double_t        _phHadronicOverEm[12];   //[_nPh]
   Bool_t          _phPassElectronVeto[12];   //[_nPh]
   Bool_t          _phHasPixelSeed[12];   //[_nPh]
   Bool_t          _phIsPrompt[12];   //[_nPh]
   Int_t           _phMatchMCPhotonAN15165[12];   //[_nPh]
   Int_t           _phMatchMCLeptonAN15165[12];   //[_nPh]
   Int_t           _phTTGMatchCategory[12];   //[_nPh]
   Double_t        _phTTGMatchPt[12];   //[_nPh]
   Double_t        _phTTGMatchEta[12];   //[_nPh]
   Int_t           _phMatchPdgId[12];   //[_nPh]
   UInt_t          _nJets;
   Double_t        _jetPt[20];   //[_nJets]
   Double_t        _jetPt_JECUp[20];   //[_nJets]
   Double_t        _jetPt_JECDown[20];   //[_nJets]
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
   TBranch        *b__gen_pdgID;   //!
   TBranch        *b__gen_lPt;   //!
   TBranch        *b__gen_lEta;   //!
   TBranch        *b__gen_lPhi;   //!
   TBranch        *b__gen_lE;   //!
   TBranch        *b__gen_lFlavor;   //!
   TBranch        *b__gen_lCharge;   //!
   TBranch        *b__gen_lMomPdg;   //!
   TBranch        *b__gen_vertex_x;   //!
   TBranch        *b__gen_vertex_y;   //!
   TBranch        *b__gen_vertex_z;   //!
   TBranch        *b__gen_lIsPrompt;   //!
   TBranch        *b__gen_lMinDeltaR;   //!
   TBranch        *b__gen_lPassParentage;   //!
   TBranch        *b__gen_HT;   //!
   TBranch        *b__nL;   //!
   TBranch        *b__pvX;   //!
   TBranch        *b__pvY;   //!
   TBranch        *b__pvZ;   //!
   TBranch        *b__pvXErr;   //!
   TBranch        *b__pvYErr;   //!
   TBranch        *b__pvZErr;   //!
   TBranch        *b__nMu;   //!
   TBranch        *b__nEle;   //!
   TBranch        *b__nLight;   //!
   TBranch        *b__nTau;   //!
   TBranch        *b__nVFit;   //!
   TBranch        *b__nGoodLeading;   //!
   TBranch        *b__nGoodDisplaced;   //!
   TBranch        *b__lIndex;   //!
   TBranch        *b__vertices;   //!
   TBranch        *b__lDisplaced;   //!
   TBranch        *b__lHasTrigger;   //!
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
   TBranch        *b__2dIP;   //!
   TBranch        *b__2dIPSig;   //!
   TBranch        *b__lSimType;   //!
   TBranch        *b__lSimExtType;   //!
   TBranch        *b__lSimFlavour;   //!
   TBranch        *b__lElectronMva;   //!
   TBranch        *b__lElectronPassEmu;   //!
   TBranch        *b__lLooseCBwoIsolationwoMissingInnerhitswoConversionVeto;   //!
   TBranch        *b__lPOGVeto;   //!
   TBranch        *b__lPOGLoose;   //!
   TBranch        *b__lPOGMedium;   //!
   TBranch        *b__lPOGTight;   //!
   TBranch        *b__lpassConversionVeto;   //!
   TBranch        *b__eleNumberInnerHitsMissing;   //!
   TBranch        *b__lGlobalMuon;   //!
   TBranch        *b__lTrackerMuon;   //!
   TBranch        *b__lInnerTrackValidFraction;   //!
   TBranch        *b__lGlobalTrackNormalizeChi2;   //!
   TBranch        *b__lCQChi2Position;   //!
   TBranch        *b__lCQTrackKink;   //!
   TBranch        *b__muonSegComp;   //!
   TBranch        *b__lNumberOfMatchedStation;   //!
   TBranch        *b__lNumberOfValidPixelHits;   //!
   TBranch        *b__muNumberInnerHits;   //!
   TBranch        *b__lTrackerLayersWithMeasurement;   //!
   TBranch        *b__muDTStationsWithValidHits;   //!
   TBranch        *b__muCSCStationsWithValidHits;   //!
   TBranch        *b__muRPCStationsWithValidHits;   //!
   TBranch        *b__muMuonStationsWithValidHits;   //!
   TBranch        *b__lMuTime;   //!
   TBranch        *b__lMuTimeErr;   //!
   TBranch        *b__lMuRPCTime;   //!
   TBranch        *b__lMuRPCTimeErr;   //!
   TBranch        *b__lMuTimenDof;   //!
   TBranch        *b__lMuRPCTimenDof;   //!
   TBranch        *b__lEleIsEB;   //!
   TBranch        *b__lEleIsEE;   //!
   TBranch        *b__lEleSuperClusterOverP;   //!
   TBranch        *b__lEleEcalEnergy;   //!
   TBranch        *b__lElefull5x5SigmaIetaIeta;   //!
   TBranch        *b__lEleDEtaInSeed;   //!
   TBranch        *b__lEleDeltaPhiSuperClusterTrackAtVtx;   //!
   TBranch        *b__lElehadronicOverEm;   //!
   TBranch        *b__lEleInvMinusPInv;   //!
   TBranch        *b__relIso;   //!
   TBranch        *b__puCorr;   //!
   TBranch        *b__absIso03;   //!
   TBranch        *b__absIso04;   //!
   TBranch        *b__sumNeutralHadronEt04;   //!
   TBranch        *b__sumChargedHadronPt04;   //!
   TBranch        *b__sumPhotonEt04;   //!
   TBranch        *b__sumNeutralHadronEt03;   //!
   TBranch        *b__sumChargedHadronPt03;   //!
   TBranch        *b__sumPhotonEt03;   //!
   TBranch        *b__trackIso;   //!
   TBranch        *b__ecalIso;   //!
   TBranch        *b__hcalIso;   //!
   TBranch        *b__deltaBIso;   //!
   TBranch        *b__ecalPFClusterIso;   //!
   TBranch        *b__hcalPFClusterIso;   //!
   TBranch        *b__ptRel;   //!
   TBranch        *b__ptRatio;   //!
   TBranch        *b__selectedTrackMult;   //!
   TBranch        *b__tauMuonVeto;   //!
   TBranch        *b__tauEleVeto;   //!
   TBranch        *b__decayModeFindingNew;   //!
   TBranch        *b__tauVLooseMvaNew;   //!
   TBranch        *b__tauLooseMvaNew;   //!
   TBranch        *b__tauMediumMvaNew;   //!
   TBranch        *b__tauTightMvaNew;   //!
   TBranch        *b__tauVTightMvaNew;   //!
   TBranch        *b__tauVTightMvaOld;   //!
   TBranch        *b__closestJetCsvV2;   //!
   TBranch        *b__closestJetDeepCsv_b;   //!
   TBranch        *b__closestJetDeepCsv_bb;   //!
   TBranch        *b__lGenIndex;   //!
   TBranch        *b__lMatchType;   //!
   TBranch        *b__lIsPrompt;   //!
   TBranch        *b__lIsPromptFinalState;   //!
   TBranch        *b__lIsPromptDecayed;   //!
   TBranch        *b__lMatchPdgId;   //!
   TBranch        *b__lProvenance;   //!
   TBranch        *b__lProvenanceCompressed;   //!
   TBranch        *b__lMatchPt;   //!
   TBranch        *b__lMatchEta;   //!
   TBranch        *b__lMatchPhi;   //!
   TBranch        *b__lMatchVertexX;   //!
   TBranch        *b__lMatchVertexY;   //!
   TBranch        *b__lMatchVertexZ;   //!
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
   TBranch        *b__jetPt_JECUp;   //!
   TBranch        *b__jetPt_JECDown;   //!
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
   
TTree * Tree;

TString FileName;
Double_t    nPromptTaus[NumberOfSamples] = {0};
