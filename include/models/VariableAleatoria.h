#ifndef VARIABLEALEATORIA_H
#define VARIABLEALEATORIA_H

#include "distributions/Distribucion.h"
#include "datatypes/DTDistribucion.h"
#include "datatypes/DTVariableAleatoria.h"
#include "datatypes/PropiedadNumerica.h"

class VariableAleatoria {
    private:
        std::string id;
        std::string descripcion;
        Distribucion* distribucion;
    public:
        VariableAleatoria(std::string,std::string,DTDistribucion);
        ~VariableAleatoria();
        DTVariableAleatoria getDT() const;
        float simular() const;
        float consultarPropiedad(PropiedadNumerica) const;
        float evaluar(float) const;
        float distribucionAcumulada(float) const;
};

#endif