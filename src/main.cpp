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
    NodoDecision* raiz = arbol.getRaiz();

    cout << "Decision inicial: " << raiz->getTexto() << endl;
    cout << "Ruta SI: " << raiz->getRamaSi()->getServicio() << endl;
    cout << "Ruta NO: " << raiz->getRamaNo()->getTexto() << endl;

    return 0;
}