BIN := helloOMP


CFLAGS := -std=c++14
LDFLAGS := -fopenmp

CXX := g++

HEADS :=
SRC :=

helloOMP: helloOMP.cpp $(HEADS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) helloOMP.cpp

num_thr_in: num_thr_in.cpp $(HEADS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) num_thr_in.cpp

piSerial: piSerial.cpp $(HEADS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) piSerial.cpp

piParallel: piParallel.cpp $(HEADS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) piParallel.cpp
