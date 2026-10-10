// Nombre: Joaquín Esteban Torres Flores
// RUT: 21.547.370-8
// Usuario de GitHub: JoaquinTFdev1
// Carrera: Ingeniería Civil Industrial
// Paralelo: C1

#include <iostream>

#include "ArchivoPacientes.h"
#include "ColaPacientes.h"
#include "ArbolDecision.h"

using namespace std;


int main() {

    ColaPacientes cola;

    ArbolDecision arbol;


    int incorporados = 0;

    int rechazados = 0;


    bool cargado =
        cargarPacientesEnCola(
            "pacientes.txt",
            cola,
            incorporados,
            rechazados
        );


    if (!cargado) {

        return 0;
    }


    cout
        << "Pacientes incorporados: "
        << incorporados
        << endl;


    cout
        << "Registros rechazados: "
        << rechazados
        << endl;


    cout
        << "\n=== CLASIFICACION DE PACIENTES ==="
        << endl;


    while (!cola.isEmpty()) {

        Paciente* paciente =
            cola.pop();


        string ruta = "";


        string servicio =
            arbol.evaluarPaciente(
                paciente,
                ruta
            );


        cout
            << "\nID: "
            << paciente->getId()
            << endl;


        cout
            << "Nombre: "
            << paciente->getNombre()
            << endl;


        cout
            << "Ruta: "
            << ruta
            << endl;


        cout
            << "Servicio: "
            << servicio
            << endl;


        delete paciente;
    }


    arbol.mostrarPreorden();


    arbol.mostrarInorden();


    arbol.mostrarPostorden();


    return 0;
}