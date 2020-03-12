BIN		:= serial parallel generate BubbleSort

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

BubbleSort: BubbleSort.cpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ BubbleSort.cpp

clean:
	rm $(BIN) *.o core*
