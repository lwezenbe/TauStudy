import ROOT, glob, os
from ROOT import TFile, TCanvas
from plottingTools import plotROC, DrawHist, extraTextFormat
from helpers import makeDirIfNeeded, getObjFromFile, loadtxtCstyle, progress
import numpy as np

discriminatorNames = ['MuonDiscr', 'ElectronDiscr']
workingPointsEle = ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']
workingPointsMu = ['Loose', 'Tight']
basefolder = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/Efficiency/Histos/LepDiscr/'

def mergeEfficiency(efficiencyNames, method):
    #Load in efficiencies
    efficiencyNum = None
    efficiencyDenom = None
    for name in efficiencyNames:
        listOfFilesDenom = glob.glob(basefolder + name + '/'+method+'/efficiency_totTau*.dat')
        listOfFilesNum = glob.glob(basefolder + name + '/'+method+'/efficiency_passedTau*.dat')
        print len(listOfFilesDenom), len(listOfFilesNum)
        for f in listOfFilesNum:
            if efficiencyNum is None:
                efficiencyNum = np.loadtxt(f)
            else: 
                efficiencyNum = np.add(efficiencyNum, np.loadtxt(f))
            os.remove(f)
        for f in listOfFilesDenom:
            if efficiencyDenom is None:
                efficiencyDenom = np.loadtxt(f)
            else: 
                efficiencyDenom = np.add(efficiencyDenom, np.loadtxt(f))
            os.remove(f)

    #Calculate efficiencies for ROC
    efficiency = efficiencyNum
    efficiencyErrors = np.sqrt(efficiency)
    efficiency = np.divide(efficiency, efficiencyDenom)
    efficiency = np.multiply(efficiency, 100.)
    efficiencyErrors = np.divide(efficiencyErrors, efficiencyDenom)
    efficiencyErrors = np.multiply(efficiencyErrors, 100)

    #Save efficiencies
    makeDirIfNeeded(basefolder)
    makeDirIfNeeded(basefolder+'Merged')
    makeDirIfNeeded(basefolder+'Merged/Efficiency')
    makeDirIfNeeded(basefolder+'Merged/Efficiency/'+method)
    makeDirIfNeeded(basefolder+'Merged/Efficiency/'+ method + '/' + efficiencyNames[0])
    np.savetxt(basefolder + "Merged/Efficiency/" + method + '/' +efficiencyNames[0]+ "/efficienciesROC.dat", efficiency) 
    np.savetxt(basefolder + "Merged/Efficiency/" + method + '/' +efficiencyNames[0] + "/efficienciesErrorsROC.dat", efficiencyErrors) 

    #Pt and eta hist
    #gather histograms
    finalEffPtNum = []
    finalEffEtaNum = []
    finalEffPtDenom = []
    finalEffEtaDenom = []
    for name in efficiencyNames:
        efficienciesptdiscrDenom = None
        efficienciesetadiscrDenom = None
        effptSamples = []
        effetaSamples = []
        tmphistpt = []
        tmphisteta = []
        listOfPtFilesDenom = glob.glob(basefolder + name +'/'+method+'/pt_efficiency_denom_*root')
        listOfEtaFilesDenom = glob.glob(basefolder + name +'/'+method+'/eta_efficiency_denom_*root')
        for fpt, feta in zip(listOfPtFilesDenom, listOfEtaFilesDenom):
            tmphistpt.append(getObjFromFile(fpt, 'pt_efficiency_denom'))
            tmphisteta.append(getObjFromFile(feta, 'eta_efficiency_denom'))
            os.remove(fpt)
            os.remove(feta)
        for hpt, heta in zip(tmphistpt, tmphisteta):
            if not efficienciesptdiscrDenom:
                efficienciesptdiscrDenom = hpt.Clone('pt_efficiency_d')
            else:
                efficienciesptdiscrDenom.Add(hpt)
            if not efficienciesetadiscrDenom:
                efficienciesetadiscrDenom = heta.Clone('eta_efficiency_d')
            else:
                efficienciesetadiscrDenom.Add(heta)
        for discr in discriminatorNames:
            efficienciesptdiscrNum = []
            efficienciesetadiscrNum = []
            if discr == 'MuonDiscr':        workingPoints = workingPointsMu
            else:                           workingPoints = workingPointsEle
            for WP in workingPoints:
                listOfPtFilesNum = glob.glob(basefolder + name +'/'+method+'/pt_efficiency_num_'+discr+'_'+WP+'*.root')
                listOfEtaFilesNum = glob.glob(basefolder + name +'/'+method+'/eta_efficiency_num_'+discr+'_'+WP+'*.root')
                tmphistspt = []
                tmphistseta = []
                for fpt, feta in zip(listOfPtFilesNum, listOfEtaFilesNum):
                    tmphistspt.append(getObjFromFile(fpt, "pt_efficiency_num_"+ discr + "_" + WP))
                    tmphistseta.append(getObjFromFile(feta, "eta_efficiency_num"+ discr + "_" + WP))
                    os.remove(fpt)
                    os.remove(feta)
                tmppt = None
                tmpeta = None
                for hpt, heta in zip(tmphistspt, tmphistseta):
                    if not tmppt:
                        tmppt = hpt.Clone('pt_efficiency_n_'+ discr + "_" + WP)
                    else:
                        tmppt.Add(hpt)
                    if not tmpeta:
                        tmpeta = heta.Clone('eta_efficiency_n'+ discr + "_" + WP)
                    else:
                        tmpeta.Add(heta)
                efficienciesptdiscrNum.append(tmppt)
                efficienciesetadiscrNum.append(tmpeta)
            effptSamples.append(efficienciesptdiscrNum)
            effetaSamples.append(efficienciesetadiscrNum)

        finalEffPtNum.append(effptSamples)
        finalEffEtaNum.append(effetaSamples)
        finalEffPtDenom.append(efficienciesptdiscrDenom)
        finalEffEtaDenom.append(efficienciesetadiscrDenom)

    #merge all different samples
    for sample in efficiencyNames:
        if efficiencyNames.index(sample) == 0:      
            pass
        else :                                     
            finalEffPtDenom[0][discriminatorNames.index(discr)][workingPoint.index(WP)].Add(finalEffPtDenom[efficiencyNames.index(sample)][discriminatorNames.index(discr)][workingPoint.index(WP)])   
            finalEffEtaDenom[0][discriminatorNames.index(discr)][workingPoint.index(WP)].Add(finalEffEtaDenom[efficiencyNames.index(sample)][discriminatorNames.index(discr)][workingPoint.index(WP)])   
        for discr in discriminatorNames:           
            if discr == 'MuonDiscr':        workingPoints = workingPointsMu
            else:                           workingPoints = workingPointsEle
            for WP in workingPoints:
                if efficiencyNames.index(sample) == 0:      
                    pass
                else :                                     
                    finalEffPtNum[0][discriminatorNames.index(discr)][workingPoint.index(WP)].Add(finalEffPtNum[efficiencyNames.index(sample)][discriminatorNames.index(discr)][workingPoint.index(WP)])   
                    finalEffEtaNum[0][discriminatorNames.index(discr)][workingPoint.index(WP)].Add(finalEffEtaNum[efficiencyNames.index(sample)][discriminatorNames.index(discr)][workingPoint.index(WP)])   

    #calc efficiency and save
    for discr in discriminatorNames:
        if discr == 'MuonDiscr':        workingPoints = workingPointsMu
        else:                           workingPoints = workingPointsEle
        for WP in workingPoints:
            EffPt = finalEffPtNum[0][discriminatorNames.index(discr)][workingPoints.index(WP)].Clone('pt_efficiency_'+discr+'_'+WP) 
            EffEta = finalEffEtaNum[0][discriminatorNames.index(discr)][workingPoints.index(WP)].Clone('eta_efficiency_'+discr+'_'+WP) 
            EffPt.Divide(finalEffPtDenom[0])
            EffEta.Divide(finalEffEtaDenom[0])
            EffPt.Scale(100.)
            EffEta.Scale(100.)
            EffPt.SaveAs(basefolder+'Merged/Efficiency/'+method+'/'+efficiencyNames[0]+'/pt_efficiency_'+discr+'_'+WP+'.root')
            EffEta.SaveAs(basefolder+'Merged/Efficiency/'+method+'/'+efficiencyNames[0]+'/eta_efficiency_'+discr+'_'+WP+'.root')

