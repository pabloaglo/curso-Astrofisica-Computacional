#include<stdio.h>
#include<stdlib.h>

void cambio(int *i, int *j){
    int x = *i;//Se almacena el valor del primer número analizado
    *i = *j;//El valor del primer número se cambia por el del segundo
    *j = x;//El valor del segundo número se cambia por el del primero
}
void burbuja(int array[], int n){
    int i, j;//Se declaran los índices
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){//Estos ciclos recorre los números del array revisando si el número siguiente 
            if(array[j]>array[j+1])//es mayor o menor,  usando la función cambio para cambiar su posición en
				cambio(&array[j],&array[j+1]);}}//el arreglo
}

int main(){
	//Primero se crea un archivo con los números que se ordenarán, ingresados por el usuario
	int N,i,n;//Declaración de variables
	printf("Ingrese la cantidad de números que va a organizar.\n");
	scanf("%d",&N);//El usuario ingresa el tamaño que tendrá el array
	
	FILE *ingresan = fopen("ingresan.dat","w");//Se crea el archivo de los nímeros que ingresan
	printf("Ingrese los números que va a organizar.\n");
	i=0;
	while(i<N){
		scanf("%d",&n);
		fprintf(ingresan,"%d\n",n);
		i++;}
		
	fclose(ingresan);
	printf("\n%d\n",N);
	int array[N];//Se declara un arreglo que tendrá N números guardados
	
	FILE *organizan = fopen("ingresan.dat","r");//Se lee el archivo de números ingresados y  se guardan en el arreglo
	for(i=0;i<N;++i){
	fscanf(organizan,"%d",&array[i]);}
	
	printf("Los números ingresados son:\n");//Se imprime en pantalla el arreglo ingresado
	for(i=0;i<N;i++){
	printf("%d ",array[i]);}
	
	burbuja(array,N);//Se ejecuta la función y se organizan en orden los números del arreglo
	
	printf("\n\nLos números organizados son:\n");//Se imprime en pantalla el arreglo organizado
	for(i=0;i<N;i++){
	printf("%d ",array[i]);}
	
	FILE *organizados = fopen("organizados.dat","w");//Se crea un archivo con los números del arreglo organizado
	i=0;
	while(i<N){
		fprintf(organizados,"%d\n",array[i]);
		i++;	}
	
	fclose(organizados);
	
	printf("\n\nSe ha creado un archivo con los %d números ingresados en orden.",N);
	
	return 0;
}