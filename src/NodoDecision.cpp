#include "NodoDecision.h"

NodoDecision::NodoDecision(int tipo, string texto,string servicio) {
    this->tipo = tipo;
    this->texto = texto;
    this->servicio = servicio;
    this->ramaSi = nullptr;
    this->ramaNo = nullptr;
}


NodoDecision::~NodoDecision() {}


int NodoDecision::getTipo() {
    return this->tipo;
}

string NodoDecision::getTexto() {
    return this->texto;
}


string NodoDecision::getServicio() {
    return this->servicio;
}


NodoDecision* NodoDecision::getRamaSi() {
    return this->ramaSi;
}

NodoDecision* NodoDecision::getRamaNo() {
    return this->ramaNo;
}

void NodoDecision::setRamaSi(NodoDecision* nodo) {
    this->ramaSi = nodo;
}

void NodoDecision::setRamaNo(NodoDecision* nodo) {
    this->ramaNo = nodo;
}

bool NodoDecision::esHoja() {
    return !this->servicio.empty();
}