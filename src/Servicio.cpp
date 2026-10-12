#include "Servicio.h"
#include <iostream>

using namespace std;

Servicio::Servicio(string nombre) {
    this->nombre = nombre;
}

Servicio::~Servicio() {
}

string Servicio::getNombre() {
    return this->nombre;
}

AVL* Servicio::getArbol() {
    return &this->arbol;
}

bool Servicio::insertarPaciente(Paciente* paciente) {
    return this->arbol.insertar(paciente);
}

Paciente* Servicio::buscarPorId(string id, string& ruta) {
    return this->arbol.buscarPorId(id, ruta);
}

Paciente* Servicio::buscarPorNombre(string nombre) {
    return this->arbol.buscarPorNombre(nombre);
}

bool Servicio::eliminarPaciente(string id) {
    return this->arbol.eliminar(id);
}

bool Servicio::isEmpty() {
    return this->arbol.isEmpty();
}

int Servicio::getAltura() {
    return this->arbol.getAltura();
}

void Servicio::mostrarEstado() {
    cout << "\n" << this->nombre << endl;

    if (this->arbol.isEmpty()) {
        cout << "Sin pacientes" << endl;
        return;
    }

    cout << "Pacientes:" << endl;
    this->arbol.mostrarPacientes();
}

void Servicio::mostrarInorden() {
    this->arbol.mostrarInorden();
}

void Servicio::mostrarPreorden() {
    this->arbol.mostrarPreorden();
}

void Servicio::mostrarPostorden() {
    this->arbol.mostrarPostorden();
}

void Servicio::mostrarFactores() {
    this->arbol.mostrarFactores();
}



