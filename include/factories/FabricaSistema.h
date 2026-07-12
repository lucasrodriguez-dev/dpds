#ifndef FABRICASISTEMA_H
#define FABRICASISTEMA_H

#include "controllers/ControladorExperimento.h"

class FabricaSistema {
private:
    static FabricaSistema* instancia;
    FabricaSistema();
public:
    static FabricaSistema* getInstancia();
    static void liberarMemoria();
    IExperimento* getIExperimento();
};

#endif