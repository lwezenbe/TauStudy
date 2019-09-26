import plottingTools as plt
import fakeRateCalculator
from helpers import makeDirIfNeeded, makePathTimeStamped

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--inData',              action='store',         default=None)
argParser.add_argument('--year',                action='store',         default='2016')

args = argParser.parse_args()

if args.inData:
    indata_str = 'DATA'
else:
    indata_str = 'MC'

output_dir = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots/'+indata_str+args.year


makeDirIfNeeded('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots')
makeDirIfNeeded('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots/'+indata_str+args.year)
makePathTimeStamped(output_dir)

FR = fakeRateCalculator.fakeRateCalculator(args.year, indata_str)
tightToLoose = FR.getTightToLoose()

output_str = output_dir+'/tightToLoose'

plt.draw2DHist(tightToLoose, 'p_{T} [GeV]', '|#eta|', output_str)
