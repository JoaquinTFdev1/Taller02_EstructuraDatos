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
    this->raiz = this->insertar(this->raiz, paciente, insertado);

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
        nodo->setIzquierda(this->insertar(
            nodo->getIzquierda(), paciente, insertado
        ));
    }

    else if (idNuevo > idActual) {
        nodo->setDerecha(this->insertar(nodo->getDerecha(), paciente, insertado));
    }

    else {
        insertado = false;
        return nodo;
    }
    this->actualizarAltura(nodo);
    int balance = this->getFactorBalance(nodo);

    if (balance > 1 && idNuevo < nodo->getIzquierda()->getPaciente()->getId()) {
        return this->rotacionDerecha(nodo);
    }
    if (balance < -1 && idNuevo > nodo->getDerecha()->getPaciente()->getId()) {
        return this->rotacionIzquierda(nodo);
    }

    return nodo;
}

int AVL::altura(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    return nodo->getAltura();
}

int AVL::maximo(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}

void AVL::actualizarAltura(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return;
    }

    int alturaIzquierda = this->altura(nodo->getIzquierda());
    int alturaDerecha = this->altura(nodo->getDerecha());

    nodo->setAltura(1 + this->maximo(alturaIzquierda, alturaDerecha));
}

int AVL::getAltura() {
    return this->altura(this->raiz);
}

int AVL::getFactorBalance(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    return this->altura(nodo->getIzquierda()) -
           this->altura(nodo->getDerecha());
}

NodoAVL* AVL::rotacionDerecha(NodoAVL* nodo) {
    NodoAVL* nuevaRaiz = nodo->getIzquierda();
    NodoAVL* temporal = nuevaRaiz->getDerecha();

    nuevaRaiz->setDerecha(nodo);

    nodo->setIzquierda(temporal);

    this->actualizarAltura(nodo);
    this->actualizarAltura(nuevaRaiz);

    return nuevaRaiz;
}

NodoAVL* AVL::rotacionIzquierda(NodoAVL* nodo) {
    NodoAVL* nuevaRaiz = nodo->getDerecha();
    NodoAVL* temporal = nuevaRaiz->getIzquierda();

    nuevaRaiz->setIzquierda(nodo);
    nodo->setDerecha(temporal);

    this->actualizarAltura(nodo);
    this->actualizarAltura(nuevaRaiz);

    return nuevaRaiz;
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