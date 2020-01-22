from helpers_old import getObjFromFile

#
#Tau enery scale class
#


class tauEnergyScale:
    
    TAU_ENERGY_SCALES = {('2016_ReReco', 0) : (-0.005, 0.012),
                         ('2016_ReReco', 1) : (0.011, 0.012),
                         ('2016_ReReco', 2) : (0.011, 0.012),
                         ('2016_ReReco', 10) : (0.006, 0.012),
        
                         ('2016_Legacy', 0) : (-0.006, 0.010),
                         ('2016_Legacy', 1) : (-0.005, 0.009),
                         ('2016_Legacy', 2) : (-0.005, 0.009),
                         ('2016_Legacy', 10) : (0.006, 0.012),

                         ('2017_ReReco', 0) : (-0.006, 0.010),
                         ('2017_ReReco', 1) : (-0.005, 0.009),
                         ('2017_ReReco', 2) : (-0.005, 0.009),
                         ('2017_ReReco', 10) : (0.006, 0.012),

                         ('2018_', 0) : (-0.013, 0.011),
                         ('2018_', 1) : (-0.005, 0.009),
                         ('2018_', 2) : (-0.005, 0.009),
                         ('2018_', 10) : (-0.012, 0.008)}
    
    def __init__(self, year, reco = ''):
        self.reco = reco
        if not self.reco:
            if year == '2016':
                self.reco = 'Legacy'
            elif year == '2018':
                pass
            else:
                self.reco = 'ReReco'
        self.era = year + '_' + self.reco
 
    def getES(self, DM):
        ES = self.TAU_ENERGY_SCALES.get((self.era, DM))
        return 1. + ES[0]

