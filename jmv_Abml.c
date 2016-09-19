#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

/** \brief Indica cual es el primer registro vacio de un conjunto de arrays paralelos.
* \param Dirección de memoria del arreglo de estructura.
* \return Ubicacion del registro vacio.
*
*/

int regOff(struct datosPersonas *p)
    {
        int i;
        int ret = 0;

        for(i = 0; i<20; i++)
        {
            if(p[i].idEstado=='b')
            {
                ret = i;
                break;
            }
        }


        return ret;
    }

/** \brief Formulario de carga en el primer registro vacio.
* \param Dirección de memoria del arreglo de estructura.
*
*
*/

void loadPerson(struct datosPersonas *p)
{
    char buffer[4000]; // Array de caracteres buffer para ingresar caracteres indiscriminadamente y luego validarlos.
    int pos = regOff(p); // Esta funcion retorna la posicion del primer registro vacio.}
    int estado;
    char bande = 'n';

    do
    {
        // SOLICITO NOMBRE.
        printf("Nombre de la persona a cargar:");

        scanf("%s",buffer);
        fflush(stdin);
        estado = validateIsName(buffer); // Valido el nombre return [1] Si es valido [0] Si no.


        if(estado==1)
        {
            // Si la cadena es correcta automáticamente la asigno.
            strcpy(p[pos].nombre,buffer);
            bande = 'n';
        }   else // De lo contrario pregunto...
                {
                    printf("El nombre ingresado es invalido, desea reingresar y seguir cargando datos? S/N: ");
                    bande = tolower(getch());
                    if(bande=='n')
                    {
                        bande = 's'; // Si sale todo mal asigno el flag en 's'
                        break;
                    }
                }

    }while(bande=='s');

    do
    {
        if(bande=='s') // Si entra con 's' Corta.
        {
            break;
        } else
            {

            }
        // Solicito edad

        printf("Edad de la persona a cargar:");
        scanf("%s",buffer);
        estado = validateIsNum(buffer,2);

        if(estado==1)
        {
            p[pos].edad = atoi(buffer);

        } else
            {
                    printf("El dato ingresado es invalido, desea reingresar y seguir cargando datos? S/N: ");
                    bande = tolower(getch());
                    if(bande=='n')
                    {
                        bande = 's'; // Si sale todo mal asigno el flag en 's'
                        break;
                    }
            }



    }while(bande=='s');


    do
    {
        if(bande=='s') // Si entra con 's' Corta.
        {
            break;
        }

    // Solicito documento.
    printf("Documento de identidad de la persona a cargar:");
    scanf("%d",&p[pos].dni);

    }while(bande=='s');


    // Cambio el estado del registro a activo.
    p[pos].idEstado = 'a'; // Se asigna el estado ACTIVO automáticamente siendo que es una alta.

    // Dependiendo de la edad de la persona asigno el grupo correspondiente.
    if(p[pos].edad<=18)
    {
        p[pos].idGrupo = 1; // Menores de 18 y 18 inclusive..
    } else
        {
            if(p[pos].edad>=19&&p[pos].edad<=35)
            {
                p[pos].idGrupo = 2; // Entre 19 y 35
            } else
                {
                    if(p[pos].edad>35)
                    {
                        p[pos].idGrupo = 3; // Mayores de 35
                    }
                }

        }

    printf("\n");
}

/** \brief Imprime la descripcion del grupo segun su id.
* \param Dirección de memoria del array de estructura.
* \param group Numero de identificacion del grupo.
*
*/
void printGroup(int group)
{
    if(group==1)
    {
        printf("Grupo asignado: Menor de 18 anios.");
    }
    if(group==2)
    {
        printf("Grupo asignado: Entre 19 y 35 anios.");
    }
    if(group==3)
    {
        printf("Grupo asignado: Mayor de 35 anios.");
    }
}

/** \brief Indica cual es el primer registro vacio de un conjunto de arrays paralelos.
* \param Dirección de memoria del array.
* \return Ubicacion del registro vacio.
*
*/
int inicializarRegistros(struct datosPersonas *p)
{

    int i;
    int retorno = 0;
    for(i = 0; i<20 ;i++)
    {
        p[i].idEstado = 'b';
    }

    for(i = 0; i<20; i++)
    {
        if(p[i].idEstado=='b')
        {
            retorno++;
        }
    }

    return retorno;

}

/** \brief Indica cual es el primer registro vacio de un conjunto de arrays paralelos.
* \param Dirección de memoria del array.
* \return Ubicacion del registro vacio.
*
*/
void printPerson(struct datosPersonas *p, int id)
{

    printf("\n[ID:%d] Nombre: %s\n",id+1,p[id].nombre);
    printf("[ID:%d] Edad: %d\n",id+1,p[id].edad);
    printf("[ID:%d] DNI: %d\n",id+1,p[id].dni);
    printf("[ID:%d] Codigo de estado: %c\n",id+1,p[id].idEstado);
    printGroup(p[id].idGrupo);
    printf("\n");

}
/** \brief Indica cual es el primer registro vacio de un conjunto de arrays paralelos.
* \param Dirección de memoria del arreglo de estructura.
* \return Ubicacion del registro vacio.
*
*/

int regCantOff(struct datosPersonas *p)
    {
        int i;
        int ret = 0;

        for(i = 0; i<20; i++)
        {
            if(p[i].idEstado=='b')
            {
                ret++;

            }
        }


        return ret;
    }

/** \brief
* \param
* \return
*
*/

int suprPerson(struct datosPersonas *p,int id)
{
    int comprobA;
    int comprobB;
    int ret = 0;
    comprobA = regCantOff(p); // Cantidad de registros antes.
    p[id].idEstado = 'b';
    comprobB = regCantOff(p); // Cantidad de registros despues.


    // Comprobamos si se realizó una baja. ( Antes - Despues = -1 )
    if(comprobA-comprobB==-1)
    {
        // De ser asi retorno 1.
        ret = 1;
    }

        return ret;

}

/** \brief
* \param
* \return
*
*/

void printActiveUssersNameList(struct datosPersonas *p)
    {
        int i;

        for(i=0; i<20; i++)
        {
            if(p[i].idEstado=='a')
            {
                printf("[ID = %d] Nombre: %s | Edad: %d | Dni: %d\n",i+1,p[i].nombre,p[i].edad,p[i].dni);
            }

        }
    }
