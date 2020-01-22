import ROOT
from helpers import getObjFromFile

#path = '/user/lwezenbe/public/ntuples/ewkino_trilep2/SMS-TChiSlepSnu_x0p5_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root'
#path = '/user/lwezenbe/public/ntuples/ewkino_trilep2/SMS-TChiStauStau_x0p5_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root'
path = '/user/lwezenbe/public/ntuples/ewkino_trilep2/SMS-TChiSlepSnu_tauenriched_x0p05_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root'

hCounterSUSY = getObjFromFile(path, 'hCounterSUSY')

xbins = hCounterSUSY.GetNbinsX()
ybins = hCounterSUSY.GetNbinsY()

print xbins, ybins

total_filled_bins = 0
for x in xrange(xbins):
    for y in xrange(ybins):
        cont = hCounterSUSY.GetBinContent(x,y)
        if cont > 0: total_filled_bins += 1

print total_filled_bins
