BIN		:= serial parallel generate

CFLAGS		:= -std=c++14 -O3 -m64
LDFLAGS		:= -fopenmp

CXX		:= g++

HEADS		:=  generate_random.hpp
SRC		:=  generate_random.cpp



serial: serial.cpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ serial.cpp

parallel: parallel.cpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ parallel.cpp

generate: generate.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) generate.cpp

clean:
	rm $(BIN) *.o core*
