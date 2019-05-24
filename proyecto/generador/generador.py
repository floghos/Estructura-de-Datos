#inclusion de modulo (como libreria), usar el "as" me permite acortar codigo
import numpy as np

#las variables no llevan tipo definido explicitamente
#input viene siendo la entrada
numPuntos = int(input("ingrese cantidad de puntos: "))
n = int(input("cantidad de columnas: "))
m = int(input("cantidad de filas: "))
# distribucion normal recibe promedio,desviacion estandar y cantidad
# de elementos
#CUIDADO AL CAMBIAR LA DESVIACION ESTANDAR, SE PUEDE SALIR DEL RANGO
arrX = np.random.normal(n*0.5,n*0.1,numPuntos)
#castear los elementos a enteros (redondear)
arrX = arrX.astype('int')
arrY = np.random.normal(m*0.5,m*0.1,numPuntos)
#castear los elementos a enteros (redondear)
arrY = arrY.astype('int')
puntos = set(zip(arrX,arrY))
print("cantidad de puntos", len(puntos))
#aqui imprimo los puntos
#zip(arrX,arrY) junta los dos arreglos y los convierte en
#un arreglo de pares
#aqui se imprimen los puntos (el for de python es distinto al de c)
for x,y in puntos:
    print(x,y)
