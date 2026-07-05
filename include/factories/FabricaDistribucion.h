#ifndef FABRICADISTRIBUCION_H
#define FABRICADISTRIBUCION_H

#include "Distribucion.h"
#include "DTDistribucion.h"

class FabricaDistribucion {
    public:
        static Distribucion* crear(DTDistribucion&);
};

#endif