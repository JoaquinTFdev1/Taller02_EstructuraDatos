#pragma once
#include "NodoDecision.h"

class ArbolDecision {
private:
    NodoDecision* raiz;
    void liberar(NodoDecision* nodo);

public:
    ArbolDecision();
    ~ArbolDecision();
    NodoDecision* getRaiz();
};



