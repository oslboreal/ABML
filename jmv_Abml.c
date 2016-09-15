#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include "funciones.h"

/** \brief Indica cual es el primer registro vacio de un conjunto de arrays paralelos.
* \param Dirección de memoria del array.
* \return Cantidad de caracteres del string.
*
*/

int primerVacio(int esta[])
    {
        int i;
        int ubicacion = 0;

        for(i=0;i<50;i++)
        {

            if(esta[i]==0)
            {
                ubicacion = i;
                break;
            }
        }

        return ubicacion;
    }

    /** \brief Solicita la carga de un producto en el primer registro vácio..
* \param Dirección del arreglo [Codigo de producto].
* \param Dirección del arreglo [Descripcion del producto].
* \param Dirección del arreglo [Precio del producto].
* \param Dirección del arreglo [Estado del producto].
* \return Cantidad de caracteres del string.
*
*/

int altaProducto(int *cod, float *price, int *state, char *desc)
    {
    printf("%s",desc[0]);
    scanf("%s",desc[0]);
    printf("%s",desc[0]);

    int lugarCargar = primerVacio(state);
    int codAux = 0;
    float priAux;
    //int staAux;
/////////////////////////////////////
    // Cargar código.
    printf("\nIngresa el codigo numerico del producto: [ID:%d]", lugarCargar);
    scanf("%d",&codAux);
    printf("%d",codAux);
    fflush(stdin);
    // Asignación.
    cod[lugarCargar] = codAux;
/////////////////////////////////////
/////////////////////////////////////
    // Cargar precio.
    printf("\nIngresa el precio del producto: [ID:%d]", lugarCargar);
    scanf("%f",&priAux);
    fflush(stdin);
    // Asignación.
    price[lugarCargar] = priAux;
    // Cargar estado.
    state[lugarCargar] = 1;

    // Descripcion






    return 1;
    }



