#include "Constants.h"
// #include "Tools.h"
#include "/user/lwezenbe/private/PhD/Code/CMS_lumi/CMS_lumi.C"
#include "/user/lwezenbe/private/PhD/Code/CMS_lumi/tdrstyle.C"

void SetBranches(TString FileName, bool ch){
    chain = new TChain("blackJackAndHookers/blackJackAndHookersTree");
    if(ch){      chain->Add(FileName+"*.root");
    } else {    chain->Add(FileName+".root");
    }

    chain->SetBranchAddress("_runNb", &_runNb, &b__runNb);
    chain->SetBranchAddress("_lumiBlock", &_lumiBlock, &b__lumiBlock);
    chain->SetBranchAddress("_eventNb", &_eventNb, &b__eventNb);
    chain->SetBranchAddress("_nVertex", &_nVertex, &b__nVertex);
    chain->SetBranchAddress("_nTrueInt", &_nTrueInt, &b__nTrueInt);
    chain->SetBranchAddress("_weight", &_weight, &b__weight);
    chain->SetBranchAddress("_nLheWeights", &_nLheWeights, &b__nLheWeights);
    chain->SetBranchAddress("_lheWeight", _lheWeight, &b__lheWeight);
    chain->SetBranchAddress("_ttgEventType", &_ttgEventType, &b__ttgEventType);
    chain->SetBranchAddress("_zgEventType", &_zgEventType, &b__zgEventType);
    chain->SetBranchAddress("_gen_met", &_gen_met, &b__gen_met);
    chain->SetBranchAddress("_gen_metPhi", &_gen_metPhi, &b__gen_metPhi);
    chain->SetBranchAddress("_gen_nL", &_gen_nL, &b__gen_nL);
    chain->SetBranchAddress("_gen_lPt", _gen_lPt, &b__gen_lPt);
    chain->SetBranchAddress("_gen_lEta", _gen_lEta, &b__gen_lEta);
    chain->SetBranchAddress("_gen_lPhi", _gen_lPhi, &b__gen_lPhi);
    chain->SetBranchAddress("_gen_lE", _gen_lE, &b__gen_lE);
    chain->SetBranchAddress("_gen_lFlavor", _gen_lFlavor, &b__gen_lFlavor);
    chain->SetBranchAddress("_gen_lCharge", _gen_lCharge, &b__gen_lCharge);
    chain->SetBranchAddress("_gen_lMomPdg", _gen_lMomPdg, &b__gen_lMomPdg);
    chain->SetBranchAddress("_gen_lIsPrompt", _gen_lIsPrompt, &b__gen_lIsPrompt);
    chain->SetBranchAddress("_gen_HT", &_gen_HT, &b__gen_HT);
    chain->SetBranchAddress("_passMETFilters", &_passMETFilters, &b__passMETFilters);
    chain->SetBranchAddress("_nL", &_nL, &b__nL);
    chain->SetBranchAddress("_nMu", &_nMu, &b__nMu);
    chain->SetBranchAddress("_nEle", &_nEle, &b__nEle);
    chain->SetBranchAddress("_nLight", &_nLight, &b__nLight);
    chain->SetBranchAddress("_nTau", &_nTau, &b__nTau);
    chain->SetBranchAddress("_lPt", _lPt, &b__lPt);
    chain->SetBranchAddress("_lEta", _lEta, &b__lEta);
    chain->SetBranchAddress("_lEtaSC", _lEtaSC, &b__lEtaSC);
    chain->SetBranchAddress("_lPhi", _lPhi, &b__lPhi);
    chain->SetBranchAddress("_lE", _lE, &b__lE);
    chain->SetBranchAddress("_lFlavor", _lFlavor, &b__lFlavor);
    chain->SetBranchAddress("_lCharge", _lCharge, &b__lCharge);
    chain->SetBranchAddress("_dxy", _dxy, &b__dxy);
    chain->SetBranchAddress("_dz", _dz, &b__dz);
    chain->SetBranchAddress("_3dIP", _3dIP, &b__3dIP);
    chain->SetBranchAddress("_3dIPSig", _3dIPSig, &b__3dIPSig);
    chain->SetBranchAddress("_lElectronMva", _lElectronMva, &b__lElectronMva);
    chain->SetBranchAddress("_lElectronMvaHZZ", _lElectronMvaHZZ, &b__lElectronMvaHZZ);
    chain->SetBranchAddress("_lElectronMvaFall17Iso", _lElectronMvaFall17Iso, &b__lElectronMvaFall17Iso);
    chain->SetBranchAddress("_lElectronMvaFall17NoIso", _lElectronMvaFall17NoIso, &b__lElectronMvaFall17NoIso);
    chain->SetBranchAddress("_lElectronPassEmu", _lElectronPassEmu, &b__lElectronPassEmu);
    chain->SetBranchAddress("_lElectronPassConvVeto", _lElectronPassConvVeto, &b__lElectronPassConvVeto);
    chain->SetBranchAddress("_lElectronChargeConst", _lElectronChargeConst, &b__lElectronChargeConst);
    chain->SetBranchAddress("_lElectronMissingHits", _lElectronMissingHits, &b__lElectronMissingHits);
    chain->SetBranchAddress("_leptonMvaSUSY16", _leptonMvaSUSY16, &b__leptonMvaSUSY16);
    chain->SetBranchAddress("_leptonMvaTTH16", _leptonMvaTTH16, &b__leptonMvaTTH16);
    chain->SetBranchAddress("_leptonMvaSUSY17", _leptonMvaSUSY17, &b__leptonMvaSUSY17);
    chain->SetBranchAddress("_leptonMvaTTH17", _leptonMvaTTH17, &b__leptonMvaTTH17);
    chain->SetBranchAddress("_leptonMvatZqTTV16", _leptonMvatZqTTV16, &b__leptonMvatZqTTV16);
    chain->SetBranchAddress("_leptonMvatZqTTV17", _leptonMvatZqTTV17, &b__leptonMvatZqTTV17);
    chain->SetBranchAddress("_lHNLoose", _lHNLoose, &b__lHNLoose);
    chain->SetBranchAddress("_lHNFO", _lHNFO, &b__lHNFO);
    chain->SetBranchAddress("_lHNTight", _lHNTight, &b__lHNTight);
    chain->SetBranchAddress("_lEwkLoose", _lEwkLoose, &b__lEwkLoose);
    chain->SetBranchAddress("_lEwkFO", _lEwkFO, &b__lEwkFO);
    chain->SetBranchAddress("_lEwkTight", _lEwkTight, &b__lEwkTight);
    chain->SetBranchAddress("_lPOGVeto", _lPOGVeto, &b__lPOGVeto);
    chain->SetBranchAddress("_lPOGLoose", _lPOGLoose, &b__lPOGLoose);
    chain->SetBranchAddress("_lPOGMedium", _lPOGMedium, &b__lPOGMedium);
    chain->SetBranchAddress("_lPOGTight", _lPOGTight, &b__lPOGTight);
    chain->SetBranchAddress("_tauMuonVeto", _tauMuonVeto, &b__tauMuonVeto);
    chain->SetBranchAddress("_tauEleVeto", _tauEleVeto, &b__tauEleVeto);
    chain->SetBranchAddress("_tauDecayMode", _tauDecayMode, &b__tauDecayMode);
    chain->SetBranchAddress("_decayModeFinding", _decayModeFinding, &b__decayModeFinding);
    chain->SetBranchAddress("_decayModeFindingNew", _decayModeFindingNew, &b__decayModeFindingNew);
    chain->SetBranchAddress("_tauVLooseMvaNew", _tauVLooseMvaNew, &b__tauVLooseMvaNew);
    chain->SetBranchAddress("_tauLooseMvaNew", _tauLooseMvaNew, &b__tauLooseMvaNew);
    chain->SetBranchAddress("_tauMediumMvaNew", _tauMediumMvaNew, &b__tauMediumMvaNew);
    chain->SetBranchAddress("_tauTightMvaNew", _tauTightMvaNew, &b__tauTightMvaNew);
    chain->SetBranchAddress("_tauVTightMvaNew", _tauVTightMvaNew, &b__tauVTightMvaNew);
    chain->SetBranchAddress("_tauVTightMvaOld", _tauVTightMvaOld, &b__tauVTightMvaOld);
    chain->SetBranchAddress("_tauAgainstElectronMVA6Raw", _tauAgainstElectronMVA6Raw, &b__tauAgainstElectronMVA6Raw);
    chain->SetBranchAddress("_tauCombinedIsoDBRaw3Hits", _tauCombinedIsoDBRaw3Hits, &b__tauCombinedIsoDBRaw3Hits);
    chain->SetBranchAddress("_tauIsoMVAPWdR03oldDMwLT", _tauIsoMVAPWdR03oldDMwLT, &b__tauIsoMVAPWdR03oldDMwLT);
    chain->SetBranchAddress("_tauIsoMVADBdR03oldDMwLT", _tauIsoMVADBdR03oldDMwLT, &b__tauIsoMVADBdR03oldDMwLT);
    chain->SetBranchAddress("_tauIsoMVADBdR03newDMwLT", _tauIsoMVADBdR03newDMwLT, &b__tauIsoMVADBdR03newDMwLT);
    chain->SetBranchAddress("_tauIsoMVAPWnewDMwLT", _tauIsoMVAPWnewDMwLT, &b__tauIsoMVAPWnewDMwLT);
    chain->SetBranchAddress("_tauIsoMVAPWoldDMwLT", _tauIsoMVAPWoldDMwLT, &b__tauIsoMVAPWoldDMwLT);
    chain->SetBranchAddress("_relIso", _relIso, &b__relIso);
    chain->SetBranchAddress("_relIso0p4", _relIso0p4, &b__relIso0p4);
    chain->SetBranchAddress("_relIso0p4MuDeltaBeta", _relIso0p4MuDeltaBeta, &b__relIso0p4MuDeltaBeta);
    chain->SetBranchAddress("_miniIso", _miniIso, &b__miniIso);
    chain->SetBranchAddress("_miniIsoCharged", _miniIsoCharged, &b__miniIsoCharged);
    chain->SetBranchAddress("_ptRel", _ptRel, &b__ptRel);
    chain->SetBranchAddress("_ptRatio", _ptRatio, &b__ptRatio);
    chain->SetBranchAddress("_closestJetCsvV2", _closestJetCsvV2, &b__closestJetCsvV2);
    chain->SetBranchAddress("_closestJetDeepCsv_b", _closestJetDeepCsv_b, &b__closestJetDeepCsv_b);
    chain->SetBranchAddress("_closestJetDeepCsv_bb", _closestJetDeepCsv_bb, &b__closestJetDeepCsv_bb);
    chain->SetBranchAddress("_selectedTrackMult", _selectedTrackMult, &b__selectedTrackMult);
    chain->SetBranchAddress("_lMuonSegComp", _lMuonSegComp, &b__lMuonSegComp);
    chain->SetBranchAddress("_lMuonTrackPt", _lMuonTrackPt, &b__lMuonTrackPt);
    chain->SetBranchAddress("_lMuonTrackPtErr", _lMuonTrackPtErr, &b__lMuonTrackPtErr);
    chain->SetBranchAddress("_lIsPrompt", _lIsPrompt, &b__lIsPrompt);
    chain->SetBranchAddress("_lMatchPdgId", _lMatchPdgId, &b__lMatchPdgId);
    chain->SetBranchAddress("_lMomPdgId", _lMomPdgId, &b__lMomPdgId);
    chain->SetBranchAddress("_lProvenance", _lProvenance, &b__lProvenance);
    chain->SetBranchAddress("_lProvenanceCompressed", _lProvenanceCompressed, &b__lProvenanceCompressed);
    chain->SetBranchAddress("_lProvenanceConversion", _lProvenanceConversion, &b__lProvenanceConversion);
    chain->SetBranchAddress("_nJets", &_nJets, &b__nJets);
    chain->SetBranchAddress("_jetPt", _jetPt, &b__jetPt);
    chain->SetBranchAddress("_jetPt_JECDown", _jetPt_JECDown, &b__jetPt_JECDown);
    chain->SetBranchAddress("_jetPt_JECUp", _jetPt_JECUp, &b__jetPt_JECUp);
    chain->SetBranchAddress("_jetPt_L1", _jetPt_L1, &b__jetPt_L1);
    chain->SetBranchAddress("_jetPt_L2", _jetPt_L2, &b__jetPt_L2);
    chain->SetBranchAddress("_jetPt_L3", _jetPt_L3, &b__jetPt_L3);
    chain->SetBranchAddress("_jetEta", _jetEta, &b__jetEta);
    chain->SetBranchAddress("_jetPhi", _jetPhi, &b__jetPhi);
    chain->SetBranchAddress("_jetE", _jetE, &b__jetE);
    chain->SetBranchAddress("_jetCsvV2", _jetCsvV2, &b__jetCsvV2);
    chain->SetBranchAddress("_jetDeepCsv_udsg", _jetDeepCsv_udsg, &b__jetDeepCsv_udsg);
    chain->SetBranchAddress("_jetDeepCsv_b", _jetDeepCsv_b, &b__jetDeepCsv_b);
    chain->SetBranchAddress("_jetDeepCsv_c", _jetDeepCsv_c, &b__jetDeepCsv_c);
    chain->SetBranchAddress("_jetDeepCsv_bb", _jetDeepCsv_bb, &b__jetDeepCsv_bb);
    chain->SetBranchAddress("_jetHadronFlavor", _jetHadronFlavor, &b__jetHadronFlavor);
    chain->SetBranchAddress("_jetIsLoose", _jetIsLoose, &b__jetIsLoose);
    chain->SetBranchAddress("_jetIsTight", _jetIsTight, &b__jetIsTight);
    chain->SetBranchAddress("_jetIsTightLepVeto", _jetIsTightLepVeto, &b__jetIsTightLepVeto);
    chain->SetBranchAddress("_jetNeutralHadronFraction", _jetNeutralHadronFraction, &b__jetNeutralHadronFraction);
    chain->SetBranchAddress("_jetChargedHadronFraction", _jetChargedHadronFraction, &b__jetChargedHadronFraction);
    chain->SetBranchAddress("_jetNeutralEmFraction", _jetNeutralEmFraction, &b__jetNeutralEmFraction);
    chain->SetBranchAddress("_jetChargedEmFraction", _jetChargedEmFraction, &b__jetChargedEmFraction);
    chain->SetBranchAddress("_jetHFHadronFraction", _jetHFHadronFraction, &b__jetHFHadronFraction);
    chain->SetBranchAddress("_jetHFEmFraction", _jetHFEmFraction, &b__jetHFEmFraction);
    chain->SetBranchAddress("_met", &_met, &b__met);
    chain->SetBranchAddress("_metJECDown", &_metJECDown, &b__metJECDown);
    chain->SetBranchAddress("_metJECUp", &_metJECUp, &b__metJECUp);
    chain->SetBranchAddress("_metUnclDown", &_metUnclDown, &b__metUnclDown);
    chain->SetBranchAddress("_metUnclUp", &_metUnclUp, &b__metUnclUp);
    chain->SetBranchAddress("_metPhi", &_metPhi, &b__metPhi);
    chain->SetBranchAddress("_metPhiJECDown", &_metPhiJECDown, &b__metPhiJECDown);
    chain->SetBranchAddress("_metPhiJECUp", &_metPhiJECUp, &b__metPhiJECUp);
    chain->SetBranchAddress("_metPhiUnclDown", &_metPhiUnclDown, &b__metPhiUnclDown);
    chain->SetBranchAddress("_metPhiUnclUp", &_metPhiUnclUp, &b__metPhiUnclUp);
    chain->SetBranchAddress("_metSignificance", &_metSignificance, &b__metSignificance);
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

void FillSignalHistsOld(){
    for(int sample = 0; sample < NumberOfSignalSamples; ++sample){
        SetBranches(SignalSamples[sample], true);
        nentry = chain->GetEntries();                                                           //Load number of entries in chain
        cout << endl << "Looping over all events in: " << SignalSamples[sample] << endl;
        double progress = 0.0;
        for(Long64_t entry = 0; entry < nentry; entry++){                               //Loop over all entries
            progress = Progressbar(progress, entry, nentry);                            //Increase progress in progressbar
            chain->GetEntry(entry);
            
            //Tau selector
            for(int lepton = 0; lepton < _nL; lepton++){                                //Loop over all leptons in event
                
                if(_lFlavor[lepton] != 2)                           continue;  

                if(!_lIsPrompt[lepton])                             continue;

                ++nTaus[Signal];                                                       //Prompt Tau Count 
                EfficiencyPtHistDenom[Signal]->Fill(_lPt[lepton]);  
                EfficiencyEtaHistDenom[Signal]->Fill(_lEta[lepton]);

                if(!_decayModeFinding[lepton])                      continue;           //Tau decay mode finding 

                // if(!_tauMuonVeto[lepton])                           continue;
                // if(!_tauEleVeto[lepton])                            continue;   

                //Old tau ID
                if(_lPOGVeto[lepton]){                               ++Efficiency[Signal][MVA_Old][VLoose_MVA]; EfficiencyPtHistNum[Signal][MVA_Old][VLoose_MVA]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][MVA_Old][VLoose_MVA]->Fill(_lEta[lepton]);}                              
                if(_lPOGLoose[lepton]){                              ++Efficiency[Signal][MVA_Old][Loose_MVA]; EfficiencyPtHistNum[Signal][MVA_Old][Loose_MVA]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][MVA_Old][Loose_MVA]->Fill(_lEta[lepton]);}              
                if(_lPOGMedium[lepton]){                             ++Efficiency[Signal][MVA_Old][Medium_MVA]; EfficiencyPtHistNum[Signal][MVA_Old][Medium_MVA]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][MVA_Old][Medium_MVA]->Fill(_lEta[lepton]);}           
                if(_lPOGTight[lepton]){                              ++Efficiency[Signal][MVA_Old][Tight_MVA]; EfficiencyPtHistNum[Signal][MVA_Old][Tight_MVA]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][MVA_Old][Tight_MVA]->Fill(_lEta[lepton]);}                  
                if(_tauVTightMvaOld[lepton]){                        ++Efficiency[Signal][MVA_Old][VTight_MVA]; EfficiencyPtHistNum[Signal][MVA_Old][VTight_MVA]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][MVA_Old][VTight_MVA]->Fill(_lEta[lepton]);}           

                //New tau ID
                if(_tauVLooseMvaNew[lepton]){                        ++Efficiency[Signal][MVA_New][VLoose_MVA]; EfficiencyPtHistNum[Signal][MVA_New][VLoose_MVA]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][MVA_New][VLoose_MVA]->Fill(_lEta[lepton]);}                                  
                if(_tauLooseMvaNew[lepton]){                         ++Efficiency[Signal][MVA_New][Loose_MVA]; EfficiencyPtHistNum[Signal][MVA_New][Loose_MVA]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][MVA_New][Loose_MVA]->Fill(_lEta[lepton]);}             
                if(_tauMediumMvaNew[lepton]){                        ++Efficiency[Signal][MVA_New][Medium_MVA]; EfficiencyPtHistNum[Signal][MVA_New][Medium_MVA]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][MVA_New][Medium_MVA]->Fill(_lEta[lepton]);}           
                if(_tauTightMvaNew[lepton]){                         ++Efficiency[Signal][MVA_New][Tight_MVA]; EfficiencyPtHistNum[Signal][MVA_New][Tight_MVA]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][MVA_New][Tight_MVA]->Fill(_lEta[lepton]);}             
                if(_tauVTightMvaNew[lepton]){                        ++Efficiency[Signal][MVA_New][VTight_MVA]; EfficiencyPtHistNum[Signal][MVA_New][VTight_MVA]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][MVA_New][VTight_MVA]->Fill(_lEta[lepton]);}  

                //Cut-based
                if(_tauCombinedIsoDBRaw3Hits[lepton] < 4.5){         ++Efficiency[Signal][Cut_based][VVLoose_Cut]; EfficiencyPtHistNum[Signal][Cut_based][VVLoose_Cut]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][Cut_based][VVLoose_Cut]->Fill(_lEta[lepton]);}                                   
                if(_tauCombinedIsoDBRaw3Hits[lepton] < 3.5){         ++Efficiency[Signal][Cut_based][VLoose_Cut]; EfficiencyPtHistNum[Signal][Cut_based][VLoose_Cut]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][Cut_based][VLoose_Cut]->Fill(_lEta[lepton]);}               
                if(_tauCombinedIsoDBRaw3Hits[lepton] < 2.0){         ++Efficiency[Signal][Cut_based][Loose_Cut]; EfficiencyPtHistNum[Signal][Cut_based][Loose_Cut]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][Cut_based][Loose_Cut]->Fill(_lEta[lepton]);}               
                if(_tauCombinedIsoDBRaw3Hits[lepton] < 1.0){         ++Efficiency[Signal][Cut_based][Medium_Cut]; EfficiencyPtHistNum[Signal][Cut_based][Medium_Cut]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][Cut_based][Medium_Cut]->Fill(_lEta[lepton]);}              
                if(_tauCombinedIsoDBRaw3Hits[lepton] < 0.8){         ++Efficiency[Signal][Cut_based][Tight_Cut]; EfficiencyPtHistNum[Signal][Cut_based][Tight_Cut]->Fill(_lPt[lepton]); EfficiencyEtaHistNum[Signal][Cut_based][Tight_Cut]->Fill(_lEta[lepton]);}  
            
            }
        }
    }
}

