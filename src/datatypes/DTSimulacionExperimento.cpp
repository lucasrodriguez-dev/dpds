#include "DTSimulacionExperimento.h"

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