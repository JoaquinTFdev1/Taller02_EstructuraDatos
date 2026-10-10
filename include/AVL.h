#pragma once
#include "NodoAVL.h"

class AVL {

private:
    NodoAVL* raiz;
    NodoAVL* insertar(NodoAVL* nodo,Paciente* paciente,bool& insertado);
    int altura(NodoAVL* nodo);
    int maximo(int a, int b);
    void actualizarAltura(NodoAVL* nodo);
    void liberar(NodoAVL* nodo);

public:
    AVL();
    ~AVL();
    NodoAVL* getRaiz();
    bool insertar(Paciente* paciente);
    bool isEmpty();
    int getAltura();
    int getFactorBalance(NodoAVL* nodo);
};

