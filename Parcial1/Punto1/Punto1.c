#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
	Por facilidad, este programa es en mucha parte una copia directa del programa 6 trabajado en clase.
	Los cambios realizados son en pro de comparar los métodos de integración de Euler y de leapfrog DKD 
	para determinar cuál es más efectivo a la hora de:
		- Mantener la energía del sistema
		- Ser computacionalmente efectivo
		- Producir resultados en archivos ligeros
*/

// Variables globales

double g=9.8;


double checkE(double t, double masa, double vx, double vy, double altura)//Chequeo de la energía
{
  double energia, v2;

  v2 = vx*vx+vy*vy;

  energia = 0.5*masa*v2 + masa*g*altura;

  return energia;
}

int main(int argc, char *argv[])
{
	
	int i;
  
	double altura, vel_ini;
	double energia, masa, x, y, vx, vy, t, dt_1000, dt_20,energia_inicial,error_energia;
	double tiempo_caida;
  
  //iniciar el resto de variables
	x = 0.0;
	y = altura = 10.0;
	masa = 1.0;
	vx = vel_ini =  1.0;
	vy = 0.0;
	t = 0.0;
	energia = energia_inicial = 0.5*masa*(vx*vx+vy*vy) + masa*g*altura;
	tiempo_caida = sqrt( 2.0*altura/g );
	printf("Tiempo de caída estimado = %lf s\n",tiempo_caida);
	printf("energia_inicial = %lf\n",energia_inicial);

	printf("\n\nEn este programa se usarán, para el mismo problema, los métodos Leapfrog DKD, y  Euler para 20 y 1000 pasos en el tiempo.\n\nLeer el readme incluido para mayor información.");	
	//======================================================================
	dt_1000 = tiempo_caida/1000;
	dt_20 = tiempo_caida/20;
	//======================================================================
	///*
	// Euler con 1000 puntos
	FILE *p_e_f = fopen("parabolicoEuler1000.dat","w");
	fprintf(p_e_f,"%lf\t%lf\t%lf\t%lf\t%lf\n", t, x, y, vy, energia);
  
	FILE *fEulergia = fopen("Eulergia.dat","w");
	energia = checkE(t,masa,vx,vy,y);
	error_energia = ( fabs(energia-energia_inicial) ) / energia_inicial;
	fprintf(fEulergia," %lf,%lf,%lf\n",t,energia,error_energia);
	
	double vy_e = vy, x_e=x, y_e=y,error_energia_e,energia_e;
            //Integración Euler y fichero:
	for ( t=0.0; t<=tiempo_caida; t+=dt_1000 )
    {
      vy_e = vy_e - g*dt_1000;
      
      x_e = x_e + vx*dt_1000;
      y_e = y_e + vy_e*dt_1000;
      

      if (y_e>=0.0)
	{
	  energia_e = checkE(t, masa, vx, vy_e, y_e);
	  error_energia_e = ( fabs(energia_e-energia_inicial) ) / energia_inicial;
	  fprintf(fEulergia,"%lf %lf %lf\n",t,energia_e,error_energia_e);
	  fprintf(p_e_f,"%lf\t%lf\t%lf\t%lf\t%lf\n", t, x_e, y_e, vy_e, energia_e);
	}
      else
	break;
    }
	fclose(p_e_f);
	fclose(fEulergia);	
	//*/
	//======================================================================
	///*
	// Euler con 20 puntos
	FILE *p_e_f20 = fopen("parabolicoEuler20.dat","w");
	fprintf(p_e_f20,"%lf\t%lf\t%lf\t%lf\t%lf\n", t, x, y, vy, energia);
  
	FILE *fEulergia20 = fopen("Eulergia20.dat","w");
	energia = checkE(t,masa,vx,vy,y);
	error_energia = ( fabs(energia-energia_inicial) ) / energia_inicial;
	fprintf(fEulergia20," %lf,%lf,%lf\n",t,energia,error_energia);
	
	double vy_e20 = vy, x_e20=x, y_e20=y,error_energia_e20,energia_e20;
            //Integración Euler y fichero:
	for ( t=0.0; t<=tiempo_caida; t+=dt_20 )
    {
      vy_e20 = vy_e20 - g*dt_20;
      
      x_e20 = x_e20 + vx*dt_20;
      y_e20 = y_e20 + vy_e20*dt_20;
      

      if (y_e20>=0.0)
	{
	  energia_e20 = checkE(t, masa, vx, vy_e20, y_e20);
	  error_energia_e20 = ( fabs(energia_e20-energia_inicial) ) / energia_inicial;
	  fprintf(fEulergia20,"%lf %lf %lf\n",t,energia_e20,error_energia_e20);
	  fprintf(p_e_f20,"%lf\t%lf\t%lf\t%lf\t%lf\n", t, x_e20, y_e20, vy_e20, energia_e20);
	}
      else
	break;
    }
	fclose(p_e_f20);
	fclose(fEulergia20);	
	//*/
	//======================================================================
	///*
	// DKD con 1000 puntos
	FILE *p_dkd1_f = fopen("parabolicoDKD1.dat","w");
	fprintf(p_dkd1_f,"%lf\t%lf\t%lf\t%lf\t%lf\n", t, x, y, vy, energia);
  
	FILE *fEnergia_DKD1 = fopen("DKD_energia_1.dat","w");
	energia = checkE(t,masa,vx,vy,y);
	error_energia = ( fabs(energia-energia_inicial) ) / energia_inicial;
	fprintf(fEnergia_DKD1," %lf,%lf,%lf\n",t,energia,error_energia);
	
	double vy_dkd = vy, x_dkd=x, y_dkd=y,error_energia_dkd,energia_dkd;
            //Integración DKD y fichero:
	for ( t=0.0; t<=tiempo_caida; t+=dt_1000 )
    {
      y_dkd = y_dkd + vy_dkd*dt_1000*0.5;
	  
	  vy_dkd = vy_dkd - g*dt_1000;
      
      x_dkd = x_dkd + vx*dt_1000;
	  
      y_dkd = y_dkd + vy_dkd*dt_1000*0.5;

      if (y_dkd>=0.0)
	{
	  energia_dkd = checkE(t, masa, vx, vy_dkd, y_dkd);
	  error_energia_dkd = ( fabs(energia_dkd-energia_inicial) ) / energia_inicial;
	  fprintf(fEnergia_DKD1,"%.12lf %.12lf %.12lf\n",t,energia_dkd,error_energia_dkd);
	  fprintf(p_dkd1_f,"%.12lf\t%.12lf\t%.12lf\t%.12lf\t%.12lf\n", t, x_dkd, y_dkd, vy_dkd, energia_dkd);
	}
      else
	break;
    }
	fclose(p_dkd1_f);
	fclose(fEnergia_DKD1);
	//*/
	//======================================================================
	///*
	// DKD con 20 puntos
	FILE *p_dkd2_f = fopen("parabolicoDKD2.dat","w");
	fprintf(p_dkd2_f,"%lf\t%lf\t%lf\t%lf\t%lf\n", t, x, y, vy, energia);
  
	FILE *fEnergia_DKD2 = fopen("DKD_energia_2.dat","w");
	energia = checkE(t,masa,vx,vy,y);
	error_energia = ( fabs(energia-energia_inicial) ) / energia_inicial;
	fprintf(fEnergia_DKD2," %lf,%lf,%lf\n",t,energia,error_energia);
	
	double vy_dkd2 = vy, x_dkd2=x, y_dkd2=y,error_energia_dkd2,energia_dkd2;
            //Integración DKD y fichero:
	for ( t=0.0; t<=tiempo_caida; t+=dt_20 )
    {
      y_dkd2 = y_dkd2 + vy_dkd2*dt_20*0.5;
	  
	  vy_dkd2 = vy_dkd2 - g*dt_20;
      
      x_dkd2 = x_dkd2 + vx*dt_20;
	  
      y_dkd2 = y_dkd2 + vy_dkd*dt_20*0.5;

      if (y_dkd2>=0.0)
	{
	  energia_dkd2 = checkE(t, masa, vx, vy_dkd2, y_dkd2);
	  error_energia_dkd2 = ( fabs(energia_dkd2-energia_inicial) ) / energia_inicial;
	  fprintf(fEnergia_DKD2,"%.12lf %.12lf %.12lf\n",t,energia_dkd2,error_energia_dkd2);
	  fprintf(p_dkd2_f,"%.12lf\t%.12lf\t%.12lf\t%.12lf\t%.12lf\n", t, x_dkd2, y_dkd2, vy_dkd2, energia_dkd2);
	}
      else
	break;
    }
	fclose(p_dkd2_f);
	fclose(fEnergia_DKD2);
	//*/
		//======================================================================
	///*
	
	return 0;
	
}
