import ROOT
from ROOT import TLine, THStack, TColor, TCanvas, TLegend, gROOT, gStyle, TH1, TMultiGraph, TGraphErrors, TGraph, TLatex, TPad
import CMS_lumi as cl
import tdrstyle as tdr
import numpy as np
from helpers import makeDirIfNeeded

def GeneralSettings():
    gROOT.SetBatch(True)
    gStyle.SetOptStat(0)
    tdr.setTDRStyle()
    gStyle.SetPaintTextFormat("4.2f")
    gROOT.ProcessLine( "gErrorIgnoreLevel = 1001;")

def GetStackColor(index):
    if index == 0:      return "#4C5760"
    if index == 1:      return "#93A8AC"
    if index == 2:      return "#D7CEB2"
    if index == 3:      return "#F4FDD9"
    if index == 4:      return "#AA767C"
    if index == 5:      return "#D6A184"

def GetStackColorTauPOG(index):
    if index == 0:      return "#18252a"
    if index == 1:      return "#de5a6a"
    if index == 2:      return "#9999cc"
    if index == 3:      return "#4496c8"
    if index == 4:      return "#ffcc66"
    if index == 5:      return "#e5b7e5"

def GetHistColor(index):        
    if index == 0:      return "#000000"
    if index == 1:      return "#000075"
    if index == 2:      return "#800000"
    if index == 3:      return "#f58231"
    if index == 4:      return "#3cb44d"
    if index == 5:      return "#ffe119"

def GetLineColor(index):
    if index == 0:      return "#000000"
    if index == 1:      return "#e6194B"
    if index == 2:      return "#4363d8"

def GetMarker(index):
    if index == 0:      return 20
    if index == 1:      return 21
    if index == 2:      return 22

def GetOverallMaximum(hist):
    currentMax = 0
    for h in hist:
        if h.GetMaximum() > currentMax :    currentMax = h.GetMaximum()
    return currentMax

def GetOverallMinimum(hist):
    currentMin = 99999
    for h in hist:
        if h.GetMinimum() < currentMin :    currentMin = h.GetMinimum()
    return currentMin

def GetNestedMin(arr):
    localMin = []
    for a in arr:
        localMin.append(np.min(a))
    return np.min(localMin)

def GetNestedMax(arr):
    localMax = []
    for a in arr:
        localMax.append(np.max(a))
    return np.max(localMax)

def extraTextFormat(text, xpos = None, ypos = None, textsize = None):
    return [text, xpos, ypos, textsize]

def DrawExtraText(pad, additionalInformation):
    pad.cd()
    lastYpos = 0.8
    for info in additionalInformation:
        try :
            extraTextString = info[0]
            extraTextXpos = info[1]
            extraTextYpos = info[2]
            extraTextSize = info[3]
        except:
            print("Wrong Format for additionalInformation. Stopping")
            pass
         
        if extraTextXpos is None:
            extraTextXpos = 0.2
        if extraTextYpos is None:
            if lastYpos is None:
                extraTextYpos = lastYpos - 0.1
            else: extraTextYpos = 0.8
        if extraTextSize is None:
            extraTextSize = 0.03

        extraText = TLatex(extraTextXpos, extraTextYpos, extraTextString)
        extraText.SetNDC()
        extraText.SetTextSize(extraTextSize)
        extraText.Draw("Same")
        lastYpos = extraTextYpos
    pad.Update()
    
def plotDataVSMC(DataHist, MCHist, xtitle, legendNames, DataName, destination):
    GeneralSettings()
    
    Canv = TCanvas("Canv"+destination, "Canv"+destination, 1000, 1000)
    
    #Set Histogram Styles
    for h in MCHist :
        h.SetFillColor(TColor.GetColor(GetStackColorTauPOG(MCHist.index(h)))) 
        h.SetLineColor(TColor.GetColor(GetStackColorTauPOG(MCHist.index(h))))
    
    DataHist.SetMarkerColor(ROOT.kBlack)
    DataHist.SetLineColor(ROOT.kBlack)    
    DataHist.SetMarkerStyle(20)    
    
    #Add all MC samples to use in ratios
    totBkgr = MCHist[0].Clone("totBkgr")
    for h in MCHist[1:]:
        totBkgr.Add(h)
    DataOverMC = DataHist.Clone("DataOverMC")
    DataOverMC.Divide(totBkgr)

    #First pad
    plotpad = TPad("plotpad", "plotpad", 0, .3, 1, 0.98)
    plotpad.SetBottomMargin(0.025)
    plotpad.Draw()
    plotpad.cd()

    #Create Stack (Change with most logical ordering)
    hs = THStack("hs", "hs")
    for h in MCHist:
        hs.Add(h)
    hs.Draw("EHist")                                                            #Draw before using GetHistogram, see https://root-forum.cern.ch/t/thstack-gethistogram-null-pointer-error/12892/4
    title = " ; ; Events / " +str(MCHist[0].GetBinWidth(1)) + " GeV"
    hs.SetTitle(title)
