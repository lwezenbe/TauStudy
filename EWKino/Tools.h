#include "ConstantsROC.h"

void inputFileName(){
    TString InputSignalFileNames[3] = {"TChiWZ", "TChiSlepSnu_x0p5", "TChiSlepSnu_x0p05"};
    TString InputBkgrFileNames[3] = {"WZTo3LNu", "TTJets", "DYJets"};
    Int_t RawInputSignal;
    Int_t RawInputBkgr;
    Double_t mass1;
    Double_t mass2;
    cout << "Which sample would you like to use as signal?" << endl << "0. TChiWZ" << endl << "1. TChiSlepSnu_x0p5" << endl << "2. TChiSlepSnu_x0p05" << endl;
    cin >> RawInputSignal;
    cout << "Define Masses" << endl;
    cin >> mass1 >> mass2;
    cout << endl << "Which sample would you like to use as background?" << endl << "0. WZ" << endl << "1. TTjets" << endl << "2. DYJets" << endl;
    cin >> RawInputBkgr;

    FileName[Signal] = InputSignalFileNames[RawInputSignal];
    FileName[Background] = InputBkgrFileNames[RawInputBkgr];
    m1 = mass1;
    m2 = mass2;
}
