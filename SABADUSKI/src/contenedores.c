#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contenedores.h"
int inicializarPeso(eContenedor array[],int size)
{   int i;
    int retorno=-1;
    if(array!=NULL&&size>0)
    {
        for(i=0;i<size;i++)
        {
            array[i].peso=0;
        }
        retorno=0;

    }
return retorno;}

int inicializarContenedores(eContenedor array[],int size)
{   int i;
    int retorno=-1;
    if(array!=NULL&&size>0)
    {
        for(i=0;i<size;i++)
        {
            array[i].isEmpty=1;
        }
        retorno=0;

    }
return retorno;}

int imprimirContenedores(eContenedor array[],int size)
{
	int retorno=-1;
	    int i;
	    if(array!=NULL && size>=0)
	    { 	printf("\nID CONTENEDOR\t\tNOMBRE\t\tCAPACIDAD\t\tPESO\t\t\tDIA\t\t\tMES\t\tAÑO\n");
	    		    							    	retorno=0;
	    	for(i=0;i<size;i++)
	    	{
	    		if(array[i].isEmpty==0)
	    		{

	    			printf("[%10d] %17s %15d %20d %20d %20d %20d\n"
	    											,array[i].idContenedor,array[i].nombre,array[i].capacidad,array[i].peso,array[i].dia,array[i].mes,array[i].anio);
	    		}
	    		}
		}
		    return retorno;


	}

void hardcodeContenedores (eContenedor array[],int size)
{
	int i;
    char nombre[3][20]={"LILIAN","LITHOU","WANZUNG"};
    int capacidad[3]={1500,1500,1500};
    int isEmpty[3]={0,0,0};
    int idContenedor[3]={1,2,3};
    int dia[3]={23,23,23};
    int mes[3]={5,5,5};
    int anio[3]={2020,2020,2020};

    for(i=0;i<size;i++)
    {
    	strcpy(array[i].nombre,nombre[i]);
    	array[i].capacidad=capacidad[i];
    	array[i].isEmpty=isEmpty[i];
    	array[i].dia=dia[i];
    	array[i].mes=mes[i];
    	array[i].anio=anio[i];
    	array[i].idContenedor=idContenedor[i];
    }


}
