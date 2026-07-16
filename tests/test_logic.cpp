#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

#include "factories/FabricaSistema.h"
#include "datatypes/DTEvento.h"
#include "datatypes/DTSimulacionExperimento.h"
#include "datatypes/DTBin.h"
#include "datatypes/DTUni.h"
#include "datatypes/DTVariableAleatoria.h"
#include "datatypes/DTDistribucion.h"
#include "datatypes/PropiedadNumerica.h"

int failures = 0;

void expect_true(bool cond, const std::string &name){
    if(!cond){
        std::cout << "FAIL: " << name << std::endl;
        failures++;
    } else {
        std::cout << "PASS: " << name << std::endl;
    }
}

void expect_throws(std::function<void()> fn, const std::string &name){
    try{
        fn();
        std::cout << "FAIL: " << name << " (no exception)" << std::endl;
        failures++;
    } catch(...){
        std::cout << "PASS: " << name << std::endl;
    }
}

int main(){
    using namespace std;

    IExperimento* ie = FabricaSistema::getInstancia()->getIExperimento();

    // 1. altaExperimento y listarExperimentos
    ie->altaExperimento("exp1", "descripcion 1");
    auto list1 = ie->listarExperimentos();
    expect_true(list1.size() == 1 && list1[0].getNombre() == "exp1", "altaExperimento + listarExperimentos");

    // 2. altaExperimento duplicado lanza
    expect_throws([&](){ ie->altaExperimento("exp1", "otra"); }, "altaExperimento duplicado lanza");

    // 3. asociarEventos con probabilidades inválidas -> lanza
    vector<DTEvento> badEvents = { DTEvento("a", 0.3f), DTEvento("b", 0.3f) };
    expect_throws([&](){ ie->asociarEventos("exp1", badEvents); }, "asociarEventos con probabilidades inválidas lanza");

    // 4. asociarEventos válido y simularExperimento
    vector<DTEvento> goodEvents = { DTEvento("a", 0.5f), DTEvento("b", 0.5f) };
    ie->asociarEventos("exp1", goodEvents);
    DTEvento e = ie->simularExperimento("exp1");
    bool name_ok = (e.getNombre() == "a" || e.getNombre() == "b");
    expect_true(name_ok, "simularExperimento devuelve un evento esperado");

    // 5. simularExperimento sobre experimento inexistente -> lanza
    expect_throws([&](){ ie->simularExperimento("noexiste"); }, "simularExperimento sobre inexistente lanza");

    // 6. simularExperimento con N simulaciones
    int N = 500;
    auto sims = ie->simularExperimento("exp1", N);
    unsigned int totalOcc = 0;
    for(auto &d: sims) totalOcc += d.getOcurrencias();
    expect_true(totalOcc == (unsigned)N, "simularExperimento(N) suma ocurrencias == N");

    // 7. altaVariableAleatoria en experimento inexistente -> lanza
    expect_throws([&](){ ie->altaVariableAleatoria("noexiste", "v1", "desc", new DTUni(0,1)); }, "altaVariableAleatoria en experimento inexistente lanza");

    // 8. altaVariableAleatoria con distribución nula -> lanza
    expect_throws([&](){ ie->altaVariableAleatoria("exp1", "vnull", "desc", nullptr); }, "altaVariableAleatoria con distribución nula lanza");

    // 9. altaVariableAleatoria flujo normal y listarVariablesAleatorias
    ie->altaVariableAleatoria("exp1", "v1", "var uniforme", new DTUni(0.0f, 1.0f));
    auto vars = ie->listarVariablesAleatorias("exp1");
    bool found_v1 = false;
    for(auto &d: vars) if(d.getId() == "v1") found_v1 = true;
    expect_true(found_v1, "altaVariableAleatoria + listarVariablesAleatorias contiene v1");

    // 10. simularVariableAleatoria devuelve valor dentro del soporte
    float sampled = ie->simularVariableAleatoria("exp1", "v1");
    expect_true(sampled >= 0.0f && sampled <= 1.0f, "simularVariableAleatoria valor en [0,1]");

    // 11. consultarPropiedad (esperanza y varianza) para uniforme
    float esp = ie->consultarPropiedad("exp1", "v1", PropiedadNumerica::esperanza);
    float var = ie->consultarPropiedad("exp1", "v1", PropiedadNumerica::varianza);
    expect_true(abs(esp - 0.5f) < 1e-6f, "consultarPropiedad esperanza correcta (uniforme)");
    expect_true(abs(var - ((1.0f-0.0f)*(1.0f-0.0f)/12.0f)) < 1e-6f, "consultarPropiedad varianza correcta (uniforme)");

    // 12. evaluarVariableAleatoria y evaluarFuncionDistribucionAcumulada
    float pdf_at_middle = ie->evaluarVariableAleatoria("exp1", "v1", 0.5f);
    float cdf_below = ie->evaluarFuncionDistribucionAcumulada("exp1", "v1", -1.0f);
    float cdf_above = ie->evaluarFuncionDistribucionAcumulada("exp1", "v1", 2.0f);
    expect_true(abs(pdf_at_middle - 1.0f) < 1e-6f, "evaluarVariableAleatoria en (a,b) devuelve densidad correcta para uniforme");
    expect_true(abs(cdf_below - 0.0f) < 1e-6f && abs(cdf_above - 1.0f) < 1e-6f, "evaluarFuncionDistribucionAcumulada en extremos devuelve 0 y 1");

    // 13. simularVariableAleatoria para variable inexistente -> lanza
    expect_throws([&](){ ie->simularVariableAleatoria("exp1", "noexiste"); }, "simularVariableAleatoria variable inexistente lanza");

    // 14. consultarPropiedad variable inexistente lanza
    expect_throws([&](){ ie->consultarPropiedad("exp1", "noexiste", PropiedadNumerica::esperanza); }, "consultarPropiedad variable inexistente lanza");

    // limpiar
    delete ie;
    FabricaSistema::liberarMemoria();

    if(failures == 0){
        std::cout << "\nALL TESTS PASSED" << std::endl;
        return 0;
    } else {
        std::cout << "\nFAILURES: " << failures << std::endl;
        return 1;
    }
}
