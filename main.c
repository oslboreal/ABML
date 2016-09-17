#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


void loadMenu(int segu,const char menu[]);

void inicializarEstados(); // Establecer todos los registros en Inactivos para poder ser cargados
void mostrarActivos(); // Imprime en pantalla los registros activos.
void mostrarInactivos(); // Imprime en pantalla los registros inactivos.


struct pelicula
{
    int idPelicula;
    char titulo[255];
    int idDirector;
    int idNacionalidad;
    char idEstado;
};

struct estado
{
    char idEstado;
    char descripcion[50];
};

struct director
{
    int idDirector;
    char nombre[50];
    char idEstado;
    int idNacionalidad;
};

struct nacionalidad
{
    int idNacionalidad;
    char descripcion[50];
    char idEstado;
};

    struct pelicula peli[10];
    struct estado state[1];
    struct director direc[10];
    struct nacionalidad pais[10];


int main()
{

    // Arrays del ABML

    //Peli uno
    peli[0].idDirector = 1;
    peli[0].idEstado = 'a';
    peli[0].idNacionalidad = 1;
    peli[0].idPelicula = 1;
    strcpy(peli[0].titulo,"Escuadron Suicida");

    // Dos estados
    state[0].idEstado = 'a';
    strcpy(state[0].descripcion,"Alta");

    state[1].idEstado = 'b';
    strcpy(state[1].descripcion,"Baja");



    // direc
    direc[0].idDirector=1;
    direc[0].idEstado='a';
    direc[0].idNacionalidad=1;
    strcpy(direc[0].nombre,"direc Vallejo");

    // nac
    strcpy(pais[0].descripcion,"Arg");
    pais[0].idEstado='a';
    pais[0].idNacionalidad=1;


    // Estados
    int bandera = 0;



    const char menu[] = "1. Alta.\n"
                        "2. Modificar.\n"
                        "3. Baja.\n"
                        "4. Listar ordenadamente.\n"
                        "5. Salir";


    while(bandera!=5)
    {
        loadMenu(bandera, menu);
        printf("\n\nComandos: ");
        scanf("%d", &bandera);

        switch(bandera)
        {
        case 1:


            system("pause");

            break;
        case 2:

            system("pause");

            break;
        case 3:
            break;
        case 4:
            break;

        }



    }

void inicializarEstados();
{
    int i;

    for(i=0;i<10;i++)
    {
        peli[i].idEstado = 'b';
        direc[i].idEstado = 'b';
        nacionalidad[i].idEstado = 'b';

    }
}





    return 0;
}

void loadMenu(int segu,const char menu[])
    {

            system("cls");
            printf("%s", menu);


    }
