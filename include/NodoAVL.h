#pragma once
#include "Paciente.h"

class NodoAVL {

private:
    Paciente* paciente;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

public:
    NodoAVL(Paciente* paciente);
    ~NodoAVL();

    Paciente* getPaciente();
    NodoAVL* getIzquierda();
    NodoAVL* getDerecha();

    int getAltura();
    void setPaciente(Paciente* paciente);
    void setIzquierda(NodoAVL* nodo);
    void setDerecha(NodoAVL* nodo);
    void setAltura(int altura);

};

