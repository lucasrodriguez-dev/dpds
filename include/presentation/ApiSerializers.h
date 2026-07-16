#ifndef APISERIALIZERS_H
#define APISERIALIZERS_H

#include <nlohmann/json.hpp>
#include "datatypes/DTExperimento.h"
#include "datatypes/DTEvento.h"
#include "datatypes/DTVariableAleatoria.h"

void to_json(nlohmann::json& j, const DTExperimento& d);
void to_json(nlohmann::json& j, const DTEvento& d);
void to_json(nlohmann::json& j, const DTVariableAleatoria& d);

#endif
