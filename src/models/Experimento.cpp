#include "models/Experimento.h"
#include "algorithms/simulacion/SimulacionAlgorithms.h"

Experimento::Experimento(std::string nombre, std::string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}

DTExperimento Experimento::getDT() {
    return DTExperimento(nombre, descripcion);
}

void Experimento::asociarEventos(std::vector<DTEvento> dteventos) {
    for(auto dt: dteventos){
        eventos.insert({dt.getNombre(), Evento(dt)});
    }
}

DTEvento Experimento::simular() const {
    std::vector<float> probabilidades;
    std::vector<Evento> eventosIndexados;
    for(auto evento: eventos){
        probabilidades.push_back(evento.second.getProbabilidad());
        eventosIndexados.push_back(evento.second);
    }
    size_t indice = algorithms::simulacion::lineal::simular(probabilidades);
    return eventosIndexados[indice].getDT();
}

std::vector<DTSimulacionExperimento> Experimento::simular(int cantidadSimulaciones) const {
    std::map<DTEvento, int> ocurrencias;
    for(int i=1; i<= cantidadSimulaciones; i++){
        DTEvento dt = simular();
        ocurrencias[dt]++;
    }
    std::vector<DTSimulacionExperimento> retorno;
    for(auto [evento, cantidadApariciones]: ocurrencias){
        retorno.push_back(DTSimulacionExperimento(evento, cantidadApariciones, static_cast<float>(cantidadApariciones)/cantidadSimulaciones));
    }
    return retorno;
}

bool Experimento::existeVariableAleatoria(std::string id) const {
    return variablesAleatorias.find(id) != variablesAleatorias.end();
}

void Experimento::agregarVariableAleatoria(std::string id, std::string descripcion, DTDistribucion* dtdistribucion) {
    variablesAleatorias.insert({id, VariableAleatoria(id, descripcion, dtdistribucion)});
}

std::vector<DTVariableAleatoria> Experimento::listarVariablesAleatorias() const {
    std::vector<DTVariableAleatoria> retorno;
    for(auto va: variablesAleatorias){
        retorno.push_back(va.second.getDT());
    }
    return retorno;
}

float Experimento::simularVariableAleatoria(std::string id) const {
    return variablesAleatorias.at(id).simular();
}
float Experimento::consultarPropiedad(std::string id,PropiedadNumerica prop) const {
    return variablesAleatorias.at(id).consultarPropiedad(prop);
}
float Experimento::evaluarVariableAleatoria(std::string id, float x) const {
    return variablesAleatorias.at(id).evaluar(x);
}
float Experimento::evaluarDistribucionAcumulada(std::string id, float x) const {
    return variablesAleatorias.at(id).distribucionAcumulada(x);
}