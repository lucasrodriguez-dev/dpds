#ifndef DISTRIBUCIONFACTORY_H
#define DISTRIBUCIONFACTORY_H

#include "Distribucion.h"
#include "TipoDistribucion.h"
#include <string>

class DistribucionFactory {
    private:
        static DistribucionFactory& instancia;
        DistribucionFactory();
    public:
        static DistribucionFactory& getInstancia();
        Distribucion& crear(TipoDistribucion, std::set<float>);
};

#endif