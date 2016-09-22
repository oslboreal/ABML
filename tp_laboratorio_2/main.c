#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "funciones.h"



int main()
{

// Variables de estado y contadores.
    char seguir='s';
    int opcion=0;
    int i;
    struct datosPersonas pers[20];

    // Inicializa todos los estados en "vacio".
    inicializarRegistros(pers);


// Prueba de una persona.
strcpy(pers[0].nombre, "Romeo Abdul");
pers[0].id = 1;
pers[0].edad = 25;
pers[0].idEstado = 'a';
pers[0].dni = 23232;
pers[0].idGrupo = 2;
// Prueba de una persona.
strcpy(pers[1].nombre, "Nicolas Pedro");
pers[1].id = 2;
pers[1].edad = 25;
pers[1].idEstado = 'a';
pers[1].dni = 23232;
pers[1].idGrupo = 2;
// Prueba de una persona.
strcpy(pers[2].nombre, "Carlos drago");
pers[2].id = 3;
pers[2].edad = 25;
pers[2].idEstado = 'a';
pers[2].dni = 23232;
pers[2].idGrupo = 2;





    // Estructura repetitiva del menú esperando que el flag cambie.

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir \n");


        printf("\nOpcion: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                    loadPerson(pers,20); // Funcion para dar el alta a una nueva persona.

                    break;

            case 2:
                    // Muestra una lista de usuarios con determinado estado. (ACTIVOS)
                    // Y solicita el ingreso del ID para realizar la baja.
                    deleteUsser(pers);

                        system("pause");
            break;

            case 3:



                       for(i=0; i<20; i++)
                        {
                             printPerson(pers,i);

                        }

                            system("pause");
                    break;

            case 4:
                break;

            case 5:
                seguir = 'n';

        }
    }

    return 0;
}


