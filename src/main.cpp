// Nombre: Joaquín Esteban Torres Flores
// RUT: 21.547.370-8
// Usuario de GitHub: JoaquinTFdev1
// Carrera: Ingeniería Civil Industrial
// Paralelo: C1

#include <iostream>

#include "ArbolDecision.h"
using namespace std;

int main() {

    ArbolDecision arbol;
    cout << "Raiz del arbol: "<< arbol.getRaiz()->getTexto() << endl;

    return 0;
}