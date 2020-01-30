BIN		:= test


CFLAGS		:= -std=c++14 #-O3 -m64
LDFLAGS		:= -pthread

CXX		:= g++

HEADS		:= lib.hpp
SRC		:= lib.cpp



test:	test.cpp $(HEADS)
	$(CXX) $(CFLAGS) -o $@ $(SRC) test.cpp


clean:
	rm $(BIN) *.o core*
