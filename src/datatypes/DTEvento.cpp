#include "datatypes/DTEvento.h"
#include "exceptions/ParametroInvalidoException.h"
#include <iostream>

DTEvento::DTEvento(std::string nombre, float probabilidad) {
    if(probabilidad < 0 || probabilidad > 1){
        throw ParametroInvalidoException("La probabilidad debe pertenecer al intervalo [0,1]");
    }
    this->nombre = nombre;
    this->probabilidad = probabilidad;
}

std::string DTEvento::getNombre() const {
    return nombre;
}
float DTEvento::getProbabilidad() const {
    return probabilidad;
}

std::ostream& operator<<(std::ostream& os, DTEvento dt) {
    os << dt.getNombre() << " (p=" << dt.getProbabilidad() << ")";
    return os;
}