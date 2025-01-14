#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>

#define Nparticulas 1000
#define X 0
#define Y 1

typedef struct
{
    int id;
	double pos[2];
	int *cercanas;
	int nCercanas;
	int *inquilinas;
	int nInquilinas;
}malla;

malla *mesh, *auxMesh;

typedef struct
{
    int id;
    double pos[2];
    malla *ptrMalla;
    int idMalla;
    int *idVecinas;
    int nVecinas;
}particulas;

malla *mesh, *auxMesh;
particulas *part, *auxPart;

double dist(double x1, double x2, double y1, double y2);
void posParticulas();
void posMallas(double h, int n);
void mallasCercanas(int n, double h);
void inquilinato(int k, int h, int n);
void NN(int k, double h);


int main(int argc, char *argv[])
{
    int i,j,k,n,Nceldas,*auxInt,idInteres;
	double h;
    
	printf("El cuadrado contenedor de los puntos tiene dimensiones 100x100.\nConsiderando que se desea dividir en n^2 celdas del mismo tamaño, siendo n un divisor de 100 (1,2,4,5,10,20,25,50,100), escoja n.\n(recomendación, tomar n = 10)\n");
	scanf("%d",&n);
	Nceldas = n*n;
	h = 100.0/(2.0*(double)n);
	printf("\nUsted escogió n = %d , esto significa que (asumiendo %d celdas de lado L = 2h ) está buscando vecinos a una distancia h = %f.\n\n",n,Nceldas,h);

	part = (particulas *) malloc((size_t)(Nparticulas)*sizeof(particulas));
	mesh = (malla *) malloc((size_t)(Nceldas)*sizeof(malla));
	
	if( part==NULL || mesh==NULL)
	{
		printf("Error alocando part\n");
		exit(0);
	}
	
    posParticulas();


    printf("Creando mallas...\n");
	posMallas(h,n);

    printf("Encontrando mallas vecinas a cada malla...\n");
	mallasCercanas(Nceldas,h);
	
	FILE *celdasvecinas = fopen("celdasvecinas","w");
	
	for(i=0 ; i<Nceldas ; i++)
	{
		fprintf(celdasvecinas,"Celda %d\n",i);
		for(k=0 ; k<mesh[i].nCercanas ; k++)
		{
			fprintf(celdasvecinas,"%d\t",mesh[i].cercanas[k]);
		}
		fprintf(celdasvecinas,"\n\n");
	}
	fclose(celdasvecinas);
	
	
	
	printf("Metiendo partículas en sus celdas...\n");
	
	FILE *parti = fopen("particuloides.dat","w");
	for(k=0 ; k<Nceldas ; k++)
		inquilinato(k,h,Nparticulas);
	
	for(k=0 ; k<Nparticulas ; k++)
		fprintf(parti,"%3d %09.6lf %09.6lf %2d\n",part[k].id,part[k].pos[X],part[k].pos[Y],part[k].idMalla);
	
    printf("Particulas metidas con éxito.\n\n");
	fclose(parti);
	
	FILE *MallasParticulas = fopen("mallas_particulas","w");
	for(i=0 ; i<Nceldas ; i++)
	{
		fprintf(MallasParticulas,"Malla %d : %d partículas\n",mesh[i].id,mesh[i].nInquilinas);
	}
	fclose(MallasParticulas);

	
	FILE *hospedaje = fopen("hospedaje","w");
	for(i=0 ; i<Nceldas ; i++)
	{
		fprintf(hospedaje,"Celda %d\n",i);
		for(k=0 ; k<mesh[i].nInquilinas ; k++)
		{
			fprintf(hospedaje,"%d\t",mesh[i].inquilinas[k]);
		}
		fprintf(hospedaje,"\n\n");
	}
	fclose(hospedaje);
	
	printf("Encontrando vecinas de cada particula\n");
	for(k=0 ; k<Nparticulas ; k++)
		NN(k, h);
	
	printf("particulas enlazadas con exito\n\n");
	
	//Particula de interés al azar
	
	idInteres = rand()%Nparticulas;
	
	FILE *NNpart = fopen("particulas_vecinas.dat","w");
	printf("Particula de interés: %d\nVecinas:\n",idInteres);
	fprintf(NNpart,"%lf %lf\n",part[idInteres].pos[X],part[idInteres].pos[Y]);
	for(i=0 ; i<part[idInteres].nVecinas ; i++)
	{
		// Imprime en pantalla la partícula de interés y el ID de sus vecinas
		// Imprime el archivo las coordenadas X y Y de sus vecinas
		printf("%d\t",part[idInteres].idVecinas[i]);
		fprintf(NNpart,"%lf %lf\n",part[part[idInteres].idVecinas[i]].pos[X],part[part[idInteres].idVecinas[i]].pos[Y]);
	}
	printf("\n\nArchivo de particulas grabado con éxito\nSe debe cargar el script Graficas.gp en terminal gnuplot.\n\n**Finaliza programa**");
	fclose(NNpart);
	
	free(part);
	free(mesh);
	
    return 0;
}

// FIN DE MAIN

