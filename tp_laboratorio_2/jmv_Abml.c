#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

/** \brief Indica cual es el primer registro vacio (Siendo vacío 0 por convencion).
* \param Dirección de memoria del arreglo de estructura.
* \return Ubicacion del registro vacio.
*
*/

int regOff(struct datosPersonas *p, int tam)
    {
        int i;
        int ubi;
        for(i = 0; i<tam; i++)
        {
            if(p[i].idEstado=='b') // Recorro el array buscando coincidencias.
            {
                ubi = i; // Si encuentro una coincidencia retorno la direccion del array.
                break;

            } else
                {
                    ubi = -1;
                }
        }


return ubi;
    }

/** \brief Formulario de carga en el primer registro vacio.
* \param Dirección de memoria del arreglo de estructura.
*
*
*/

void loadPerson(struct datosPersonas *p, int tama)
{
    char buffer[4000]; // Array de caracteres buffer para ingresar caracteres indiscriminadamente y luego validarlos.
    int pos = regOff(p, tama); // Esta funcion retorna la posicion del primer registro vacio.}
    int estado;
    int cantAsignaciones = 0; // Almaceno la cantidad de veces que asigné datos en las validaciones.
    int flag = 1;
    char bande;
system("cls");
printf("[ID %d] - Es el primer ID vacio.", pos+1);

    // En este algoritmo apenas sea validado el ingreso se va a asignar debido a que no importa el valor asignado
    // Em el campo, de todas maneras solo sí todos los campos fueron validados se asignará el ALTA a la persona.

    // Solicito, valido y asigno nombre.
    do
    {
        printf("\n[1/3] Ingrese el nombre de la persona a dar el ALTA:");
        scanf("%s",buffer);
        fflush(stdin);

        // Validacion
        estado = validateIsName(buffer); // Valido el nombre return [1] Si es valido [0] Si no.

        if(estado==1)
        {
            // Si la cadena es correcta automáticamente la asigno.
            strcpy(p[pos].nombre,buffer); // Realizo la asignacion.
            cantAsignaciones++; // Sumo la cantidad de asignaciones.
            break; // Salto a la siguiente estructura.

        }           else // De lo contrario pregunto...
                    {
                            printf("\nEl nombre ingresado es invalido, desea reingresar y seguir cargando datos? S/N: ");
                            bande = tolower(getch());
                            if(bande=='n') // Si el usuario responde 'n' salgo de todas las estructuras.
                            {
                                flag = 0;
                                break;
                            }
                    }


    }while(flag == 1);

    // Solicito, valido y asigno edad.
    while(flag == 1)
    {
        printf("\n[2/3] Edad de la persona a cargar:");
        scanf("%s",buffer);

        if(validateIsNum(buffer,2) == 1 && validateIsPos(atoi(buffer)) == 1) // Valido el numero almacenado en buffer, el 2 es el TIPO (Entero) (El 1 seria flotante).
        {
            p[pos].edad = atoi(buffer); // Realizo la asignacion.
            cantAsignaciones++; // Sumo la cantidad de asignaciones
            break; // Salgo de la estructura
        }else
            {
                    printf("\nEl dato ingresado es invalido, desea reingresar y seguir cargando datos? S/N: ");
                    bande = tolower(getch());
                    if(bande=='n')
                    {
                        flag = 0;
                        break;
                    }
            }
    }

    // Solicito, valido y asigno DNI.
    while(flag == 1)
    {
    printf("\n[3/3] Documento de identidad de la persona a cargar:");
    scanf("%s",buffer); // Almaceno en el buffer

     if(validateIsNum(buffer,2) == 1 && validateIsPos(atoi(buffer)) == 1) // Valido el numero almacenado en buffer, el 2 es el TIPO (Entero) (El 1 seria flotante).
        {
            p[pos].dni = atoi(buffer); // Realizo la asignacion.
            cantAsignaciones++; // Sumo la cantidad de asignaciones
            break; // Salgo de la estructura
        }else
            {
                    printf("\nEl dato ingresado es invalido, desea reingresar y seguir cargando datos? S/N: ");
                    bande = tolower(getch());
                    if(bande=='n')
                    {
                        flag = 0;
                        break;
                    }
            }



    }

    // Comprobamos si todas las asignaciones se realizaron correctamente para dar el alta.
    if(cantAsignaciones==3) // Si todo fue asignado correctamente, asigno el estado "ALTA" y el grupo correspondiente.
     {
         printf("\nEl usuario se cargo correctamente.\n");
         p[pos].idEstado = 'a'; // Se asigna el estado ACTIVO automáticamente siendo que es una alta.
         p[pos].idGrupo = asignarGrupo(p[pos].edad);
         p[pos].id = pos+1;
         system("pause");
     } else
         {
             printf("\nNo se realizo el alta del nuevo usuario.\n");
             system("pause");
         }



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

/** \brief Inicializa todas las personas con codigo de baja.
* \param Dirección de memoria del array de estructura.
* \return La cantidad de registros que fueron inicializados..
*
*/
int inicializarRegistros(struct datosPersonas *p)
{

    int i;
    int retorno = 0;
    for(i = 0; i<20 ;i++) // Recorremos el campo inicializando en 0
    {
        p[i].idEstado = 'b';
    }

    for(i = 0; i<20; i++) // Recorremos nuevamente comprobando cuantos fueron inicializados para luego retornar el valor.
    {
        if(p[i].idEstado== 'b')
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
    if(p[id].idEstado=='a')
    {
    printf("\n[ID:%d] Nombre: %s - Edad: %d\n", p[id].id, p[id].nombre, p[id].edad);
    printf("[ID:%d] DNI: %d\n", p[id].id,p[id].dni);
    printf("[ID:%d] Codigo de estado: %c\n", p[id].id,p[id].idEstado);
    printGroup(p[id].idGrupo);
    printf("\n");
    }


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
            if(p[i].idEstado=='b') // Si al recorrer el array hay un registro vacio
            {
                ret++; // Aumenta la cant de registros vacios en 1

            }

        }


        return ret; // Retorna la cantidad.
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


    // Comprobamos si se realizó una baja. ( Antes - Despues =! 0)
    if(comprobA-comprobB!=0)
    {
        // De ser asi retorno 1.
        ret = 1;
    }

        return ret;

}

/** \brief Imprime un listado de usuarios que coincidan con un estado determinado.
* \param Array de estructuras a analizar.
* \param Caracter del estado a encontrar - Por ejemplo: 'a'
* \return Retorna la cantidad de registros encontrados - [-1] Si no encontró coincidencias.
*
*/

int printActiveUssersNameList(struct datosPersonas *p, char estado)
    {
        int i;
        int ret = 0;
        int cant = 0;

        for(i=0; i<20; i++) // Recorro el array para ver si encuentro un registro que coincida con mi estado.
        {
            if(p[i].idEstado==estado)
            {
                cant++;
                printf("[ID = %d] Nombre: %s | Edad: %d | Dni: %d\n",i+1,p[i].nombre,p[i].edad,p[i].dni);
            }

        }


        if(cant>0) // Si se encontró algun registro se retornará uno.
        {
            ret = cant;
        } else // Sino se retornará cero.
            {
                ret = -1;
            }

            return ret;
    }

/** \brief Devuelve el ID de Grupo correspondiente según el rango de edad.
* \param Int Edad a evaluar
* \return Retorna un INT con el ID del grupo.
*
*/

int asignarGrupo(int edadIngre)
{
    int ret;
    // Dependiendo de la edad de la persona asigno el grupo correspondiente.
    if(edadIngre<=18)
    {
        ret = 1; // Menores de 18 y 18 inclusive..
    } else
        {
            if(edadIngre>=19&&edadIngre<=35)
            {
                ret = 2; // Entre 19 y 35
            } else
                {
                    if(edadIngre>35)
                    {
                        ret = 3; // Mayores de 35
                    }
                }
        }

return ret; // Retorno el id correspondiente.
}

/** \brief Devuelve el ID de Grupo correspondiente según el rango de edad.
* \param Int Edad a evaluar
* \return Retorna un INT con el ID del grupo.
*
*/

int deleteUsser(struct datosPersonas *p)
    {
        int subOpcion=0;
        char flag = 's';
        int acum = 0;
        int cantidad;

        cantidad = printActiveUssersNameList(p, 'a');
        if(cantidad >= 1) // Si hay usuarios activos.
                    {

                            printf("\n\nIngrese el ID de la persona a Borrar:");
                            scanf("%d",&subOpcion); // Ingreso del ID a Borrar
                            system("cls");


                            if(subOpcion<=cantidad)
                            {
                                printPerson(p, subOpcion -1); // Mostramos nuevamente la persona a borrar.

                                printf("Realmente te gustaria borrar a esta persona? S/N");
                                scanf("%c", &flag);
                                flag = tolower(getch());
                                 if(flag == 's')
                            {
                                acum = suprPerson(p, subOpcion-1); // Si responde que quiere borrar, le damos la baja.
                            }

                            }


                        if(acum==1) // Si suprPerson retorno uno, todo salió bien.
                        {
                            printf("\nRegistro borrado correctamente.\n");
                        } else
                            {
                             printf("\nOperacion cancelada..\n");
                            }

                    } else
                        {
                            printf("No hay usuarios activos para borrar.\n");
                        }

        return 0;
    }

/** \brief Ordena alfabeticamente variables de estructura según un campo de cadena de caracteres...
 *
 * \param Estructura a trabajar.
 * \param Tamaño del array de estructuras.
 * \return Retornará: [1] Si todo salió correctamente - [0] De lo contrario.
 *
 */

 int orderPerByName(struct datosPersonas *p, int tama)
    {
        return 1;
    }
