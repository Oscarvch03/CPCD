BIN		:= mandelbrot mandelbrot_omp mandelbrot_omp2



CFLAGS		:= -std=c++14 -O3 -m64

LDFLAGS		:= -fopenmp

CXX		:= g++


HEADS		:=
SRC		:=


mandelbrot: mandelbrot.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) mandelbrot.cpp

mandelbrot_omp: mandelbrot_omp.cpp $(HEADS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) mandelbrot_omp.cpp

mandelbrot_omp2: mandelbrot_omp2.cpp $(HEADS)
		$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC) mandelbrot_omp2.cpp

clean:
	rm $(BIN) *.o core*
