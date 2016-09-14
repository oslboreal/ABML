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

    /** \brief Indica cual es el primer registro vacio de un conjunto de arrays paralelos.
* \param Dirección de memoria del array.
* \return Cantidad de caracteres del string.
*
*/



/** \brief Indica cual es el primer registro vacio de un conjunto de arrays paralelos.
* \param Dirección de memoria del array.
* \return Cantidad de caracteres del string.
*
*/
