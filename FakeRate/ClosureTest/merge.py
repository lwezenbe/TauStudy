import os, argparse
import glob

def strInList(in_str, in_list):
    
    for el in in_list:
        if in_str in el:        return True
    return False


argParser = argparse.ArgumentParser(description = "Argument parser")
argParser.add_argument('--inData',             action='store',         default=False) 
argParser.add_argument('--year',             action='store',         default='2016') 
args = argParser.parse_args()

if args.inData:
    inData_str='DATA'
else:
    inData_str='MC'
input_dir = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/ClosureTest/Data/'+args.year+'/'+inData_str

sampleNames = [x.rsplit('/', 1)[-1] for x in glob.glob(input_dir+'/*')]

varNames = ['ptTau', 'etaTau', 'Mll', 'met']
if not args.inData:
    categNames = ['Categ_C', 'Categ_D', 'Categ_E', 'Categ_F', 'Check']
else:
    categNames = ['inData']

for sample in sampleNames:
    all_file_names = glob.glob(input_dir+'/'+sample+'/*subJob*root')
    for var in varNames:
        if not strInList(var, all_file_names): continue
        for categ in categNames:
            if not strInList(categ, all_file_names): continue
            os.system('hadd -f ' + input_dir + '/'+ sample +'/' +categ+'_' + var + '.root ' + input_dir + '/'+ sample +'/*_'+categ+'_' + var + '.root')        
            os.system('rm ' +input_dir + '/'+ sample +'/*_' +categ+'_' + var + '.root')        
