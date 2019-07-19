import ROOT
from helpers import getObjFromFile

basefolder = '/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Merged'

NUMBER_OF_ELE_WP = 6
NUMBER_OF_MU_WP = 3
NUMBER_OF_ISO_WP = 5

ntau = ('singletau', 'ditau')

background_names = ['VV', 'QCD', 'ST', 'TT', 'WJets', 'DYJets']
#background_names = []
#signal_names = ['TChiWZ', 'TChiSlepSnu_x0p5', 'TChiSlepSnu_x0p05']
signal_names = ['TChiStauStau', 'TChiSlep_tauEnr_x0p5', 'TChiSlep_tauEnr_x0p05']
#signal_names = []

def merge_specific_sample(sample_name, number_of_taus):
    
    #Outer loop over muon working points, we will keep these files separate
    for mu_cut_index in range(NUMBER_OF_MU_WP):
        number_of_bins_needed = NUMBER_OF_ELE_WP*NUMBER_OF_ISO_WP
        combined_hist = ROOT.TH1D("combined_hist"+sample_name+str(number_of_taus)+str(mu_cut_index), "combined_hist"+sample_name+str(number_of_taus)+str(mu_cut_index), number_of_bins_needed, 0, number_of_bins_needed)
    
        #Inner loop over electron working points, merge these into single plot
        for ele_cut_index in range(NUMBER_OF_ELE_WP):
            print basefolder+'/'+sample_name+'_'+number_of_taus+'_'+str(ele_cut_index)+'_'+str(mu_cut_index)+'.root'
            tmp_hist = getObjFromFile(basefolder+'/'+sample_name+'_'+number_of_taus+'_'+str(ele_cut_index)+'_'+str(mu_cut_index)+'.root', number_of_taus)
            nBins = tmp_hist.GetNbinsX()
            for tmp_hist_bin in range(1, nBins+1):
                combined_hist.SetBinContent(ele_cut_index*nBins+tmp_hist_bin, tmp_hist.GetBinContent(tmp_hist_bin))
                
    
        combined_hist.SaveAs(basefolder + '/Combined/'+ sample_name + '_'+number_of_taus + '_' + str(mu_cut_index)+ '.root')

for n in ntau:
    for bkgr in background_names:
        merge_specific_sample(bkgr, n)
    for sig in signal_names:
        merge_specific_sample(sig, n)
