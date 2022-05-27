/*
 * censista.c
 *
 *  Created on: 20 may. 2022
 *      Author: Luis
 */

#include "censista.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "vivienda.h"

void listadoCensistas(censista *lista, int largo, vivienda *listaViviendas, int largoVivienda)
{
	setbuf(stdout, NULL);
	int i;
	int flagMaximo = 1;
	int maximo;
	int cantidadAux;
	char censistaMaximo[20];
	for(i=0; i < largo; i++)
	{
		printf("Legajo: %d | %s | %d años | %s \n ------------------------------ \n", (*(lista+i)).legajoCensista, (*(lista+i)).nombre, (*(lista+i)).edad, (*(lista+i)).telefono);

		listadoViviendasPorCensista(listaViviendas, largoVivienda, (*(lista+i)).legajoCensista);
		cantidadAux = maximoCensado(listaViviendas, largoVivienda, (*(lista+i)).legajoCensista);

		if(cantidadAux > maximo || flagMaximo == 1)
		{
			maximo = cantidadAux;
			flagMaximo = 0;
			strcpy(censistaMaximo, (*(lista+i)).nombre);
		}
		else
		{
			if(cantidadAux == maximo)
			{
				strcat(censistaMaximo, ", ");
				strcat(censistaMaximo, (*(lista+i)).nombre);
			}
		}

	}
	printf("\n%s fue/fueron quienes mas viviendas censaron\n", censistaMaximo);
}

int validarCensista(censista *lista, int largo, int legajoIngresado)
{
	int i;
	for(i = 0; i < largo; i ++)
	{
		if( (*(lista+i)).legajoCensista == legajoIngresado)
		{
			return 0;
		}
	}

	return -1;
}

void listadoViviendasPorCensista(vivienda *listaVivienda, int largo, int legajo)
{
	setbuf(stdout, NULL);
	int i;

	for(i=0; i < largo; i++)
	{
		if((*(listaVivienda+i)).idVivienda != -1 && (*(listaVivienda+i)).legajoCensista == legajo)
		{
			char tipoAux[20];
			switch((*(listaVivienda+i)).tipoVivienda)
			{
				case 1:
				{
					strcpy(tipoAux, "Casa");
					break;
				}
				case 2:
				{
					strcpy(tipoAux, "Departamento");
					break;
				}
				case 3:
				{
					strcpy(tipoAux, "Casilla");
					break;
				}
				case 4:
				{
					strcpy(tipoAux, "Rancho");
					break;
				}
			}
			printf("-\tId: %d | Calle: %s | Cantidad de personas: %d | Cantidad de habitaciones: %d | Tipo de vivienda: %s | Legajo del censista encargado %d \n", (*(listaVivienda+i)).idVivienda, (*(listaVivienda+i)).calle, (*(listaVivienda+i)).cantidadPersonas, (*(listaVivienda+i)).cantidadHabitaciones, tipoAux, (*(listaVivienda+i)).legajoCensista);
		}
	}
}

int maximoCensado(vivienda *listaViviendas, int largo, int legajoAContar)
{
	int contador = 0;
	for(int i = 0; i<largo; i++)
	{
		if((*(listaViviendas+i)).legajoCensista == legajoAContar)
		{
			contador ++;
		}
	}

	return contador;
}
