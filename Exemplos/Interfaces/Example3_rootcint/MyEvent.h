
#ifndef MYEVENT_H
#define MYEVENT_H

#include "TObject.h"
#include "MyParticle.h"
#include <vector>
#include <string>

class MyEvent : public TObject {
private:
    Int_t fRunNumber;           // Número do run
    Int_t fEventNumber;         // Número do evento
    Int_t fLuminosityBlock;     // Bloco de luminosidade
    Float_t fEventWeight;       // Peso do evento
    std::string fProcessType;   // Tipo de processo físico
    
    // Coleções de partículas
    std::vector<MyParticle> fMuons;
    std::vector<MyParticle> fElectrons;
    std::vector<MyParticle> fJets;
    std::vector<MyParticle> fPhotons;
    std::vector<MyParticle> fTaus;
    
    // Metadados
    Float_t fMissingET;         // Energia faltante (MET)
    Float_t fMissingETPhi;      // Phi do MET
    
public:
    // Construtor padrão - OBRIGATÓRIO
    MyEvent();
    
    // Construtor com parâmetros básicos
    MyEvent(Int_t run, Int_t event, Int_t lumi);
    
    // Destrutor
    virtual ~MyEvent() {}
    
    // Getters
    Int_t GetRunNumber() const { return fRunNumber; }
    Int_t GetEventNumber() const { return fEventNumber; }
    Int_t GetLuminosityBlock() const { return fLuminosityBlock; }
    Float_t GetEventWeight() const { return fEventWeight; }
    Float_t GetMissingET() const { return fMissingET; }
    Int_t GetNMuons() const { return fMuons.size(); }
    Int_t GetNElectrons() const { return fElectrons.size(); }
    Int_t GetNJets() const { return fJets.size(); }
    Int_t GetNPhotons() const { return fPhotons.size(); }
    
    // Setters
    void SetRunNumber(Int_t run) { fRunNumber = run; }
    void SetEventNumber(Int_t event) { fEventNumber = event; }
    void SetMissingET(Float_t met, Float_t phi);
    
    // Métodos para adicionar partículas
    void AddMuon(const MyParticle& mu) { fMuons.push_back(mu); }
    void AddElectron(const MyParticle& el) { fElectrons.push_back(el); }
    void AddJet(const MyParticle& jet) { fJets.push_back(jet); }
    void AddPhoton(const MyParticle& photon) { fPhotons.push_back(photon); }
    
    // Métodos para acessar coleções
    const std::vector<MyParticle>& GetMuons() const { return fMuons; }
    const std::vector<MyParticle>& GetElectrons() const { return fElectrons; }
    const std::vector<MyParticle>& GetJets() const { return fJets; }
    
    // Método para impressão resumida
    void PrintSummary(Option_t* option = "") const;
    
    // Macro ClassDef
    ClassDef(MyEvent, 1)
};

#endif
