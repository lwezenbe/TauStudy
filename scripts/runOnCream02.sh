#!/bin/bash
PYTHONUNBUFFERED=TRUE
source $VO_CMS_SW_DIR/cmsset_default.sh
cd /user/lwezenbe/private/CMSSW_10_2_13/src
eval `scram runtime -sh`
export X509_USER_PROXY=/user/$USER/x509up_u$(id -u $USER) 
eval $command
