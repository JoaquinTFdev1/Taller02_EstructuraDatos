// Nombre: Joaquín Esteban Torres Flores
// RUT: 21.547.370-8
// Usuario de GitHub: JoaquinTFdev1
// Carrera: Ingeniería Civil Industrial
// Paralelo: C1

#include <iostream>
#include <string>

#include "ArchivoPacientes.h"

using namespace std;

int main() {

     string linea =
         "001;Juan Perez;25;37.0;120;3;otro;0;0;0;0";

     string error = "";


     Paciente* paciente = crearPacienteDesdeLinea(linea,error);


     if (paciente == nullptr) {
          cout << "Error: " << error<< endl;
          return 0;
     }

     cout << "Paciente interpretado correctamente"<< endl;

     cout << "ID: " << paciente->getId() << endl;

     cout << "Nombre: "<< paciente->getNombre()<< endl;

     cout << "Edad: "<< paciente->getEdad() << endl;

     cout << "Temperatura: " << paciente->getTemperatura()<< endl;

     cout << "Presion arterial: "<< paciente->getPresionArterial() << endl;

     cout << "Dolor: " << paciente->getDolor()<< endl;
     cout << "Tipo dolor: " << paciente->getTipoDolor()<< endl;
     cout << "Trauma: " << paciente->getTrauma() << endl;
     cout << "Sintomas neurologicos: " << paciente->getSintomasNeurologicos() << endl;
     cout << "Requiere cirugia: "<< paciente->getRequiereCirugia()<< endl;
     cout << "Dias hospitalizacion: " << paciente->getDiasHospitalizacion() << endl;


     delete paciente;


     return 0;
}