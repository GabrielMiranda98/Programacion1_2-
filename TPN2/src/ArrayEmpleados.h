
#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_
#define QTY_EMPLEADO 1000
typedef struct
{	int id;
	int esVacio;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;

}eEmpleado;

int hardcodeEmpleado (eEmpleado array[], int size, int id, char nombre[], char apellido[], float salario, int sector);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int inicializarEmpleado(eEmpleado array[], int size);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int buscarEmpleado(eEmpleado array[], int size, int valorBuscado, int* posicion);
int buscarVacioEmpleado(eEmpleado array[], int size, int* posicion);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int altaEmpleado(eEmpleado array[], int size, int* contadorID);
int bajaEmpleado(eEmpleado array[], int sizeArray, int indice);
int modificarEmpleado(eEmpleado array[],int limite, int indice);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int imprimirEmpleado(eEmpleado array[],int size);
int funcionImprimir(eEmpleado array[], int size);
int ordenamientoEmpleados(eEmpleado array[], int size, int orden);
int informesSalarios(eEmpleado array[], int size);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif /* ARRAYEMPLEADOS_H_ */

