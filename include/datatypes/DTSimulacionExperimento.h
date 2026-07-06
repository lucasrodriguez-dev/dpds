#ifndef DTSIMULACIONEXPERIMENTO_H
#define DTSIMULACIONEXPERIMENTO_H

#include "DTEvento.h"

class DTSimulacionExperimento {
    private:
        DTEvento evento;
        unsigned int ocurrencias;
        float frecuenciaRelativa;
    public:
        DTSimulacionExperimento(DTEvento,unsigned int,float);
        DTSimulacionExperimento(DTEvento,unsigned int);
        DTEvento getEvento() const;
        unsigned int getOcurrencias() const;
        float getFrecuenciaRelativa() const;
        void setFrecuenciaRelativa(float);
};
std::ostream& operator<<(std::ostream&, DTSimulacionExperimento);

#endif