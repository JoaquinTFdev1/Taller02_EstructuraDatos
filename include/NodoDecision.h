#pragma once
#include <string>

using namespace std;
class NodoDecision {

private:

    int tipo;
    string texto;
    string servicio;
    NodoDecision* ramaSi;
    NodoDecision* ramaNo;

public:

    NodoDecision(int tipo, string texto, string servicio);
    ~NodoDecision();

    int getTipo();
    string getTexto();
    string getServicio();

    NodoDecision* getRamaSi();
    NodoDecision* getRamaNo();

    void setRamaSi(NodoDecision* nodo);
    void setRamaNo(NodoDecision* nodo);
    bool esHoja();
};


