CC=g++
CXXFLAGS=-g -std=c++17 -pedantic
ODIR=.
BUILD=build

_OBJ=$(BUILD)/DFA2dot.o $(BUILD)/DatosDFA.o $(BUILD)/LectorDFA.o 
OBJ=$(patsubst %,%,$(_OBJ))

all:DFA2dot

$(BUILD)/DFA2dot.o: $(ODIR)/DFA2dot.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/LectorDFA.o: $(ODIR)/LectorDFA.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/DatosDFA.o: $(ODIR)/DatosDFA.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

DFA2dot: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -lm

.PHONY:clean

clean:
	rm -rf build/* DFA2dot