void FillSignalHistsANtest(){
    for(int sample = 0; sample < NumberOfSignalSamples; ++sample){
        SetBranches(SignalSamples[sample], true);
        nentry = chain->GetEntries();                                                           //Load number of entries in chain
        cout << endl << "Looping over all events in: " << SignalSamples[sample] << endl;
        double progress = 0.0;

        cout << nentry << endl;
        for(Long64_t entry = 0; entry < nentry; entry++){                               //Loop over all entries
            progress = Progressbar(progress, entry, nentry);                            //Increase progress in progressbar
            chain->GetEntry(entry);
            
            //Tau selector
            for(int genlepton = 0; genlepton < _gen_nL; genlepton++){                                //Loop over all genleptons in event
                if(entry < 50) cout << _gen_lFlavor[genlepton] << endl;
                
                if(_gen_lFlavor[genlepton] != 2)                           continue;
                if(!_gen_lIsPrompt[genlepton])                              continue;
                if(_gen_lPt[genlepton] < 20 or fabs(_gen_lEta[genlepton]) > 2.3) continue;
                // if(!_lIsPrompt[genlepton])                             continue;
                TLorentzVector genTauVec;
                genTauVec.SetPtEtaPhiE(_gen_lPt[genlepton], _gen_lEta[genlepton], _gen_lPhi[genlepton], _gen_lE[genlepton]);

                int matchindex = 0;
                Double_t minDeltaR = 99999999;
                for(int lepton = 0; lepton < _nL; lepton++){                    
                    if(_lFlavor[lepton] != 2)                           continue;

                    TLorentzVector lVec;
                    lVec.SetPtEtaPhiE(_lPt[lepton], _lEta[lepton], _lPhi[lepton], _lE[lepton]);
                    
                    Double_t deltaR = lVec.DeltaR(genTauVec);
                    if(deltaR < minDeltaR){
                        minDeltaR = deltaR;
                        matchindex = lepton;
                    }
                }

                if(minDeltaR > 0.2)                                    continue;
        
                ++nTaus[Signal];                                                       //Prompt Tau Count 
                EfficiencyPtHistDenom[Signal]->Fill(_lPt[genlepton]);  
                EfficiencyEtaHistDenom[Signal]->Fill(_lEta[genlepton]);

                if(!_decayModeFinding[matchindex])                      continue;           //Tau decay mode finding
                // if(!_tauMuonVeto[lepton])                              continue;
                // if(!_tauEleVeto[lepton])                               continue; 

                //Old tau ID
                if(_lPOGVeto[matchindex]){                               ++Efficiency[Signal][MVA_Old][VLoose_MVA]; EfficiencyPtHistNum[Signal][MVA_Old][VLoose_MVA]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][MVA_Old][VLoose_MVA]->Fill(_gen_lEta[genlepton]);}                               
                if(_lPOGLoose[matchindex]){                              ++Efficiency[Signal][MVA_Old][Loose_MVA]; EfficiencyPtHistNum[Signal][MVA_Old][Loose_MVA]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][MVA_Old][Loose_MVA]->Fill(_gen_lEta[genlepton]);}                  
                if(_lPOGMedium[matchindex]){                             ++Efficiency[Signal][MVA_Old][Medium_MVA]; EfficiencyPtHistNum[Signal][MVA_Old][Medium_MVA]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][MVA_Old][Medium_MVA]->Fill(_gen_lEta[genlepton]);}           
                if(_lPOGTight[matchindex]){                              ++Efficiency[Signal][MVA_Old][Tight_MVA]; EfficiencyPtHistNum[Signal][MVA_Old][Tight_MVA]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][MVA_Old][Tight_MVA]->Fill(_gen_lEta[genlepton]);}                  
                if(_tauVTightMvaOld[matchindex]){                        ++Efficiency[Signal][MVA_Old][VTight_MVA]; EfficiencyPtHistNum[Signal][MVA_Old][VTight_MVA]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][MVA_Old][VTight_MVA]->Fill(_gen_lEta[genlepton]);}           

                //New tau ID
                if(_tauVLooseMvaNew[matchindex]){                        ++Efficiency[Signal][MVA_New][VLoose_MVA]; EfficiencyPtHistNum[Signal][MVA_New][VLoose_MVA]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][MVA_New][VLoose_MVA]->Fill(_gen_lEta[genlepton]);}                                  
                if(_tauLooseMvaNew[matchindex]){                         ++Efficiency[Signal][MVA_New][Loose_MVA]; EfficiencyPtHistNum[Signal][MVA_New][Loose_MVA]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][MVA_New][Loose_MVA]->Fill(_gen_lEta[genlepton]);}             
                if(_tauMediumMvaNew[matchindex]){                        ++Efficiency[Signal][MVA_New][Medium_MVA]; EfficiencyPtHistNum[Signal][MVA_New][Medium_MVA]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][MVA_New][Medium_MVA]->Fill(_gen_lEta[genlepton]);}           
                if(_tauTightMvaNew[matchindex]){                         ++Efficiency[Signal][MVA_New][Tight_MVA]; EfficiencyPtHistNum[Signal][MVA_New][Tight_MVA]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][MVA_New][Tight_MVA]->Fill(_gen_lEta[genlepton]);}             
                if(_tauVTightMvaNew[matchindex]){                        ++Efficiency[Signal][MVA_New][VTight_MVA]; EfficiencyPtHistNum[Signal][MVA_New][VTight_MVA]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][MVA_New][VTight_MVA]->Fill(_gen_lEta[genlepton]);} 

                //Cut-based
                if(_tauCombinedIsoDBRaw3Hits[matchindex] < 4.5){         ++Efficiency[Signal][Cut_based][VVLoose_Cut]; EfficiencyPtHistNum[Signal][Cut_based][VVLoose_Cut]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][Cut_based][VVLoose_Cut]->Fill(_gen_lEta[genlepton]);}                                   
                if(_tauCombinedIsoDBRaw3Hits[matchindex] < 3.5){         ++Efficiency[Signal][Cut_based][VLoose_Cut]; EfficiencyPtHistNum[Signal][Cut_based][VLoose_Cut]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][Cut_based][VLoose_Cut]->Fill(_gen_lEta[genlepton]);}               
                if(_tauCombinedIsoDBRaw3Hits[matchindex] < 2.0){         ++Efficiency[Signal][Cut_based][Loose_Cut]; EfficiencyPtHistNum[Signal][Cut_based][Loose_Cut]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][Cut_based][Loose_Cut]->Fill(_gen_lEta[genlepton]);}               
                if(_tauCombinedIsoDBRaw3Hits[matchindex] < 1.0){         ++Efficiency[Signal][Cut_based][Medium_Cut]; EfficiencyPtHistNum[Signal][Cut_based][Medium_Cut]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][Cut_based][Medium_Cut]->Fill(_gen_lEta[genlepton]);}              
                if(_tauCombinedIsoDBRaw3Hits[matchindex] < 0.8){         ++Efficiency[Signal][Cut_based][Tight_Cut]; EfficiencyPtHistNum[Signal][Cut_based][Tight_Cut]->Fill(_gen_lPt[genlepton]); EfficiencyEtaHistNum[Signal][Cut_based][Tight_Cut]->Fill(_gen_lEta[genlepton]);} 

                if(!_lPOGTight[matchindex]) continue;

                SignalVarHist[lpt]->Fill(_lPt[matchindex]);
                SignalVarHist[leta]->Fill(_lEta[matchindex]);
                SignalVarHist[lE]->Fill(_lE[matchindex]);
                SignalVarHist[dxy]->Fill(_dxy[matchindex]);
                SignalVarHist[dz]->Fill(_dz[matchindex]);
                SignalVarHist[reliso]->Fill(_relIso[matchindex]);
                SignalVarHist[tauAgainstElectronMVA6Raw]->Fill(_tauAgainstElectronMVA6Raw[matchindex]);
                SignalVarHist[tauCombinedIsoDBRaw3Hits]->Fill(_tauAgainstElectronMVA6Raw[matchindex]);
                SignalVarHist[ptRel]->Fill(_ptRel[matchindex]);
                SignalVarHist[ptRatio]->Fill(_ptRatio[matchindex]);
            }
        }

    }
}

