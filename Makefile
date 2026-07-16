CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Iinclude/vendor -g -O0

SRC = $(shell find src -name "*.cpp")

# Source files for tests (exclude files that define main)
SRCTEST = $(filter-out src/presentation/main_api.cpp src/presentation/ApiServer.cpp, $(SRC))

TARGET = main

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) main.cpp $(SRC) -o $(TARGET)

api_server:
	$(CXX) $(CXXFLAGS) src/presentation/main_api.cpp $(SRC) -o api_server

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind -s --leak-check=full ./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -f api_server

test: 
	$(CXX) $(CXXFLAGS) tests/test_logic.cpp $(SRCTEST) -o test_runner

run_test: test
	./test_runner