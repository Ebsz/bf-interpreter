CXX=g++
CXXFLAGS=-std=c++11

SOURCES=src/*.cpp

BIN=bf

all:
	$(CXX) $(CXXFLAGS) -o $(BIN) $(SOURCES)	
