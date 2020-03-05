BIN		:= serial

CFLAGS		:= -std=c++14 -O3 -m64
LDFLAGS		:= -fopenmp

CXX		:= g++

HEADS		:=
SRC		:=



serial: serial.cpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ serial.cpp

clean:                                           
	rm $(BIN) *.o core*
