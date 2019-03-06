import ROOT
from plottingTools import calcAndDrawSignificance, extraTextFormat
from helpers import makePathTimeStamped, getObjFromFile

basefolderInput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Merged'
basefolderOutput = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Significance/Plots'

background_names = ['VV', 'QCD', 'ST', 'TT', 'WJets', 'DYJets']
signal_names = ['TChiWZ', 'TChiSlepSnu_x0p5', 'TChiSlepSnu_x0p05']

workingPoints = ('VLoose', 'Loose', 'Medium', 'Tight', 'VTight')

background_hists = []
signal_hists = []

ntau = ['singletau', 'ditau']

for n in ntau:
    tmp_hists = []
    for bkgr in background_names:
        tmp_hists.append(getObjFromFile(basefolderInput+'/'+bkgr+'_'+n+'.root', n))
    background_hists.append(tmp_hists)
    tmp_hists = []
    for sig in signal_names:
        tmp_hists.append(getObjFromFile(basefolderInput+'/'+sig+'_'+n+'.root', n))
    signal_hists.append(tmp_hists)
       

basefolderOutput = makePathTimeStamped(basefolderOutput) 
for i, tn in enumerate(ntau):
    for s, hn in zip(signal_hists[i], signal_names):
        extraText = []
        extraText.append(extraTextFormat(tn + ' channel', 0.5, 0.9, None))
        extraText.append(extraTextFormat('m_{#chi_{1}} = 200 GeV'))
        extraText.append(extraTextFormat('m_{#chi_{2}} = 300 GeV'))

        out_path =  basefolderOutput + '/'+hn+'_'+tn
        calcAndDrawSignificance(s, background_hists[i], 'working point', background_names, [hn], out_path, ylog = True, customLabels=workingPoints, extraText=extraText) 
