// Nombre: Joaquín Esteban Torres Flores
// RUT: 21.547.370-8
// Usuario de GitHub: JoaquinTFdev1
// Carrera: Ingeniería Civil Industrial
// Paralelo: C1

#include <iostream>
#include "ColaPacientes.h"

using namespace std;

int main() {
    ColaPacientes cola;

    cola.push(new Paciente("001", "Juan Perez", 25, 37.0, 120,3, "otro", 0, 0, 0, 0));

    cola.push(new Paciente("002", "Ana Torres", 12, 36.8, 110,2, "cabeza", 0, 0, 0, 0));

    cola.push(new Paciente("003", "Luis Diaz", 31, 36.9, 125,5, "extremidad", 1, 0, 0, 0));

    cola.mostrar();

    cout << "\nOrden de salida:" << endl;

    while (!cola.isEmpty()) {
        Paciente* paciente = cola.pop();

        cout << paciente->getId() << " - " << paciente->getNombre() << endl;

        delete paciente;
    }

    return 0;
}