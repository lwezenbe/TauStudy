import ROOT, os, glob
import jobSubmitter as sub
import argparse

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--f',           action='store',         default=None)
argParser.add_argument('--Input',       action='store',         default=None)
argParser.add_argument('--Output',      action='store',         default=None)

args = argParser.parse_args()

print args.f

split_f = args.f.rsplit('/', 1)
subsplit_f = split_f[1].split('_', 1)
os.system('hadd -f '+args.Output+'/'+subsplit_f[1]+'.root '+args.f+'/*.root')
#os.system('rm -r '+args.f)