void FillBackgroundHists(){
    for(int sample = 0; sample < NumberOfBkgrSamples; ++sample){
        SetBranches(BkgrSamples[sample], true);
        nentry = chain->GetEntries();                                                           //Load number of entries in chain
        cout << endl << "Looping over all events in: " << BkgrSamples[sample] << endl;
        double progress = 0.0;

        for(Long64_t entry = 0; entry < nentry; entry++){                               //Loop over all entries
            progress = Progressbar(progress, entry, nentry);                            //Increase progress in progressbar
            chain->GetEntry(entry);
            
            //Tau selector
            for(int jet = 0; jet < _nJets; ++jet){                                //Loop over all leptons in event

                // if(!_jetIsTight[jet])                                   continue;
                if(_jetPt[jet] < 20 or fabs(_jetEta[jet]) > 2.3)              continue;
                TLorentzVector jetVec;
                jetVec.SetPtEtaPhiE(_jetPt[jet], _jetEta[jet], _jetPhi[jet], _jetE[jet]);

                ++nTaus[Background];                                                       //Prompt Tau Count 
                EfficiencyPtHistDenom[Background]->Fill(_jetPt[jet]);  
                EfficiencyEtaHistDenom[Background]->Fill(_jetEta[jet]);

                int matchindex = 0;
                Double_t minDeltaR = 99999999;
                for(int lepton = 0; lepton < _nL; lepton++){                    
                    if(_lFlavor[lepton] != 2)                           continue;

                    TLorentzVector lVec;
                    lVec.SetPtEtaPhiE(_lPt[lepton], _lEta[lepton], _lPhi[lepton], _lE[lepton]);
                    
                    Double_t deltaR = lVec.DeltaR(jetVec);
                    if(deltaR < minDeltaR){
                        minDeltaR = deltaR;
                        matchindex = lepton;
                    }
                }

                if(minDeltaR > 0.2)                                    continue;
                if(!_decayModeFinding[matchindex])                      continue;           //Tau decay mode finding
                // if(!_tauMuonVeto[lepton])                              continue;
                // if(!_tauEleVeto[lepton])                               continue; 

                //Old tau ID
                if(_lPOGVeto[matchindex]){                               ++Efficiency[Background][MVA_Old][VLoose_MVA]; EfficiencyPtHistNum[Background][MVA_Old][VLoose_MVA]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][MVA_Old][VLoose_MVA]->Fill(_jetEta[jet]);}                               
                if(_lPOGLoose[matchindex]){                              ++Efficiency[Background][MVA_Old][Loose_MVA]; EfficiencyPtHistNum[Background][MVA_Old][Loose_MVA]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][MVA_Old][Loose_MVA]->Fill(_jetEta[jet]);}                  
                if(_lPOGMedium[matchindex]){                             ++Efficiency[Background][MVA_Old][Medium_MVA]; EfficiencyPtHistNum[Background][MVA_Old][Medium_MVA]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][MVA_Old][Medium_MVA]->Fill(_jetEta[jet]);}           
                if(_lPOGTight[matchindex]){                              ++Efficiency[Background][MVA_Old][Tight_MVA]; EfficiencyPtHistNum[Background][MVA_Old][Tight_MVA]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][MVA_Old][Tight_MVA]->Fill(_jetEta[jet]);}                  
                if(_tauVTightMvaOld[matchindex]){                        ++Efficiency[Background][MVA_Old][VTight_MVA]; EfficiencyPtHistNum[Background][MVA_Old][VTight_MVA]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][MVA_Old][VTight_MVA]->Fill(_jetEta[jet]);}           

                //New tau ID
                if(_tauVLooseMvaNew[matchindex]){                        ++Efficiency[Background][MVA_New][VLoose_MVA]; EfficiencyPtHistNum[Background][MVA_New][VLoose_MVA]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][MVA_New][VLoose_MVA]->Fill(_jetEta[jet]);}                                  
                if(_tauLooseMvaNew[matchindex]){                         ++Efficiency[Background][MVA_New][Loose_MVA]; EfficiencyPtHistNum[Background][MVA_New][Loose_MVA]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][MVA_New][Loose_MVA]->Fill(_jetEta[jet]);}             
                if(_tauMediumMvaNew[matchindex]){                        ++Efficiency[Background][MVA_New][Medium_MVA]; EfficiencyPtHistNum[Background][MVA_New][Medium_MVA]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][MVA_New][Medium_MVA]->Fill(_jetEta[jet]);}           
                if(_tauTightMvaNew[matchindex]){                         ++Efficiency[Background][MVA_New][Tight_MVA]; EfficiencyPtHistNum[Background][MVA_New][Tight_MVA]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][MVA_New][Tight_MVA]->Fill(_jetEta[jet]);}             
                if(_tauVTightMvaNew[matchindex]){                        ++Efficiency[Background][MVA_New][VTight_MVA]; EfficiencyPtHistNum[Background][MVA_New][VTight_MVA]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][MVA_New][VTight_MVA]->Fill(_jetEta[jet]);} 

                //Cut-based
                if(_tauCombinedIsoDBRaw3Hits[matchindex] < 4.5){         ++Efficiency[Background][Cut_based][VVLoose_Cut]; EfficiencyPtHistNum[Background][Cut_based][VVLoose_Cut]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][Cut_based][VVLoose_Cut]->Fill(_jetEta[jet]);}                                   
                if(_tauCombinedIsoDBRaw3Hits[matchindex] < 3.5){         ++Efficiency[Background][Cut_based][VLoose_Cut]; EfficiencyPtHistNum[Background][Cut_based][VLoose_Cut]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][Cut_based][VLoose_Cut]->Fill(_jetEta[jet]);}               
                if(_tauCombinedIsoDBRaw3Hits[matchindex] < 2.0){         ++Efficiency[Background][Cut_based][Loose_Cut]; EfficiencyPtHistNum[Background][Cut_based][Loose_Cut]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][Cut_based][Loose_Cut]->Fill(_jetEta[jet]);}               
                if(_tauCombinedIsoDBRaw3Hits[matchindex] < 1.0){         ++Efficiency[Background][Cut_based][Medium_Cut]; EfficiencyPtHistNum[Background][Cut_based][Medium_Cut]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][Cut_based][Medium_Cut]->Fill(_jetEta[jet]);}              
                if(_tauCombinedIsoDBRaw3Hits[matchindex] < 0.8){         ++Efficiency[Background][Cut_based][Tight_Cut]; EfficiencyPtHistNum[Background][Cut_based][Tight_Cut]->Fill(_jetPt[jet]); EfficiencyEtaHistNum[Background][Cut_based][Tight_Cut]->Fill(_jetEta[jet]);} 

                if(!_lPOGTight[matchindex]) continue;

                BkgrVarHist[jetpt]->Fill(_jetPt[matchindex]);
                BkgrVarHist[jeteta]->Fill(_jetEta[matchindex]);
                BkgrVarHist[jetE]->Fill(_jetE[matchindex]);
                BkgrVarHist[jetCsvV2]->Fill(_jetCsvV2[matchindex]);
            }
        }
    }
}

