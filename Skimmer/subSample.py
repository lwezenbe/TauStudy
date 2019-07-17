import os
import ROOT, glob
from helpers import getObjFromFile


class subSample():
    
    MAX_FILESIZE_PER_JOB = 900                      #FileSize in MB

    def __init__(self, path, subdir):
        self.subdir      = subdir
        self.path        = path
        self.listOfAllFiles = sorted(glob.glob(path+'/*/000'+str(subdir)+'/*.root'))
        self.listOfSubjobs = None        

        #get correct naming first
        split_up_path   = self.path.split('/')
        self.group      = split_up_path[-2]
        self.name       = split_up_path[-1]
        self.Chain       = None

    @staticmethod
    def fileSize(path):              #return filesize in MB
        file_info = os.stat(path)
        file_size = file_info.st_size
        file_size_MB = 0.000001*file_size
        return file_size_MB

    def arrangeFilesInSubjobs(self):
        self.listOfSubjobs = []
        total_size = 0
        tmp_list = []
        for f in self.listOfAllFiles:
            tmp_size = total_size + self.fileSize(f)
            if tmp_size < self.MAX_FILESIZE_PER_JOB:
                tmp_list.append(f)
                total_size = tmp_size
            else:       #Append, Reset counter and tmp
                self.listOfSubjobs.append(tmp_list)
                tmp_list = [f]
                total_size = self.fileSize(f)
        return self.listOfSubjobs

    #Get combined hCounter or hCounterSUSY 
    def getHist(self, subjob, name, subPath = None):                                            
        if subPath is None:             subPath = self.path
        if subPath.endswith('.root'):
            hCounter                    = getObjFromFile(subPath, 'blackJackAndHookers/'+name)
            return hCounter
        else:
            hCounter = None
            for f in self.arrangeFilesInSubjobs()[subjob]:
                if hCounter is None:     hCounter = self.getHist(subjob,name, f)
                else:                    hCounter.Add(self.getHist(subjob, name, f))
                print hCounter.GetSumOfWeights()
            return hCounter
    
    def initChain(self, subjob):
        self.Chain              = ROOT.TChain('blackJackAndHookers/blackJackAndHookersTree')
        
        for f in self.arrangeFilesInSubjobs()[subjob]:
            if 'pnfs' in f:
                f = 'root://maite.iihe.ac.be'+f
            self.Chain.Add(f)

        return self.Chain 

def createSampleList(fileName):
    sampleInfos = [line.split('%')[0].strip() for line in open(fileName)]                     # Strip % comments and \n charachters
    sampleInfos = [line.split() for line in sampleInfos if line]                              # Get lines into tuples
    
    list_of_paths = []
    for sample in sampleInfos:
        list_of_paths += glob.glob(sample[0])
    return list_of_paths

if __name__ == "__main__":
    #s = subSample('/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_MiniAOD2016v3_ext1-v2_2016-v1', 0)   
    s = subSample('/pnfs/iihe/cms/store/user/lwezenbe/heavyNeutrino/SingleMuon/crab_Run2016H-17Jul2018-v1_ForJana', 0)   
    x = s.arrangeFilesInSubjobs()
    print len(x)
    for sub in s.listOfSubjobs:
        total = 0
        for j in sub:
            total += s.fileSize(j)
            print j, s.fileSize(j)        
        print total
