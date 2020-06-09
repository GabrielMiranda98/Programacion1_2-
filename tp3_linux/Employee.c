#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"


Employee* employee_new(void)
{		Employee* auxP;

	auxP=(Employee*)malloc(sizeof(Employee));

	return auxP;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
	Employee* auxP=NULL;
		auxP=employee_new();
		int idAux;
		int horasTrabajadasAux;
		int sueldoAux;
		  if(auxP!=NULL)
		  {
			  idAux = atoi(idStr);
			  horasTrabajadasAux = atoi(horasTrabajadasStr);
			  sueldoAux = atoi(sueldo);

			  auxP->id=idAux;
			  strcpy(auxP->nombre,nombreStr);
			  auxP->horasTrabajadas=horasTrabajadasAux;
			  auxP->sueldo=sueldoAux;

		  }
		  return auxP;
		}

int employee_delete(Employee* this)
{	int retorno=-1;

	if(this!=NULL)
	{retorno=0;
		free(this);
	}
	return retorno;
}

static int contadorID = 1;

int employee_automaticId()
{
	return contadorID++;
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;

		if(this!=NULL && id>=0)
		{
			this->id = id;
			retorno = 0;
		}
		return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

		if(this!=NULL && id>=0)
		{
			*id = this->id;
			retorno = 0;
		}
		return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL&& isValidName(nombre)==1)
	{
		strncpy(this->nombre,nombre,NOMBRE_LEN);
	}

	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL&&nombre!=NULL)
	{
		retorno=0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

		if(this!=NULL && horasTrabajadas>0)
		{
			this->horasTrabajadas=horasTrabajadas;
			retorno = 0;
		}

		return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

			if(this!=NULL && horasTrabajadas>0)
			{
				*horasTrabajadas = this->id;
				retorno = 0;
			}
			return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this!=NULL && sueldo>0)
	{
		this->sueldo=sueldo;
		retorno = 0;
	}

	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this!=NULL && sueldo>0)
	{
		*sueldo = this->id;
		retorno = 0;
	}
	return retorno;
}

int employeeSortById(void* empleadoA, void* empleadoB){
    int retorno = -1;
    int id1;
    int id2;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        employee_getId(empA,&id1);
        employee_getId(empB,&id2);


        if(( id1)<(id2)){
            retorno = 1 ;
        }else if((id1)>(id2)){
            retorno = -1 ;
        }else if((id1)==(id2)){
            retorno = 0;
        }
    }
    return retorno;
}

int employeeSortByName(void* empleadoA, void* empleadoB){
    int retorno = -1;
    char n1[50];
    char n2[50];

    Employee* empA;
    Employee* empB;


    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        employee_getNombre(empA,n1);
         employee_getNombre(empB,n2);



        retorno = strcmp(n2, n1);
    }

    return retorno;
}

int employeeSortByHours(void* empleadoA, void* empleadoB){
    int retorno = -1;
    int h1;
    int h2;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
           employee_getHorasTrabajadas(empA,&h1);
           employee_getHorasTrabajadas(empB,&h2);
                if((h1)<(h2)){
            retorno = 1 ;
        }else if((h1)>(h2)){
            retorno = -1 ;
        }else if((h1)==(h2)){
            retorno = 0;
        }
    }
    return retorno;
}

int employeeSortBySalary(void* empleadoA, void* empleadoB){
    int retorno = -1;
    int s1;
    int s2;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        employee_getSueldo(empA,&s1);
        employee_getSueldo(empB,&s2);
        if((s1)<(s2)){
            retorno = 1 ;
        }else if((s1)>(s2)){
            retorno = -1 ;
        }else if((s1)==(s2)){
            retorno = 0;
        }
    }
    return retorno;
}
