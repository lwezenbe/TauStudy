#!/bin/bash
PYTHONUNBUFFERED=TRUE
cd /user/lwezenbe/private/CMSSW_9_4_10/src
source $VO_CMS_SW_DIR/cmsset_default.sh
eval `scram runtime -sh`
eval $command