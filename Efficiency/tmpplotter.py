import ROOT, os

info = []
info.append(['Iso', ['Bluj'], ['Bluj']])
#info.append(['LepDiscr', ['AN'], ['AN']])
#info.append(['All', ['Default'], ['Default']])

for i in info:
    for ef in i[1]:
        for fr in i[2]:
            os.system('python plots.py '+i[0]+' WZ --effMethod='+ef+' DYJets --frMethod='+fr+'')
