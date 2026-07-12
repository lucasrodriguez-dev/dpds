#include "presentation/EntradaAlgorithms.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <algorithm>

using std::cin, std::cout, std::numeric_limits, std::streamsize, std::string, std::stringstream;

namespace presentacion::algorithms::entrada {
    void descartarSaltoDeLinea() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    bool esVacio(string cadena){
    return std::all_of(cadena.begin(), cadena.end(),
        [](unsigned char c) {
            return std::isspace(c);
        });
    }
    string leerNoVacio(string mensaje) {
        string retorno;
        do {
            cout << mensaje; getline(cin, retorno);
        } while(esVacio(retorno));
        return retorno;
    }
    int leerEntero(string mensaje) {
        while (true) {
            string linea; cout << mensaje; getline(cin, linea);
            stringstream ss(linea);
            int numero;
            if (ss >> numero && ss.eof())
                return numero;
            cout << "Debe ingresar un número entero.";
        }
    }
    int leerEnteroPositivo(string mensaje) {
        while (true) {
            string linea; cout << mensaje; getline(cin, linea);
            stringstream ss(linea);
            int numero;
            if (ss >> numero && ss.eof() && numero > 0)
                return numero;
            cout << "Debe ingresar un número entero positivo.";
        }
    }
    float leerDecimal(string mensaje) {
        while (true) {
            string linea; cout << mensaje; getline(cin, linea); std::replace(linea.begin(), linea.end(), ',', '.');
            stringstream ss(linea);
            float numero;
            if (ss >> numero && ss.eof())
                return numero;
            cout << "Debe ingresar un número decimal.";
        }
    }
    float leerDecimalPositivo(string mensaje) {
        while (true) {
            string linea; cout << mensaje; getline(cin, linea); std::replace(linea.begin(), linea.end(), ',', '.');
            stringstream ss(linea);
            float numero;
            if (ss >> numero && ss.eof() && numero > 0)
                return numero;
            cout << "Debe ingresar un número decimal positivo.";
        }
    }
    float leerProbabilidad(string mensaje) {
        while(true) {
            float p = leerDecimal(mensaje);
            if(0 <= p && p <= 1)
                return p;
            cout << "La probabilidad debe estar entre 0 y 1.";
        }
    }
    bool leerBooleano(string mensaje) {
        while (true) {
            string linea; cout << mensaje; getline(cin, linea);
            stringstream ss(linea);
            int numero;
            if (ss >> numero && ss.eof())
                return numero == 1;
            cout << "Debe ingresar 1 o 0.";
        }
    }
}