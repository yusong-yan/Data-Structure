CXX=g++

CXXFLAGS= -std=c++11 -Wall -g

BINARIES=tests

tests: Tries.o Test.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f $(BINARIES) *.o 