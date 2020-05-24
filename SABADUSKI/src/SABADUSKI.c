#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contenedores.h"
#include "producto.h"
int maximoPromedio(int *array,int *resultado);

int main(void)
{	setbuf(stdout,NULL);
int opcion;
		eContenedor arrayContenedor[QTY_CONTENEDORES];
		eProducto arrayProducto[QTY_PRODUCTO];


	 inicializarPeso(arrayContenedor,QTY_CONTENEDORES);
	 inicializarContenedores(arrayContenedor,QTY_CONTENEDORES);

	 hardcodeContenedores (arrayContenedor,QTY_CONTENEDORES);


	 inicializartipo(arrayProducto,QTY_PRODUCTO);
	 inicializarPesoProducto(arrayProducto,QTY_PRODUCTO);

	 hardcodeProducto(arrayProducto,QTY_PRODUCTO);

do{
	 printf("\n1-Productos, 2-Contenedores 3-Salir\n");
	 scanf("%d",&opcion);
	switch(opcion)
	{
	case 1:
	 imprimirProducto(arrayProducto,QTY_PRODUCTO,arrayContenedor,QTY_CONTENEDORES);
	 break;
	case 2:
	 imprimirContenedores(arrayContenedor,QTY_CONTENEDORES);
	 break;

	}}while(opcion!=3);

	 return 0;
}

/*1
 *  Necesitamos una función que de un array de enteros que recibe como parámetro ,
 *  que nos retorne si el array está vacío/null o no y obtener el máximo y el Promedio ,
 *  La función no debe mostrar ningún mensaje , solo me deja obtener los valores.
*/


int maximoPromedio(int *array,int size, int *resultado, int *maximo, int *minimo)
{
	int retorno=-1;
	int i;
	int* Maximo[size+1];
	int* Minimo[size+1];
	if(array!=NULL)
	{
		retorno=0;

			for(i=0;i<size;i++)
			{
				*array[i]=&Maximo[i];
			}

	}

	return retorno;
}


/*2
 *necesitamos una función que reciba tres parámetros de tipo int,
 *necesitamos que retorne si están ordenados de menor a mayor (o o 1)por el orden de los parámetros,
 y que los ordene de mayor a menor intercambiando los valores
*/






/*3
 *Necesitamos una funcion que reciba dos parametros:
 *Necesitamos una cadena y una que nos retorne si esta vacia o no.
 *Necesitamos  y ordene la cadena de la a A la Z
*/




