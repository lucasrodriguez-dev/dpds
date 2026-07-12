CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -g -O0

SRC = $(shell find src -name "*.cpp")

TARGET = main

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) main.cpp $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind -s --leak-check=full ./$(TARGET)

clean:
	rm -f $(TARGET)