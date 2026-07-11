#include "datatypes/DTExperimento.h"
#include <iostream>

DTExperimento::DTExperimento(std::string nombre,std::string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

std::string DTExperimento::getNombre() const {
    return nombre;
}
std::string DTExperimento::getDescripcion() const {
    return descripcion;
}

std::ostream& operator<<(std::ostream& os, DTExperimento dt) {
    os << dt.getNombre() << std::endl << "--- " << dt.getDescripcion();
    return os;
}