#    hs.GetHistogram().GetXaxis().SetTickLength(0)
    hs.GetHistogram().GetXaxis().SetLabelOffset(9999999)
    hs.GetHistogram().SetMaximum(1)    

    #Set range
    overallMin = GetOverallMinimum(MCHist+[DataHist])
    overallMax = GetOverallMaximum([totBkgr]+[DataHist])
    hs.SetMinimum(0.5*overallMin)    
    hs.SetMaximum(1.2*overallMax)    
    DataHist.Draw("EPSame")
     
    #Create Legend
    legend = TLegend(0.7, .7, .9, .9)
    for h, n in zip(MCHist, legendNames):
        legend.AddEntry(h, n)
    legend.AddEntry(DataHist, DataName)  
    legend.SetFillStyle(0)
    legend.SetBorderSize(0)

    legend.Draw()

    #Return to canvas
    Canv.cd()

    #Second pad
    ratiopad = TPad("ratiopad", "ratiopad", 0, 0.05, 1, .3)
    ratiopad.SetTopMargin(0.05)
    ratiopad.SetBottomMargin(0.25)
    ratiopad.Draw()
    ratiopad.cd()
    
    #Set Style for bottom plot
    DataOverMC.SetTitle(";" + xtitle + "; Data/MC")
    DataOverMC.GetXaxis().SetTitleSize(.12)
    DataOverMC.GetYaxis().SetTitleSize(.12)
    DataOverMC.GetYaxis().SetTitleOffset(.6)
    DataOverMC.GetXaxis().SetLabelSize(.12)
    DataOverMC.GetYaxis().SetLabelSize(.12)
    DataOverMC.GetYaxis().SetMinimum(0.)
    DataOverMC.GetYaxis().SetMaximum(2.)
    DataOverMC.Draw("EP")

    #Draw a guide for the eye
    line = TLine(DataOverMC.GetXaxis().GetXmin(),1,DataOverMC.GetXaxis().GetXmax(),1)
    line.SetLineColor(ROOT.kRed)
    line.SetLineWidth(1)
    line.SetLineStyle(1)
    line.Draw("Same")
   
    #Throw CMs lumi at it
    cl.CMS_lumi(Canv, 4, 11, 'Preliminary', True)
 
    #Save everything
    Canv.SaveAs(destination + ".pdf")
    Canv.SaveAs(destination + ".png")
    Canv.SaveAs(destination + ".root")

