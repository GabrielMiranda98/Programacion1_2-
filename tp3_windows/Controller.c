#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
int controller_menu()
{
    int option = -1;
        printf("\n\t -Trabajo Practico N°3: LinkedList- \n\t\tGabriel Miranda \n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). \n");
        printf("3. Alta de empleado \n");
        printf("4. Modificar datos de empleado \n");
        printf("5. Baja de empleado \n");
        printf("6. Listar empleados \n");
        printf("7. Ordenar empleados \n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario). \n");
        printf("10. Salir \n");
        utn_getNumero(&option,"\nIngrese una opcion:\n"
        	    			,"\nERROR ingrese una opcion valida\n",1,10,3);

        return option;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
		Employee* auxP;
		int retorno=-1;
		int auxId=0;
		char auxN[40];
		int auxS;
		int auxH;
		char idStr[10], nombreStr[100], horasStr[9], sueldoStr[20];
		if(pArrayListEmployee != NULL)
			{
				auxP= employee_new();

				utn_getName("\nIngrese el nombre del empleado:\n","\nError\n",0,30,3,auxN);
				utn_getUnsignedInt("\nIngrese las horas trabajadas:","\nError",1,50,1,5000,3,&auxH);
				utn_getUnsignedInt("\nIngrese el sueldo:","\nError",1,30,1,100000,3,&auxS);
				auxId=employee_automaticId();


					itoa(auxH, horasStr, 10);
					itoa(auxS, sueldoStr, 10);
					itoa(auxId, idStr, 10);
					strcpy(nombreStr,auxN);
					auxP = employee_newParametros(idStr, nombreStr, horasStr, sueldoStr);

					if(!ll_add(pArrayListEmployee,auxP))
					{
						printf("\tID\t\tNOMBRE\t\tHORAS TRABAJADAS\t\tSUELDO\n");
						printf("%10s %19s %20s %25s\n",idStr,nombreStr,horasStr,sueldoStr);
						retorno = 0;
						printf("\nALTA EXITOSA\n");

					}
					else
					{
						printf("\nALTA DENEGADA\n");
					}

				}
				else
				{
					printf("\nERROR\n");
				}

		  return retorno;	}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

		int idM;
	    int option;
	    int seguir = 2; // y 1 n 2
	    Employee* this;
	    char auxN[128];
	    int auxH;
	    int auxS;

	    printf("Ingrese ID de empleadx a modificar: ");
	    scanf("%d", &idM);
	    for(int i=0; i<ll_len(pArrayListEmployee); i++){
	        this = (Employee*) ll_get(pArrayListEmployee, i);
	        if(idM == this->id){
	            printf("\n  Id\t    Nombre\t  Horas trabajadas\tSueldo\n");
	            printf("%4d%14s\t\t%d\t\t%6d\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);

	        do{

	            utn_getNumero(&option,"\nIngrese dato a modificar:\n1- Nombre\n2- Horas trabajadas\n3- Sueldo\n4- Cancelar \n",
	            		"\nERROR OPCION NO VALIDA\n",1,4,3);

	            switch(option){

	            case 1:
					utn_getName("\nIngrese el nombre del empleado:\n","\nError\n",0,30,3,auxN);

	                employee_setNombre(this, auxN);
	                printf("Desea continuar modificando al mismo empleado? ");
	                utn_getNumero(&seguir,"\nDesea seguir modificando al mismo empleado? 1-SI \t2-NO/n: \n",
	             	            		"\nERROR OPCION NO VALIDA\n",1,2,3);
	                if(seguir == 2){
	                    return 0;
	                }
	                break;
	            case 2:
					utn_getUnsignedInt("\nIngrese las horas trabajadas:","\nError",1,50,1,5000,3,&auxH);
	                employee_setHorasTrabajadas(this, auxH);
	                utn_getNumero(&seguir,"\nDesea seguir modificando al mismo empleado? 1-SI \t2-NO/n: \n",
	             	            		"\nERROR OPCION NO VALIDA\n",1,2,3);
	                if(seguir == 2){
	                    return 0;
	                }
	                break;
	            case 3:
					utn_getUnsignedInt("\nIngrese el sueldo:","\nError",1,30,1,100000,3,&auxS);
	            	employee_setSueldo(this, auxS);
	                utn_getNumero(&seguir,"\nDesea seguir modificando al mismo empleado? 1-SI \t2-NO/n: \n",
	             	            		"\nERROR OPCION NO VALIDA\n",1,2,3);
	                if(seguir == 2){
	                    return 0;
	                }
	                break;
	            case 4:
	                printf("Modificacion cancelada\n");
	                return 1;
	                break;
	            }
	        }while(seguir == 1);
	        }
	    }
	    printf("\nNo se ha encontrado empleado\n");
	    return -1;


}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	    int retorno = -1;
	    int i;
	    Employee* this;
	    if((ll_len(pArrayListEmployee))>0){
	    	printf("\tID\t\tNOMBRE\t\tHORAS TRABAJADAS\t\tSUELDO\n");
	        for(i=0; i<ll_len(pArrayListEmployee); i++){
	            this = ll_get(pArrayListEmployee, i);  //NO ME LO CARGA
	            printf("\n1\n");
	            if(this != NULL){
	            	printf("\n2\n");
	            	printf("%10d %19s %20d %25d\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
	            }
	            else
	            {
	            	printf("\nTHIULO\n");
	            }
	        }
	    }else{
	    	printf("\nNO HAY NADA PARA MOSTRAR\n");
	    }
	    return retorno;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

