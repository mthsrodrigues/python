
#include "MyParticle.h"
#include <iostream>
#include <cmath>

// Macro ClassImp - NECESSÁRIA para a implementação
ClassImp(MyParticle)

// Construtor padrão - DEVE inicializar todos os membros
MyParticle::MyParticle() : 
    fP4(0, 0, 0, 0),  // TLorentzVector(px, py, pz, E)
    fCharge(0),
    fPdgId(0),
    fIsolation(0.0),
    fChi2(0.0) {
    // fHits é inicializado automaticamente como vazio
}

// Construtor com parâmetros
MyParticle::MyParticle(Double_t energy, Double_t px, Double_t py, Double_t pz,
                       Int_t charge, Int_t pdgId) :
    fP4(px, py, pz, energy),
    fCharge(charge),
    fPdgId(pdgId),
    fIsolation(0.0),
    fChi2(0.0) {
    // fHits inicializado vazio
}

void MyParticle::SetP4(Double_t energy, Double_t px, Double_t py, Double_t pz) {
    fP4.SetPx(px);
    fP4.SetPy(py);
    fP4.SetPz(pz);
    fP4.SetE(energy);
}

void MyParticle::Print(Option_t* option) const {
    std::cout << "=== MyParticle ===" << std::endl;
    std::cout << "PDG ID: " << fPdgId << std::endl;
    std::cout << "Charge: " << fCharge << " e" << std::endl;
    std::cout << "Energy: " << GetEnergy() << " GeV" << std::endl;
    std::cout << "Pt: " << GetPt() << " GeV/c" << std::endl;
    std::cout << "Eta: " << GetEta() << std::endl;
    std::cout << "Phi: " << GetPhi() << " rad" << std::endl;
    std::cout << "Mass: " << GetMass() << " GeV/c^2" << std::endl;
    std::cout << "Isolation: " << fIsolation << std::endl;
    std::cout << "Chi2: " << fChi2 << std::endl;
    std::cout << "Number of hits: " << fHits.size() << std::endl;
}
