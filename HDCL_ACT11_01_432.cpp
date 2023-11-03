//Hector Daniel Camacho Lopez     372239                                                     //
//Ensenada, Baja California a 31 de Octubre del 2023                                         //
//Programa que guarda informacion de alumnos en una estructura                               //
//Nombre de la actividad: HDCL_ACT11_01_432                                                  //

#include "daniel.h"
#define MAX 500
#include<fstream>

// CREANDO ESTRUCTURA //
typedef struct _alum{
    int status;
    int matri;
    char nombre[30];
    char appat[30];
    char apmat[30];
    int edad;
    char curp[18];
    int año;
    int mes;
    int dia;
    char estado[2];
    char sex[1];
    int sexo;}talum;

//PROTOTIPOS DE FUNCIONES //
int decision();
void menu();
void apellidos(char cadena[]);
void nom_feme(char cadena[]);
void nom_masc(char cadena[]);
void imprimir(talum vect[], int n);

void ordenar(talum vect[], int n);
void encontrar(talum vect[],int n);
int busqueda(talum vect[], int n, int matri);

int gene_matri();
int gene_sex();
char gene_nomb(int sexo);
char gene_appat();
char gene_apmat();
int gene_año();
int gene_mes();
int gene_dia(int mes);
int gene_est();
char curp_2(char appat[30]);

void eliminar(talum vect[], int i);

int main()
{
    menu();
}

// PROTOTIPOS DE TALUM //
talum gene_auto();


// FUNCION DE MENU PARTE 1 //
int decision()
{
    int opc;
    printf("\n                MENU                    ");
    printf("\n1) Cargar");
    printf("\n2) Eliminar");
    printf("\n3) Buscar");
    printf("\n4) Ordenar");
    printf("\n5) Imprimir");
    printf("\n6) Archivo de texto");
    printf("\n0) SALIR");
    opc = valida_num(0, 6, "\nQue deseas hacer? Ingresa el numero correspondiente: ");
    return opc;
}

// FUNCION DE MENU PRINCIPAL PARTE 2 //
void menu()
{
    talum vect[MAX], reg;
    int i = 0, opc, j, k;
    int txtband;
    do
    {
        opc = decision();
        switch(opc)
        {
            case 1:
                for (j = 0; j < 100; j++)
                {
                    vect[i++] = gene_auto();
                }
                break;
            
            case 2:
                eliminar(vect, i);
                break;

            case 3:
                encontrar(vect, i);
                break;

            case 4:
                ordenar(vect, i);
                break;

            case 5:
                imprimir(vect, i);
                break;

            case 6:
                FILE *festructura;
                int k;
                for (k = 0; k < 100; k++)
                {
                        festructura = fopen("registros.txt", "w+");
                        fprintf(festructura, "\n MATRICULA: %d", vect[k].matri);
                        fprintf(festructura, "\n NOMBRE: %s", vect[k].nombre);
                        fprintf(festructura, "\n APELLIDO PATERNO: %s", vect[k].appat);
                        fprintf(festructura, "\n APELLIDO MATERNO: %s", vect[k].apmat);
                        fprintf(festructura, "\n FECHA DE NACIMIENTO: %d/ %d / %d", vect[k].dia, vect[k].mes, vect[k].año);
                        fprintf(festructura, "\n SEXO: %d", vect[k].curp[10]);
                        fprintf(festructura, "\n EDAD: %d", vect[k].edad);
                        fprintf(festructura, "\n CURP: %d", vect[k].curp);
                        fprintf(festructura, "\n\n");
                        fclose(festructura);
                }
                printf("Se genero un archivo de texto de los registros\n");
                break;

            default:
                break;
        }
    }while(opc != 0 && i < MAX);
}


