#include "Hospital.h"
#include "ArchivoPacientes.h"
#include "Utilidades.h"
#include <iostream>

using namespace std;
Hospital::Hospital() {

    this->servicios[0] = new Servicio("Urgencias");
    this->servicios[1] = new Servicio("Medicina General");
    this->servicios[2] = new Servicio("Cardiologia");
    this->servicios[3] = new Servicio("Neurologia");
    this->servicios[4] = new Servicio("Traumatologia");
    this->servicios[5] = new Servicio("Cirugia");
    this->servicios[6] = new Servicio("Pediatria");
    this->servicios[7] = new Servicio("Hospitalizacion");

}

Hospital::~Hospital() {
    for (int i = 0; i < 8; i++) {
        delete this->servicios[i];
    }
}

Servicio* Hospital::obtenerServicio(string nombre) {

    for (int i = 0; i < 8; i++) {

        if (textosIguales(this->servicios[i]->getNombre(),nombre)) {
            return this->servicios[i];
        }
    }

    return nullptr;
}

bool Hospital::idExisteEnServicios(string id) {

    for (int i = 0; i < 8; i++) {
        string ruta = "";

        if (this->servicios[i]->buscarPorId(id,ruta) != nullptr) {
            return true;
        }
    }

    return false;
}

bool Hospital::cargarArchivo(string ruta, int& incorporados, int& rechazados) {

    ColaPacientes temporal;

    int validosArchivo = 0;
    int rechazadosArchivo = 0;

    bool cargado = cargarPacientesEnCola(ruta,temporal, validosArchivo, rechazadosArchivo);

    if (!cargado) {
        return false;
    }

    incorporados = 0;
    rechazados = rechazadosArchivo;

    while (!temporal.isEmpty()) {

        Paciente* paciente = temporal.pop();
        bool duplicado = this->cola.buscarPorId(paciente->getId()) != nullptr;

        if (!duplicado) {
            duplicado = this->idExisteEnServicios(paciente->getId());
        }

        if (duplicado) {
            cout << "Paciente rechazado por ID duplicado: " << paciente->getId() << endl;
            delete paciente;
            rechazados++;
            continue;
        }

        this->cola.push(paciente);
        incorporados++;
    }

    return true;
}

void Hospital::mostrarDatosPaciente(Paciente* paciente) {

    if (paciente == nullptr) {
        return;
    }

    cout << "ID: " << paciente->getId() << endl;
    cout << "Nombre: " << paciente->getNombre() << endl;
    cout << "Edad: " << paciente->getEdad() << endl;
    cout << "Temperatura: " << paciente->getTemperatura() << endl;
    cout << "PresionArterial: " << paciente->getPresionArterial() << endl;
    cout << "Dolor: " << paciente->getDolor()<< endl;
    cout << "TipoDolor: " << paciente->getTipoDolor() << endl;
    cout << "Trauma: " << paciente->getTrauma() << endl;
    cout << "SintomasNeurologicos: " << paciente->getSintomasNeurologicos()<< endl;
    cout << "RequiereCirugia: " << paciente->getRequiereCirugia() << endl;
    cout << "DiasHospitalizacion: " << paciente->getDiasHospitalizacion() << endl;

}

bool Hospital::atenderSiguiente() {

    if (this->cola.isEmpty()) {
        cout << "No hay pacientes pendientes." << endl;
        return false;
    }

    Paciente* paciente = this->cola.pop();
    string ruta = "";

    string nombreServicio = this->arbolDecision.evaluarPaciente(paciente, ruta);

    Servicio* servicio = this->obtenerServicio(nombreServicio);

    cout << "\n=== ATENDIENDO PACIENTE ===" << endl;

    this->mostrarDatosPaciente(paciente);

    cout << "\nRuta: " << ruta << endl;
    cout << "\nServicio asignado: " << nombreServicio << endl;

    if (servicio == nullptr) {
        cout << "No fue posible encontrar el servicio." << endl;
        delete paciente;
        return false;
    }

    bool insertado = servicio->insertarPaciente(paciente);

    if (!insertado) {

        cout << "No fue posible insertar el paciente." << endl;
        delete paciente;
        return false;
    }

    cout << "Paciente insertado en el AVL de " << nombreServicio << "." << endl;
    return true;
}

int Hospital::getPendientes() {
    return this->cola.getSize();
}