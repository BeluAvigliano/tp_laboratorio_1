/*
 * arrayEmployees.h
 *
 *  Created on: 29 sep. 2020
 *      Author: Belu
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;

/* * \ brief Para indicar que todas las posiciones en la matriz están vacías,
* esta función pone la bandera (isEmpty) en VERDADERO en todas las  posiciónes de la matriz
* \ param aEmpleadoIngresado Employee * Puntero a la matriz de empleados
* \ param len int Longitud de la matriz
* \ return int Devuelve (-1) si Error [Longitud inválida o puntero NULO] - (0) si está bien
*/
int initEmployees(Employee* list, int len);

/* * \ brief agregar en una lista existente de empleados los valores pedidos por teclado
 * \param aEmpleadoIngresado employee*
 * \param len int
 * \param posicion int*
* \ return int Devuelve 1 si esta libre y 0 si no esta libre
*/
int buscarLibre(Employee* aEmpleadoIngresado, int len, int* posicion);//int buscarLibre(Employee* aEmpleadoIngresado, int len, int* posicion);//int buscarLibre(Employee* list, int len, int* posicion);



/* * \ brief agregar en una lista existente de empleados los valores recibidos como parámetros en la primera posición vacía empleado de la lista de parámetros *
 * \param aEmpleadoIngresado employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
* \ return int Devuelve (-1) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (0) si está bien
*/
int addEmployee(Employee* aEmpleadoIngresado, int len, int id, char name[],char lastName[],float salary, int sector, int* posicion);

/* * \ brief crea el numero ID de manera secuencial y automatica
 * \param aEmpleadoIngresado employee*
 * \param len int
* \ return int Devuelve (-1) si Error [Longitud inválida o puntero NULL o sin espacio libre] - (0) si está bien
*/
int numeroId(Employee* aEmpleadoIngresado, int len);

/* * \ brief agregar en una lista existente de empleados los valores recibidos por teclado a las variables auxiliares*
 * \param aEmpleadoIngresado employee*
 * \param len int
* \ return int Devuelve (1) si es Error (0) si está bien
*/
int cargarEmpleado(Employee* aEmpleadoIngresado, int len);

/** \brief Encuentra el primer índice vacío en una matriz empleado de la lista de parámetros *
 *
 * \param aEmpleadoIngresado Employee*
 * \param len int
 * \param id int
 * \return Return int
 */
int findEmployeeById(Employee* aEmpleadoIngresado, int len,int id);

/** \brief Creo un menu de opciones para saber que quiere modificar
 *
 * \param aEmpleadoIngresado Employee*
 * \param len int
 * \return Return nada
 */
void menuModificar(Employee* aEmpleadoIngresado, int len);

/** \brief Modifica el valor que necesita.
 *
 * \param aEmpleadoIngresado Employee*
 * \param len int
 * \param posicion int
 * \return Return int 1 si esta algo mal cargado y 0 si esta bien cargado
 */
int modificarEmpleado(Employee* aEmpleadoIngresado, int len, int posicion);

/** \brief Eliminar a un empleado por Id (poner la bandera isEmpty en 1)
 *
 * \param aEmpleadoIngresado Employee*
 * \param len int
 * \param id int
 * \return int Retorna (-1) si Error [Longitud inválida o puntero NULL o si no puede
buscar un empleado] - (0) si está bien
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Creo un menu de opciones para saber que quiere borrar
 *
 * \param aEmpleadoIngresado Employee*
 * \param len int
 * \return Return nada
 */
void menuBorrar(Employee* aEmpleadoIngresado, int len);

/** \brief Pido el orden en el que quiero ordenar mi estructura/matriz
 *
 * \param aEmpleadoIngresado Employee*
 * \param len int
 * \return Return nada
 */
int pedirOrden(Employee* aEmpleadoIngresado, int len);

/** \brief Ordenar los elementos en la matriz de empleados
 *
 * \param aEmpleadoIngresadi Employee*
 * \param len int
 * \param order int [1] Ascendente - [2] Descendente
 * \return int Devuelve (-1) si Error [Longitud inválida o puntero NULO] - (0) si está bien
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief imprime el contenido de la matriz de empleados
 *
 * \param aEmpleadoIngresado Employee*
 * \param len int
 * \return
 *
 */
int printEmployees(Employee* list, int length);

/** \brief Suma la totalidad de todos los salarios
 *
 * \param aEmpleadoIngresado Employee*
 * \param len int
 * \return Return un float
 */
float sumaSalarios(Employee* aEmpleadoIngresado, int len);

/** \brief Cuenta la cantidad de empleados que hay y saca el promedio de los sueldos
 *
 * \param aEmpleadoIngresado Employee*
 * \param len int
 * \return Return float
 */
float promedioSueldos(Employee* aEmpleadoIngresado, int len);

/** \brief cuenta la cantidad de empleados que superan el salario promedio.
 *
 * \param aEmpleadoIngresado Employee*
 * \param len int
 * \return Return int
 */
int superanSalarioPromedio(Employee* aEmpleadoIngresado, int len);

#endif /* ARRAYEMPLOYEES_H_ */
