/*
 * vivienda.h
 *
 *  Created on: 20 may. 2022
 *      Author: Luis
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

struct
{
	int idVivienda; //empieza en 20000, autoincremental
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda; // (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO)
	int legajoCensista; // (debe existir) Validar
}typedef vivienda;

#endif /* VIVIENDA_H_ */

/** \brief  * Recorre todas las posiciones del array, poniendo las id en -1
* \param lista censista* Lista a inicializar
* \param largo int longitud del array
* \return int Return devuelve 0 si se pudo, -1 si hubo un error.
*
*/
int initVivienda(vivienda *list, int len);

/** \brief  * Recorre todas las posiciones del array, buscando el id -1 para agregar los datos
* \param lista censista* Lista a agregar
* \param largo int longitud del array
* \return int Return devuelve 0 si se pudo agregar, -1 si hubo un error.
*
*/
int altaVivienda(vivienda *list, int len, int id, char calle[], int personas, int habitaciones, int tipoVivienda, int legajoCensista);

/** \brief  * Recorre todas las posiciones del array, ordenandolas por calle y cantidad de pasajeros
* \param lista censista* Lista a ordenar
* \param largo int longitud del array
*
*/
void ordenarViviendas(vivienda *lista, int largo);

/** \brief  * Muestra todas las viviendas
* \param lista censista* Lista a leer
* \param largo int longitud del array
*
*/
void listadoViviendas(vivienda *lista, int largo);

/** \brief  * Recorre todas las posiciones del array, buscando el legajo ingresado
* \param lista vivienda* Lista a comprobar
* \param largo int longitud del array
* \param id int id a buscar
* \return int Return devuelve la posicion en el array, -1 si hubo un error.
*
*/
int buscarViviendaPorID(vivienda *lista, int largo, int id);

/** \brief  * Busca la posicion y cambia su id por -1
* \param lista censista* Lista a comprobar
* \param largo int longitud del array
* \param posicion int Posicion a buscar
*
*/
void eliminarVivienda(vivienda *lista, int largo, int posicion);
