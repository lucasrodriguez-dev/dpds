#include "DTEvento.h"

DTEvento::DTEvento(std::string nombre, float probabilidad) {
    this->nombre = nombre;
    this->probabilidad = probabilidad;
}

std::string DTEvento::getNombre() const {
    return nombre;
}
float DTEvento::getProbabilidad() const {
    return probabilidad;
}