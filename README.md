# ABML - Desarrollo de bibliotecas.

-> regOff(); - Encuentra el primer registro vácio ( Hay que estandarizarla ).

-> validateIsNum(); - Funcionando correctamente.

-> validateIsName(); - Funcionando correctamente.

-> validateIsPos(); (Valida si es positivo) - Funcionando correctamente.

-> validateIsNotZero(); - Funcionando correctamente.

#Desarrollando actualmente - Funciones:
- validateIsField(); - Una sola funcion que valida en funcion del argumento que se le pasa por valor. (Valida multiples criterios).

#Desarrollando actualmente - Módulos:

1 - Alta Standar (Útil para cualquier ABML solo modificando algunas cosas) // La anterior era muy enquilombada.
Funciones que utiliza: -> regOff(); -> validateIsField();
*Es recomendable tener una cascara harcodeada para copypastear.

2 - Modificacion Standar (Útil para cualquier ABML solo modificando algunas cosas)
validateIsField();

3 - Baja Standar (Útil para cualquier ABML solo modificando algunas cosas)
100% Funcional 
*// Solo es necesario cambiarle el puntero a la estructura y que el id de estado sea isEmpty.
