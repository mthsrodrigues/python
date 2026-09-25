# PYTHIA8 Higgs simulation

This exercise simulates proton-proton collisions at 13 TeV using PYTHIA 8.318 with the CTEQ6L1 PDF set through LHAPDF 6.5.6.

The signal sample contains 1000 Standard Model Higgs events produced through gluon fusion, with a Higgs mass of 125 GeV and the decay H -> bb.

Three background samples were also generated with 1000 events each:

- QCD bb production
- Z -> bb production
- ttbar production

For the Higgs signal, the invariant mass is reconstructed from the b and anti-b quarks associated with the Higgs decay in the PYTHIA event record.

For the background samples, a bb invariant-mass candidate is constructed from the highest-pT b and anti-b quarks found in the event record.

The ROOT files contain a TTree named `events` with the reconstructed mass stored in the `mH` branch.

The final figure `higgs_backgrounds.png` compares normalized invariant-mass distributions for the signal and background samples.

## Files

- `higgs.cmnd`: Higgs PYTHIA configuration
- `qcd_bb.cmnd`: QCD bb configuration
- `zbb.cmnd`: Z -> bb configuration
- `ttbar.cmnd`: ttbar configuration
- `main_higgs.cc`: Higgs event generation and reconstruction
- `main_backgrounds.cc`: background generation and reconstruction
- `Makefile`: compilation
- `plot.C`: ROOT plotting macro
- `higgs_mass.root`: Higgs output
- `qcd_bb.root`: QCD background
- `zbb.root`: Z background
- `ttbar.root`: ttbar background
- `higgs_backgrounds.png`: final comparison
