#include "ArchivoPacientes.h"
#include "Utilidades.h"
#include <fstream>
#include <iostream>

using namespace std;

Paciente* crearPacienteDesdeLinea(string linea, string& error) {
    if (recortar(linea).empty()) {
        error = "la linea esta vacia";
        return nullptr;
    }

    string campos[11];
    string campoActual = "";
    int cantidadCampos = 0;
    int largo = linea.length();

    for (int i = 0; i < largo; i++) {
        if (linea[i] == ';') {
            if (cantidadCampos >= 10) {
                error = "la linea tiene mas de once campos";
                return nullptr;
            }

            campos[cantidadCampos] = recortar(campoActual);
            cantidadCampos++;
            campoActual = "";
        } else {
            campoActual += linea[i];
        }
    }

    campos[cantidadCampos] = recortar(campoActual);
    cantidadCampos++;

    if (cantidadCampos != 11) {
        error = "la linea debe tener once campos separados por punto y coma";
        return nullptr;
    }

    if (campos[0].empty()) {
        error = "el ID esta vacio";
        return nullptr;
    }

    if (campos[1].empty()) {
        error = "el nombre esta vacio";
        return nullptr;
    }

    int edad = 0;
    double temperatura = 0;
    int presionArterial = 0;
    int dolor = 0;
    int trauma = 0;
    int sintomasNeurologicos = 0;
    int requiereCirugia = 0;
    int diasHospitalizacion = 0;

    if (!convertirAEnteroNoNegativo(campos[2], edad) || edad > 120) {
        error = "la edad debe estar entre 0 y 120";
        return nullptr;
    }

    if (!convertirARealNoNegativo(campos[3], temperatura) || temperatura < 30 || temperatura > 45) {
        error = "la temperatura debe estar entre 30 y 45";
        return nullptr;
    }

    if (!convertirAEnteroNoNegativo(campos[4], presionArterial) || presionArterial < 40 || presionArterial > 250) {
        error = "la presion arterial debe estar entre 40 y 250";
        return nullptr;
    }

    if (!convertirAEnteroNoNegativo(campos[5], dolor) || dolor > 10) {
        error = "el dolor debe estar entre 0 y 10";
        return nullptr;
    }

    string tipoDolor = aMinusculasSimple(campos[6]);

    if (!tipoDolorValido(tipoDolor)) {
        error = "el tipo de dolor no es valido";
        return nullptr;
    }

    if (!convertirAEnteroNoNegativo(campos[7], trauma) || (trauma != 0 && trauma != 1)) {
        error = "Trauma debe ser 0 o 1";
        return nullptr;
    }

    if (!convertirAEnteroNoNegativo(campos[8], sintomasNeurologicos) || (sintomasNeurologicos != 0 && sintomasNeurologicos != 1)) {
        error = "SintomasNeurologicos debe ser 0 o 1";
        return nullptr;
    }

    if (!convertirAEnteroNoNegativo(campos[9], requiereCirugia) || (requiereCirugia != 0 && requiereCirugia != 1)) {
        error = "RequiereCirugia debe ser 0 o 1";
        return nullptr;
    }

    if (!convertirAEnteroNoNegativo(campos[10], diasHospitalizacion) || diasHospitalizacion > 365) {
        error = "DiasHospitalizacion debe estar entre 0 y 365";
        return nullptr;
    }

    return new Paciente(campos[0], campos[1], edad, temperatura, presionArterial, dolor, tipoDolor, trauma,sintomasNeurologicos, requiereCirugia, diasHospitalizacion);
}

bool cargarPacientesEnCola(string ruta, ColaPacientes& cola, int& incorporados, int& rechazados) {
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo '" << ruta << "'." << endl;
        return false;
    }

    incorporados = 0;
    rechazados = 0;
    int numeroLinea = 0;
    char caracter;

    while (true) {
        string linea = "";
        bool seLeyeronCaracteres = false;

        while (archivo.get(caracter)) {
            seLeyeronCaracteres = true;

            if (caracter == '\n') {
                break;
            }

            linea += caracter;
        }

        if (!seLeyeronCaracteres) {
            break;
        }

        numeroLinea++;
        string error = "";

        Paciente* paciente = crearPacienteDesdeLinea(linea, error);

        if (paciente == nullptr) {
            cout << "Linea " << numeroLinea << " rechazada: " << error << "." << endl;
            rechazados++;
            continue;
        }

        if (cola.buscarPorId(paciente->getId()) != nullptr) {
            cout << "Linea " << numeroLinea << " rechazada: ID duplicado "<< paciente->getId() << "." << endl;
            delete paciente;
            rechazados++;
            continue;
        }

        cola.push(paciente);
        incorporados++;
    }

    archivo.close();
    return true;
}