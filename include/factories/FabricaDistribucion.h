#ifndef FABRICADISTRIBUCION_H
#define FABRICADISTRIBUCION_H

#include "distributions/Distribucion.h"
#include "datatypes/DTDistribucion.h"

class FabricaDistribucion {
    public:
        static Distribucion* crear(DTDistribucion&);
};

#endif