// FUNCION DE LLENAR AUTOMATICAMENTE //
talum gene_auto()
{
    talum aut;
    int aux, i, noestado, num, tam;
    char años[4];
    char meses[2];
    char dias[2];
    char sex[1];
    char abrevest[3];
    char numero[1];

    aut.status = 1;
    aut.matri = (rand()%399999) + 300000;
    aut.sexo = rand()%2;
    if (aut.sexo == 1)
    {
        nom_masc(aut.nombre);
        aut.sex[0] = 'H';
    }
    else
    {
        nom_feme(aut.nombre);
        aut.sex[0] = 'M';
    }

    apellidos(aut.appat);
    apellidos(aut.apmat);
    aut.edad = (rand()%60) + 10;
    aut.año = gene_año();
    aut.mes = gene_mes();
    aut.dia = gene_dia(aut.mes);
    noestado = gene_est();
    aut.curp[0] = aut.appat[0];
    aut.curp[1] = curp_2(aut.appat);
    aut.curp[2] = aut.apmat[0];
    aut.curp[3] = aut.nombre[0];
    entero_cad(aut.año, años);
    aut.curp[4] = años[2];
    aut.curp[5] = años[3];
    for (i = 0; i < 82; i++)
        {
            if (aut.curp[0] == malas[i][0])
            {
                if (aut.curp[1] == malas[i][1])
                {
                    if (aut.curp[2] == malas[i][2])
                    {
                        if (aut.curp[3] == malas[i][3])
                        {
                            aut.curp[1] = 'X';
                            i = 82;
                        }
                    }
                }
            }
        }    

    entero_cad(aut.mes, meses);
    aut.curp[6] = 48;
    aut.curp[7] = meses[0];
    if (aut.mes > 10)
    {
        aut.curp[6] = 49;
        if ((aut.mes - 10) == 0)
        {
            aut.curp[7] = 48;
        }
        if ((aut.mes - 10) == 1)
        {
            aut.curp[7] = 49;
        }
        if ((aut.mes - 10) == 2)
        {
            aut.curp[7] = 50;
        }
    }
    entero_cad(aut.dia, dias);
    if (aut.dia < 10)
    {
        aux = dias[0];
        dias[0] = 48;
        dias[1] = aux;
    }
    aut.curp[8] = dias[0];
    aut.curp[9] = dias[1];

    aut.curp[10] = aut.sex[0];


    for (i = 0; i < 34; i++)
    {
        if (noestado == i)
        {
            aut.estado[0] = abrev[i][0];
            aut.estado[1] = abrev[i][1];
        }
    }
    aut.curp[11] = aut.estado[0];
    aut.curp[12] = aut.estado[1];

    tam = tamaño(aut.appat);
    for(i = 1; i < tam; i++)
    {
        if (aut.appat[i] != 65)
        {
            if (aut.appat[i] != 69)
            {
                if (aut.appat[i] != 73)
                {
                    if (aut.appat[i] != 79)
                    {
                        if (aut.appat[i] != 85)
                        {
                            aut.curp[13] = aut.appat[i];
                            i = tam;
                        }
                    }
                }
            }
        }
    }

    tam = tamaño(aut.apmat);
    for(i = 1; i < tam; i++)
    {
        if (aut.apmat[i] != 65)
        {
            if (aut.apmat[i] != 69)
            {
                if (aut.apmat[i] != 73)
                {
                    if (aut.apmat[i] != 79)
                    {
                        if (aut.apmat[i] != 85)
                        {
                            aut.curp[14] = aut.apmat[i];
                            i = tam;
                        }
                    }
                }
            }
        }
    }

    tam = tamaño(aut.nombre);
    for(i = 1; i < tam; i++)
    {
        if (aut.nombre[i] != 65)
            {
                if (aut.nombre[i] != 69)
                {
                    if (aut.nombre[i] != 73)
                    {
                        if (aut.nombre[i] != 79)
                        {
                            if (aut.nombre[i] != 85)
                            {
                                aut.curp[15] = aut.nombre[i];
                                i = tam;
                            }
                        }
                    }
                }
            }
        }
    if (aut.año < 1999)
    {
        aut.curp[16] = 48;
    }
    else
    {
        if (aut.año <= 2010)
        {
            aut.curp[16] = 65;
        }
        else
        {
            if (aut.año <= 2020)
            {
                aut.curp[16] = 66;
            }
            else
            {
                if (aut.año <= 2030)
                {
                    aut.curp[16] = 67;
                }
            }
        }
    }
    num = rand()%9;
    entero_cad(num, numero);
    aut.curp[17] = numero[0];



    return aut;
}

