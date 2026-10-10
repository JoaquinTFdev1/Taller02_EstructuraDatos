#pragma once

#include "NodoDecision.h"
#include "Paciente.h"
#include <string>

using namespace std;
class ArbolDecision {

private:

    NodoDecision* raiz;
    void construirArbol();
    void liberar(NodoDecision* nodo);

    bool cumpleCondicion(int tipo,Paciente* paciente);
    void mostrarPreorden(NodoDecision* nodo);
    void mostrarInorden(NodoDecision* nodo);

    void mostrarPostorden(NodoDecision* nodo);
    void mostrarNodo(NodoDecision* nodo);

public:

    ArbolDecision();
    ~ArbolDecision();
    NodoDecision* getRaiz();
    string evaluarPaciente(Paciente* paciente, string& ruta);
    void mostrarPreorden();
    void mostrarInorden();
    void mostrarPostorden();
};