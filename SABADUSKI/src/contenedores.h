
#ifndef CONTENEDORES_H_
#define CONTENEDORES_H_
#define QTY_CONTENEDORES 3

typedef struct
{
    char nombre[50];
    int peso;
    int capacidad;
    int isEmpty;
    int idContenedor;
    int dia;
    int mes;
    int anio ;
}eContenedor;

int inicializarPeso(eContenedor array[],int size);
void hardcodeContenedores (eContenedor array[],int size);
int inicializarContenedores(eContenedor array[],int size);
int imprimirContenedores(eContenedor array[],int size);

#endif /* CONTENEDORES_H_ */
