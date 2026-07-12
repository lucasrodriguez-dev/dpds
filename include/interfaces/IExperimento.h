#ifndef IEXPERIMENTO_H
#define IEXPERIMENTO_H

#include <string>
#include <vector>
#include "datatypes/DTExperimento.h"
#include "datatypes/DTEvento.h"
#include "datatypes/DTSimulacionExperimento.h"
#include "datatypes/DTVariableAleatoria.h"
#include "datatypes/DTDistribucion.h"
#include "datatypes/PropiedadNumerica.h"
#include "exceptions/DominioException.h"

class IExperimento {
    public:
        virtual ~IExperimento() {}
        virtual void altaExperimento(std::string,std::string) = 0;
        virtual std::vector<DTExperimento> listarExperimentos() const = 0;
        virtual void asociarEventos(std::string,std::vector<DTEvento>) = 0;
        virtual DTEvento simularExperimento(std::string) const = 0;
        virtual std::vector<DTSimulacionExperimento> simularExperimento(std::string,int) const = 0;
        virtual void altaVariableAleatoria(std::string,std::string,std::string,DTDistribucion*) = 0;
        virtual std::vector<DTVariableAleatoria> listarVariablesAleatorias(std::string) = 0;
        virtual float simularVariableAleatoria(std::string,std::string) = 0;
        virtual float consultarPropiedad(std::string,std::string,PropiedadNumerica) = 0;
        virtual float evaluarVariableAleatoria(std::string,std::string,float) = 0;
        virtual float evaluarFuncionDistribucionAcumulada(std::string,std::string,float) = 0;
};

#endif