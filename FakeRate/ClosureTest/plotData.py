import plottingTools as plt
from helpers import getObjFromFile, makeDirIfNeeded, makePathTimeStamped
import glob, os
import jobSubmitter as sub

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--year',                action='store',         default='2016')
args = argParser.parse_args()

input_dir = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/Data/'+args.year+'/DATA'
output_dir = makePathTimeStamped('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/ClosureTest/'+args.year+'/DATA')

sampleNames = [x.rsplit('/', 1)[-1] for x in glob.glob(input_dir+'/*')]

varNames = ['ptTau', 'etaTau', 'Mll', 'met']
xtitle_map = {'ptTau': 'P_{T}(#tau) [GeV]', 'etaTau': '#eta(#tau)', 'Mll': 'M(ll) [GeV]', 'met':'E_{T}^{miss} [GeV]'}
ytitle_map = {'ptTau': 'Taus', 'etaTau': 'Taus', 'Mll': 'Events', 'met':'Events'}
log_map = {'ptTau': False, 'etaTau': False, 'Mll': True, 'met':True}

for var in varNames:
    predicted = []
    observed = None
    store_data_observed = None
    legendNames = []
    for sample in sampleNames:
        f = glob.glob(input_dir + '/' + sample + '/*'+var+'.root')
        if sample == 'Data_'+args.year:
            observed = getObjFromFile(f[0], 'inData_'+var)
            store_data_observed = getObjFromFile(f[0], 'inData_'+var+'_sideBand')
        else:
            tmp_pred = getObjFromFile(f[0], 'inData_'+var)
            tmp_pred_corr = getObjFromFile(f[0], 'inData_'+var+'_sideBand')
            tmp_pred.Add(tmp_pred_corr, -1.)
            predicted.append(tmp_pred)
            legendNames.append(sample)
    predicted.append(store_data_observed)
    legendNames.append('nonprompt')
    
    plt.plotDataVSMC(observed, predicted, xtitle_map[var], legendNames, 'Data',  output_dir+'/'+var, ytitle_bottom = 'Measured/pred.')
    


