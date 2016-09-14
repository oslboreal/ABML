#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#include <windows.h>
#include <conio.h>
#include <ctype.h>




/* ---------------------------------------------------------  /
//
// Menú básico - Trabajo práctico 1 (UTN FRA)
//
// Alumno Juan Marcos Vallejo.
// Prof. Scarafilo German & Lic. Mauricio Dávila.
//
// --------------------------------------------------------- */

    // Array para ordenar
    float primero = 4.3;
    float segundo = 5.8;

    // Estados
    int bandera = 0;


int main()
{
    const char menu[] = "1. Alta.\n"
                        "2. Modificar.\n"
                        "3. Baja.\n"
                        "4. Listar ordenadamente.\n"
                        "5. Salir";
    // Cargar menú principal.
    while(bandera!=5)
    {
        loadMenu(bandera, menu);
        printf("\n\nComandos: ");
        scanf("%d", &bandera);

        switch(bandera)
        {
        case 1:
            printf("Opcion 1.\n");
            system("pause");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;

        }



    }






    return 0;
}



