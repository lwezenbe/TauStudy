import plottingTools as plt
from helpers import getObjFromFile, makeDirIfNeeded, makePathTimeStamped, CleanNegativeBins
import argparse, glob

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('sample',          action='store')
argParser.add_argument('input_dir',          action='store')
argParser.add_argument('output_dir',          action='store')
args = argParser.parse_args()

xtitle_map = {'ptTau': 'P_{T}(#tau) [GeV]', 'etaTau': '#eta(#tau)', 'Mll': 'M(ll) [GeV]', 'met':'E_{T}^{miss} [GeV]'}
ytitle_map = {'ptTau': 'Taus', 'etaTau': 'Taus', 'Mll': 'Events', 'met':'Events'}
log_map = {'ptTau': False, 'etaTau': False, 'Mll': True, 'met':True}
categ_map = {'Categ_C': 'C: OSSF + #tau', 'Categ_D': 'D: OSOF + #tau', 'Categ_E': 'E: SS + #tau' , 'Categ_F':'F: e/#mu + #tau#tau'}

makeDirIfNeeded(args.output_dir+'/'+args.sample)
file_paths = glob.glob(args.input_dir + '/' + args.sample + '/Categ*.root')

for f in file_paths:
    print f
    h_name = f.rsplit('/', 1)[1]
    h_name = h_name.split('.')[0]
    split_names = h_name.rsplit('_', 1) 
    categ_name = split_names[0]
    var_name = split_names[1]
    extraText = []
    if categ_name in categ_map.keys():
        extraText.append(plt.extraTextFormat(categ_map[categ_name], 0.5, 0.9))
    
    dist_observed = getObjFromFile(f, h_name)
    dist_predicted = getObjFromFile(f, h_name+'_sideBand')
    plt.plotClosure(CleanNegativeBins(dist_observed), CleanNegativeBins(dist_predicted), xtitle_map[var_name], ytitle_map[var_name], args.sample, extraText, args.output_dir + '/' +args.sample+'/'+h_name, yLog=log_map[var_name])

