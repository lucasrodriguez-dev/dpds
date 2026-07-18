#include <crow.h>
#include "factories/FabricaSistema.h"
#include "interfaces/IExperimento.h"
#include "datatypes/DTBer.h"
#include "datatypes/DTBin.h"
#include "datatypes/DTBinNeg.h"
#include "datatypes/DTHip.h"
#include "datatypes/DTPois.h"
#include "datatypes/DTExp.h"
#include "datatypes/DTNormal.h"
#include "datatypes/DTUni.h"

using std::exception;
using std::move;
using json_obj = crow::json::wvalue;
using json_list = crow::json::wvalue::list;
using std::string;
using std::vector;

/*
Toda ruta devuelve un
{
    status: "success" | "error",
    message: string,
    data: any
}
*/

crow::json::wvalue success(const std::string& message, crow::json::wvalue data = json_obj()) {
    crow::json::wvalue response;
    response["status"] = "success";
    response["message"] = message;
    response["data"] = move(data);
    return response;
}

crow::json::wvalue error(const std::string& message, crow::json::wvalue data = json_obj()) {
    crow::json::wvalue response;
    response["status"] = "error";
    response["message"] = message;
    response["data"] = move(data);
    return response;
}

DTDistribucion* crearDTDistribucion(const crow::json::rvalue& json)
{
    string tipo = json["tipo"].s();
    if (tipo == "bernoulli")
        return new DTBer(json["p"].d());
    if (tipo == "binomial")
        return new DTBin(json["n"].i(), json["p"].d());
    if (tipo == "binomial_negativa")
        return new DTBinNeg(json["r"].i(), json["p"].d());
    if (tipo == "hipergeometrica")
        return new DTHip(json["n"].i(), json["N"].i(), json["K"].i());
    if (tipo == "poisson")
        return new DTPois(json["lambda"].d());
    if (tipo == "exponencial")
        return new DTExp(json["lambda"].d());
    if (tipo == "normal")
        return new DTNormal(json["mu"].d(), json["sigma"].d());
    if (tipo == "uniforme")
        return new DTUni(json["a"].d(), json["b"].d());
    throw ParametroInvalidoException("Tipo de distribución inválido.");
}

