CXX=g++
CXXFLAGS=-std=c++11

SOURCES=main.cpp interpreter.cpp

BIN=bfint

all:
	$(CXX) $(CXXFLAGS) -o $(BIN) $(SOURCES)	
