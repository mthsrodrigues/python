#ifndef MYEVENT_H
#define MYEVENT_H

#include "TObject.h"
#include "MyParticle.h"
#include <vector>

class MyEvent : public TObject {
private:
    Int_t fRunNumber;
    Int_t fEventNumber;
    Int_t fLuminosityBlock;
    std::vector<MyParticle> fMuons;
    std::vector<MyParticle> fElectrons;
    std::vector<MyParticle> fJets;
    
public:
    MyEvent();
    void AddMuon(const MyParticle& mu);
    void AddElectron(const MyParticle& el);
    void AddJet(const MyParticle& jet);
    
    // Getters
    Int_t GetRunNumber() const { return fRunNumber; }
    Int_t GetEventNumber() const { return fEventNumber; }
    
    ClassDef(MyEvent, 1)
};
#endif
