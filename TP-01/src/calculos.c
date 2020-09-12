/*
 * calculos.c
 *
 *  Created on: 4 sep. 2020
 *      Author: Belu
 */

#include "calculos.h"

int suma(int numero1, int numero2)
{
	int total;

	total = numero1 + numero2;

	return total;
}

int resta(int numero1, int numero2)
{
	int total;

	total = numero1 - numero2;

	return total;
}

int multiplicacion (int numero1, int numero2)
{
	int total;

	total = numero1 * numero2;

	return total;
}
float division (int numero1, int numero2)
{
	int total;

	total = numero1 / numero2;

	return total;
}
long factorial(int numero1)
{
    long factoria = 1 ;
    int i;

    for (i = 1; i <= numero1; i++)

    	factoria = factoria*i;

    return factoria;
}




