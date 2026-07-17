#include <crow.h>
#include "factories/FabricaSistema.h"
#include "interfaces/IExperimento.h"

using std::exception;

/*
Toda ruta devuelve un
{
    status: "success" | "error",
    message: string,
    data: any
}
*/

int main() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();

    crow::SimpleApp app;

    using json_null = crow::json::wvalue;
    using json_emptylist = crow::json::wvalue::list;

    CROW_ROUTE(app, "/experimentos")([&]() {
        try {
            auto experimentos = controlador->listarExperimentos();
            crow::json::wvalue response;
            response["data"] = json_emptylist();
            int i = 0;
            for (const auto& exp : experimentos) {
                response["data"][i]["nombre"] = exp.getNombre();
                response["data"][i]["descripcion"] = exp.getDescripcion();
                i++;
            }
            response["status"] = "success";
            response["message"] = "Experimentos listados correctamente";
            return response;
        } catch (const exception& e) {
            crow::json::wvalue response;
            response["status"] = "error";
            response["message"] = e.what();
            response["data"] = json_emptylist();
            return response;
        }
    });

    CROW_ROUTE(app, "/experimentos/<string>/variables")([&](const std::string& experimento) {
        try {
            auto variables = controlador->listarVariablesAleatorias(experimento);
            crow::json::wvalue response;
            response["data"] = json_emptylist();
            int i = 0;
            for (const auto& var : variables) {
                response["data"][i]["id"] = var.getId();
                response["data"][i]["descripcion"] = var.getDescripcion();
                i++;
            }
            response["status"] = "success";
            response["message"] = "Variables aleatorias listadas correctamente";
            return response;
        } catch (const exception& e) {
            crow::json::wvalue response;
            response["status"] = "error";
            response["message"] = e.what();
            response["data"] = json_emptylist();
            return response;
        }
    });

    app.port(8080).multithreaded().run();
}