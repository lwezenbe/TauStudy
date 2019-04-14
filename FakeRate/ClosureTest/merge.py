import os

sampleNames = ['DYJets']
#sampleNames = ['TT', 'DYJets']
varNames = ['pt_tau', 'eta_tau', 'Mll', 'met']
categNames = ['Categ_C', 'Categ_D', 'Categ_E', 'Categ_F']
input_dir = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/ClosureTest'

for sample in sampleNames:
    for var in varNames:
        for categ in categNames:
            os.system('hadd -f ' + input_dir + '/'+ sample +'/' +categ+'_' + var + '.root ' + input_dir + '/'+ sample +'/*_'+categ+'_' + var + '.root')        
            os.system('rm ' +input_dir + '/'+ sample +'/*_' +categ+'_' + var + '.root')        
