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
    string ids[5] = {"020","010","030","025","040"};

    for (int i = 0; i < 5; i++) {
        arbol.insertar(new Paciente(ids[i],"Paciente",30,37.0,120,1,"otro",0,0,0,0));
    }

    cout << "Antes de eliminar:" << endl;
    arbol.mostrarInorden();

    bool eliminado = arbol.eliminar("030");

    cout << "\nEliminado: " << eliminado << endl;

    cout << "\nDespues de eliminar:" << endl;
    arbol.mostrarInorden();

    arbol.mostrarFactores();

    return 0;
}

