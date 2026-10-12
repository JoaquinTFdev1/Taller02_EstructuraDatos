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
    Servicio* obtenerServicioPorNumero(int numero);

    bool idExisteEnServicios(string id);
    void mostrarDatosPaciente(Paciente* paciente);

public:
    Hospital();
    ~Hospital();
    bool cargarArchivo(string ruta,int& incorporados,int& rechazados);
    bool atenderSiguiente();
    int getPendientes();
    void mostrarDepartamentos();
    void mostrarServiciosNumerados();
    Paciente* buscarPaciente(string dato,string& servicio,string& ruta);
    bool eliminarPaciente(string id,string& servicio);
    void mostrarRecorridosServicio(int numero);
    void mostrarBalanceServicio(int numero);
    void mostrarRecorridosArbolDecision();
};


