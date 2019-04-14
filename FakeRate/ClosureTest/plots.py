import plottingTools as plt
from helpers import getObjFromFile, makeDirIfNeeded, makePathTimeStamped
import glob

sampleNames = ['TT', 'DYJets']
#sampleNames = ['DYJets']
categNames = ['Categ_C', 'Categ_D', 'Categ_E', 'Categ_F']
input_dir = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/ClosureTest'
output_dir = makePathTimeStamped(input_dir + '/Plots')

for sample in sampleNames:
    makeDirIfNeeded(output_dir+'/'+sample)    
    file_paths = glob.glob(input_dir + '/' + sample + '/*.root')
    for f in file_paths:
        var_name = f.rsplit('/', 1)[1]
        var_name = var_name.split('.')[0]

        dist_observed = getObjFromFile(f, var_name)
        dist_predicted = getObjFromFile(f, var_name+'_sideBand')
        
        plt.plotClosure(dist_observed, dist_predicted, var_name, sample, output_dir + '/' +sample+'/'+var_name)
