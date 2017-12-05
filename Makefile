CPPFLAGS = -std=c++11 -Wall -Werror -g -O0

BIN = build
SRC = $(shell find src/ -name *.cpp)
OBJ = $(SRC:%.cpp=build/%.o)

INCLUDE = -Isrc/Model -Isrc/Model/Chessman -Isrc/View

APP = main

all: $(APP)

$(APP): $(OBJ)
	g++ $(CPPFLAGS) $^ -o $(BIN)/$(APP)

build/%.o: %.cpp
	mkdir -p $(dir $@)
	g++ $(CPPFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(BIN)
