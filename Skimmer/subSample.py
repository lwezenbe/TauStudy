import ROOT, glob
from helpers import getObjFromFile


class subSample():
    
    FILES_PER_JOB = 30.

    def __init__(self, path, subdir):
        self.subdir      = subdir
        self.path        = path
        self.listOfAllFiles = glob.glob(path+'/*/000'+str(subdir)+'/*.root')
            
        #get correct naming first
        split_up_path   = self.path.split('/')
        self.group      = split_up_path[8]
        self.name       = split_up_path[9]
        
        self.totalJobs   = int(round((len(self.listOfAllFiles)/self.FILES_PER_JOB)+0.5))
        self.Chain       = None
        
    def getFileRange(self, subjob):
        limits = None
        if subjob < self.totalJobs-1:
            limits =  [(subjob*self.FILES_PER_JOB)+1, ((subjob + 1)*self.FILES_PER_JOB)+1]
        elif subjob == self.totalJobs-1:
            limits =  [(subjob*self.FILES_PER_JOB)+1, len(self.listOfAllFiles)]
        return xrange(int(limits[0]), int(limits[1]))

    def filesInSubjob(self, subjob):
        files_in_subjob = self.getFileRange(subjob)
        list_of_files = []
        for f in files_in_subjob:
            subfile = glob.glob(self.path + '/*/000'+str(self.subdir)+'/*_'+str(f + 1000*self.subdir)+'.root')
            if len(subfile) > 0:
                list_of_files.append(subfile[0])
            else:
                print 'file ' + str(f) + ' seems to be missing'
    
        return list_of_files
   
    #Get combined hCounter or hCounterSUSY 
    def getHist(self, subjob, name, subPath = None):                                            
        if subPath is None:             subPath = self.path
        if subPath.endswith('.root'):
            hCounter                    = getObjFromFile(subPath, 'blackJackAndHookers/'+name)
            return hCounter
        else:
            hCounter = None
            for f in self.filesInSubjob(subjob):
                if hCounter is None:     hCounter = self.getHist(subjob,name, f)
                else:                    hCounter.Add(self.getHist(subjob, name, f))
                print hCounter.GetSumOfWeights()
            return hCounter
    
    def initChain(self, subjob):
        self.Chain              = ROOT.TChain('blackJackAndHookers/blackJackAndHookersTree')

        for f in self.filesInSubjob(subjob):
            self.Chain.Add(f)

        return self.Chain 

def createSampleList(fileName):
    sampleInfos = [line.split('%')[0].strip() for line in open(fileName)]                     # Strip % comments and \n charachters
    sampleInfos = [line.split() for line in sampleInfos if line]                              # Get lines into tuples
    
    list_of_paths = []
    for sample in sampleInfos:
        list_of_paths += glob.glob(sample[0])
    return list_of_paths


