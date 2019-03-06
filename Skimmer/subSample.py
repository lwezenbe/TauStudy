import ROOT, glob
from helpers import getObjFromFile


class subSample():
    
    FILES_PER_JOB = 5.

    def __init__(self, path, subdir):
        self.subdir      = subdir
        self.path        = path
        self.listOfFiles = glob.glob(path+'/*/000'+str(subdir)+'/*.root')
        
        #get correct naming first
        split_up_path   = self.path.split('/')
        self.group      = split_up_path[8]
        self.name       = split_up_path[9]
        if 'SingleMuon' in self.group:
            self.FILES_PER_JOB = 10.
        if 'TTJets' in self.group or 'QCD_HT1000to1500' in self.group: 
            self.FILES_PER_JOB = 10.
        
        self.totalJobs   = int((len(self.listOfFiles)/self.FILES_PER_JOB)+0.5)
        self.Chain       = None
        


    def getFileRange(self, subjob):
        limits = None
        if subjob < self.totalJobs-1:
            limits =  [(subjob*self.FILES_PER_JOB)+1, ((subjob + 1)*self.FILES_PER_JOB)+1]
        elif subjob == self.totalJobs-1:
            limits =  [(subjob*self.FILES_PER_JOB)+1, len(self.listOfFiles)]
        return xrange(int(limits[0]), int(limits[1]))

    def gethCounter(self, subPath = None):
        if subPath is None:             subPath = self.path
        if subPath.endswith('.root'):
            hCounter                    = getObjFromFile(subPath, 'blackJackAndHookers/hCounter')
            return hCounter
        else:
            hCounter = None
            for f in self.listOfFiles:
                if hCounter is None:     hCounter = self.gethCounter(f)
                else:                    hCounter.Add(self.gethCounter(f))
            return hCounter
    
    def gethCounterSUSY(self, subPath = None):
        if subPath is None:             subPath = self.path
        if subPath.endswith('.root'):
            hCounter                    = getObjFromFile(subPath, 'blackJackAndHookers/hCounterSUSY')
            return hCounter
        else:
            hCounter = None
            for f in self.listOfFiles:
                if hCounter is None:     hCounter = self.gethCounterSUSY(f)
                else:                    hCounter.Add(self.gethCounterSUSY(f))
            return hCounter

    def initChain(self, subjob):
        self.Chain              = ROOT.TChain('blackJackAndHookers/blackJackAndHookersTree')

        files_in_subjob = self.getFileRange(subjob)

        for f in files_in_subjob:
            subfiles = glob.glob(self.path + '/*/000'+str(self.subdir)+'/*_'+str(f)+'.root')
            print f, subfiles
            if len(subfiles) > 0:
                self.Chain.Add(subfiles[0])
            else:
                print 'file ' + str(f) + ' seems to be missing'

        return self.Chain 

def createSampleList(fileName):
    sampleInfos = [line.split('%')[0].strip() for line in open(fileName)]                     # Strip % comments and \n charachters
    sampleInfos = [line.split() for line in sampleInfos if line]                              # Get lines into tuples
    
    list_of_paths = []
    for sample in sampleInfos:
        list_of_paths += glob.glob(sample[0])
    return list_of_paths