def plotROC(xdata, ydata, xlabel, ylabel, destination, xerror = None, yerror = None, xlog = False, ylog = False, additionalInformation = None):
    GeneralSettings()
    
    #Create Canvas
    Canv = TCanvas("Canv"+destination, "Canv"+destination, 1000, 1000)
    
    tdr.setTDRStyle()

    #Create TGraph
    graph = None
    if xerror is None and yerror is None: graph = TGraph(len(xdata), xdata, ydata)
    elif xerror is None  or yerror is None:
        NullErrors = np.zeros(len(xdata))
        if xerror is not None:      graph = TGraphErrors(len(xdata), xdata, ydata, xerror, NullErrors)
        if yerror is not None:      graph = TGraphErrors(len(xdata), xdata, ydata, NullErrors, yerror)
    else:
        graph = TGraphErrors(len(xdata), xdata, ydata, xerror, yerror)

    graph.SetTitle(";" + xlabel + ";" + ylabel)
    graph.SetMarkerSize(.5)
    
    graph.Draw("AP")
    cl.CMS_lumi(Canv, 4, 11, 'Simulation', False)
    
    if xlog :
        Canv.SetLogx()
        graph.GetXaxis().SetRangeUser(0.3*np.min(xdata), 30*np.max(xdata))
    else :
        graph.GetXaxis().SetRangeUser(0.7*np.min(xdata), 1.3*np.max(xdata))
    
    if ylog :
        Canv.SetLogy()
        graph.GetYaxis().SetRangeUser(0.3*np.min(ydata), 10*np.max(ydata))
    else :
        graph.GetYaxis().SetRangeUser(0.5*np.min(ydata), 1.2*np.max(ydata))
   
    #Write extra text
    if additionalInformation is not None:
        lastYpos = 0.8
        lastCorrectedYpos = None
        extraText = TLatex()
        for info in additionalInformation:
            try :
                extraTextString = info[0]
                extraTextXpos = info[1]
                extraTextYpos = info[2]
                extraTextSize = info[3]
            except:
                print("Wrong Format for additionalInformation. Stopping")
                pass
            
            if extraTextSize is None:
                extraTextSize = 0.03
            if extraTextXpos is None:
                extraTextXpos = 0.2
            if extraTextYpos is None:
                if lastYpos is None:
                    extraTextYpos = lastCorrectedYpos -0.05 
                else: extraTextYpos = 0.8
            
            extraText.SetNDC()
            extraText.SetTextAlign(12)
            extraText.SetTextSize(extraTextSize)
            extraText.DrawLatex(extraTextXpos, extraTextYpos, extraTextString)
            
            lastYpos = info[2]
            lastCorrectedYpos = extraTextYpos
 
    #Save
    Canv.SaveAs(destination + ".pdf")    
    Canv.SaveAs(destination + ".png")    
    Canv.SaveAs(destination + ".root")

def plotMultipleROC(xdata, ydata, xlabel, ylabel, legendNames,destination, xerror = None, yerror = None, xlog = False, ylog = False, additionalInformation = None):
    GeneralSettings()
    
    #Create Canvas
    Canv = TCanvas("Canv"+destination, "Canv"+destination, 1000, 1000)
    
    tdr.setTDRStyle()

    #Create TGraph
    graphs = []
    for x, y, xe, ye in zip(xdata, ydata, xerror, yerror):
        tmpgraph = None
        if xe is None and ye is None: 
            tmpgraph = TGraph(len(x), x, y)
        elif xe is None or ye is None:
            NullErrors = np.zeros(len(x))
            if xe is not None:      tmpgraph = TGraphErrors(len(x), x, y, xe, NullErrors)
            if ye is not None:      tmpgraph = TGraphErrors(len(x), x, y, NullErrors, ye)
        else:
            tmpgraph = TGraphErrors(len(x), x, y, xe, ye)
        graphs.append(tmpgraph)
    
    mgraph = TMultiGraph()
    
    for i, graph in enumerate(graphs):
        graph.SetMarkerSize(1.5)
        graph.SetLineColor(TColor.GetColor(GetLineColor(graphs.index(graph))))
        graph.SetMarkerColor(TColor.GetColor(GetLineColor(graphs.index(graph))))
        graph.SetMarkerStyle(GetMarker(graphs.index(graph)))
        mgraph.Add(graph)

    mgraph.Draw("APLine")
    mgraph.SetTitle(";" + xlabel + ";" + ylabel)
    
    cl.CMS_lumi(Canv, 4, 11, 'Simulation', False)
    
    if xlog :
        Canv.SetLogx()
        mgraph.GetXaxis().SetRangeUser(0.3*GetNestedMin(xdata), 30*GetNestedMax(xdata))
    else :
        mgraph.GetXaxis().SetRangeUser(0.7*GetNestedMin(xdata[0]), 1.3*GetNestedMax(xdata))
    
    if ylog :
        Canv.SetLogy()
        mgraph.GetYaxis().SetRangeUser(0.3*GetNestedMin(ydata), 10*GetNestedMax(ydata))
    else :
        mgraph.GetYaxis().SetRangeUser(0.5*GetNestedMin(ydata), 1.2*GetNestedMax(ydata))
   
    #Write extra text
    if additionalInformation is not None:
        lastYpos = 0.8
        lastCorrectedYpos = None
        extraText = TLatex()
        for info in additionalInformation:
            try :
                extraTextString = info[0]
                extraTextXpos = info[1]
                extraTextYpos = info[2]
                extraTextSize = info[3]
            except:
                print("Wrong Format for additionalInformation. Stopping")
                pass
            
            if extraTextSize is None:
                extraTextSize = 0.03
            if extraTextXpos is None:
                extraTextXpos = 0.2
            if extraTextYpos is None:
                if lastYpos is None:
                    extraTextYpos = lastCorrectedYpos -0.05 
                else: extraTextYpos = 0.8
            
            extraText.SetNDC()
            extraText.SetTextAlign(12)
            extraText.SetTextSize(extraTextSize)
            extraText.DrawLatex(extraTextXpos, extraTextYpos, extraTextString)
            
            lastYpos = info[2]
            lastCorrectedYpos = extraTextYpos

    if legendNames:
        legend = TLegend(0.7, .7, .9, .9)
        for g, n in zip(graphs, legendNames):
            legend.AddEntry(g, n)
        legend.SetFillStyle(0)
        legend.SetBorderSize(0)
        legend.Draw() 

    #Save
    Canv.SaveAs(destination + ".pdf")    
    Canv.SaveAs(destination + ".png")    
    Canv.SaveAs(destination + ".root")    

