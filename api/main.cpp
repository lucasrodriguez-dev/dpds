#include <crow.h>
#include "factories/FabricaSistema.h"
#include "interfaces/IExperimento.h"

using std::exception;
using std::move;

/*
Toda ruta devuelve un
{
    status: "success" | "error",
    message: string,
    data: any
}
*/

crow::json::wvalue success(const std::string& message, crow::json::wvalue data) {
    crow::json::wvalue response;
    response["status"] = "success";
    response["message"] = message;
    response["data"] = move(data);
    return response;
}

crow::json::wvalue error(const std::string& message, crow::json::wvalue data) {
    crow::json::wvalue response;
    response["status"] = "error";
    response["message"] = message;
    response["data"] = move(data);
    return response;
}

int main() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();

    crow::SimpleApp app;

    using json_null = crow::json::wvalue;
    using json_list = crow::json::wvalue::list;

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
            return error("Error al listar experimentos", json_list());
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
            return error("Error al listar variables aleatorias", json_list());
        }
    });

    app.port(8080).multithreaded().run();
}