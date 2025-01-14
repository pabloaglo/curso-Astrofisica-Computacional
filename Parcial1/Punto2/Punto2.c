#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	// Primero se crean las dos matrices
	int fil1, col1, fil2, col2; //Declaración de integrales para las matrices M1 de orden (n1 x m1) y M2 de orden (n2 x m2)
	int opcion; //Switch
	char entrada;
	printf("Inserte numero de filas de la primera matriz.\n\n");
	scanf("%d",&fil1);
	printf("Inserte numero de columnas de la primera matriz.\n\n");
	scanf("%d",&col1);
	printf("\n\n============ATENCIÓN============\nNo ingrese números muy grandes\nsi va a generar matrices grandes\n=================================\n\n");
	int matrix1[fil1][col1],i,j,k;
	for (i=0;i<fil1;i++){
		for (j=0;j<col1;j++)
		{
			printf("Elemento - (%d,%d) : ",i,j);
			scanf("%d",&matrix1[i][j]);
		}
	}
	printf("\nLa primera matriz es: \n");
	for(i=0;i<fil1;i++)
	{	
		printf("\n");
		for(j=0;j<col1;j++)
			printf("%d\t",matrix1[i][j]);

	}
	
	printf("\n\nInserte numero de filas de la segunda matriz.\n");
	scanf("%d",&fil2);
	printf("\nInserte numero de columnas de la segunda matriz.\n");
	scanf("%d",&col2);
	//
	int matrix2[fil2][col2];
	for (i=0;i<fil2;i++){
		for (j=0;j<col2;j++)
		{
			printf("Elemento - (%d,%d) : ",i,j);
			scanf("%d",&matrix2[i][j]);
		}
	}
	printf("\nLa segunda matriz es: \n");
	for(i=0;i<fil2;i++)
	{	
		printf("\n");
		for(j=0;j<col2;j++)
			printf("%d\t",matrix2[i][j]);

	}
	
	int mescalar1[fil1][col1], mescalar2[fil2][col2];
	/* ===================================================================
	Estas matrices para la multiplicación por un escalar están declaradas fuera del switch pues me generaban el siguiente error al generar el case 4:
		switch jumps into scope of identifier with variably modified type
	Busqué en internet soluciones y encontré que es por declarar variables dentro de un caso del switch, y al parecer lo que hay que hacer es declararlas fuera
	para que el switch pueda tener todas las variables a su alcance.
	Realmente sigo sin entender el error, pues hasta ese momento estaba declarando sin problemas dentro de casos en el switch, y como se observa todavía,
	el resto de matrices y variables siguen declaradas dentro de los casos.
	   ===================================================================*/
	do{
	printf("\n\nInserte el número de la operación que desea realizar con las matrices:\n\n1.Suma de matrices\n2.Resta de matrices\n3.Producto por escalar\n4.Producto cruz\n\n");
	scanf("%d",&opcion);
	
	switch (opcion)
		{
		case 1:
		if (fil1==fil2 && col1==col2){//revisa que tengan iguales filas y columnas
		int suma[fil1][col1];
		for (i = 0; i < fil1; ++i){
			for (j = 0; j < col1; ++j) {
				suma[i][j] = matrix1[i][j] + matrix2[i][j];}}
		printf("\nLa suma de las matrices es:\n");
		for(i=0;i<fil1;i++){
			printf("\n");
			for (j=0;j<col1;j++)
				printf("%d\t",suma[i][j]);}}
		else {printf("\nEl número de columnas y filas de las matrices no son iguales.\n");}
		break;
		
		case 2:
		if (fil1==fil2 && col1==col2){//revisa que tengan iguales filas y columnas
		int resta[fil1][col1];
		for (i = 0; i < fil1; ++i){
			for (j = 0; j < col1; ++j) {
				resta[i][j] = matrix1[i][j] - matrix2[i][j];}}
		printf("\nLa resta de las matrices es:\n");
		for(i=0;i<fil1;i++){
			printf("\n");
			for (j=0;j<col1;j++)
				printf("%d\t",resta[i][j]);}}
		else {printf("\nEl número de columnas y filas de las matrices no son iguales.\n");}
		break;

		case 3:
		int escalar;//declaro la variable para el escalar a usar
		printf("Ingrese un escalar entero.\n");
		scanf("%d",&escalar);//almacena el valor en escalar
		for(i=0;i<fil1;++i){
			for(j=0;j<col1;++j){
				mescalar1[i][j] = escalar * matrix1[i][j];}}
		for(i=0;i<fil2;++i){
			for(j=0;j<col2;++j){
				mescalar2[i][j] = escalar * matrix2[i][j];}}
		printf("\nEl producto por escalar para las matrices es:\n");
		printf("\n\nMatriz 1:\n");
		for(i=0;i<fil1;i++){
			printf("\n");
			for (j=0;j<col1;j++)
				printf("%d\t",mescalar1[i][j]);}
		printf("\n\nMatriz 2:\n");
		for(i=0;i<fil2;i++){
			printf("\n");
			for (j=0;j<col2;j++){
				printf("%d\t",mescalar2[i][j]);}}
		break;
		
		case 4:
		if(col1==fil2){//Revisa que la cantidad de columnas de la primera matriz sea la misma que de filas de la segunda matriz
		int multrix[fil1][col2];
		for (i=0;i<fil1; i++){
            for (j=0;j<col2; j++){
                multrix[i][j] = 0;
                for (k=0;k<fil2;k++) {//se genera una matriz cuyas filas son las de la primera y columnas son las de la segunda
				multrix[i][j] += matrix1[i][k] * matrix2[k][j];};}}
		printf("\nEl producto de las matrices es:\n\n");
		
		for(i=0;i<fil1;i++){
			printf("\n");
			for (j=0;j<col2;j++)
				printf("%d\t",multrix[i][j]);}}
		else{printf("\nEl número de columnas de la matriz 1 no es igual al número de filas de la matriz 2, esta operación no se puede realizar.\n");}
		break;
	}
	
	
	printf("\n\nIngrese S si desea continuar, si desea finalizar inserte cualquier caracter.\n");
	scanf(" %c",&entrada); 
	}
	while(entrada == 'S');
	return 0;	
}	