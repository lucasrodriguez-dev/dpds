#include "factories/FabricaSistema.h"

FabricaSistema* FabricaSistema::instancia = nullptr;

FabricaSistema* FabricaSistema::getInstancia() {
    if (instancia == nullptr) {
        instancia = new FabricaSistema();
    }
    return instancia;
}
void FabricaSistema::liberarMemoria() {
    ControladorExperimento::liberarMemoria();
    delete instancia;
    instancia = nullptr;
}
IExperimento* FabricaSistema::getIExperimento() {
    return new ControladorExperimento();
}