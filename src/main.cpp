// Nombre: Joaquín Esteban Torres Flores
// RUT: 21.547.370-8
// Usuario de GitHub: JoaquinTFdev1
// Carrera: Ingeniería Civil Industrial
// Paralelo: C1

#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
    AVL arbol;
    arbol.insertar(new Paciente("020", "Paciente B", 30, 37.0, 120,2, "otro", 0, 0, 0, 0));
    arbol.insertar(new Paciente("010", "Paciente A", 25, 36.8, 115,1, "otro", 0, 0, 0, 0));
    arbol.insertar(new Paciente("030", "Paciente C", 35, 37.2, 125,3, "otro", 0, 0, 0, 0));

    cout << "Raiz: " << arbol.getRaiz()->getPaciente()->getId() << endl;
    cout << "Izquierda: "<< arbol.getRaiz()->getIzquierda()->getPaciente()->getId() << endl;
    cout << "Derecha: " << arbol.getRaiz()->getDerecha()->getPaciente()->getId() << endl;

    return 0;
}