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
    char descripcion[50][50];
    float precio[50];
    int codigo[50];
    int estado[50]; // 1 - Activo 0  - De baja
    // Estados
    int bandera = 0;
    int lugar;

    // Contadores y acumuladores
    int i;


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
            codigo[0] = 2343;
            //descripcion[0] = "PRueba";
            precio[0] = 23.4;
            estado[0] = 1;
            //
            lugar = primerVacio(estado);

            printf("\nPrimer lugar vacio es: %d\n",lugar);
            printf("\nEstado 0: %d",estado[0]);
            printf("\nCodigo 0: %d",codigo[0]);
            printf("\nPrecio 0: %f",precio[0]);
            system("pause");
              altaProducto(codigo,precio,estado,descripcion);

            printf("\nEstado 0: %d",estado[0]);
            printf("\nCodigo 0: %d",codigo[0]);
            printf("\nPrecio 0: %f",precio[0]);
            printf("\nDescripcion 0: %s",descripcion[0]);
            system("pause");
            //altaProducto(codigo,descripcion,precio,estado);

            system("pause");
            for(i = 0; i < 50; i++)
            {
            printf("\nEstado 0: %d",estado[i]);
            printf("\nCodigo 0: %d",codigo[i]);
            printf("\nPrecio 0: %f\n\n",precio[i]);
            }
            system("pause");

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



