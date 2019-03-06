import ROOT
from ROOT import gROOT, TCanvas, TH1D, gStyle, TColor, TGraphErrors
from numpy import zeros
import CMS_lumi, tdrstyle
import math


#Define some constants
NumberOfDiscr = 3
NumberOfWP = 5
NumberOfFracComp = 2
NumberOfSamples = 2

MVA_Old = 0
MVA_New = 1
Cut_based = 2

VLoose_MVA = 0
Loose_MVA = 1
Medium_MVA = 2
Tight_MVA = 3
VTight_MVA = 4

VVLoose_Cut = 0
VLoose_Cut = 1
Loose_Cut = 2
Medium_Cut = 3
Tight_Cut = 4

Background = 1
Signal = 0

Numerator = 0
Denominator = 1

sample = 0
FileName = "TTJets"

#set the tdr style
tdrstyle.setTDRStyle()

#Other draw options
gROOT.SetBatch(True)
gStyle.SetOptStat(0)
gStyle.SetPaintTextFormat("4.2f")
gROOT.ProcessLine( "gErrorIgnoreLevel = 1001;")

#Define array used to calculate the efficiency
Efficiency = zeros([NumberOfSamples, NumberOfDiscr, NumberOfWP])
EfficiencyErrors = zeros([NumberOfSamples, NumberOfDiscr, NumberOfWP])
nTauDenom = zeros([NumberOfSamples])

print Efficiency[Signal][1][1], Efficiency[Background][1][1]
# # print nTauDenom[Signal], nTauDenom[Background]

#Open Tree
infile = ROOT.TFile.Open("/user/lwezenbe/private/PhD/Trees/"+FileName+"_skimmedwcopytree.root", "read")
tree = infile.Get("blackJackAndHookersTree")

#Run over all entries and fill efficiency
for entry in tree :
    for lepton in xrange(ord(tree._nL)) :

        if (tree._lFlavor[lepton] != 2):
            continue

        if tree._lIsPrompt[lepton] :                               
            sample = Signal
        else :
            sample = Background 
        
        nTauDenom[sample] += 1.

        if not (tree._decayModeFindingNew[lepton]) :
            continue

        #Fill Efficiency
        if(tree._lPOGVeto[lepton]) :                      
           Efficiency[sample][MVA_Old][VLoose_MVA] += 1.
        if(tree._lPOGLoose[lepton]) :                     
           Efficiency[sample][MVA_Old][Loose_MVA] += 1.
        if(tree._lPOGMedium[lepton]) :                    
           Efficiency[sample][MVA_Old][Medium_MVA] += 1.
        if(tree._lPOGTight[lepton]) :                     
           Efficiency[sample][MVA_Old][Tight_MVA] += 1.
        if(tree._tauVTightMvaOld[lepton]) :               
           Efficiency[sample][MVA_Old][VTight_MVA] += 1.

        if(tree._tauVLooseMvaNew[lepton]) :               
           Efficiency[sample][MVA_New][VLoose_MVA] += 1.
        if(tree._tauLooseMvaNew[lepton]) :                
           Efficiency[sample][MVA_New][Loose_MVA] += 1.
        if(tree._tauMediumMvaNew[lepton]) :               
           Efficiency[sample][MVA_New][Medium_MVA] += 1.
        if(tree._tauTightMvaNew[lepton]) :                
           Efficiency[sample][MVA_New][Tight_MVA] += 1.
        if(tree._tauVTightMvaNew[lepton]) :               
           Efficiency[sample][MVA_New][VTight_MVA] += 1.
        
        if(tree._tauCombinedIsoDBRaw3Hits[lepton] < 4.5) :                
           Efficiency[sample][Cut_based][VVLoose_Cut] += 1.
        if(tree._tauCombinedIsoDBRaw3Hits[lepton] < 3.5) :                
           Efficiency[sample][Cut_based][VLoose_Cut] += 1.
        if(tree._tauCombinedIsoDBRaw3Hits[lepton] < 2.0) :                
           Efficiency[sample][Cut_based][Loose_Cut] += 1.
        if(tree._tauCombinedIsoDBRaw3Hits[lepton] < 1.0) :                
           Efficiency[sample][Cut_based][Medium_Cut] += 1.
        if(tree._tauCombinedIsoDBRaw3Hits[lepton] < 0.8) :                
           Efficiency[sample][Cut_based][Tight_Cut] += 1.

#Calculate efficiency and errors
for discriminator in xrange(NumberOfDiscr) :
    for WP in xrange(NumberOfWP) :
        EfficiencyErrors[Signal][discriminator][WP] = (math.sqrt(Efficiency[Signal][discriminator][WP])/nTauDenom[Signal])*100
        Efficiency[Signal][discriminator][WP] = (Efficiency[Signal][discriminator][WP]/nTauDenom[Signal])*100   
        EfficiencyErrors[Background][discriminator][WP] = (math.sqrt(Efficiency[Background][discriminator][WP])/nTauDenom[Background])*100
        Efficiency[Background][discriminator][WP] = (Efficiency[Background][discriminator][WP]/nTauDenom[Background])*100

        print discriminator, WP, EfficiencyErrors[Signal][discriminator][WP], Efficiency[Signal][discriminator][WP], nTauDenom[Signal], EfficiencyErrors[Background][discriminator][WP], Efficiency[Background][discriminator][WP], nTauDenom[Background]

#Create ROC graphs
ROCmvaOld = TGraphErrors(5, Efficiency[Background][MVA_Old], Efficiency[Signal][MVA_Old], EfficiencyErrors[Background][MVA_Old], EfficiencyErrors[Signal][MVA_Old])
c1 = TCanvas("c1, c1")
# c1.SetLogx()
ROCmvaOld.SetTitle("; Efficiency in Background (%); Efficiency in Signal (%)")
ROCmvaOld.SetMarkerSize(.5)
# ROCmvaOld.GetXaxis().SetLimits(20, 100)
ROCmvaOld.Draw("AP")
CMS_lumi.CMS_lumi(c1, 4, 11)
c1.SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_MVAOld.pdf")
c1.SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_MVAOld.png")

ROCmvaNew = TGraphErrors(5, Efficiency[Background][MVA_New], Efficiency[Signal][MVA_New], EfficiencyErrors[Background][MVA_New], EfficiencyErrors[Signal][MVA_New])
c2 = TCanvas("c2, c2")
# c2.SetLogx()
ROCmvaNew.SetTitle("; Efficiency in Background (%); Efficiency in Signal (%)")
ROCmvaNew.SetMarkerSize(.5)
# ROCmvaNew.GetXaxis().SetLimits(20, 100)
ROCmvaNew.Draw("AP")
CMS_lumi.CMS_lumi(c2, 4, 11)
c2.SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_MVANew.pdf")
c2.SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_MVANew.png")

ROCCuts = TGraphErrors(5, Efficiency[Background][Cut_based], Efficiency[Signal][Cut_based], EfficiencyErrors[Background][Cut_based], EfficiencyErrors[Signal][Cut_based])
c3 = TCanvas("c3, c3")
# c3.SetLogx()
ROCCuts.SetTitle("; Efficiency in Background (%); Efficiency in Signal (%)")
ROCCuts.SetMarkerSize(.5)
# ROCCuts.GetXaxis().SetLimits(20, 100)
ROCCuts.Draw("AP")
CMS_lumi.CMS_lumi(c3, 4, 11)
c3.SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_Cuts.pdf")
c3.SaveAs("/user/lwezenbe/private/PhD/Results/TauStudy/EWKino/ROC/"+FileName+"/ROC_Cuts.png")