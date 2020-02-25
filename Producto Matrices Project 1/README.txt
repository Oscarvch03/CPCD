OSCAR VELASCO CHIQUILLO
13 DE FEBRERO DE 2020
CPCD: PROJECT 1 / Prodcuto entre matrices Serial & Paralelo

Link Github: https://github.com/Oscarvch03/CPCD-PROJECT-1-MxM.git

El repositorio cuenta con un "Makefile" que facilita la compilación.

1) "make mainSerial": Genera el txt "serial.txt" con los tiempos y
    tiempos al cuadrado de la ejecucion Serial.
    Se demora aprox. 1000 seg = 16,6 min. (Tambien lo hubiese podido
    paralelizar :(. ).
    Para ejecutar "./mainSerial 1000" (o la dimension que desee para
    la matriz resultante).

2) "make mainParallel": Genero el txt "parallel.txt" con los tiempos
    y tiempos al cuadrado de la ejecucion en Paralelo.
    Se demora aprox. 300 seg = 5 min. (Tambien lo hubiese podido
    paralelizar :(. ).
    Para ejecutar "./mainParallel 1000" (o la dimension que desee para 
    la matriz resultante).

3) "make SUandDE": Leo los tiempo y los tiempos cuadrados de los txt
    generados en los "make" 1 & 2. Luego calculo el SpeedUp promedio
    ("SpU") y su Desviacion Estandar ("DE").
    Para ejecutar "./SUandDE".


FALTO AGREGAR PRUEBAS INDIVIDUALES PARA OPERADOR SERIAL Y PARALELO. REVISAR