void DrawHists(){
    gROOT->SetBatch(kTRUE);
    gStyle->SetOptStat(0);
    setTDRStyle();
	gStyle->SetPaintTextFormat("4.2f");
    gROOT->ProcessLine( "gErrorIgnoreLevel = 1001;");

    TCanvas * EfficiencyPtOld = new TCanvas("EfficiencyPtOld, EfficiencyPtOld");
    EfficiencyPtHistNum[Signal][MVA_Old][VLoose_MVA]->SetLineColor(kBlack);
    EfficiencyPtHistNum[Signal][MVA_Old][VLoose_MVA]->GetXaxis()->SetNdivisions(508);
    EfficiencyPtHistNum[Signal][MVA_Old][VLoose_MVA]->SetMinimum(0);
    EfficiencyPtHistNum[Signal][MVA_Old][VLoose_MVA]->SetMaximum(100);
    TString plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHistNum[Signal][MVA_Old][VLoose_MVA]->GetBinWidth(1), 2) + "GeV";
    EfficiencyPtHistNum[Signal][MVA_Old][VLoose_MVA]->SetTitle(plottitle);
    EfficiencyPtHistNum[Signal][MVA_Old][VLoose_MVA]->Draw("EHIST");
    EfficiencyPtHistNum[Signal][MVA_Old][Loose_MVA]->SetLineColor(kBlue);
    EfficiencyPtHistNum[Signal][MVA_Old][Loose_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Signal][MVA_Old][Medium_MVA]->SetLineColor(kRed);
    EfficiencyPtHistNum[Signal][MVA_Old][Medium_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Signal][MVA_Old][Tight_MVA]->SetLineColor(kOrange);
    EfficiencyPtHistNum[Signal][MVA_Old][Tight_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Signal][MVA_Old][VTight_MVA]->SetLineColor(kGreen-1);
    EfficiencyPtHistNum[Signal][MVA_Old][VTight_MVA]->Draw("EHISTSAME");
    auto legendEfficiencyPtOld = new TLegend(.85,.7,1., .9);
    legendEfficiencyPtOld->AddEntry(EfficiencyPtHistNum[Signal][MVA_Old][VLoose_MVA], "VLoose");
    legendEfficiencyPtOld->AddEntry(EfficiencyPtHistNum[Signal][MVA_Old][Loose_MVA], "Loose");
    legendEfficiencyPtOld->AddEntry(EfficiencyPtHistNum[Signal][MVA_Old][Medium_MVA], "Medium");
    legendEfficiencyPtOld->AddEntry(EfficiencyPtHistNum[Signal][MVA_Old][Tight_MVA], "Tight");
    legendEfficiencyPtOld->AddEntry(EfficiencyPtHistNum[Signal][MVA_Old][VTight_MVA], "VTight");
    legendEfficiencyPtOld->SetFillStyle(0);
    legendEfficiencyPtOld->SetBorderSize(0);
    legendEfficiencyPtOld->Draw();
    CMS_lumi(EfficiencyPtOld, 4, 11);
    EfficiencyPtOld->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/OldMVATauEwkinoEfficiencyAsFuncOfPT.pdf");
    EfficiencyPtOld->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/OldMVATauEwkinoEfficiencyAsFuncOfPT.root");
    delete EfficiencyPtOld;

    TCanvas * EfficiencyPtNew = new TCanvas("EfficiencyPtNew, EfficiencyPtNew");
    EfficiencyPtHistNum[Signal][MVA_New][VLoose_MVA]->SetLineColor(kBlack);
    EfficiencyPtHistNum[Signal][MVA_New][VLoose_MVA]->GetXaxis()->SetNdivisions(508);
    EfficiencyPtHistNum[Signal][MVA_New][VLoose_MVA]->SetMinimum(0);
    EfficiencyPtHistNum[Signal][MVA_New][VLoose_MVA]->SetMaximum(100);
    plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHistNum[Signal][MVA_New][VLoose_MVA]->GetBinWidth(1), 2) + "GeV";
    EfficiencyPtHistNum[Signal][MVA_New][VLoose_MVA]->SetTitle(plottitle);
    EfficiencyPtHistNum[Signal][MVA_New][VLoose_MVA]->Draw("EHIST");
    EfficiencyPtHistNum[Signal][MVA_New][Loose_MVA]->SetLineColor(kBlue);
    EfficiencyPtHistNum[Signal][MVA_New][Loose_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Signal][MVA_New][Medium_MVA]->SetLineColor(kRed);
    EfficiencyPtHistNum[Signal][MVA_New][Medium_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Signal][MVA_New][Tight_MVA]->SetLineColor(kOrange);
    EfficiencyPtHistNum[Signal][MVA_New][Tight_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Signal][MVA_New][VTight_MVA]->SetLineColor(kGreen-1);
    EfficiencyPtHistNum[Signal][MVA_New][VTight_MVA]->Draw("EHISTSAME");
    auto legendEfficiencyPtNew = new TLegend(.85,.7,1., .9);
    legendEfficiencyPtNew->AddEntry(EfficiencyPtHistNum[Signal][MVA_New][VLoose_MVA], "VLoose");
    legendEfficiencyPtNew->AddEntry(EfficiencyPtHistNum[Signal][MVA_New][Loose_MVA], "Loose");
    legendEfficiencyPtNew->AddEntry(EfficiencyPtHistNum[Signal][MVA_New][Medium_MVA], "Medium");
    legendEfficiencyPtNew->AddEntry(EfficiencyPtHistNum[Signal][MVA_New][Tight_MVA], "Tight");
    legendEfficiencyPtNew->AddEntry(EfficiencyPtHistNum[Signal][MVA_New][VTight_MVA], "VTight");
    legendEfficiencyPtNew->SetFillStyle(0);
    legendEfficiencyPtNew->SetBorderSize(0);
    legendEfficiencyPtNew->Draw();
    CMS_lumi(EfficiencyPtNew, 4, 11);
    EfficiencyPtNew->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/NewMVATauEwkinoEfficiencyAsFuncOfPT.pdf");
    EfficiencyPtNew->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/NewMVATauEwkinoEfficiencyAsFuncOfPT.root");
    delete EfficiencyPtNew;

    TCanvas * EfficiencyPtCuts = new TCanvas("EfficiencyPtCuts, EfficiencyPtCuts");
    EfficiencyPtHistNum[Signal][Cut_based][VVLoose_Cut]->SetLineColor(kBlack);
    EfficiencyPtHistNum[Signal][Cut_based][VVLoose_Cut]->GetXaxis()->SetNdivisions(508);
    EfficiencyPtHistNum[Signal][Cut_based][VVLoose_Cut]->SetMinimum(0);
    EfficiencyPtHistNum[Signal][Cut_based][VVLoose_Cut]->SetMaximum(100);
    plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyPtHistNum[Signal][Cut_based][VLoose_Cut]->GetBinWidth(1), 2) + "GeV";
    EfficiencyPtHistNum[Signal][Cut_based][VVLoose_Cut]->SetTitle(plottitle);
    EfficiencyPtHistNum[Signal][Cut_based][VVLoose_Cut]->Draw("HIST");
    EfficiencyPtHistNum[Signal][Cut_based][VLoose_Cut]->SetLineColor(kBlue);
    EfficiencyPtHistNum[Signal][Cut_based][VLoose_Cut]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Signal][Cut_based][Loose_Cut]->SetLineColor(kRed);
    EfficiencyPtHistNum[Signal][Cut_based][Loose_Cut]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Signal][Cut_based][Medium_Cut]->SetLineColor(kOrange);
    EfficiencyPtHistNum[Signal][Cut_based][Medium_Cut]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Signal][Cut_based][Tight_Cut]->SetLineColor(kGreen-1);
    EfficiencyPtHistNum[Signal][Cut_based][Tight_Cut]->Draw("EHISTSAME");
    auto legendEfficiencyPtCuts = new TLegend(.85,.7,1., .9);
    legendEfficiencyPtCuts->AddEntry(EfficiencyPtHistNum[Signal][Cut_based][VVLoose_Cut], "VLoose");
    legendEfficiencyPtCuts->AddEntry(EfficiencyPtHistNum[Signal][Cut_based][VLoose_Cut], "Loose");
    legendEfficiencyPtCuts->AddEntry(EfficiencyPtHistNum[Signal][Cut_based][Loose_Cut], "Medium");
    legendEfficiencyPtCuts->AddEntry(EfficiencyPtHistNum[Signal][Cut_based][Medium_Cut], "Tight");
    legendEfficiencyPtCuts->AddEntry(EfficiencyPtHistNum[Signal][Cut_based][Tight_Cut], "VTight");
    legendEfficiencyPtCuts->SetFillStyle(0);
    legendEfficiencyPtCuts->SetBorderSize(0);
    legendEfficiencyPtCuts->Draw();
    CMS_lumi(EfficiencyPtCuts, 4, 11);
    EfficiencyPtCuts->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/CutBasedTauEwkinoEfficiencyAsFuncOfPT.pdf");
    EfficiencyPtCuts->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/CutBasedTauEwkinoEfficiencyAsFuncOfPT.root");
    delete EfficiencyPtCuts;

    TCanvas * EfficiencyEtaOld = new TCanvas("EfficiencyEtaOld, EfficiencyEtaOld");
    EfficiencyEtaHistNum[Signal][MVA_Old][VLoose_MVA]->SetLineColor(kBlack);
    EfficiencyEtaHistNum[Signal][MVA_Old][VLoose_MVA]->GetXaxis()->SetNdivisions(508);
    EfficiencyEtaHistNum[Signal][MVA_Old][VLoose_MVA]->SetMinimum(0);
    EfficiencyEtaHistNum[Signal][MVA_Old][VLoose_MVA]->SetMaximum(100);
    plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHistNum[Signal][MVA_Old][VLoose_MVA]->GetBinWidth(1), 2) + "GeV";
    EfficiencyEtaHistNum[Signal][MVA_Old][VLoose_MVA]->SetTitle(plottitle);
    EfficiencyEtaHistNum[Signal][MVA_Old][VLoose_MVA]->Draw("EHIST");
    EfficiencyEtaHistNum[Signal][MVA_Old][Loose_MVA]->SetLineColor(kBlue);
    EfficiencyEtaHistNum[Signal][MVA_Old][Loose_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Signal][MVA_Old][Medium_MVA]->SetLineColor(kRed);
    EfficiencyEtaHistNum[Signal][MVA_Old][Medium_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Signal][MVA_Old][Tight_MVA]->SetLineColor(kOrange);
    EfficiencyEtaHistNum[Signal][MVA_Old][Tight_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Signal][MVA_Old][VTight_MVA]->SetLineColor(kGreen-1);
    EfficiencyEtaHistNum[Signal][MVA_Old][VTight_MVA]->Draw("EHISTSAME");
    auto legendEfficiencyEtaOld = new TLegend(.85,.7,1., .9);
    legendEfficiencyEtaOld->AddEntry(EfficiencyEtaHistNum[Signal][MVA_Old][VLoose_MVA], "VLoose");
    legendEfficiencyEtaOld->AddEntry(EfficiencyEtaHistNum[Signal][MVA_Old][Loose_MVA], "Loose");
    legendEfficiencyEtaOld->AddEntry(EfficiencyEtaHistNum[Signal][MVA_Old][Medium_MVA], "Medium");
    legendEfficiencyEtaOld->AddEntry(EfficiencyEtaHistNum[Signal][MVA_Old][Tight_MVA], "Tight");
    legendEfficiencyEtaOld->AddEntry(EfficiencyEtaHistNum[Signal][MVA_Old][VTight_MVA], "VTight");
    legendEfficiencyEtaOld->SetFillStyle(0);
    legendEfficiencyEtaOld->SetBorderSize(0);
    legendEfficiencyEtaOld->Draw();
    CMS_lumi(EfficiencyEtaOld, 4, 11);
    EfficiencyEtaOld->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/OldMVATauEwkinoEfficiencyAsFuncOfEta.pdf");
    EfficiencyEtaOld->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/OldMVATauEwkinoEfficiencyAsFuncOfEta.root");
    delete EfficiencyEtaOld;

    TCanvas * EfficiencyEtaNew = new TCanvas("EfficiencyEtaNew, EfficiencyEtaNew");
    EfficiencyEtaHistNum[Signal][MVA_New][VLoose_MVA]->SetLineColor(kBlack);
    EfficiencyEtaHistNum[Signal][MVA_New][VLoose_MVA]->GetXaxis()->SetNdivisions(508);
    EfficiencyEtaHistNum[Signal][MVA_New][VLoose_MVA]->SetMinimum(0);
    EfficiencyEtaHistNum[Signal][MVA_New][VLoose_MVA]->SetMaximum(100);
    plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHistNum[Signal][MVA_New][VLoose_MVA]->GetBinWidth(1), 2) + "GeV";
    EfficiencyEtaHistNum[Signal][MVA_New][VLoose_MVA]->SetTitle(plottitle);
    EfficiencyEtaHistNum[Signal][MVA_New][VLoose_MVA]->Draw("EHIST");
    EfficiencyEtaHistNum[Signal][MVA_New][Loose_MVA]->SetLineColor(kBlue);
    EfficiencyEtaHistNum[Signal][MVA_New][Loose_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Signal][MVA_New][Medium_MVA]->SetLineColor(kRed);
    EfficiencyEtaHistNum[Signal][MVA_New][Medium_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Signal][MVA_New][Tight_MVA]->SetLineColor(kOrange);
    EfficiencyEtaHistNum[Signal][MVA_New][Tight_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Signal][MVA_New][VTight_MVA]->SetLineColor(kGreen-1);
    EfficiencyEtaHistNum[Signal][MVA_New][VTight_MVA]->Draw("EHISTSAME");
    auto legendEfficiencyEtaNew = new TLegend(.85,.7,1., .9);
    legendEfficiencyEtaNew->AddEntry(EfficiencyEtaHistNum[Signal][MVA_New][VLoose_MVA], "VLoose");
    legendEfficiencyEtaNew->AddEntry(EfficiencyEtaHistNum[Signal][MVA_New][Loose_MVA], "Loose");
    legendEfficiencyEtaNew->AddEntry(EfficiencyEtaHistNum[Signal][MVA_New][Medium_MVA], "Medium");
    legendEfficiencyEtaNew->AddEntry(EfficiencyEtaHistNum[Signal][MVA_New][Tight_MVA], "Tight");
    legendEfficiencyEtaNew->AddEntry(EfficiencyEtaHistNum[Signal][MVA_New][VTight_MVA], "VTight");
    legendEfficiencyEtaNew->SetFillStyle(0);
    legendEfficiencyEtaNew->SetBorderSize(0);
    legendEfficiencyEtaNew->Draw();
    CMS_lumi(EfficiencyEtaNew, 4, 11);
    EfficiencyEtaNew->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/NewMVATauEwkinoEfficiencyAsFuncOfEta.pdf");
    EfficiencyEtaNew->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/NewMVATauEwkinoEfficiencyAsFuncOfEta.root");
    delete EfficiencyEtaNew;

    TCanvas * EfficiencyEtaCuts = new TCanvas("EfficiencyEtaCuts, EfficiencyEtaCuts");
    EfficiencyEtaHistNum[Signal][Cut_based][VVLoose_Cut]->SetLineColor(kBlack);
    EfficiencyEtaHistNum[Signal][Cut_based][VVLoose_Cut]->GetXaxis()->SetNdivisions(508);
    EfficiencyEtaHistNum[Signal][Cut_based][VVLoose_Cut]->SetMinimum(0);
    EfficiencyEtaHistNum[Signal][Cut_based][VVLoose_Cut]->SetMaximum(100);
    plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHistNum[Signal][Cut_based][VLoose_Cut]->GetBinWidth(1), 2) + "GeV";
    EfficiencyEtaHistNum[Signal][Cut_based][VVLoose_Cut]->SetTitle(plottitle);
    EfficiencyEtaHistNum[Signal][Cut_based][VVLoose_Cut]->Draw("EHIST");
    EfficiencyEtaHistNum[Signal][Cut_based][VLoose_Cut]->SetLineColor(kBlue);
    EfficiencyEtaHistNum[Signal][Cut_based][VLoose_Cut]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Signal][Cut_based][Loose_Cut]->SetLineColor(kRed);
    EfficiencyEtaHistNum[Signal][Cut_based][Loose_Cut]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Signal][Cut_based][Medium_Cut]->SetLineColor(kOrange);
    EfficiencyEtaHistNum[Signal][Cut_based][Medium_Cut]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Signal][Cut_based][Tight_Cut]->SetLineColor(kGreen-1);
    EfficiencyEtaHistNum[Signal][Cut_based][Tight_Cut]->Draw("EHISTSAME");
    auto legendEfficiencyEtaCuts = new TLegend(.85,.7,1., .9);
    legendEfficiencyEtaCuts->AddEntry(EfficiencyEtaHistNum[Signal][Cut_based][VVLoose_Cut], "VLoose");
    legendEfficiencyEtaCuts->AddEntry(EfficiencyEtaHistNum[Signal][Cut_based][VLoose_Cut], "Loose");
    legendEfficiencyEtaCuts->AddEntry(EfficiencyEtaHistNum[Signal][Cut_based][Loose_Cut], "Medium");
    legendEfficiencyEtaCuts->AddEntry(EfficiencyEtaHistNum[Signal][Cut_based][Medium_Cut], "Tight");
    legendEfficiencyEtaCuts->AddEntry(EfficiencyEtaHistNum[Signal][Cut_based][Tight_Cut], "VTight");
    legendEfficiencyEtaCuts->SetFillStyle(0);
    legendEfficiencyEtaCuts->SetBorderSize(0);
    legendEfficiencyEtaCuts->Draw();
    CMS_lumi(EfficiencyEtaCuts, 4, 11);
    EfficiencyEtaCuts->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/CutBasedTauEwkinoEfficiencyAsFuncOfEta.pdf");
    EfficiencyEtaCuts->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/CutBasedTauEwkinoEfficiencyAsFuncOfEta.root");
    delete EfficiencyEtaCuts;

    TCanvas * MisIdPtOld = new TCanvas("MisIdPtOld, MisIdPtOld");
    EfficiencyPtHistNum[Background][MVA_Old][VLoose_MVA]->SetLineColor(kBlack);
    EfficiencyPtHistNum[Background][MVA_Old][VLoose_MVA]->GetXaxis()->SetNdivisions(508);
    EfficiencyPtHistNum[Background][MVA_Old][VLoose_MVA]->SetMinimum(1e-6);
    // // EfficiencyPtHistNum[Background][MVA_Old][VLoose_MVA]->SetMaximum(1);
    plottitle = "; p_{T}(#tau) [GeV]; Fake rate / " + to_string_with_precision(EfficiencyPtHistNum[Background][MVA_Old][VLoose_MVA]->GetBinWidth(1), 2) + "GeV";
    EfficiencyPtHistNum[Background][MVA_Old][VLoose_MVA]->SetTitle(plottitle);
    EfficiencyPtHistNum[Background][MVA_Old][VLoose_MVA]->Draw("EHIST");
    EfficiencyPtHistNum[Background][MVA_Old][Loose_MVA]->SetLineColor(kBlue);
    EfficiencyPtHistNum[Background][MVA_Old][Loose_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Background][MVA_Old][Medium_MVA]->SetLineColor(kRed);
    EfficiencyPtHistNum[Background][MVA_Old][Medium_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Background][MVA_Old][Tight_MVA]->SetLineColor(kOrange);
    EfficiencyPtHistNum[Background][MVA_Old][Tight_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Background][MVA_Old][VTight_MVA]->SetLineColor(kGreen-1);
    EfficiencyPtHistNum[Background][MVA_Old][VTight_MVA]->Draw("EHISTSAME");
    auto legendMisIdPtOld = new TLegend(.85,.7,1., .9);
    legendMisIdPtOld->AddEntry(EfficiencyPtHistNum[Background][MVA_Old][VLoose_MVA], "VLoose");
    legendMisIdPtOld->AddEntry(EfficiencyPtHistNum[Background][MVA_Old][Loose_MVA], "Loose");
    legendMisIdPtOld->AddEntry(EfficiencyPtHistNum[Background][MVA_Old][Medium_MVA], "Medium");
    legendMisIdPtOld->AddEntry(EfficiencyPtHistNum[Background][MVA_Old][Tight_MVA], "Tight");
    legendMisIdPtOld->AddEntry(EfficiencyPtHistNum[Background][MVA_Old][VTight_MVA], "VTight");
    legendMisIdPtOld->SetFillStyle(0);
    legendMisIdPtOld->SetBorderSize(0);
    legendMisIdPtOld->Draw();
    CMS_lumi(MisIdPtOld, 4, 11);
    MisIdPtOld->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/OldMVATauEwkinoMisIDAsFuncOfPT.pdf");
    MisIdPtOld->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/OldMVATauEwkinoMisIDAsFuncOfPT.root");
    delete MisIdPtOld;

    TCanvas * MisIdPtNew = new TCanvas("MisIdPtNew, MisIdPtNew");
    EfficiencyPtHistNum[Background][MVA_New][VLoose_MVA]->SetLineColor(kBlack);
    EfficiencyPtHistNum[Background][MVA_New][VLoose_MVA]->GetXaxis()->SetNdivisions(508);
    EfficiencyPtHistNum[Background][MVA_New][VLoose_MVA]->SetMinimum(1e-7);
    // EfficiencyPtHistNum[Background][MVA_New][VLoose_MVA]->SetMaximum(1);
    plottitle = "; p_{T}(#tau) [GeV]; Fake rate / " + to_string_with_precision(EfficiencyPtHistNum[Background][MVA_Old][VLoose_MVA]->GetBinWidth(1), 2) + "GeV";
    EfficiencyPtHistNum[Background][MVA_New][VLoose_MVA]->SetTitle(plottitle);
    EfficiencyPtHistNum[Background][MVA_New][VLoose_MVA]->Draw("EHIST");
    EfficiencyPtHistNum[Background][MVA_New][Loose_MVA]->SetLineColor(kBlue);
    EfficiencyPtHistNum[Background][MVA_New][Loose_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Background][MVA_New][Medium_MVA]->SetLineColor(kRed);
    EfficiencyPtHistNum[Background][MVA_New][Medium_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Background][MVA_New][Tight_MVA]->SetLineColor(kOrange);
    EfficiencyPtHistNum[Background][MVA_New][Tight_MVA]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Background][MVA_New][VTight_MVA]->SetLineColor(kGreen-1);
    EfficiencyPtHistNum[Background][MVA_New][VTight_MVA]->Draw("EHISTSAME");
    auto legendMisIdPtNew = new TLegend(.85,.7,1., .9);
    legendMisIdPtNew->AddEntry(EfficiencyPtHistNum[Background][MVA_New][VLoose_MVA], "VLoose");
    legendMisIdPtNew->AddEntry(EfficiencyPtHistNum[Background][MVA_New][Loose_MVA], "Loose");
    legendMisIdPtNew->AddEntry(EfficiencyPtHistNum[Background][MVA_New][Medium_MVA], "Medium");
    legendMisIdPtNew->AddEntry(EfficiencyPtHistNum[Background][MVA_New][Tight_MVA], "Tight");
    legendMisIdPtNew->AddEntry(EfficiencyPtHistNum[Background][MVA_New][VTight_MVA], "VTight");
    legendMisIdPtNew->SetFillStyle(0);
    legendMisIdPtNew->SetBorderSize(0);
    legendMisIdPtNew->Draw();
    CMS_lumi(MisIdPtNew, 4, 11);
    MisIdPtNew->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/NewMVATauEwkinoMisIDAsFuncOfPT.pdf");
    MisIdPtNew->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/NewMVATauEwkinoMisIDAsFuncOfPT.root");
    delete MisIdPtNew;

    TCanvas * MisIdPtCuts = new TCanvas("MisIdPtCuts, MisIdPtCuts");
    EfficiencyPtHistNum[Background][Cut_based][VVLoose_Cut]->SetLineColor(kBlack);
    EfficiencyPtHistNum[Background][Cut_based][VVLoose_Cut]->GetXaxis()->SetNdivisions(508);
    EfficiencyPtHistNum[Background][Cut_based][VVLoose_Cut]->SetMinimum(1e-7);
    // EfficiencyPtHistNum[Background][Cut_based][VVLoose_Cut]->SetMaximum(1);
    plottitle = "; p_{T}(#tau) [GeV]; Fake rate / " + to_string_with_precision(EfficiencyPtHistNum[Background][MVA_Old][VLoose_Cut]->GetBinWidth(1), 2) + "GeV";
    EfficiencyPtHistNum[Background][Cut_based][VVLoose_Cut]->SetTitle(plottitle);
    EfficiencyPtHistNum[Background][Cut_based][VVLoose_Cut]->Draw("EHIST");
    EfficiencyPtHistNum[Background][Cut_based][VLoose_Cut]->SetLineColor(kBlue);
    EfficiencyPtHistNum[Background][Cut_based][VLoose_Cut]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Background][Cut_based][Loose_Cut]->SetLineColor(kRed);
    EfficiencyPtHistNum[Background][Cut_based][Loose_Cut]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Background][Cut_based][Medium_Cut]->SetLineColor(kOrange);
    EfficiencyPtHistNum[Background][Cut_based][Medium_Cut]->Draw("EHISTSAME");
    EfficiencyPtHistNum[Background][Cut_based][Tight_Cut]->SetLineColor(kGreen-1);
    EfficiencyPtHistNum[Background][Cut_based][Tight_Cut]->Draw("EHISTSAME");
    auto legendMisIdPtCuts = new TLegend(.85,.7,1., .9);
    legendMisIdPtCuts->AddEntry(EfficiencyPtHistNum[Background][Cut_based][VVLoose_Cut], "VLoose");
    legendMisIdPtCuts->AddEntry(EfficiencyPtHistNum[Background][Cut_based][VLoose_Cut], "Loose");
    legendMisIdPtCuts->AddEntry(EfficiencyPtHistNum[Background][Cut_based][Loose_Cut], "Medium");
    legendMisIdPtCuts->AddEntry(EfficiencyPtHistNum[Background][Cut_based][Medium_Cut], "Tight");
    legendMisIdPtCuts->AddEntry(EfficiencyPtHistNum[Background][Cut_based][Tight_Cut], "VTight");
    legendMisIdPtCuts->SetFillStyle(0);
    legendMisIdPtCuts->SetBorderSize(0);
    legendMisIdPtCuts->Draw();
    CMS_lumi(MisIdPtCuts, 4, 11);
    MisIdPtCuts->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/CutBasedTauEwkinoMisIDAsFuncOfPT.pdf");
    MisIdPtCuts->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/CutBasedTauEwkinoMisIDAsFuncOfPT.root");
    delete MisIdPtCuts;

    TCanvas * MisIdEtaOld = new TCanvas("MisIdEtaOld, MisIdEtaOld");
    EfficiencyEtaHistNum[Background][MVA_Old][VLoose_MVA]->SetLineColor(kBlack);
    EfficiencyEtaHistNum[Background][MVA_Old][VLoose_MVA]->GetXaxis()->SetNdivisions(508);
    EfficiencyEtaHistNum[Background][MVA_Old][VLoose_MVA]->SetMinimum(1e-7);
    // EfficiencyEtaHistNum[Background][MVA_Old][VLoose_MVA]->SetMaximum(1);
    plottitle = "; p_{T}(#tau) [GeV]; Fake rate / " + to_string_with_precision(EfficiencyEtaHistNum[Background][MVA_Old][VLoose_MVA]->GetBinWidth(1), 2) + "GeV";
    EfficiencyEtaHistNum[Background][MVA_Old][VLoose_MVA]->SetTitle(plottitle);
    EfficiencyEtaHistNum[Background][MVA_Old][VLoose_MVA]->Draw("EHIST");
    EfficiencyEtaHistNum[Background][MVA_Old][Loose_MVA]->SetLineColor(kBlue);
    EfficiencyEtaHistNum[Background][MVA_Old][Loose_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Background][MVA_Old][Medium_MVA]->SetLineColor(kRed);
    EfficiencyEtaHistNum[Background][MVA_Old][Medium_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Background][MVA_Old][Tight_MVA]->SetLineColor(kOrange);
    EfficiencyEtaHistNum[Background][MVA_Old][Tight_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Background][MVA_Old][VTight_MVA]->SetLineColor(kGreen-1);
    EfficiencyEtaHistNum[Background][MVA_Old][VTight_MVA]->Draw("EHISTSAME");
    auto legendMisIdEtaOld = new TLegend(.85,.7,1., .9);
    legendMisIdEtaOld->AddEntry(EfficiencyEtaHistNum[Background][MVA_Old][VLoose_MVA], "VLoose");
    legendMisIdEtaOld->AddEntry(EfficiencyEtaHistNum[Background][MVA_Old][Loose_MVA], "Loose");
    legendMisIdEtaOld->AddEntry(EfficiencyEtaHistNum[Background][MVA_Old][Medium_MVA], "Medium");
    legendMisIdEtaOld->AddEntry(EfficiencyEtaHistNum[Background][MVA_Old][Tight_MVA], "Tight");
    legendMisIdEtaOld->AddEntry(EfficiencyEtaHistNum[Background][MVA_Old][VTight_MVA], "VTight");
    legendMisIdEtaOld->SetFillStyle(0);
    legendMisIdEtaOld->SetBorderSize(0);
    legendMisIdEtaOld->Draw();
    CMS_lumi(MisIdEtaOld, 4, 11);
    MisIdEtaOld->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/OldMVATauEwkinoMisIDAsFuncOfEta.pdf");
    MisIdEtaOld->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/OldMVATauEwkinoMisIDAsFuncOfEta.root");
    delete MisIdEtaOld;

    TCanvas * MisIdEtaNew = new TCanvas("MisIdEtaNew, MisIdEtaNew");
    EfficiencyEtaHistNum[Background][MVA_New][VLoose_MVA]->SetLineColor(kBlack);
    EfficiencyEtaHistNum[Background][MVA_New][VLoose_MVA]->GetXaxis()->SetNdivisions(508);
    EfficiencyEtaHistNum[Background][MVA_New][VLoose_MVA]->SetMinimum(1e-7);
    // EfficiencyEtaHistNum[Background][MVA_New][VLoose_MVA]->SetMaximum(1);
    plottitle = "; p_{T}(#tau) [GeV]; Efficiency (%) / " + to_string_with_precision(EfficiencyEtaHistNum[Background][MVA_Old][VLoose_MVA]->GetBinWidth(1), 2) + "GeV";
    EfficiencyEtaHistNum[Background][MVA_New][VLoose_MVA]->SetTitle(plottitle);
    EfficiencyEtaHistNum[Background][MVA_New][VLoose_MVA]->Draw("EHIST");
    EfficiencyEtaHistNum[Background][MVA_New][Loose_MVA]->SetLineColor(kBlue);
    EfficiencyEtaHistNum[Background][MVA_New][Loose_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Background][MVA_New][Medium_MVA]->SetLineColor(kRed);
    EfficiencyEtaHistNum[Background][MVA_New][Medium_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Background][MVA_New][Tight_MVA]->SetLineColor(kOrange);
    EfficiencyEtaHistNum[Background][MVA_New][Tight_MVA]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Background][MVA_New][VTight_MVA]->SetLineColor(kGreen-1);
    EfficiencyEtaHistNum[Background][MVA_New][VTight_MVA]->Draw("EHISTSAME");
    auto legendMisIdEtaNew = new TLegend(.85,.7,1., .9);
    legendMisIdEtaNew->AddEntry(EfficiencyEtaHistNum[Background][MVA_New][VLoose_MVA], "VLoose");
    legendMisIdEtaNew->AddEntry(EfficiencyEtaHistNum[Background][MVA_New][Loose_MVA], "Loose");
    legendMisIdEtaNew->AddEntry(EfficiencyEtaHistNum[Background][MVA_New][Medium_MVA], "Medium");
    legendMisIdEtaNew->AddEntry(EfficiencyEtaHistNum[Background][MVA_New][Tight_MVA], "Tight");
    legendMisIdEtaNew->AddEntry(EfficiencyEtaHistNum[Background][MVA_New][VTight_MVA], "VTight");
    legendMisIdEtaNew->SetFillStyle(0);
    legendMisIdEtaNew->SetBorderSize(0);
    legendMisIdEtaNew->Draw();
    CMS_lumi(MisIdEtaNew, 4, 11);
    MisIdEtaNew->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/NewMVATauEwkinoMisIDAsFuncOfEta.pdf");
    MisIdEtaNew->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/NewMVATauEwkinoMisIDAsFuncOfEta.root");
    delete MisIdEtaNew;

    TCanvas * MisIdEtaCuts = new TCanvas("MisIdEtaCuts, MisIdEtaCuts");
    EfficiencyEtaHistNum[Background][Cut_based][VVLoose_Cut]->SetLineColor(kBlack);
    EfficiencyEtaHistNum[Background][Cut_based][VVLoose_Cut]->GetXaxis()->SetNdivisions(508);
    EfficiencyEtaHistNum[Background][Cut_based][VVLoose_Cut]->SetMinimum(1e-7);
    // EfficiencyEtaHistNum[Background][Cut_based][VVLoose_Cut]->SetMaximum(1);
    plottitle = "; p_{T}(#tau) [GeV]; Fake rate / " + to_string_with_precision(EfficiencyEtaHistNum[Background][MVA_Old][VLoose_Cut]->GetBinWidth(1), 2) + "GeV";
    EfficiencyEtaHistNum[Background][Cut_based][VVLoose_Cut]->SetTitle(plottitle);
    EfficiencyEtaHistNum[Background][Cut_based][VVLoose_Cut]->Draw("EHIST");
    EfficiencyEtaHistNum[Background][Cut_based][VLoose_Cut]->SetLineColor(kBlue);
    EfficiencyEtaHistNum[Background][Cut_based][VLoose_Cut]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Background][Cut_based][Loose_Cut]->SetLineColor(kRed);
    EfficiencyEtaHistNum[Background][Cut_based][Loose_Cut]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Background][Cut_based][Medium_Cut]->SetLineColor(kOrange);
    EfficiencyEtaHistNum[Background][Cut_based][Medium_Cut]->Draw("EHISTSAME");
    EfficiencyEtaHistNum[Background][Cut_based][Tight_Cut]->SetLineColor(kGreen-1);
    EfficiencyEtaHistNum[Background][Cut_based][Tight_Cut]->Draw("EHISTSAME");
    auto legendMisIdEtaCuts = new TLegend(.85,.7,1., .9);
    legendMisIdEtaCuts->AddEntry(EfficiencyEtaHistNum[Background][Cut_based][VVLoose_Cut], "VLoose");
    legendMisIdEtaCuts->AddEntry(EfficiencyEtaHistNum[Background][Cut_based][VLoose_Cut], "Loose");
    legendMisIdEtaCuts->AddEntry(EfficiencyEtaHistNum[Background][Cut_based][Loose_Cut], "Medium");
    legendMisIdEtaCuts->AddEntry(EfficiencyEtaHistNum[Background][Cut_based][Medium_Cut], "Tight");
    legendMisIdEtaCuts->AddEntry(EfficiencyEtaHistNum[Background][Cut_based][Tight_Cut], "VTight");
    legendMisIdEtaCuts->SetFillStyle(0);
    legendMisIdEtaCuts->SetBorderSize(0);
    legendMisIdEtaCuts->Draw();
    CMS_lumi(MisIdEtaCuts, 4, 11);
    MisIdEtaCuts->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/CutBasedTauEwkinoMisIDAsFuncOfEta.pdf");
    MisIdEtaCuts->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/CutBasedTauEwkinoMisIDAsFuncOfEta.root");
    delete MisIdEtaCuts;

    TGraphErrors * ROCmvaOld = new TGraphErrors(5, Efficiency[Signal][MVA_Old], Efficiency[Background][MVA_Old], EfficiencyErrors[Signal][MVA_Old], EfficiencyErrors[Background][MVA_Old]);
    TCanvas * c1 = new TCanvas("c1, c1");
    // c1->SetLogx();
    ROCmvaOld->SetTitle("; Efficiency in Signal (%); Jet->#tau FR");
    ROCmvaOld->SetMarkerSize(.5);
    // ROCmvaOld->GetXaxis()->SetLimits(20, 100);
    ROCmvaOld->Draw("AP");
    CMS_lumi(c1, 4, 11);
    c1->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/ROC/ROC_MVAOld.pdf");
    c1->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/ROC/ROC_MVAOld.jpg");
    c1->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/ROC/ROC_MVAOld.root");

    TGraphErrors * ROCmvaNew = new TGraphErrors(5, Efficiency[Signal][MVA_New], Efficiency[Background][MVA_New], EfficiencyErrors[Signal][MVA_New], EfficiencyErrors[Background][MVA_New]);
    TCanvas * c2 = new TCanvas("c2, c2");
    // c2->SetLogx();
    ROCmvaNew->SetTitle("; Efficiency in Signal (%); Jet->#tau FR");
    ROCmvaNew->SetMarkerSize(.5);
    // ROCmvaNew->GetXaxis()->SetLimits(20, 100);
    ROCmvaNew->Draw("AP");
    CMS_lumi(c2, 4, 11);
    c2->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/ROC/ROC_MVANew.pdf");
    c2->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/ROC/ROC_MVANew.jpg");
    c2->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/ROC/ROC_MVANew.root");

    TGraphErrors * ROCCuts = new TGraphErrors(5, Efficiency[Signal][Cut_based], Efficiency[Background][Cut_based], EfficiencyErrors[Signal][Cut_based], EfficiencyErrors[Background][Cut_based]);
    TCanvas * c3 = new TCanvas("c3, c3");
    // c3->SetLogx();
    ROCCuts->SetTitle("; Efficiency in Signal (%); Jet->#tau FR");
    ROCCuts->SetMarkerSize(.5);
    // ROCCuts->GetXaxis()->SetLimits(20, 100);
    ROCCuts->Draw("AP");
    CMS_lumi(c3, 4, 11);
    c3->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/ROC/ROC_Cuts.pdf");
    c3->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/ROC/ROC_Cuts.jpg");
    c3->SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/ROC/ROC_Cuts.root");
}

