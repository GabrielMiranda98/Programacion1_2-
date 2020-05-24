
#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#define QTY_PRODUCTO 15
#include "contenedores.h"
typedef struct
{
	int tipo;
	char apellido[51];
	int peso;
	int isEmpty;
	int id;
    int idContenedor;


}eProducto;

int inicializartipo(eProducto array[],int size);
void hardcodeProducto(eProducto array[],int size);
int imprimirProducto(eProducto array[],int size,eContenedor array2[],int size2);
int inicializarPesoProducto(eProducto array[],int size);
#endif /* PRODUCTO_H_ */
