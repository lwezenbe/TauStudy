import ROOT, subprocess
import subSample
import jobSubmitter as sub

inputFile = 'trilepFiles'
analysis = 'ewkino'

files_to_skim = subSample.createSampleList('Data/'+inputFile+'.conf')
for f in files_to_skim:
    number_of_subdir = int(subprocess.check_output("/bin/ls -lA " + f + "/* | egrep -c '^-|^d'", shell=True, stderr=subprocess.STDOUT))
    for subdir in xrange(number_of_subdir):
        subsample = subSample.subSample(f, subdir)
        nJobs = subsample.totalJobs
        for job in xrange(nJobs):
            log = '/user/lwezenbe/public/ntuples/Log/'+subsample.group+'_'+subsample.name+ '_'+ str(subdir)+ '_' +str(job)+'.log'   #temporary lazy log
            command = 'python /storage_mnt/storage/user/lwezenbe/private/PhD/Code/TauStudy/Skimmer_Old/main.py --path='+f+' --subDir='+ str(subdir)+ ' --subJob=' +str(job) + ' --analysis=' + analysis
            name = subsample.group+'_'+subsample.name+ '_'+ str(subdir)+ '_' +str(job)
            sub.launchCream02(command, log, False, str(job)+ '_' + name)

