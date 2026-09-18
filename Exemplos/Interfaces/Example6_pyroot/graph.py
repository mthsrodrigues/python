#!/usr/bin/env python
import ROOT
from array import array

# Desativa plotagem na tela (modo batch)
ROOT.gROOT.SetBatch(True)
def main():
    # Cria arrays para os dados
    x = array("d")
    y = array("d") 
    x.append(1.0)
    y.append(1.0)
    x.append(3.0)
    y.append(2.0)
    x.append(4.0)
    y.append(2.5)
    x.append(6.0)
    y.append(3.0)
    
    n = len(x)
    
    # Cria canvas
    canvas = ROOT.TCanvas("someName", "Graph Plot", 500, 500)
    canvas.SetFillColor(0)
    canvas.cd()
    
    # Cria frame para eixos
    frame = ROOT.TH2F("frame", "", 2, 0, 6, 2, 0, 4)
    frame.SetStats(0)
    frame.GetXaxis().SetTitle("x")
    frame.GetYaxis().SetTitle("y")
    frame.Draw()
    
    # Cria e plota o gráfico
    graph = ROOT.TGraph(n, x, y)
    graph.SetMarkerStyle(2)   # Quadrado
    graph.SetMarkerSize(2)    # Tamanho 2
    graph.SetLineColor(2)     # Vermelho
    graph.Draw("PL")          # Pontos e linhas
    
    # Salva a figura
    canvas.Print("graph.eps")
    print("Graph saved to graph.eps")

if __name__ == "__main__":
    main()
