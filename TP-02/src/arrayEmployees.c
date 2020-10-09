/*
 * ArrayEmployees.c
 *
 *  Created on: 27 sep. 2020
 *      Author: Belu
 */
#define MAX_CARACTERES 51


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stddef.h>


#include "arrayEmployees.h"
#include "utn.h"

int initEmployees(Employee* aEmpleadoIngresado, int len)
{
    if (len < 1) return -1; // si no hay elementos retorna -1

    for (int i = 0 ; i < len ; i++) {
    	aEmpleadoIngresado[i].isEmpty = 1; 			//inicializo todos los campos y pongo el campo empty accesible para cargar datos.
    	aEmpleadoIngresado[i].id = 0;
    	strcpy(aEmpleadoIngresado[i].name, " ");
    	strcpy(aEmpleadoIngresado[i].lastName, " ");
    	aEmpleadoIngresado[i].salary = 0;
    	aEmpleadoIngresado[i].sector = 0;
    }

 return 0;
}

int buscarLibre(Employee* aEmpleadoIngresado, int len, int* posicion) // "1 ES LIBRE.
{
	int i;
	    if (aEmpleadoIngresado != NULL && len > 0)
	    {
	        for (i = 0 ; i < len; i ++)
	        {
	            if (aEmpleadoIngresado[i].isEmpty == 1 )
	            {
	               *posicion = i;
	               return 1;
	            }
	        }
	    }
	   return 0;
}

int addEmployee(Employee* aEmpleadoIngresado, int len, int id, char name[],char lastName[],float salary, int sector, int* posicion)
{
	if(aEmpleadoIngresado != NULL && len > 0)
	{
			//posicion = buscarLibre(aEmpleadoIngresado, len, posicion);
			aEmpleadoIngresado[*posicion].isEmpty = 0;
			aEmpleadoIngresado[*posicion].id = id;
			strcpy(aEmpleadoIngresado[*posicion].name, name);
			strcpy(aEmpleadoIngresado[*posicion].lastName, lastName);
			aEmpleadoIngresado[*posicion].salary = salary;
			aEmpleadoIngresado[*posicion].sector = sector;

			return 0;
	}
 return -1;
}

int numeroId(Employee* aEmpleadoIngresado, int len)
{
	int i;
	int contador = 0;

	for(i = 0;i < len; i++)
	{
		if(aEmpleadoIngresado[i].isEmpty != 1)
		{
			contador = contador+1;
		}
	}
	contador = contador+1;

	return contador;
}

int cargarEmpleado(Employee* aEmpleadoIngresado, int len)
{
	 int posicionLibre;
	 char auxNombre[MAX_CARACTERES];
	 char auxApellido[MAX_CARACTERES];
	 float auxSalario;
	 int auxSector;
	 int auxLegajo;
	 int posicion;
	 int contadorId = 0;

	 contadorId = numeroId(aEmpleadoIngresado, len);

	 posicionLibre = buscarLibre(aEmpleadoIngresado, len, &posicion);
	 if(posicionLibre == 1)
	 {
	 		 if(!getInt(&auxLegajo,"Ingrese legajo, debe estar entre 1 y 1000","Error, El legajo debe de estar entre 1 y 1000\n",1 ,9 ,3) == 0)
	 		 {
	 			 return 1;
	 		 }

	 		 if(!getString(auxNombre,"Ingrese su nombre","Error. El nombre debe contener minimo 2 y maximo 50 caracteres.\n",2 ,MAX_CARACTERES-1 ,3) == 0)
	 		 {
	 			 return 1;
	 		 }

	 		 if(!getString(auxApellido,"Ingrese su apellido","Error. El apellido debe contener minimo 2 y maximo 50 caracteres.\n",2 ,MAX_CARACTERES-1 ,3) == 0)
	 		 {
	 			 return 1;
	 		 }

	 		 if(!getFloat(&auxSalario,"Ingrese el salario: ","Error, el salario no debe ser menor a 0 y mayor a 1000000\n", 1, 1000000) == 0)
	 		 {
	 			 return 1;
	 		 }

	 		if(!getInt(&auxSector,"Ingrese el sector que corresponde 1.RRHH, 2.ADM, 3.LEGAL, 4.PLANTA, 5.JEFE ","Error, el sector debe ser 1.RRHH, 2.ADM, 3.LEGAL, 4.PLANTA, 5.JEFE \n", 1, 5, 3) == 0)
	 		{
	 			 return 1;
	 		}


	 	addEmployee(aEmpleadoIngresado, len, contadorId,  auxNombre, auxApellido, auxSalario, auxSector, &posicion);
	 }else
	 {
		 printf("No hay posiciones libres");
	 }
	return 0;
}


int findEmployeeById(Employee* aEmpleadoIngresado, int len,int id)
{

	int i;
	int posicion = -1;  //-1 es el error

	for(i = 0; i < len; i++)
	{
		if(aEmpleadoIngresado[i].id == id)
		{
			posicion = i;
		}
	}

	return posicion;
}

