#include "ColaPacientes.h"
#include <iostream>

using namespace std;

ColaPacientes::ColaPacientes() {
    this->frente = nullptr;
    this->final = nullptr;
    this->cantidad = 0;
}

ColaPacientes::~ColaPacientes() {
    while (!this->isEmpty()) {
        Paciente* paciente = this->pop();
        delete paciente;
    }
}

bool ColaPacientes::isEmpty() {
    return this->frente == nullptr;
}

int ColaPacientes::getSize() {
    return this->cantidad;
}

void ColaPacientes::push(Paciente* paciente) {
    if (paciente == nullptr) {
        return;
    }

    NodoCola* nuevo = new NodoCola(paciente);

    if (this->frente == nullptr) {
        this->frente = nuevo;
        this->final = nuevo;
    } else {
        this->final->next = nuevo;
        this->final = nuevo;
    }

    this->cantidad++;
}

Paciente* ColaPacientes::pop() {
    if (this->frente == nullptr) {
        return nullptr;
    }

    NodoCola* eliminado = this->frente;
    Paciente* paciente = eliminado->paciente;

    this->frente = eliminado->next;

    if (this->frente == nullptr) {
        this->final = nullptr;
    }

    delete eliminado;
    this->cantidad--;

    return paciente;
}

Paciente* ColaPacientes::front() {
    if (this->frente == nullptr) {
        return nullptr;
    }

    return this->frente->paciente;
}

Paciente* ColaPacientes::buscarPorId(string id) {
    NodoCola* actual = this->frente;

    while (actual != nullptr) {
        if (actual->paciente->getId() == id) {
            return actual->paciente;
        }

        actual = actual->next;
    }

    return nullptr;
}

void ColaPacientes::mostrar() {
    cout << "\n=== PACIENTES EN ESPERA ===" << endl;

    if (this->frente == nullptr) {
        cout << "No hay pacientes pendientes." << endl;
        return;
    }

    NodoCola* actual = this->frente;
    int numero = 1;

    while (actual != nullptr) {
        cout << numero << ". " << actual->paciente->getId() << " - " << actual->paciente->getNombre() << endl;
        actual = actual->next;
        numero++;
    }
}