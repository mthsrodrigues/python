#ifndef MYPARTICLE_H
#define MYPARTICLE_H

#include "TObject.h"
#include "TLorentzVector.h"
#include <vector>

class MyParticle : public TObject {
private:
    // Dados da partícula
    TLorentzVector fP4;           // Quadrimomento (E, px, py, pz)
    Int_t fCharge;                // Carga elétrica em unidades de e
    Int_t fPdgId;                 // ID PDG da partícula
    Float_t fIsolation;           // Isolamento (0=isolado, 1=overlapping)
    Float_t fChi2;                // Chi2 do ajuste da trajetória
    std::vector<Float_t> fHits;   // Depósitos de energia no detector
    
public:
    // Construtor padrão - OBRIGATÓRIO para ROOT I/O
    MyParticle();
    
    // Construtor com parâmetros
    MyParticle(Double_t energy, Double_t px, Double_t py, Double_t pz,
               Int_t charge, Int_t pdgId);
    
    // Destrutor
    virtual ~MyParticle() {}
    
    // Métodos Getter
    Double_t GetEnergy() const { return fP4.Energy(); }
    Double_t GetPt() const { return fP4.Pt(); }
    Double_t GetEta() const { return fP4.Eta(); }
    Double_t GetPhi() const { return fP4.Phi(); }
    Double_t GetMass() const { return fP4.Mag(); }
    Int_t GetCharge() const { return fCharge; }
    Int_t GetPdgId() const { return fPdgId; }
    Float_t GetIsolation() const { return fIsolation; }
    Float_t GetChi2() const { return fChi2; }
    Int_t GetNHits() const { return fHits.size(); }
    
    // Métodos Setter
    void SetP4(Double_t energy, Double_t px, Double_t py, Double_t pz);
    void SetCharge(Int_t charge) { fCharge = charge; }
    void SetPdgId(Int_t pdgId) { fPdgId = pdgId; }
    void SetIsolation(Float_t iso) { fIsolation = iso; }
    void AddHit(Float_t energy) { fHits.push_back(energy); }
    
    // Método para impressão
    void Print(Option_t* option = "") const;
    
    // Macro ClassDef - ESSENCIAL para ROOT I/O
    // O número 1 é a versão da classe
    ClassDef(MyParticle, 1)
};

#endif

