#include "controllers/ControladorExperimento.h"
#include "handlers/ManejadorExperimento.h"
#include "exceptions/ElementoDuplicadoException.h"
#include "exceptions/ProbabilidadesInvalidasException.h"
#include "exceptions/ElementoNoEncontradoException.h"

ControladorExperimento::ControladorExperimento() {}

void ControladorExperimento::altaExperimento(std::string nombre, std::string descripcion) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    if(me->existeExperimento(nombre)){
        throw ElementoDuplicadoException("Ya existe un experimento con el nombre '" + nombre + "'");
    }
    me->altaExperimento(nombre, descripcion);
}

std::vector<DTExperimento> ControladorExperimento::listarExperimentos() const {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    return me->listarExperimentos();
}

void ControladorExperimento::asociarEventos(std::string experimento, std::vector<DTEvento> eventos) {
    float suma = 0;
    for(auto evento: eventos){
        suma += evento.getProbabilidad();
    }
    if(suma != 1){
        throw ProbabilidadesInvalidasException("Las probabilidades de los eventos deben sumar 1");
    }
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    Experimento* exp = me->getExperimento(experimento);
    exp->asociarEventos(eventos);
}

DTEvento ControladorExperimento::simularExperimento(std::string experimento) const {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    if(!me->existeExperimento(experimento)){
        throw ElementoNoEncontradoException("No existe un experimento llamado '" + experimento + "'");
    }
    Experimento* exp = me->getExperimento(experimento);
    return exp->simular();
}

std::vector<DTSimulacionExperimento> ControladorExperimento::simularExperimento(std::string experimento, int cantidadSimulaciones) const {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    if(!me->existeExperimento(experimento)){
        throw ElementoNoEncontradoException("No existe un experimento llamado '" + experimento + "'");
    }
    Experimento* exp = me->getExperimento(experimento);
    return exp->simular(cantidadSimulaciones);
}

void ControladorExperimento::altaVariableAleatoria(std::string experimento, std::string id, std::string descripcion, DTDistribucion* dtdistribucion) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    if(!me->existeExperimento(experimento)){
        throw ElementoNoEncontradoException("No existe un experimento llamado '" + experimento + "'");
    }
    Experimento* exp = me->getExperimento(experimento);
    if(!exp->existeVariableAleatoria(id)){
        throw ElementoNoEncontradoException("No existe una variable aleatoria '" + id + "' en el experimento '" + experimento + "'");
    }
    exp->agregarVariableAleatoria(id, descripcion, dtdistribucion);
}

std::vector<DTVariableAleatoria> ControladorExperimento::listarVariablesAleatorias(std::string experimento) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    if(!me->existeExperimento(experimento)){
        throw ElementoNoEncontradoException("No existe un experimento llamado '" + experimento + "'");
    }
    return me->getExperimento(experimento)->listarVariablesAleatorias();
}

float ControladorExperimento::simularVariableAleatoria(std::string experimento, std::string variableAleatoria) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    if(!me->existeExperimento(experimento)){
        throw ElementoNoEncontradoException("No existe un experimento llamado '" + experimento + "'");
    }
    Experimento* exp = me->getExperimento(experimento);
    if(!exp->existeVariableAleatoria(variableAleatoria)){
        throw ElementoNoEncontradoException("No existe una variable aleatoria '" + variableAleatoria + "' en el experimento '" + experimento + "'");
    }
    return exp->simularVariableAleatoria(variableAleatoria);
}

float ControladorExperimento::consultarPropiedad(std::string experimento, std::string variableAleatoria, PropiedadNumerica propiedad) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    if(!me->existeExperimento(experimento)){
        throw ElementoNoEncontradoException("No existe un experimento llamado '" + experimento + "'");
    }
    Experimento* exp = me->getExperimento(experimento);
    if(!exp->existeVariableAleatoria(variableAleatoria)){
        throw ElementoNoEncontradoException("No existe una variable aleatoria '" + variableAleatoria + "' en el experimento '" + experimento + "'");
    }
    return exp->consultarPropiedad(variableAleatoria, propiedad);
}

float ControladorExperimento::evaluarVariableAleatoria(std::string experimento, std::string variableAleatoria, float x) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    if(!me->existeExperimento(experimento)){
        throw ElementoNoEncontradoException("No existe un experimento llamado '" + experimento + "'");
    }
    Experimento* exp = me->getExperimento(experimento);
    if(!exp->existeVariableAleatoria(variableAleatoria)){
        throw ElementoNoEncontradoException("No existe una variable aleatoria '" + variableAleatoria + "' en el experimento '" + experimento + "'");
    }
    return exp->evaluarVariableAleatoria(variableAleatoria, x);
}

float ControladorExperimento::evaluarFuncionDistribucionAcumulada(std::string experimento, std::string variableAleatoria, float x) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    if(!me->existeExperimento(experimento)){
        throw ElementoNoEncontradoException("No existe un experimento llamado '" + experimento + "'");
    }
    Experimento* exp = me->getExperimento(experimento);
    if(!exp->existeVariableAleatoria(variableAleatoria)){
        throw ElementoNoEncontradoException("No existe una variable aleatoria '" + variableAleatoria + "' en el experimento '" + experimento + "'");
    }
    return exp->evaluarDistribucionAcumulada(variableAleatoria, x);
}

void ControladorExperimento::liberarMemoria() {
    ManejadorExperimento::liberarMemoria();
}