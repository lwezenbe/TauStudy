import ROOT, glob, os
from helpers import getObjFromFile

class Sample:

    def __init__(self, name, path, output, splitJobs, xsec):
        self.name               = name
        self.path               = path
        self.isData             = (xsec == 'data')
        self.xsec               = eval(xsec) if not self.isData else None
        self.splitJobs          = splitJobs
        self.hCount             = None
        self.Chain              = None
        self.output             = output
        self.singleFile         = self.path.endswith('.root')
        self.hCount             = None
        self.isSkimmed          = not 'pnfs' in self.path
    
    def gethCount(self, subPath = None): 
        if subPath is None:             subPath = self.path
        if subPath.endswith('.root'):
            if not self.isSkimmed:      
                hCounter                    = getObjFromFile(subPath, 'blackJackAndHookers/hCounter')
            else:
                hCounter                    = getObjFromFile(subPath, 'hCounter')
            self.hCount                     = hCounter.GetEntries()
            return hCounter
        else:
            hCounter = None
            listOfFiles                 = glob.glob(self.path + '/*.root')
            for f in listOfFiles:
                if hCounter is None:     hCounter = self.gethCount(f)
                else:                    hCounter.Add(self.gethCount(f))
            self.hCount                 = hCounter.GetEntries() 
    
    def initTree(self, branches = None):
        if not self.isSkimmed:      
            self.Chain              = ROOT.TChain('blackJackAndHookers/blackJackAndHookersTree')
        else:      
            self.Chain              = ROOT.TChain('blackJackAndHookersTree')
        if self.singleFile:
            listOfFiles         = [self.path]
        else:
            listOfFiles         = glob.glob(self.path + '/*.root')
        for f in listOfFiles:
            self.Chain.Add(f)

        if branches is not None:        self.setSpecificBranches(branches)

        if(self.singleFile and not self.isData):    self.gethCount()

        return self.Chain

    def getEventRange(self, subJob):
        limits = [entry*self.Chain.GetEntries()/self.splitJobs for entry in range(self.splitJobs)] + [self.Chain.GetEntries()]
        return xrange(limits[subJob], limits[subJob+1])

    def setSpecificBranches(self, branches):
        self.Chain.SetBranchStatus("*",0)
        for branch in branches:
            self.Chain.SetBranchStatus(branch, 1)


def createSampleList(fileName):
    sampleInfos = [line.split('%')[0].strip() for line in open(fileName)]                     # Strip % comments and \n charachters
    sampleInfos = [line.split() for line in sampleInfos if line]                              # Get lines into tuples
    for name, path, output, splitJobs, xsec in sampleInfos:
        if splitJobs == 'Calc':
            if path.endswith('.root'):
                file_info = os.stat(path)
                file_size = file_info.st_size
                splitJobs = (file_size/400000000.)+0.5
            else:
                splitJobs = (len(glob.glob(path + '/*.root'))/10.)+0.5
        if int(splitJobs) == 0:       splitJobs = 1
        yield Sample(name, path, output, int(splitJobs), xsec)

def getSampleFromList(sampleList, name):
  return next((s for s in sampleList if s.name==name), None)
     
