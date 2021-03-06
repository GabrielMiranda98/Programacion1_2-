#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define QTY_EMPLOYEE 4
#define NOMBRE_LEN 30
typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    int horasTrabajadas;
    int sueldo;
}Employee;


Employee* employee_new(void);

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_automaticId();


int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


/*ARRAY*/
int employee_initArray(Employee* arrayPointer[],int limit);

int employee_SearchFreeArray(Employee* arrayPointer[],int limit);

#endif // employee_H_INCLUDED
