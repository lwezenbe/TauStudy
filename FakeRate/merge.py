import os
import glob

#Parse arguments
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--inData',              action='store_true')
argParser.add_argument('--year',                action='store',         default='2016')

args = argParser.parse_args()

if args.inData:
    data_str = 'DATA'
else:
    data_str = 'MC'

inputfolders = glob.glob('Data/tmp_fakeRate'+data_str+args.year)

for folder in inputfolders:
    name = folder.split('/')[-1].split('_')[-1]
    print name
    os.system('hadd -f Data/'+ name +'.root ' +folder+'/fakeRate*.root')
    os.system('rm -r '+folder)
