import ROOT
from array import array

ROOT.gROOT.SetBatch(True)

file = ROOT.TFile("data_pyroot.root", "READ")
tree = file.Get("tree")

x = array("d", [0.0])
tree.SetBranchAddress("x", x)

canvas = ROOT.TCanvas("canvas", "Gaussian distribution", 800, 600)
canvas.SetFillColor(ROOT.kWhite)

hist = ROOT.TH1F(
    "hist",
    "Gaussian distribution;Generated value;Number of entries",
    50, -5, 5
)

hist.SetLineColor(ROOT.kBlack)
hist.SetLineWidth(3)
hist.SetFillColor(ROOT.kYellow)

for i in range(tree.GetEntries()):
    tree.GetEntry(i)
    hist.Fill(x[0])

fit = ROOT.TF1("fit", "gaus", -5, 5)
hist.Fit(fit)

hist.Draw()
canvas.SaveAs("fit_pyroot.png")

print("Mean =", fit.GetParameter(1))
print("Sigma =", fit.GetParameter(2))

file.Close()
