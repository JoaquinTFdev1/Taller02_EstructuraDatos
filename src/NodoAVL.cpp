#include "NodoAVL.h"

NodoAVL::NodoAVL(Paciente* paciente) {
    this->paciente = paciente;
    this->izquierda = nullptr;
    this->derecha = nullptr;
    this->altura = 1;
}

NodoAVL::~NodoAVL() {
    delete this->paciente;
    this->paciente = nullptr;
}

Paciente* NodoAVL::getPaciente() {
    return this->paciente;
}

NodoAVL* NodoAVL::getIzquierda() {
    return this->izquierda;
}

NodoAVL* NodoAVL::getDerecha() {
    return this->derecha;
}

int NodoAVL::getAltura() {
    return this->altura;
}

void NodoAVL::setPaciente(Paciente* paciente) {
    this->paciente = paciente;
}

void NodoAVL::setIzquierda(NodoAVL* nodo) {
    this->izquierda = nodo;
}

void NodoAVL::setDerecha(NodoAVL* nodo) {
    this->derecha = nodo;
}

void NodoAVL::setAltura(int altura) {
    this->altura = altura;
}