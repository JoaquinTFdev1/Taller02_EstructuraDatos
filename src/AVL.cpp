#include "AVL.h"

AVL::AVL() {
    this->raiz = nullptr;
}

AVL::~AVL() {
    this->liberar(this->raiz);
}

NodoAVL* AVL::getRaiz() {
    return this->raiz;
}

bool AVL::isEmpty() {
    return this->raiz == nullptr;
}

bool AVL::insertar(Paciente* paciente) {

    if (paciente == nullptr) {
        return false;
    }

    bool insertado = false;
    this->raiz = this->insertar(this->raiz,paciente,insertado);

    return insertado;
}

NodoAVL* AVL::insertar(NodoAVL* nodo, Paciente* paciente, bool& insertado) {

    if (nodo == nullptr) {
        insertado = true;
        return new NodoAVL(paciente);
    }

    string idNuevo = paciente->getId();
    string idActual = nodo->getPaciente()->getId();

    if (idNuevo < idActual) {
        nodo->setIzquierda(this->insertar(nodo->getIzquierda(),paciente,insertado));
    }

    else if (idNuevo > idActual) {
        nodo->setDerecha(this->insertar(nodo->getDerecha(),paciente,insertado));
    }

    else {
        insertado = false;
    }
    return nodo;
}

void AVL::liberar(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return;
    }

    this->liberar(nodo->getIzquierda());
    this->liberar(nodo->getDerecha());
    delete nodo->getPaciente();
    delete nodo;
}