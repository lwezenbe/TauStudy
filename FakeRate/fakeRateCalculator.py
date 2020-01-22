from helpers_old import getObjFromFile

class fakeRateCalculator():
    
    #INPUT_PATH = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data/fakeRateDATA2016.root'
    INPUT_PATH = '/user/lwezenbe/private/PhD/Code/TauStudy/FakeRate/Data'
    def __init__(self, year, inData):
        print self.INPUT_PATH+'/fakeRate'+inData+year+'.root'    
        self.num = getObjFromFile(self.INPUT_PATH+'/fakeRate'+inData+year+'.root', 'fakeRate_num')
        self.denom = getObjFromFile(self.INPUT_PATH+'/fakeRate'+inData+year+'.root', 'fakeRate_denom')

    def getTightToLoose(self):
        tight_to_loose = self.num.Clone('tightToLoose')
        tight_to_loose.Divide(self.denom)
        return tight_to_loose

if __name__ == '__main__':
    y= '2016'
    i= 'MC'
    FR = fakeRateCalculator(y, i)
    tightToLoose = FR.getTightToLoose()
    tightToLoose.SaveAs('/user/lwezenbe/private/PhD/Results/TauStudy/FakeRate/tightToLoose_'+i+'_'+y+'.root')
    
    
