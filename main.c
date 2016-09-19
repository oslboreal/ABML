#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "funciones.h"

struct datosPersonas persona[20];
struct datosEstados estados[1];
struct datosGrupos grupo[2];

int main()
{


// Inicialización de los dos tipos de estado posibles.
estados[0].idEstado = 'a';
strcpy(estados[0].descripcionEstado, "Alta");

estados[1].idEstado = 'b';
strcpy(estados[1].descripcionEstado, "Baja");

// Inicialización de los tres grupos posibles.
grupo[0].idGrupo = 1;
strcpy(grupo[0].descripcionGrupo, "Menores de 18 anios.");
grupo[0].idEstado = 'a';

grupo[1].idGrupo = 2;
strcpy(grupo[1].descripcionGrupo, "Entre 19 a 35 anios.");
grupo[1].idEstado = 'a';

grupo[2].idGrupo = 3;
strcpy(grupo[2].descripcionGrupo, "Mayores de 35 anios.");
grupo[2].idEstado = 'a';

// Inicializacion de los estados.
inicializarRegistros(persona);

// Prueba de una persona.
strcpy(persona[0].nombre, "Abdul");
persona[0].edad = 25;
persona[0].idEstado = 'a';
persona[0].dni = 23232;
persona[0].idGrupo = 2;


// Variables de estado y contadores.
    char seguir='s';
    int opcion=0;
    int subOpcion=0;
    int acum;
    int i;

    //int acum;

    // Estructura repetitiva del menú esperando que el flag cambie.

    // Limpia el estado de los registros.


    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");

        printf("\nOpciones adicionales\n");
        printf("5- Ver grupos vigentes \n");
        printf("6- Ver estados posibles \n");
        printf("9- Salir\n");

        printf("\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    loadPerson(persona);
                    system("pause");
                    break;

            case 2:
                    printf("Ingrese el ID de la persona a Borrar:\n\n");
                    printActiveUssersNameList(persona);

                    printf("\nID Ingresado: ");
                    scanf("%d",&subOpcion);
                    system("cls");
                    printPerson(persona, subOpcion -1);
                    printf("\nDesea realmente borarr esto?\n");
                    system("pause");
                    acum = suprPerson(persona, subOpcion-1);

                    if(acum==1)
                    {
                        printf("\nRegistro borrado correctamente.\n");
                    }

                        system("pause");
            break;

            case 3:
acum = validateIsName(persona[0].nombre);

                       for(i=0; i<20; i++)
                        {
                             printPerson(persona,i);
                             printf("%d",acum);

                        }

                            system("pause");
                    break;

            case 4:
                break;

            case 5:

                for(i = 0; i<3;i++) // Recorre todos los grupos existentes imprimiendo los estados.
                {
                    printf("%d - %s\n",grupo[i].idGrupo,grupo[i].descripcionGrupo);
                    if(grupo[i].idEstado=='a')
                    {
                        printf("Estado: Alta.\n\n");
                    } else
                        {
                            printf("Estado: Baja.\n\n");
                        }
                }
                system("pause");
                break;


            case 6:
                printf("[%d] %s - Codigo: %c\n",1,estados[0].descripcionEstado, estados[0].idEstado);
                printf("[%d] %s - Codigo: %c\n",2,estados[1].descripcionEstado,estados[1].idEstado);
                system("pause");
                break;
            case 7:



                    system("pause");
                    system("cls");




                system("pause");
                break;

            case 9:
                seguir = 'n';
                break;

        }
    }

    return 0;
}


