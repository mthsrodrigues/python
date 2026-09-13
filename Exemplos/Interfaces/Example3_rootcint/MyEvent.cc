#include "MyEvent.h"
#include <iostream>

ClassImp(MyEvent)

MyEvent::MyEvent() :
    fRunNumber(0),
    fEventNumber(0),
    fLuminosityBlock(0),
    fEventWeight(1.0),
    fProcessType("Unknown"),
    fMissingET(0.0),
    fMissingETPhi(0.0) {
    // Todas as coleções são inicializadas vazias
}

MyEvent::MyEvent(Int_t run, Int_t event, Int_t lumi) :
    fRunNumber(run),
    fEventNumber(event),
    fLuminosityBlock(lumi),
    fEventWeight(1.0),
    fProcessType("Unknown"),
    fMissingET(0.0),
    fMissingETPhi(0.0) {
}

void MyEvent::SetMissingET(Float_t met, Float_t phi) {
    fMissingET = met;
    fMissingETPhi = phi;
}

void MyEvent::PrintSummary(Option_t* option) const {
    std::cout << "=== MyEvent ===" << std::endl;
    std::cout << "Run: " << fRunNumber << std::endl;
    std::cout << "Event: " << fEventNumber << std::endl;
    std::cout << "Luminosity Block: " << fLuminosityBlock << std::endl;
    std::cout << "Process: " << fProcessType << std::endl;
    std::cout << "Event Weight: " << fEventWeight << std::endl;
    std::cout << "MET: " << fMissingET << " GeV, phi: " << fMissingETPhi << " rad" << std::endl;
    std::cout << "Muons: " << fMuons.size() << std::endl;
    std::cout << "Electrons: " << fElectrons.size() << std::endl;
    std::cout << "Jets: " << fJets.size() << std::endl;
    std::cout << "Photons: " << fPhotons.size() << std::endl;
}
