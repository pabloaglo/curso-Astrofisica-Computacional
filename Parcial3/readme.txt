===========================================================================================
===========================================================================================

Este programa implementa el algoritmo linked list para la búsqueda de vecinos a la simula-
ción de SPH brindada en clase. Se hicieron modificaciones importante a la forma en la que
se tratan las celdas, pues estas me causaron los principales problemas y retrasos a la hora
de realizar el código:
	-En primer lugar, se crean las celdas dentro de la función main en vez de usar una
	función separada como en el parcial 2; esto es debido a que el primer problema fue
	a la hora de generar las posiciones de sus centros. Si se creaban, se creaban todas
	en cero; si se creaban bien, a la hora de recorrer el algoritmo de búsqueda de par-
	tículas vecinas se volvía a desbaratar todo. Decidí dejarlo dentro del main para
	arreglarlo más fácil en vez de tener que modificar main y función a la vez.
	
	-En segundo lugar la búsqueda de celdas vecinas se modifica y en vez de buscar en
	un radio de 2h*sqrt(2) se analiza la posición de cada celda en la malla:
	En caso de pertenecer a una esquina, va a resultar con cuatro vecinas; en caso de
	pertenecer a un lateral, va a resultar con seis vecinas; en cualquier otro caso
	resultará con nueve vecinas. A su vez eso se implemetó dentro del main para hacer
	todo el proceso de la construcción menos tedioso.
	
La función inquilinato sigue funcionando igual, analizando si la partícula en cuestión cae
dentro del área de la celda. La función NN() se modificó para la implementación del algo-
ritmo del parcial 2.

Anexado en la entrega se encuentra el informe pedido en el que se analizan los tiempos de
ejecución se realiza un estudio paramétrico sobre diferentes variables que determinan la
simulación; para cada parámetro modificado se analizaron mínimo tres casos, y en algunos
se enlaza un gif para ilustrar mejor los cambios.

===========================================================================================
===========================================================================================
