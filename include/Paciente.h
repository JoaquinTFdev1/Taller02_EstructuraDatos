#pragma once

#include "Persona.h"

#include <string>

using namespace std;

class Paciente : public Persona {

private:
    string id;
    double temperatura;
    int presionArterial;
    int dolor;
    string tipoDolor;
    int trauma;
    int sintomasNeurologicos;
    int requiereCirugia;
    int diasHospitalizacion;

public:
    Paciente(
        string id,
        string nombre,
        int edad,
        double temperatura,
        int presionArterial,
        int dolor,
        string tipoDolor,
        int trauma,
        int sintomasNeurologicos,
        int requiereCirugia,
        int diasHospitalizacion
    );

    ~Paciente();

    string getId();

    double getTemperatura();

    int getPresionArterial();

    int getDolor();

    string getTipoDolor();

    int getTrauma();

    int getSintomasNeurologicos();

    int getRequiereCirugia();

    int getDiasHospitalizacion();
};