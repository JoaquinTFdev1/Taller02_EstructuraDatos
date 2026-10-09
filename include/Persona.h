#pragma once

#include <string>

using namespace std;

class Persona {

protected:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad);

    virtual ~Persona();

    string getNombre();

    int getEdad();
};