#include "AVL.h"

#include <iostream>

using namespace std;

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

NodoAVL* AVL::insertar(NodoAVL* nodo, Paciente* paciente,bool& insertado) {

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

    if (balance > 1 && idNuevo > nodo->getIzquierda()->getPaciente()->getId()) {
        nodo->setIzquierda(this->rotacionIzquierda(nodo->getIzquierda()));
        return this->rotacionDerecha(nodo);
    }

    if (balance < -1 && idNuevo < nodo->getDerecha()->getPaciente()->getId()) {
        nodo->setDerecha(this->rotacionDerecha(nodo->getDerecha()));
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
    nodo->setAltura(1 + this->maximo(alturaIzquierda,alturaDerecha));
}

int AVL::getAltura() {

    return this->altura(
        this->raiz
    );
}

int AVL::getFactorBalance(NodoAVL* nodo) {

    if (nodo == nullptr) {
        return 0;
    }

    return this->altura(nodo->getIzquierda()) - this->altura(nodo->getDerecha());
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

Paciente* AVL::buscarPorId(string id,string& ruta) {

    ruta = "";
    return this->buscarPorId(this->raiz,id,ruta);
}

Paciente* AVL::buscarPorId(NodoAVL* nodo, string id,string& ruta) {

    if (nodo == nullptr) {
        return nullptr;
    }

    if (!ruta.empty()) {
        ruta += " -> ";
    }

    ruta += nodo->getPaciente()->getId();

    string idActual = nodo->getPaciente()->getId();

    if (id == idActual) {
        return nodo->getPaciente();
    }

    if (id < idActual) {
        return this->buscarPorId(nodo->getIzquierda(),id,ruta);
    }

    return this->buscarPorId(nodo->getDerecha(),id,ruta);
}

void AVL::mostrarInorden(NodoAVL* nodo) {

    if (nodo == nullptr) {
        return;
    }

    this->mostrarInorden(nodo->getIzquierda());

    cout << nodo->getPaciente()->getId() << " - " << nodo->getPaciente()->getNombre() << endl;

    this->mostrarInorden(nodo->getDerecha());
}

void AVL::mostrarInorden() {

    cout << "\n=== RECORRIDO INORDEN ==="<< endl;

    if (this->raiz == nullptr) {

        cout << "Sin pacientes." << endl;
        return;
    }

    this->mostrarInorden(this->raiz);
}

void AVL::mostrarPreorden(NodoAVL* nodo) {

    if (nodo == nullptr) {
        return;
    }

    cout << nodo->getPaciente()->getId() << " - " << nodo->getPaciente()->getNombre() << endl;

    this->mostrarPreorden(nodo->getIzquierda());
    this->mostrarPreorden(nodo->getDerecha());
}

void AVL::mostrarPreorden() {

    cout << "\n=== RECORRIDO PREORDEN ==="<< endl;

    if (this->raiz == nullptr) {

        cout << "Sin pacientes." << endl;
        return;
    }

    this->mostrarPreorden(this->raiz);
}

void AVL::mostrarPostorden(NodoAVL* nodo) {

    if (nodo == nullptr) {
        return;
    }

    this->mostrarPostorden(nodo->getIzquierda());
    this->mostrarPostorden(nodo->getDerecha());

    cout << nodo->getPaciente()->getId() << " - " << nodo->getPaciente()->getNombre() << endl;

}

void AVL::mostrarPostorden() {

    cout << "\n=== RECORRIDO POSTORDEN ===" << endl;

    if (this->raiz == nullptr) {

        cout << "Sin pacientes." << endl;
        return;
    }

    this->mostrarPostorden(this->raiz);
}

void AVL::mostrarFactores(NodoAVL* nodo) {

    if (nodo == nullptr) {
        return;
    }

    this->mostrarFactores(nodo->getIzquierda());

    cout << "ID: " << nodo->getPaciente()->getId() << " | Altura: " << nodo->getAltura() << " | Balance: " << this->getFactorBalance(nodo) << endl;
    this->mostrarFactores(nodo->getDerecha());

}

void AVL::mostrarFactores() {

    cout << "\n=== ALTURAS Y FACTORES DE BALANCE ===" << endl;

    if (this->raiz == nullptr) {
        cout << "Arbol vacio." << endl;
        return;
    }

    this->mostrarFactores(
        this->raiz
    );
}

bool AVL::eliminar(string id) {
    bool eliminado = false;
    this->raiz = this->eliminar(this->raiz,id, eliminado);
    return eliminado;
}

NodoAVL* AVL::nodoMenor(NodoAVL* nodo) {

    NodoAVL* actual = nodo;

    while (actual != nullptr && actual->getIzquierda() != nullptr) {
        actual = actual->getIzquierda();
    }

    return actual;
}

NodoAVL* AVL::eliminar(NodoAVL* nodo, string id,bool& eliminado) {

    if (nodo == nullptr) {
        return nullptr;
    }

    string idActual = nodo->getPaciente()->getId();

    if (id < idActual) {
        nodo->setIzquierda(this->eliminar( nodo->getIzquierda(),id,eliminado));
    }

    else if (id > idActual) {
        nodo->setDerecha(this->eliminar(nodo->getDerecha(),id,eliminado));
    }

    else {

        eliminado = true;

        if (nodo->getIzquierda() == nullptr && nodo->getDerecha() == nullptr) {

            delete nodo->getPaciente();
            delete nodo;

            return nullptr;
        }

        if (nodo->getIzquierda() == nullptr) {

            NodoAVL* hijo = nodo->getDerecha();

            delete nodo->getPaciente();
            delete nodo;

            return hijo;
        }

        if (nodo->getDerecha() == nullptr) {

            NodoAVL* hijo = nodo->getIzquierda();

            delete nodo->getPaciente();
            delete nodo;

            return hijo;
        }

        NodoAVL* sucesor = this->nodoMenor(nodo->getDerecha());

        Paciente* pacienteActual = nodo->getPaciente();
        Paciente* pacienteSucesor = sucesor->getPaciente();

        nodo->setPaciente(pacienteSucesor);
        sucesor->setPaciente(pacienteActual);

        bool eliminadoInterno = false;
        nodo->setDerecha(this->eliminar(nodo->getDerecha(), id, eliminadoInterno));
    }

    this->actualizarAltura(nodo);

    int balance = this->getFactorBalance(nodo);

    if (balance > 1 && this->getFactorBalance(nodo->getIzquierda()) >= 0) {
        return this->rotacionDerecha(nodo);
    }

    if (balance > 1 && this->getFactorBalance(nodo->getIzquierda()) < 0) {
        nodo->setIzquierda(this->rotacionIzquierda(nodo->getIzquierda()));
        return this->rotacionDerecha(nodo);
    }

    if (balance < -1 && this->getFactorBalance(nodo->getDerecha()) <= 0) {
        return this->rotacionIzquierda(nodo);
    }

    if (balance < -1 && this->getFactorBalance(nodo->getDerecha()) > 0) {

        nodo->setDerecha(this->rotacionDerecha(nodo->getDerecha()));
        return this->rotacionIzquierda(nodo);
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