void GeneralTauEfficiency(){

    //Initiate Histograms
    TString histtitle;
    for(int categ = 0; categ < 2; ++categ){
        histtitle = "EfficiencyPtDenom"+to_string_with_precision(categ, 2);
        EfficiencyPtHistDenom[categ] = new TH1D(histtitle, histtitle, 10, 20, PtHistLimits[categ]);
        EfficiencyPtHistDenom[categ]->Sumw2();
        histtitle = "EfficiencyEtaDenom"+to_string_with_precision(categ, 2);
        EfficiencyEtaHistDenom[categ] = new TH1D(histtitle, histtitle, 12, 0, 2.4);
        EfficiencyEtaHistDenom[categ]->Sumw2();
        for(int discriminator = 0; discriminator < NumberOfDiscr; ++discriminator){
            for(int WP = 0; WP < NumberOfWP; ++WP){
                histtitle = "EfficiencyPtNum"+to_string_with_precision(discriminator, 2)+to_string_with_precision(WP, 2)+to_string_with_precision(categ, 2);
                EfficiencyPtHistNum[categ][discriminator][WP] = new TH1D(histtitle, histtitle, 10, 20, PtHistLimits[categ]);
                EfficiencyPtHistNum[categ][discriminator][WP]->Sumw2();
                histtitle = "EfficiencyEtaNum"+to_string_with_precision(discriminator, 2)+to_string_with_precision(WP, 2)+to_string_with_precision(categ, 2);
                EfficiencyEtaHistNum[categ][discriminator][WP] = new TH1D(histtitle, histtitle, 12, 0, 2.4);
                EfficiencyEtaHistNum[categ][discriminator][WP]->Sumw2();
            }
        }
    }

    SignalVarHist[lpt] = new TH1D("lpt", "lpt", 20, 20, 120);
    SignalVarHist[leta] = new TH1D("leta", "leta", 12, -2.4, 2.4);
    SignalVarHist[lE] = new TH1D("lE", "lE", 20, 20, 120);
    SignalVarHist[dxy] = new TH1D("dxy", "dxy", 20, 0, 1);
    SignalVarHist[dz] = new TH1D("dz", "dz", 20, 0, 1);
    SignalVarHist[reliso] = new TH1D("reliso", "reliso", 20, 0, 1);
    SignalVarHist[tauAgainstElectronMVA6Raw] = new TH1D("tauAgainstElectronMVA6Raw", "tauAgainstElectronMVA6Raw", 20, -1, 1);
    SignalVarHist[tauCombinedIsoDBRaw3Hits] = new TH1D("tauCombinedIsoDBRaw3Hits", "tauCombinedIsoDBRaw3Hits", 20, 0, 1);
    SignalVarHist[ptRel] = new TH1D("ptRel", "ptRel", 20, 0, 60);
    SignalVarHist[ptRatio] = new TH1D("ptRatio", "ptRatio", 20, 0.6, 1.2);

    for(int var = 0; var < NumberOfSignalVar; ++var){
        SignalVarHist[var]->Sumw2();
    }

    BkgrVarHist[jetpt] = new TH1D("jetpt", "jetpt", 20, 0, 300);
    BkgrVarHist[jeteta] = new TH1D("jeteta", "jeteta", 20, 0, 2.5);
    BkgrVarHist[jetE] = new TH1D("jetE", "jetE", 20, 0, 300);
    BkgrVarHist[jetCsvV2] = new TH1D("jetCsvV2", "jetCsvV2", 20, -1, 1);

    for(int var = 0; var < NumberOfBkgrVar; ++var){
        BkgrVarHist[var]->Sumw2();
    }

    FillBackgroundHists();
    FillSignalHistsANtest();

    cout << endl << "Calculating efficiencies and drawing plots" << endl;

    //Calculate Efficiency and Fake Rate
    for(int discriminator = 0; discriminator < NumberOfDiscr; ++discriminator){                                             
        for(int WP = 0; WP < NumberOfWP; ++WP){
            //Efficiencies
            EfficiencyErrors[Signal][discriminator][WP] = (sqrt(Efficiency[Signal][discriminator][WP])/nTaus[Signal])*100;
            Efficiency[Signal][discriminator][WP] = (Efficiency[Signal][discriminator][WP]/nTaus[Signal])*100;
            EfficiencyPtHistNum[Signal][discriminator][WP]->Divide(EfficiencyPtHistDenom[Signal]);
            EfficiencyPtHistNum[Signal][discriminator][WP]->Scale(100.);
            EfficiencyEtaHistNum[Signal][discriminator][WP]->Divide(EfficiencyEtaHistDenom[Signal]);
            EfficiencyEtaHistNum[Signal][discriminator][WP]->Scale(100.);

            //Fake Rates
            EfficiencyErrors[Background][discriminator][WP] = (sqrt(Efficiency[Background][discriminator][WP])/nTaus[Background]);
            Efficiency[Background][discriminator][WP] = (Efficiency[Background][discriminator][WP]/nTaus[Background]);
            EfficiencyPtHistNum[Background][discriminator][WP]->Divide(EfficiencyPtHistDenom[Background]);
            //~ EfficiencyPtHistNum[Background][discriminator][WP]->Scale(100.);
            EfficiencyEtaHistNum[Background][discriminator][WP]->Divide(EfficiencyEtaHistDenom[Background]);
            //~ EfficiencyEtaHistNum[Background][discriminator][WP]->Scale(100.);
        }
    }

    for(int discriminator = 0; discriminator < NumberOfDiscr; ++discriminator){                                             
        for(int WP = 0; WP < NumberOfWP; ++WP){
            TString SaveTitle = "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencySignal_Pt_" + discriminatorNames[discriminator] + "_" + WPNames[WP]+".root";
            EfficiencyPtHistNum[Signal][discriminator][WP]->SaveAs(SaveTitle);
            SaveTitle = "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencyBkgr_Pt_" + discriminatorNames[discriminator] + "_" + WPNames[WP]+".root";
            EfficiencyPtHistNum[Background][discriminator][WP]->SaveAs(SaveTitle);
            SaveTitle = "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencySignal_Eta_" + discriminatorNames[discriminator] + "_" + WPNames[WP]+".root";
            EfficiencyEtaHistNum[Signal][discriminator][WP]->SaveAs(SaveTitle);
            SaveTitle = "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencyBkgr_Eta_" + discriminatorNames[discriminator] + "_" + WPNames[WP]+".root";
            EfficiencyEtaHistNum[Background][discriminator][WP]->SaveAs(SaveTitle);
        }
    }

    for(int var = 0; var < NumberOfSignalVar; ++var){
        TString SaveTitle = "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/SignalVar_" + SignalVarNames[var] +".root";
        SignalVarHist[var]->SaveAs(SaveTitle);
    }

    for(int var = 0; var < NumberOfBkgrVar; ++var){
        TString SaveTitle = "/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/BkgrVar_" + BkgrVarNames[var] +".root";
        BkgrVarHist[var]->SaveAs(SaveTitle);
    }
    ofstream effOutFiles[2][NumberOfDiscr]; 
    ofstream effOutFilesErrors[2][NumberOfDiscr];

    for(int discr = 0; discr < NumberOfDiscr; ++discr){
        effOutFiles[Signal][discr].open("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencyROC_Signal"+ discriminatorNames[discr] + ".dat");
        effOutFilesErrors[Signal][discr].open("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencyROCErrors_Signal"+ discriminatorNames[discr] + ".dat");
        effOutFiles[Background][discr].open("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencyROC_Bkgr"+ discriminatorNames[discr] + ".dat");
        effOutFilesErrors[Background][discr].open("/user/lwezenbe/private/PhD/Results/TauStudy/ReproducePlots/Histos/EfficiencyROCErrors_Bkgr"+ discriminatorNames[discr] + ".dat");
        for(int WP = 0; WP < NumberOfWP; ++WP){
            effOutFiles[Signal][discr] << Efficiency[Signal][discr][WP] << " ";
            effOutFilesErrors[Signal][discr] << EfficiencyErrors[Signal][discr][WP] << " ";
            effOutFiles[Background][discr] << Efficiency[Background][discr][WP] << " ";
            effOutFilesErrors[Background][discr] << EfficiencyErrors[Background][discr][WP] << " ";
        }
        effOutFiles[Signal][discr] << endl; 
        effOutFilesErrors[Signal][discr] <<endl;
        effOutFiles[Background][discr] << endl;
        effOutFilesErrors[Background][discr] << endl;
    }
     for(int discr = 0; discr < NumberOfDiscr; ++discr){
        effOutFiles[Signal][discr].close();
        effOutFilesErrors[Signal][discr].close();
        effOutFiles[Background][discr].close();
        effOutFilesErrors[Background][discr].close();
    } 
         
    DrawHists();

}

int main(){
    GeneralTauEfficiency();
}

