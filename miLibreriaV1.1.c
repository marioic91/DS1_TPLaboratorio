#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miLibreriaV1.1.h"

//FUNCIONES SECUNDARIAS
void fRegistrarEmpresa(empresa empresas[],int *nE){
	printf("REGISTRAR EMPRESA %i\n",*nE+1);
	printf("CODIGO:");
    scanf("%i",&empresas[*nE].codigo);
	printf("\nNOMBRE:");
	fflush(stdin);
	fgets(empresas[*nE].nombre,20,stdin);
	fCambioString (empresas[*nE-1].nombre);
	fflush(stdin);
	printf("\nSE HA REGISTRADO CON EXITO LA EMPRESA %i\n",*nE+1);
	system("pause");
	system("cls");
	return;
}

void fMostrarEmpresas(empresa empresas[],int *nE){
	int i;
	for (i=0;i<*nE;i++){
	    printf("EMPRESA %i\n",i+1);
	    printf("CODIGO: %i",empresas[i].codigo);
	    printf("\nNOMBRE: %s\n",empresas[i].nombre);
	    printf("\n");
	    system("pause");
	    system("cls");
	}
	return;
}
void fModificarEmpresa(empresa empresas[],int *nE){
	int i,codigo;
	printf("INGRESAR CODIGO DE EMPRESA\n");
	scanf("%i",&codigo);
	for (i=0;i<*nE;i++){
	    if(codigo==empresas[i].codigo){
	    	printf("NUEVO NOMBRE:");
	        fflush(stdin);
	        fgets(empresas[i].nombre,20,stdin);
	        fCambioString (empresas[i].nombre);
	        fflush(stdin);
	        system("cls");
		}
	}
	return;
}

void fCambioString (char *palabra){
	int i;
	int n=strlen(palabra);
	for (i=0;i<n;i++){
		if (*(palabra+i)=='\n'){
			*(palabra+i)='\0';
		}
	}
	return;
}

void fRegistrarPersonal(empleado personal[],int *nP){
	printf("REGISTRAR EMPLEADO %i\n",*nP+1);
	printf("\nLEGAJO:");
	scanf("%i",&personal[*nP].legajo);
	printf("\nNOMBRE COMPLETO:");
	fflush(stdin);
	fgets(personal[*nP].nombre,20,stdin);
	fCambioString (personal[*nP].nombre);
	printf("\nDNI:");
	scanf("%li",&personal[*nP].DNI);
	printf("\nFECHA DE NACIMIENTO (DIA/MES/AÑO):");
	scanf("%i %i %i",&personal[*nP].fechaNacimiento.dia,&personal[*nP].fechaNacimiento.mes,&personal[*nP].fechaNacimiento.ano);
	printf("\nCARGO:");
	fflush(stdin);
	fgets(personal[*nP].cargo,20,stdin);
	fCambioString (personal[*nP].cargo);
	fflush(stdin);
	printf("\nFECHA DE INGRESO (DIA/MES/AÑO):");
	scanf("%i %i %i",&personal[*nP].fechaIngreso.dia,&personal[*nP].fechaIngreso.mes,&personal[*nP].fechaIngreso.ano);
	printf("\nSE HA REGISTRADO CON EXITO EL EMPLEADO %i\n",*nP+1);
	system("pause");
	system("cls");
	return;
}

void fMostrarPersonal(empleado personal[],int *nP){
	int i;
	for (i=0;i<*nP;i++){
	    printf("EMPLEADO %i\n",i+1);
	    printf("\nLEGAJO: %i",personal[i].legajo);
	    printf("\nNOMBRE COMPLETO: %s",personal[i].nombre);
	    printf("\nDNI: %li",personal[i].DNI);
	    printf("\nFECHA DE NACIMIENTO (DIA/MES/AÑO): %i/%i/%i",personal[i].fechaNacimiento.dia,personal[i].fechaNacimiento.mes,personal[i].fechaNacimiento.ano);
	    printf("\nCARGO: %s",personal[i].cargo);
	    printf("\nFECHA DE INGRESO (DIA/MES/AÑO): %i/%i/%i\n",personal[i].fechaIngreso.dia,personal[i].fechaIngreso.mes,personal[i].fechaIngreso.ano);
	    system("pause");
	    system("cls");
	}
}

void fModificarPersonal(empleado personal[],int *nP){
	int i,codigo;
	printf("INGRESAR LEGAJO DE EMPLEADO\n");
	scanf("%i",&codigo);
	for (i=0;i<*nP;i++){
	    if(codigo==personal[i].legajo){
	    	printf("NUEVO LEGAJO:");
	        scanf("%i",&personal[i].legajo);
	        printf("\nNUEVO NOMBRE COMPLETO:");
	        fflush(stdin);
	        fgets(personal[i].nombre,20,stdin);
	        fCambioString (personal[i].nombre);
	        printf("\nNUEVO DNI:");
	        scanf("%li",&personal[i].DNI);
	        printf("\nNUEVA FECHA DE NACIMIENTO (DIA/MES/AÑO):");
	        scanf("%i %i %i",&personal[i].fechaNacimiento.dia,&personal[i].fechaNacimiento.mes,&personal[i].fechaNacimiento.ano);
	        printf("\nNUEVO CARGO:");
	        fflush(stdin);
	        fgets(personal[i].cargo,20,stdin);
	        fCambioString (personal[i].cargo);
	        fflush(stdin);
	        printf("\nNUEVA FECHA DE INGRESO (DIA/MES/AÑO):");
	        scanf("%i %i %i",&personal[i].fechaIngreso.dia,&personal[i].fechaIngreso.mes,&personal[i].fechaIngreso.ano);
	        printf("\n");
	        system("PAUSE");
		}
	}
	return;
}

void fAsignarMemoriaE (empresa *empresas, int *nE){
	empresas=(empresa*)realloc(empresas,*nE+1*sizeof(empresa));
	if (empresas==NULL){
		printf ("NO SE HA RESERVADO ESPACIO EN LA MEMORIA!\n");
		exit(1);
	}
	return;
}

void fAsignarMemoriaP (empleado *personal, int *nP){
	personal=(empleado*)realloc(personal,*nP+1*sizeof(empleado));
	if (personal==NULL){
		printf ("NO SE HA RESERVADO ESPACIO EN LA MEMORIA!\n");
		exit(1);
	}
	return;
}
