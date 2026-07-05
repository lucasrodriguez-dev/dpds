#ifndef EVENTO_H
#define EVENTO_H

#include "datatypes/DTEvento.h"

class Evento {
    private:
        std::string nombre;
        float probabilidad;
    public:
        Evento(DTEvento);
        float getProbabilidad() const;
        DTEvento getDT() const;
};

#endif