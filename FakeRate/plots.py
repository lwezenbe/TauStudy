import plottingTools as plt
import fakeRateCalculator
from helpers import makeDirIfNeeded

makeDirIfNeeded('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots')
output = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/Plots/tightToLoose'

FR = fakeRateCalculator.fakeRateCalculator()
tightToLoose = FR.getTightToLoose()

plt.draw2DHist(tightToLoose, 'p_{T} [GeV]', '|#eta|', output)
