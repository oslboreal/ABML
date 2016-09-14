#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


float sumarOperandos(float x,float y);
float restarOperandos(float x, float y);
float realizarDivision(float x, float y);
float realizarMultiplicacion(float primerValor, float segundoValor);
void mostrarAlerta(char mensaje[100],float primerValor, float segundoValor,int importante, char resultado[50]);
int validateIsNum(char num[], int tipo);
float factorialDeNum(int n);
float inputOperator(char operandoValidar[50], float primerOperandoActual, float segundoOperandoActual);
int esPositivo(int x);

int aIntOrder(int *arr[]);
// Intercambio
int swapInt(int *, int *);
int swapChar(char *, char *);
int swapFloat(float *, float *);

// Interface.
void loadMenu(int segu,const char menu[]);

#endif // FUNCIONES_H_INCLUDED
