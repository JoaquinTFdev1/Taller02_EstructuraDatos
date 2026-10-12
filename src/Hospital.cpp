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

void Hospital::mostrarDepartamentos() {

    cout
        << "\n=== ESTADO DE LOS DEPARTAMENTOS ==="
        << endl;

    for (int i = 0; i < 8; i++) {

        this->servicios[i]
            ->mostrarEstado();
    }
}

Paciente* Hospital::buscarPaciente(string dato, string& servicio,string& ruta) {

    servicio = "";
    ruta = "";

    for (int i = 0; i < 8; i++) {

        string rutaActual = "";
        Paciente* paciente = this->servicios[i]->buscarPorId(dato,rutaActual);

        if (paciente != nullptr) {
            servicio = this->servicios[i]->getNombre();
            ruta = rutaActual;
            return paciente;
        }
    }

    for (int i = 0; i < 8; i++) {
        Paciente* paciente = this->servicios[i]->buscarPorNombre(dato);

        if (paciente != nullptr) {
            servicio = this->servicios[i]->getNombre();
            ruta = "Busqueda por nombre mediante recorrido del AVL";
            return paciente;
        }
    }

    return nullptr;
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

bool Hospital::eliminarPaciente(string id,string& servicio) {

    servicio = "";
    for (int i = 0; i < 8; i++) {

        string ruta = "";
        Paciente* paciente =this->servicios[i]->buscarPorId(id,ruta);

        if (paciente != nullptr) {
            servicio = this->servicios[i]->getNombre();
            return this->servicios[i]->eliminarPaciente(id);
        }
    }

    return false;
}


Servicio* Hospital::obtenerServicioPorNumero(int numero) {
    if (numero < 1 || numero > 8) {
        return nullptr;
    }

    return this->servicios[numero - 1];
}

void Hospital::mostrarServiciosNumerados() {

    cout << "\n=== SERVICIOS ===" << endl;

    for (int i = 0; i < 8; i++) {

        cout << i + 1 << ". " << this->servicios[i]->getNombre() << endl;
    }
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

void Hospital::mostrarRecorridosServicio(int numero) {

    Servicio* servicio = this->obtenerServicioPorNumero(numero);

    if (servicio == nullptr) {
        cout << "Servicio no valido." << endl;
        return;
    }

    cout << "\n=== " << servicio->getNombre() << " ===" << endl;
    servicio->mostrarInorden();
    servicio->mostrarPreorden();
    servicio->mostrarPostorden();
}

void Hospital::mostrarBalanceServicio(int numero) {

    Servicio* servicio = this->obtenerServicioPorNumero(numero);

    if (servicio == nullptr) {
        cout << "Servicio no valido." << endl;
        return;
    }

    cout << "\n=== ESTADO AVL: " << servicio->getNombre() << " ===" << endl;
    cout << "Altura del arbol: " << servicio->getAltura() << endl;
    servicio->mostrarFactores();
}

void Hospital::mostrarRecorridosArbolDecision() {

    this->arbolDecision.mostrarPreorden();
    this->arbolDecision.mostrarInorden();
    this->arbolDecision.mostrarPostorden();
}

int Hospital::getPendientes() {
    return this->cola.getSize();
}