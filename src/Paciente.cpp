#include "Paciente.h"

Paciente::Paciente(string id,string nombre,int edad,double temperatura,int presionArterial,int dolor,string tipoDolor,int trauma,int sintomasNeurologicos,int requiereCirugia,int diasHospitalizacion) : Persona(nombre, edad) {
    this->id = id;
    this->temperatura = temperatura;
    this->presionArterial = presionArterial;
    this->dolor = dolor;
    this->tipoDolor = tipoDolor;
    this->trauma = trauma;
    this->sintomasNeurologicos = sintomasNeurologicos;
    this->requiereCirugia = requiereCirugia;
    this->diasHospitalizacion = diasHospitalizacion;
}

Paciente::~Paciente() {
}

string Paciente::getId() {
    return this->id;
}

double Paciente::getTemperatura() {
    return this->temperatura;
}

int Paciente::getPresionArterial() {
    return this->presionArterial;
}

int Paciente::getDolor() {
    return this->dolor;
}

string Paciente::getTipoDolor() {
    return this->tipoDolor;
}

int Paciente::getTrauma() {
    return this->trauma;
}

int Paciente::getSintomasNeurologicos() {
    return this->sintomasNeurologicos;
}

int Paciente::getRequiereCirugia() {
    return this->requiereCirugia;
}

int Paciente::getDiasHospitalizacion() {
    return this->diasHospitalizacion;
}