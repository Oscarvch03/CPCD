BIN := mainSerial mainParallel SUandDE

CFLAGS := -std=c++14
LDFLAGS := -pthread

CXX := g++

HEADSs := matrix.hpp serial.hpp
SRCs := matrix.cpp serial.cpp

HEADSp := matrix.hpp parallel.hpp
SRCp := matrix.cpp parallel.cpp


mainSerial: mainSerial.cpp $(HEADSs)
	$(CXX) $(CFLAGS) -o $@ $(SRCs) mainSerial.cpp
	# Genero el txt con los tiempos y tiempos al cuadrado
	# de la ejecucion Serial
	# Se demora aprox. 1000seg = 16,6 min


mainParallel: mainParallel.cpp $(HEADSp)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRCp) mainParallel.cpp
	# Genero el txt con los tiempos y tiempos al cuadrado
	# de la ejecucion en Paralelo
	# Se demora aprox. 300seg = 5min

SUandDE: SUandDE.cpp
	$(CXX) $(CFLAGS) -o $@ SUandDE.cpp
	# Calculo el SpeedUp promedio y su Desviacion Estandar
