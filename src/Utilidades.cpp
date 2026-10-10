#include "Utilidades.h"
#include <climits>

string recortar(string texto) {
    if (texto.empty()) {
        return "";
    }

    int inicio = 0;
    int fin = texto.length() - 1;

    while (inicio <= fin && (texto[inicio] == ' ' || texto[inicio] == '\t' || texto[inicio] == '\r' || texto[inicio] == '\n')) {
        inicio++;
    }

    while (fin >= inicio && (texto[fin] == ' ' || texto[fin] == '\t' || texto[fin] == '\r' || texto[fin] == '\n')) {
        fin--;
    }

    if (inicio > fin) {
        return "";
    }

    string resultado = "";

    for (int i = inicio; i <= fin; i++) {
        resultado += texto[i];
    }

    return resultado;
}

string aMinusculasSimple(string texto) {
    int largo = texto.length();

    for (int i = 0; i < largo; i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = texto[i] + 32;
        }
    }

    return texto;
}

bool convertirAEnteroNoNegativo(string texto, int& valor) {
    texto = recortar(texto);

    if (texto.empty()) {
        return false;
    }

    int numero = 0;
    int largo = texto.length();

    for (int i = 0; i < largo; i++) {
        char caracter = texto[i];

        if (caracter < '0' || caracter > '9') {
            return false;
        }

        int digito = caracter - '0';

        if (numero > (INT_MAX - digito) / 10) {
            return false;
        }

        numero = numero * 10 + digito;
    }

    valor = numero;
    return true;
}

bool convertirARealNoNegativo(string texto, double& valor) {
    texto = recortar(texto);

    if (texto.empty()) {
        return false;
    }

    int largo = texto.length();

    if (texto[0] == '.' || texto[largo - 1] == '.') {
        return false;
    }

    double numero = 0;
    double divisor = 10;
    bool puntoEncontrado = false;

    for (int i = 0; i < largo; i++) {
        char caracter = texto[i];

        if (caracter == '.') {
            if (puntoEncontrado) {
                return false;
            }

            puntoEncontrado = true;
        } else {
            if (caracter < '0' || caracter > '9') {
                return false;
            }

            int digito = caracter - '0';

            if (!puntoEncontrado) {
                numero = numero * 10 + digito;
            } else {
                numero = numero + digito / divisor;
                divisor = divisor * 10;
            }
        }
    }

    valor = numero;
    return true;
}

bool tipoDolorValido(string tipoDolor) {
    tipoDolor = aMinusculasSimple(recortar(tipoDolor));

    return tipoDolor == "pecho" || tipoDolor == "cabeza" || tipoDolor == "abdomen" || tipoDolor == "extremidad" || tipoDolor == "otro";
}

bool textosIguales(string texto1, string texto2) {
    texto1 = aMinusculasSimple(recortar(texto1));
    texto2 = aMinusculasSimple(recortar(texto2));

    return texto1 == texto2;
}