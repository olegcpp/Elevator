CXX=clang++
CXXFLAGS=-g -I ./src -std=c++14 -Wall -pedantic
BIN=build/elevator
TEST_BIN=build/elevatorTest

SRC = $(wildcard src/*.cpp)
APP_SRC = $(SRC) main.cpp
APP_OBJ=$(APP_SRC:%.cpp=%.o)
TEST_SRC = $(SRC) $(wildcard test/*.cpp)
TEST_OBJ=$(TEST_SRC:%.cpp=%.o)

all: $(BIN) test
.PHONY: all

test: $(TEST_BIN)
	$(TEST_BIN)
.PHONY: test

$(TEST_BIN): $(TEST_OBJ)
	$(CXX) -o $(TEST_BIN) $^

$(BIN): $(APP_OBJ)
	$(CXX) -o $(BIN) $^

clean:
	rm -f src/*.o
	rm -f test/*.o
	rm *.o
	rm $(BIN)
	rm $(TEST_BIN)

print-%  : ; @echo $* = $($*)
