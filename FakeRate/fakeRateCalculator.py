from helpers import getObjFromFile

class fakeRateCalculator():
    
    INPUT_PATH = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/fakeRateDATA2016.root'
    #INPUT_PATH = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/tmp_fakeRateData2016/fakeRateData2016-Data_2016_subJob0.root'
    
    #num_file = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/DYJets/fakeRate_num.root' 
    #denom_file = '/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/DYJets/fakeRate_denom.root' 
    def __init__(self):
        self.num = getObjFromFile(self.INPUT_PATH, 'fakeRate_num')
        self.denom = getObjFromFile(self.INPUT_PATH, 'fakeRate_denom')


    def getTightToLoose(self):
        tight_to_loose = self.num.Clone('tightToLoose')
        tight_to_loose.Divide(self.denom)
        return tight_to_loose

if __name__ == '__main__':
    FR = fakeRateCalculator()
    tightToLoose = FR.getTightToLoose()
    tightToLoose.SaveAs('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/tightToLoose.root')
    
    