double dist(double x1, double x2, double y1, double y2)// Función para hallar distancia entre dos puntos
{
    double xij, yij, d;
    xij = x2 - x1;
    yij = y2 - y1;
    d = sqrt( xij*xij + yij*yij);
    return d;
    
}
void posParticulas()//asigna un valor al azar entre 0 y 100 a las coordenadas en X y Y de una partícula
{
    int i;
    FILE *posiciones = fopen("pos.dat","w");
        for(i=0; i<Nparticulas ; i++)
        {
            part[i].id = i;
            part[i].pos[X] = 100*(rand() / (RAND_MAX + 1.0));
            part[i].pos[Y] = 100*(rand() / (RAND_MAX + 1.0));

            fprintf(posiciones,"%lf %lf\n",part[i].pos[X],part[i].pos[Y]);
        }
    fclose(posiciones);
}

void posMallas(double h, int n)//Crea las mallas generando "partículas" en el centro de cada una de estas
{
    int id = 0;
    int i,j;
	for(i=0; i<n ; i++)
	{
		for(j=0; j<n ; j++)
	    {
	    mesh[id].id = id;
	    mesh[id].pos[X] = (2*(i+1))*h - h; 
		mesh[id].pos[Y] = (2*(j+1))*h - h;
		id++;
	    }
	}
}

void mallasCercanas(int n, double h)
{
    //printf("inicia la función mallasCercanas...\n");
    double rij,xij,yij;
    int i, j, nCerca, *auxInt;
	
    FILE *celdas = fopen("centros_mallas.dat","w");
    //printf("\n%d %lf ",n,h);
    for (i=0 ; i<n ; i++)
    {
		//free(mesh[i].cercanas);
		mesh[i].cercanas = NULL;
        nCerca = 0;
        for (j=0 ; j<n ; j++)
        {
            //xij = mesh[i].pos[X] - mesh[j].pos[X];
			//yij = mesh[i].pos[Y] - mesh[j].pos[Y];
			//rij = sqrt( xij*xij + yij*yij);
			
			rij = dist(mesh[i].pos[X], mesh[j].pos[X], mesh[i].pos[Y], mesh[j].pos[Y]);
			
            if (rij<= sqrt(2)*2*h + 1e-10)
            {   
                ///printf("prueba");
                nCerca++;
                auxInt = NULL;
                auxInt = (int *)realloc(mesh[i].cercanas,(size_t)(nCerca)*sizeof(int));
                mesh[i].cercanas = auxInt;
				auxInt = NULL;
				
                mesh[i].cercanas[nCerca-1] = j;
			}
        }
        mesh[i].nCercanas = nCerca;
		//printf("Malla %d número vecinas: %d\n",mesh[i].id,mesh[i].nCercanas);
        fprintf(celdas,"%2d %04.1lf %04.1lf %p %d\n",mesh[i].id,mesh[i].pos[X],mesh[i].pos[Y],&mesh[i],mesh[i].nCercanas);
    }
    fclose(celdas);
}

void inquilinato(int k, int h, int n)
{
	//printf("Iniciando inquilinato para celda %d...\n",k);
	free(mesh[k].inquilinas);
	mesh[k].inquilinas=NULL;
	
	int nPart=0, i, *auxInt;
	double xij, yij;
	//printf("Iniciando ciclo llenador...\n");
	for(i=0 ; i<n ; i++)
	{
		xij = fabs(mesh[k].pos[X] - part[i].pos[X]);
		yij = fabs(mesh[k].pos[Y] - part[i].pos[Y]);
		
		if( (xij<=h +1e-7) && (yij<=h +1e-7) )
		{
			nPart++;
			//añadir part a celdas
			auxInt = NULL;
			auxInt = (int *)realloc(mesh[k].inquilinas,(size_t)(nPart)*sizeof(int));
			mesh[k].inquilinas = auxInt;
			auxInt = NULL;
			
			mesh[k].inquilinas[nPart-1] = i;
			part[i].idMalla = k;
			
			//printf("La celda %d contiene a la particula %d \n",k,mesh[k].inquilinas[nPart-1]);
			//printf("La particula %d está en la celda %d \n",i,part[i].idMalla);
		}
	}
	mesh[k].nInquilinas = nPart;
}

void NN(int k, double h)
{
	free(part[k].idVecinas);
	part[k].idVecinas = NULL;
	
	int nN = 0, i, j, *auxInt, miMalla = part[k].idMalla;
	double rij;
	//printf("\niniciando ciclo enlazador %d\n",k);
	for(i=0 ; i<mesh[miMalla].nCercanas ; i++)
	{
		//int misPart = mesh[miMalla].nInquilinas;
		for(j=0 ; j<mesh[mesh[miMalla].cercanas[i]].nInquilinas ; j++)
		{
			if(k!=mesh[mesh[miMalla].cercanas[i]].inquilinas[j]) // Si la partícula no es igual
			{
				//rij = dist(part[k].pos[X], part[mesh[mesh[miMalla].cercanas[i]].inquilinas[j]].pos[X], part[k].pos[Y], part[mesh[mesh[miMalla].cercanas[i]].inquilinas[j]].pos[Y]);
				rij = dist(part[mesh[mesh[miMalla].cercanas[i]].inquilinas[j]].pos[X], part[k].pos[X], part[mesh[mesh[miMalla].cercanas[i]].inquilinas[j]].pos[Y], part[k].pos[Y]);
				
				if(rij<2*h)
				{
					nN++;
					auxInt = NULL;
					auxInt = (int *)realloc(part[k].idVecinas,(size_t)(nN)*sizeof(int));
					part[k].idVecinas = auxInt;
					auxInt = NULL;
					
					part[k].idVecinas[nN-1] = mesh[mesh[miMalla].cercanas[i]].inquilinas[j];
				}
			}
		}
	}
	//printf("\nParticula %d llenada\n",k);
	part[k].nVecinas=nN;
}