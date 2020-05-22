#include "ArrayEmpleados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
int hardcodeEmpleado (eEmpleado array[], int size, int id, char nombre[], char apellido[], float salario, int sector)
{
    array[id].id = id;
    strcpy(array[id].nombre, nombre);
    strcpy(array[id].apellido, apellido);
    array[id].esVacio = 0;
    array[id].salario = salario;
    array[id].sector = sector;

    return id;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int inicializarEmpleado(eEmpleado array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].esVacio=1;
        }
        retorno=0;
    }
    return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int buscarEmptyEmpleado(eEmpleado array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].esVacio==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int buscarEmpleado(eEmpleado array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].esVacio==1)
                continue;
            else if(array[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int altaEmpleado(eEmpleado array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    float salario;
    int sector;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(buscarEmptyEmpleado(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].id=*contadorID;
            array[posicion].esVacio=0;
            utn_getName("\tIngrese el nombre del Empleado : ","\nError",1,51,3,array[posicion].nombre);
            utn_getName("\tIngrese el apellido del Empleado : ","\nError",1,51,3,array[posicion].apellido);
            utn_getFloat("\tIngrese el salario del Empleado\t","\tError\t",0,20,1000,10000000,3,&salario);
            utn_getNumero(&sector,"\tIngrese el sector del Empleado\t","\tError\t",1,3,3);
            array[posicion].salario=salario;
            array[posicion].sector=sector;
			printf("\tSe cargo al Empleado.\t");

            retorno=0;
        }
    }
    return retorno;
}
int bajaEmpleado(eEmpleado array[], int sizeArray, int indice)
{	int retorno=-1;
	int validar;

		if(array!=NULL&&sizeArray>=0&&indice>=0&&array[indice].esVacio==0)
		{//tengo que mostra los prestamos del cliente
        	printf("\tID:[ %d ]\n\tNombre del Empleado:[ %s ]\n\tApellido del Empleado :[ %s ]\n\tSector del Empleado :[ %d ]\n\tSalario del Empleado :[ %.2f ]",array[indice].id,array[indice].nombre,array[indice].apellido,array[indice].sector,array[indice].salario);
		 utn_getNumero(&validar,"\t\n1-CONFIRMAR ID \n2-CANCELAR \n","\tError, numero ingresado no valido\n",1,2,3);

		 if(validar==1){

			 array[indice].esVacio=1;
			retorno=0;
			printf("\tEliminacion de ID exitosa\n");}
		 else if(validar==2)
		 {
			printf("\tCANCELADO\t");
		 }
		}
		else
		{
			printf("\nID NO ENCONTRADO\n");
		}
	return retorno;
}
int modificarEmpleado(eEmpleado array[],int limite, int indice)
{
	int retorno=-1;
	int opcion;
	 float salario;
	    int sector;
	if(array!=NULL&&limite>0&&indice<limite&&indice>=0&&array[indice].esVacio==0)
	{
		utn_getNumero(&opcion,"\t\n¿Que desea modificar?\n\t1-NOMBRE\n\t2-APELLIDO\n\t3-SALARIO\n\t4-SECTOR\n\t5-TODOS LOS CAMPOS\n","\nError\n",1,5,3);
		switch(opcion)
		{
		case 1:
            utn_getName("\n\tIngrese el nombre del Empleado : ","\nError",1,51,3,array[indice].nombre);
		break;
		case 2:
            utn_getName("\n\tIngrese el apellido del Empleado : ","\nError",1,51,3,array[indice].apellido);
			  break;
		case 3:
            utn_getFloat("\t\tIngrese el salario del Empleado: ","\tError\t",0,20,1000,10000000,3,&salario);
            array[indice].salario=salario;

				break;
		case 4:
            utn_getNumero(&sector,"\tIngrese el sector del Empleado\t","\tError\t",1,3,3);
            array[indice].sector=sector;
			  break;
		case 5:
			   utn_getName("\n\tIngrese el nombre del Empleado : ","\nError",1,51,3,array[indice].nombre);
			            utn_getName("\n\tIngrese el apellido del Empleado : ","\nError",1,51,3,array[indice].apellido);
			            utn_getFloat("\n\tIngrese el salario del Empleado: ","\tError\t",0,20,1000,10000000,3,&salario);
			                    utn_getNumero(&sector,"\n\tIngrese el sector del Empleado\t","\tError\t",1,3,3);
			                               array[indice].sector=sector;
			                               array[indice].salario=salario;

			break;

			retorno=0;
		}
	}
	else
		{
			printf("\nID NO ENCONTRADO\n");
		}
return retorno;}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int imprimirEmpleado(eEmpleado array[],int size)
{
	int retorno=-1;
	    int i;
	    if(array!=NULL && size>=0)
	    {
	        for(i=0;i<size;i++)
	        {
	            if(array[i].esVacio==1)
	                continue;
	            else
	            	printf("\tID:[ %d ]\t\nNombre del Empleado:[ %s ]\t\nApellido del Empleado :[ %s ]\t\nSector del Empleado :[ %d ]\t\nSalario del Empleado :[ %.2f ]",array[i].id,array[i].nombre,array[i].apellido,array[i].sector,array[i].salario);

	        }
	        retorno=0;
	    }
		else
			{
				printf("\nID NO ENCONTRADO\n");
			}
	    return retorno;


}
//int imprimirPrestamosDelCliente(eCliente array2[],int size2,ePrestamo array[],int size)
int funcionImprimir(eEmpleado array[], int size)
{
	int retorno = -1;
	int opcion = 0;
	int orden;
	if (array != NULL && size >0)
	{
		while (opcion != 3)
		{
			utn_getNumero(&opcion,"\t\n1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector\t\n2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n\n\t3-Salir","\nError\n",1,3,3);
			switch(opcion)
			{
			case 1:
				utn_getNumero(&orden,"\t\nOrdenar por apellido:\n\t1-Ascendente \n\t2-Descendente\nSeleccione la opción:","\nError\n",1,2,3);
				ordenamientoEmpleados(array,size,orden);
				imprimirEmpleado(array,size);
				break;
			case 2:
				informesSalarios(array,size);
				break;
			case 3:
				printf("\n\tFin de Informes\t\n");
				break;
			}
		}
		retorno = 0;
	}
	else
		{
			printf("\nID NO ENCONTRADO\n");
		}
	return retorno;
}


int ordenamientoEmpleados(eEmpleado array[], int size, int orden)
{
	int retorno = -1;

	eEmpleado estructuraAuxiliar;

	if(array!= NULL && size>0 && orden>0)
	{

		switch(orden)
		{

		case 1:
			for(int i=0; i<size - 1; i++)
			{  if(array[i].esVacio==1)
	                continue;
			else{
				for(int j=i+1; j<size; j++)
				{
					if(strcmp(array[j].apellido, array[i].apellido) < 0)
					{
						estructuraAuxiliar = array[i];
						array[i] = array[j];
						array[j] = estructuraAuxiliar;
					}
					else if(strcmp(array[j].apellido, array[i].apellido) == 0 && array[j].sector < array[i].sector)
					{
						estructuraAuxiliar = array[i];
						array[i] = array[j];
						array[j] = estructuraAuxiliar;
					}
				}
			}}
			retorno = 0;
			break;


			case 2:
			for(int i = 0; i < size - 1; i++)
			{if(array[i].esVacio==1)
                continue;
		else{
				for(int j = i + 1; j < size; j++)
				{
					if(strcmp(array[j].apellido, array[i].apellido) > 0)
					{
						estructuraAuxiliar = array[i];
						array[i] = array[j];
						array[j] = estructuraAuxiliar;
					}
					else if(strcmp(array[j].apellido, array[i].apellido) == 0 && array[j].sector > array[i].sector)
					{
						estructuraAuxiliar = array[i];
						array[i] = array[j];
						array[j] = estructuraAuxiliar;
					}
				}
			}}
			retorno = 0;
			break;
		}
	}

return retorno;	}
int informesSalarios(eEmpleado array[], int size)
{
	int retorno = -1;
	int i;
	int contador =0;
	float acumulador = 0;
	float promedioSalarios = 0;
	int empleadosSuperan = 0;

	if(array!=NULL && size>0)
	{
		for(i=0;i<size;i++)
		{
			if(array[i].esVacio == 0)
			{
				contador++;
				acumulador = acumulador + array[i].salario;
			}
		}

		promedioSalarios = acumulador/contador;

		for (i=0; i<size; i++)
		{
			if(array[i].esVacio == 0 && array[i].salario >promedioSalarios)
			{
				empleadosSuperan++;
			}
		}

		    printf("\n\tEl total de los salarios son: [%.2f] ", acumulador);
		    printf("\n\tPromedio de los salarios: : [%.2f] ", promedioSalarios);
		    printf("\n\tEl numero de empleados que superan el promedio son: [%d] \n", empleadosSuperan);


	retorno = 0;
	}
	return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
