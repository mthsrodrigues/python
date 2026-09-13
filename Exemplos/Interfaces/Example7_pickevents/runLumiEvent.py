#!/usr/bin/env python

import sys
import os
import ROOT
import array

def usage():
    print
    print("### Usage:  ",os.path.basename(sys.argv[0]),"inputfile(s)")
    print
    sys.exit()

def main():

    if len(sys.argv) < 1:
        usage()

    for f in sys.argv[1:]:
        fIN = ROOT.TFile.Open(f)
        tree = fIN.Get("Events")

        run   = array.array('I',[0])
        lumi  = array.array('I',[0])
        event = array.array('Q',[0])
        tree.SetBranchAddress("run",run)
        #tree.SetBranchAddress("luminosityBlock",lumi)
        tree.SetBranchAddress("lumi",lumi)
        tree.SetBranchAddress("event",event)
        
        fOUT = open(os.path.basename(f).split('.')[0]+".pickevents",'w')
        for i in range(0,tree.GetEntries()):
            tree.GetEvent(i)
            print("%s:%s:%s"%(run[0],lumi[0],event[0]))
            fOUT.write("%s:%s:%s\n"%(run[0],lumi[0],event[0]))
        fOUT.close()

if __name__=="__main__":
    main()
