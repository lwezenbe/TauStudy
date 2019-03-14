import ROOT, glob, os

basefolderInput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Histos'
basefolderOutput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Merged'
samples = ['TT', 'DYJets', 'QCD', 'TChiWZ', 'TChiSlepSnu_x0p5', 'TChiSlepSnu_x0p05', 'ST', 'WJets', 'VV']

NUMBER_OF_ELE_WP = 6
NUMBER_OF_MU_WP = 3


for sample in samples:
    for mu in range(NUMBER_OF_MU_WP):
        for ele in range(NUMBER_OF_ELE_WP):
            os.system('hadd -f ' + basefolderOutput + '/' + sample + '_singletau_'+str(ele)+'_'+str(mu)+'.root ' + basefolderInput + '/' + sample + '/*_singletau_'+str(ele)+'_'+str(mu)+'*.root')  
            os.system('hadd -f ' + basefolderOutput + '/' + sample + '_ditau_'+str(ele)+'_'+str(mu)+'.root ' + basefolderInput + '/' + sample + '/*_ditau_'+str(ele)+'_'+str(mu)+'*.root')  
            #for f in glob.glob(basefolderInput + '/' + sample + '/*_singletau_'+str(ele)+'_'+str(mu)+'*.root'):
            #    os.remove(f)
            #for f in glob.glob(basefolderInput + '/' + sample + '/*_ditau_'+str(ele)+'_'+str(mu)+'*.root'):
            #    os.remove(f)
           
    
