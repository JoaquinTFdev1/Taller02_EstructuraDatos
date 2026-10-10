#pragma once

#include "NodoAVL.h"

class AVL {

private:
    NodoAVL* raiz;
    NodoAVL* insertar(NodoAVL* nodo,Paciente* paciente, bool& insertado);
    void liberar(NodoAVL* nodo);

public:
    AVL();
    ~AVL();
    NodoAVL* getRaiz();
    bool insertar(Paciente* paciente);
    bool isEmpty();
};