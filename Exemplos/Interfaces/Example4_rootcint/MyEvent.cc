#include "MyEvent.h"

ClassImp(MyEvent)

MyEvent::MyEvent() : fRunNumber(0), fEventNumber(0),
                     fLuminosityBlock(0) {
    // Construtor padrão
}

void MyEvent::AddMuon(const MyParticle& mu) {
    fMuons.push_back(mu);
}

void MyEvent::AddElectron(const MyParticle& el) {
    fElectrons.push_back(el);
}

void MyEvent::AddJet(const MyParticle& jet) {
    fJets.push_back(jet);
}
