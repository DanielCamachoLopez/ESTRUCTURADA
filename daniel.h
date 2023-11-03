//Hector Daniel Camacho Lopez     372239                                                     //
//Ensenada, Baja California a 31 de Octubre del 2023                                         //
//Libreria                                                                                   //
//Nombre de la actividad: HDCL_ACT11_CURP_432                                                //

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#define M 15
#define N 4
#define AMINI 1900
#define AMAXI 2023

char malas[82][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", 
                    "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", 
                    "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO",
                    "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "TOPO", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA",
                    "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};

char abrev[34][3] =  {"NO","AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL",
                    "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "NE"};


//PROTOTIPOS DE FUNCIONES //
void mayusculas(char cadena[60]);
void entero_cad(int n, char cadena[]);
int valida_num(int ri, int rf, char msge[]);
int tamaño(char cadena[60]);
void noespacios(char cadena[60]);
void descomp(char cadena[30]);
void capital(char cadena[60]);
void voltear(char cadena[60]);
char permitir(char cadena[60]);
void todas(char cadena[60]);
void minusculas(char cadena[60]);
bool no_repetir(int vect[], int n);
void llenar_vect_aleatorio(int vect[], int m, int ri, int rf);
void llenar_matriz(int matriz[4][4], int m, int ri, int rf);
void imprimir_mat(int matriz[4][4], int m, int n);
void imprimir_vect(int vect[], int m);
bool no_repetir_m(int matriz[4][4],int n);
void ordenar(int vect[], int m);
int busq_sec(int vect[], int n, int num);
void buscar (int vect[], int m);
char gene_curp(char nombre[], char appat[], char apmat[], int año, int mes, int dia, int sexo, int estado);



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
            }
        }
    }
}

//FUNCION PARA PASAR DE ENTEROS A CADENA //
void entero_cad(int n, char cadena[])
{
    int digits = 0;
    int aux = n;
    while(aux > 0)
    {
        aux = aux / 10;
        digits++;
    }

    cadena[digits]= '\0';
    aux = n;
    int pos = digits - 1, dig;
    while(pos >= 0)
    {
        dig = aux%10;
        aux = aux/10;
        cadena[pos] = dig + '0';
        pos--;
    }
}

//FUNCION QUE VALIDA NUMEROS //
int valida_num(int ri, int rf, char msge[])
{
    char xnum[30];
    int n;
    do
    {
        puts(msge);
        fflush(stdin);
        gets(xnum);
        n = atoi(xnum);
    } while (n < ri || n > rf);
    return n;
}

