#inclusion de modulo (como libreria), usar el "as" me permite acortar codigo
import numpy as np
import matplotlib.pyplot as plt

#las variables no llevan tipo definido explicitamente
#input viene siendo la entrada
numPuntos = int(input())
n = int(input())
# distribucion normal recibe promedio,desviacion estandar y cantidad
# de elementos
arrX = np.random.uniform(0, n, numPuntos)
#castear los elementos a enteros (redondear)
arrX = arrX.astype('int')
arrY = np.random.uniform(0, n, numPuntos)
#castear los elementos a enteros (redondear)
arrY = arrY.astype('int')
puntos = set(zip(arrX,arrY))

print(n, n)
print(len(puntos))
#aqui imprimo los puntos
#zip(arrX,arrY) junta los dos arreglos y los convierte en
#un arreglo de pares
#aqui se imprimen los puntos (el for de python es distinto al de c)

for x,y in puntos:
    print (x,y)

plt.plot(arrX, arrY, '+')
plt.axis([0, numPuntos, 0, numPuntos])
plt.show()
# otras distribuciones:
# uniform([low, high, size])
# zipf(a[, size])
# normal([loc, scale, size])
# referencias https://docs.scipy.org/doc/numpy/reference/routines.random.html
