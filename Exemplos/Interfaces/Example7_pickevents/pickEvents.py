#!/usr/bin/env python3
import sys, os, re
import ROOT
 
root_re = re.compile(r"(?P<rootfile>([^/]*))\.root$")
event_re = re.compile(r"(?P<run>(\d+)):(?P<lumi>(\d+)):(?P<event>(\d+))")
 
 
def main():
    if len(sys.argv) == 1:
        print()
        print("# Usage: " + sys.argv[0] + " <root file> -pick <pick events file>")
        print()
        sys.exit()
 
    rootfiles = []
    pickeventsfile = ""
    iarg = 1
    while iarg < len(sys.argv):
        if sys.argv[iarg] == "-pick" and iarg < len(sys.argv) - 1:
            pickeventsfile = sys.argv[iarg + 1]
            iarg += 1
        match = root_re.search(sys.argv[iarg])
        if match:
            rootfiles.append(sys.argv[iarg])
        iarg += 1
 
    events = getEvents(pickeventsfile)
    for file in rootfiles:
        pick(file, events)
 
 
def getEvents(filename):
    events = []
    fIN = open(filename, 'r')
    for line in fIN:
        events.append(line.replace("\n", ""))
    return events
 
 
def pick(filename, events):
    fIN = ROOT.TFile.Open(filename)
    fName = "picked.root"
    match = root_re.search(filename)
    if match:
        namebody = match.group("rootfile")
        fName = filename.replace(namebody, "picked_" + namebody)
 
    fOUT = ROOT.TFile.Open(fName, 'RECREATE')
    intree = fIN.Get("Events")
    tree = intree.CloneTree(0)
 
    for event in events:
        match = event_re.search(event)
        if match:
            selection = "run==" + match.group("run")
            selection += "&&lumi==" + match.group("lumi")
            selection += "&&event==" + match.group("event")
            picktree = intree.CopyTree(selection)
            treelist = ROOT.TList()
            treelist.Add(picktree)
            tree.Merge(treelist)
 
    print("Saving", tree.GetEntries(), "events")
    tree.AutoSave()
    fIN.Close()
    fOUT.Close()
 
 
if __name__ == "__main__":
    main()
