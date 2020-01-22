import ROOT
from helpers_old import makeDirIfNeeded

class histogram():
    
    def __init__(self, title, bins, output_dir, customBins = False):
        self.title = title
        self.bins = bins
        self.output_path = output_dir + '_' +title + '.root'   

        if not customBins:
            self.hist = ROOT.TH1D(title, title, bins[0], bins[1], bins[2])
        else:
            self.hist = ROOT.TH1D(title, title, bins.size-1, bins)
        self.hist.Sumw2()
        self.sideBand = self.hist.Clone(title + '_sideBand')

    def fill_histogram(self, value, weight):
        self.hist.Fill(min(max(self.hist.GetXaxis().GetBinCenter(1), value), self.hist.GetXaxis().GetBinCenter(self.hist.GetXaxis().GetLast())), weight)

    def fill_sideband(self, value, weight, sideBandFactor):
        self.sideBand.Fill(min(max(self.sideBand.GetXaxis().GetBinCenter(1), value), self.sideBand.GetXaxis().GetBinCenter(self.sideBand.GetXaxis().GetLast())), weight*sideBandFactor)

    def fill(self, value, weight, fakeFactor):
        if fakeFactor == -999.:
            self.fill_histogram(value, weight)
        else:
            self.fill_sideband(value, weight, fakeFactor)

    def get_histogram(self):
        return self.hist

    def get_sideband(self):
        return self.sideBand

    def write_hist(self):
        makeDirIfNeeded(self.output_path)
        output_file = ROOT.TFile(self.output_path, 'recreate')
        output_file.cd()
        self.hist.Write()
        self.sideBand.Write()
        output_file.Close()
 
        
