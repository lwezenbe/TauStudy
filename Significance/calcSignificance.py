import ROOT, glob, os
from helpers import getObjFromFile
from numpy import sqrt

basefolderInput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Merged'
basefolderOutput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Sig'

background_names = ['TT']
signal_names = ['TT']

def calcAndSaveSignificance(filecateg, namecateg):
    background_hist = getObjFromFile(basefolderInput + '/' + background_names[0] + '_' +filecateg+'.root', namecateg)
    for bkgr in background_names[1:]:
        background_hist.Add(getObjFromFile(basefolderInput + '/' + bkgr+ '_' +filecateg+'.root', namecateg))

    for signal in signal_names:
        significance = getObjFromFile(basefolderInput + '/' + signal + '_' +filecateg+'.root', namecateg)
        total = significance.Clone('Total_Output')
        total.Add(background_hist)
        sqrt_total = total.Clone('Sqrt_Total_Output')
        for xbin in xrange(1, total.GetSize()-1):                     #GetSize returns nbins + 2 (for overflow and underflow bin)
            sqrt_total.SetBinContent(xbin, sqrt(total.GetBinContent(xbin)))

        significance.Divide(sqrt_total)
        significance.SaveAs(basefolderOutput + '/' + signal + '_' +filecateg+'.root')

calcAndSaveSignificance('singletau', 'Single_Tau_Output')
calcAndSaveSignificance('ditau', 'Di_Tau_Output')
