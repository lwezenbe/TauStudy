import ROOT
from plottingTools import calcAndDrawSignificance, extraTextFormat
from helpers import makeDirIfNeeded, makePathTimeStamped, getObjFromFile

basefolderInput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Merged'
basefolderOutput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Plots'

#background_names = ['WJets', 'VV', 'ST', 'TT', 'DYJets']                       #singletau
background_names = ['VV', 'DYJets','ST', 'TT', 'WJets']                         #ditau
#signal_names = ['TChiWZ', 'TChiSlepSnu_x0p5', 'TChiSlepSnu_x0p05']
signal_names = ['TChiStauStau', 'TChiSlep_tauEnr_x0p5', 'TChiSlep_tauEnr_x0p05']

IsoWorkingPoints = ('VLoose', 'Loose', 'Medium', 'Tight', 'VTight')
EleWorkingPoints = ('No discr', 'VLoose', 'Loose', 'Medium', 'Tight', 'VTight')
MuWorkingPoints = ('No discr', 'Loose', 'Tight')

NUMBER_OF_ELE_WP = 6
NUMBER_OF_MU_WP = 3

background_hists = []
signal_hists = []

background_hists_comb = []
signal_hists_comb = []

ntau = ['singletau', 'ditau']
#scales = (1./280., 1./281., 1./237)
scales = (1., 1., 1.)
for n in ntau:
    tmp_mu_hists_bkgr = []
    tmp_mu_hists_sig = []
    for mu_cut_index in range(NUMBER_OF_MU_WP):
        tmp_hists = []        
        for bkgr in background_names:
            tmp_hists.append(getObjFromFile(basefolderInput+'/Combined/'+bkgr+'_'+n+'_'+str(mu_cut_index)+'.root', 'combined_hist'+bkgr+n+str(mu_cut_index)))
        tmp_mu_hists_bkgr.append(tmp_hists)
        tmp_hists = []
        for sig, scale in zip(signal_names, scales):
            hist = getObjFromFile(basefolderInput+'/Combined/'+sig+'_'+n+'_'+str(mu_cut_index)+'.root', 'combined_hist'+sig+n+str(mu_cut_index))
            hist.Scale(scale)
            tmp_hists.append(hist)
        tmp_mu_hists_sig.append(tmp_hists)
    background_hists_comb.append(tmp_mu_hists_bkgr)
    signal_hists_comb.append(tmp_mu_hists_sig)


for n in ntau:
    tmp_mu_hists_bkgr = []
    tmp_mu_hists_sig = []
    for mu_cut_index in range(NUMBER_OF_MU_WP):

        tmp_hists_ele_sig = []
        tmp_hists_ele_bkgr = []
        for ele_cut_index in range(NUMBER_OF_ELE_WP):
            tmp_hists = []
            for bkgr in background_names:
                tmp_hists.append(getObjFromFile(basefolderInput+'/'+bkgr+'_'+n+'_'+str(ele_cut_index)+'_'+str(mu_cut_index)+'.root', n))
            tmp_hists_ele_bkgr.append(tmp_hists)
            tmp_hists = []
            for sig, scale in zip(signal_names, scales):
                hist = getObjFromFile(basefolderInput+'/'+sig+'_'+n+'_'+str(ele_cut_index)+'_'+str(mu_cut_index)+'.root', n)
                hist.Scale(scale)
                tmp_hists.append(hist)
                
            tmp_hists_ele_sig.append(tmp_hists)
        tmp_mu_hists_bkgr.append(tmp_hists_ele_bkgr)
        tmp_mu_hists_sig.append(tmp_hists_ele_sig)

    background_hists.append(tmp_mu_hists_bkgr)
    signal_hists.append(tmp_mu_hists_sig)

basefolderOutput = makePathTimeStamped(basefolderOutput) 
specific_mass = True
mchi1 = '150'
mchi2 = '250'
for i, tn in enumerate(ntau):
    for mu_cut_index, muname in enumerate(MuWorkingPoints):
        for ele_cut_index, ename in enumerate(EleWorkingPoints):
            for s, hn in zip(signal_hists[i][mu_cut_index][ele_cut_index], signal_names):
                extraText = []
                extraText.append(extraTextFormat(tn + ' channel', 0.5, 0.9, None))
                extraText.append(extraTextFormat('Muon discr: ' + muname))
                extraText.append(extraTextFormat('Electron discr: ' + ename))
                if specific_mass:
                    extraText.append(extraTextFormat('m_{#chi_{1}} = '+mchi1+' GeV'))
                    extraText.append(extraTextFormat('m_{#chi_{2}} = '+mchi2+' GeV'))
                    
                out_path =  basefolderOutput + '/'+hn+'_'+tn+'_'+str(ele_cut_index)+'_'+str(mu_cut_index)
                calcAndDrawSignificance(s, background_hists[i][mu_cut_index][ele_cut_index], 'Iso working point', background_names, [hn], out_path, ylog = True, customLabels=IsoWorkingPoints, extraText=extraText) 


basefolderOutput = basefolderOutput+'/Combined'
makeDirIfNeeded(basefolderOutput)
for i, tn in enumerate(ntau):
    for mu_cut_index, muname in enumerate(MuWorkingPoints):

        for s, hn in zip(signal_hists_comb[i][mu_cut_index], signal_names):
            extraText = []
            extraText.append(extraTextFormat(tn + ' channel', 0.5, 0.9, None))
            extraText.append(extraTextFormat('Muon discr: ' + muname))
            if specific_mass:
                extraText.append(extraTextFormat('m_{#chi_{1}} = '+mchi1+' GeV'))
                extraText.append(extraTextFormat('m_{#chi_{2}} = '+mchi2+' GeV'))

            line_division = (6, EleWorkingPoints)

            out_path =  basefolderOutput + '/'+hn+'_'+tn+'_'+str(mu_cut_index)
            calcAndDrawSignificance(s, background_hists_comb[i][mu_cut_index], 'Iso working point', background_names, [hn], out_path, ylog = True, customLabels=IsoWorkingPoints, extraText=extraText, DivideByLine=line_division)

for i, tn in enumerate(ntau):
    for mu_cut_index, muname in enumerate(MuWorkingPoints):
        extraText = []
        extraText.append(extraTextFormat(tn + ' channel', 0.5, 0.9, None))
        extraText.append(extraTextFormat('Muon discr: ' + muname))
        if specific_mass:
            extraText.append(extraTextFormat('m_{#chi_{1}} = '+mchi1+' GeV'))
            extraText.append(extraTextFormat('m_{#chi_{2}} = '+mchi2+' GeV'))

        line_division = (6, EleWorkingPoints)

        out_path =  basefolderOutput + '/total_'+tn+'_'+str(mu_cut_index)
        calcAndDrawSignificance(signal_hists_comb[i][mu_cut_index], background_hists_comb[i][mu_cut_index], 'Iso working point', background_names, signal_names, out_path, ylog = True, customLabels=IsoWorkingPoints, extraText=extraText, DivideByLine=line_division)
