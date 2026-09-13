#include "MyParticle.h"

ClassImp(MyParticle)

MyParticle::MyParticle() : fCharge(0), fPdgId(0), 
                           fIsolation(0), fChi2(0) {
    // Construtor padrão - OBRIGATÓRIO
}

MyParticle::MyParticle(Double_t E, Double_t px, 
                       Double_t py, Double_t pz)
    : fP4(px, py, pz, E), fCharge(0), fPdgId(0),
      fIsolation(0), fChi2(0) {
    // Construtor com parâmetros
}
