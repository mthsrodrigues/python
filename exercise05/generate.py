import ROOT
from array import array

N = 1000
mean = 0.0
sigma = 1.0

file = ROOT.TFile("data_pyroot.root", "RECREATE")
tree = ROOT.TTree("tree", "Gaussian random numbers")

x = array("d", [0.0])
tree.Branch("x", x, "x/D")

rnd = ROOT.TRandom3(0)

for _ in range(N):
    x[0] = rnd.Gaus(mean, sigma)
    tree.Fill()

tree.Write()
file.Close()
