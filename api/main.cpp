#include <crow.h>
#include "factories/FabricaSistema.h"
#include "interfaces/IExperimento.h"

int main() {
    IExperimento* controlador = FabricaSistema::getInstancia()->getIExperimento();

    crow::SimpleApp app;
    CROW_ROUTE(app, "/experimentos")([&]() {
        auto experimentos = controlador->listarExperimentos();
        crow::json::wvalue response;
        response["data"] = crow::json::wvalue::list();
        int i = 0;
        for (const auto& exp : experimentos) {
            response["data"][i]["nombre"] = exp.getNombre();
            response["data"][i]["descripcion"] = exp.getDescripcion();
            i++;
        }
        response["status"] = "success";
        return response;
    });

    app.port(8080).multithreaded().run();
}