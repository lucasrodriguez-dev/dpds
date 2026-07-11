#include "datatypes/DTUni.h"

DTUni::DTUni(float a, float b) {
    if(a >= b){
        throw ParametroInvalidoException("Debe cumplirse a < b");
    }
    this->a = a;
    this->b = b;
}

float DTUni::getA() const {
    return a;
}
float DTUni::getB() const {
    return b;
}