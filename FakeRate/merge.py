import os
import glob

inputfolders = glob.glob('Data/tmp_fakeRate*')

for folder in inputfolders:
    name = folder.split('/')[-1].split('_')[-1]
    print name
    os.system('hadd -f Data/'+ name +'.root ' +folder+'/fakeRate*.root')
    #os.system('rm -r '+folder)
