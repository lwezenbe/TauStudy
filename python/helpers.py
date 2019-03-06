import ROOT, socket, os, shutil, subprocess, time
from math import pi, sqrt
from operator import mul
from numpy import loadtxt
import sys

#
# Check if valid ROOT file exists
#
def isValidRootFile(fname):
  if not os.path.exists(os.path.expandvars(fname)): return False
  f = ROOT.TFile(fname)
  if not f: return False
  try:
    return not (f.IsZombie() or f.TestBit(ROOT.TFile.kRecovered) or f.GetListOfKeys().IsEmpty())
  finally:
    f.Close()

#
# Get object (e.g. hist) from file using key, and keep in memory after closing
#
def getObjFromFile(fname, hname):
  assert isValidRootFile(fname)
  try:
    f = ROOT.TFile(fname)
    f.cd()
    htmp = f.Get(hname)
    if not htmp: return None
    ROOT.gDirectory.cd('PyROOT:/')
    res = htmp.Clone()
    return res
  finally:
    f.Close()

def loadtxtCstyle(source):
    arr = loadtxt(source)
    arr = arr.flatten('C')
    arr = arr.astype('double')
    return arr

#
# Progress bar
#

def progress(i, N, prefix="", size=60):
    x = int(size*i/(N-1))
    sys.stdout.write("%s\x1b[6;30;42m%s\x1b[0m\x1b[0;30;41m%s\x1b[0m %i/%i %s\r" % (" "*0, " "*x, " "*(size-x), i, N, prefix))
    sys.stdout.flush()

def makeDirIfNeeded(path):
    try:
        os.makedirs(path)
    except OSError:
        pass

#
#Return array with values of a branch because I don't know a better solution
#

def showBranch(branch):
    arr = [x for x in branch]
    return arr

#
#Add timestamp to the end of a path
#
def makePathTimeStamped(path):
    timestamp = time.strftime("%Y%m%d_%H%M%S")
    basefolderOutput = path+'/'+timestamp
    makeDirIfNeeded(basefolderOutput)
    return basefolderOutput

#
#Sort one list based on another list
#
def sortByOtherList(to_sort, base):
    orderedList = [x for _,x in sorted(zip(base,to_sort))]
    return orderedList
