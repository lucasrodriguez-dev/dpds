#ifndef CONTROLADOREXPERIMENTO_H
#define CONTROLADOREXPERIMENTO_H

#include "ManejadorExperimento.h"

class ControladorExperimento {
    private:
        static const std::string EXPERIMENTO_NULO;
        std::string experimentoSeleccionado;
    public:
        void altaExperimento(std::string,std::string);
        std::vector<DTExperimento> listarExperimentos() const;
        void asociarEventos(std::string,std::vector<DTEvento>);
        DTEvento simularExperimento(std::string) const;
        std::vector<DTSimulacionExperimento> simularExperimento(std::string,int) const;
        void altaVariableAleatoria(std::string,std::string,std::string,DTDistribucion);
        std::vector<DTVariableAleatoria> listarVariablesAleatorias() const;
        float simularVariableAleatoria(std::string) const;
        float consultarPropiedad(std::string,PropiedadNumerica) const; 
        float evaluarFuncionDensidad(std::string,float) const;       
        float evaluarFuncionDistribucionAcumulada(std::string,float) const;       
};

#endif