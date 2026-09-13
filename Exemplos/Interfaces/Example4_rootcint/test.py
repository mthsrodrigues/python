#!/usr/bin/env python
import ROOT

# Carrega a biblioteca com as classes
ROOT.gSystem.Load("libMyEvent.so")

# Cria objetos como no C++
muon = ROOT.MyParticle(100.0, 10.0, 5.0, 1.0)
muon.Print()

# Cria evento
event = ROOT.MyEvent()
event.AddMuon(muon)
event.AddElectron(ROOT.MyParticle(50.0, 5.0, 2.0, 0.5))

print(f"Run Number: {event.GetRunNumber()}")
print(f"Event Number: {event.GetEventNumber()}")

# Salva em arquivo
f = ROOT.TFile("events.root", "RECREATE")
event.Write("event1")
f.Close()

# Lê de volta
f2 = ROOT.TFile("events.root")
event2 = f2.Get("event1")
f2.Close()
