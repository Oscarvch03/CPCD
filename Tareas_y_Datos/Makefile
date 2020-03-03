BIN		:= master single private firstprivate default



CFLAGS		:= -std=c++14 -O3 -m64

LDFLAGS		:= -fopenmp

CXX		:= g++


HEADS		:=
SRC		:=


master: master.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) master.cpp

single: single.cpp $(HEADS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) single.cpp

private: private.cpp $(HEADS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) private.cpp

firstprivate: firstprivate.cpp $(HEADS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) firstprivate.cpp

default: default.cpp $(HEADS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) default.cpp

clean:
	rm $(BIN) *.o core*
