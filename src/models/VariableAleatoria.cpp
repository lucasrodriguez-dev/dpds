#include "models/VariableAleatoria.h"
#include "factories/FabricaDistribucion.h"
#include "exceptions/DominioException.h"

VariableAleatoria::VariableAleatoria(std::string id, std::string descripcion, DTDistribucion dtdistribucion) {
    this->id = id;
    this->descripcion = descripcion;
    this->distribucion = FabricaDistribucion::crear(dtdistribucion);
}

VariableAleatoria::~VariableAleatoria() {
    delete distribucion;
}

DTVariableAleatoria VariableAleatoria::getDT() const {
    return DTVariableAleatoria(id, descripcion);
}
float VariableAleatoria::simular() const {
    return distribucion->simular();
}
float VariableAleatoria::consultarPropiedad(PropiedadNumerica prop) const {
    if(prop == PropiedadNumerica::esperanza){
        return distribucion->esperanza();
    }
    if(prop == PropiedadNumerica::varianza){
        return distribucion->varianza();
    }
    if(prop == PropiedadNumerica::desvio){
        return distribucion->desvio();
    } else {
        throw DominioException("Propiedad no contemplada");
    }
}
float VariableAleatoria::evaluar(float x) const {
    return distribucion->evaluar(x);
}
float VariableAleatoria::distribucionAcumulada(float x) const {
    return distribucion->distribucionAcumulada(x);
}