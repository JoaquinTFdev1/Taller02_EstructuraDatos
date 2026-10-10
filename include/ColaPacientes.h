#pragma once

#include "Paciente.h"
#include <string>

using namespace std;

class ColaPacientes {

private:

    class NodoCola {

    public:
        Paciente* paciente;
        NodoCola* next;

        NodoCola(Paciente* paciente) {

            this->paciente = paciente;
            this->next = nullptr;
        }
    };


    NodoCola* frente;
    NodoCola* final;

    int cantidad;


public:

    ColaPacientes();

    ~ColaPacientes();

    bool isEmpty();

    int getSize();

    void push(Paciente* paciente);

    Paciente* pop();

    Paciente* front();

    Paciente* buscarPorId(string id);

    void mostrar();
};