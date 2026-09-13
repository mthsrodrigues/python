#ifndef MYPARTICLE_H
#define MYPARTICLE_H

#include "TObject.h"
#include "TLorentzVector.h"
#include <vector>

class MyParticle : public TObject {
private:
    TLorentzVector fP4;        // Quadrimomento
    Int_t fCharge;             // Carga elétrica
    Int_t fPdgId;              // ID PDG
    Float_t fIsolation;        // Isolamento
    Float_t fChi2;             // Qualidade do ajuste
    
public:
    MyParticle();              // Construtor padrão
    MyParticle(Double_t E, Double_t px, Double_t py, Double_t pz);
    
    // Getters
    Double_t GetEnergy() const { return fP4.Energy(); }
    Double_t GetPt() const { return fP4.Pt(); }
    Double_t GetEta() const { return fP4.Eta(); }
    Double_t GetPhi() const { return fP4.Phi(); }
    
    ClassDef(MyParticle, 1)
};
#endif