void menuModificar(Employee* aEmpleadoIngresado, int len)
{
	int pedirId;
	int posicion;



	if(getInt(&pedirId,"Escribir el numero de ID","Error, ingrese un valor numerico",1,999,3)==0)
	    {
			posicion = findEmployeeById(aEmpleadoIngresado, len, pedirId);
	        if(posicion == -1)
	        {
	        	printf("No existe el ID");
	        }else
	        {
	        	modificarEmpleado(aEmpleadoIngresado, len, posicion);

	        }

	    }
}


int modificarEmpleado(Employee* aEmpleadoIngresado, int len, int posicion)
{
	char respuesta = 'n';
	int opcionModificar;
	char auxNombre[MAX_CARACTERES];
	char auxApellido[MAX_CARACTERES];
	float auxSalario;
	int auxSector;



	if(!getInt(&opcionModificar,"1.Modificar - Nombre\n2.Modificar - Apellido\n3.Modificar - Salario\n4.Modificar - Sector\n5. Salir\nElija una opcion:","Error. Elija una de las opciones dadas.\n",1,5,3)==0)
	{

		return 1;
    }

		do
		{
			switch(opcionModificar)
			{
			case 1:
				if(!getString(auxNombre,"Ingrese el nombre que quiere modificar","Error. El nombre debe contener minimo 2 y maximo 50 caracteres.\n",2 ,MAX_CARACTERES-1 ,3) == 0)
				 {
					 return 1;
				 }else
				 {
					 strcpy(aEmpleadoIngresado[posicion].name, auxNombre);
					 respuesta = 's';
				 }
				break;
			case 2:
				 if(!getString(auxApellido,"Ingrese su apellido que quiere modificar","Error. El apellido debe contener minimo 2 y maximo 50 caracteres.\n",2 ,MAX_CARACTERES-1 ,3) == 0)
				 {
					 return 1;
				 }else
				 {
					 strcpy(aEmpleadoIngresado[posicion].lastName, auxApellido);
					 respuesta = 's';
				 }
				break;
			case 3:
				if(!getFloat(&auxSalario,"Ingrese el salario que quiere modificar: ","Error, el salario no debe ser menor a 0 y mayor a 1000000\n", 1, 1000000) == 0)
				{
					 return 1;
				}else
				{
					aEmpleadoIngresado[posicion].salary = auxSalario;
					respuesta = 's';
				}
				break;
			case 4:
				if(!getInt(&auxSector,"Ingrese el sector que corresponde modificar 1.RRHH, 2.ADM, 3.LEGAL, 4.PLANTA, 5.JEFE ","Error, el sector debe ser 1.RRHH, 2.ADM, 3.LEGAL, 4.PLANTA, 5.JEFE \n\n", 1, 5, 3) == 0)
				{
					return 1;
				}else
				{
					aEmpleadoIngresado[posicion].sector = auxSector;
					respuesta = 's';
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

		}while(respuesta == 'n');

		return EXIT_SUCCESS;
}


int removeEmployee(Employee* aEmpleadoIngresado, int len, int id)
{
	int i;

	for(i = 0;i < len; i++)
	{
		if(aEmpleadoIngresado[i].id == id)
		{
			aEmpleadoIngresado[i].isEmpty = 1;
			aEmpleadoIngresado[i].id = 0;
			strcpy(aEmpleadoIngresado[i].name, " ");
			strcpy(aEmpleadoIngresado[i].lastName, " ");
			aEmpleadoIngresado[i].salary = 0;
			aEmpleadoIngresado[i].sector = 0;
		}
	}
 return -1;
}

void menuBorrar(Employee* aEmpleadoIngresado, int len)
{
	int pedirId;
	int posicion;

	if(getInt(&pedirId,"Escribir el numero de ID","Error, ingrese un valor numerico",1,999,3)==0)
	    {
			posicion = findEmployeeById(aEmpleadoIngresado, len, pedirId);
	        if(posicion == -1)
	        {
	        	printf("No existe el ID");
	        }else
	        {
	        	removeEmployee(aEmpleadoIngresado, len, pedirId);

	        }

	    }
}
int pedirOrden(Employee* aEmpleadoIngresado, int len)
{
	int opcionOrden;
	int superanPromedio;
	float sumaSalario;
	float promedioSalario;

	if(!getInt(&opcionOrden,"Como quiere visualizar los datos: \n1.Ascendente(a-z)\n 2.Descendente (z-a) \n 3. Salir\n","Error. Elija una de las opciones dadas.\n",1,3,3)==0)
	{
		return 1;
	}

	sortEmployees(aEmpleadoIngresado, len, opcionOrden);


	sumaSalario = sumaSalarios(aEmpleadoIngresado,len);
	printf("La suma total de todos los sueldos es de: %.2f\n", sumaSalario);

	promedioSalario = promedioSueldos(aEmpleadoIngresado,len);
	printf("El promedio de todos los sueldos es de: %.2f\n", promedioSalario);

	superanPromedio = superanSalarioPromedio(aEmpleadoIngresado, len);
	printf("La cantidad de personas que superan el promedio es: %d\n", superanPromedio);

	return 0;
}
int sortEmployees(Employee* aEmpleadoIngresado, int len, int order) // si retorna -1 es ERROR.
{

	Employee auxiliar;
	int i;
	int j;

		for(i = 0; i < len - 1; i++)
		{
			for(j = 0; j < len; j++)
			{
				if(aEmpleadoIngresado[i].isEmpty == 0 && aEmpleadoIngresado[j].isEmpty == 0)
				{
					if(order ==1)
					{
						if(strcmp(aEmpleadoIngresado[i].lastName, aEmpleadoIngresado[j].lastName) == 0 && aEmpleadoIngresado[i].sector < aEmpleadoIngresado[j].sector)
						{
							auxiliar = aEmpleadoIngresado[i];
							aEmpleadoIngresado[i] = aEmpleadoIngresado[j];
							aEmpleadoIngresado[j] = auxiliar;

						}

					}

				}
			}

		}

		for(i = 0; i < len - 1; i++)
			{
				for(j = 0; j < len; j++)
				{
					if(aEmpleadoIngresado[i].isEmpty == 0 && aEmpleadoIngresado[j].isEmpty == 0)
					{
						if(order == 2 )
						{
							if(strcmp(aEmpleadoIngresado[i].lastName, aEmpleadoIngresado[j].lastName) == 0 && aEmpleadoIngresado[i].sector > aEmpleadoIngresado[j].sector)
							{
								auxiliar = aEmpleadoIngresado[i];
								aEmpleadoIngresado[i] = aEmpleadoIngresado[j];
								aEmpleadoIngresado[j] = auxiliar;
							}
						}
					}
				}
			}

	for(i = 0;i < len-1; i++)
	{
		for(j = i+1;j < len; j++)
		{
			if(aEmpleadoIngresado[i].isEmpty == 0 && aEmpleadoIngresado[j].isEmpty == 0)
			{
				if(order == 1)
				{
					if(strcmp(aEmpleadoIngresado[i].lastName,aEmpleadoIngresado[j].lastName) > 0)
					{
						auxiliar = aEmpleadoIngresado[i];
						aEmpleadoIngresado[i] = aEmpleadoIngresado[j];
						aEmpleadoIngresado[j] = auxiliar;
					}
				}else
				{
					if(order == 2)
					{
						if(strcmp(aEmpleadoIngresado[i].lastName,aEmpleadoIngresado[j].lastName) < 0)
						{
							auxiliar = aEmpleadoIngresado[i];
							aEmpleadoIngresado[i] = aEmpleadoIngresado[j];
							aEmpleadoIngresado[j] = auxiliar;
						}
					}
				}
			}
		}
	}
	return EXIT_SUCCESS;
}




float sumaSalarios(Employee* aEmpleadoIngresado, int len)
{
	int i;
	float acumuladorSueldo = 0;

	for(i = 0;i < len ; i++)
	{
		if(aEmpleadoIngresado[i].isEmpty == 0)
		{

			acumuladorSueldo = acumuladorSueldo + aEmpleadoIngresado[i].salary;
		}
	}
	return acumuladorSueldo;
}

float promedioSueldos(Employee* aEmpleadoIngresado, int len)
{
	int contadorEmpleado = 0;
	float promedioSalario;
	int i;

	for(i = 0;i < len; i++)
	{
		if(aEmpleadoIngresado[i].isEmpty == 0)
		{
			contadorEmpleado++;
		}
	}
	promedioSalario = sumaSalarios(aEmpleadoIngresado, len) / contadorEmpleado;

	return promedioSalario;
}

int superanSalarioPromedio(Employee* aEmpleadoIngresado, int len)
{
	int i;
	float valorPromedioSalario;
	int contEmpleadoSuperanPromedio = 0;

	valorPromedioSalario = promedioSueldos(aEmpleadoIngresado, len);

	for(i = 0;i < len ; i++)
	{
		if(aEmpleadoIngresado[i].isEmpty == 0 && aEmpleadoIngresado[i].salary > valorPromedioSalario)
		{
			contEmpleadoSuperanPromedio++;
		}
	}

	return contEmpleadoSuperanPromedio;

}






int printEmployees(Employee* list, int length)
{
	int i;

	printf("\n****************************************************\n");
	printf("\n**ID    Nombre      Apellido      Salario   sector*\n");
	printf("\n****************************************************\n");

	for(i = 0; i < length; i++)
	{
		if(list[i].isEmpty == 0)
		{
		printf("  %d", list[i].id);
		printf("  %s",list[i].name);
		printf("  %s",list[i].lastName);
		printf("  %.2f",list[i].salary);
		printf("  %d\n",list[i].sector);
		}
	}
	printf("\n****************************************************\n");
	return 0;

}









