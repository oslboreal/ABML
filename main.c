#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>





/* ---------------------------------------------------------  /
//
// Menú básico - Trabajo práctico 1 (UTN FRA)
//
// Alumno Juan Marcos Vallejo.
// Prof. Scarafilo German & Lic. Mauricio Dávila.
//
// --------------------------------------------------------- */





    // Arrays del ABML
    char nombre[50];
    float precio[50];
    int codigo[50];
    int estado[50]; // 1 - Activo -1 - Inactivo.
    // Estados
    int bandera = 0;
    int lugar;


int main()
{
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
            estado[0] = 1;
            estado[1] = 2;
            lugar = primerVacio(estado);
            printf("\nPrimer lugar vacio es: %d",lugar);
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