def DrawHist(hist, xlabel, ylabel, legendNames, destination, ylog = False):
    GeneralSettings()

    #Create Canvas
    Canv = TCanvas("Canv"+destination, "Canv"+destination, 1000, 1000)

    tdr.setTDRStyle()

    #Set Histogram Styles
    for h in hist:
        h.SetLineColor(TColor.GetColor(GetHistColor(hist.index(h))))
    title = " ;" +xlabel+ " ; "+ylabel+" / " +str(hist[0].GetBinWidth(1)) + " GeV"
    hist[0].SetTitle(title)
    
    OverallMax = GetOverallMaximum(hist)
    OverallMin = GetOverallMinimum(hist)

    if ylog :
        Canv.SetLogy()
        hist[0].GetYaxis().SetRangeUser(0.3*OverallMin, 30*OverallMax)
    else :
        hist[0].GetYaxis().SetRangeUser(0.7*OverallMin, 1.3*OverallMax)

    #Start Drawing
    for h in hist:
        if(hist.index(h) == 0) :
            h.Draw("EHIST")
        else:
            h.Draw("EHISTSAME")
    #Create Legend
    if legendNames :
        legend = TLegend(0.7, .7, .9, .9)
        for h, n in zip(hist, legendNames):
            legend.AddEntry(h, n)
        legend.SetFillStyle(0)
        legend.SetBorderSize(0)
        legend.Draw()
    
    #CMS lumi
    cl.CMS_lumi(Canv, 4, 11, 'Simulation', False)

    #Save
    Canv.SaveAs(destination + ".pdf")    
    Canv.SaveAs(destination + ".png")    
    Canv.SaveAs(destination + ".root")

def DrawSignificance(hist, destination, legendNames = None, ylog = False):
    GeneralSettings()

    #Create Canvas
    Canv = TCanvas("Canv"+destination, "Canv"+destination, 1000, 1000)

    tdr.setTDRStyle()

    #Set Histogram Styles
    for h in hist:
        h.SetLineColor(TColor.GetColor(GetHistColor(hist.index(h))))
    title = " ; ; S/#sqrt{S+B}"
    hist[0].SetTitle(title)
    
    OverallMax = GetOverallMaximum(hist)
    OverallMin = GetOverallMinimum(hist)

    if ylog :
        Canv.SetLogy()
        hist[0].GetYaxis().SetRangeUser(0.3*OverallMin, 30*OverallMax)
    else :
        hist[0].GetYaxis().SetRangeUser(0.7*OverallMin, 1.3*OverallMax)

    #Start Drawing
    for h in hist:
        if(hist.index(h) == 0) :
            h.Draw("EP")
        else:
            h.Draw("EPSAME")

    #Create Legend
    if legendNames :
        legend = TLegend(0.7, .7, .9, .9)
        for h, n in zip(hist, legendNames):
            legend.AddEntry(h, n)
        legend.SetFillStyle(0)
        legend.SetBorderSize(0)
        legend.Draw()
    
    #CMS lumi
    cl.CMS_lumi(Canv, 4, 11, 'Simulation', False)

    #Save
    Canv.SaveAs(destination + ".pdf")    
    Canv.SaveAs(destination + ".png")    
    Canv.SaveAs(destination + ".root")

