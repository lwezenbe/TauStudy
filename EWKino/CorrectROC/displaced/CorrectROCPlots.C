#include "ConstantsROC.h"
#include "/user/lwezenbe/private/PhD/Programs/CMS_lumi/CMS_lumi.C"
#include "/user/lwezenbe/private/PhD/Programs/CMS_lumi/tdrstyle.C"

void SetBranches(TString FileName){
    TFile * inFile = new TFile("/user/lwezenbe/private/PhD/Trees/" + FileName +"_skimmedwcopytree.root", "read");

    inFile->GetObject("blackJackAndHookersTree", Tree);

   Tree->SetBranchAddress("_runNb", &_runNb, &b__runNb);
   Tree->SetBranchAddress("_lumiBlock", &_lumiBlock, &b__lumiBlock);
   Tree->SetBranchAddress("_eventNb", &_eventNb, &b__eventNb);
   Tree->SetBranchAddress("_nVertex", &_nVertex, &b__nVertex);
   Tree->SetBranchAddress("_nTrueInt", &_nTrueInt, &b__nTrueInt);
   Tree->SetBranchAddress("_weight", &_weight, &b__weight);
   Tree->SetBranchAddress("_lheHTIncoming", &_lheHTIncoming, &b__lheHTIncoming);
   Tree->SetBranchAddress("_ctauHN", &_ctauHN, &b__ctauHN);
   Tree->SetBranchAddress("_nLheWeights", &_nLheWeights, &b__nLheWeights);
   Tree->SetBranchAddress("_lheWeight", _lheWeight, &b__lheWeight);
   Tree->SetBranchAddress("_ttgEventType", &_ttgEventType, &b__ttgEventType);
   Tree->SetBranchAddress("_zgEventType", &_zgEventType, &b__zgEventType);
   Tree->SetBranchAddress("_gen_met", &_gen_met, &b__gen_met);
   Tree->SetBranchAddress("_gen_metPhi", &_gen_metPhi, &b__gen_metPhi);
   Tree->SetBranchAddress("_gen_nPh", &_gen_nPh, &b__gen_nPh);
   Tree->SetBranchAddress("_gen_phStatus", _gen_phStatus, &b__gen_phStatus);
   Tree->SetBranchAddress("_gen_phPt", _gen_phPt, &b__gen_phPt);
   Tree->SetBranchAddress("_gen_phEta", _gen_phEta, &b__gen_phEta);
   Tree->SetBranchAddress("_gen_phPhi", _gen_phPhi, &b__gen_phPhi);
   Tree->SetBranchAddress("_gen_phE", _gen_phE, &b__gen_phE);
   Tree->SetBranchAddress("_gen_phMomPdg", _gen_phMomPdg, &b__gen_phMomPdg);
   Tree->SetBranchAddress("_gen_phIsPrompt", _gen_phIsPrompt, &b__gen_phIsPrompt);
   Tree->SetBranchAddress("_gen_phMinDeltaR", _gen_phMinDeltaR, &b__gen_phMinDeltaR);
   Tree->SetBranchAddress("_gen_phPassParentage", _gen_phPassParentage, &b__gen_phPassParentage);
   Tree->SetBranchAddress("_gen_nL", &_gen_nL, &b__gen_nL);
   Tree->SetBranchAddress("_gen_pdgID", _gen_pdgID, &b__gen_pdgID);
   Tree->SetBranchAddress("_gen_lPt", _gen_lPt, &b__gen_lPt);
   Tree->SetBranchAddress("_gen_lEta", _gen_lEta, &b__gen_lEta);
   Tree->SetBranchAddress("_gen_lPhi", _gen_lPhi, &b__gen_lPhi);
   Tree->SetBranchAddress("_gen_lE", _gen_lE, &b__gen_lE);
   Tree->SetBranchAddress("_gen_lFlavor", _gen_lFlavor, &b__gen_lFlavor);
   Tree->SetBranchAddress("_gen_lCharge", _gen_lCharge, &b__gen_lCharge);
   Tree->SetBranchAddress("_gen_lMomPdg", _gen_lMomPdg, &b__gen_lMomPdg);
   Tree->SetBranchAddress("_gen_vertex_x", _gen_vertex_x, &b__gen_vertex_x);
   Tree->SetBranchAddress("_gen_vertex_y", _gen_vertex_y, &b__gen_vertex_y);
   Tree->SetBranchAddress("_gen_vertex_z", _gen_vertex_z, &b__gen_vertex_z);
   Tree->SetBranchAddress("_gen_lIsPrompt", _gen_lIsPrompt, &b__gen_lIsPrompt);
   Tree->SetBranchAddress("_gen_lMinDeltaR", _gen_lMinDeltaR, &b__gen_lMinDeltaR);
   Tree->SetBranchAddress("_gen_lPassParentage", _gen_lPassParentage, &b__gen_lPassParentage);
   Tree->SetBranchAddress("_gen_HT", &_gen_HT, &b__gen_HT);
   Tree->SetBranchAddress("_nL", &_nL, &b__nL);
   Tree->SetBranchAddress("_pvX", &_pvX, &b__pvX);
   Tree->SetBranchAddress("_pvY", &_pvY, &b__pvY);
   Tree->SetBranchAddress("_pvZ", &_pvZ, &b__pvZ);
   Tree->SetBranchAddress("_pvXErr", &_pvXErr, &b__pvXErr);
   Tree->SetBranchAddress("_pvYErr", &_pvYErr, &b__pvYErr);
   Tree->SetBranchAddress("_pvZErr", &_pvZErr, &b__pvZErr);
   Tree->SetBranchAddress("_nMu", &_nMu, &b__nMu);
   Tree->SetBranchAddress("_nEle", &_nEle, &b__nEle);
   Tree->SetBranchAddress("_nLight", &_nLight, &b__nLight);
   Tree->SetBranchAddress("_nTau", &_nTau, &b__nTau);
   Tree->SetBranchAddress("_nVFit", &_nVFit, &b__nVFit);
   Tree->SetBranchAddress("_nGoodLeading", &_nGoodLeading, &b__nGoodLeading);
   Tree->SetBranchAddress("_nGoodDisplaced", &_nGoodDisplaced, &b__nGoodDisplaced);
   Tree->SetBranchAddress("_lIndex", _lIndex, &b__lIndex);
   Tree->SetBranchAddress("_vertices", &_vertices, &b__vertices);
   Tree->SetBranchAddress("_lDisplaced", &_lDisplaced, &b__lDisplaced);
   Tree->SetBranchAddress("_lHasTrigger", _lHasTrigger, &b__lHasTrigger);
   Tree->SetBranchAddress("_lPt", _lPt, &b__lPt);
   Tree->SetBranchAddress("_lEta", _lEta, &b__lEta);
   Tree->SetBranchAddress("_lEtaSC", _lEtaSC, &b__lEtaSC);
   Tree->SetBranchAddress("_lPhi", _lPhi, &b__lPhi);
   Tree->SetBranchAddress("_lE", _lE, &b__lE);
   Tree->SetBranchAddress("_lFlavor", _lFlavor, &b__lFlavor);
   Tree->SetBranchAddress("_lCharge", _lCharge, &b__lCharge);
   Tree->SetBranchAddress("_dxy", _dxy, &b__dxy);
   Tree->SetBranchAddress("_dz", _dz, &b__dz);
   Tree->SetBranchAddress("_3dIP", _3dIP, &b__3dIP);
   Tree->SetBranchAddress("_3dIPSig", _3dIPSig, &b__3dIPSig);
   Tree->SetBranchAddress("_2dIP", _2dIP, &b__2dIP);
   Tree->SetBranchAddress("_2dIPSig", _2dIPSig, &b__2dIPSig);
   Tree->SetBranchAddress("_lSimType", _lSimType, &b__lSimType);
   Tree->SetBranchAddress("_lSimExtType", _lSimExtType, &b__lSimExtType);
   Tree->SetBranchAddress("_lSimFlavour", _lSimFlavour, &b__lSimFlavour);
   Tree->SetBranchAddress("_lElectronMva", _lElectronMva, &b__lElectronMva);
   Tree->SetBranchAddress("_lElectronPassEmu", _lElectronPassEmu, &b__lElectronPassEmu);
   Tree->SetBranchAddress("_lLooseCBwoIsolationwoMissingInnerhitswoConversionVeto", _lLooseCBwoIsolationwoMissingInnerhitswoConversionVeto, &b__lLooseCBwoIsolationwoMissingInnerhitswoConversionVeto);
   Tree->SetBranchAddress("_lPOGVeto", _lPOGVeto, &b__lPOGVeto);
   Tree->SetBranchAddress("_lPOGLoose", _lPOGLoose, &b__lPOGLoose);
   Tree->SetBranchAddress("_lPOGMedium", _lPOGMedium, &b__lPOGMedium);
   Tree->SetBranchAddress("_lPOGTight", _lPOGTight, &b__lPOGTight);
   Tree->SetBranchAddress("_lpassConversionVeto", _lpassConversionVeto, &b__lpassConversionVeto);
   Tree->SetBranchAddress("_eleNumberInnerHitsMissing", _eleNumberInnerHitsMissing, &b__eleNumberInnerHitsMissing);
   Tree->SetBranchAddress("_lGlobalMuon", _lGlobalMuon, &b__lGlobalMuon);
   Tree->SetBranchAddress("_lTrackerMuon", _lTrackerMuon, &b__lTrackerMuon);
   Tree->SetBranchAddress("_lInnerTrackValidFraction", _lInnerTrackValidFraction, &b__lInnerTrackValidFraction);
   Tree->SetBranchAddress("_lGlobalTrackNormalizeChi2", _lGlobalTrackNormalizeChi2, &b__lGlobalTrackNormalizeChi2);
   Tree->SetBranchAddress("_lCQChi2Position", _lCQChi2Position, &b__lCQChi2Position);
   Tree->SetBranchAddress("_lCQTrackKink", _lCQTrackKink, &b__lCQTrackKink);
   Tree->SetBranchAddress("_muonSegComp", _muonSegComp, &b__muonSegComp);
   Tree->SetBranchAddress("_lNumberOfMatchedStation", _lNumberOfMatchedStation, &b__lNumberOfMatchedStation);
   Tree->SetBranchAddress("_lNumberOfValidPixelHits", _lNumberOfValidPixelHits, &b__lNumberOfValidPixelHits);
   Tree->SetBranchAddress("_muNumberInnerHits", _muNumberInnerHits, &b__muNumberInnerHits);
   Tree->SetBranchAddress("_lTrackerLayersWithMeasurement", _lTrackerLayersWithMeasurement, &b__lTrackerLayersWithMeasurement);
   Tree->SetBranchAddress("_muDTStationsWithValidHits", _muDTStationsWithValidHits, &b__muDTStationsWithValidHits);
   Tree->SetBranchAddress("_muCSCStationsWithValidHits", _muCSCStationsWithValidHits, &b__muCSCStationsWithValidHits);
   Tree->SetBranchAddress("_muRPCStationsWithValidHits", _muRPCStationsWithValidHits, &b__muRPCStationsWithValidHits);
   Tree->SetBranchAddress("_muMuonStationsWithValidHits", _muMuonStationsWithValidHits, &b__muMuonStationsWithValidHits);
   Tree->SetBranchAddress("_lMuTime", _lMuTime, &b__lMuTime);
   Tree->SetBranchAddress("_lMuTimeErr", _lMuTimeErr, &b__lMuTimeErr);
   Tree->SetBranchAddress("_lMuRPCTime", _lMuRPCTime, &b__lMuRPCTime);
   Tree->SetBranchAddress("_lMuRPCTimeErr", _lMuRPCTimeErr, &b__lMuRPCTimeErr);
   Tree->SetBranchAddress("_lMuTimenDof", _lMuTimenDof, &b__lMuTimenDof);
   Tree->SetBranchAddress("_lMuRPCTimenDof", _lMuRPCTimenDof, &b__lMuRPCTimenDof);
   Tree->SetBranchAddress("_lEleIsEB", _lEleIsEB, &b__lEleIsEB);
   Tree->SetBranchAddress("_lEleIsEE", _lEleIsEE, &b__lEleIsEE);
   Tree->SetBranchAddress("_lEleSuperClusterOverP", _lEleSuperClusterOverP, &b__lEleSuperClusterOverP);
   Tree->SetBranchAddress("_lEleEcalEnergy", _lEleEcalEnergy, &b__lEleEcalEnergy);
   Tree->SetBranchAddress("_lElefull5x5SigmaIetaIeta", _lElefull5x5SigmaIetaIeta, &b__lElefull5x5SigmaIetaIeta);
   Tree->SetBranchAddress("_lEleDEtaInSeed", _lEleDEtaInSeed, &b__lEleDEtaInSeed);
   Tree->SetBranchAddress("_lEleDeltaPhiSuperClusterTrackAtVtx", _lEleDeltaPhiSuperClusterTrackAtVtx, &b__lEleDeltaPhiSuperClusterTrackAtVtx);
   Tree->SetBranchAddress("_lElehadronicOverEm", _lElehadronicOverEm, &b__lElehadronicOverEm);
   Tree->SetBranchAddress("_lEleInvMinusPInv", _lEleInvMinusPInv, &b__lEleInvMinusPInv);
   Tree->SetBranchAddress("_relIso", _relIso, &b__relIso);
   Tree->SetBranchAddress("_puCorr", _puCorr, &b__puCorr);
   Tree->SetBranchAddress("_absIso03", _absIso03, &b__absIso03);
   Tree->SetBranchAddress("_absIso04", _absIso04, &b__absIso04);
   Tree->SetBranchAddress("_sumNeutralHadronEt04", _sumNeutralHadronEt04, &b__sumNeutralHadronEt04);
   Tree->SetBranchAddress("_sumChargedHadronPt04", _sumChargedHadronPt04, &b__sumChargedHadronPt04);
   Tree->SetBranchAddress("_sumPhotonEt04", _sumPhotonEt04, &b__sumPhotonEt04);
   Tree->SetBranchAddress("_sumNeutralHadronEt03", _sumNeutralHadronEt03, &b__sumNeutralHadronEt03);
   Tree->SetBranchAddress("_sumChargedHadronPt03", _sumChargedHadronPt03, &b__sumChargedHadronPt03);
   Tree->SetBranchAddress("_sumPhotonEt03", _sumPhotonEt03, &b__sumPhotonEt03);
   Tree->SetBranchAddress("_trackIso", _trackIso, &b__trackIso);
   Tree->SetBranchAddress("_ecalIso", _ecalIso, &b__ecalIso);
   Tree->SetBranchAddress("_hcalIso", _hcalIso, &b__hcalIso);
   Tree->SetBranchAddress("_deltaBIso", _deltaBIso, &b__deltaBIso);
   Tree->SetBranchAddress("_ecalPFClusterIso", _ecalPFClusterIso, &b__ecalPFClusterIso);
   Tree->SetBranchAddress("_hcalPFClusterIso", _hcalPFClusterIso, &b__hcalPFClusterIso);
   Tree->SetBranchAddress("_ptRel", _ptRel, &b__ptRel);
   Tree->SetBranchAddress("_ptRatio", _ptRatio, &b__ptRatio);
   Tree->SetBranchAddress("_selectedTrackMult", _selectedTrackMult, &b__selectedTrackMult);
   Tree->SetBranchAddress("_tauMuonVeto", _tauMuonVeto, &b__tauMuonVeto);
   Tree->SetBranchAddress("_tauEleVeto", _tauEleVeto, &b__tauEleVeto);
   Tree->SetBranchAddress("_decayModeFindingNew", _decayModeFindingNew, &b__decayModeFindingNew);
   Tree->SetBranchAddress("_tauVLooseMvaNew", _tauVLooseMvaNew, &b__tauVLooseMvaNew);
   Tree->SetBranchAddress("_tauLooseMvaNew", _tauLooseMvaNew, &b__tauLooseMvaNew);
   Tree->SetBranchAddress("_tauMediumMvaNew", _tauMediumMvaNew, &b__tauMediumMvaNew);
   Tree->SetBranchAddress("_tauTightMvaNew", _tauTightMvaNew, &b__tauTightMvaNew);
   Tree->SetBranchAddress("_tauVTightMvaNew", _tauVTightMvaNew, &b__tauVTightMvaNew);
   Tree->SetBranchAddress("_tauVTightMvaOld", _tauVTightMvaOld, &b__tauVTightMvaOld);
   Tree->SetBranchAddress("_closestJetCsvV2", _closestJetCsvV2, &b__closestJetCsvV2);
   Tree->SetBranchAddress("_closestJetDeepCsv_b", _closestJetDeepCsv_b, &b__closestJetDeepCsv_b);
   Tree->SetBranchAddress("_closestJetDeepCsv_bb", _closestJetDeepCsv_bb, &b__closestJetDeepCsv_bb);
   Tree->SetBranchAddress("_lGenIndex", _lGenIndex, &b__lGenIndex);
   Tree->SetBranchAddress("_lMatchType", _lMatchType, &b__lMatchType);
   Tree->SetBranchAddress("_lIsPrompt", _lIsPrompt, &b__lIsPrompt);
   Tree->SetBranchAddress("_lIsPromptFinalState", _lIsPromptFinalState, &b__lIsPromptFinalState);
   Tree->SetBranchAddress("_lIsPromptDecayed", _lIsPromptDecayed, &b__lIsPromptDecayed);
   Tree->SetBranchAddress("_lMatchPdgId", _lMatchPdgId, &b__lMatchPdgId);
   Tree->SetBranchAddress("_lProvenance", _lProvenance, &b__lProvenance);
   Tree->SetBranchAddress("_lProvenanceCompressed", _lProvenanceCompressed, &b__lProvenanceCompressed);
   Tree->SetBranchAddress("_lMatchPt", _lMatchPt, &b__lMatchPt);
   Tree->SetBranchAddress("_lMatchEta", _lMatchEta, &b__lMatchEta);
   Tree->SetBranchAddress("_lMatchPhi", _lMatchPhi, &b__lMatchPhi);
   Tree->SetBranchAddress("_lMatchVertexX", _lMatchVertexX, &b__lMatchVertexX);
   Tree->SetBranchAddress("_lMatchVertexY", _lMatchVertexY, &b__lMatchVertexY);
   Tree->SetBranchAddress("_lMatchVertexZ", _lMatchVertexZ, &b__lMatchVertexZ);
   Tree->SetBranchAddress("_nPh", &_nPh, &b__nPh);
   Tree->SetBranchAddress("_phPt", _phPt, &b__phPt);
   Tree->SetBranchAddress("_phEta", _phEta, &b__phEta);
   Tree->SetBranchAddress("_phEtaSC", _phEtaSC, &b__phEtaSC);
   Tree->SetBranchAddress("_phPhi", _phPhi, &b__phPhi);
   Tree->SetBranchAddress("_phE", _phE, &b__phE);
   Tree->SetBranchAddress("_phCutBasedLoose", _phCutBasedLoose, &b__phCutBasedLoose);
   Tree->SetBranchAddress("_phCutBasedMedium", _phCutBasedMedium, &b__phCutBasedMedium);
   Tree->SetBranchAddress("_phCutBasedTight", _phCutBasedTight, &b__phCutBasedTight);
   Tree->SetBranchAddress("_phMva", _phMva, &b__phMva);
   Tree->SetBranchAddress("_phRandomConeChargedIsolation", _phRandomConeChargedIsolation, &b__phRandomConeChargedIsolation);
   Tree->SetBranchAddress("_phChargedIsolation", _phChargedIsolation, &b__phChargedIsolation);
   Tree->SetBranchAddress("_phNeutralHadronIsolation", _phNeutralHadronIsolation, &b__phNeutralHadronIsolation);
   Tree->SetBranchAddress("_phPhotonIsolation", _phPhotonIsolation, &b__phPhotonIsolation);
   Tree->SetBranchAddress("_phSigmaIetaIeta", _phSigmaIetaIeta, &b__phSigmaIetaIeta);
   Tree->SetBranchAddress("_phSigmaIetaIphi", _phSigmaIetaIphi, &b__phSigmaIetaIphi);
   Tree->SetBranchAddress("_phHadronicOverEm", _phHadronicOverEm, &b__phHadronicOverEm);
   Tree->SetBranchAddress("_phPassElectronVeto", _phPassElectronVeto, &b__phPassElectronVeto);
   Tree->SetBranchAddress("_phHasPixelSeed", _phHasPixelSeed, &b__phHasPixelSeed);
   Tree->SetBranchAddress("_phIsPrompt", _phIsPrompt, &b__phIsPrompt);
   Tree->SetBranchAddress("_phMatchMCPhotonAN15165", _phMatchMCPhotonAN15165, &b__phMatchMCPhotonAN15165);
   Tree->SetBranchAddress("_phMatchMCLeptonAN15165", _phMatchMCLeptonAN15165, &b__phMatchMCLeptonAN15165);
   Tree->SetBranchAddress("_phTTGMatchCategory", _phTTGMatchCategory, &b__phTTGMatchCategory);
   Tree->SetBranchAddress("_phTTGMatchPt", _phTTGMatchPt, &b__phTTGMatchPt);
   Tree->SetBranchAddress("_phTTGMatchEta", _phTTGMatchEta, &b__phTTGMatchEta);
   Tree->SetBranchAddress("_phMatchPdgId", _phMatchPdgId, &b__phMatchPdgId);
   Tree->SetBranchAddress("_nJets", &_nJets, &b__nJets);
   Tree->SetBranchAddress("_jetPt", _jetPt, &b__jetPt);
   Tree->SetBranchAddress("_jetPt_JECUp", _jetPt_JECUp, &b__jetPt_JECUp);
   Tree->SetBranchAddress("_jetPt_JECDown", _jetPt_JECDown, &b__jetPt_JECDown);
   Tree->SetBranchAddress("_jetPt_Uncorrected", _jetPt_Uncorrected, &b__jetPt_Uncorrected);
   Tree->SetBranchAddress("_jetPt_L1", _jetPt_L1, &b__jetPt_L1);
   Tree->SetBranchAddress("_jetPt_L2", _jetPt_L2, &b__jetPt_L2);
   Tree->SetBranchAddress("_jetPt_L3", _jetPt_L3, &b__jetPt_L3);
   Tree->SetBranchAddress("_jetEta", _jetEta, &b__jetEta);
   Tree->SetBranchAddress("_jetPhi", _jetPhi, &b__jetPhi);
   Tree->SetBranchAddress("_jetE", _jetE, &b__jetE);
   Tree->SetBranchAddress("_jetCsvV2", _jetCsvV2, &b__jetCsvV2);
   Tree->SetBranchAddress("_jetDeepCsv_udsg", _jetDeepCsv_udsg, &b__jetDeepCsv_udsg);
   Tree->SetBranchAddress("_jetDeepCsv_b", _jetDeepCsv_b, &b__jetDeepCsv_b);
   Tree->SetBranchAddress("_jetDeepCsv_c", _jetDeepCsv_c, &b__jetDeepCsv_c);
   Tree->SetBranchAddress("_jetDeepCsv_bb", _jetDeepCsv_bb, &b__jetDeepCsv_bb);
   Tree->SetBranchAddress("_jetHadronFlavor", _jetHadronFlavor, &b__jetHadronFlavor);
   Tree->SetBranchAddress("_jetIsLoose", _jetIsLoose, &b__jetIsLoose);
   Tree->SetBranchAddress("_jetIsTight", _jetIsTight, &b__jetIsTight);
   Tree->SetBranchAddress("_jetIsTightLepVeto", _jetIsTightLepVeto, &b__jetIsTightLepVeto);
   Tree->SetBranchAddress("_jetNeutralHadronFraction", _jetNeutralHadronFraction, &b__jetNeutralHadronFraction);
   Tree->SetBranchAddress("_jetChargedHadronFraction", _jetChargedHadronFraction, &b__jetChargedHadronFraction);
   Tree->SetBranchAddress("_jetNeutralEmFraction", _jetNeutralEmFraction, &b__jetNeutralEmFraction);
   Tree->SetBranchAddress("_jetChargedEmFraction", _jetChargedEmFraction, &b__jetChargedEmFraction);
   Tree->SetBranchAddress("_jetHFHadronFraction", _jetHFHadronFraction, &b__jetHFHadronFraction);
   Tree->SetBranchAddress("_jetHFEmFraction", _jetHFEmFraction, &b__jetHFEmFraction);
   Tree->SetBranchAddress("_met", &_met, &b__met);
   Tree->SetBranchAddress("_metRaw", &_metRaw, &b__metRaw);
   Tree->SetBranchAddress("_metJECDown", &_metJECDown, &b__metJECDown);
   Tree->SetBranchAddress("_metJECUp", &_metJECUp, &b__metJECUp);
   Tree->SetBranchAddress("_metUnclDown", &_metUnclDown, &b__metUnclDown);
   Tree->SetBranchAddress("_metUnclUp", &_metUnclUp, &b__metUnclUp);
   Tree->SetBranchAddress("_metPhi", &_metPhi, &b__metPhi);
   Tree->SetBranchAddress("_metRawPhi", &_metRawPhi, &b__metRawPhi);
   Tree->SetBranchAddress("_metPhiJECDown", &_metPhiJECDown, &b__metPhiJECDown);
   Tree->SetBranchAddress("_metPhiJECUp", &_metPhiJECUp, &b__metPhiJECUp);
   Tree->SetBranchAddress("_metPhiUnclDown", &_metPhiUnclDown, &b__metPhiUnclDown);
   Tree->SetBranchAddress("_metPhiUnclUp", &_metPhiUnclUp, &b__metPhiUnclUp);
   Tree->SetBranchAddress("_metSignificance", &_metSignificance, &b__metSignificance);
}

