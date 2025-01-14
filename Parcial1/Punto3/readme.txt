========================================================================================================
========================================================================================================

En este programa se calculan y grafican las funciones de primera especie para órdenes 0, 1 y 2 en un in-
tervalo de x entre 0 y 20, para compararlas con la gráfica de ejemplo entregada por el profesor.

Primero se realizó una función que calcula de forma recursiva el factorial del número entregado en for-
mato long double pues este puede tomar valores muy grandes.

Posteriormente se pensó en realizar una función que calculara cada orden de Bessel para un x determinado,
sin embargo, tenía demasiados problemas a la hora de realizarla. Los cálculos salían desastrosos.
Por recomendaciones de colegas del curso, se realizó ese cálculo dentro de la función main, donde empezó
a tomar mejor forma y con un valor de k (índice de la sumatoria) adecuado, se lograron obtener resultados
satisfactorios.
Finalmente, se realizó el script de gnuplot que grafica estas funciones en los rangos de X y Y de la
gráfica de ejemplo. Revisando la imagen puede ver que es la misma que la del ejemplo.

Comandos utilizados en la misma carpeta:
	
	gcc Punto3.c -o Punto3.exe
	./Punto3.c
	gnuplot
	load "BesselGraph.gp"
	
========================================================================================================
========================================================================================================