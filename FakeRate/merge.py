import os
input_dir = '/storage_mnt/storage/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate'

#os.system('hadd -f '+input_dir+'/DYJets/fakeRate_denom.root ' + input_dir+'/DYJets/fakeRate_denom_*.root')
#os.system('hadd -f '+input_dir+'/DYJets/fakeRate_num.root ' +input_dir+'/DYJets/fakeRate_num_*.root')
os.system('hadd -f '+input_dir+'/fakeRate.root ' +input_dir+'/fakeRate_*.root')

#os.system('rm '+input_dir+'/DYJets/fakeRate_denom_*.root')
#os.system('rm '+input_dir+'/DYJets/fakeRate_num_*.root')
os.system('rm '+input_dir+'/fakeRate_*.root')
