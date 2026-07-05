#include "aleatorio_uniforme.h"
#include <random>

namespace algorithms::simulacion::aleatorio::uniforme {
    float generar(float a, float b){
        static std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<float> dist(a, b);
        return dist(gen);
    }
}