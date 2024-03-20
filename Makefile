CXX=g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I.
EXEC=main
OBJECT=main.o
SRC=main.cpp

$(EXEC) : $(OBJECT)
	g++ $(OBJECT) -o $(EXEC)

$(OBJECT) : $(SRC) parameters.hpp
	g++ -c $(SRC) -o $(OBJECT)

clean:
	$(RM) *.o