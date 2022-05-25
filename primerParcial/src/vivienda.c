/*
 * vivienda.c
 *
 *  Created on: 20 may. 2022
 *      Author: Luis
 */

#include "vivienda.h"
#include <stdio.h>
#include <string.h>

int initVivienda(vivienda *list, int len)
{
	int i = 0;

	if(list == NULL)
	{
		return -1;
	}
	for (; i < len; i++) {
		(*(list+i)).idVivienda = -1;
	}

	return 0;
}

int altaVivienda(vivienda *list, int len, int id, char calle[], int personas, int habitaciones, int tipoVivienda, int legajoCensista) {

	setbuf(stdout, NULL);
	int i = 0;
	int retorno;
	if(list == NULL)
	{
		return -1;
	}
	for (; i < len; i++)
	{
		if ((*(list+i)).idVivienda == -1)
		{
			(*(list+i)).idVivienda = id;
			strcpy((*(list+i)).calle, calle);
			(*(list+i)).cantidadPersonas = personas;
			(*(list+i)).cantidadHabitaciones = habitaciones;
			(*(list+i)).tipoVivienda = tipoVivienda;
			(*(list+i)).legajoCensista = legajoCensista;
			printf("\nEl id de la vivienda es %d\n", id);

			retorno = 0;
			break;
		}
		else
		{
			retorno = -1;
		}

	}
	return retorno;
}

void ordenarViviendas(vivienda *lista, int largo)
{
	int i;
	int j;
	int value = 0;

	vivienda listaAux;

	for(i = 0; i < largo; i++)
	{
		for (j = i+1; j < largo; j++)
		{

			if ((*(lista+j)).idVivienda != -1)
			{
				value = strcmp( (*(lista+i)).calle, (*(lista+j)).calle );

					if(value != 1)
					{
						if((*(lista+i)).cantidadPersonas > (*(lista+j)).cantidadPersonas)
						{
							value = 1;
						}
					}

				if (value == 1)
				{
					value = 0;

					listaAux = (*(lista+i));
					(*(lista+i)) = (*(lista+j));
					(*(lista+j)) = listaAux;

					j = i+1;
				}
			}
		}
	}

}

void listadoViviendas(vivienda *lista, int largo)
{
	setbuf(stdout, NULL);
	int i;

	for(i=0; i < largo; i++)
	{
		if((*(lista+i)).idVivienda != -1)
		{
			char tipoAux[20];
			switch((*(lista+i)).tipoVivienda)
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
			printf("Id: %d | Calle: %s | Cantidad de personas: %d | Cantidad de habitaciones: %d | Tipo de vivienda: %s | Legajo del censista encargado %d \n ------------------------------ \n", (*(lista+i)).idVivienda, (*(lista+i)).calle, (*(lista+i)).cantidadPersonas, (*(lista+i)).cantidadHabitaciones, tipoAux, (*(lista+i)).legajoCensista);
		}
	}
}

void eliminarVivienda(vivienda *lista, int largo, int posicion)
{
	(*(lista+posicion)).idVivienda = -1;
}

int buscarViviendaPorID(vivienda *lista, int largo, int id)
{
	int i;
	int posicion = -1;
	for(i = 0; i < largo; i ++)
	{
		if( (*(lista+i)).idVivienda == id)
		{
			posicion = i;

			char tipoAux[20];
			switch((*(lista+i)).tipoVivienda)
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
			printf("Id: %d | Calle: %s | Cantidad de personas: %d | Cantidad de habitaciones: %d | Tipo de vivienda: %s | Legajo del censista encargado %d \n ------------------------------ \n", (*(lista+i)).idVivienda, (*(lista+i)).calle, (*(lista+i)).cantidadPersonas, (*(lista+i)).cantidadHabitaciones, tipoAux, (*(lista+i)).legajoCensista);
		}
	}
	return posicion;
}
