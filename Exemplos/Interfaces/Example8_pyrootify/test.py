#!/usr/bin/env python
import ROOT

# Carrega a biblioteca com as classes
ROOT.gSystem.Load("libMyEvent.so")

# Cria objetos como no C++
muon = ROOT.MyParticle(100.0, 10.0, 5.0, 1.0, -1, 13)
muon.Print()

# Cria evento
event = ROOT.MyEvent(1, 12345, 50)
event.AddMuon(muon)
event.AddElectron(ROOT.MyParticle(50.0, 5.0, 2.0, 0.5, -1, 11))

print(f"Number of muons: {event.GetNMuons()}")
print(f"Number of electrons: {event.GetNElectrons()}")
# Salva em arquivo
f = ROOT.TFile("events.root", "RECREATE")
event.Write("event1")
f.Close()

# Lê de volta
f2 = ROOT.TFile("events.root")
event2 = f2.Get("event1")
event2.PrintSummary()
f2.Close()
