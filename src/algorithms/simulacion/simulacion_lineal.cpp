#include "simulacion_lineal.h"
#include "aleatorio_uniforme.h"

using std::vector;
using algorithms::simulacion::aleatorio::uniforme::generar;

namespace algorithms::simulacion::lineal {
    size_t simular(vector<float> probabilidades) {
        float u = generar(0, 1);
        float acumulada = 0;
        size_t size = probabilidades.size();
        for(size_t i=0; i<size; i++){
            acumulada += probabilidades[i];
            if(u < acumulada){
                return i;
            }
        }
        //como u pertenece a [0,1] y la suma de probabilidades es 1, esto nunca debería suceder. Pero por la representación de punto flotante, podría suceder.
        return size-1;
    }
}