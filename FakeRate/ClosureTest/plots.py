import plottingTools as plt
from helpers import getObjFromFile, makeDirIfNeeded, makePathTimeStamped
import glob, os
import jobSubmitter as sub

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--year',                action='store',         default='2016')
argParser.add_argument('--inData',              action='store',         default='') 
args = argParser.parse_args()

if args.inData:
    inData_Str = 'DATA'
else:
    inData_Str = 'MC'

input_dir = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/Data/'+args.year+'/'+inData_Str
output_dir = makePathTimeStamped('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/ClosureTest/'+args.year+'/'+inData_Str)

sampleNames = [x.rsplit('/', 1)[-1] for x in glob.glob(input_dir+'/*')]

if not args.inData:
    for sample in sampleNames:
        #log = sample+'.txt'
        command = 'python tmpplotter.py '+sample+ ' ' + input_dir + ' ' + output_dir
        #sub.runLocal(command, log)
        os.system(command)

else:
        command = 'python plotData.py --year='+args.year
        os.system(command)
