#ifndef EXPERIMENTO_H
#define EXPERIMENTO_H

#include "models/Evento.h"
#include "models/VariableAleatoria.h"
#include "datatypes/DTExperimento.h"
#include "datatypes/DTEvento.h"
#include "datatypes/DTSimulacionExperimento.h"
#include "datatypes/DTDistribucion.h"
#include "datatypes/DTVariableAleatoria.h"
#include "datatypes/PropiedadNumerica.h"

#include <map>
#include <vector>

class Experimento {
    private:
        std::string nombre;
        std::string descripcion;
        std::map<std::string, Evento> eventos;
        std::map<std::string, VariableAleatoria> variablesAleatorias;
    public:
        Experimento(std::string,std::string);
        DTExperimento getDT();
        void asociarEventos(std::vector<DTEvento>);
        DTEvento simular() const;
        std::vector<DTSimulacionExperimento> simular(int) const;
        bool existeVariableAleatoria(std::string) const;
        void agregarVariableAleatoria(std::string,std::string,DTDistribucion*);
        std::vector<DTVariableAleatoria> listarVariablesAleatorias() const;
        float simularVariableAleatoria(std::string) const;
        float consultarPropiedad(std::string,PropiedadNumerica) const;
        float evaluarVariableAleatoria(std::string,float) const;
        float evaluarDistribucionAcumulada(std::string,float) const;
};

#endif