#include "DTSimulacionExperimento.h"

DTSimulacionExperimento::DTSimulacionExperimento(DTEvento evento, int ocurrencias, float frecuenciaRelativa): evento(evento), ocurrencias(ocurrencias), frecuenciaRelativa(frecuenciaRelativa) {}
DTSimulacionExperimento::DTSimulacionExperimento(DTEvento evento, int ocurrencias): evento(evento), ocurrencias(ocurrencias) {}

DTEvento DTSimulacionExperimento::getEvento() const {
    return evento;
}
int DTSimulacionExperimento::getOcurrencias() const {
    return ocurrencias;
}
float DTSimulacionExperimento::getFrecuenciaRelativa() const {
    return frecuenciaRelativa;
}
void DTSimulacionExperimento::setFrecuenciaRelativa(float frecuenciaRelativa) {
    this->frecuenciaRelativa = frecuenciaRelativa;
}