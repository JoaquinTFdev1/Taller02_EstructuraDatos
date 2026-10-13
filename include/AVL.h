#pragma once

#include "NodoAVL.h"

#include <string>

using namespace std;

class AVL {

private:
    NodoAVL* raiz;
    NodoAVL* insertar(NodoAVL* nodo,Paciente* paciente,bool& insertado);
    NodoAVL* eliminar(NodoAVL* nodo, string id, bool& eliminado);
    NodoAVL* nodoMenor(NodoAVL* nodo);

    int altura(NodoAVL* nodo);
    int maximo(int a, int b);
    void actualizarAltura(NodoAVL* nodo);

    NodoAVL* rotacionDerecha(NodoAVL* nodo);
    NodoAVL* rotacionIzquierda(NodoAVL* nodo);

    Paciente* buscarPorId(NodoAVL* nodo, string id, string& ruta);
    Paciente* buscarPorNombre(NodoAVL* nodo, string nombre);

    void mostrarInorden(NodoAVL* nodo);
    void mostrarPreorden(NodoAVL* nodo);
    void mostrarPostorden(NodoAVL* nodo);
    void mostrarFactores(NodoAVL* nodo);
    void mostrarPacientes(NodoAVL* nodo);
    void liberar(NodoAVL* nodo);

public:
    AVL();
    ~AVL();
    NodoAVL* getRaiz();
    bool insertar(Paciente* paciente);
    bool eliminar(string id);
    bool isEmpty();
    int getAltura();
    int getFactorBalance(NodoAVL* nodo);

    Paciente* buscarPorId(string id, string& ruta);
    Paciente* buscarPorNombre(string nombre);

    void mostrarInorden();
    void mostrarPreorden();
    void mostrarPostorden();
    void mostrarFactores();
    void mostrarPacientes();
};