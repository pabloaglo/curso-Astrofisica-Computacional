========================================================================================================
========================================================================================================

Este programa crea puntos de posiciones al azar dentro de una cuadrícula 100x100 y divide esta en dife-
retes mallas (el usuario escoge la cantidad, se recomienda usar 10*10 pues más cantidad generaría mucho
esfuerzo computacional; por simplicidad se asume que el usuario escogerá los números bien por lo que no
genera error al ingresar algo equivocado). La mallas tienen un tamaño de lado igual a 2*h (kappa se asu-
me como 2).

Las mallas cuentan con una "partícula" cuyas coordenadas son sus centros, por lo que se procede a hallar
sus mallas vecinas a una distancia menor o igual a sqrt(2)*2h (esto busca las partículas centrales de las
demás celdas en un círculo cuyo radio es este valor). 
Se imprime un archivo de datos ("celdasvecinas) que contiene el ID de las mallas vecinas a cada malla.
Se corrobora que las esquinas cuentan con cuatro vecinas (contando a sí mismas), los laterales tienen
seis y el resto tienen nueve. Además también se imprime un archivo ("centros_mallas.dat") con el id de
cada malla, las coordenadas de sus centros, su dirección de memoria y la cantidad de mallas vecinas.
(La dirección de memoria se iba a usar para redirigir a esta todas las partículas que estaban dentro de
esta, pero por simplicidad se decidió seguir con el uso de las ID).

Posteriormente con la función inquilinato() se enlazan las partículas con la respectiva malla que las
contiene, y se imprime un archivo con sus ID, las posiciones de cada una de estas y la ID de la malla en
la que se encuentra. Si se cotejan los valores de sus coordenadas con las coordenadas del centro de la
celda dada se puede confirmar que los resultados están bien.
Se crea un archivo que contiene la cantidad de partículas que tiene cada malla. ("mallas_particulas"),
además de otro archivo que contiene las ID de las partículas que tiene cada malla. ("hospedaje").

Luego se procede a encontrar las partículas vecinas de cada partícula a una distancia de 2*h con la fun-
ción NN(). Esta función recorre todas las partículas que componen las mallas vecinas (y su misma malla),
añadiendo el ID de la partículas si cumplen con las condiciones de ser vecina (se hace un condicional que
evita que la partícula sea vecina de sí misma).

Finalmente se escoge al azar el ID de alguna partícula. Se imprime en la pantalla el ID de sus vecinas
y se imprime en un archivo ("particulas_vecinas.dat"): en la primera fila las coordenadas de esta partí-
cula de interés, y en el resto de filas las coordenadas de sus vecinas.

Al grabarse con éxito, se libera el espacio de memoria que acaparan las mallas y las partículas y se
finaliza el programa.

El script graficador primero grafica todas las partículas en sus posiciones X y Y, luego las partículas
vecinas a la de interés (contando esta) con un color diferente y un tamaño de punto menor y finalmente
sobrepone la partícula de interés con otro color.

Toda relocación de memoria se hizo con su respectivo puntero auxiliar para prevenir cualquier tipo de
problema.
Se anexa una carpeta con el programa ejecutado por una compañera. Al parecer mi Windows pone demasiado
problema a la hora de echarle memoria a la ejecución del programa y no ejecutaba completo. Sin embargo,
estoy seguro que no habrá problema en ejecutarlo en un computador normal.
Intenté comentar más el código, pero preferí no seguir tocándolo por la imposibilidad de probar yo
mismo su funcionamiento. u_u


Comandos utilizados dentro de la misma carpeta:
	
	gcc Punto2.c -o Punto2.exe
	./Punto2.exe
	>>Se escoge la cantidad de mallas por lado
	
	gnuplot
	>load Graficas.gp
	
========================================================================================================
========================================================================================================