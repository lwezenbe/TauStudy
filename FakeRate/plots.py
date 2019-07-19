import plottingTools as plt
import fakeRateCalculator
from helpers import makeDirIfNeeded

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

output_str = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots/'+indata_str+args.year+'/tightToLoose'


makeDirIfNeeded('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots')
makeDirIfNeeded('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots/'+indata_str+args.year)


FR = fakeRateCalculator.fakeRateCalculator(args.year, indata_str)
tightToLoose = FR.getTightToLoose()

plt.draw2DHist(tightToLoose, 'p_{T} [GeV]', '|#eta|', output_str)