std::string to_string_with_precision(const Double_t a_value, const int n){
    std::ostringstream out;
    out << std::setprecision(n) << a_value;
    return out.str();
}

double Progressbar(double progress, double entry, double nentries){
	unsigned barWidth = 100;				
	std::cout << "[";				
	unsigned pos = barWidth*progress;				
	for (unsigned i = 0; i < barWidth; ++i) {					
		if (i < pos) std::cout << "=";					
		else if (i == pos) std::cout << ">";					
		else std::cout << " ";				
	}							
	std::cout << "] " << int(progress * 100.0) << " %\r";				
	std::cout.flush();				
	double a = (double) entry;				
	double b = (double) nentries;				
	progress = a/b;
	return progress;
}

void CorrectROCPlots(){
    gROOT->SetBatch(kTRUE);                                     //Plotting settings
    gStyle->SetOptStat(0);
    setTDRStyle();
	gStyle->SetPaintTextFormat("4.2f");
    gROOT->ProcessLine("gErrorIgnoreLevel = 1001;");

    Double_t Efficiency[NumberOfSamples][NumberOfDiscr][NumberOfWP] = {0};                  //Define arrays to determine efficiency
    Double_t EfficiencyErrors[NumberOfSamples][NumberOfDiscr][NumberOfWP] = {0};

    // TString FileName = "WZTo3LNu";
    //~ TString FileName = "displacedTTJets_skimmedwcopytree";
    TString FileName = "displacedTTJets";
    SetBranches(FileName);
    
    Double_t    nentry = Tree->GetEntries();                                //Define variables

    double progress = 0.0; 
    Int_t sample = 0;    

    for(Long64_t entry = 0; entry < nentry; entry++){                               //Loop over all entries
        progress = Progressbar(progress, entry, nentry);                            //Increase progress in progressbar
        Tree->GetEntry(entry);

        //Tau selector
        for(int lepton = 0; lepton < _nL; lepton++){                                //Loop over all leptons in event
        
            if(_lFlavor[lepton] != 2)                           continue;
            
            if(_lIsPrompt[lepton])                              sample = Signal;   

            if(!_lIsPrompt[lepton])                             sample = Background;
                
            nPromptTaus[sample]++;  
            
            if(!_decayModeFindingNew[lepton])                   continue;                       //New tau decay mode finding
            
            //~ if(!_tauMuonVeto[lepton])                           continue;
            //~ if(!_tauEleVeto[lepton])                            continue;

            if(_lPOGVeto[lepton])                               ++Efficiency[sample][MVA_Old][VLoose_MVA];                                  //Old tau ID
            if(_lPOGLoose[lepton])                              ++Efficiency[sample][MVA_Old][Loose_MVA];                  
            if(_lPOGMedium[lepton])                             ++Efficiency[sample][MVA_Old][Medium_MVA];                
            if(_lPOGTight[lepton])                              ++Efficiency[sample][MVA_Old][Tight_MVA];                  
            if(_tauVTightMvaOld[lepton])                        ++Efficiency[sample][MVA_Old][VTight_MVA];           

            if(_tauVLooseMvaNew[lepton])                        ++Efficiency[sample][MVA_New][VLoose_MVA];                                  //New tau ID
            if(_tauLooseMvaNew[lepton])                         ++Efficiency[sample][MVA_New][Loose_MVA];             
            if(_tauMediumMvaNew[lepton])                        ++Efficiency[sample][MVA_New][Medium_MVA];           
            if(_tauTightMvaNew[lepton])                         ++Efficiency[sample][MVA_New][Tight_MVA];             
            if(_tauVTightMvaNew[lepton])                        ++Efficiency[sample][MVA_New][VTight_MVA];           
            
            //~ if(_tauCombinedIsoDBRaw3Hits[lepton] < 4.5)         ++Efficiency[sample][Cut_based][VVLoose_Cut];                                   //Cut-based
            //~ if(_tauCombinedIsoDBRaw3Hits[lepton] < 3.5)         ++Efficiency[sample][Cut_based][VLoose_Cut];               
            //~ if(_tauCombinedIsoDBRaw3Hits[lepton] < 2.0)         ++Efficiency[sample][Cut_based][Loose_Cut];               
            //~ if(_tauCombinedIsoDBRaw3Hits[lepton] < 1.0)         ++Efficiency[sample][Cut_based][Medium_Cut];              
            //~ if(_tauCombinedIsoDBRaw3Hits[lepton] < 0.8)         ++Efficiency[sample][Cut_based][Tight_Cut];  
            
        }
        
    }

        // for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
        //     for(int WP = 0; WP < NumberOfWP; ++WP){
        //         cout << Efficiency[Signal][discriminator][WP] << " " << nPromptTaus[Signal] << endl;
        //         cout << Efficiency[Background][discriminator][WP] << " " << nPromptTaus[Background] << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        //     }
        // }



        for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
            for(int WP = 0; WP < NumberOfWP; ++WP){
                EfficiencyErrors[Signal][discriminator][WP] = (sqrt(Efficiency[Signal][discriminator][WP])/nPromptTaus[Signal])*100;
                Efficiency[Signal][discriminator][WP] = (Efficiency[Signal][discriminator][WP]/nPromptTaus[Signal])*100;   
                EfficiencyErrors[Background][discriminator][WP] = (sqrt(Efficiency[Background][discriminator][WP])/nPromptTaus[Background])*100;
                Efficiency[Background][discriminator][WP] = (Efficiency[Background][discriminator][WP]/nPromptTaus[Background])*100;   
            }
        }

    //Create ROC graphs

    TGraphErrors * ROCmvaOld = new TGraphErrors(5, Efficiency[Background][MVA_Old], Efficiency[Signal][MVA_Old], EfficiencyErrors[Background][MVA_Old], EfficiencyErrors[Signal][MVA_Old]);
    TCanvas * c1 = new TCanvas("c1, c1");
    // c1->SetLogx();
    ROCmvaOld->SetTitle("; Efficiency in Background (%); Efficiency in Signal (%)");
    ROCmvaOld->SetMarkerSize(.5);
    // ROCmvaOld->GetXaxis()->SetLimits(20, 100);
    ROCmvaOld->Draw("AP");
    CMS_lumi(c1, 4, 11);
    c1->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_MVAOld.pdf");
    c1->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_MVAOld.jpg");

    TGraphErrors * ROCmvaNew = new TGraphErrors(5, Efficiency[Background][MVA_New], Efficiency[Signal][MVA_New], EfficiencyErrors[Background][MVA_New], EfficiencyErrors[Signal][MVA_New]);
    TCanvas * c2 = new TCanvas("c2, c2");
    // c2->SetLogx();
    ROCmvaNew->SetTitle("; Efficiency in Background (%); Efficiency in Signal (%)");
    ROCmvaNew->SetMarkerSize(.5);
    // ROCmvaNew->GetXaxis()->SetLimits(20, 100);
    ROCmvaNew->Draw("AP");
    CMS_lumi(c2, 4, 11);
    c2->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_MVANew.pdf");
    c2->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_MVANew.jpg");

    TGraphErrors * ROCCuts = new TGraphErrors(5, Efficiency[Background][Cut_based], Efficiency[Signal][Cut_based], EfficiencyErrors[Background][Cut_based], EfficiencyErrors[Signal][Cut_based]);
    TCanvas * c3 = new TCanvas("c3, c3");
    // c3->SetLogx();
    ROCCuts->SetTitle("; Efficiency in Background (%); Efficiency in Signal (%)");
    ROCCuts->SetMarkerSize(.5);
    // ROCCuts->GetXaxis()->SetLimits(20, 100);
    ROCCuts->Draw("AP");
    CMS_lumi(c3, 4, 11);
    c3->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_Cuts.pdf");
    c3->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_Cuts.jpg");

}
