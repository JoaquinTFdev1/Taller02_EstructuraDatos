// Nombre: Joaquín Esteban Torres Flores
// RUT: 21.547.370-8
// Usuario de GitHub: JoaquinTFdev1
// Carrera: Ingeniería Civil Industrial
// Paralelo: C1

#include <iostream>
#include <string>
#include "Hospital.h"
#include "Utilidades.h"

using namespace std;

void mostrarPacienteEncontrado(Paciente* paciente, string servicio, string ruta) {
    if (paciente == nullptr) {
        return;
    }

    cout << "\nPaciente encontrado:" << endl;
    cout << "ID: " << paciente->getId() << endl;
    cout << "Nombre: " << paciente->getNombre() << endl;
    cout << "Edad: " << paciente->getEdad() << endl;
    cout << "Departamento: " << servicio << endl;
    cout << "Temperatura: " << paciente->getTemperatura() << endl;
    cout << "PresionArterial: " << paciente->getPresionArterial() << endl;
    cout << "Dolor: " << paciente->getDolor() << endl;
    cout << "TipoDolor: " << paciente->getTipoDolor() << endl;
    cout << "Trauma: " << paciente->getTrauma() << endl;
    cout << "SintomasNeurologicos: " << paciente->getSintomasNeurologicos() << endl;
    cout << "RequiereCirugia: " << paciente->getRequiereCirugia() << endl;
    cout << "DiasHospitalizacion: " << paciente->getDiasHospitalizacion() << endl;

    cout << "\nRuta de busqueda:" << endl;
    cout << ruta << endl;
}

void menuArboles(Hospital& hospital) {
    int opcion = 0;
    string entrada = "";

    do {
        cout << "\n=== OPERACIONES DE ARBOLES ===" << endl;
        cout << "1. Mostrar recorridos de un AVL" << endl;
        cout << "2. Mostrar altura y factores de balance" << endl;
        cout << "3. Eliminar paciente por ID" << endl;
        cout << "4. Mostrar recorridos del arbol de decision" << endl;
        cout << "5. Volver" << endl;
        cout << "\nSeleccionar opcion: ";

        getline(cin, entrada);
        opcion = 0;
        convertirAEnteroNoNegativo(entrada, opcion);

        if (opcion == 1) {
            hospital.mostrarServiciosNumerados();
            cout << "\nSeleccionar servicio: ";
            getline(cin, entrada);

            int servicio = 0;
            convertirAEnteroNoNegativo(entrada, servicio);
            hospital.mostrarRecorridosServicio(servicio);
        }
        else if (opcion == 2) {
            hospital.mostrarServiciosNumerados();
            cout << "\nSeleccionar servicio: ";
            getline(cin, entrada);

            int servicio = 0;
            convertirAEnteroNoNegativo(entrada, servicio);
            hospital.mostrarBalanceServicio(servicio);
        }
        else if (opcion == 3) {
            string id = "";

            cout << "\nID del paciente a eliminar: ";
            getline(cin, id);

            string servicio = "";
            bool eliminado = hospital.eliminarPaciente(id, servicio);

            if (eliminado) {
                cout << "Paciente eliminado del AVL de "
                     << servicio << "." << endl;
            }
            else {
                cout << "Paciente no encontrado." << endl;
            }
        }
        else if (opcion == 4) {
            hospital.mostrarRecorridosArbolDecision();
        }
        else if (opcion != 5) {
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 5);
}

int main() {
    Hospital hospital;

    int incorporados = 0;
    int rechazados = 0;

    bool cargado = hospital.cargarArchivo(
        "pacientes.txt", incorporados, rechazados
    );

    if (!cargado) {
        return 0;
    }

    cout << "Pacientes incorporados: " << incorporados << endl;
    cout << "Registros rechazados: " << rechazados << endl;

    int opcion = 0;
    string entrada = "";

    do {
        cout << "\n=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamentos" << endl;
        cout << "3. Buscar paciente" << endl;
        cout << "4. Salir" << endl;
        cout << "\nSeleccionar opcion: ";

        getline(cin, entrada);
        opcion = 0;
        convertirAEnteroNoNegativo(entrada, opcion);

        if (opcion == 1) {
            hospital.atenderSiguiente();
        }
        else if (opcion == 2) {
            hospital.mostrarDepartamentos();
            menuArboles(hospital);
        }
        else if (opcion == 3) {
            string dato = "";

            cout << "\n=== BUSCAR PACIENTE ===" << endl;
            cout << "Indique el ID o Nombre del paciente: ";
            getline(cin, dato);

            string servicio = "";
            string ruta = "";

            Paciente* paciente = hospital.buscarPaciente(
                dato, servicio, ruta
            );

            if (paciente == nullptr) {
                cout << "\nPaciente no encontrado." << endl;
            }
            else {
                mostrarPacienteEncontrado(paciente, servicio, ruta);
            }
        }
        else if (opcion == 4) {
            cout << "\nHasta luego." << endl;
        }
        else {
            cout << "\nOpcion no valida." << endl;
        }

    } while (opcion != 4);

    return 0;
}