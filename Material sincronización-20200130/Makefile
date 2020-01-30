BIN		:= serial parallel version_1 version_2 version_2 version_3 atomic_ex


CFLAGS		:= -std=c++14 #-O3 -m64
LDFLAGS		:= -pthread

CXX		:= g++

HEADS		:= generate_v3.hpp
SRC		:= generate_v3.cpp


serial: serial.cpp $(HEADS)
	$(CXX) $(CFLAGS) -o $@ $(SRC) serial.cpp

parallel: parallel.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) parallel.cpp

version_1: version_1.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) version_1.cpp

version_2: version_2.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) version_2.cpp

version_3: version_3.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) version_3.cpp

atomic_ex: atomic_ex.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) atomic_ex.cpp

clean:
	rm $(BIN) *.o core*
