#include "ArbolDecision.h"

ArbolDecision::ArbolDecision() {
    this->raiz = new NodoDecision(1, "Edad menor a 14","");
}

ArbolDecision::~ArbolDecision() {
    this->liberar(this->raiz);
}

void ArbolDecision::liberar(NodoDecision* nodo) {
    if (nodo == nullptr) {
        return;
    }

    this->liberar(nodo->getRamaSi());
    this->liberar(nodo->getRamaNo());
    delete nodo;
}

NodoDecision* ArbolDecision::getRaiz() {
    return this->raiz;
}