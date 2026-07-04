#include "DTVariableAleatoria.h"

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