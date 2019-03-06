import ROOT

#Names
discriminatorNames = ['OldMVA', 'NewMVA', 'Cut_Based']
lightLepDiscriminatorNames = ['MuonDiscr', 'ElectronDiscr']
workingPointsMu = ['Loose', 'Tight']
workingPointsEle = ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']
workingPointsMVA = ['VLoose', 'Loose', 'Medium', 'Tight', 'VTight']
workingPointsCut = ['VVLoose', 'VLoose', 'Loose', 'Medium', 'Tight']

#Branches that are needed (currently not used)
branches = ["_gen_nL", "_gen_lFlavor", "_gen_lIsPrompt", "_gen_lPt", "_gen_lEta", "_gen_lPhi", "_gen_lE",  
        "_nL", "_lPt", "_lEta", "_lPhi", "_lE",  
        "_weight", 
        "_decayModeFinding", "_lPOGVeto", "_lPOGLoose", "_lPOGMedium", "_lPOGTight", "_tauVTightMvaOld", 
        "_tauVLooseMvaNew", "_tauLooseMvaNew", "_tauMediumMvaNew", "_tauTightMvaNew", "_tauVTightMvaNew", 
        "_tauCombinedIsoDBRaw3Hits"]

#Information for histograms
var = []                                #list of variables each represented as [name, nBins, lowedge, highedge]
var.append(['pt', 10, 20, 120])
var.append(['eta', 24, -2.4, 2.4])
