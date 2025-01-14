========================================================================================================
========================================================================================================

Este programa crea un árbol como estructura autorreferenciada. El árbol creado es conocido como árbol de
búsqueda binario y es muy funcional a la hora de mantener organizada una lista de números. Es llamado
árbol binario pues cada nodo tiene un máximo de dos hojas (o hijos). La organización de los datos se da
de la siguiente forma:
	-> Todo nodo a la izquierda es menor que el nodo raíz (el primero de todos).
	-> Todo nodo a la derecha es mayor que el nodo raíz.
	-> Cada rama de cada nodo es además un árbol binario, por lo que se cumplen las previas propiedades
	
Se tuvo como base el código proporcionado en la página 444 del texto compartido (Deitel, H. M., &
Deitel, P. J. (2004). Cómo programar en C/C++ y Java. Pearson Educación); sin embargo, para no quedar
corto en la práctica realicé el ejercicio 12.25 en el que se busca imprimir el árbol generado por medio
de una función recursiva. Con esto se afianzaron los conceptos de estas estructuras y el buen manejo
de punteros para poder obtener resultados satisfactorios.

La figura impresa del árbol varía mucho, en el ejemplo del ejercicio se ve bien al estar organizada
y simétrica, sin embargo al generarse árboles con datos aleatorios las gráficas no pueden llegar a ser
tan estéticamente apreciables; sin embargo, se puede verificar la veracidad de la figura comparando con
el recorrido preOrden:
	1. Se recorren todas las ramas de la izquierda (números menores).
	2. Se empieza desde el final a recorrer las ramas de la derecha (mayores).
	3. Al llegar al nodo raíz se recorren el primer sub-arbol de la derecha, desviándose con prioridad
	a las nuevas ramas de la izquierda (números menores).
	

Comandos utilizados dentro de la misma carpeta:
	
	gcc Punto3.c -o Punto3.exe
	./Punto3.exe

========================================================================================================
========================================================================================================

