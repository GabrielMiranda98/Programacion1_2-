#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmpleados.h"
#include "utn.h"


int main(void)
{setbuf(stdout,NULL);

			eEmpleado arrayEmpleado [QTY_EMPLEADO];
			inicializarEmpleado(arrayEmpleado,QTY_EMPLEADO);

	/*	 hardcodeEmpleado (arrayEmpleado,QTY_EMPLEADO,1,"Gabriel","Miranda",1500,1);
		 hardcodeEmpleado (arrayEmpleado,QTY_EMPLEADO,2,"Lil","Supa",2697,2);
		 hardcodeEmpleado (arrayEmpleado,QTY_EMPLEADO,3,"Acru","One",1478,3);
	*/
	 	int idEmpleado = 0;
		int option = 0;
		int indice;
		while(option !=5)
		{
			utn_getUnsignedInt("\tMenu\t\n1-Alta de Empleado:\n2-Modificar datos de Empleado:\n3-Baja de Empleado:\n4-Informes\n5-Salir\n\tIngrese una opcion: ","\nError\n",1,sizeof(int),1,2,3,&option);
			switch(option)
			{
			case 1:
				altaEmpleado(arrayEmpleado,QTY_EMPLEADO,&idEmpleado);
				break;
			case 2:
				utn_getNumero(&indice,"\nIngrese el ID del Empleado a modificar\n","\nError\n",0,QTY_EMPLEADO,3);
				modificarEmpleado(arrayEmpleado,QTY_EMPLEADO,indice);
				break;
			case 3:
				utn_getNumero(&indice,"\nIngrese el ID del Cliente a dar de baja\n","\nError\n",0,QTY_EMPLEADO,3);
				bajaEmpleado(arrayEmpleado,QTY_EMPLEADO,indice);
				break;
			case 4:
				 funcionImprimir(arrayEmpleado,QTY_EMPLEADO);
				break;

			}
		}
		return 0;
}
