#include "Constants.h"
#include "Tools.h"
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
   Tree->SetBranchAddress("_nPsWeights", &_nPsWeights, &b__nPsWeights);
   Tree->SetBranchAddress("_psWeight", _psWeight, &b__psWeight);
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
   Tree->SetBranchAddress("_gen_lPt", _gen_lPt, &b__gen_lPt);
   Tree->SetBranchAddress("_gen_lEta", _gen_lEta, &b__gen_lEta);
   Tree->SetBranchAddress("_gen_lPhi", _gen_lPhi, &b__gen_lPhi);
   Tree->SetBranchAddress("_gen_lE", _gen_lE, &b__gen_lE);
   Tree->SetBranchAddress("_gen_lFlavor", _gen_lFlavor, &b__gen_lFlavor);
   Tree->SetBranchAddress("_gen_lCharge", _gen_lCharge, &b__gen_lCharge);
   Tree->SetBranchAddress("_gen_lMomPdg", _gen_lMomPdg, &b__gen_lMomPdg);
   Tree->SetBranchAddress("_gen_lIsPrompt", _gen_lIsPrompt, &b__gen_lIsPrompt);
   Tree->SetBranchAddress("_gen_lMinDeltaR", _gen_lMinDeltaR, &b__gen_lMinDeltaR);
   Tree->SetBranchAddress("_gen_lPassParentage", _gen_lPassParentage, &b__gen_lPassParentage);
   Tree->SetBranchAddress("_gen_HT", &_gen_HT, &b__gen_HT);
   Tree->SetBranchAddress("_passMETFilters", &_passMETFilters, &b__passMETFilters);
   Tree->SetBranchAddress("_Flag_HBHENoiseFilter", &_Flag_HBHENoiseFilter, &b__Flag_HBHENoiseFilter);
   Tree->SetBranchAddress("_Flag_HBHENoiseIsoFilter", &_Flag_HBHENoiseIsoFilter, &b__Flag_HBHENoiseIsoFilter);
   Tree->SetBranchAddress("_Flag_EcalDeadCellTriggerPrimitiveFilter", &_Flag_EcalDeadCellTriggerPrimitiveFilter, &b__Flag_EcalDeadCellTriggerPrimitiveFilter);
   Tree->SetBranchAddress("_Flag_goodVertices", &_Flag_goodVertices, &b__Flag_goodVertices);
   Tree->SetBranchAddress("_Flag_BadPFMuonFilter", &_Flag_BadPFMuonFilter, &b__Flag_BadPFMuonFilter);
   Tree->SetBranchAddress("_Flag_BadChargedCandidateFilter", &_Flag_BadChargedCandidateFilter, &b__Flag_BadChargedCandidateFilter);
   Tree->SetBranchAddress("_Flag_globalTightHalo2016Filter", &_Flag_globalTightHalo2016Filter, &b__Flag_globalTightHalo2016Filter);
   Tree->SetBranchAddress("_passTrigger_e", &_passTrigger_e, &b__passTrigger_e);
   Tree->SetBranchAddress("_HLT_Ele27_WPTight_Gsf", &_HLT_Ele27_WPTight_Gsf, &b__HLT_Ele27_WPTight_Gsf);
   Tree->SetBranchAddress("_HLT_Ele27_WPTight_Gsf_prescale", &_HLT_Ele27_WPTight_Gsf_prescale, &b__HLT_Ele27_WPTight_Gsf_prescale);
   Tree->SetBranchAddress("_HLT_Ele105_CaloIdVT_GsfTrkIdT", &_HLT_Ele105_CaloIdVT_GsfTrkIdT, &b__HLT_Ele105_CaloIdVT_GsfTrkIdT);
   Tree->SetBranchAddress("_HLT_Ele105_CaloIdVT_GsfTrkIdT_prescale", &_HLT_Ele105_CaloIdVT_GsfTrkIdT_prescale, &b__HLT_Ele105_CaloIdVT_GsfTrkIdT_prescale);
   Tree->SetBranchAddress("_HLT_Ele115_CaloIdVT_GsfTrkIdT", &_HLT_Ele115_CaloIdVT_GsfTrkIdT, &b__HLT_Ele115_CaloIdVT_GsfTrkIdT);
   Tree->SetBranchAddress("_HLT_Ele115_CaloIdVT_GsfTrkIdT_prescale", &_HLT_Ele115_CaloIdVT_GsfTrkIdT_prescale, &b__HLT_Ele115_CaloIdVT_GsfTrkIdT_prescale);
   Tree->SetBranchAddress("_HLT_IsoMu24", &_HLT_IsoMu24, &b__HLT_IsoMu24);
   Tree->SetBranchAddress("_HLT_IsoMu24_prescale", &_HLT_IsoMu24_prescale, &b__HLT_IsoMu24_prescale);
   Tree->SetBranchAddress("_HLT_IsoTkMu24", &_HLT_IsoTkMu24, &b__HLT_IsoTkMu24);
   Tree->SetBranchAddress("_HLT_IsoTkMu24_prescale", &_HLT_IsoTkMu24_prescale, &b__HLT_IsoTkMu24_prescale);
   Tree->SetBranchAddress("_HLT_IsoMu22", &_HLT_IsoMu22, &b__HLT_IsoMu22);
   Tree->SetBranchAddress("_HLT_IsoMu22_prescale", &_HLT_IsoMu22_prescale, &b__HLT_IsoMu22_prescale);
   Tree->SetBranchAddress("_HLT_IsoTkMu22", &_HLT_IsoTkMu22, &b__HLT_IsoTkMu22);
   Tree->SetBranchAddress("_HLT_IsoTkMu22_prescale", &_HLT_IsoTkMu22_prescale, &b__HLT_IsoTkMu22_prescale);
   Tree->SetBranchAddress("_passTrigger_ee", &_passTrigger_ee, &b__passTrigger_ee);
   Tree->SetBranchAddress("_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   Tree->SetBranchAddress("_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   Tree->SetBranchAddress("_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   Tree->SetBranchAddress("_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   Tree->SetBranchAddress("_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL", &_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL, &b__HLT_DoubleEle33_CaloIdL_GsfTrkIdVL);
   Tree->SetBranchAddress("_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale", &_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale, &b__HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_prescale);
   Tree->SetBranchAddress("_passTrigger_eee", &_passTrigger_eee, &b__passTrigger_eee);
   Tree->SetBranchAddress("_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL", &_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL, &b__HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL);
   Tree->SetBranchAddress("_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale", &_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale, &b__HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_prescale);
   Tree->SetBranchAddress("_passTrigger_eem", &_passTrigger_eem, &b__passTrigger_eem);
   Tree->SetBranchAddress("_HLT_Mu8_DiEle12_CaloIdL_TrackIdL", &_HLT_Mu8_DiEle12_CaloIdL_TrackIdL, &b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL);
   Tree->SetBranchAddress("_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale", &_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale, &b__HLT_Mu8_DiEle12_CaloIdL_TrackIdL_prescale);
   Tree->SetBranchAddress("_passTrigger_em", &_passTrigger_em, &b__passTrigger_em);
   Tree->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL", &_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL, &b__HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL);
   Tree->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_prescale", &_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_prescale, &b__HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_prescale);
   Tree->SetBranchAddress("_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   Tree->SetBranchAddress("_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   Tree->SetBranchAddress("_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL", &_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL, &b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
   Tree->SetBranchAddress("_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_prescale", &_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_prescale, &b__HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_prescale);
   Tree->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ", &_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ, &b__HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ);
   Tree->SetBranchAddress("_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_prescale", &_HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_prescale, &b__HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_prescale);
   Tree->SetBranchAddress("_HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL", &_HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL, &b__HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL);
   Tree->SetBranchAddress("_HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_prescale", &_HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_prescale, &b__HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_prescale);
   Tree->SetBranchAddress("_passTrigger_emm", &_passTrigger_emm, &b__passTrigger_emm);
   Tree->SetBranchAddress("_HLT_DiMu9_Ele9_CaloIdL_TrackIdL", &_HLT_DiMu9_Ele9_CaloIdL_TrackIdL, &b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL);
   Tree->SetBranchAddress("_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale", &_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale, &b__HLT_DiMu9_Ele9_CaloIdL_TrackIdL_prescale);
   Tree->SetBranchAddress("_passTrigger_et", &_passTrigger_et, &b__passTrigger_et);
   Tree->SetBranchAddress("_HLT_Ele22_eta2p1_WPLoose_GSF_LooseIsoPFtau20_SingleL1", &_HLT_Ele22_eta2p1_WPLoose_GSF_LooseIsoPFtau20_SingleL1, &b__HLT_Ele22_eta2p1_WPLoose_GSF_LooseIsoPFtau20_SingleL1);
   Tree->SetBranchAddress("_HLT_Ele22_eta2p1_WPLoose_GSF_LooseIsoPFtau20_SingleL1_prescale", &_HLT_Ele22_eta2p1_WPLoose_GSF_LooseIsoPFtau20_SingleL1_prescale, &b__HLT_Ele22_eta2p1_WPLoose_GSF_LooseIsoPFtau20_SingleL1_prescale);
   Tree->SetBranchAddress("_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30", &_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30, &b__HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30);
   Tree->SetBranchAddress("_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_prescale", &_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_prescale, &b__HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30_prescale);
   Tree->SetBranchAddress("_HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1", &_HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1, &b__HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1);
   Tree->SetBranchAddress("_HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_prescale", &_HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_prescale, &b__HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1_prescale);
   Tree->SetBranchAddress("_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20", &_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20, &b__HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20);
   Tree->SetBranchAddress("_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_prescale", &_HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_prescale, &b__HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_prescale);
   Tree->SetBranchAddress("_passTrigger_m", &_passTrigger_m, &b__passTrigger_m);
   Tree->SetBranchAddress("_HLT_Mu50", &_HLT_Mu50, &b__HLT_Mu50);
   Tree->SetBranchAddress("_HLT_Mu50_prescale", &_HLT_Mu50_prescale, &b__HLT_Mu50_prescale);
   Tree->SetBranchAddress("_HLT_TkMu50", &_HLT_TkMu50, &b__HLT_TkMu50);
   Tree->SetBranchAddress("_HLT_TkMu50_prescale", &_HLT_TkMu50_prescale, &b__HLT_TkMu50_prescale);
   Tree->SetBranchAddress("_HLT_Mu45_eta2p1", &_HLT_Mu45_eta2p1, &b__HLT_Mu45_eta2p1);
   Tree->SetBranchAddress("_HLT_Mu45_eta2p1_prescale", &_HLT_Mu45_eta2p1_prescale, &b__HLT_Mu45_eta2p1_prescale);
   Tree->SetBranchAddress("_passTrigger_mm", &_passTrigger_mm, &b__passTrigger_mm);
   Tree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
   Tree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_prescale);
   Tree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ", &_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ, &b__HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ);
   Tree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale", &_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale, &b__HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale);
   Tree->SetBranchAddress("_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ", &_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ, &b__HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ);
   Tree->SetBranchAddress("_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale", &_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale, &b__HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_prescale);
   Tree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
   Tree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale", &_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale, &b__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_prescale);
   Tree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", &_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL, &b__HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL);
   Tree->SetBranchAddress("_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale", &_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale, &b__HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale);
   Tree->SetBranchAddress("_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL", &_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL, &b__HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL);
   Tree->SetBranchAddress("_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale", &_HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale, &b__HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_prescale);
   Tree->SetBranchAddress("_HLT_Mu30_TkMu11", &_HLT_Mu30_TkMu11, &b__HLT_Mu30_TkMu11);
   Tree->SetBranchAddress("_HLT_Mu30_TkMu11_prescale", &_HLT_Mu30_TkMu11_prescale, &b__HLT_Mu30_TkMu11_prescale);
   Tree->SetBranchAddress("_passTrigger_mmm", &_passTrigger_mmm, &b__passTrigger_mmm);
   Tree->SetBranchAddress("_HLT_TripleMu_12_10_5", &_HLT_TripleMu_12_10_5, &b__HLT_TripleMu_12_10_5);
   Tree->SetBranchAddress("_HLT_TripleMu_12_10_5_prescale", &_HLT_TripleMu_12_10_5_prescale, &b__HLT_TripleMu_12_10_5_prescale);
   Tree->SetBranchAddress("_passTrigger_mt", &_passTrigger_mt, &b__passTrigger_mt);
   Tree->SetBranchAddress("_HLT_IsoMu19_eta2p1_LooseIsoPFTau20", &_HLT_IsoMu19_eta2p1_LooseIsoPFTau20, &b__HLT_IsoMu19_eta2p1_LooseIsoPFTau20);
   Tree->SetBranchAddress("_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_prescale", &_HLT_IsoMu19_eta2p1_LooseIsoPFTau20_prescale, &b__HLT_IsoMu19_eta2p1_LooseIsoPFTau20_prescale);
   Tree->SetBranchAddress("_nL", &_nL, &b__nL);
   Tree->SetBranchAddress("_nMu", &_nMu, &b__nMu);
   Tree->SetBranchAddress("_nEle", &_nEle, &b__nEle);
   Tree->SetBranchAddress("_nLight", &_nLight, &b__nLight);
   Tree->SetBranchAddress("_nTau", &_nTau, &b__nTau);
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
   Tree->SetBranchAddress("_lElectronMva", _lElectronMva, &b__lElectronMva);
   Tree->SetBranchAddress("_lElectronMvaHZZ", _lElectronMvaHZZ, &b__lElectronMvaHZZ);
   Tree->SetBranchAddress("_lElectronMvaFall17Iso", _lElectronMvaFall17Iso, &b__lElectronMvaFall17Iso);
   Tree->SetBranchAddress("_lElectronMvaFall17NoIso", _lElectronMvaFall17NoIso, &b__lElectronMvaFall17NoIso);
   Tree->SetBranchAddress("_lElectronPassEmu", _lElectronPassEmu, &b__lElectronPassEmu);
   Tree->SetBranchAddress("_lElectronPassConvVeto", _lElectronPassConvVeto, &b__lElectronPassConvVeto);
   Tree->SetBranchAddress("_lElectronChargeConst", _lElectronChargeConst, &b__lElectronChargeConst);
   Tree->SetBranchAddress("_lElectronMissingHits", _lElectronMissingHits, &b__lElectronMissingHits);
   Tree->SetBranchAddress("_leptonMvaSUSY16", _leptonMvaSUSY16, &b__leptonMvaSUSY16);
   Tree->SetBranchAddress("_leptonMvaTTH16", _leptonMvaTTH16, &b__leptonMvaTTH16);
   Tree->SetBranchAddress("_leptonMvaSUSY17", _leptonMvaSUSY17, &b__leptonMvaSUSY17);
   Tree->SetBranchAddress("_leptonMvaTTH17", _leptonMvaTTH17, &b__leptonMvaTTH17);
   Tree->SetBranchAddress("_leptonMvatZqTTV16", _leptonMvatZqTTV16, &b__leptonMvatZqTTV16);
   Tree->SetBranchAddress("_leptonMvatZqTTV17", _leptonMvatZqTTV17, &b__leptonMvatZqTTV17);
   Tree->SetBranchAddress("_lHNLoose", _lHNLoose, &b__lHNLoose);
   Tree->SetBranchAddress("_lHNFO", _lHNFO, &b__lHNFO);
   Tree->SetBranchAddress("_lHNTight", _lHNTight, &b__lHNTight);
   Tree->SetBranchAddress("_lEwkLoose", _lEwkLoose, &b__lEwkLoose);
   Tree->SetBranchAddress("_lEwkFO", _lEwkFO, &b__lEwkFO);
   Tree->SetBranchAddress("_lEwkTight", _lEwkTight, &b__lEwkTight);
   Tree->SetBranchAddress("_lPOGVeto", _lPOGVeto, &b__lPOGVeto);
   Tree->SetBranchAddress("_lPOGLoose", _lPOGLoose, &b__lPOGLoose);
   Tree->SetBranchAddress("_lPOGMedium", _lPOGMedium, &b__lPOGMedium);
   Tree->SetBranchAddress("_lPOGTight", _lPOGTight, &b__lPOGTight);
   Tree->SetBranchAddress("_lPOGLooseWOIso", _lPOGLooseWOIso, &b__lPOGLooseWOIso);
   Tree->SetBranchAddress("_lPOGMediumWOIso", _lPOGMediumWOIso, &b__lPOGMediumWOIso);
   Tree->SetBranchAddress("_lPOGTightWOIso", _lPOGTightWOIso, &b__lPOGTightWOIso);
   Tree->SetBranchAddress("_tauMuonVeto", _tauMuonVeto, &b__tauMuonVeto);
   Tree->SetBranchAddress("_tauEleVeto", _tauEleVeto, &b__tauEleVeto);
   Tree->SetBranchAddress("_decayModeFindingNew", _decayModeFindingNew, &b__decayModeFindingNew);
   Tree->SetBranchAddress("_tauVLooseMvaNew", _tauVLooseMvaNew, &b__tauVLooseMvaNew);
   Tree->SetBranchAddress("_tauLooseMvaNew", _tauLooseMvaNew, &b__tauLooseMvaNew);
   Tree->SetBranchAddress("_tauMediumMvaNew", _tauMediumMvaNew, &b__tauMediumMvaNew);
   Tree->SetBranchAddress("_tauTightMvaNew", _tauTightMvaNew, &b__tauTightMvaNew);
   Tree->SetBranchAddress("_tauVTightMvaNew", _tauVTightMvaNew, &b__tauVTightMvaNew);
   Tree->SetBranchAddress("_tauVTightMvaOld", _tauVTightMvaOld, &b__tauVTightMvaOld);
   Tree->SetBranchAddress("_tauAgainstElectronMVA6Raw", _tauAgainstElectronMVA6Raw, &b__tauAgainstElectronMVA6Raw);
   Tree->SetBranchAddress("_tauCombinedIsoDBRaw3Hits", _tauCombinedIsoDBRaw3Hits, &b__tauCombinedIsoDBRaw3Hits);
   Tree->SetBranchAddress("_tauIsoMVAPWdR03oldDMwLT", _tauIsoMVAPWdR03oldDMwLT, &b__tauIsoMVAPWdR03oldDMwLT);
   Tree->SetBranchAddress("_tauIsoMVADBdR03oldDMwLT", _tauIsoMVADBdR03oldDMwLT, &b__tauIsoMVADBdR03oldDMwLT);
   Tree->SetBranchAddress("_tauIsoMVADBdR03newDMwLT", _tauIsoMVADBdR03newDMwLT, &b__tauIsoMVADBdR03newDMwLT);
   Tree->SetBranchAddress("_tauIsoMVAPWnewDMwLT", _tauIsoMVAPWnewDMwLT, &b__tauIsoMVAPWnewDMwLT);
   Tree->SetBranchAddress("_tauIsoMVAPWoldDMwLT", _tauIsoMVAPWoldDMwLT, &b__tauIsoMVAPWoldDMwLT);
   Tree->SetBranchAddress("_relIso", _relIso, &b__relIso);
   Tree->SetBranchAddress("_relIso0p4", _relIso0p4, &b__relIso0p4);
   Tree->SetBranchAddress("_relIso0p4MuDeltaBeta", _relIso0p4MuDeltaBeta, &b__relIso0p4MuDeltaBeta);
   Tree->SetBranchAddress("_miniIso", _miniIso, &b__miniIso);
   Tree->SetBranchAddress("_miniIsoCharged", _miniIsoCharged, &b__miniIsoCharged);
   Tree->SetBranchAddress("_ptRel", _ptRel, &b__ptRel);
   Tree->SetBranchAddress("_ptRatio", _ptRatio, &b__ptRatio);
   Tree->SetBranchAddress("_closestJetCsvV2", _closestJetCsvV2, &b__closestJetCsvV2);
   Tree->SetBranchAddress("_closestJetDeepCsv_b", _closestJetDeepCsv_b, &b__closestJetDeepCsv_b);
   Tree->SetBranchAddress("_closestJetDeepCsv_bb", _closestJetDeepCsv_bb, &b__closestJetDeepCsv_bb);
   Tree->SetBranchAddress("_selectedTrackMult", _selectedTrackMult, &b__selectedTrackMult);
   Tree->SetBranchAddress("_lMuonSegComp", _lMuonSegComp, &b__lMuonSegComp);
   Tree->SetBranchAddress("_lMuonTrackPt", _lMuonTrackPt, &b__lMuonTrackPt);
   Tree->SetBranchAddress("_lMuonTrackPtErr", _lMuonTrackPtErr, &b__lMuonTrackPtErr);
   Tree->SetBranchAddress("_lIsPrompt", _lIsPrompt, &b__lIsPrompt);
   Tree->SetBranchAddress("_lMatchPdgId", _lMatchPdgId, &b__lMatchPdgId);
   Tree->SetBranchAddress("_lMomPdgId", _lMomPdgId, &b__lMomPdgId);
   Tree->SetBranchAddress("_lProvenance", _lProvenance, &b__lProvenance);
   Tree->SetBranchAddress("_lProvenanceCompressed", _lProvenanceCompressed, &b__lProvenanceCompressed);
   Tree->SetBranchAddress("_lProvenanceConversion", _lProvenanceConversion, &b__lProvenanceConversion);
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
   Tree->SetBranchAddress("_jetPt_JECDown", _jetPt_JECDown, &b__jetPt_JECDown);
   Tree->SetBranchAddress("_jetPt_JECUp", _jetPt_JECUp, &b__jetPt_JECUp);
   Tree->SetBranchAddress("_jetSmearedPt", _jetSmearedPt, &b__jetSmearedPt);
   Tree->SetBranchAddress("_jetSmearedPt_JECDown", _jetSmearedPt_JECDown, &b__jetSmearedPt_JECDown);
   Tree->SetBranchAddress("_jetSmearedPt_JECUp", _jetSmearedPt_JECUp, &b__jetSmearedPt_JECUp);
   Tree->SetBranchAddress("_jetSmearedPt_JERDown", _jetSmearedPt_JERDown, &b__jetSmearedPt_JERDown);
   Tree->SetBranchAddress("_jetSmearedPt_JERUp", _jetSmearedPt_JERUp, &b__jetSmearedPt_JERUp);
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

void MisID(){
    gROOT->SetBatch(kTRUE);
    gStyle->SetOptStat(0);
    setTDRStyle();
	gStyle->SetPaintTextFormat("4.2f");
    gROOT->ProcessLine( "gErrorIgnoreLevel = 1001;");

    TString FileName = inputFileName();
    SetBranches(FileName);

    Double_t    nentry = Tree->GetEntries();                                //Define variables
    Double_t    nNonPromptTaus = 0;

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

    for(Long64_t entry = 0; entry < nentry; entry++){                               //Loop over all entries
        progress = Progressbar(progress, entry, nentry);                            //Increase progress in progressbar
        Tree->GetEntry(entry);
        
        //Tau selector
        for(int lepton = 0; lepton < _nL; lepton++){                                //Loop over all leptons in event
            
            if(_lFlavor[lepton] != 2)                           continue;
            
            if(_lIsPrompt[lepton])                              continue;

            // if(_lMatchPdgId[lepton] != 0)                       continue;
            // cout << _lMatchPdgId[lepton] << " " << entry << endl;

            nNonPromptTaus++;                                                                          //NonPromptTau Count
            for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
                EfficiencyPtHist[discriminator][Denominator]->Fill(_lPt[lepton]);  
                EfficiencyEtaHist[discriminator][Denominator]->Fill(_lEta[lepton]);                 
            }

            if(!_decayModeFindingNew[lepton])                   continue;                       //New tau decay mode finding

            // if(_tauCombinedIsoDBRaw3Hits[lepton] > 2.0)         continue;                       //Loose Isolation cut                       
            
            if(!_tauMuonVeto[lepton])                           continue;
            if(!_tauEleVeto[lepton])                            continue;


            for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
                if(discriminator == VLoose_Old and _lPOGVeto[lepton]){                  EfficiencyHistMVA->AddBinContent(1); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}                 //Old tau ID
                if(discriminator == Loose_Old and _lPOGLoose[lepton]){                  EfficiencyHistMVA->AddBinContent(2); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
                if(discriminator == Medium_Old and _lPOGMedium[lepton]){                EfficiencyHistMVA->AddBinContent(3); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
                if(discriminator == Tight_Old and _lPOGTight[lepton]){                  EfficiencyHistMVA->AddBinContent(4); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
                if(discriminator == VTight_Old and _tauVTightMvaOld[lepton]){           EfficiencyHistMVA->AddBinContent(5); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}

                if(discriminator == VLoose_New and _tauVLooseMvaNew[lepton]){           EfficiencyHistMVA->AddBinContent(6); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}                    //New tau ID
                if(discriminator == Loose_New and _tauLooseMvaNew[lepton]){             EfficiencyHistMVA->AddBinContent(7); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
                if(discriminator == Medium_New and _tauMediumMvaNew[lepton]){           EfficiencyHistMVA->AddBinContent(8); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
                if(discriminator == Tight_New and _tauTightMvaNew[lepton]){             EfficiencyHistMVA->AddBinContent(9); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
                if(discriminator == VTight_New and _tauVTightMvaNew[lepton]){           EfficiencyHistMVA->AddBinContent(10); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
                
                if(discriminator == VVLoose_Cut and _tauCombinedIsoDBRaw3Hits[lepton] < 4.5){              EfficiencyHistCuts->AddBinContent(1); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}                    //Cut-based
                if(discriminator == VLoose_Cut and _tauCombinedIsoDBRaw3Hits[lepton] < 3.5){               EfficiencyHistCuts->AddBinContent(2); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
                if(discriminator == Loose_Cut and _tauCombinedIsoDBRaw3Hits[lepton] < 2.0){                EfficiencyHistCuts->AddBinContent(3); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
                if(discriminator == Medium_Cut and _tauCombinedIsoDBRaw3Hits[lepton] < 1.0){               EfficiencyHistCuts->AddBinContent(4); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
                if(discriminator == Tight_Cut and _tauCombinedIsoDBRaw3Hits[lepton] < 0.8){                EfficiencyHistCuts->AddBinContent(5); EfficiencyPtHist[discriminator][Enumerator]->Fill(_lPt[lepton]); EfficiencyEtaHist[discriminator][Enumerator]->Fill(_lEta[lepton]);}
            
            }
        
        }

    }

cout << nNonPromptTaus << endl;

    EfficiencyHistMVA->Scale(100./nNonPromptTaus);
    EfficiencyHistCuts->Scale(100./nNonPromptTaus);
    for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
        EfficiencyPtHist[discriminator][Enumerator]->Divide(EfficiencyPtHist[discriminator][Denominator]);
        EfficiencyPtHist[discriminator][Enumerator]->Scale(100.);
        EfficiencyEtaHist[discriminator][Enumerator]->Divide(EfficiencyEtaHist[discriminator][Denominator]);
        EfficiencyEtaHist[discriminator][Enumerator]->Scale(100.);
    }

//Draw

    for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
        EfficiencyPtHist[discriminator][Enumerator]->SetMarkerStyle(0);
        EfficiencyEtaHist[discriminator][Enumerator]->SetMarkerStyle(0);
    }
    

    TCanvas * c1 = new TCanvas("c1, c1");                           
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
    EfficiencyHistMVA->SetMinimum(0);
    EfficiencyHistMVA->SetMaximum(100);
    EfficiencyHistMVA->Draw("EHISTTEXT");
    // CMS_lumi(c1, 4, 1);
    c1->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/"+FileName+"/MisID/TauEwkinoEfficiencyMVA.pdf");
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
    c12->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/"+FileName+"/MisID/TauEwkinoEfficiencyCuts.pdf");
    delete c12;
    delete EfficiencyHistCuts;

    TCanvas * c2 = new TCanvas("c2, c2");
    EfficiencyPtHist[VLoose_Old][Enumerator]->SetLineColor(kBlack);
    EfficiencyPtHist[VLoose_Old][Enumerator]->GetXaxis()->SetNdivisions(508);
    EfficiencyPtHist[VLoose_Old][Enumerator]->SetMinimum(0);
    EfficiencyPtHist[VLoose_Old][Enumerator]->SetMaximum(100);
    // TString plottitle = "Efficiency of different old discriminators as a function of the transverse momentum of the lepton; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    TString plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    EfficiencyPtHist[VLoose_Old][Enumerator]->SetTitle(plottitle);
    EfficiencyPtHist[VLoose_Old][Enumerator]->Draw("HIST");
    EfficiencyPtHist[Loose_Old][Enumerator]->SetLineColor(kBlue);
    EfficiencyPtHist[Loose_Old][Enumerator]->Draw("HISTSAME");
    EfficiencyPtHist[Medium_Old][Enumerator]->SetLineColor(kRed);
    EfficiencyPtHist[Medium_Old][Enumerator]->Draw("HISTSAME");
    EfficiencyPtHist[Tight_Old][Enumerator]->SetLineColor(kOrange);
    EfficiencyPtHist[Tight_Old][Enumerator]->Draw("HISTSAME");
    EfficiencyPtHist[VTight_Old][Enumerator]->SetLineColor(kGreen-1);
    EfficiencyPtHist[VTight_Old][Enumerator]->Draw("HISTSAME");
    auto legend = new TLegend(.85,.7,1., .9);
    legend->AddEntry(EfficiencyPtHist[VLoose_Old][Enumerator], "VLoose");
    legend->AddEntry(EfficiencyPtHist[Loose_Old][Enumerator], "Loose");
    legend->AddEntry(EfficiencyPtHist[Medium_Old][Enumerator], "Medium");
    legend->AddEntry(EfficiencyPtHist[Tight_Old][Enumerator], "Tight");
    legend->AddEntry(EfficiencyPtHist[VTight_Old][Enumerator], "VTight");
    legend->SetFillStyle(0);
    legend->SetBorderSize(0);
    legend->Draw();
    CMS_lumi(c2, 4, 11);
    c2->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/"+FileName+"/MisID/OldMVATauEwkinoEfficiencyAsFuncOfPT.pdf");
    delete c2;

    TCanvas * c3 = new TCanvas("c3, c3");
    EfficiencyPtHist[VLoose_New][Enumerator]->SetLineColor(kBlack);
    EfficiencyPtHist[VLoose_New][Enumerator]->GetXaxis()->SetNdivisions(508);
    EfficiencyPtHist[VLoose_New][Enumerator]->SetMinimum(0);
    EfficiencyPtHist[VLoose_New][Enumerator]->SetMaximum(100);
    // plottitle = "Efficiency of different new discriminators as a function of the transverse momentum of the lepton; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    EfficiencyPtHist[VLoose_New][Enumerator]->SetTitle(plottitle);
    EfficiencyPtHist[VLoose_New][Enumerator]->Draw("HIST");
    EfficiencyPtHist[Loose_New][Enumerator]->SetLineColor(kBlue);
    EfficiencyPtHist[Loose_New][Enumerator]->Draw("HISTSAME");
    EfficiencyPtHist[Medium_New][Enumerator]->SetLineColor(kRed);
    EfficiencyPtHist[Medium_New][Enumerator]->Draw("HISTSAME");
    EfficiencyPtHist[Tight_New][Enumerator]->SetLineColor(kOrange);
    EfficiencyPtHist[Tight_New][Enumerator]->Draw("HISTSAME");
    EfficiencyPtHist[VTight_New][Enumerator]->SetLineColor(kGreen-1);
    EfficiencyPtHist[VTight_New][Enumerator]->Draw("HISTSAME");
    auto legend1 = new TLegend(.85,.7,1., .9);
    legend1->AddEntry(EfficiencyPtHist[VLoose_New][Enumerator], "VLoose");
    legend1->AddEntry(EfficiencyPtHist[Loose_New][Enumerator], "Loose");
    legend1->AddEntry(EfficiencyPtHist[Medium_New][Enumerator], "Medium");
    legend1->AddEntry(EfficiencyPtHist[Tight_New][Enumerator], "Tight");
    legend1->AddEntry(EfficiencyPtHist[VTight_New][Enumerator], "VTight");
    legend1->SetFillStyle(0);
    legend1->SetBorderSize(0);
    legend1->Draw();
    CMS_lumi(c3, 4, 11);
    c3->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/"+FileName+"/MisID/NewMVATauEwkinoEfficiencyAsFuncOfPT.pdf");
    delete c3;

    TCanvas * c4 = new TCanvas("c4, c4");
    EfficiencyEtaHist[VLoose_Old][Enumerator]->SetLineColor(kBlack);
    EfficiencyEtaHist[VLoose_Old][Enumerator]->GetXaxis()->SetNdivisions(508);
    EfficiencyEtaHist[VLoose_Old][Enumerator]->SetMaximum(100);
    EfficiencyEtaHist[VLoose_Old][Enumerator]->SetMinimum(0);
    // plottitle = "Efficiency of different old discriminators as a function of the pseudorapidity of the lepton; #eta(#tau); Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 1);
    plottitle = "; #eta(#tau); Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 1);
    EfficiencyEtaHist[VLoose_Old][Enumerator]->SetTitle(plottitle);
    EfficiencyEtaHist[VLoose_Old][Enumerator]->Draw("HIST");
    EfficiencyEtaHist[Loose_Old][Enumerator]->SetLineColor(kBlue);
    EfficiencyEtaHist[Loose_Old][Enumerator]->Draw("HISTSAME");
    EfficiencyEtaHist[Medium_Old][Enumerator]->SetLineColor(kRed);
    EfficiencyEtaHist[Medium_Old][Enumerator]->Draw("HISTSAME");
    EfficiencyEtaHist[Tight_Old][Enumerator]->SetLineColor(kOrange);
    EfficiencyEtaHist[Tight_Old][Enumerator]->Draw("HISTSAME");
    EfficiencyEtaHist[VTight_Old][Enumerator]->SetLineColor(kGreen-1);
    EfficiencyEtaHist[VTight_Old][Enumerator]->Draw("HISTSAME");
    auto legend2 = new TLegend(.85,.7,1., .9);
    legend2->AddEntry(EfficiencyEtaHist[VLoose_Old][Enumerator], "VLoose");
    legend2->AddEntry(EfficiencyEtaHist[Loose_Old][Enumerator], "Loose");
    legend2->AddEntry(EfficiencyEtaHist[Medium_Old][Enumerator], "Medium");
    legend2->AddEntry(EfficiencyEtaHist[Tight_Old][Enumerator], "Tight");
    legend2->AddEntry(EfficiencyEtaHist[VTight_Old][Enumerator], "VTight");
    legend2->SetFillStyle(0);
    legend2->SetBorderSize(0);
    legend2->Draw();
    CMS_lumi(c4, 4, 11);
    c4->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/"+FileName+"/MisID/OldMVATauEwkinoEfficiencyAsFuncOfETA.pdf");
    delete c4;

    TCanvas * c5 = new TCanvas("c5, c5");
    EfficiencyEtaHist[VLoose_New][Enumerator]->SetLineColor(kBlack);
    EfficiencyEtaHist[VLoose_New][Enumerator]->GetXaxis()->SetNdivisions(508);
    EfficiencyEtaHist[VLoose_New][Enumerator]->SetMaximum(100);
    EfficiencyEtaHist[VLoose_New][Enumerator]->SetMinimum(0);
    plottitle = "; #eta(#tau); Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 1);
    // plottitle = "Efficiency of different new discriminators as a function of the pseudorapidity of the lepton; #eta(#tau); Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 1);
    EfficiencyEtaHist[VLoose_New][Enumerator]->SetTitle(plottitle);
    EfficiencyEtaHist[VLoose_New][Enumerator]->Draw("HIST");
    EfficiencyEtaHist[Loose_New][Enumerator]->SetLineColor(kBlue);
    EfficiencyEtaHist[Loose_New][Enumerator]->Draw("HISTSAME");
    EfficiencyEtaHist[Medium_New][Enumerator]->SetLineColor(kRed);
    EfficiencyEtaHist[Medium_New][Enumerator]->Draw("HISTSAME");
    EfficiencyEtaHist[Tight_New][Enumerator]->SetLineColor(kOrange);
    EfficiencyEtaHist[Tight_New][Enumerator]->Draw("HISTSAME");
    EfficiencyEtaHist[VTight_New][Enumerator]->SetLineColor(kGreen-1);
    EfficiencyEtaHist[VTight_New][Enumerator]->Draw("HISTSAME");
    auto legend3 = new TLegend(.85,.7,1., .9);
    legend3->AddEntry(EfficiencyEtaHist[VLoose_New][Enumerator], "VLoose");
    legend3->AddEntry(EfficiencyEtaHist[Loose_New][Enumerator], "Loose");
    legend3->AddEntry(EfficiencyEtaHist[Medium_New][Enumerator], "Medium");
    legend3->AddEntry(EfficiencyEtaHist[Tight_New][Enumerator], "Tight");
    legend3->AddEntry(EfficiencyEtaHist[VTight_New][Enumerator], "VTight");
    legend3->SetFillStyle(0);
    legend3->SetBorderSize(0);
    legend3->Draw();
    CMS_lumi(c5, 4, 11);
    c5->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/"+FileName+"/MisID/NewMVATauEwkinoEfficiencyAsFuncOfETA.pdf");
    delete c5;

    TCanvas * c6 = new TCanvas("c6, c6");
    EfficiencyPtHist[VVLoose_Cut][Enumerator]->SetLineColor(kBlack);
    // EfficiencyPtHist[VVLoose_Cut][Enumerator]->SetTitleOffset(1.);
    EfficiencyPtHist[VVLoose_Cut][Enumerator]->GetXaxis()->SetNdivisions(508);
    EfficiencyPtHist[VVLoose_Cut][Enumerator]->SetMaximum(100);
    EfficiencyPtHist[VVLoose_Cut][Enumerator]->SetMinimum(0);
    // plottitle = "Efficiency of different cut-based discriminators as a function of the transverse momentum of the lepton; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    EfficiencyPtHist[VVLoose_Cut][Enumerator]->SetTitle(plottitle);
    EfficiencyPtHist[VVLoose_Cut][Enumerator]->Draw("HIST");
    EfficiencyPtHist[VLoose_Cut][Enumerator]->SetLineColor(kBlue);
    EfficiencyPtHist[VLoose_Cut][Enumerator]->Draw("HISTSAME");
    EfficiencyPtHist[Loose_Cut][Enumerator]->SetLineColor(kRed);
    EfficiencyPtHist[Loose_Cut][Enumerator]->Draw("HISTSAME");
    EfficiencyPtHist[Medium_Cut][Enumerator]->SetLineColor(kOrange);
    EfficiencyPtHist[Medium_Cut][Enumerator]->Draw("HISTSAME");
    EfficiencyPtHist[Tight_Cut][Enumerator]->SetLineColor(kGreen-1);
    EfficiencyPtHist[Tight_Cut][Enumerator]->Draw("HISTSAME");
    auto legend12 = new TLegend(.85,.7,1., .9);
    legend12->AddEntry(EfficiencyPtHist[VVLoose_Cut][Enumerator], "VVLoose");
    legend12->AddEntry(EfficiencyPtHist[VLoose_Cut][Enumerator], "VLoose");
    legend12->AddEntry(EfficiencyPtHist[Loose_Cut][Enumerator], "Loose");
    legend12->AddEntry(EfficiencyPtHist[Medium_Cut][Enumerator], "Medium");
    legend12->AddEntry(EfficiencyPtHist[Tight_Cut][Enumerator], "Tight");
    legend12->SetFillStyle(0);
    legend12->SetBorderSize(0);
    legend12->Draw();
    CMS_lumi(c6, 4, 11);
    c6->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/"+FileName+"/MisID/CUTTauEwkinoEfficiencyAsFuncOfPT.pdf");
    delete c6;

    TCanvas * c7 = new TCanvas("c7, c7");
    EfficiencyEtaHist[VVLoose_Cut][Enumerator]->SetLineColor(kBlack);
    EfficiencyEtaHist[VVLoose_Cut][Enumerator]->GetXaxis()->SetNdivisions(508);
    EfficiencyEtaHist[VVLoose_Cut][Enumerator]->SetMaximum(100);
    EfficiencyEtaHist[VVLoose_Cut][Enumerator]->SetMinimum(0);
    // plottitle = "Efficiency of different cut-based discriminators as a function of the transverse momentum of the lepton; #eta(#tau) ; Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    plottitle = "Efficiency of different cut-based discriminators as a function of the transverse momentum of the lepton; #eta(#tau) ; Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHist[VLoose_Old][Enumerator]->GetBinWidth(1), 2) + "GeV";
    EfficiencyEtaHist[VVLoose_Cut][Enumerator]->SetTitle(plottitle);
    EfficiencyEtaHist[VVLoose_Cut][Enumerator]->Draw("HIST");
    EfficiencyEtaHist[VLoose_Cut][Enumerator]->SetLineColor(kBlue);
    EfficiencyEtaHist[VLoose_Cut][Enumerator]->Draw("HISTSAME");
    EfficiencyEtaHist[Loose_Cut][Enumerator]->SetLineColor(kRed);
    EfficiencyEtaHist[Loose_Cut][Enumerator]->Draw("HISTSAME");
    EfficiencyEtaHist[Medium_Cut][Enumerator]->SetLineColor(kOrange);
    EfficiencyEtaHist[Medium_Cut][Enumerator]->Draw("HISTSAME");
    EfficiencyEtaHist[Tight_Cut][Enumerator]->SetLineColor(kGreen-1);
    EfficiencyEtaHist[Tight_Cut][Enumerator]->Draw("HISTSAME");
    auto legend22 = new TLegend(.85,.7,1., .9);
    legend22->AddEntry(EfficiencyEtaHist[VVLoose_Cut][Enumerator], "VVLoose");
    legend22->AddEntry(EfficiencyEtaHist[VLoose_Cut][Enumerator], "VLoose");
    legend22->AddEntry(EfficiencyEtaHist[Loose_Cut][Enumerator], "Loose");
    legend22->AddEntry(EfficiencyEtaHist[Medium_Cut][Enumerator], "Medium");
    legend22->AddEntry(EfficiencyEtaHist[Tight_Cut][Enumerator], "Tight");
    legend22->SetFillStyle(0);
    legend22->SetBorderSize(0);
    legend22->Draw();
    CMS_lumi(c7, 4, 11);
    c7->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/"+FileName+"/MisID/CUTTauEwkinoEfficiencyAsFuncOfETA.pdf");
    delete c7;
    
    for(int discriminator = 0; discriminator < NumberOfDiscr; discriminator++){
        delete EfficiencyPtHist[discriminator][Enumerator];
        delete EfficiencyPtHist[discriminator][Denominator];
        delete EfficiencyEtaHist[discriminator][Denominator];
        delete EfficiencyEtaHist[discriminator][Enumerator];
    }
//
}

int main(){
    MisID();
}

