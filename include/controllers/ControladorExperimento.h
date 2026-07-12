#ifndef CONTROLADOREXPERIMENTO_H
#define CONTROLADOREXPERIMENTO_H

#include "interfaces/IExperimento.h"

class ControladorExperimento: public IExperimento {
    public:
        ControladorExperimento();
        void altaExperimento(std::string,std::string);
        std::vector<DTExperimento> listarExperimentos() const;
        void asociarEventos(std::string,std::vector<DTEvento>);
        DTEvento simularExperimento(std::string) const;
        std::vector<DTSimulacionExperimento> simularExperimento(std::string,int) const;
        void altaVariableAleatoria(std::string,std::string,std::string,DTDistribucion*);
        std::vector<DTVariableAleatoria> listarVariablesAleatorias(std::string);
        float simularVariableAleatoria(std::string,std::string);
        float consultarPropiedad(std::string,std::string,PropiedadNumerica);
        float evaluarVariableAleatoria(std::string,std::string,float);
        float evaluarFuncionDistribucionAcumulada(std::string,std::string,float);
        static void liberarMemoria();
};

#endif