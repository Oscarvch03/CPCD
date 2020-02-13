BIN		:=  serial parallel


CFLAGS		:= -std=c++14 #-O3 -m64
LDFLAGS		:= -pthread

CXX		:= g++

HEADS		:=
SRC		:=



serial: serial.cpp
	$(CXX) $(CFLAGS) -o $@ serial.cpp

parallel: parallel.cpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ parallel.cpp

clean:
	rm $(BIN) *.o core*
