#include "ManejadorExperimento.h"

ManejadorExperimento* ManejadorExperimento::instancia = nullptr;

ManejadorExperimento::~ManejadorExperimento() {
    for(auto& [nombre, experimento]: experimentos){
        delete experimento;
    }
}

ManejadorExperimento* ManejadorExperimento::getInstancia() {
    if(instancia == nullptr){
        instancia = new ManejadorExperimento();
    }
    return instancia;
}

void ManejadorExperimento::altaExperimento(std::string nombre, std::string descripcion) {
    experimentos[nombre] = new Experimento(nombre, descripcion);
}

std::vector<DTExperimento> ManejadorExperimento::listarExperimentos() const {
    std::vector<DTExperimento> retorno;
    for(auto experimento: experimentos){
        retorno.push_back(experimento.second->getDT());
    }
    return retorno;
}

Experimento* ManejadorExperimento::getExperimento(std::string nombre) const {
    auto exp = experimentos.find(nombre);
    if(exp != experimentos.end()){
        return exp->second;
    }
    return nullptr;
}

void ManejadorExperimento::liberarMemoria() {
    delete instancia;
    instancia = nullptr;
}