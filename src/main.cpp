#include <iostream>

#include "AVL.h"

using namespace std;

int main() {

    AVL arbol;

    arbol.insertar(
        new Paciente(
            "020",
            "Paciente B",
            30,
            37.0,
            120,
            2,
            "otro",
            0,
            0,
            0,
            0
        )
    );

    arbol.insertar(
        new Paciente(
            "010",
            "Paciente A",
            25,
            36.8,
            115,
            1,
            "otro",
            0,
            0,
            0,
            0
        )
    );

    arbol.insertar(
        new Paciente(
            "030",
            "Paciente C",
            35,
            37.2,
            125,
            3,
            "otro",
            0,
            0,
            0,
            0
        )
    );

    cout
        << "Altura del arbol: "
        << arbol.getAltura()
        << endl;

    cout
        << "Factor de la raiz: "
        << arbol.getFactorBalance(
            arbol.getRaiz()
        )
        << endl;

    return 0;
}