import ROOT, os, glob
import subSample
import jobSubmitter as sub
from helpers import makeDirIfNeeded

basefolderInput = '/user/lwezenbe/public/heavyNeutrino'
basefolderOutput = '/user/lwezenbe/public/trilep/SkimmedTuples'
makeDirIfNeeded(basefolderOutput)


list_of_samples = glob.glob(basefolderInput+'/*')

for f in list_of_samples:
    name = f.rsplit('/', 1)[1]
    command = 'hadd '+basefolderOutput+'/'+name+'.root '+ f +'/*.root'
    os.system(command)
    



#####OLD CODE###########
#different_samples = set()
#for f in list_of_samples:
#    split_f = f.split('/')
#    different_samples.add(split_f[8])
#
#for s in different_samples:
#    samples_to_hadd = ['hadd ' + basefolderOutput + '/' + s + '.root']
#    for f in list_of_samples:
#        if s in f:
#            samples_to_hadd.append(f + '/*/*/*.root')
#    command = ' '.join(samples_to_hadd)
#    log = basefolderOutput + '/' + s + '.log'
#    sub.launchCream02(command, log)
