#ifdef __CINT__

// Desativa links para tudo por padrão
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

// Ativa links para nossas classes
#pragma link C++ class MyParticle+;
#pragma link C++ class vector<MyParticle>;
#pragma link C++ class MyEvent+;
#pragma link C++ class vector<MyEvent>;

// Se quisermos também disponibilizar os métodos
// #pragma link C++ function MyParticle::Print;

#endif
