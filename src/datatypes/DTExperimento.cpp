#include "DTExperimento.h"

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