int main() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([&]() {
        return success("Bienvenido a la API de Experimentos Aleatorios");
    });

    CROW_ROUTE(app, "/experimentos/new").methods(crow::HTTPMethod::POST)([&](const crow::request& req) {
        try {
            auto body = crow::json::load(req.body);
            if (!body)
                return error("JSON inválido");
            controlador->altaExperimento(body["nombre"].s(), body["descripcion"].s());
            return success("Experimento creado");
        } catch (const exception& e) {
            return error("Error al crear experimento: " + string(e.what()));
        }
    });

    CROW_ROUTE(app, "/experimentos")([&]() {
        try {
            auto experimentos = controlador->listarExperimentos();
            crow::json::wvalue response;
            json_list data;
            int i = 0;
            for (const auto& exp : experimentos) {
                data[i]["nombre"] = exp.getNombre();
                data[i]["descripcion"] = exp.getDescripcion();
                i++;
            }
            return success("Experimentos listados correctamente", data);
        } catch (const exception& e) {
            return error("Error al listar experimentos: " + string(e.what()), json_list());
        }
    });

    CROW_ROUTE(app, "/experimentos/<string>/eventos").methods(crow::HTTPMethod::POST)([&](const crow::request& req, const std::string& experimento) {
        try {
            auto body = crow::json::load(req.body);
            if (!body)
                return error("JSON inválido");
            vector<DTEvento> eventos;
            for (const auto& evento : body["eventos"]) {
                eventos.emplace_back(evento["nombre"].s(), static_cast<float>(evento["probabilidad"].d()));
            }
            controlador->asociarEventos(experimento, eventos);
            return success("Eventos asociados correctamente");
        } catch (const exception& e) {
            return error("Error al asociar eventos: " + string(e.what()), json_list());
        }
    });

    CROW_ROUTE(app, "/experimentos/<string>/simular")([&](const crow::request& req, const std::string& experimento) {
        try {
            int cantidad = 1;
            if (const char* cantidad_str = req.url_params.get("cantidad"))
                cantidad = std::stoi(cantidad_str);
            if(cantidad == 1){
                auto simulacion = controlador->simularExperimento(experimento);
                json_obj data;
                data["nombre"] = simulacion.getNombre();
                data["probabilidad"] = simulacion.getProbabilidad();
                return success("Simulación realizada correctamente", data);
            }
            auto simulaciones = controlador->simularExperimento(experimento, cantidad);
            json_list data;
            int i = 0;
            for (const auto& sim : simulaciones) {
                data[i]["evento"] = sim.getEvento().getNombre();
                data[i]["ocurrencias"] = sim.getOcurrencias();
                data[i]["frecuenciaRelativa"] = sim.getFrecuenciaRelativa();
                i++;
            }
            return success("Simulación realizada correctamente", data);
        } catch (const exception& e) {
            return error("Error al simular experimento: " + string(e.what()), json_obj());
        }
    });

    CROW_ROUTE(app, "/experimentos/<string>/variables/new").methods(crow::HTTPMethod::POST)([&](const crow::request& req, const std::string& experimento) {
        try {
            auto body = crow::json::load(req.body);
            if (!body)
                return error("JSON inválido");
            DTDistribucion* dt = crearDTDistribucion(body["distribucion"]);
            controlador->altaVariableAleatoria(experimento, body["id"].s(), body["descripcion"].s(), dt);
            return success("Variable aleatoria creada correctamente");
        } catch (const exception& e) {
            return error("Error al crear variable aleatoria: " + string(e.what()));
        }
    });

    CROW_ROUTE(app, "/experimentos/<string>/variables")([&](const std::string& experimento) {
        try {
            auto variables = controlador->listarVariablesAleatorias(experimento);
            json_list data;
            int i = 0;
            for (const auto& var : variables) {
                data[i]["id"] = var.getId();
                data[i]["descripcion"] = var.getDescripcion();
                i++;
            }
            return success("Variables aleatorias listadas correctamente", data);
        } catch (const exception& e) {
            return error("Error al listar variables aleatorias: " + string(e.what()), json_list());
        }
    });

    CROW_ROUTE(app, "/experimentos/<string>/variables/<string>/simular")([&](const std::string& experimento, const std::string& variable) {
        try {
            float resultado = controlador->simularVariableAleatoria(experimento, variable);
            json_obj data;
            data["resultado"] = resultado;
            return success("Simulación de variable aleatoria realizada correctamente", data);
        } catch (const exception& e) {
            return error("Error al simular variable aleatoria: " + string(e.what()), json_obj());
        }
    });

    CROW_ROUTE(app, "/experimentos/<string>/variables/<string>/propiedad")([&](const crow::request& req, const std::string& experimento, const std::string& variable) {
        try {
            if (const char* propiedad_str = req.url_params.get("propiedad")) {
                PropiedadNumerica propiedad;
                string propiedad_s = propiedad_str;
                if (propiedad_s == "esperanza")
                    propiedad = PropiedadNumerica::esperanza;
                else if (propiedad_s == "varianza")
                    propiedad = PropiedadNumerica::varianza;
                else if (propiedad_s == "desviacion_estandar")
                    propiedad = PropiedadNumerica::desvio;
                else
                    return error("Propiedad inválida");
                float resultado = controlador->consultarPropiedad(experimento, variable, propiedad);
                json_obj data;
                data["resultado"] = resultado;
                return success("Propiedad de variable aleatoria consultada correctamente", data);
            } else {
                return error("Falta parámetro 'propiedad'");
            }
        } catch (const exception& e) {
            return error("Error al consultar propiedad de variable aleatoria: " + string(e.what()), json_obj());
        }
    });

    CROW_ROUTE(app, "/experimentos/<string>/variables/<string>/evaluar")([&](const crow::request& req, const std::string& experimento, const std::string& variable) {
        try {
            if (const char* valor_str = req.url_params.get("valor")) {
                float valor = std::stof(valor_str);
                float resultado = controlador->evaluarVariableAleatoria(experimento, variable, valor);
                json_obj data;
                data["resultado"] = resultado;
                return success("Evaluación de variable aleatoria realizada correctamente", data);
            } else {
                return error("Falta parámetro 'valor'");
            }
        } catch (const exception& e) {
            return error("Error al evaluar variable aleatoria: " + string(e.what()), json_obj());
        }
    });

    CROW_ROUTE(app, "/experimentos/<string>/variables/<string>/evaluar_distribucion_acumulada")([&](const crow::request& req, const std::string& experimento, const std::string& variable) {
        try {
            if (const char* valor_str = req.url_params.get("valor")) {
                float valor = std::stof(valor_str);
                float resultado = controlador->evaluarFuncionDistribucionAcumulada(experimento, variable, valor);
                json_obj data;
                data["resultado"] = resultado;
                return success("Evaluación de función de distribución acumulada realizada correctamente", data);
            } else {
                return error("Falta parámetro 'valor'");
            }
        } catch (const exception& e) {
            return error("Error al evaluar función de distribución acumulada: " + string(e.what()), json_obj());
        }
    });

    app.port(8080).multithreaded().run();
}