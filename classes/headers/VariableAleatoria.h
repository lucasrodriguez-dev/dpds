#ifndef VARIABLEALEATORIA_H
#define VARIABLEALEATORIA_H

#include <string>
#include "Distribucion.h"

class VariableAleatoria {
    private:
        std::string id;
        std::string significado;
        Distribucion& distribucion;
    public:
        VariableAleatoria(std::string, std::string);
};

#endif