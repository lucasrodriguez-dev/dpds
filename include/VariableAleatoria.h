#ifndef VARIABLEALEATORIA_H
#define VARIABLEALEATORIA_H

#include "datatypes/DTDistribucion.h"
#include "datatypes/DTVariableAleatoria.h"
#include "datatypes/PropiedadNumerica.h"

class VariableAleatoria {
    private:
        std::string id;
        std::string descripcion;
    public:
        VariableAleatoria(std::string,std::string,DTDistribucion);
        DTVariableAleatoria getDT();
        float simular();
        float consultarPropiedad(PropiedadNumerica);
        float densidad(float);
        float distribucionAcumulada(float);
};

#endif