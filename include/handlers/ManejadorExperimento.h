#ifndef MANEJADOREXPERIMENTO_H
#define MANEJADOREXPERIMENTO_H

#include "Experimento.h"
#include "datatypes/DTExperimento.h"

class ManejadorExperimento {
    private:
        static ManejadorExperimento* instancia;
        ManejadorExperimento();
        std::map<std::string,Experimento*> experimentos;
    public:
        ~ManejadorExperimento();
        static ManejadorExperimento* getInstancia();
        void altaExperimento(std::string,std::string);
        std::vector<DTExperimento> listarExperimentos() const;
        Experimento* getExperimento(std::string) const;
        static void liberarMemoria();
};

#endif