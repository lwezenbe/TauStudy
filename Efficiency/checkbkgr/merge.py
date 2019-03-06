import ROOT, glob, subprocess
import numpy as np

samplesToMergeLocation = ["DYJets", "TT", "WJets", "QCD"]

for name in samplesToMergeLocation:
    listOfFiles = glob.glob('/user/lwezenbe/private/PhD/Results/TauStudy/CheckBkgr/Histos/*'+name + '*.dat')
    output = [0., 0.]
    for f in listOfFiles:
        tmp = np.loadtxt(f)
        output = np.add(output, tmp)
    print name, output
    np.savetxt('/user/lwezenbe/private/PhD/Results/TauStudy/CheckBkgr/Histos/Merged/'+name+'.dat', output)
