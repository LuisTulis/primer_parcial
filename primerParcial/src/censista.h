/*
 * censista.h
 *
 *  Created on: 20 may. 2022
 *      Author: Luis
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_


struct
{
	int legajoCensista; // Relacion con la otra estructura
	char nombre[51];
	int edad;
	char telefono[10];
}typedef censista;

#endif /* CENSISTA_H_ */

/** \brief  Muestra todos los censistas registrados
* \param lista censista* Lista a mostrar
* \param largo int longitud del array
*
*/
void listadoCensistas(censista *lista, int largo);

/** \brief  * Recorre todas las posiciones del array, buscando el legajo ingresado
* \param lista censista* Lista a comprobar
* \param largo int longitud del array
* \param legajoIngresado int legajo a comprobar
* \return int Return devuelve 0 si se encontró, -1 si hubo un error.
*
*/
int validarCensista(censista *lista, int largo, int legajoIngresado);
