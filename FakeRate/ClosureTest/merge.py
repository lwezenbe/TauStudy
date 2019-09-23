import os, argparse
import glob

argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--isCheck',             action='store',         default=False) #Check needs to be finished
argParser.add_argument('--inData',             action='store',         default=False) 
argParser.add_argument('--year',             action='store',         default='2016') 
args = argParser.parse_args()

if args.inData:
    inData_str='DATA'
else:
    inData_str='MC'
input_dir = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/Data/'+args.year+'/'+inData_str

sampleNames = [x.rsplit('/', 1)[-1] for x in glob.glob(input_dir+'/*')]
print sampleNames

if not args.isCheck:    
    varNames = ['ptTau', 'etaTau', 'Mll', 'met']
    if not args.inData:
        categNames = ['Categ_C', 'Categ_D', 'Categ_E', 'Categ_F']
    else:
        categNames = ['inData']
else:   
    categNames = ['Check']
    varNames = ['ptTau', 'etaTau']
    sampleNames = ['DYJets']

print sampleNames
for sample in sampleNames:
    if sample == "DYJets": continue
    for var in varNames:
        for categ in categNames:
            os.system('hadd -f ' + input_dir + '/'+ sample +'/' +categ+'_' + var + '.root ' + input_dir + '/'+ sample +'/*_'+categ+'_' + var + '.root')        
            os.system('rm ' +input_dir + '/'+ sample +'/*_' +categ+'_' + var + '.root')        
