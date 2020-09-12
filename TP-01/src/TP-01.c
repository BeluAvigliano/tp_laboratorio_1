/*
 ============================================================================
 Name        : TP-01.c
 Author      : Avigliano, Maria Belen.
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include <ctype.h>
#include <conio.h>

int main() {
	setbuf(stdout, NULL);

	int numero1;
	int numero2;
	int opcion;
	char opcionDeCalcular;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	long resultadoFactorialA;
	long resultadoFactorialB;

	int banderaDelPrimero = 0;
	int banderaDelSegundo = 0;
	int banderaDelTercero = 0;


	char salir;

	char respuesta = 's';



while(respuesta == 's')
	{

				printf("\n1- Ingresar el primer numero A=\n");
	            printf("2- Ingresar el segundo numero B= B\n");
	            printf("3- Realizar calculos \n");
	            printf("4- Mostrar resultados\n");
	            printf("5- Salir?\n");
	            scanf("%d",&opcion);
	            fflush(stdin);
	            system("cls");

	            //printf("imprimir el valor %d", opcion);
	            switch(opcion)
	            {
	            case 1:
	            	printf("Ingresar el primer numero A=\n");
	            	fflush(stdin);
	            	scanf("%d", &numero1);
	            	banderaDelPrimero = 1;
	            	break;
	            case 2:
	            	if(banderaDelPrimero == 1)
					{
	            		banderaDelSegundo = 1;
	            		printf("\nIngresar el segundo numero B= \n");
	            		fflush(stdin);
	            	  	scanf("%d", &numero2);

					}else
					{
						printf("\nDebe ingresar el numero A antes.\n");
					}
	            	break;
	            case 3:
	            	if(banderaDelSegundo != 1 && banderaDelPrimero != 1)
	                  	{
	            		 	printf("\nDebe ingresar los numeros A y B\n");
	                  	}

	            	while(banderaDelSegundo == 1 && banderaDelPrimero == 1
	            			&& ( salir != 'X' ) )
	            	{
	            		banderaDelTercero = 1;
	            		printf("\nA)Calcular la suma de %d + %d", numero1, numero2);
	            			printf("\nB)Calcular la resta de %d - %d", numero1, numero2);
	            			printf("\nC)Calcular la multiplicacion de %d * %d", numero1, numero2);
	            			printf("\nD)Calcular la division de %d / %d", numero1, numero2);
	            			printf("\nE)Calcular el factorial de %d y %d", numero1, numero2);
	            			printf("\nF)Calcular todas las operaciones\n");
	            			fflush(stdin);
	            			scanf("%c", &opcionDeCalcular);


	            			switch(opcionDeCalcular)
	            			{
	            			case 'A':
	            				resultadoSuma = suma(numero1, numero2);
	            				salir = 'X';
	            				break;
	            			case 'B':
	            				resultadoResta = resta(numero1, numero2);
	            				salir = 'X';
	            				break;
	            			case 'C':
	            				resultadoMultiplicacion = multiplicacion (numero1, numero2);
	            				salir = 'X';
	            				break;
	            			case 'D':
	            				resultadoDivision = division (numero1, numero2);
	            				salir = 'X';
	            				break;
	            			case 'E':
	            				resultadoFactorialA = factorial (numero1);
	            				resultadoFactorialB = factorial (numero2);
	            				salir = 'X';
	            				break;
	            			case 'F':
	            					resultadoSuma = suma(numero1, numero2);
	            					resultadoResta = resta(numero1, numero2);
	            					resultadoMultiplicacion = multiplicacion (numero1, numero2);
	            					resultadoDivision = division (numero1, numero2);
	            					resultadoFactorialA = factorial (numero1);
	            					resultadoFactorialB = factorial (numero2);
	            					salir = 'X';
	            			}
	            	}


	            	break;
	            case 4:
	            	if(banderaDelTercero != 1)
	            	{
	            	printf("\nTiene que ingresar los numeros.\n");
	            	}else
	            	{
	            		switch(opcionDeCalcular)
	            		{
	            		case 'A':
	            			printf("\nEl resultado de la suma de %d + %d es: %d\n", numero1, numero2, resultadoSuma );
	            			break;
	            		case 'B':
	            			printf("\nEl resultado de la resta de %d + %d es: %d\n", numero1, numero2, resultadoResta);
	            			break;
	            		case 'C':
	            			printf("\nEl resultado de la multiplicacion de %d + %d es: %dv\n", numero1, numero2, resultadoMultiplicacion);
	            			break;
	            		case 'D':
	            			printf("\nEl resultado de la division de %d + %d es: %2.f\n", numero1, numero2, resultadoDivision);
	            			break;
	            		case 'E':
	            			printf("\nEl resultado del factorial de A es: %li y El resultado del factorial de B es: %li\n", resultadoFactorialA, resultadoFactorialB);
	            			break;
	            		case 'F':
	            			printf("\nEl resultado de la suma de %d + %d es: %d\n", numero1, numero2, resultadoSuma);
	            			printf("\nEl resultado de la resta de %d - %d es: %d\n", numero1, numero2, resultadoResta);
	            			printf("\nEl resultado de la multiplicacion de %d * %d es: %d\n",numero1, numero2, resultadoMultiplicacion);
	            			printf("\nEl resultado de la division de %d / %d es: %2.f\n", numero1, numero2, resultadoDivision);
	            			printf("\nEl resultado del factorial de A es: %li y El resultado del factorial de B es: %li\n", resultadoFactorialA, resultadoFactorialB);
	            			break;
	            		}
	            		salir = ' ';
	            		banderaDelPrimero = ' ';
	            		banderaDelSegundo = ' ';
	            		banderaDelTercero = ' ';
					}


	              	 break;
	            case 5:
	            	printf("\nDesea Seguir?\n");
	            			printf("\nSi=s");
	            			printf("\nNo=n\n");
	            			scanf("%c", &respuesta);
	            			fflush(stdin);


	            }//switch

	}return EXIT_SUCCESS;
}
