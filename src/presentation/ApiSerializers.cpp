#include "presentation/ApiSerializers.h"
#include <nlohmann/json.hpp>

using nlohmann::json;

void to_json(json& j, const DTExperimento& d) {
    j = json{{"nombre", d.getNombre()}, {"descripcion", d.getDescripcion()}};
}

void to_json(json& j, const DTEvento& d) {
    j = json{{"nombre", d.getNombre()}, {"probabilidad", d.getProbabilidad()}};
}

void to_json(json& j, const DTVariableAleatoria& d) {
    j = json{{"id", d.getId()}, {"descripcion", d.getDescripcion()}};
}
