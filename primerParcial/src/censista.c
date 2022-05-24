/*
 * censista.c
 *
 *  Created on: 20 may. 2022
 *      Author: Luis
 */

#include "censista.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"

void listadoCensistas(censista *lista, int largo)
{
	setbuf(stdout, NULL);
	int i;

	for(i=0; i < largo; i++)
	{
		printf("Legajo: %d | %s | %d años | %s \n ------------------------------ \n", (*(lista+i)).legajoCensista, (*(lista+i)).nombre, (*(lista+i)).edad, (*(lista+i)).telefono);
	}
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


