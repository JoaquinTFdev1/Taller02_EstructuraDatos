#include "Servicio.h"

Servicio::Servicio(string nombre) {
    this->nombre = nombre;
}

Servicio::~Servicio() {}

string Servicio::getNombre() {
    return this->nombre;
}

AVL* Servicio::getArbol() {
    return &this->arbol;
}

bool Servicio::insertarPaciente(Paciente* paciente) {
    return this->arbol.insertar(paciente);
}

Paciente* Servicio::buscarPorId(string id,string& ruta) {
    return this->arbol.buscarPorId(id,ruta);
}

bool Servicio::eliminarPaciente(string id) {
    return this->arbol.eliminar(id);
}

bool Servicio::isEmpty() {
    return this->arbol.isEmpty();
}