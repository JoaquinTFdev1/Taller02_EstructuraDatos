#pragma once
#include "ColaPacientes.h"
#include "ArbolDecision.h"
#include "Servicio.h"
#include <string>

using namespace std;
class Hospital {

private:
    ColaPacientes cola;
    ArbolDecision arbolDecision;

    Servicio* servicios[8];
    Servicio* obtenerServicio(string nombre);

    bool idExisteEnServicios(string id);
    void mostrarDatosPaciente(Paciente* paciente);

public:
    Hospital();
    ~Hospital();

    bool cargarArchivo(string ruta, int& incorporados, int& rechazados);
    bool atenderSiguiente();
    int getPendientes();
};