// FUNCION QUE CONTIENE APELLIDOS //
void apellidos(char cadena[])
{
    char apell[20][20] = {"HERNANDEZ","GARCIA","MARTINEZ","LOPEZ","GONZALES","PEREZ","RODRIGUEZ","SANCHEZ","RAMIREZ","CRUZ","GOMEZ","FLORES","MORALES","VAZQUEZ","JIMENEZ","REYES","DIAZ","TORRES","VICENTE","CAMACHO"};
    strcpy(cadena,apell[rand()%20]);
}

// FUNCION QUE CONTIENE NOMBRES MASCULINOS //
void nom_masc(char cadena[])
{
    char nom[20][12] = {"JUAN","LUIS","PEDRO","HECTOR","DANIEL","MANUEL","CARLOS","ROBERTO","MIGUEL","FRANCISCO","DIEGO","RAFAEL","ANGEL","JAVIER","ANTONIO","ALFREDO","RUBEN","DIEGO","PABLO","JONATHAN"};
    strcpy(cadena,nom[rand()%20]);
}

// FUNCION QUE CONTIENE NOMBRES FEMENINOS //
void nom_feme(char cadena[])
{
    char nomfem[20][20] = {"GENESIS","LARA","MARIA","MARGARITA","JUANA","CARMEN","VERONICA","ROSA","FLOR","TERESA","ALICIA","ALEJANDRA","XIMENA","CAMILA","VALERIA","ELIZABETH","RENATA","DANNA","VICTORIA","ESMERALDA"};
    strcpy(cadena,nomfem[rand()%20]);
}

// FUNCION QUE IMPRIME LOS DATOS //
void imprimir(talum vect[], int n)
{
    int i, borrar = 0;
    printf("\tNo.   Matricula       Nombre(s)       Apellido Paterno   Apellido Materno     Edad       Sexo(1-HOMBRE 2-MUJER):           CURP");
    if (borrar == 0 )
    {
    for(i = 0; i < n; i++)
    {
        if (vect[i].status == 0)
        {
            i++;
        }
        printf("\n\t%d       %d        %s         %s        %s               %d                      %d                 %s",i+1, vect[i].matri, vect[i].nombre,vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo, vect[i].curp);
    }
    printf("\n");
    }
    else
    {
        printf("SIN DATOS REGISTRADOS");
    }
}



// FUNCION QUE BUSCA UN REGISTRO (BUSQUEDA SECUENCIAL) //
int busqueda(talum vect[], int n, int matri)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(matri == vect[i].matri)
        {
            return i;
        }
    }
    return -1;
}

// FUNCION QUE BUSCA UN REGISTRO (BUSQUEDA BINARIA) //
int busqueda2(talum vect[], int n, int matri)
{
    int inf, sup, mitad, i;
    inf = 0;
    sup = 100;

        while( inf <= sup)
        {
            mitad = (inf + sup) / 2;
            if (vect[mitad].matri == matri)
            {
                return i;
                break;
            }
            if (vect[mitad].matri > matri)
            {
                sup = mitad;
                mitad = (inf + sup) / 2;
            }
            if (vect[mitad].matri < matri)
            {
                inf = mitad;
                mitad = (inf + sup) / 2;
            }
        }
        return -1;

}


// FUNCION QUE PROPORCIONA DATOS DEL ALUMNO //
void encontrar(talum vect[], int n)
{
    int matri, z;
    matri = valida_num(300000,399999,"\nIngresa la matricula que deseas encontrar para iniciar la busqueda de informacion: ");
    z = busqueda(vect, n, matri);

    if (z != -1)
    {
        printf("\nRESULTADO ENCONTRADO. La matricula es de: %s %s %s", vect[z].nombre, vect[z].appat, vect[z].apmat);
        printf("\nNo.   Matricula       Nombre(s)       Apellido Paterno   Apellido Materno     Edad       Sexo:(1 - HOMBRE; 0 - MUJER)        CURP");
        printf("\n\t%d       %d        %s         %s        %s               %d             %d           %s",z+1, vect[z].matri, vect[z].nombre,vect[z].appat, vect[z].apmat, vect[z].edad, vect[z].sexo, vect[z].curp);
    }
    else
    {
        printf("\nLo siento, no hay registro de la matricula digitada");
    }
}

// FUNCION QUE ORDENA LOS REGISTROS //
void ordenar(talum vect[], int n)
{
    int i, j, aux;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if (vect[j].matri < vect[i].matri)
            {
                aux = vect[i].matri;
                vect[i].matri = vect[j].matri;
                vect[j].matri = aux;
            }
        }
    }
}

