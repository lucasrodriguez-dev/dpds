#include "ControladorExperimento.h"

ControladorExperimento::ControladorExperimento() {
    this->experimentoSeleccionado = ControladorExperimento::EXPERIMENTO_NULO;
}

void ControladorExperimento::altaExperimento(std::string nombre, std::string descripcion) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    me->altaExperimento(nombre, descripcion);
}

std::vector<DTExperimento> ControladorExperimento::listarExperimentos() const {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    return me->listarExperimentos();
}

void ControladorExperimento::asociarEventos(std::string experimento, std::vector<DTEvento> eventos) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    Experimento* exp = me->getExperimento(experimento);
    bool ok = exp->asociarEventos(eventos);
    if(!ok){
        throw std::runtime_error("No se pudo asociar los eventos");
    }
}

DTEvento ControladorExperimento::simularExperimento(std::string experimento) const {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    Experimento* exp = me->getExperimento(experimento);
    return exp->simular();
}

std::vector<DTSimulacionExperimento> ControladorExperimento::simularExperimento(std::string experimento, int cantidadSimulaciones) const {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    Experimento* exp = me->getExperimento(experimento);
    return exp->simular(cantidadSimulaciones);
}

void ControladorExperimento::altaVariableAleatoria(std::string experimento, std::string id, std::string descripcion, DTDistribucion dtdistribucion) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    Experimento* exp = me->getExperimento(experimento);
    exp->agregarVariableAleatoria(id, descripcion, dtdistribucion);
}

std::vector<DTVariableAleatoria> ControladorExperimento::listarVariablesAleatorias(std::string experimento) {
    experimentoSeleccionado = experimento;
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    Experimento* exp = me->getExperimento(experimento);
    return exp->listarVariablesAleatorias();
}

float ControladorExperimento::simularVariableAleatoria(std::string variableAleatoria) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    Experimento* exp = me->getExperimento(experimentoSeleccionado);
    experimentoSeleccionado = ControladorExperimento::EXPERIMENTO_NULO;
    return exp->simularVariableAleatoria(variableAleatoria);
}

float ControladorExperimento::consultarPropiedad(std::string variableAleatoria, PropiedadNumerica propiedad) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    Experimento* exp = me->getExperimento(experimentoSeleccionado);
    experimentoSeleccionado = ControladorExperimento::EXPERIMENTO_NULO;
    return exp->consultarPropiedad(variableAleatoria, propiedad);
}

float ControladorExperimento::evaluarVariableAleatoria(std::string variableAleatoria, float x) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    Experimento* exp = me->getExperimento(experimentoSeleccionado);
    experimentoSeleccionado = ControladorExperimento::EXPERIMENTO_NULO;
    return exp->evaluarVariableAleatoria(variableAleatoria, x);
}

float ControladorExperimento::evaluarFuncionDistribucionAcumulada(std::string variableAleatoria, float x) {
    ManejadorExperimento* me = ManejadorExperimento::getInstancia();
    Experimento* exp = me->getExperimento(experimentoSeleccionado);
    experimentoSeleccionado = ControladorExperimento::EXPERIMENTO_NULO;
    return exp->evaluarDistribucionAcumulada(variableAleatoria, x);
}