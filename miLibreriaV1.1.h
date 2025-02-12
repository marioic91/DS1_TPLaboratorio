#ifndef MILIBRERIAV1.1_H
#define MILIBRERIAV1.1_H

//ESTRUCTURAS
typedef struct fecha{
    int dia;
    int mes;
    int ano;
}fecha;

typedef struct empleado{
    int legajo;
    char nombre[20];
    long int DNI;
    fecha fechaNacimiento;
    char cargo[20];
    fecha fechaIngreso;
}empleado;

typedef struct empresa{
 int codigo;
 char nombre[20];
}empresa;

//FUNCIONES SECUNDARIAS
void fRegistrarEmpresa(empresa empresas[],int *nE);
void fCambioString (char *palabra);
void fMostrarEmpresas(empresa empresas[],int *nE);
void fModificarEmpresa(empresa empresas[],int *nE);
void fAsignarMemoriaE(empresa *empresas, int *nE);
void fAsignarMemoriaP(empleado *personal, int *nP);
void fRegistrarPersonal(empleado personal[],int *nP);
void fMostrarPersonal(empleado personal[],int *nP);
void fModificarPersonal(empleado personal[],int *nP);

#endif