// FUNCION QUE GENERA MATRICULA ALEATORIA //
int gene_matri()
{
    int matri;
    matri = (rand()%399999) + 300000;
    return matri;
}

// FUNCION QUE GENERA SEXO ALEATORIO //
int gene_sex()
{
    int sexo;
    sexo = rand()%2;
}

// FUNCION QUE GENERA NOMBRES ALEATORIOS //
char gene_nomb(int sexo)
{
    char nombre[30];
    if (sexo == 1)
    {
        nom_masc(nombre);
        sexo = 'M';
    }
    else
    {
        nom_feme(nombre);
        sexo = 'F';
    }
    return nombre[30];
}

// FUNCION QUE GENERA APELLIDO PATERNO //
char gene_appat()
{
    char appat[15];
    apellidos(appat);
    return appat[15];
}

// FUNCION QUE GENERA APELLIDO MATERNO //
char gene_apmat()
{
    char apmat[15];
    apellidos(apmat);
    return apmat[15];
}

// FUNCION QUE GENERA AÑO ALEATORIO //
int gene_año()
{
    int año;
    año = (rand()%2023) + 1930;
    return año;
}

// FUNCION QUE GENERA MES ALEATORIO //
int gene_mes()
{
    int mes;
    mes = (rand()%12) + 1;
    return mes;
}

// FUNCION QUE GENERA DIA ALEATORIO //
int gene_dia(int mes)
{
    int dia;
    if (mes = 1)
    {
        dia = (rand()%31) + 1;
    }
    if (mes = 2)
    {
        dia = (rand()%28) + 1;
    }
    if (mes = 3)
    {
        dia = (rand()%31) + 1;
    }
    if (mes = 4)
    {
        dia = (rand()%30) + 1;
    }
    if (mes = 5)
    {
        dia = (rand()%31) + 1;
    }
    if (mes = 6)
    {
        dia = (rand()%30) + 1;
    }
    if (mes = 7)
    {
        dia = (rand()%31) + 1;
    }
    if (mes = 8)
    {
        dia = (rand()%31) + 1;
    }
    if (mes = 9)
    {
        dia = (rand()%30) + 1;
    }
    if (mes = 10)
    {
        dia = (rand()%31) + 1;
    }
    if (mes = 11)
    {
        dia = (rand()%30) + 1;
    }
    if (mes = 13)
    {
        dia = (rand()%31) + 1;
    }
    return dia;
}

// FUNCION QUE GENERA ESTADO ALEATORIO //
int gene_est()
{
    int estado;
    estado = (rand()%33) + 1;
    return estado;
}

// FUNCION QUE GENERA ESPACIO 2 DEL CURP //
char curp_2 (char appat[30])
{
    char curp2;
    int tam, i;
    tam = tamaño(appat);
    for (i = 1; i < tam; i++)
        {
            if (appat[i] == 65)
            {
                curp2 = appat[i];
                i = tam;
            }
            else
            {
                if (appat[i] == 69)
                {
                    curp2 = appat[i];
                    i = tam;
                }
                else
                {
                    if (appat[i] == 73)
                    {
                        curp2 = appat[i];
                        i = tam;
                    }
                    else
                    {
                        if (appat[i] == 79)
                        {
                            curp2 = appat[i];
                            i = tam;
                        }
                        else
                        {
                            if (appat[i] == 85)
                            {
                                curp2 = appat[i];
                                i = tam;

                            }
                        }    
                    }
                }
            }
        
    } 
    return curp2;      
} 

// FUNCION QUE BORRA UN REGISTRO //
void eliminar(talum vect[], int i)
{
    int posic, opc, matri;
    matri = valida_num(300000, 399999,"INGRESA LA MATRICULA QUE QUIERES ELIMINAR: ");

    posic = busqueda(vect, 100, matri); 
    if (posic != -1)
    { 
        printf("ENCONTRADO, seguro que deseas borrar este registro? ");
        printf("PRESIONA: 1 - SI         2 - NO");
        scanf("%d", &opc);
    }
    if (opc == 1) 
    {
        vect[posic].status = 0;
    }  
    else
    {
        printf("Cancelando borrado de registro");
    }
}


