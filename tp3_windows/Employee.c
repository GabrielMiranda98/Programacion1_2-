#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"


Employee* employee_new(void)
{
	return (Employee*)malloc(sizeof(Employee));
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
		  return 0;
		}
void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

//INICIO				 GETTER AND SETTER

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

//FIN 					  GETTER AND SETTER
//FUNCIONES ARRAY
int employee_initArray(Employee* arrayPointer[],int limit)
{
	int retorno=-1;
	int i;
	if(arrayPointer!=NULL && limit>0)
	{
		retorno=0;
		for(i=0;i<limit;i++)
		{
			arrayPointer[i]=NULL;
		}
	}

	return retorno;
}

int employee_SearchFreeArray(Employee* arrayPointer[],int limit)
{
	int retorno=-1;
	int i;
	if(arrayPointer!=NULL && limit>0)
	{
		retorno=-2;
		for(i=0;i<limit;i++)
		{
			if(arrayPointer[i]==NULL)
			{
				retorno=i;
				break;
			}
		}
	}

	return retorno;

}


int employee_deleteIndexInArray(Employee* arrayPointer[],int indice)
{
	int retorno=-1;
	if(arrayPointer!=NULL && indice>=0&&arrayPointer[indice]!=NULL)
	{
		retorno=0;
		free(arrayPointer[indice]);
		arrayPointer[indice]=NULL;

	}
	return retorno;
}
int employee_searchForIdArray(Employee* arrayPointer[],int size, int id)
{
	int retorno=-1;
	int i;
	if(arrayPointer!=NULL&&size>0&&id>=0)
	{
		retorno=-2;
		for(i=0;i<size;i++)
		{
			if(arrayPointer[i]!=NULL && arrayPointer[i]->id==id)
			{
				retorno=i;
				break;
			}
		}
	}

	return retorno;

}
int employee_deleteForIdArray()
{
	int retorno=-1;
	return retorno;

}
