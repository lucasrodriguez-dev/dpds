#include "presentation/ApiServer.h"
#include <iostream>

int main(int argc, char** argv) {
    int port = 18080;
    if (argc > 1) port = std::stoi(argv[1]);
    ApiServer server;
    std::cout << "Starting API server on port " << port << "\n";
    server.run(port);
    return 0;
}
