//Hector Daniel Camacho Lopez     372239                                                     //
//Ensenada, Baja California a 20 de Septiembre del 2023                                      //
//Libreria                                                                                   //
//Nombre de la actividad: HDCL_ACT9_01_432                                                   //

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define M 15
#define N 4

// PROTOTIPOS DE FUNCIONES //

void mayusculas(char cadena[60]);
void minusculas(char cadena[60]);
void capital(char cadena[60]);
int tamaño(char cadena[60]);
void voltear(char cadena[60]);
void noespacios(char cadena[60]);
char permitir(char cadena[60]);
void todas(char cadena[60]);
void palindromo(char cadena[]);

int valida_num(int ri, int rf);
bool no_repetir(int vect[], int n);
void llenar_vect_aleatorio(int vect[], int m, int ri, int rf);
void llenar_matriz(int matriz[4][4], int m, int ri, int rf);
void imprimir_mat(int matriz[4][4], int m, int n);
void imprimir_vect(int vect[], int m);
bool no_repetir_m(int matriz[4][4],int n);
void ordenar(int vect[], int m);
int busq_sec(int vect[], int n, int num);
void buscar (int vect[], int m);


          
// FUNCION DE MAYUSCULAS //
void mayusculas(char cadena[60])
{
    int i;
    printf("\n");
    for(i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 97)
        {
            if (cadena[i] <= 122)
            {
                cadena[i] = cadena[i] - 32;
                printf("%c" ,cadena[i]);
            }
        }
    }
}

// FUNCION DE MINUSCULAS //
void minusculas(char cadena[60])
{
    int i;
    printf("\n");
    for(i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 65)
        {
            if (cadena[i] <= 90)
            {
                cadena[i] = cadena[i] + 32;
                printf("%c" ,cadena[i]);
            }
        }
    }
}

// FUNCION QUE CONVIERTE CADENA EN "CAPITAL" //
void capital(char cadena[60])
{
    int i;
    printf("\n");
    cadena[0] = 67;
    cadena[1] = 65;
    cadena[2] = 80;
    cadena[3] = 73;
    cadena[4] = 84;
    cadena[5] = 65;
    cadena[6] = 76;
    cadena[7] = '\0';
    for(i = 0; cadena[i] != '\0'; i++)
    {
        printf("%c", cadena[i]);
    }
}

// FUNCION QUE CUENTA LOS CARACTERES DE LA CADENA //
int tamaño(char cadena[60])
{
    printf("\n");
    int i;
    for(i = 0; cadena[i] != '\0'; i++);
    return i;
}

// FUNCION QUE VOLTEA LA CADENA AL REVES //
void voltear(char cadena[60])
{
    int i, t;
    printf("\n");
    t = tamaño(cadena);
    for (i = t-1; i >= 0; i--)
    {
        printf("%c", cadena[i]);
    }
}

// FUNCION QUE ELIMINA LOS ESPACIOS DE LA CADENA //
void noespacios(char cadena[60])
{
    int i, t, aux, espacio;
    printf("\n");
    t = tamaño(cadena);
    for(i = 0; i < t; i++)
    {
        if (cadena[i] == 32)
        {
            espacio = i;
            aux = i;
            while (cadena[aux] == 32 && aux < t - 1)
            aux ++;
            cadena[espacio] = cadena[aux];
            cadena[aux] = 32;
        }
    }
    
    for(i = 0; cadena[i] != '\0'; i++)
    {
        printf("%c", cadena[i]);
    }
}

// FUNCION QUE PERMITE O NO LA CADENA //
char permitir(char cadena[60])
{
    int i, t;
    t = tamaño(cadena);
    printf("\n");
    for(i = 0; cadena[i] != '\0'; i++)
    {

    if (cadena[0] == ' ' || cadena[t] == ' ')
    {
        printf("\nNO PERMITIDA, debe ser una cadenas sin espacios al inicio ni al final");
        cadena[i] = '\0';
    }
    
    if (cadena[i] == 32 && cadena[i-1] == 32)
    {
        printf("NO PERMITIDO, debe ser cadena sin espacios dobles");
        cadena[i] = '\0';
    }

    if (cadena[i] != 32 && (cadena[i] < 65 || cadena[i] > 122))
    {printf("\nNO PERMITIDO, solo caracteres alfabeticos");
        cadena[i] = '\0';
    }

    }printf("\n");
    for(i = 0; cadena[i] != '\0'; i++)
    {
        printf("%c", cadena[i]);
    }
    return cadena[60];

}

