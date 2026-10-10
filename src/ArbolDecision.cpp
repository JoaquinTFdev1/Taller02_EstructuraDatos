#include "ArbolDecision.h"
#include <iostream>

ArbolDecision::ArbolDecision() {
    this->raiz = nullptr;
    this->construirArbol();
}

ArbolDecision::~ArbolDecision() {
    this->liberar(this->raiz);
}

bool ArbolDecision::cumpleCondicion(int tipo,Paciente* paciente) {

    if (paciente == nullptr) {
        return false;
    }

    if (tipo == 1) {
        return paciente->getEdad() < 14;
    }

    if (tipo == 2) {
        return paciente->getTrauma() == 1;
    }

    if (tipo == 3) {
        return paciente->getRequiereCirugia() == 1;
    }

    if (tipo == 4) {
        return paciente->getSintomasNeurologicos() == 1;
    }

    if (tipo == 5) {
        return paciente->getTipoDolor() == "pecho";
    }

    if (tipo == 6) {
        return paciente->getTemperatura() >= 38.5 || paciente->getDolor() >= 8 || paciente->getPresionArterial() >= 160;
    }

    if (tipo == 7) {
        return paciente->getDiasHospitalizacion() >= 2;
    }

    return false;
}

void ArbolDecision::construirArbol() {
    NodoDecision* edad = new NodoDecision(1, "Edad menor a 14", "");
    NodoDecision* trauma = new NodoDecision(2, "Trauma igual a 1", "");
    NodoDecision* cirugia = new NodoDecision(3, "Requiere cirugia igual a 1", "");
    NodoDecision* neurologicos = new NodoDecision(4, "Sintomas neurologicos igual a 1", "");
    NodoDecision* dolorPecho = new NodoDecision(5, "Tipo de dolor igual a pecho", "");
    NodoDecision* urgencia = new NodoDecision(6, "Temperatura alta, dolor intenso o presion alta", "");
    NodoDecision* hospitalizacion = new NodoDecision(7, "Dias de hospitalizacion mayor o igual a 2", "");

    NodoDecision* pediatria = new NodoDecision(0, "", "Pediatria");
    NodoDecision* servicioCirugia = new NodoDecision(0, "", "Cirugia");
    NodoDecision* traumatologia = new NodoDecision(0, "", "Traumatologia");
    NodoDecision* neurologia = new NodoDecision(0, "", "Neurologia");
    NodoDecision* cardiologia = new NodoDecision(0, "", "Cardiologia");
    NodoDecision* urgencias = new NodoDecision(0, "", "Urgencias");
    NodoDecision* servicioHospitalizacion = new NodoDecision(0, "", "Hospitalizacion");
    NodoDecision* medicinaGeneral = new NodoDecision(0, "", "Medicina General");

    edad->setRamaSi(pediatria);
    edad->setRamaNo(trauma);

    trauma->setRamaSi(cirugia);
    trauma->setRamaNo(neurologicos);

    cirugia->setRamaSi(servicioCirugia);
    cirugia->setRamaNo(traumatologia);

    neurologicos->setRamaSi(neurologia);
    neurologicos->setRamaNo(dolorPecho);

    dolorPecho->setRamaSi(cardiologia);
    dolorPecho->setRamaNo(urgencia);

    urgencia->setRamaSi(urgencias);
    urgencia->setRamaNo(hospitalizacion);

    hospitalizacion->setRamaSi(servicioHospitalizacion);
    hospitalizacion->setRamaNo(medicinaGeneral);

    this->raiz = edad;
}

void ArbolDecision::mostrarPreorden(NodoDecision* nodo) {

    if (nodo == nullptr) {
        return;
    }

    this->mostrarNodo(nodo);
    this->mostrarPreorden(nodo->getRamaSi());
    this->mostrarPreorden(nodo->getRamaNo());
}

void ArbolDecision::mostrarNodo(NodoDecision* nodo) {

    if (nodo == nullptr) {
        return;
    }

    if (nodo->esHoja()) {
        cout << "[Servicio: "<< nodo->getServicio() << "]"<< endl;
    }

    else {
        cout << "[Decision: " << nodo->getTexto() << "]" << endl;
    }
}

void ArbolDecision::mostrarInorden(NodoDecision* nodo) {

    if (nodo == nullptr) {
        return;
    }

    this->mostrarInorden(nodo->getRamaSi());
    this->mostrarNodo(nodo);
    this->mostrarInorden(nodo->getRamaNo());
}

void ArbolDecision::mostrarPostorden(NodoDecision* nodo) {

    if (nodo == nullptr) {
        return;
    }

    this->mostrarPostorden(nodo->getRamaSi());
    this->mostrarPostorden(nodo->getRamaNo());
    this->mostrarNodo(nodo);
}

string ArbolDecision::evaluarPaciente(Paciente* paciente,string& ruta) {

    ruta = "";
    if (paciente == nullptr) {
        return "";
    }

    NodoDecision* actual = this->raiz;

    while (actual != nullptr &&!actual->esHoja()) {

        bool resultado = this->cumpleCondicion(actual->getTipo(),paciente);

        if (!ruta.empty()) {
            ruta += " -> ";
        }
        ruta += actual->getTexto();

        if (resultado) {
            ruta += " [SI]";
            actual = actual->getRamaSi();
        }

        else {
            ruta += " [NO]";
            actual = actual->getRamaNo();
        }
    }


    if (actual == nullptr) {
        return "";
    }

    return actual->getServicio();
}

void ArbolDecision::mostrarPreorden() {

    cout << "\n=== PREORDEN ARBOL DE DECISION ===" << endl;
    this->mostrarPreorden(this->raiz);
}


void ArbolDecision::mostrarInorden() {

    cout << "\n=== INORDEN ARBOL DE DECISION ===" << endl;
    this->mostrarInorden(this->raiz);
}


void ArbolDecision::mostrarPostorden() {

    cout << "\n=== POSTORDEN ARBOL DE DECISION ===" << endl;
    this->mostrarPostorden(this->raiz);
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