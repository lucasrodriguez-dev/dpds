#ifndef APISERVER_H
#define APISERVER_H

#include <memory>
#include <string>
#include <nlohmann/json.hpp>
#include "interfaces/IExperimento.h"

namespace crow { class SimpleApp; }

class ApiServer {
public:
    ApiServer();
    ~ApiServer();
    void run(int port = 18080);

private:
    void setupRoutes();
    IExperimento* sistema;
    // crow::SimpleApp* app; // forward-declared in implementation
};

#endif
