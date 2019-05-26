#inclusion de modulo (como libreria), usar el "as" me permite acortar codigo
import numpy as np
import matplotlib.pyplot as plt
#las variables no llevan tipo definido explicitamente
#input viene siendo la entrada
numPuntos = int(input()) # de elementos
a = float(input())

arrX = np.random.zipf(a,numPuntos)
arrX = arrX.astype('int') #castear los elementos a enteros (redondear)

arrY = np.random.zipf(a,numPuntos)
arrY = arrY.astype('int') #castear los elementos a enteros (redondear)
puntos = set(zip(arrX,arrY)) #zip(arrX,arrY) junta los dos arreglos y los convierte en
#un arreglo de pares

print(numPuntos, numPuntos)
print(len(puntos)) #aqui imprimo la cantidad de puntos
for x,y in puntos: #aqui se imprimen los puntos (el for de python es distinto al de c)
	print (x,y)

plt.plot(arrX, arrY, '+')
plt.axis([0, numPuntos, 0, numPuntos])
plt.show()


# otras distribuciones:
# uniform([low, high, size])
# zipf(a[, size])
# normal([loc, scale, size])
# referencias https://docs.scipy.org/doc/numpy/reference/routines.random.html
