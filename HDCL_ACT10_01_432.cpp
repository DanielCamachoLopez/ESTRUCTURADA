//Hector Daniel Camacho Lopez     372239                                                     //
//Ensenada, Baja California a 15 de Octubre del 2023                                         //
//Programa que guarda informacion de alumnos en una estructura                               //
//Nombre de la actividad: HDCL_ACT10_01_432                                                  //

#include "daniel.h"
#define MAX 500

// CREANDO ESTRUCTURA //
typedef struct _alum{
    int status;
    int matri;
    char nombre[30];
    char appat[30];
    char apmat[30];
    int edad;
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

int main()
{
    menu();
}

// PROTOTIPOS DE TALUM //
talum gene_manual();
talum gene_auto();
talum eliminar(talum vect[], int n);


// FUNCION DE MENU PARTE 1 //
int decision()
{
    int opc;
    printf("\n                MENU                    ");
    printf("\n1) Registro manual");
    printf("\n2) Registro automatico (10 datos)");
    printf("\n3) Borrar");
    printf("\n4) Ordenar");
    printf("\n5) Buscar");
    printf("\n6) Imprimir");
    printf("\n0) SALIR");
    opc = valida_num(0, 6, "\nQue deseas hacer? Ingresa el numero correspondiente: ");
    return opc;
}

// FUNCION DE MENU PRINCIPAL PARTE 2 //
void menu()
{
    talum vect[MAX], reg;
    int i = 0, opc, j;
    do
    {
        opc = decision();
        switch(opc)
        {
            case 1:
                if (i < MAX-1)
                {
                    vect[i++] = gene_manual();
                }
                break;

            case 2:
                for (j = 0; j < 10; j++)
                {
                    vect[i++] = gene_auto();
                }
                break;
            
            case 3:
                eliminar(vect, i);
                break;

            case 4:
                ordenar(vect, i);
                break;

            case 5:
                encontrar(vect, i);
                break;

            case 6:
                imprimir(vect, i);
                break;

            default:
                break;
        }
    }while(opc != 0 && i < MAX);
}

// FUNCION DE LLENAR MANUALMENTE //
talum gene_manual()
{
    talum manu;
    manu.status = 1; //ACTIVO:1      INACTIVO:0
    manu.matri = valida_num(300000, 399999, "\n Dame la matricula: ");
    
    printf("\nNombre(s) (SIN APELLIDOS): ");
    fflush(stdin);
    gets(manu.nombre);
    mayusculas(manu.nombre);
    printf(manu.nombre);

    printf("\nApellido paterno: ");
    fflush(stdin);
    gets(manu.appat);
    mayusculas(manu.appat);
    printf(manu.appat);

    printf("\nApellido materno: ");
    fflush(stdin);
    gets(manu.apmat);
    mayusculas(manu.apmat);
    printf(manu.apmat);

    manu.edad = valida_num(10, 60, "\nIngresa tu edad: ");
    printf(" %d ",manu.edad);
    manu.sexo = valida_num(1, 2, "INGRESA: \n(1 - Si eres hombre)    o   (2 - Si eres mujer)");
    return manu;
}


// FUNCION DE LLENAR AUTOMATICAMENTE //
talum gene_auto()
{
    talum aut;
    int sexo, random;
    random = rand()%2;
    aut.status = 1;
    aut.matri = (rand()%399999) + 300000;
    aut.sexo = rand()%2;
    if (aut.sexo == 1)
    {
        nom_masc(aut.nombre);
    }
    else
    {
        nom_feme(aut.nombre);
    }
    apellidos(aut.appat);
    apellidos(aut.apmat);
    aut.edad = (rand()%60) + 10;
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
    printf("\tNo.   Matricula       Nombre(s)       Apellido Paterno   Apellido Materno     Edad       Sexo:(1 - HOMBRE; 0 - MUJER)");
    if (borrar == 0 )
    {
    for(i = 0; i < n; i++)
    {
        printf("\n\t%d       %d        %s         %s        %s               %d             %d",i+1, vect[i].matri, vect[i].nombre,vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
    }
    printf("\n");
    }
    else
    {
        printf("SIN DATOS REGISTRADOS");
    }
}



// FUNCION QUE BUSCA UN REGISTRO //
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

// FUNCION QUE PROPORCIONA DATOS DEL ALUMNO //
void encontrar(talum vect[], int n)
{
    int matri, z;
    matri = valida_num(300000,399999,"\nIngresa la matricula que deseas encontrar para iniciar la busqueda de informacion: ");
    z = busqueda(vect, n, matri);

    if (z != -1)
    {
        printf("\nRESULTADO ENCONTRADO. La matricula es de: %s %s %s", vect[z].nombre, vect[z].appat, vect[z].apmat);
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


talum eliminar(talum vect[], int n)
{
    int z = 0;
    int matri = valida_num(300000, 399999, "\nIngresa la matricula para borrar los datos correspondientes: ");
    talum vec[MAX];

    for (int i = 0; i < n; i++)
    {
        if (matri != vect[i].matri)
        {
            vec[z] = vect[i];
            z++;
        }
    }

    if (z == n)
    {
        printf("\nLo siento, no hay datos registrados con esa matricula\n");
    }
    else
    {
        printf("\nEliminando registro completo");
        n = z;
        for (int i = 0; i < z; i++)
        {
            vect[i] = vec[i];
        }
    }
    if (z > 0)
    {
        return vec[z - 1];
    }
    else
    {
        talum vacio;
        vacio.status = 0;
        return vacio;
    }
}



