#include "datatypes/DTVariableAleatoria.h"
#include <iostream>

DTVariableAleatoria::DTVariableAleatoria(std::string id, std::string descripcion) {
    this->id = id;
    this->descripcion = descripcion;
}

std::string DTVariableAleatoria::getId() const {
    return id;
}
std::string DTVariableAleatoria::getDescripcion() const {
    return descripcion;
}

std::ostream& operator<<(std::ostream& os, DTVariableAleatoria dt) {
    os << dt.getId() << std::endl << " := " << dt.getDescripcion();
    return os;
}