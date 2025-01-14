#include<stdio.h>
#include<stdlib.h>
#include<math.h>


long double factorial(long double);//declaración de la rutina usada para calcular el factorial de un número

int main(void)
{
	//========================================================
	FILE *Bessel = fopen("Bessel.dat","w");//Se crea el archivo para almacenar los datos 
	double x, dx = 0.01,J_0,J_1,J_2,k;/*Se declaran las variables que se usarán:
	
	dx: el paso en el que incrementará x en el ciclo ; J_0,J_1 y J_2 los valores*/
	//========================================================
	for(x=0.0;x<=20.0;x=x+dx){//Ciclo que recorre los valores de x hasta el límite de la gráfica del ejemplo
		J_0=0.0;// Se toman en cero los valores de cada
		J_1=0.0;// función J_alfa(x) para calcularse en
		J_2=0.0;// una nueva suma
		//========================================================
		for(k=0.0;k<=30.0;k++){//Ciclo que recorre los valores del índice de la sumatoria
			J_0 += pow(-1,k)*pow(x*0.5,2*k)/(factorial(k)*factorial(k));
			J_1 += pow(-1,k)*pow(x*0.5,2*k+1)/(factorial(k)*factorial(k+1));
			J_2 += pow(-1,k)*pow(x*0.5,2*k+2)/(factorial(k)*factorial(k+2));
			}
		//========================================================
		/* Para cada valor de X se calculan mediante la sumatoria dada, los valores
		   de la función de Bessel de primera especie para los órdenes 0, 1 y 2
		   Posteriormente se imprime cada resultado en el archivo.*/
		//========================================================
		fprintf(Bessel,"%lf %lf %lf %lf\n",x,J_0,J_1,J_2);
		}
	fclose(Bessel);
	
	
	return 0;
}

long double factorial(long double n)//Calculando el factorial de 'n' de manera recursiva
{if (n==0.0){return 1.0;}//           como long double pues se tomarán valores muy grandes         
else{return n*factorial(n-1.0);}}
