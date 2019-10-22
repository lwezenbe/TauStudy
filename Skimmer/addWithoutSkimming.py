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
    