// FUNCION QUE CUENTA LOS CARACTERES DE LA CADENA //
int tamaño(char cadena[60])
{
    printf("\n");
    int i;
    for(i = 0; cadena[i] != '\0'; i++);
    return i;
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

// FUNCION QUE DESCOMPONE LOS NOMBRES COMPUESTOS //
void descomp(char cadena[30])
{
    int i, j, tamaño, tampal, comp, z;
    char palabra[20];
    char nuevo[30];
    char malas[19][4] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "Y", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON"};
    i = 0;
    j = 0;
    z = 0;
    comp = 0;
    tampal = 0;
    tamaño = strlen(cadena);
    while(i < tamaño)
    {
        tampal = 0;
        while(i < tamaño && cadena[i] != ' ')
        {
            tampal;
            i++;
        }
        strncpy(palabra, &cadena[i - tampal], tampal);
        palabra[tampal] = '\0';

        for (z = 0; z < 19; z++)
        {
            if(strcmp(palabra, malas[z]) == 0);
            {
                comp = 1;
                i = 19;
            }
        }

        if (!comp)
        {
            for (z = 0; z < tampal; z++)
            {
                nuevo[j] = palabra[z];
                j++;
            }
            nuevo[j] = ' ';
            j++;
        }

        while(i < tamaño && cadena[i] == ' ')
        {
            i++;
        }
    }
    nuevo[j] = '\0';
    strcpy(cadena, nuevo);
    printf(cadena);
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
    num = valida_num(100, 200, "Digita un numero");
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



// FUNCION QUE GENERA CURP RECIBIENDO PARAMETROS//
char gene_curp(char nombre[], char appat[], char apmat[], int año, int mes, int dia, int sexo, int estado)
{
    int opc, i, tam, aux, j, noestado, n, num, z, cont1, cont2;
    int matriz[82][4];
    opc = 1;
    char curp[18];
    char cuatro[4];
    char numero[2];
    char años[10];
    char dias[2];
    char sex[1];
    char abrevest[3];
    char meses[2];
    char malas[82][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", 
                          "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", 
                          "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO",
                          "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "TOPO", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA",
                          "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};

    char abrev[34][3] =  {"NO","AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL",
                         "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "NE"};



    // RECOLECCION DE DATOS //
    while (opc == 1)
    {
        fflush(stdin);
        gets(nombre);
        mayusculas(nombre);

        fflush(stdin);
        gets(appat);
        mayusculas(appat);

        fflush(stdin);
        gets(apmat);
        mayusculas(apmat);

        entero_cad(año, años);

        entero_cad(dia, dias);
        if (dia < 10)
        {
            aux = dias[0];
            dias[0] = 48;
            dias[1] = aux;
        }

        scanf("%d", &sexo);
        if (sexo == 1)
        {
            sex[0] = 'H';
        }
        else
        {
            sex[0] = 'M';
        }

        for (i = 0; i < 34; i++)
        {
            if (estado == i)
            {
                abrevest[0] = abrev[i][0];
                abrevest[1] = abrev[i][1];
            }
        }


        // GENERACION DE CURP //
        z = 0;
        tam = tamaño(appat);
        cuatro[0] = appat[0];
        for (i = 1; i < tam; i++)
        {
            if (appat[i] == 65)
            {
                cuatro[1] = appat[i];
                i = tam;
            }
            else
            {
                if (appat[i] == 69)
                {
                    cuatro[1] = appat[i];
                    i = tam;
                }
                else
                {
                    if (appat[i] == 73)
                    {
                        cuatro[2] = appat[i];
                        i = tam;
                    }
                    else
                    {
                        if (appat[i] == 79)
                        {
                            cuatro[1] = appat[i];
                            i = tam;
                        }
                        else
                        {
                            if (appat[i] == 85)
                            {
                                cuatro[1] = appat[i];
                                i = tam;
                            }
                            else  // PARA X //
                            {
                                z = 1;
                                cuatro[0] = appat[0];
                                tam = tamaño(apmat);
                                for (i = 1; i < tam; i++)
                                {
                                    if (apmat[i] == 65)
                                    {
                                        cuatro[1] = apmat[i];
                                        i = tam;
                                    }
                                    else
                                    {
                                        if (apmat[i] == 69)
                                        {
                                            cuatro[1] = apmat[i];
                                            i = tam;
                                        }
                                        else
                                        {
                                        if (apmat[i] == 73)
                                        {
                                            cuatro[2] = apmat[i];
                                            i = tam;
                                        }
                                        else
                                        {
                                            if (apmat[i] == 79)
                                            {
                                                cuatro[1] = apmat[i];
                                                 i = tam;
                                            }
                                            else
                                            {
                                            if (apmat[i] == 85)
                                            {
                                                cuatro[1] = apmat[i];
                                                i = tam;
                                            }
                                            }
                                        }
                                        }
                                    }    
                                }
                            }
                        }
                    }
                }
            }
        }
        cuatro[2] = apmat[0];
        cuatro[3] = nombre[0];
        if (z == 1)
        {
            cuatro[2] = 88;
        }

        curp[0] = cuatro[0];
        curp[1] = cuatro[1];
        curp[2] = cuatro[2];
        curp[3] = cuatro[3];

        

        for (i = 0; i < 82; i++)
        {
            if (curp[0] == malas[i][0])
            {
                if (curp[1] == malas[i][1])
                {
                    if (curp[2] == malas[i][2])
                    {
                        if (curp[3] == malas[i][3])
                        {
                            curp[1] = 'X';
                            i = 82;
                        }
                    }
                }
            }
        }    

        curp[4] = años[2];
        curp[5] = años[3];



        entero_cad(mes, meses);
        curp[6] = 48;
        curp[7] = meses[0];
        if (mes > 10)
        {
            curp[6] = 49;
            if ((mes - 10) == 0)
            {
                curp[7] = 48;
            }
            if ((mes - 10) == 1)
            {
                curp[7] = 49;
            }
            if ((mes - 10) == 2)
            {
                curp[7] = 50;
            }
        }


        curp[8] = dias[0];
        curp[9] = dias[1];
        curp[10] = sex[0];
        curp[11] = abrevest[0];
        curp[12] = abrevest[1];
        

        tam = tamaño(appat);
        for(i = 1; i < tam; i++)
        {
            if (appat[i] != 65)
            {
                if (appat[i] != 69)
                {
                    if (appat[i] != 73)
                    {
                        if (appat[i] != 79)
                        {
                            if (appat[i] != 85)
                            {
                                curp[13] = appat[i];
                                i = tam;
                                tam = tamaño(appat);
                                for (i = 0; i < tam; i++)
                                {
                                    if (appat[i] <= 65 && appat[i] >= 90)
                                    {
                                        appat[i] = 88;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (z == 1)
        {
            tam = tamaño(apmat);
            for(i = 1; i < tam; i++)
            {
                if (apmat[i] != 65)
                {
                    if (apmat[i] != 69)
                    {
                        if (apmat[i] != 73)
                        {
                            if (apmat[i] != 79)
                            {
                                if (apmat[i] != 85)
                                {
                                    curp[13] = apmat[i];
                                    curp[14] = 88;
                                    i = tam;
                                    z = 1;
                                    tam = tamaño(apmat);
                                    for (i = 0; i < tam; i++)
                                    {
                                        if (apmat[i] <= 65 && apmat[i] >= 90)
                                        {
                                            apmat[i] = 88;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        if(z != 1)
        {
        tam = tamaño(apmat);
        for(i = 1; i < tam; i++)
        {
            if (apmat[i] != 65)
            {
                if (apmat[i] != 69)
                {
                    if (apmat[i] != 73)
                    {
                        if (apmat[i] != 79)
                        {
                            if (apmat[i] != 85)
                            {
                                curp[14] = apmat[i];
                                i = tam;
                                tam = tamaño(apmat);
                                for (i = 0; i < tam; i++)
                                {
                                    if (apmat[i] <= 65 && apmat[i] >= 90)
                                    {
                                        apmat[i] = 88;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        }


        tam = tamaño(nombre);
        for(i = 1; i < tam; i++)
        {
            if (nombre[i] != 65)
            {
                if (nombre[i] != 69)
                {
                    if (nombre[i] != 73)
                    {
                        if (nombre[i] != 79)
                        {
                            if (nombre[i] != 85)
                            {
                                curp[15] = nombre[i];
                                i = tam;
                                tam = tamaño(nombre);
                                for (i = 0; i < tam; i++)
                                {
                                    if (nombre[i] <= 65 && nombre[i] >= 90)
                                    {
                                        nombre[i] = 88;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


        if (año < 1999)
        {
            n = rand()%9;
            curp[16] = 48;
        }
        else
        {
            if (año <= 2010)
            {
                curp[16] = 65;
            }
            else
            {
                if (año <= 2020)
                {
                    curp[16] = 66;
                }
                else
                {
                    if (año <= 2030)
                    {
                        curp[16] = 67;
                    }
                }
            }
        }
             
        num = rand()%9;
        entero_cad(num, numero);
        curp[17] = numero[0];
        printf(curp);

        
    }
    return curp[18];
}


