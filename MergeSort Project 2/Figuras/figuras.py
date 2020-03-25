import matplotlib.pyplot as plt

main = [1, 4, 8, 16]

K10 = [0.0023, 0.048, 0.094, 0.11]
K100 = [0.045, 0.073, 0.074, 0.11]
M1 = [0.35, 0.24, 0.18, 0.20]
M5 = [2.10, 0.62, 0.68, 0.63]
M10 = [4.49, 1.93, 1.87, 0.70]
M20 = [8.67, 3.97, 2.77, 1.30]
M50 = [24.92, 8.54, 7.05, 2.84]
M75 = [33.50, 15.04, 10.51, 4.48]
M100 = [48.71, 21.15, 13.73, 5.53]


which = M100


plt.plot(main, which, 'o-')
plt.xlabel('# De Procesadores')
plt.ylabel('Tiempo de Ejecución (seg)')
plt.title('Tamaño del Vector: 100M Elementos \n El mejor SpeedUp se da con 16 Proc. & es 8.80')
plt.grid()
for i in range(len(main)):
    plt.annotate(str(which[i]), (main[i], which[i]))
plt.savefig('prueba.PNG')
plt.show()
