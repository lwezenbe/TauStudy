import ROOT, os

categ = 'Iso'
effMethods=['Bluj']
frMethods=['Bluj']
#effMethods=['Bluj', 'AN']
#frMethods=['Bluj', 'AN']

#categ = 'LepDiscr'
#effMethods=['AN']
#frMethods=['AN']

#categ = 'All'
#effMethods=['Default']
#frMethods=['Default']

for ef in effMethods:
    for fr in frMethods:
#        os.system('python plots.py '+categ+' WZ --effMethod='+ef+' WJets --frMethod='+fr+'')
        os.system('python plots.py '+categ+' WZ --effMethod='+ef+' DYJets --frMethod='+fr+'')
#        os.system('python plots.py '+categ+' WZ --effMethod='+ef+' TT --frMethod='+fr+'')
#        os.system('python plots.py '+categ+' WZ --effMethod='+ef+' QCD --frMethod='+fr+'')
#        os.system('python plots.py '+categ+' DYJets --effMethod='+ef+' WJets --frMethod='+fr+'')
#        os.system('python plots.py '+categ+' DYJets --effMethod='+ef+' TT --frMethod='+fr+'')
#        os.system('python plots.py '+categ+' DYJets --effMethod='+ef+' QCD --frMethod='+fr+'')