// FUNCION QUE REALIZA 5 ACCIONES DE LAS FUNCIONES ANTERIORES //
void todas(char cadena[60])
{
    int i;
    char original[60], original2[60], original3[60], original4[60];
    for (i = 0; cadena[i] != '\0'; i++)
    {
        original[i] = cadena[i];
        original2[i] = cadena[i];
        original3[i] = cadena[i];
        original4[i] = cadena[i];
    }
    noespacios(cadena);
    mayusculas(original);
    minusculas(original2);
    voltear(original3);
    capital(original4);

}

 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////FUNCIONES NUEVAS/////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////      

// FUNCION QUE VALIDA NUMEROS //
int valida_num(int ri, int rf)
{
    int n;
    char xnum[30];
    printf("\nDame un numero entre el %d y %d: ", ri, rf);
    scanf("%c", &xnum);
    fflush(stdin);
    gets(xnum);
    n = atoi(xnum);
    if (n > rf)
    {
        printf("\nNUMERO FUERA DE RANGO");
        n = 70;
    }
    
    if (n < ri)
    {
        printf("\nNUMERO MUY PEQUEÑO PARA EL RANGO");
        n = 30;
    }

    return n;
}

// FUNCION QUE EVITA NUMEROS REPETIDOS EN VECTOR //
bool no_repetir(int vect[],int n)
{
    int i;
    for (i = 0; i < 15; i++)
    {
        if (n == vect[i])
        {
            return true;
        }            
    }
    return false;
}

// FUNCION QUE LLENA VECTOR ALEATORIAMENTE //
void llenar_vect_aleatorio(int vect[], int m, int ri, int rf)
{
    int rango, i, n;
    rango = (rf - ri) + 1;
    srand(time(NULL)); 
    for(i = 0; i < m; i++)
    {
        do
        {
            n = (rand()%rango) + ri;
        } while (no_repetir(vect, n));
        vect[i] = n;  
    }
}

// FUNCION QUE LLENA MATRIZ DE FORMA ALEATORIA //
void llenar_matriz(int matriz[4][4], int m, int ri, int rf)
{
    int rango, i, n, j;
    rango = (rf - ri) + 1;
    srand(time(NULL)); 
    for(j = 0; j < 4; j++)
    {
        for(i = 0; i < 4; i++)
        {
            do{
                n = (rand()%rango) + ri;
                } while (no_repetir_m(matriz, n));
        matriz[j][i] = n;  
        }
    }
}

// FUNCION QUE IMPRIME LA MATRIZ //
void imprimir_mat(int matriz[4][4], int m, int n)
{
    printf("\nMATRIZ");
    int j, i;
    printf("\n");
    for (j = 0; j < m; j++)
    {
        printf("\n[");
        for(i = 0; i < n; i++)
        {
            printf("%d, ", matriz[j][i]);
        }
        printf("]");
    }
    printf("\n");

}

// FUNCION QUE IMPRIME VECTOR //
void imprimir_vect(int vect[], int m)
{
    int i;
    printf("\nVECTOR");
    printf("\n[");
    for (i = 0; i < m; i++)
    {
        printf("%d, ", vect[i]);
    }
    printf("]");
    printf("\n");
}

// FUNCION QUE EVITA NUMEROS REPETIDOS EN MATRIZ //
bool no_repetir_m(int matriz[4][4],int n)
{
    int i, j;
    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 4; i++)
        {
            if (n == matriz[j][i])
            {
                return true;
            }    
        }        
    }
    return false;
}

// FUNCION QUE ORDENA EL VECTOR //
void ordenar(int vect[], int m)
{
    int temp, i, j;
    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (vect[j] < vect[i])
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }

    printf("\nVECTOR ORDENADO");
    printf("\n[");
    for (i = 0; i < m; i++)
    {
        printf("%d, ", vect[i]);
    }
    printf("]");
    printf("\n");
}

// FUNCION PARA BUSQUEDA SECUENCIA //
int busq_sec(int vect[], int n, int num)
{
    int i;
    n = num;
    for (i = 0; i < n; i++)
    {
        if(num == vect[i])
        {
            return i;
        }
    }
    return -1;
}

// FUNCION PARA BUSCAR NUMERO //
void buscar (int vect[], int m)
{
    int num, x, i;
    num = valida_num(100, 200);
    x = busq_sec(vect, M, num);
    if (x != -1)
    {
        printf("\nSi existe");
        printf("\n%d esta en el indice %d", num, x);
    }
    else
    {
        printf("\nNo existe");
    }
}