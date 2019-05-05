from ROOT import TH1D, TFile, TGraphErrors
from helpers import makeDirIfNeeded, getObjFromFile
import numpy as np

class ROC:
    def __init__(self, name, *args):
        self.name = name
        self.eff_numerator = None
        self.eff_denominator = None
        self.misid_numerator = None
        self.misid_denominator = None
        self.WP = None
        self.path = None
        
        if args and isinstance(args[0], list):
            self.WP = args[0]
            self.eff_numerator = TH1D(name + '_eff_numerator', name + '_eff_numerator', len(self.WP), 0, len(self.WP))
            self.misid_numerator = TH1D(name + '_misid_numerator', name + '_misid_numerator', len(self.WP), 0, len(self.WP))
            self.eff_denominator = TH1D(name + '_eff_denominator', name + '_eff_denominator', 1, 0, 1)
            self.misid_denominator = TH1D(name + '_misid_denominator', name + '_misid_denominator', 1, 0, 1)

            self.eff_numerator.Sumw2() 
            self.misid_numerator.Sumw2() 
            self.eff_denominator.Sumw2() 
            self.misid_denominator.Sumw2()
        elif args and isinstance(args[0], str):
            self.path = args[0]
            self.eff_numerator = getObjFromFile(self.path, name + '_eff_numerator')
            self.eff_denominator = getObjFromFile(self.path, name + '_eff_denominator')
            self.misid_numerator = getObjFromFile(self.path, name + '_misid_numerator')
            self.misid_denominator = getObjFromFile(self.path, name + '_misid_denominator')
        else:
            pass
            

    def fill_eff_numerator(self, WP, weight=1.):
        self.eff_numerator.Fill(WP+0.5, weight)

    def fill_misid_numerator(self, WP, weight=1.):
        self.misid_numerator.Fill(WP+0.5, weight)

    def fill_eff_denominator(self, weight=1.):
        self.eff_denominator.Fill(.5, weight)

    def fill_misid_denominator(self, weight=1.):
        self.misid_denominator.Fill(0.5, weight)

    def load_efficiency(self, name, path):
        self.eff_numerator = getObjFromFile(path, name + '_eff_numerator')
        self.eff_denominator = getObjFromFile(path, name + '_eff_denominator')
    
    def load_fakerate(self, name, path):
        self.misid_numerator = getObjFromFile(path, name + '_misid_numerator')
        self.misid_denominator = getObjFromFile(path, name + '_misid_denominator')

    def write(self, output_dir, additionalInfo = None):
        makeDirIfNeeded(output_dir)
        output_name = self.name
        if additionalInfo:
            output_name += '_'+additionalInfo
        output_file = TFile(output_dir + '/' + output_name + '.root', 'recreate')
        output_file.cd()
        self.eff_numerator.Write()
        self.eff_denominator.Write()
        self.misid_numerator.Write()
        self.misid_denominator.Write()
        output_file.Close()

    def get_efficiency(self):
        eff = self.eff_numerator.Clone('efficiency')
        eff.Scale(1./self.eff_denominator.GetSumOfWeights()) #Wghat about errors?
        eff.Scale(100.)
        return eff
    
    def get_fakerate(self):
        eff = self.misid_numerator.Clone('efficiency')
        eff.Scale(1./self.misid_denominator.GetBinContent(1))
        return eff

    @staticmethod
    def bincontent_to_array(h):
        arr = np.array([])
        for b in xrange(h.GetXaxis().GetNbins()):
            arr = np.append(arr, h.GetBinContent(b+1))
        return arr
        
    @staticmethod
    def binerror_to_array(h):
        arr = np.array([])
        for b in xrange(h.GetXaxis().GetNbins()):
            arr = np.append(arr, h.GetBinError(b+1))
        return arr

    def return_graph(self):
        eff = self.get_efficiency()
        fr = self.get_fakerate()
        
        xval = self.bincontent_to_array(eff).flatten('C')
        yval = self.bincontent_to_array(fr).flatten('C')
        xerr = self.binerror_to_array(eff).flatten('C')
        yerr = self.binerror_to_array(fr).flatten('C')
        
        #xval = self.bincontent_to_array(eff)
        #yval = self.bincontent_to_array(fr)
        #xerr = self.binerror_to_array(eff)
        #yerr = self.binerror_to_array(fr)

        graph = TGraphErrors(len(xval), xval, yval, xerr, yerr)
        return graph

if __name__ == '__main__':
    roc = ROC('x', ['x', 'y', 'z'])
