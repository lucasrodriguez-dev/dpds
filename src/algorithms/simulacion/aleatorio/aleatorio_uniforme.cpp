#include "algorithms/simulacion/aleatorio/aleatorio_uniforme.h"
#include <random>

namespace algorithms::simulacion::aleatorio::uniforme {
    float generar(float a, float b){
        //construimos un generador pseudoaleatorio
        static std::mt19937 gen = std::mt19937(std::random_device{}());
        //construimos una distribución uniforme entre a y b
        std::uniform_real_distribution<float> dist =  std::uniform_real_distribution<float>(a, b);
        //le pedimos a la distribución que use ese generador para producir un número
        return dist(gen);
    }
}