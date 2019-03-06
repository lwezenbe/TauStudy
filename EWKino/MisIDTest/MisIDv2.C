#include "Constants.h"

void SetBranches(){
    WZTo3LNuFile->GetObject("blackJackAndHookers/blackJackAndHookersTree", WZTo3LNuTree);

    WZTo3LNuTree->SetBranchAddress("_runNb", &_runNb, &b__runNb);
   WZTo3LNuTree->SetBranchAddress("_lumiBlock", &_lumiBlock, &b__lumiBlock);
   WZTo3LNuTree->SetBranchAddress("_eventNb", &_eventNb, &b__eventNb);
   WZTo3LNuTree->SetBranchAddress("_nVertex", &_nVertex, &b__nVertex);
   WZTo3LNuTree->SetBranchAddress("_nTrueInt", &_nTrueInt, &b__nTrueInt);
   WZTo3LNuTree->SetBranchAddress("_weight", &_weight, &b__weight);
   WZTo3LNuTree->SetBranchAddress("_lheHTIncoming", &_lheHTIncoming, &b__lheHTIncoming);
   WZTo3LNuTree->SetBranchAddress("_ctauHN", &_ctauHN, &b__ctauHN);
   WZTo3LNuTree->SetBranchAddress("_nLheWeights", &_nLheWeights, &b__nLheWeights);
   WZTo3LNuTree->SetBranchAddress("_lheWeight", _lheWeight, &b__lheWeight);
   WZTo3LNuTree->SetBranchAddress("_nPsWeights", &_nPsWeights, &b__nPsWeights);
   WZTo3LNuTree->SetBranchAddress("_psWeight", _psWeight, &b__psWeight);
   WZTo3LNuTree->SetBranchAddress("_ttgEventType", &_ttgEventType, &b__ttgEventType);
   WZTo3LNuTree->SetBranchAddress("_zgEventType", &_zgEventType, &b__zgEventType);
   WZTo3LNuTree->SetBranchAddress("_gen_met", &_gen_met, &b__gen_met);
   WZTo3LNuTree->SetBranchAddress("_gen_metPhi", &_gen_metPhi, &b__gen_metPhi);
   WZTo3LNuTree->SetBranchAddress("_gen_nPh", &_gen_nPh, &b__gen_nPh);
   WZTo3LNuTree->SetBranchAddress("_gen_phStatus", _gen_phStatus, &b__gen_phStatus);
   WZTo3LNuTree->SetBranchAddress("_gen_phPt", _gen_phPt, &b__gen_phPt);
   WZTo3LNuTree->SetBranchAddress("_gen_phEta", _gen_phEta, &b__gen_phEta);
   WZTo3LNuTree->SetBranchAddress("_gen_phPhi", _gen_phPhi, &b__gen_phPhi);
   WZTo3LNuTree->SetBranchAddress("_gen_phE", _gen_phE, &b__gen_phE);
   WZTo3LNuTree->SetBranchAddress("_gen_phMomPdg", _gen_phMomPdg, &b__gen_phMomPdg);
   WZTo3LNuTree->SetBranchAddress("_gen_phIsPrompt", _gen_phIsPrompt, &b__gen_phIsPrompt);
   WZTo3LNuTree->SetBranchAddress("_gen_phMinDeltaR", _gen_phMinDeltaR, &b__gen_phMinDeltaR);
   WZTo3LNuTree->SetBranchAddress("_gen_phPassParentage", _gen_phPassParentage, &b__gen_phPassParentage);
   WZTo3LNuTree->SetBranchAddress("_gen_nL", &_gen_nL, &b__gen_nL);
   WZTo3LNuTree->SetBranchAddress("_gen_lPt", _gen_lPt, &b__gen_lPt);
   WZTo3LNuTree->SetBranchAddress("_gen_lEta", _gen_lEta, &b__gen_lEta);
   WZTo3LNuTree->SetBranchAddress("_gen_lPhi", _gen_lPhi, &b__gen_lPhi);
   WZTo3LNuTree->SetBranchAddress("_gen_lE", _gen_lE, &b__gen_lE);
   WZTo3LNuTree->SetBranchAddress("_gen_lFlavor", _gen_lFlavor, &b__gen_lFlavor);
   WZTo3LNuTree->SetBranchAddress("_gen_lCharge", _gen_lCharge, &b__gen_lCharge);
   WZTo3LNuTree->SetBranchAddress("_gen_lMomPdg", _gen_lMomPdg, &b__gen_lMomPdg);
   WZTo3LNuTree->SetBranchAddress("_gen_lIsPrompt", _gen_lIsPrompt, &b__gen_lIsPrompt);
   WZTo3LNuTree->SetBranchAddress("_gen_lMinDeltaR", _gen_lMinDeltaR, &b__gen_lMinDeltaR);
   WZTo3LNuTree->SetBranchAddress("_gen_lPassParentage", _gen_lPassParentage, &b__gen_lPassParentage);
   WZTo3LNuTree->SetBranchAddress("_gen_HT", &_gen_HT, &b__gen_HT);
   WZTo3LNuTree->SetBranchAddress("_passMETFilters", &_passMETFilters, &b__passMETFilters);
   WZTo3LNuTree->SetBranchAddress("_Flag_HBHENoiseFilter", &_Flag_HBHENoiseFilter, &b__Flag_HBHENoiseFilter);
   WZTo3LNuTree->SetBranchAddress("_Flag_HBHENoiseIsoFilter", &_Flag_HBHENoiseIsoFilter, &b__Flag_HBHENoiseIsoFilter);
   WZTo3LNuTree->SetBranchAddress("_Flag_EcalDeadCellTriggerPrimitiveFilter", &_Flag_EcalDeadCellTriggerPrimitiveFilter, &b__Flag_EcalDeadCellTriggerPrimitiveFilter);
   WZTo3LNuTree->SetBranchAddress("_Flag_goodVertices", &_Flag_goodVertices, &b__Flag_goodVertices);
   WZTo3LNuTree->SetBranchAddress("_Flag_globalTightHalo2016Filter", &_Flag_globalTightHalo2016Filter, &b__Flag_globalTightHalo2016Filter);
   WZTo3LNuTree->SetBranchAddress("_Flag_ecalBadCalibFilter", &_Flag_ecalBadCalibFilter, &b__Flag_ecalBadCalibFilter);
   WZTo3LNuTree->SetBranchAddress("_Flag_BadPFMuonFilter", &_Flag_BadPFMuonFilter, &b__Flag_BadPFMuonFilter);
   WZTo3LNuTree->SetBranchAddress("_Flag_BadChargedCandidateFilter", &_Flag_BadChargedCandidateFilter, &b__Flag_BadChargedCandidateFilter);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_e", &_passTrigger_e, &b__passTrigger_e);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele32_WPTight_Gsf", &_HLT_Ele32_WPTight_Gsf, &b__HLT_Ele32_WPTight_Gsf);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele32_WPTight_Gsf_prescale", &_HLT_Ele32_WPTight_Gsf_prescale, &b__HLT_Ele32_WPTight_Gsf_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele35_WPTight_Gsf", &_HLT_Ele35_WPTight_Gsf, &b__HLT_Ele35_WPTight_Gsf);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele35_WPTight_Gsf_prescale", &_HLT_Ele35_WPTight_Gsf_prescale, &b__HLT_Ele35_WPTight_Gsf_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele38_WPTight_Gsf", &_HLT_Ele38_WPTight_Gsf, &b__HLT_Ele38_WPTight_Gsf);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele38_WPTight_Gsf_prescale", &_HLT_Ele38_WPTight_Gsf_prescale, &b__HLT_Ele38_WPTight_Gsf_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele40_WPTight_Gsf", &_HLT_Ele40_WPTight_Gsf, &b__HLT_Ele40_WPTight_Gsf);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele40_WPTight_Gsf_prescale", &_HLT_Ele40_WPTight_Gsf_prescale, &b__HLT_Ele40_WPTight_Gsf_prescale);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_ee", &_passTrigger_ee, &b__passTrigger_ee);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL", &_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL, &b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale", &_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale, &b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_eee", &_passTrigger_eee, &b__passTrigger_eee);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL", &_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL, &b__HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale", &_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale, &b__HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_eem", &_passTrigger_eem, &b__passTrigger_eem);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu8_DiEle12_CaloIdL_TrackIdL", &_HLT_Mu8_DiEle12_CaloIdL_TrackIdL, &b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale", &_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale, &b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ", &_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ, &b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ_prescale", &_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ_prescale, &b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ_prescale);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_em", &_passTrigger_em, &b__passTrigger_em);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ", &_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ, &b__HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ_prescale", &_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ_prescale, &b__HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL", &_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL, &b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_prescale", &_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_prescale, &b__HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_prescale);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_emm", &_passTrigger_emm, &b__passTrigger_emm);
   WZTo3LNuTree->SetBranchAddress("_HLT_DiMu9_Ele9_CaloIdL_TrackIdL", &_HLT_DiMu9_Ele9_CaloIdL_TrackIdL, &b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL);
   WZTo3LNuTree->SetBranchAddress("_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale", &_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale, &b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ", &_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ, &b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ);
   WZTo3LNuTree->SetBranchAddress("_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_prescale", &_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_prescale, &b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_prescale);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_et", &_passTrigger_et, &b__passTrigger_et);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", &_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1, &b__HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1);
   WZTo3LNuTree->SetBranchAddress("_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_prescale", &_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_prescale, &b__HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_prescale);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_m", &_passTrigger_m, &b__passTrigger_m);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu24", &_HLT_IsoMu24, &b__HLT_IsoMu24);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu24_prescale", &_HLT_IsoMu24_prescale, &b__HLT_IsoMu24_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu24_eta2p1", &_HLT_IsoMu24_eta2p1, &b__HLT_IsoMu24_eta2p1);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu24_eta2p1_prescale", &_HLT_IsoMu24_eta2p1_prescale, &b__HLT_IsoMu24_eta2p1_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu27", &_HLT_IsoMu27, &b__HLT_IsoMu27);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu27_prescale", &_HLT_IsoMu27_prescale, &b__HLT_IsoMu27_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu30", &_HLT_IsoMu30, &b__HLT_IsoMu30);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu30_prescale", &_HLT_IsoMu30_prescale, &b__HLT_IsoMu30_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu50", &_HLT_Mu50, &b__HLT_Mu50);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu50_prescale", &_HLT_Mu50_prescale, &b__HLT_Mu50_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu55", &_HLT_Mu55, &b__HLT_Mu55);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu55_prescale", &_HLT_Mu55_prescale, &b__HLT_Mu55_prescale);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_mm", &_passTrigger_mm, &b__passTrigger_mm);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_prescale", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_prescale, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_prescale", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_prescale, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8", &_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8, &b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8_prescale", &_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8_prescale, &b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8", &_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8, &b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8);
   WZTo3LNuTree->SetBranchAddress("_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8_prescale", &_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8_prescale, &b__HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8_prescale);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_mmm", &_passTrigger_mmm, &b__passTrigger_mmm);
   WZTo3LNuTree->SetBranchAddress("_HLT_TripleMu_10_5_5_DZ", &_HLT_TripleMu_10_5_5_DZ, &b__HLT_TripleMu_10_5_5_DZ);
   WZTo3LNuTree->SetBranchAddress("_HLT_TripleMu_10_5_5_DZ_prescale", &_HLT_TripleMu_10_5_5_DZ_prescale, &b__HLT_TripleMu_10_5_5_DZ_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_TripleMu_5_3_3_Mass3p8to60_DZ", &_HLT_TripleMu_5_3_3_Mass3p8to60_DZ, &b__HLT_TripleMu_5_3_3_Mass3p8to60_DZ);
   WZTo3LNuTree->SetBranchAddress("_HLT_TripleMu_5_3_3_Mass3p8to60_DZ_prescale", &_HLT_TripleMu_5_3_3_Mass3p8to60_DZ_prescale, &b__HLT_TripleMu_5_3_3_Mass3p8to60_DZ_prescale);
   WZTo3LNuTree->SetBranchAddress("_TripleMu_12_10_5", &_TripleMu_12_10_5, &b__TripleMu_12_10_5);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_mt", &_passTrigger_mt, &b__passTrigger_mt);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1", &_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1, &b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_prescale", &_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_prescale, &b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1", &_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1, &b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_prescale", &_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_prescale, &b__HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1_prescale", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1_prescale, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1_prescale", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1_prescale, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1_prescale);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
   WZTo3LNuTree->SetBranchAddress("_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_prescale", &_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_prescale, &b__HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_prescale);
   WZTo3LNuTree->SetBranchAddress("_passTrigger_t", &_passTrigger_t, &b__passTrigger_t);
   WZTo3LNuTree->SetBranchAddress("_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr", &_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr, &b__HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
   WZTo3LNuTree->SetBranchAddress("_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_prescale", &_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_prescale, &b__HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_prescale);
   WZTo3LNuTree->SetBranchAddress("_nL", &_nL, &b__nL);
   WZTo3LNuTree->SetBranchAddress("_nMu", &_nMu, &b__nMu);
   WZTo3LNuTree->SetBranchAddress("_nEle", &_nEle, &b__nEle);
   WZTo3LNuTree->SetBranchAddress("_nLight", &_nLight, &b__nLight);
   WZTo3LNuTree->SetBranchAddress("_nTau", &_nTau, &b__nTau);
   WZTo3LNuTree->SetBranchAddress("_lPt", _lPt, &b__lPt);
   WZTo3LNuTree->SetBranchAddress("_lEta", _lEta, &b__lEta);
   WZTo3LNuTree->SetBranchAddress("_lEtaSC", _lEtaSC, &b__lEtaSC);
   WZTo3LNuTree->SetBranchAddress("_lPhi", _lPhi, &b__lPhi);
   WZTo3LNuTree->SetBranchAddress("_lE", _lE, &b__lE);
   WZTo3LNuTree->SetBranchAddress("_lFlavor", _lFlavor, &b__lFlavor);
   WZTo3LNuTree->SetBranchAddress("_lCharge", _lCharge, &b__lCharge);
   WZTo3LNuTree->SetBranchAddress("_dxy", _dxy, &b__dxy);
   WZTo3LNuTree->SetBranchAddress("_dz", _dz, &b__dz);
   WZTo3LNuTree->SetBranchAddress("_3dIP", _3dIP, &b__3dIP);
   WZTo3LNuTree->SetBranchAddress("_3dIPSig", _3dIPSig, &b__3dIPSig);
   WZTo3LNuTree->SetBranchAddress("_lElectronMva", _lElectronMva, &b__lElectronMva);
   WZTo3LNuTree->SetBranchAddress("_lElectronMvaHZZ", _lElectronMvaHZZ, &b__lElectronMvaHZZ);
   WZTo3LNuTree->SetBranchAddress("_lElectronMvaFall17Iso", _lElectronMvaFall17Iso, &b__lElectronMvaFall17Iso);
   WZTo3LNuTree->SetBranchAddress("_lElectronMvaFall17NoIso", _lElectronMvaFall17NoIso, &b__lElectronMvaFall17NoIso);
   WZTo3LNuTree->SetBranchAddress("_lElectronPassEmu", _lElectronPassEmu, &b__lElectronPassEmu);
   WZTo3LNuTree->SetBranchAddress("_lElectronPassConvVeto", _lElectronPassConvVeto, &b__lElectronPassConvVeto);
   WZTo3LNuTree->SetBranchAddress("_lElectronChargeConst", _lElectronChargeConst, &b__lElectronChargeConst);
   WZTo3LNuTree->SetBranchAddress("_lElectronMissingHits", _lElectronMissingHits, &b__lElectronMissingHits);
   WZTo3LNuTree->SetBranchAddress("_leptonMvaSUSY16", _leptonMvaSUSY16, &b__leptonMvaSUSY16);
   WZTo3LNuTree->SetBranchAddress("_leptonMvaTTH16", _leptonMvaTTH16, &b__leptonMvaTTH16);
   WZTo3LNuTree->SetBranchAddress("_leptonMvaSUSY17", _leptonMvaSUSY17, &b__leptonMvaSUSY17);
   WZTo3LNuTree->SetBranchAddress("_leptonMvaTTH17", _leptonMvaTTH17, &b__leptonMvaTTH17);
   WZTo3LNuTree->SetBranchAddress("_leptonMvatZqTTV16", _leptonMvatZqTTV16, &b__leptonMvatZqTTV16);
   WZTo3LNuTree->SetBranchAddress("_leptonMvatZqTTV17", _leptonMvatZqTTV17, &b__leptonMvatZqTTV17);
   WZTo3LNuTree->SetBranchAddress("_lHNLoose", _lHNLoose, &b__lHNLoose);
   WZTo3LNuTree->SetBranchAddress("_lHNFO", _lHNFO, &b__lHNFO);
   WZTo3LNuTree->SetBranchAddress("_lHNTight", _lHNTight, &b__lHNTight);
   WZTo3LNuTree->SetBranchAddress("_lEwkLoose", _lEwkLoose, &b__lEwkLoose);
   WZTo3LNuTree->SetBranchAddress("_lEwkFO", _lEwkFO, &b__lEwkFO);
   WZTo3LNuTree->SetBranchAddress("_lEwkTight", _lEwkTight, &b__lEwkTight);
   WZTo3LNuTree->SetBranchAddress("_lPOGVeto", _lPOGVeto, &b__lPOGVeto);
   WZTo3LNuTree->SetBranchAddress("_lPOGLoose", _lPOGLoose, &b__lPOGLoose);
   WZTo3LNuTree->SetBranchAddress("_lPOGMedium", _lPOGMedium, &b__lPOGMedium);
   WZTo3LNuTree->SetBranchAddress("_lPOGTight", _lPOGTight, &b__lPOGTight);
   WZTo3LNuTree->SetBranchAddress("_lPOGLooseWOIso", _lPOGLooseWOIso, &b__lPOGLooseWOIso);
   WZTo3LNuTree->SetBranchAddress("_lPOGMediumWOIso", _lPOGMediumWOIso, &b__lPOGMediumWOIso);
   WZTo3LNuTree->SetBranchAddress("_lPOGTightWOIso", _lPOGTightWOIso, &b__lPOGTightWOIso);
   WZTo3LNuTree->SetBranchAddress("_tauMuonVeto", _tauMuonVeto, &b__tauMuonVeto);
   WZTo3LNuTree->SetBranchAddress("_tauEleVeto", _tauEleVeto, &b__tauEleVeto);
   WZTo3LNuTree->SetBranchAddress("_decayModeFindingNew", _decayModeFindingNew, &b__decayModeFindingNew);
   WZTo3LNuTree->SetBranchAddress("_tauVLooseMvaNew", _tauVLooseMvaNew, &b__tauVLooseMvaNew);
   WZTo3LNuTree->SetBranchAddress("_tauLooseMvaNew", _tauLooseMvaNew, &b__tauLooseMvaNew);
   WZTo3LNuTree->SetBranchAddress("_tauMediumMvaNew", _tauMediumMvaNew, &b__tauMediumMvaNew);
   WZTo3LNuTree->SetBranchAddress("_tauTightMvaNew", _tauTightMvaNew, &b__tauTightMvaNew);
   WZTo3LNuTree->SetBranchAddress("_tauVTightMvaNew", _tauVTightMvaNew, &b__tauVTightMvaNew);
   WZTo3LNuTree->SetBranchAddress("_tauVTightMvaOld", _tauVTightMvaOld, &b__tauVTightMvaOld);
   WZTo3LNuTree->SetBranchAddress("_tauAgainstElectronMVA6Raw", _tauAgainstElectronMVA6Raw, &b__tauAgainstElectronMVA6Raw);
   WZTo3LNuTree->SetBranchAddress("_tauCombinedIsoDBRaw3Hits", _tauCombinedIsoDBRaw3Hits, &b__tauCombinedIsoDBRaw3Hits);
   WZTo3LNuTree->SetBranchAddress("_tauIsoMVAPWdR03oldDMwLT", _tauIsoMVAPWdR03oldDMwLT, &b__tauIsoMVAPWdR03oldDMwLT);
   WZTo3LNuTree->SetBranchAddress("_tauIsoMVADBdR03oldDMwLT", _tauIsoMVADBdR03oldDMwLT, &b__tauIsoMVADBdR03oldDMwLT);
   WZTo3LNuTree->SetBranchAddress("_tauIsoMVADBdR03newDMwLT", _tauIsoMVADBdR03newDMwLT, &b__tauIsoMVADBdR03newDMwLT);
   WZTo3LNuTree->SetBranchAddress("_tauIsoMVAPWnewDMwLT", _tauIsoMVAPWnewDMwLT, &b__tauIsoMVAPWnewDMwLT);
   WZTo3LNuTree->SetBranchAddress("_tauIsoMVAPWoldDMwLT", _tauIsoMVAPWoldDMwLT, &b__tauIsoMVAPWoldDMwLT);
   WZTo3LNuTree->SetBranchAddress("_relIso", _relIso, &b__relIso);
   WZTo3LNuTree->SetBranchAddress("_relIso0p4", _relIso0p4, &b__relIso0p4);
   WZTo3LNuTree->SetBranchAddress("_relIso0p4MuDeltaBeta", _relIso0p4MuDeltaBeta, &b__relIso0p4MuDeltaBeta);
   WZTo3LNuTree->SetBranchAddress("_miniIso", _miniIso, &b__miniIso);
   WZTo3LNuTree->SetBranchAddress("_miniIsoCharged", _miniIsoCharged, &b__miniIsoCharged);
   WZTo3LNuTree->SetBranchAddress("_ptRel", _ptRel, &b__ptRel);
   WZTo3LNuTree->SetBranchAddress("_ptRatio", _ptRatio, &b__ptRatio);
   WZTo3LNuTree->SetBranchAddress("_closestJetCsvV2", _closestJetCsvV2, &b__closestJetCsvV2);
   WZTo3LNuTree->SetBranchAddress("_closestJetDeepCsv_b", _closestJetDeepCsv_b, &b__closestJetDeepCsv_b);
   WZTo3LNuTree->SetBranchAddress("_closestJetDeepCsv_bb", _closestJetDeepCsv_bb, &b__closestJetDeepCsv_bb);
   WZTo3LNuTree->SetBranchAddress("_selectedTrackMult", _selectedTrackMult, &b__selectedTrackMult);
   WZTo3LNuTree->SetBranchAddress("_lMuonSegComp", _lMuonSegComp, &b__lMuonSegComp);
   WZTo3LNuTree->SetBranchAddress("_lMuonTrackPt", _lMuonTrackPt, &b__lMuonTrackPt);
   WZTo3LNuTree->SetBranchAddress("_lMuonTrackPtErr", _lMuonTrackPtErr, &b__lMuonTrackPtErr);
   WZTo3LNuTree->SetBranchAddress("_lIsPrompt", _lIsPrompt, &b__lIsPrompt);
   WZTo3LNuTree->SetBranchAddress("_lMatchPdgId", _lMatchPdgId, &b__lMatchPdgId);
   WZTo3LNuTree->SetBranchAddress("_lMomPdgId", _lMomPdgId, &b__lMomPdgId);
   WZTo3LNuTree->SetBranchAddress("_lProvenance", _lProvenance, &b__lProvenance);
   WZTo3LNuTree->SetBranchAddress("_lProvenanceCompressed", _lProvenanceCompressed, &b__lProvenanceCompressed);
   WZTo3LNuTree->SetBranchAddress("_lProvenanceConversion", _lProvenanceConversion, &b__lProvenanceConversion);
   WZTo3LNuTree->SetBranchAddress("_nPh", &_nPh, &b__nPh);
   WZTo3LNuTree->SetBranchAddress("_phPt", _phPt, &b__phPt);
   WZTo3LNuTree->SetBranchAddress("_phEta", _phEta, &b__phEta);
   WZTo3LNuTree->SetBranchAddress("_phEtaSC", _phEtaSC, &b__phEtaSC);
   WZTo3LNuTree->SetBranchAddress("_phPhi", _phPhi, &b__phPhi);
   WZTo3LNuTree->SetBranchAddress("_phE", _phE, &b__phE);
   WZTo3LNuTree->SetBranchAddress("_phCutBasedLoose", _phCutBasedLoose, &b__phCutBasedLoose);
   WZTo3LNuTree->SetBranchAddress("_phCutBasedMedium", _phCutBasedMedium, &b__phCutBasedMedium);
   WZTo3LNuTree->SetBranchAddress("_phCutBasedTight", _phCutBasedTight, &b__phCutBasedTight);
   WZTo3LNuTree->SetBranchAddress("_phMva", _phMva, &b__phMva);
   WZTo3LNuTree->SetBranchAddress("_phRandomConeChargedIsolation", _phRandomConeChargedIsolation, &b__phRandomConeChargedIsolation);
   WZTo3LNuTree->SetBranchAddress("_phChargedIsolation", _phChargedIsolation, &b__phChargedIsolation);
   WZTo3LNuTree->SetBranchAddress("_phNeutralHadronIsolation", _phNeutralHadronIsolation, &b__phNeutralHadronIsolation);
   WZTo3LNuTree->SetBranchAddress("_phPhotonIsolation", _phPhotonIsolation, &b__phPhotonIsolation);
   WZTo3LNuTree->SetBranchAddress("_phSigmaIetaIeta", _phSigmaIetaIeta, &b__phSigmaIetaIeta);
   WZTo3LNuTree->SetBranchAddress("_phSigmaIetaIphi", _phSigmaIetaIphi, &b__phSigmaIetaIphi);
   WZTo3LNuTree->SetBranchAddress("_phHadronicOverEm", _phHadronicOverEm, &b__phHadronicOverEm);
   WZTo3LNuTree->SetBranchAddress("_phPassElectronVeto", _phPassElectronVeto, &b__phPassElectronVeto);
   WZTo3LNuTree->SetBranchAddress("_phHasPixelSeed", _phHasPixelSeed, &b__phHasPixelSeed);
   WZTo3LNuTree->SetBranchAddress("_phIsPrompt", _phIsPrompt, &b__phIsPrompt);
   WZTo3LNuTree->SetBranchAddress("_phMatchMCPhotonAN15165", _phMatchMCPhotonAN15165, &b__phMatchMCPhotonAN15165);
   WZTo3LNuTree->SetBranchAddress("_phMatchMCLeptonAN15165", _phMatchMCLeptonAN15165, &b__phMatchMCLeptonAN15165);
   WZTo3LNuTree->SetBranchAddress("_phTTGMatchCategory", _phTTGMatchCategory, &b__phTTGMatchCategory);
   WZTo3LNuTree->SetBranchAddress("_phTTGMatchPt", _phTTGMatchPt, &b__phTTGMatchPt);
   WZTo3LNuTree->SetBranchAddress("_phTTGMatchEta", _phTTGMatchEta, &b__phTTGMatchEta);
   WZTo3LNuTree->SetBranchAddress("_phMatchPdgId", _phMatchPdgId, &b__phMatchPdgId);
   WZTo3LNuTree->SetBranchAddress("_nJets", &_nJets, &b__nJets);
   WZTo3LNuTree->SetBranchAddress("_jetPt", _jetPt, &b__jetPt);
   WZTo3LNuTree->SetBranchAddress("_jetPt_JECDown", _jetPt_JECDown, &b__jetPt_JECDown);
   WZTo3LNuTree->SetBranchAddress("_jetPt_JECUp", _jetPt_JECUp, &b__jetPt_JECUp);
   WZTo3LNuTree->SetBranchAddress("_jetSmearedPt", _jetSmearedPt, &b__jetSmearedPt);
   WZTo3LNuTree->SetBranchAddress("_jetSmearedPt_JECDown", _jetSmearedPt_JECDown, &b__jetSmearedPt_JECDown);
   WZTo3LNuTree->SetBranchAddress("_jetSmearedPt_JECUp", _jetSmearedPt_JECUp, &b__jetSmearedPt_JECUp);
   WZTo3LNuTree->SetBranchAddress("_jetSmearedPt_JERDown", _jetSmearedPt_JERDown, &b__jetSmearedPt_JERDown);
   WZTo3LNuTree->SetBranchAddress("_jetSmearedPt_JERUp", _jetSmearedPt_JERUp, &b__jetSmearedPt_JERUp);
   WZTo3LNuTree->SetBranchAddress("_jetPt_Uncorrected", _jetPt_Uncorrected, &b__jetPt_Uncorrected);
   WZTo3LNuTree->SetBranchAddress("_jetPt_L1", _jetPt_L1, &b__jetPt_L1);
   WZTo3LNuTree->SetBranchAddress("_jetPt_L2", _jetPt_L2, &b__jetPt_L2);
   WZTo3LNuTree->SetBranchAddress("_jetPt_L3", _jetPt_L3, &b__jetPt_L3);
   WZTo3LNuTree->SetBranchAddress("_jetEta", _jetEta, &b__jetEta);
   WZTo3LNuTree->SetBranchAddress("_jetPhi", _jetPhi, &b__jetPhi);
   WZTo3LNuTree->SetBranchAddress("_jetE", _jetE, &b__jetE);
   WZTo3LNuTree->SetBranchAddress("_jetCsvV2", _jetCsvV2, &b__jetCsvV2);
   WZTo3LNuTree->SetBranchAddress("_jetDeepCsv_udsg", _jetDeepCsv_udsg, &b__jetDeepCsv_udsg);
   WZTo3LNuTree->SetBranchAddress("_jetDeepCsv_b", _jetDeepCsv_b, &b__jetDeepCsv_b);
   WZTo3LNuTree->SetBranchAddress("_jetDeepCsv_c", _jetDeepCsv_c, &b__jetDeepCsv_c);
   WZTo3LNuTree->SetBranchAddress("_jetDeepCsv_bb", _jetDeepCsv_bb, &b__jetDeepCsv_bb);
   WZTo3LNuTree->SetBranchAddress("_jetHadronFlavor", _jetHadronFlavor, &b__jetHadronFlavor);
   WZTo3LNuTree->SetBranchAddress("_jetIsLoose", _jetIsLoose, &b__jetIsLoose);
   WZTo3LNuTree->SetBranchAddress("_jetIsTight", _jetIsTight, &b__jetIsTight);
   WZTo3LNuTree->SetBranchAddress("_jetIsTightLepVeto", _jetIsTightLepVeto, &b__jetIsTightLepVeto);
   WZTo3LNuTree->SetBranchAddress("_jetNeutralHadronFraction", _jetNeutralHadronFraction, &b__jetNeutralHadronFraction);
   WZTo3LNuTree->SetBranchAddress("_jetChargedHadronFraction", _jetChargedHadronFraction, &b__jetChargedHadronFraction);
   WZTo3LNuTree->SetBranchAddress("_jetNeutralEmFraction", _jetNeutralEmFraction, &b__jetNeutralEmFraction);
   WZTo3LNuTree->SetBranchAddress("_jetChargedEmFraction", _jetChargedEmFraction, &b__jetChargedEmFraction);
   WZTo3LNuTree->SetBranchAddress("_jetHFHadronFraction", _jetHFHadronFraction, &b__jetHFHadronFraction);
   WZTo3LNuTree->SetBranchAddress("_jetHFEmFraction", _jetHFEmFraction, &b__jetHFEmFraction);
   WZTo3LNuTree->SetBranchAddress("_met", &_met, &b__met);
   WZTo3LNuTree->SetBranchAddress("_metRaw", &_metRaw, &b__metRaw);
   WZTo3LNuTree->SetBranchAddress("_metJECDown", &_metJECDown, &b__metJECDown);
   WZTo3LNuTree->SetBranchAddress("_metJECUp", &_metJECUp, &b__metJECUp);
   WZTo3LNuTree->SetBranchAddress("_metUnclDown", &_metUnclDown, &b__metUnclDown);
   WZTo3LNuTree->SetBranchAddress("_metUnclUp", &_metUnclUp, &b__metUnclUp);
   WZTo3LNuTree->SetBranchAddress("_metPhi", &_metPhi, &b__metPhi);
   WZTo3LNuTree->SetBranchAddress("_metRawPhi", &_metRawPhi, &b__metRawPhi);
   WZTo3LNuTree->SetBranchAddress("_metPhiJECDown", &_metPhiJECDown, &b__metPhiJECDown);
   WZTo3LNuTree->SetBranchAddress("_metPhiJECUp", &_metPhiJECUp, &b__metPhiJECUp);
   WZTo3LNuTree->SetBranchAddress("_metPhiUnclDown", &_metPhiUnclDown, &b__metPhiUnclDown);
   WZTo3LNuTree->SetBranchAddress("_metPhiUnclUp", &_metPhiUnclUp, &b__metPhiUnclUp);
   WZTo3LNuTree->SetBranchAddress("_metSignificance", &_metSignificance, &b__metSignificance);
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

void MisIDv2(){
    gROOT->SetBatch(kTRUE);
    gStyle->SetOptStat(0);
    // setTDRStyle();
	// gStyle->SetPaintTextFormat("4.2f");
    gROOT->ProcessLine( "gErrorIgnoreLevel = 1001;");

    SetBranches();

    Double_t    nentry = WZTo3LNuTree->GetEntries();                                //Define variables
    Double_t    JetCount = 0;
    Bool_t      matched = false;
    Int_t       matchedLep = 0;

    cout << nentry << endl;

    TH1D* EfficiencyHistMVA = new TH1D("EfficiencyMVA", "EfficiencyMVA", 10, 0, 10);         //Define Hist that will show the efficiency of different discriminator
    TH1D* EfficiencyHistCuts = new TH1D("EfficiencyCUT", "EfficiencyCUT", 5, 0, 5);         //Define Hist that will show the efficiency of different discriminator
    TH1D* EfficiencyPtHist[NumberOfDiscr][NumberOfFracComp];
    TH1D* EfficiencyEtaHist[NumberOfDiscr][NumberOfFracComp];

    TString histtitle;

    for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){                                                         //Initialize the enumerator and denominator for the calculation of efficiency
        for(int fracComp = 0; fracComp < NumberOfFracComp; fracComp++){
            histtitle = "EfficiencyPt"+to_string_with_precision(discriminator, 2) +to_string_with_precision(fracComp, 1);
            EfficiencyPtHist[discriminator][fracComp] = new TH1D(histtitle, histtitle, 10, 20, 120);
            histtitle = "EfficiencyEta"+to_string_with_precision(discriminator, 2)+to_string_with_precision(fracComp, 1);
            EfficiencyEtaHist[discriminator][fracComp] = new TH1D(histtitle, histtitle, 12, 0, 2.4);
        }
    }

    double progress = 0.0;      

    for(Long64_t entry = 0; entry < nentry/100; entry++){                               //Loop over all entries
        progress = Progressbar(progress, entry, nentry/100);                            //Increase progress in progressbar
        WZTo3LNuTree->GetEntry(entry);
        
        //Tau selector
        for(int jet = 0; jet < _nJets; jet++){                                //Loop over all leptons in event

            if(_jetPt[jet] < 20 or _jetEta[jet] > 2.3)                continue;

            ++JetCount;

            matched = false;
            for(int lepton = 0; lepton < _nL; lepton++){
                if(_lFlavor[lepton] != 2 or _lIsPrompt[lepton]) continue;
                Double_t DeltaR = sqrt(pow(_lEta[lepton]-_jetEta[jet],2) + pow(_lPhi[lepton]-_jetPhi[jet],2));
                if(DeltaR < 0.15){matched = true; matchedLep = lepton;}
            }

            if(!matched)                                        continue;                      

            if(!_decayModeFindingNew[matchedLep])                   continue;                       //New tau decay mode finding

            // if(_tauCombinedIsoDBRaw3Hits[matchedLep] > 2.0)         continue;                       //Loose Isolation cut                       
            
            // if(!_tauMuonVeto[matchedLep])                           continue;
            // if(!_tauEleVeto[matchedLep])                            continue;


            for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
                if(discriminator == VLoose_Old and _lPOGVeto[matchedLep]){                  EfficiencyHistMVA->AddBinContent(1); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}                 //Old tau ID
                if(discriminator == Loose_Old and _lPOGLoose[matchedLep]){                  EfficiencyHistMVA->AddBinContent(2); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
                if(discriminator == Medium_Old and _lPOGMedium[matchedLep]){                EfficiencyHistMVA->AddBinContent(3); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
                if(discriminator == Tight_Old and _lPOGTight[matchedLep]){                  EfficiencyHistMVA->AddBinContent(4); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
                if(discriminator == VTight_Old and _tauVTightMvaOld[matchedLep]){           EfficiencyHistMVA->AddBinContent(5); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}

                if(discriminator == VLoose_New and _tauVLooseMvaNew[matchedLep]){           EfficiencyHistMVA->AddBinContent(6); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}                    //New tau ID
                if(discriminator == Loose_New and _tauLooseMvaNew[matchedLep]){             EfficiencyHistMVA->AddBinContent(7); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
                if(discriminator == Medium_New and _tauMediumMvaNew[matchedLep]){           EfficiencyHistMVA->AddBinContent(8); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
                if(discriminator == Tight_New and _tauTightMvaNew[matchedLep]){             EfficiencyHistMVA->AddBinContent(9); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
                if(discriminator == VTight_New and _tauVTightMvaNew[matchedLep]){           EfficiencyHistMVA->AddBinContent(10); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
                
                if(discriminator == VVLoose_Cut and _tauCombinedIsoDBRaw3Hits[matchedLep] < 4.5){              EfficiencyHistCuts->AddBinContent(1); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}                    //Cut-based
                if(discriminator == VLoose_Cut and _tauCombinedIsoDBRaw3Hits[matchedLep] < 3.5){               EfficiencyHistCuts->AddBinContent(2); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
                if(discriminator == Loose_Cut and _tauCombinedIsoDBRaw3Hits[matchedLep] < 2.0){                EfficiencyHistCuts->AddBinContent(3); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
                if(discriminator == Medium_Cut and _tauCombinedIsoDBRaw3Hits[matchedLep] < 1.0){               EfficiencyHistCuts->AddBinContent(4); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
                if(discriminator == Tight_Cut and _tauCombinedIsoDBRaw3Hits[matchedLep] < 0.8){                EfficiencyHistCuts->AddBinContent(5); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[matchedLep]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[matchedLep]);}
            
            }
        
        }

    }

    cout << JetCount << " " << EfficiencyHistCuts->GetBinContent(1) << endl;

    EfficiencyHistMVA->Scale(100./JetCount);
    EfficiencyHistCuts->Scale(100./JetCount);
    // for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
    //     EfficiencyPtHist[discriminator][Enumerator]->Divide(EfficiencyPtHist[discriminator][Denominator]);
    //     EfficiencyPtHist[discriminator][Enumerator]->Scale(100.);
    //     EfficiencyEtaHist[discriminator][Enumerator]->Divide(EfficiencyEtaHist[discriminator][Denominator]);
    //     EfficiencyEtaHist[discriminator][Enumerator]->Scale(100.);
    // }

//Draw

    // for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
    //     EfficiencyPtHist[discriminator][Enumerator]->SetMarkerStyle(0);
    //     EfficiencyEtaHist[discriminator][Enumerator]->SetMarkerStyle(0);
    // }
    

    TCanvas * c1 = new TCanvas("c1, c1"); 
    c1->SetLogy();                         
    EfficiencyHistMVA->GetXaxis()->SetBinLabel(1, "Old_VLoose");
    EfficiencyHistMVA->GetXaxis()->SetBinLabel(2, "Old_Loose");
    EfficiencyHistMVA->GetXaxis()->SetBinLabel(3, "Old_Medium");
    EfficiencyHistMVA->GetXaxis()->SetBinLabel(4, "Old_Tight");
    EfficiencyHistMVA->GetXaxis()->SetBinLabel(5, "Old_VTight");
    EfficiencyHistMVA->GetXaxis()->SetBinLabel(6, "New_VLoose");
    EfficiencyHistMVA->GetXaxis()->SetBinLabel(7, "New_Loose");
    EfficiencyHistMVA->GetXaxis()->SetBinLabel(8, "New_Medium");
    EfficiencyHistMVA->GetXaxis()->SetBinLabel(9, "New_Tight");
    EfficiencyHistMVA->GetXaxis()->SetBinLabel(10, "New_VTight");
    EfficiencyHistMVA->SetTitle("Efficiency of different MVA discriminators to correctly identify tau leptons; ; Efficiency (%)");
    EfficiencyHistMVA->SetLineColor(kBlack);
    EfficiencyHistMVA->GetYaxis()->SetTitleOffset(1.1);
    EfficiencyHistMVA->SetFillColor(kGray);
    EfficiencyHistMVA->SetMinimum(0.001);
    EfficiencyHistMVA->SetMaximum(1);
    EfficiencyHistMVA->Draw("EHISTTEXT");
    // CMS_lumi(c1, 4, 1);
    
    c1->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/TTJets/MisID/TauEwkinoEfficiencyMVA.pdf");
    delete c1;
    delete EfficiencyHistMVA;

    TCanvas * c12 = new TCanvas("c12, c12");
    EfficiencyHistCuts->GetXaxis()->SetBinLabel(1, "VVLoose_Cuts");
    EfficiencyHistCuts->GetXaxis()->SetBinLabel(2, "VLoose_Cuts");
    EfficiencyHistCuts->GetXaxis()->SetBinLabel(3, "Loose_Cuts");
    EfficiencyHistCuts->GetXaxis()->SetBinLabel(4, "Medium_Cuts");
    EfficiencyHistCuts->GetXaxis()->SetBinLabel(5, "Tight_Cuts");
    EfficiencyHistCuts->SetTitle("Efficiency of different cut-based discriminators to correctly identify tau leptons; ; Efficiency (%)");
    EfficiencyHistCuts->SetLineColor(kBlack);
    EfficiencyHistCuts->GetYaxis()->SetTitleOffset(1.1);
    EfficiencyHistCuts->SetFillColor(kGray);
    EfficiencyHistCuts->SetMinimum(0);
    EfficiencyHistCuts->SetMaximum(100);
    EfficiencyHistCuts->Draw("EHISTTEXT");
    // CMS_lumi(c1, 4, 1);
    c12->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/TTJets/MisID/TauEwkinoEfficiencyCuts.pdf");
    delete c12;
    delete EfficiencyHistCuts;

    // TCanvas * c2 = new TCanvas("c2, c2");
    // EfficiencyPtHist[VLoose_Old][Enumerator]->SetLineColor(kBlack);
    // EfficiencyPtHist[VLoose_Old][Enumerator]->GetXaxis()->SetNdivisions(508);
    // EfficiencyPtHist[VLoose_Old][Enumerator]->SetMinimum(0);
    // EfficiencyPtHist[VLoose_Old][Enumerator]->SetMaximum(100);
    // // TString plottitle = "Efficiency of different old discriminators as a function of the transverse momentum of the lepton; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    // TString plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    // EfficiencyPtHist[VLoose_Old][Enumerator]->SetTitle(plottitle);
    // EfficiencyPtHist[VLoose_Old][Enumerator]->Draw("HIST");
    // EfficiencyPtHist[Loose_Old][Enumerator]->SetLineColor(kBlue);
    // EfficiencyPtHist[Loose_Old][Enumerator]->Draw("HISTSAME");
    // EfficiencyPtHist[Medium_Old][Enumerator]->SetLineColor(kRed);
    // EfficiencyPtHist[Medium_Old][Enumerator]->Draw("HISTSAME");
    // EfficiencyPtHist[Tight_Old][Enumerator]->SetLineColor(kOrange);
    // EfficiencyPtHist[Tight_Old][Enumerator]->Draw("HISTSAME");
    // EfficiencyPtHist[VTight_Old][Enumerator]->SetLineColor(kGreen-1);
    // EfficiencyPtHist[VTight_Old][Enumerator]->Draw("HISTSAME");
    // auto legend = new TLegend(.85,.7,1., .9);
    // legend->AddEntry(EfficiencyPtHist[VLoose_Old][Enumerator], "VLoose");
    // legend->AddEntry(EfficiencyPtHist[Loose_Old][Enumerator], "Loose");
    // legend->AddEntry(EfficiencyPtHist[Medium_Old][Enumerator], "Medium");
    // legend->AddEntry(EfficiencyPtHist[Tight_Old][Enumerator], "Tight");
    // legend->AddEntry(EfficiencyPtHist[VTight_Old][Enumerator], "VTight");
    // legend->SetFillStyle(0);
    // legend->SetBorderSize(0);
    // legend->Draw();
    // CMS_lumi(c2, 4, 11);
    // c2->SaveAs("/home/liam/Documents/PhD/Results/TauStudy/EWKino/MisID/OldMVATauEwkinoEfficiencyAsFuncOfPT.pdf");
    // delete c2;

    // TCanvas * c3 = new TCanvas("c3, c3");
    // EfficiencyPtHist[VLoose_New][Enumerator]->SetLineColor(kBlack);
    // EfficiencyPtHist[VLoose_New][Enumerator]->GetXaxis()->SetNdivisions(508);
    // EfficiencyPtHist[VLoose_New][Enumerator]->SetMinimum(0);
    // EfficiencyPtHist[VLoose_New][Enumerator]->SetMaximum(100);
    // // plottitle = "Efficiency of different new discriminators as a function of the transverse momentum of the lepton; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    // plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    // EfficiencyPtHist[VLoose_New][Enumerator]->SetTitle(plottitle);
    // EfficiencyPtHist[VLoose_New][Enumerator]->Draw("HIST");
    // EfficiencyPtHist[Loose_New][Enumerator]->SetLineColor(kBlue);
    // EfficiencyPtHist[Loose_New][Enumerator]->Draw("HISTSAME");
    // EfficiencyPtHist[Medium_New][Enumerator]->SetLineColor(kRed);
    // EfficiencyPtHist[Medium_New][Enumerator]->Draw("HISTSAME");
    // EfficiencyPtHist[Tight_New][Enumerator]->SetLineColor(kOrange);
    // EfficiencyPtHist[Tight_New][Enumerator]->Draw("HISTSAME");
    // EfficiencyPtHist[VTight_New][Enumerator]->SetLineColor(kGreen-1);
    // EfficiencyPtHist[VTight_New][Enumerator]->Draw("HISTSAME");
    // auto legend1 = new TLegend(.85,.7,1., .9);
    // legend1->AddEntry(EfficiencyPtHist[VLoose_New][Enumerator], "VLoose");
    // legend1->AddEntry(EfficiencyPtHist[Loose_New][Enumerator], "Loose");
    // legend1->AddEntry(EfficiencyPtHist[Medium_New][Enumerator], "Medium");
    // legend1->AddEntry(EfficiencyPtHist[Tight_New][Enumerator], "Tight");
    // legend1->AddEntry(EfficiencyPtHist[VTight_New][Enumerator], "VTight");
    // legend1->SetFillStyle(0);
    // legend1->SetBorderSize(0);
    // legend1->Draw();
    // CMS_lumi(c3, 4, 11);
    // c3->SaveAs("/home/liam/Documents/PhD/Results/TauStudy/EWKino/MisID/NewMVATauEwkinoEfficiencyAsFuncOfPT.pdf");
    // delete c3;

    // TCanvas * c4 = new TCanvas("c4, c4");
    // EfficiencyEtaHist[VLoose_Old][Enumerator]->SetLineColor(kBlack);
    // EfficiencyEtaHist[VLoose_Old][Enumerator]->GetXaxis()->SetNdivisions(508);
    // EfficiencyEtaHist[VLoose_Old][Enumerator]->SetMaximum(100);
    // EfficiencyEtaHist[VLoose_Old][Enumerator]->SetMinimum(0);
    // // plottitle = "Efficiency of different old discriminators as a function of the pseudorapidity of the lepton; #eta(#tau); Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 1);
    // plottitle = "; #eta(#tau); Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 1);
    // EfficiencyEtaHist[VLoose_Old][Enumerator]->SetTitle(plottitle);
    // EfficiencyEtaHist[VLoose_Old][Enumerator]->Draw("HIST");
    // EfficiencyEtaHist[Loose_Old][Enumerator]->SetLineColor(kBlue);
    // EfficiencyEtaHist[Loose_Old][Enumerator]->Draw("HISTSAME");
    // EfficiencyEtaHist[Medium_Old][Enumerator]->SetLineColor(kRed);
    // EfficiencyEtaHist[Medium_Old][Enumerator]->Draw("HISTSAME");
    // EfficiencyEtaHist[Tight_Old][Enumerator]->SetLineColor(kOrange);
    // EfficiencyEtaHist[Tight_Old][Enumerator]->Draw("HISTSAME");
    // EfficiencyEtaHist[VTight_Old][Enumerator]->SetLineColor(kGreen-1);
    // EfficiencyEtaHist[VTight_Old][Enumerator]->Draw("HISTSAME");
    // auto legend2 = new TLegend(.85,.7,1., .9);
    // legend2->AddEntry(EfficiencyEtaHist[VLoose_Old][Enumerator], "VLoose");
    // legend2->AddEntry(EfficiencyEtaHist[Loose_Old][Enumerator], "Loose");
    // legend2->AddEntry(EfficiencyEtaHist[Medium_Old][Enumerator], "Medium");
    // legend2->AddEntry(EfficiencyEtaHist[Tight_Old][Enumerator], "Tight");
    // legend2->AddEntry(EfficiencyEtaHist[VTight_Old][Enumerator], "VTight");
    // legend2->SetFillStyle(0);
    // legend2->SetBorderSize(0);
    // legend2->Draw();
    // CMS_lumi(c4, 4, 11);
    // c4->SaveAs("/home/liam/Documents/PhD/Results/TauStudy/EWKino/MisID/OldMVATauEwkinoEfficiencyAsFuncOfETA.pdf");
    // delete c4;

    // TCanvas * c5 = new TCanvas("c5, c5");
    // EfficiencyEtaHist[VLoose_New][Enumerator]->SetLineColor(kBlack);
    // EfficiencyEtaHist[VLoose_New][Enumerator]->GetXaxis()->SetNdivisions(508);
    // EfficiencyEtaHist[VLoose_New][Enumerator]->SetMaximum(100);
    // EfficiencyEtaHist[VLoose_New][Enumerator]->SetMinimum(0);
    // plottitle = "; #eta(#tau); Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 1);
    // // plottitle = "Efficiency of different new discriminators as a function of the pseudorapidity of the lepton; #eta(#tau); Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 1);
    // EfficiencyEtaHist[VLoose_New][Enumerator]->SetTitle(plottitle);
    // EfficiencyEtaHist[VLoose_New][Enumerator]->Draw("HIST");
    // EfficiencyEtaHist[Loose_New][Enumerator]->SetLineColor(kBlue);
    // EfficiencyEtaHist[Loose_New][Enumerator]->Draw("HISTSAME");
    // EfficiencyEtaHist[Medium_New][Enumerator]->SetLineColor(kRed);
    // EfficiencyEtaHist[Medium_New][Enumerator]->Draw("HISTSAME");
    // EfficiencyEtaHist[Tight_New][Enumerator]->SetLineColor(kOrange);
    // EfficiencyEtaHist[Tight_New][Enumerator]->Draw("HISTSAME");
    // EfficiencyEtaHist[VTight_New][Enumerator]->SetLineColor(kGreen-1);
    // EfficiencyEtaHist[VTight_New][Enumerator]->Draw("HISTSAME");
    // auto legend3 = new TLegend(.85,.7,1., .9);
    // legend3->AddEntry(EfficiencyEtaHist[VLoose_New][Enumerator], "VLoose");
    // legend3->AddEntry(EfficiencyEtaHist[Loose_New][Enumerator], "Loose");
    // legend3->AddEntry(EfficiencyEtaHist[Medium_New][Enumerator], "Medium");
    // legend3->AddEntry(EfficiencyEtaHist[Tight_New][Enumerator], "Tight");
    // legend3->AddEntry(EfficiencyEtaHist[VTight_New][Enumerator], "VTight");
    // legend3->SetFillStyle(0);
    // legend3->SetBorderSize(0);
    // legend3->Draw();
    // CMS_lumi(c5, 4, 11);
    // c5->SaveAs("/home/liam/Documents/PhD/Results/TauStudy/EWKino/MisID/NewMVATauEwkinoEfficiencyAsFuncOfETA.pdf");
    // delete c5;

    // TCanvas * c6 = new TCanvas("c6, c6");
    // EfficiencyPtHist[VVLoose_Cut][Enumerator]->SetLineColor(kBlack);
    // // EfficiencyPtHist[VVLoose_Cut][Enumerator]->SetTitleOffset(1.);
    // EfficiencyPtHist[VVLoose_Cut][Enumerator]->GetXaxis()->SetNdivisions(508);
    // EfficiencyPtHist[VVLoose_Cut][Enumerator]->SetMaximum(100);
    // EfficiencyPtHist[VVLoose_Cut][Enumerator]->SetMinimum(0);
    // // plottitle = "Efficiency of different cut-based discriminators as a function of the transverse momentum of the lepton; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    // plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    // EfficiencyPtHist[VVLoose_Cut][Enumerator]->SetTitle(plottitle);
    // EfficiencyPtHist[VVLoose_Cut][Enumerator]->Draw("HIST");
    // EfficiencyPtHist[VLoose_Cut][Enumerator]->SetLineColor(kBlue);
    // EfficiencyPtHist[VLoose_Cut][Enumerator]->Draw("HISTSAME");
    // EfficiencyPtHist[Loose_Cut][Enumerator]->SetLineColor(kRed);
    // EfficiencyPtHist[Loose_Cut][Enumerator]->Draw("HISTSAME");
    // EfficiencyPtHist[Medium_Cut][Enumerator]->SetLineColor(kOrange);
    // EfficiencyPtHist[Medium_Cut][Enumerator]->Draw("HISTSAME");
    // EfficiencyPtHist[Tight_Cut][Enumerator]->SetLineColor(kGreen-1);
    // EfficiencyPtHist[Tight_Cut][Enumerator]->Draw("HISTSAME");
    // auto legend12 = new TLegend(.85,.7,1., .9);
    // legend12->AddEntry(EfficiencyPtHist[VVLoose_Cut][Enumerator], "VVLoose");
    // legend12->AddEntry(EfficiencyPtHist[VLoose_Cut][Enumerator], "VLoose");
    // legend12->AddEntry(EfficiencyPtHist[Loose_Cut][Enumerator], "Loose");
    // legend12->AddEntry(EfficiencyPtHist[Medium_Cut][Enumerator], "Medium");
    // legend12->AddEntry(EfficiencyPtHist[Tight_Cut][Enumerator], "Tight");
    // legend12->SetFillStyle(0);
    // legend12->SetBorderSize(0);
    // legend12->Draw();
    // CMS_lumi(c6, 4, 11);
    // c6->SaveAs("/home/liam/Documents/PhD/Results/TauStudy/EWKino/MisID/CUTTauEwkinoEfficiencyAsFuncOfPT.pdf");
    // delete c6;

    // TCanvas * c7 = new TCanvas("c7, c7");
    // EfficiencyEtaHist[VVLoose_Cut][Enumerator]->SetLineColor(kBlack);
    // EfficiencyEtaHist[VVLoose_Cut][Enumerator]->GetXaxis()->SetNdivisions(508);
    // EfficiencyEtaHist[VVLoose_Cut][Enumerator]->SetMaximum(100);
    // EfficiencyEtaHist[VVLoose_Cut][Enumerator]->SetMinimum(0);
    // // plottitle = "Efficiency of different cut-based discriminators as a function of the transverse momentum of the lepton; #eta(#tau) ; Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    // plottitle = "Efficiency of different cut-based discriminators as a function of the transverse momentum of the lepton; #eta(#tau) ; Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    // EfficiencyEtaHist[VVLoose_Cut][Enumerator]->SetTitle(plottitle);
    // EfficiencyEtaHist[VVLoose_Cut][Enumerator]->Draw("HIST");
    // EfficiencyEtaHist[VLoose_Cut][Enumerator]->SetLineColor(kBlue);
    // EfficiencyEtaHist[VLoose_Cut][Enumerator]->Draw("HISTSAME");
    // EfficiencyEtaHist[Loose_Cut][Enumerator]->SetLineColor(kRed);
    // EfficiencyEtaHist[Loose_Cut][Enumerator]->Draw("HISTSAME");
    // EfficiencyEtaHist[Medium_Cut][Enumerator]->SetLineColor(kOrange);
    // EfficiencyEtaHist[Medium_Cut][Enumerator]->Draw("HISTSAME");
    // EfficiencyEtaHist[Tight_Cut][Enumerator]->SetLineColor(kGreen-1);
    // EfficiencyEtaHist[Tight_Cut][Enumerator]->Draw("HISTSAME");
    // auto legend22 = new TLegend(.85,.7,1., .9);
    // legend22->AddEntry(EfficiencyEtaHist[VVLoose_Cut][Enumerator], "VVLoose");
    // legend22->AddEntry(EfficiencyEtaHist[VLoose_Cut][Enumerator], "VLoose");
    // legend22->AddEntry(EfficiencyEtaHist[Loose_Cut][Enumerator], "Loose");
    // legend22->AddEntry(EfficiencyEtaHist[Medium_Cut][Enumerator], "Medium");
    // legend22->AddEntry(EfficiencyEtaHist[Tight_Cut][Enumerator], "Tight");
    // legend22->SetFillStyle(0);
    // legend22->SetBorderSize(0);
    // legend22->Draw();
    // CMS_lumi(c7, 4, 11);
    // c7->SaveAs("/home/liam/Documents/PhD/Results/TauStudy/EWKino/MisID/CUTTauEwkinoEfficiencyAsFuncOfETA.pdf");
    // delete c7;
    
    for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
        delete EfficiencyPtHist[discriminator][Enumerator];
        delete EfficiencyPtHist[discriminator][Denominator];
        delete EfficiencyEtaHist[discriminator][Denominator];
        delete EfficiencyEtaHist[discriminator][Enumerator];
    }

    
//
}

int main(){
    MisIDv2();
}

