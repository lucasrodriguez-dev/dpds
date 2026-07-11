#include "distributions/Normal.h"
#include "algorithms/normal/NormalAlgorithms.h"
#include "distributions/Uni.h"

constexpr float PI = 3.14159265358979323846f;

Normal::Normal(float mu, float sigmaSquare) {
    if(sigmaSquare <= 0){
        throw ParametroInvalidoException("sigma^2 debe ser mayor que 0");
    }
    this->mu = mu;
    this->sigmaSquare = sigmaSquare;
    this->sigma = std::sqrt(sigmaSquare);
}

float Normal::simular() const {
    //algoritmo de Box-Muller
    float u1 = Uni(0,1).simular();
    float u2 = Uni(0,1).simular();
    float Z = std::sqrt(-2*std::log(u1))*std::cos(2*PI*u2);
    return mu + sigma*Z;
}

float Normal::esperanza() const {
    return mu;
}
float Normal::varianza() const {
    return sigmaSquare;
}
float Normal::evaluar(float x) const {
    float z = x - mu;
    return std::exp(-z*z/(2*sigmaSquare))
          /std::sqrt(2*PI*sigmaSquare);
}
float Normal::distribucionAcumulada(float x) const {
    return algorithms::normal::phi((x-mu)/sigma);
}