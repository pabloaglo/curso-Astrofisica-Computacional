========================================================================================================
========================================================================================================

En este programa se utilizó el método del Euler y el método Leapfrog DKD para solucionar el problema de
tiro parabólico realizado en clase (programa 6).

Primero puede abrir el código en el editor para revisarlo.
Después, al compilar y ejecutar el código, se crearán ocho archivos:
	- Cuatro archivos contienen la información del tiro parabólico, especialmente sus posiciones en el
	eje x y en el eje y para determinado tiempo t.
	- Cuatro archivos contienen la información de la energía del sistema y su error respecto a la energía
	inicial.

Son cuatro archivos pues para cada uno de los dos métodos se usó un paso de tiempo de 20 puntos y otro
de 1000 puntos. Se pudo realizar todo en un solo archivo, sin embargo se hizo de esta forma para analizar
el tamaño de los archivos para cada método por separado en la comparación de estos.

Posteriormente, abrir la terminal gnuplot y cargar el script "EnergyGraphs.gp"; con esto, se crearán tres
gráficos:
	- Un gráfico con las posiciones en X y en Y en cada instante de tiempo con el fin de identificar la
	diferencia entre los resultados de estos métodos.
	- Un gráfico comparando el error de la energía para cada método con 20 puntos.
	- Un gráfico comparando el error de la energía para cada método con 1000 puntos.

Estas imágenes se usaron en el documento adjunto en el que se comparan los métodos.
Al cargar por primera vez este script, en mi terminal, genera el siguiente warning:
	Fontconfig error: Cannot load default config file: No such file: (null)
	
Sin embargo, al volver a cargarlo más veces deja de aparecer. Supongo que este warning es algún problema
"fantasma" de mi sistema operativo, y creo que no le aparecerá.
Puede revisar que el script está bien escrito y sin errores y el warning no afecta las gráficas creadas.

Comandos usados dentro de la misma carpeta:

	gcc Punto1.c -lm -o Punto1.exe
	./Punto1.exe
	gnuplot
	load "EnergyGraphs.gp"
	
========================================================================================================
========================================================================================================