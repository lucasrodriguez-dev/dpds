#ifndef ENTRADAALGORITHMS_H
#define ENTRADAALGORITHMS_H

#include <string>

namespace presentacion::algorithms::entrada {
    void descartarSaltoDeLinea();
    bool esVacio(std::string);
    std::string leerNoVacio(std::string);
    int leerEntero(std::string);
    unsigned int leerEnteroPositivo(std::string);
    float leerDecimal(std::string);
    float leerDecimalPositivo(std::string);
    float leerProbabilidad(std::string);
    bool leerBooleano(std::string);
}

#endif