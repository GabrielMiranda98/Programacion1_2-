#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "contenedores.h"

int inicializarPesoProducto(eProducto array[],int size)
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

int inicializartipo(eProducto array[],int size)
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
int imprimirProducto(eProducto array[],int size,eContenedor array2[],int size2)
{
	int retorno=-1;
		    int i;
		    int j;
		 if(array!=NULL && size>0&&array2!=NULL && size2>0)
		 {
			 printf("\nID PRODUCTO\t\tAPELLIDO\t\tPESO\t\tTIPO(1-IMPORTANTE / 0-NORMAL)\tID CONTENEDOR\tNOMBRE CONTENEDOR\n");
			 for(i=0;i<size;i++)
		    	{
		    		if(array[i].isEmpty==0)
		    {
		    			for(j=0;j<size2;j++)
		    		{
		    			if(array2[j].isEmpty==0)
		    			{

		    				if(array[i].idContenedor==array2[j].idContenedor)
		    				{
		    					printf("[%10d] %17s %20d %20d %25d %20s\n"
		    						    											,array[i].id,array[i].apellido,array[i].peso,array[i].tipo,array[i].idContenedor,array2[j].nombre);
		    						    	retorno=0;
		    				}


		    				}
		    			}


		    		}

		    }

		    	}
	return retorno;
	}
void hardcodeProducto(eProducto array[],int size)
{

	int i;
    char apellido[15][20]={"LILIAN","LILIAN","LILIAN","LILIAN","LILIAN","LILIAN","LITHOU","LITHOU","LITHOU","LITHOU","LITHOU","LITHOU","WANZUNG","WANZUNG","WANZUNG"};
    int peso[15]={4,4,4,4,4,4,6,6,6,6,6,6,20,20,20};
    int isEmpty[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int id[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int tipo[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int idContenedor[15]={1,1,1,1,1,1,2,2,2,2,2,2,3,3,3};
    for(i=0;i<size;i++)
    {
    	strcpy(array[i].apellido,apellido[i]);
    	array[i].id=id[i];
    	array[i].isEmpty=isEmpty[i];
    	array[i].peso=peso[i];
    	array[i].tipo=tipo[i];
    	array[i].idContenedor=idContenedor[i];
    }
}
