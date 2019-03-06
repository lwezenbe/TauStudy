import ROOT, glob, os

basefolderInput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Histos'
basefolderOutput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Merged'
samples = ['TT', 'DYJets', 'QCD', 'TChiWZ', 'TChiSlepSnu_x0p5', 'TChiSlepSnu_x0p05', 'ST', 'WJets', 'VV']

for sample in samples:
    os.system('hadd -f ' + basefolderOutput + '/' + sample + '_singletau.root ' + basefolderInput + '/' + sample + '_singletau*.root')  
    os.system('hadd -f ' + basefolderOutput + '/' + sample + '_ditau.root ' + basefolderInput + '/' + sample + '_ditau*.root')  
    for f in glob.glob(basefolderInput + '/' + sample + '_singletau*.root'):
        os.remove(f)
    for f in glob.glob(basefolderInput + '/' + sample + '_ditau*.root'):
        os.remove(f)
       
    
