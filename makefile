CXX=g++
CXXFLAGS=-std=c++11

SOURCES=src/*.cpp

BIN=bfint

all:
	$(CXX) $(CXXFLAGS) -o $(BIN) $(SOURCES)	
