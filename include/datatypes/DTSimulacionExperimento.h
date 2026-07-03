#ifndef DTSIMULACIONEXPERIMENTO_H
#define DTSIMULACIONEXPERIMENTO_H

#include "DTEvento.h"

class DTSimulacionExperimento {
    private:
        DTEvento evento;
        int ocurrencias;
        float frecuenciaRelativa;
    public:
        DTSimulacionExperimento(DTEvento,int,float);
        DTEvento getEvento() const;
        int getOcurrencias() const;
        float getFrecuenciaRelativa() const;
};

#endif