#pragma once

#include "Paciente.h"
#include "ColaPacientes.h"

#include <string>

using namespace std;

Paciente* crearPacienteDesdeLinea(string linea, string& error);

bool cargarPacientesEnCola(string ruta, ColaPacientes& cola, int& incorporados, int& rechazados );


