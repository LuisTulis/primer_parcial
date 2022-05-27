/*
 * censista.h
 *
 *  Created on: 20 may. 2022
 *      Author: Luis
 */

#include "vivienda.h"

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
void listadoCensistas(censista *lista, int largo, vivienda *listaViviendas, int largoVivienda);

/** \brief  * Recorre todas las posiciones del array, buscando el legajo ingresado
* \param lista censista* Lista a comprobar
* \param largo int longitud del array
* \param legajoIngresado int legajo a comprobar
* \return int Return devuelve 0 si se encontró, -1 si hubo un error.
*
*/
int validarCensista(censista *lista, int largo, int legajoIngresado);

/** \brief  * Muestra todas las viviendas separando por legajo de censista
* \param lista censista* Lista a leer
* \param largo int longitud del array
*
*/
void listadoViviendasPorCensista(vivienda *lista, int largo, int legajo);

/** \brief  * Lee todo el array de viviendas, comparando el legajo con el introducido
* \param lista censista* Lista a leer
* \param largo int longitud del array
* \param legajoAContar int Legajo que se compara
*
* \return Devuelve la cantidad de viviendas que tengan ese legajo
*/
int maximoCensado(vivienda *listaViviendas, int largo, int legajoAContar);
