#ifndef VACONTROLLER_H
#define VACONTROLLER_H

#include "Empirica.h"
#include "VAHandler.h"
#include "DistribucionFactory.h"
#include "TipoDistribucion.h"

class VAController {
    public:
        bool ingresarVA(std::string, std::string);
        void errorAlta();
        std::set<TipoDistribucion> listarDistribuciones();
        void seleccionarDistribucion(TipoDistribucion);
        void ingresarEmpirica(std::set<ValorProbabilidad>);
        void ingresarBernoulli(float);
        void ingresarBinomial(int, float);
        void ingresarHipergeometrica(int, int, int);
        void ingresarGeometrica(float);
        void ingresarBinomialNegativa(int, float);
        void ingresarPoisson(float);
};

#endif