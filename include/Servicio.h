#pragma once
#include "AVL.h"
#include <string>

using namespace std;
class Servicio {

private:
    string nombre;
    AVL arbol;

public:
    Servicio(string nombre);
    ~Servicio();
    string getNombre();
    AVL* getArbol();
    bool insertarPaciente(Paciente* paciente);

    Paciente* buscarPorId(string id,string& ruta);
    Paciente* buscarPorNombre(string nombre);

    void mostrarEstado();
    bool eliminarPaciente(string id);
    bool isEmpty();
};