def mergeFakeRate(fakerateNames, method):
    #Load in fakerates
    fakerateNum = None
    fakerateDenom = None
    for name in fakerateNames:
        listOfFilesNum = glob.glob(basefolder + name + '/'+method+'/fakerate_passedTau*.dat')
        listOfFilesDenom = glob.glob(basefolder + name + '/'+method+'/fakerate_totJets*.dat')
        print len(listOfFilesDenom), len(listOfFilesNum)
        
        for f in listOfFilesNum:
            if fakerateNum is None:
                fakerateNum = np.loadtxt(f)
            else: 
                fakerateNum = np.add(fakerateNum, np.loadtxt(f))
            os.remove(f)
        for f in listOfFilesDenom:
            if fakerateDenom is None:
                fakerateDenom = np.loadtxt(f)
            else: 
                fakerateDenom = np.add(fakerateDenom, np.loadtxt(f))
            os.remove(f)

    #Calculate efficiencies for ROC
    fakerate = fakerateNum
    fakerateErrors = np.sqrt(fakerate)
    fakerate[0] = np.divide(fakerate[0], fakerateDenom[0])
    fakerateErrors[0] = np.divide(fakerateErrors[0], fakerateDenom[0])
    fakerate[1] = np.divide(fakerate[1], fakerateDenom[1])
    fakerateErrors[1] = np.divide(fakerateErrors[1], fakerateDenom[1])

    #Save fakerates
    makeDirIfNeeded(basefolder+'Merged/FakeRate')
    makeDirIfNeeded(basefolder+'Merged/FakeRate'+method)
    makeDirIfNeeded(basefolder+'Merged/FakeRate/'+ method +'/'+ fakerateNames[0])
    np.savetxt(basefolder + 'Merged/FakeRate/'+method+'/'+fakerateNames[0]+"/fakeratesROC.dat", fakerate) 
    np.savetxt(basefolder + 'Merged/FakeRate/'+method+'/'+fakerateNames[0]+"/fakeratesErrorsROC.dat", fakerateErrors) 

    #Pt and eta hists
    #gather histograms
    finalFRPtNum = []
    finalFREtaNum = []
    finalFRPtDenom = []
    finalFREtaDenom = []
    for name in fakerateNames:
        fakeratesptdiscrDenom = None
        fakeratesetadiscrDenom = None
        FRptSamples = []
        FRetaSamples = []
        tmphistpt = []
        tmphisteta = []
        listOfPtFilesDenom = glob.glob(basefolder + name +'/'+method+'/pt_fakerate_denom_*root')
        listOfEtaFilesDenom = glob.glob(basefolder + name +'/'+method+'/eta_fakerate_denom_*root')
        for fpt, feta in zip(listOfPtFilesDenom, listOfEtaFilesDenom):
            tmphistpt.append(getObjFromFile(fpt, 'pt_fakerate_denom'))
            tmphisteta.append(getObjFromFile(feta, 'eta_fakerate_denom'))
            os.remove(fpt)
            os.remove(feta)
        for hpt, heta in zip(tmphistpt, tmphisteta):
            if not fakeratesptdiscrDenom:
                fakeratesptdiscrDenom = hpt.Clone('pt_fakerate_d')
            else:
                fakeratesptdiscrDenom.Add(hpt)
            if not fakeratesetadiscrDenom:
                fakeratesetadiscrDenom = heta.Clone('eta_fakerate_d')
            else:
                fakeratesetadiscrDenom.Add(heta)
        for discr in discriminatorNames:
            fakeratesptdiscrNum = []
            fakeratesetadiscrNum = []
            if discr == 'MuonDiscr':        workingPoints = workingPointsMu
            else:                           workingPoints = workingPointsEle
            for WP in workingPoints:
                listOfPtFilesNum = glob.glob(basefolder + name +'/'+method+'/pt_fakerate_num_'+discr+'_'+WP+'*.root')
                listOfEtaFilesNum = glob.glob(basefolder + name +'/'+method+'/eta_fakerate_num_'+discr+'_'+WP+'*.root')
                tmphistspt = []
                tmphistseta = []
                for fpt, feta in zip(listOfPtFilesNum, listOfEtaFilesNum):
                    tmphistspt.append(getObjFromFile(fpt, "pt_efficiency_num_"+ discr + "_" + WP))      #made a mistake with naming earlier in the code, fix this later
                    tmphistseta.append(getObjFromFile(feta, "eta_efficiency_num"+ discr + "_" + WP))
                    os.remove(fpt)
                    os.remove(feta)
                tmppt = None
                tmpeta = None
                for hpt, heta in zip(tmphistspt, tmphistseta):
                    if not tmppt:
                        tmppt = hpt.Clone('pt_fakerate_n_'+ discr + "_" + WP)
                    else:
                        tmppt.Add(hpt)
                    if not tmpeta:
                        tmpeta = heta.Clone('eta_fakerate_n'+ discr + "_" + WP)
                    else:
                        tmpeta.Add(heta)
                fakeratesptdiscrNum.append(tmppt)
                fakeratesetadiscrNum.append(tmpeta)
            FRptSamples.append(fakeratesptdiscrNum)
            FRetaSamples.append(fakeratesetadiscrNum)
        finalFRPtNum.append(FRptSamples)
        finalFREtaNum.append(FRetaSamples)
        finalFRPtDenom.append(fakeratesptdiscrDenom)
        finalFREtaDenom.append(fakeratesetadiscrDenom)

    #merge all different samples
    for sample in fakerateNames:
        if fakerateNames.index(sample) == 0:      
            continue
        else :                                     
            finalFRPtDenom[0][discriminatorNames.index(discr)][workingPoint.index(WP)].Add(finalFRPtDenom[fakerateNames.index(sample)][discriminatorNames.index(discr)][workingPoint.index(WP)])   
            finalFREtaDenom[0][discriminatorNames.index(discr)][workingPoint.index(WP)].Add(finalFREtaDenom[fakerateNames.index(sample)][discriminatorNames.index(discr)][workingPoint.index(WP)])   
        for discr in discriminatorNames:           
            if discr == 'MuonDiscr':        workingPoints = workingPointsMu
            else:                           workingPoints = workingPointsEle
            for WP in workingPoints:
                if fakerateNames.index(sample) == 0:      
                    continue
                else :                                     
                    finalFRPtNum[0][discriminatorNames.index(discr)][workingPoint.index(WP)].Add(finalFRPtNum[fakerateNames.index(sample)][discriminatorNames.index(discr)][workingPoint.index(WP)])   
                    finalFREtaNum[0][discriminatorNames.index(discr)][workingPoint.index(WP)].Add(finalFREtaNum[fakerateNames.index(sample)][discriminatorNames.index(discr)][workingPoint.index(WP)])   

    #calc fakerate and save
    for discr in discriminatorNames:
        if discr == 'MuonDiscr':        workingPoints = workingPointsMu
        else:                           workingPoints = workingPointsEle
        for WP in workingPoints:
            FRPt = finalFRPtNum[0][discriminatorNames.index(discr)][workingPoints.index(WP)].Clone('pt_fakerate_'+discr+'_'+WP) 
            FREta = finalFREtaNum[0][discriminatorNames.index(discr)][workingPoints.index(WP)].Clone('eta_fakerate_'+discr+'_'+WP) 
            FRPt.Divide(finalFRPtDenom[0])
            FREta.Divide(finalFREtaDenom[0])
            FRPt.SaveAs(basefolder+'Merged/FakeRate/'+method+'/'+fakerateNames[0]+'/pt_fakerate_'+discr+'_'+WP+'.root')
            FREta.SaveAs(basefolder+'Merged/FakeRate/'+method+'/'+fakerateNames[0]+'/eta_fakerate_'+discr+'_'+WP+'.root')

#mergeEfficiency(['DYJets'], 'AN')
mergeEfficiency(['WZ'], 'AN')
#mergeFakeRate(['TT'], 'AN')
#mergeFakeRate(['WJets'], 'AN')
mergeFakeRate(['DYJets'], 'AN')
#mergeFakeRate(['QCD'], 'AN')

