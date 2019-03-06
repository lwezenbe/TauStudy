import ROOT, glob
import plottingCode as plt
from helpers import getObjFromFile

basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Sig'
basefolderOutput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Plots'

list_of_files = glob.glob(basefolder + '/*.root')

list_of_singletau_hist  = []
list_of_ditau_hist      = []

for f in list_of_files:
    sample, ntau = f.split('/')[11].split('_')
    ntau = ntau.split('.')[0]
    if ntau == 'singletau':
        hname = 'Single_Tau_Output'
    elif ntau == 'ditau':
        hname = 'Di_Tau_Output'
    hist = getObjFromFile(f, hname)
    if ntau == 'singletau':
        list_of_singletau_hist.append(hist)
    elif ntau == 'ditau':
        list_of_ditau_hist.append(hist)

file_path = basefolderOutput + '/singletau'
plt.DrawSignificance(list_of_singletau_hist, file_path)    
   
file_path = basefolderOutput + '/ditau'
plt.DrawSignificance(list_of_ditau_hist, file_path)    
