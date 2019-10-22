from helpers import getObjFromFile
from objectSelection import isTightTau

class fakeRate():
    
    INPUT_PATH = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data'

    def __init__(self, inData, year):
        self.num = getObjFromFile(self.INPUT_PATH+'/fakeRate'+inData+year+'.root', 'fakeRate_num')
        self.denom = getObjFromFile(self.INPUT_PATH+'/fakeRate'+inData+year+'.root', 'fakeRate_denom')
        self.FR = self.num.Clone()
        self.FR.Divide(self.denom)
        
    
        self.maxpt = self.FR.GetXaxis().GetBinUpEdge(self.FR.GetXaxis().GetLast())
        self.maxeta = self.FR.GetYaxis().GetBinUpEdge(self.FR.GetYaxis().GetLast())
        
        self.lastptbincenter = self.FR.GetXaxis().GetBinCenter(self.FR.GetXaxis().GetLast())
        self.lastetabincenter = self.FR.GetYaxis().GetBinCenter(self.FR.GetYaxis().GetLast())

    def getTightToLoose(self, pt, eta):
        pt = min(max(self.FR.GetXaxis().GetBinCenter(1), pt), self.FR.GetXaxis().GetBinCenter(self.FR.GetXaxis().GetLast()))
        eta = min(max(self.FR.GetYaxis().GetBinCenter(1), abs(eta)), self.FR.GetYaxis().GetBinCenter(self.FR.GetYaxis().GetLast())) #Eta axis goes from 0 to 2.5
        ttl_bin = self.FR.FindBin(pt, abs(eta))
        return self.FR.GetBinContent(ttl_bin)

    def getFakeFactor(self, pt, eta):
        ttl = self.getTightToLoose(pt, abs(eta))
        fake_factor = ttl/(1-ttl)
        return fake_factor

    def getSingleTauWeight(self, Chain, lVec, lIndex):                          #if else selects loose but not tight
        if isTightTau(Chain, lIndex):
            return -999.
        else:
            return self.getFakeFactor(lVec[2].Pt(), abs(lVec[2].Eta()))

    def getDiTauWeight(self, Chain, lVec, lIndices):
        weight = 1.
        nTightTau = 0
        for i, l in enumerate(lIndices):
            if isTightTau(Chain, l):
                weight *= 1.
                nTightTau += 1
            else:
                weight *= self.getFakeFactor(lVec[i].Pt(), abs(lVec[i].Eta())) 
        
        if nTightTau == 0:
            weight *= -1.
        elif nTightTau == 2:
            return -999.
        return weight
        
    def getFakeWeight(self, Chain, lVec, lIndices, nLooseTau):
        if nLooseTau == 1:
            return self.getSingleTauWeight(Chain, lVec, lIndices[2])
        elif nLooseTau == 2:
            return self.getDiTauWeight(Chain, lVec[1:], lIndices[1:]) 
