import plottingTools as plt
import fakeRateCalculator
from helpers import makeDirIfNeeded

makeDirIfNeeded('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots')
makeDirIfNeeded('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots/Data2016')

output = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots/Data2016/tightToLoose'
#output = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots/Data2016/tightToLoose_noPromptSubt'

FR = fakeRateCalculator.fakeRateCalculator()
tightToLoose = FR.getTightToLoose()

plt.draw2DHist(tightToLoose, 'p_{T} [GeV]', '|#eta|', output)
