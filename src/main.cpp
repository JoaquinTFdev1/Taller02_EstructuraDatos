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

    arbol.insertar(new Paciente("030", "Paciente 30", 30, 37.0, 120,1, "otro", 0, 0, 0, 0));
    arbol.insertar(new Paciente("020", "Paciente 20", 30, 37.0, 120,1, "otro", 0, 0, 0, 0));
    arbol.insertar(new Paciente("010", "Paciente 10", 30, 37.0, 120, 1, "otro", 0, 0, 0, 0));

    cout << "Raiz despues de rotar: " << arbol.getRaiz()->getPaciente()->getId() << endl;
    cout << "Hijo izquierdo: " << arbol.getRaiz()->getIzquierda()->getPaciente()->getId() << endl;
    cout << "Hijo derecho: " << arbol.getRaiz()->getDerecha()->getPaciente()->getId() << endl;
    cout << "Altura: " << arbol.getAltura() << endl;
    cout << "Factor de balance: " << arbol.getFactorBalance(arbol.getRaiz()) << endl;

    return 0;
}