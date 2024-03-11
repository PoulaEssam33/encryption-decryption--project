CXX := g++
CXXFLAGS := -Wall -Werror -Wextra -std=c++23 -pedantic -O3

TARGET := main

SRC := src/main.cpp src/utils.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)