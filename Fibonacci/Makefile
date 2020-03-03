BIN		:= fibonacci_serial fibonacci_parallel



CFLAGS		:= -std=c++14 -O3 -m64

LDFLAGS		:= -fopenmp

CXX		:= g++


HEADS		:=
SRC		:=


fibonacci_serial: fibonacci_serial.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) fibonacci_serial.cpp

fibonacci_parallel: fibonacci_parallel.cpp $(HEADS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) fibonacci_parallel.cpp

clean:
	rm $(BIN) *.o core*
