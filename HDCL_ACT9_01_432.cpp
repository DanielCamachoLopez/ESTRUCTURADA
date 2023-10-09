//Hector Daniel Camacho Lopez     372239                                                         //
//Ensenada, Baja California a 20 de Septiembre del 2023                                          //
//Pograma que despliega un menu que trabaja con vectores y matrices usando una libreria personal //
//Nombre de la actividad: HDCL_ACT9_01_432                                                       //

#include "daniel.h"
#define M 15
#define N 4

int main()
{
    int decision, vect[M], m, matriz[4][4];
    char cadena[30];
    do{
        printf("\n          MENU            ");
        printf("\n1) Llenar un vector aleatoriamente con 15 numeros del 100 al 200 sin repetir");
        printf("\n2) LLenar matriz 4x4 con numeros aleatorios del 1 al 16 sin repetir");
        printf("\n3) Imprimir el vector de 15 numeros");
        printf("\n4) Imprimir la matriz de 4x4");
        printf("\n5) Ordenar el vector de 15 numeros");
        printf("\n6) Buscar un valor especifico en el vector de 15 numeros");
        printf("\n0) SALIR");
        printf("\nCual de las acciones anteriores deseas realizar? Ingresa el numero correspondiente: ");
        scanf("%d", &decision);
        switch(decision)
        {
            case 1:
                printf("\nHas escogido la opcion 1");
                llenar_vect_aleatorio(vect, M, 100, 200);
                break;

            case 2:
                printf("\nHas escogido la opcion 2");
                llenar_matriz(matriz, M+1, 0, 16);
                break;
            
            case 3:
                printf("\nHas escogido la opcion 3");
                imprimir_vect(vect, M);
                break;
            
            case 4:
                printf("\nHas escogido la opcion 4");
                imprimir_mat(matriz, M-11, N);
                break;

            case 5:
                printf("\nHas escogido la opcion 5");
                ordenar(vect, M);
                break;

            case 6:
                printf("\nHas escogido la opcion 6");
                buscar (vect, M);
                break;

            case 0:
                printf("\nHAS DECIDIDO SALIR");
                break;
            
            default:
                printf("\nElige una de las opciones DENTRO del menu");

        }

    }while(decision != 0);
}