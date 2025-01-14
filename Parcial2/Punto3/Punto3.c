/*  Implementación de árbol como estructura autoreferenciada
   con impresión de sus recorridos y sus nodos fila por fila */
	
/* Pablo Agudelo Londoño */
	
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define COUNT 5

struct nodoArbol{
	struct nodoArbol *Izq; // puntero al subárbol izquierdo
	int dato; // dato dentro del subárbol
	struct nodoArbol *Der; //puntero al subárbol derecho
};
typedef struct nodoArbol NodoArbol;
typedef NodoArbol *ptrNodoArbol;

void insertarNodo( ptrNodoArbol *ptrArbol, int i );
void salidaArbol(struct nodoArbol* ptrTree, int espaciosTotales);
void printAux(ptrNodoArbol ptrRaiz);
void inOrden(ptrNodoArbol ptrArbol);
void preOrden( ptrNodoArbol ptrArbol);
void postOrden( ptrNodoArbol ptrArbol);

int main()
{
	int datos,j;
	ptrNodoArbol ptrRaiz = NULL; // árbol inicia vacío

	srand( time( NULL) );
		
	printf("Al árbol ingresarán los siguientes 10 números al azar del 1 al 50:\n");
	
	for(j=1 ; j<=10 ; j++)
	{
		datos = rand() % 50;
		printf("%3d",datos);
		insertarNodo(&ptrRaiz, datos);
	}		
	printf("\n");
	printf("\n\nEl recorrido en inorden es:\n");
	inOrden(ptrRaiz);
	printf("\n\nEl recorrido en preOrden es:\n");
	preOrden(ptrRaiz);
	printf("\n\nEl recorrido en postOrden es:\n");
	postOrden(ptrRaiz);
	printf("\n\nEl tree generado es el siguiente (el resultado se puede leer comparándolo con el recorrido preOrden):\n\n");
	
	salidaArbol(ptrRaiz,0);
	
	return 0;
}

void insertarNodo(ptrNodoArbol *ptrArbol, int i)
{
	if( *ptrArbol == NULL)
	{
		*ptrArbol = (NodoArbol *) malloc(sizeof(NodoArbol));
		
		if(*ptrArbol != NULL)
		{
			(*ptrArbol)->dato = i;
			(*ptrArbol)->Izq = NULL;
			(*ptrArbol)->Der = NULL;
		}
		else
		{
			printf("Memoria insuficiente para insertar dato en nodo.");
		}
	}
	else
	{
		if(i < (*ptrArbol)->dato )
		{
			insertarNodo( &( (*ptrArbol)->Izq ), i);
		}
		else if( i > (*ptrArbol)->dato )
		{
			insertarNodo( &((*ptrArbol)->Der), i);
		}
		else
		{
			printf(" repetido  ");
		}
	}

}

void salidaArbol(struct nodoArbol* ptrTree, int espaciosTotales)
{
	int i;
	
	//printf("prueba");
	if(ptrTree == NULL)
		return;
	
	espaciosTotales += 10;
	
	salidaArbol(ptrTree->Der, espaciosTotales);
	
	printf("\n");
	for(i=1; i<espaciosTotales ; i++)
		printf(" ");
	printf("%d\n",ptrTree->dato);

	salidaArbol(ptrTree->Izq, espaciosTotales);

}

void inOrden( ptrNodoArbol ptrArbol)
{
	if(ptrArbol!=NULL){
		inOrden( ptrArbol->Izq);
		printf("%3d",ptrArbol->dato);
		inOrden(ptrArbol->Der);
	}
}

void preOrden( ptrNodoArbol ptrArbol)
{
	if(ptrArbol!=NULL){
		printf("%3d",ptrArbol->dato);
		preOrden(ptrArbol->Izq);
		preOrden(ptrArbol->Der);
	}
}

void postOrden(ptrNodoArbol ptrArbol)
{
	if(ptrArbol!=NULL){
		postOrden(ptrArbol->Izq);
		postOrden(ptrArbol->Der);
		printf("%3d",ptrArbol->dato);
	}
}