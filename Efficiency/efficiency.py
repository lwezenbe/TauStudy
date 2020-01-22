import ROOT
import numpy as np
import Sample
from helpers_old import makeDirIfNeeded, getObjFromFile, getLowEdges

class efficiency(object):

    def __init__(self, name, *args):      
        self.name = name
        self.efficiency_num = []
        self.efficiency_denom = None
        self.input_path = None
        self.bins = None
        self.workingPoints = None
        if len(args) == 2:                                #if (bins, workingpoints) is given, instantiate new histograms 
            self.bins = args[0]
            self.workingPoints = args[1]
            
            for i, WP in enumerate(self.workingPoints):
                self.efficiency_num.append(ROOT.TH1D(name+'_'+WP+'_num', name+'_'+WP+'_num', len(self.bins) - 1, self.bins))
                self.efficiency_num[i].Sumw2()
            self.efficiency_denom = ROOT.TH1D(name+'_denom', name+'_denom', len(self.bins) - 1, self.bins)
            self.efficiency_denom.Sumw2()

        elif len(args) == 1 and isinstance(args[0], str):
            self.input_path = args[0]
            self.workingPoints = []
            
            f = ROOT.TFile(self.input_path)
            names = [key.GetName() for key in f.GetListOfKeys()]
            f.Close()
            for n in names:
                if '_denom' in n:
                    self.efficiency_denom = getObjFromFile(self.input_path, n)
                elif '_num' in n:
                    self.efficiency_num.append(getObjFromFile(self.input_path, n))
                    self.workingPoints.append(n.split('_')[-2])
            self.bins = getLowEdges(self.efficiency_denom)

    def fill_numerator(self, xval, WP, weight = 1.):
        if self.efficiency_num[WP].GetXaxis().GetBinUpEdge(self.efficiency_num[WP].GetXaxis().GetLast()) < xval:
            xval = self.efficiency_num[WP].GetXaxis().GetBinCenter(self.efficiency_num[WP].GetXaxis().GetLast())

        self.efficiency_num[WP].Fill(xval, weight)

    def fill_denominator(self, xval, weight = 1.):
        if self.efficiency_denom.GetXaxis().GetBinUpEdge(self.efficiency_denom.GetXaxis().GetLast()) < xval:
            xval = self.efficiency_denom.GetXaxis().GetBinCenter(self.efficiency_denom.GetXaxis().GetLast())

        self.efficiency_denom.Fill(xval, weight)

    def get_numerator(self, WP):
        num = self.efficiency_num[WP].Clone()
        return num

    def get_denominator(self):
        return self.efficiency_denom

    def get_efficiency(self, WP, inPercent = True):
        eff = self.get_numerator(WP).Clone('efficiency')
        eff.Divide(self.get_denominator())
        if inPercent: eff.Scale(100.)
        return eff

    def write(self, output, additionalInfo):
        makeDirIfNeeded(output)
        output_file = ROOT.TFile(output + '/' + self.name + '_' + additionalInfo+'.root', 'recreate')
        output_file.cd()
        for i in xrange(len(self.workingPoints)):
            self.efficiency_num[i].Write()
        self.efficiency_denom.Write()
        output_file.Close()

if __name__ == '__main__':
    eff = efficiency('name', '/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/Iso/Merged/FakeRate/Bluj/DYJets/eta_fakerate_oldMVA.root')
