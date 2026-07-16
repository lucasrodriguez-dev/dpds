#include "presentation/ApiServer.h"
#include "presentation/ApiSerializers.h"
#include "factories/FabricaSistema.h"
#include <nlohmann/json.hpp>

// Crow single-header include - user must have installed Crow appropriately.
#include <crow_all.h>

using json = nlohmann::json;

ApiServer::ApiServer() {
    sistema = FabricaSistema::getInstancia()->getIExperimento();
}

ApiServer::~ApiServer() {}

void ApiServer::setupRoutes() {
    crow::SimpleApp& app = *new crow::SimpleApp();

    CROW_ROUTE(app, "/experimentos").methods(crow::HTTPMethod::GET)([this]() {
        auto lista = sistema->listarExperimentos();
        json j = json::array();
        for (const auto& e : lista) j.push_back(e);
        crow::response res(j.dump());
        res.set_header("Content-Type", "application/json");
        return res;
    });

    CROW_ROUTE(app, "/experimentos").methods(crow::HTTPMethod::POST)([this](const crow::request& req) {
        try {
            auto j = json::parse(req.body);
            std::string nombre = j.value("nombre", "");
            std::string descripcion = j.value("descripcion", "");
            if (nombre.empty()) {
                json err = { {"error", "'nombre' es requerido"} };
                crow::response r(err.dump()); r.code = 400; r.set_header("Content-Type","application/json");
                return r;
            }
            sistema->altaExperimento(nombre, descripcion);
            json ok = { {"status","created"}, {"nombre", nombre} };
            crow::response r(ok.dump()); r.code = 201; r.set_header("Content-Type","application/json");
            return r;
        } catch (const std::exception& ex) {
            json err = { {"error", ex.what()} };
            crow::response r(err.dump()); r.code = 400; r.set_header("Content-Type","application/json");
            return r;
        } catch (...) {
            json err = { {"error", "invalid payload"} };
            crow::response r(err.dump()); r.code = 400; r.set_header("Content-Type","application/json");
            return r;
        }
    });

    // More routes to implement: eventos, variables aleatorias, simulaciones...

    // Start app in run() so here we only configured routes on the local app instance.
}

void ApiServer::run(int port) {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")( [](){ return "DPDS API"; });

    CROW_ROUTE(app, "/experimentos").methods(crow::HTTPMethod::GET)([this]() {
        auto lista = sistema->listarExperimentos();
        json j = json::array();
        for (const auto& e : lista) j.push_back(e);
        crow::response res(j.dump()); res.set_header("Content-Type", "application/json");
        return res;
    });

    CROW_ROUTE(app, "/experimentos").methods(crow::HTTPMethod::POST)([this](const crow::request& req) {
        try {
            auto j = json::parse(req.body);
            std::string nombre = j.value("nombre", "");
            std::string descripcion = j.value("descripcion", "");
            if (nombre.empty()) {
                json err = { {"error", "'nombre' es requerido"} };
                crow::response r(err.dump()); r.code = 400; r.set_header("Content-Type","application/json");
                return r;
            }
            sistema->altaExperimento(nombre, descripcion);
            json ok = { {"status","created"}, {"nombre", nombre} };
            crow::response r(ok.dump()); r.code = 201; r.set_header("Content-Type","application/json");
            return r;
        } catch (const std::exception& ex) {
            json err = { {"error", ex.what()} };
            crow::response r(err.dump()); r.code = 400; r.set_header("Content-Type","application/json");
            return r;
        } catch (...) {
            json err = { {"error", "invalid payload"} };
            crow::response r(err.dump()); r.code = 400; r.set_header("Content-Type","application/json");
            return r;
        }
    });

    // Skeleton endpoints (return 501 Not Implemented)
    CROW_ROUTE(app, "/experimentos/<string>/eventos").methods(crow::HTTPMethod::POST)([](const crow::request&, const std::string&) {
        crow::response r; r.code = 501; r.body = "Not implemented"; r.set_header("Content-Type","text/plain"); return r;
    });

    CROW_ROUTE(app, "/experimentos/<string>/simular").methods(crow::HTTPMethod::GET)([](const crow::request&, const std::string&) {
        crow::response r; r.code = 501; r.body = "Not implemented"; r.set_header("Content-Type","text/plain"); return r;
    });

    CROW_ROUTE(app, "/experimentos/<string>/variables").methods(crow::HTTPMethod::GET)([](const crow::request&, const std::string&){
        crow::response r; r.code = 501; r.body = "Not implemented"; r.set_header("Content-Type","text/plain"); return r;
    });

    app.port(port).multithreaded().run();
}
