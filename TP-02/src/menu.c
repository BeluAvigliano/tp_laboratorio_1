/*
 * menu.c
 *
 *  Created on: 27 sep. 2020
 *      Author: Belu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


#include "utn.h"
#include "arrayEmployees.h"

#define len 1000

int opcion(void)
{
    int opcion=0;//Cero es error.
    int auxOpcion;

    if(getInt(&auxOpcion,"\n1.Alta - Ingresar un empleado\n2.Modificar\n3.Baja - Borrar un empleado\n4.Informar\n5.Salir\n\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,5,3)==0)
    {

        opcion=auxOpcion;

    }


    return opcion;
}

int menuDeIngreso(void)
{
	char respuesta = 's';
	int banderaDelPrimero = 1;



		Employee aEmpleadoIngresado[len];

		initEmployees(aEmpleadoIngresado, len);

		do
		{
			switch(opcion())
			{
			case 1:
				banderaDelPrimero = 1;
				cargarEmpleado(aEmpleadoIngresado, len);
				break;
			case 2:
				if(banderaDelPrimero == 1)
				{
					banderaDelPrimero = 1;
					menuModificar(aEmpleadoIngresado, len);

				}else
				{
					printf("\nPrimero debe ingresar un empleado .\n");
				}

				break;
			case 3:
				if(banderaDelPrimero == 1)
				{
					banderaDelPrimero = 1;
					menuBorrar(aEmpleadoIngresado, len);
				}else
				{
					printf("\nPrimero debe ingresar un empleado .\n");
				}

				break;
			case 4:

				if(banderaDelPrimero == 1)
				{
					banderaDelPrimero = 1;
					pedirOrden(aEmpleadoIngresado, len);

					printEmployees(aEmpleadoIngresado, len);
				}else
				{
					printf("\nPrimero debe ingresar un empleado .\n");
				}


				break;
			case 5:
				printf("\nDesea Seguir?\n");
				printf("\nSi=s");
				printf("\nNo=n\n");
				scanf("%c", &respuesta);
				fflush(stdin);
				break;
			}
			system("CLS");
		}while(respuesta == 's');

		return EXIT_SUCCESS;

}
