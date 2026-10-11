// Nombre: Joaquín Esteban Torres Flores
// RUT: 21.547.370-8
// Usuario de GitHub: JoaquinTFdev1
// Carrera: Ingeniería Civil Industrial
// Paralelo: C1

#include <iostream>
#include <string>

#include "AVL.h"

using namespace std;

int main() {

    AVL arbol;

    arbol.insertar(new Paciente("030","Paciente 30",30,37.0,120,1,"otro",0,0,0,0));
    arbol.insertar(new Paciente("010","Paciente 10",25, 36.8,115, 2, "otro",0,0,0,0));
    arbol.insertar(new Paciente("020", "Paciente 20",28,37.1,118,3, "otro",0, 0, 0,0));
    arbol.insertar(new Paciente("040","Paciente 40",35,37.2,125,4,"otro",0,0,0,0));
    arbol.insertar(new Paciente("050","Paciente 50",40,37.3,130,5,"otro",0,0,0,0));

    cout << "Raiz del AVL: " << arbol.getRaiz()->getPaciente()->getId()<< endl;
    cout << "Altura total: " << arbol.getAltura() << endl;

    arbol.mostrarInorden();
    arbol.mostrarPreorden();
    arbol.mostrarPostorden();
    arbol.mostrarFactores();

    string ruta = "";

    Paciente* encontrado = arbol.buscarPorId("040",ruta);

    cout << "\nRuta de busqueda: " << ruta<< endl;

    if (encontrado != nullptr) {
        cout << "Paciente encontrado: " << encontrado->getId()<< " - " << encontrado->getNombre()<< endl;
    }

    else {
        cout << "Paciente no encontrado."<< endl;
    }

    return 0;
}