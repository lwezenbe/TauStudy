import ROOT
import numpy as np
import Sample
from helpers import makeDirIfNeeded

class fakeRate():

    PT_BINS = np.array([20., 25., 35., 50., 70., 100.])
    ETA_BINS = np.array([0., 0.5, 1., 1.5, 2., 2.5])
    OUTPUT_DIR = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate'
    
    def __init__(self, name):
        self.fakeRate_num = ROOT.TH2D('fakeRate_num', 'fakeRate_num', len(self.PT_BINS) - 1, self.PT_BINS, len(self.ETA_BINS) - 1, self.ETA_BINS)
        self.fakeRate_num.Sumw2()
        self.fakeRate_denom = ROOT.TH2D('fakeRate_denom', 'fakeRate_denom', len(self.PT_BINS) - 1, self.PT_BINS, len(self.ETA_BINS) - 1, self.ETA_BINS)
        self.fakeRate_denom.Sumw2()
        self.name = name

    def fill_numerator(self, entries, weight = 1.):
        xval = entries[0]
        yval = entries[1]
        if self.fakeRate_num.GetXaxis().GetBinUpEdge(self.fakeRate_num.GetXaxis().GetLast()) < xval:
            xval = self.fakeRate_num.GetXaxis().GetBinCenter(self.fakeRate_num.GetXaxis().GetLast())
        
        if self.fakeRate_num.GetYaxis().GetBinUpEdge(self.fakeRate_num.GetYaxis().GetLast()) < yval:
            yval = self.fakeRate_num.GetYaxis().GetBinCenter(self.fakeRate_num.GetYaxis().GetLast())

        self.fakeRate_num.Fill(xval, yval, weight)

    def fill_denominator(self, entries, weight = 1.):
        xval = entries[0]
        yval = entries[1]
        if self.fakeRate_denom.GetXaxis().GetBinUpEdge(self.fakeRate_denom.GetXaxis().GetLast()) < xval:
            xval = self.fakeRate_denom.GetXaxis().GetBinCenter(self.fakeRate_denom.GetXaxis().GetLast())
        
        if self.fakeRate_denom.GetYaxis().GetBinUpEdge(self.fakeRate_denom.GetYaxis().GetLast()) < yval:
            yval = self.fakeRate_denom.GetYaxis().GetBinCenter(self.fakeRate_denom.GetYaxis().GetLast())

        self.fakeRate_denom.Fill(xval, yval, weight)
    
    def get_numerator(self):
        return self.fakeRate_num

    def get_denominator(self):
        return self.fakeRate_denom

    def writeFR(self):
        makeDirIfNeeded(self.OUTPUT_DIR)
        output_file = ROOT.TFile(self.OUTPUT_DIR + '/' + self.name + '.root', 'recreate')
        output_file.cd()
        self.fakeRate_num.Write()
        self.fakeRate_denom.Write()
        output_file.Close() 