def calcAndDrawSignificance(SignalHist, BkgrHist, xtitle, legendNames, DataName, destination):
    GeneralSettings()

    #Make sure the code works for single backgrounds
    try:
        BkgrHist[0]
    except:
        BkgrHist = [BkgrHist]

    #Define a canvas
    Canv = TCanvas("Canv"+destination, "Canv"+destination, 1000, 1000)

    #Set Histogram Styles
    for i, h in enumerate(BkgrHist) :
        h.SetFillColor(TColor.GetColor(GetStackColorTauPOG(i)))
        h.SetLineColor(TColor.GetColor(GetStackColorTauPOG(i)))

    SignalHist.SetMarkerColor(ROOT.kBlack)
    SignalHist.SetLineColor(ROOT.kBlack)
    SignalHist.SetMarkerStyle(20)

    #Calculate significance
    totBkgr = BkgrHist[0].Clone("TotBkgr")
    for h in BkgrHist[1:]:
        totBkgr.Add(h)
    total = totBkgr.Clone("Total")
    total.Add(signalHist)
    sqrt_total = total.Clone('Sqrt_Total')
    for xbin in xrange(1, total.GetSize()-1):                     #GetSize returns nbins + 2 (for overflow and underflow bin)
        sqrt_total.SetBinContent(xbin, sqrt(total.GetBinContent(xbin)))
    
    significance = SignalHist.Clone('Signal')
    significance.Divide(sqrt_total)

    #First pad
    plotpad = TPad("plotpad", "plotpad", 0, .3, 1, 0.98)
    plotpad.SetBottomMargin(0.025)
    plotpad.Draw()
    plotpad.cd()

    #Create Stack (Change with most logical ordering)
    hs = THStack("hs", "hs")
    for h in BkgrHist:
        hs.Add(h)
    hs.Draw("EHist")                                                            #Draw before using GetHistogram, see https://root-forum.cern.ch/t/thstack-gethistogram-null-pointer-error/12892/4
    title = " ; ; Events / " +str(BkgrHist[0].GetBinWidth(1)) + " GeV"
    hs.SetTitle(title)
#    hs.GetHistogram().GetXaxis().SetTickLength(0)
    hs.GetHistogram().GetXaxis().SetLabelOffset(9999999)
    hs.GetHistogram().SetMaximum(1)

    #Set range
    overallMin = GetOverallMinimum(BkgrHist+[SignalHist])
    overallMax = GetOverallMaximum([totBkgr]+[SignalHist])
    hs.SetMinimum(0.5*overallMin)
    hs.SetMaximum(1.2*overallMax)
    SignalHist.Draw("EPSame")

    #Create Legend
    legend = TLegend(0.7, .7, .9, .9)
    for h, n in zip(BkgrHist, legendNames):
        legend.AddEntry(h, n)
    legend.AddEntry(SignalHist, DataName)
    legend.SetFillStyle(0)
    legend.SetBorderSize(0)

    legend.Draw()

    #Return to canvas
    Canv.cd()

    #Second pad
    ratiopad = TPad("ratiopad", "ratiopad", 0, 0.05, 1, .3)
    ratiopad.SetTopMargin(0.05)
    ratiopad.SetBottomMargin(0.25)
    ratiopad.Draw()
    ratiopad.cd()

    #Set Style for bottom plot
    significance.SetTitle(";" + xtitle + "; S/#sqrt{S+B}")
    significance.GetXaxis().SetTitleSize(.12)
    significance.GetYaxis().SetTitleSize(.12)
    significance.GetYaxis().SetTitleOffset(.6)
    significance.GetXaxis().SetLabelSize(.12)
    significance.GetYaxis().SetLabelSize(.12)
    significance.GetYaxis().SetMinimum(0.)
    #DataOverMC.GetYaxis().SetMaximum(2.)
    DataOverMC.Draw("EP")

    #Throw CMs lumi at it
    cl.CMS_lumi(Canv, 4, 11, 'Simulation Preliminary', True)

    #Save everything
    Canv.SaveAs(destination + ".pdf")
    Canv.SaveAs(destination + ".png")
    Canv.SaveAs(destination + ".root")

