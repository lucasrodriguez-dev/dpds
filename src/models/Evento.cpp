#include "Evento.h"
#include "ParametroInvalidoException.h"

Evento::Evento(DTEvento dt) {
    float p = dt.getProbabilidad();
    if(p < 0 || p > 1){
        throw ParametroInvalidoException("La probabilidad debe pertenecer al intervalo [0,1]");
    }
    this->nombre = dt.getNombre();
    this->probabilidad = p;
}