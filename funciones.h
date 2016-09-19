#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct datosPersonas{

    int id;
    char nombre[50];
    int edad;
    char idEstado;
    int dni;
    int idGrupo;

};



struct datosEstados
{
    char idEstado;
    char descripcionEstado[50];
};





struct datosGrupos
{
    int idGrupo;
    char descripcionGrupo[50];
    char idEstado;
};





/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int regOff(struct datosPersonas *p);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
//int buscarPorDni(EPersona lista[], int dni);

/**
 * Formulario de carga de persona.
 */

void loadPerson(struct datosPersonas *p);

/**
 * Muestra según el Id ingresado el grupo correspondiente.
  * @param Id del grupo.
 */

void printGroup(int group);

/**
 * Inicializa todos los estados de las personas en "BAJA".
 * @param Variable de la estructura a trabajar..
 * @return Retorna en tipo entero la cantidad de registros inicializados.
 */

int inicializarRegistros(struct datosPersonas *p);

/**
 * Imprime un registro entero indicando el ID.
 * @param arreglo de estructura a mostrar.
 * @param id del registro a mostrar.
 */
void printPerson(struct datosPersonas *p, int id);

/** \brief
* \param
* \return
*
*/
int suprPerson(struct datosPersonas *p,int id); // Comentarrrrrrrrrrrrrrrrrrrr
/** \brief
* \param
* \return
*
*/
int regCantOff(struct datosPersonas *p);
/** \brief
* \param
* \return
*
*/
void printActiveUssersNameList(struct datosPersonas *p);
/** \brief
* \param
* \return
*
*/
 int validateIsName(char name[]);
 /** \brief
* \param
* \return
*
*/
int validateIsNum(char num[], int tipo);

#endif // FUNCIONES_H_INCLUDED
