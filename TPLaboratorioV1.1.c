//TP INTEGRAL DE LABORATORIO (DS I - TUDS)
//MARIO IVAN CARREÑO REYES - MU N°129
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miLibreriaV1.1.h"

empresa *empresas;
empleado *personal;

int main(){
	int opc,nE=0,nP=0;
	empresas=(empresa*)calloc(nE+2,sizeof(empresa));
	if (empresas==NULL){
	printf ("NO SE HA RESERVADO ESPACIO EN LA MEMORIA!\n");
	exit(1);
	}
	personal=(empleado*)calloc(nP+2,sizeof(empleado));
	if (personal==NULL){
	printf ("NO SE HA RESERVADO ESPACIO EN LA MEMORIA!\n");
	exit(1);
	}
    do{
        printf("\t Bienvenido! Elija la opcion que desea\n");
        printf("\n1-Registrar Empresa");
        printf("\n2-Registrar Personal");
        printf("\n3-Modificar datos de la Empresa");
        printf("\n4-Modificar datos del Personal");
        printf("\n5-Mostrar lista de Empresas");
        printf("\n6-Mostrar listas de personal");
        printf("\n7-Finalizar ejecucion\n");
        fflush(stdin);
        scanf("%i",&opc);
        system("cls");
        switch(opc){
            case 1: if(nE>1){
			    	fAsignarMemoriaE(empresas,&nE);
	                }
	            fRegistrarEmpresa(empresas,&nE);nE++;break;
            case 2: if(nP>1){
			    	fAsignarMemoriaP(personal,&nP);
	                }
			    fRegistrarPersonal(personal,&nP);nP++;break;
			    
            case 3: fModificarEmpresa(empresas,&nE);break;
            case 4: fModificarPersonal(personal,&nP);break;
            case 5: fMostrarEmpresas(empresas,&nE);break;
            case 6: fMostrarPersonal(personal,&nP);break;
            case 7: printf("ADIOS!");break;
            default: printf("INGRESO UNA OPCION INCORRECTA!");
        }
    }while(opc != 7);
    free(empresas);
    free(personal);
    return 0;
}
