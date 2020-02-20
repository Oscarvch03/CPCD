BIN		:= serial omp_pi1 omp_pi2 omp_pi3 \
		   omp_pi4


CFLAGS		:= -std=c++14 #-O3 -m64
LDFLAGS		:= -fopenmp

CXX		:= g++

HEADS		:= 
SRC		:= 


serial: serial.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) serial.cpp

omp_pi1: omp_pi1.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) omp_pi1.cpp

omp_pi2: omp_pi2.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) omp_pi2.cpp

omp_pi3: omp_pi3.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) omp_pi3.cpp

omp_pi4: omp_pi4.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) omp_pi4.cpp


clean:
	rm $(BIN) *.o core*
