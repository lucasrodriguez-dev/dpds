#include "datatypes/DTSimulacionExperimento.h"
#include <iostream>

DTSimulacionExperimento::DTSimulacionExperimento(DTEvento evento, unsigned int ocurrencias, float frecuenciaRelativa): evento(evento), ocurrencias(ocurrencias), frecuenciaRelativa(frecuenciaRelativa) {}
DTSimulacionExperimento::DTSimulacionExperimento(DTEvento evento, unsigned int ocurrencias): evento(evento), ocurrencias(ocurrencias) {}

DTEvento DTSimulacionExperimento::getEvento() const {
    return evento;
}
unsigned int DTSimulacionExperimento::getOcurrencias() const {
    return ocurrencias;
}
float DTSimulacionExperimento::getFrecuenciaRelativa() const {
    return frecuenciaRelativa;
}
void DTSimulacionExperimento::setFrecuenciaRelativa(float frecuenciaRelativa) {
    this->frecuenciaRelativa = frecuenciaRelativa;
}

std::ostream& operator<<(std::ostream& os, DTSimulacionExperimento dt) {
    os << "Evento: " << dt.getEvento() << ", Ocurrencias: " << dt.getOcurrencias() << ", Frecuencia: " << dt.getFrecuenciaRelativa();
    return os;
}