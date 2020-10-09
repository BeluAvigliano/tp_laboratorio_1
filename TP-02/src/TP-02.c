/*
 ============================================================================
 Name        : TP-02.c
 Author      : Avigliano, Maria Belen
 Version     :
 Copyright   : Your copyright notice
 Description : TP-02
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stddef.h>

#include "arrayEmployees.h"
#include "menu.h"
#include "utn.h"

#define MAX_CARACTERES 51

#define len 6
int main(void)
{
	setbuf(stdout, NULL);

	menuDeIngreso();

	return EXIT_SUCCESS;
}
