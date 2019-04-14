from helpers import getObjFromFile

class fakeRate():
    
    INPUT_PATH = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/fakeRate.root'

    def __init__(self):
        self.num = getObjFromFile(self.INPUT_PATH, 'fakeRate_num')
        self.denom = getObjFromFile(self.INPUT_PATH, 'fakeRate_denom')
        self.FR = self.num.Clone()
        self.FR.Divide(self.denom)
    
        self.maxpt = self.FR.GetXaxis().GetBinUpEdge(self.FR.GetXaxis().GetLast())
        self.maxeta = self.FR.GetYaxis().GetBinUpEdge(self.FR.GetYaxis().GetLast())
        
        self.lastptbincenter = self.FR.GetXaxis().GetBinCenter(self.FR.GetXaxis().GetLast())
        self.lastetabincenter = self.FR.GetYaxis().GetBinCenter(self.FR.GetYaxis().GetLast())

    def getTightToLoose(self, pt, eta):
        if pt > self.maxpt: pt = self.lastptbincenter
        if eta > self.maxeta: eta = self.lastetabincenter
        ttl_bin = self.FR.FindBin(pt, eta)
        return self.FR.GetBinContent(ttl_bin)

    def getFakeFactor(self, pt, eta):
        ttl = self.getTightToLoose(pt, eta)
        fake_factor = ttl/(1-ttl)
        return fake_factor
