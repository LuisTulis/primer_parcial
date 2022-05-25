/*
 ============================================================================
 Name        : primerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vivienda.h"
#include "censista.h"
#include "utn.h"

#define LARGOCENSISTA 3

int main(void)
{
	setbuf(stdout, NULL);
	int idVivienda = 20000;
	int largoVivienda = 30000;
	censista listaCensistas[LARGOCENSISTA] = {{100, "Ana", 34, "1203-2345"}, {101, "Juan", 24, "4301-54678"}, {102, "Sol", 47, "5902-37487"}};
	vivienda listaViviendas[largoVivienda];
	initVivienda(listaViviendas, largoVivienda);

	int respuestaMenu;

	char calleAux[25];
	int cantidadPersonasAux;
	int cantidadHabitacionesAux;
	int tipoViviendaAux; // (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO)
	int legajoCensista;

	int idIngresado;
	int validacionBuscar;
	int mostrarCensista;
	int validacionOpcion1;
	int validacionLegajo;

	int respuestaSubMenu;

	int opcionBuscar;

	int flagOpciones = 1;


	do
	{
		utn_getNumeroEntero(&respuestaMenu, "Que opcion desea realizar?\n"
						   "\n1- Alta vivienda"
						   "\n2- Modificar vivienda"
						   "\n3- Baja vivienda"
						   "\n4- Listar viviendas"
						   "\n5- Listar censistas"
						   "\n6- Salir", "\nError, ingrese un numero.\n", 1, 6, 3);

		fflush(stdin);

		switch(respuestaMenu)
		{
			case 1:
			{
				idVivienda ++;

				validacionOpcion1 = cadenaValidada(calleAux, "\nIngrese la calle de la vivienda.");
				if(validacionOpcion1 == -1)
				{
					break;
				}
				validacionOpcion1 = utn_getNumeroEntero(&cantidadPersonasAux, "\nIngrese la cantidad de personas de la vivienda.", "\nError, ingrese un numero.\n", 1, 10, 3);
				if(validacionOpcion1 == -1)
				{
					break;
				}
				validacionOpcion1 = utn_getNumeroEntero(&cantidadHabitacionesAux, "\nIngrese la cantidad de habitaciones de la vivienda.", "\nError, ingrese un numero.\n", 1, 10, 3);
				if(validacionOpcion1 == -1)
				{
					break;
				}

				validacionOpcion1 = utn_getNumeroEntero(&tipoViviendaAux, "\nIngrese el tipo de vivienda. \n 1-Casa \n 2- Departamento \n 3- Casilla \n 4- Rancho", "\nError, ingrese un numero valido (1-4).\n", 1, 4, 3 );
				if(validacionOpcion1 == -1)
				{
					break;
				}

				printf("Para ingresar el censista correspondiente a la vivienda, desea ver la lista de los mismos?");
				utn_getNumeroEntero(&mostrarCensista, "\n1- Si \n 2- No ", "\nError, ingrese un numero valido.\n", 1, 2, 3);
				if(mostrarCensista == 1)
				{
					listadoCensistas(listaCensistas, LARGOCENSISTA);
				}

				validacionOpcion1 = utn_getNumeroEntero(&legajoCensista, "\nIngrese el legajo del censista.", "\nError, ingrese un legajo valido.\n", 1, 1000, 3 );
				if(validacionOpcion1 == -1)
				{
					break;
				}

				validacionLegajo = validarCensista(listaCensistas, LARGOCENSISTA, legajoCensista);

				if(validacionLegajo == -1)
				{
					printf("Legajo del censista no encontrado, volviendo al menu para evitar erorres.\n");
					break;
				}

				altaVivienda(listaViviendas, largoVivienda, idVivienda, calleAux, cantidadPersonasAux, cantidadHabitacionesAux, tipoViviendaAux, legajoCensista);
				flagOpciones = 0;
				break;
			}
			case 2:
			{
				if(flagOpciones == 0)
				{
					utn_getNumeroEntero(&idIngresado, "Ingrese la vivienda a modificar", "\nIngrese un numero.\n", 1, 50000 , 1);
					validacionBuscar = buscarViviendaPorID(listaViviendas, largoVivienda, idIngresado);

					if(validacionBuscar != -1)
					{
						utn_getNumeroEntero(&opcionBuscar, "\nEs esa la vivienda a modificar? \n1- Si \n2- No", "\nIngrese un numero.\n", 1, 2, 1);
						if(opcionBuscar == 1)
						{
							utn_getNumeroEntero(&respuestaSubMenu, "Que campo desea modificar?\n"
													   "\n1- Calle"
													   "\n2- Cantidad de personas"
													   "\n3- Cantidad de habitantes"
													   "\n4- Tipo de vivienda"
													   "\n5- Salir", "\nError, ingrese un numero.\n", 1, 5, 3);
							switch(respuestaSubMenu)
							{
								case 1:
								{
									fflush(stdin);
									validacionOpcion1 = cadenaValidada(calleAux, "\nIngrese la calle de la vivienda.");
									if(validacionOpcion1 == -1)
									{
										break;
									}
									else
									{
										strcpy((*(listaViviendas+validacionBuscar)).calle, calleAux);
									}
									break;
								}
								case 2:
								{
									validacionOpcion1 = utn_getNumeroEntero(&cantidadPersonasAux, "\nIngrese la cantidad de personas de la vivienda.", "\nError, ingrese un numero.\n", 1, 10, 3);
									if(validacionOpcion1 == -1)
									{
										break;
									}
									else
									{
										(*(listaViviendas+validacionBuscar)).cantidadPersonas = cantidadPersonasAux;
									}
									break;
								}
								case 3:
								{
									validacionOpcion1 = utn_getNumeroEntero(&cantidadHabitacionesAux, "\nIngrese la cantidad de habitaciones de la vivienda.", "\nError, ingrese un numero.\n", 1, 10, 3);
									if(validacionOpcion1 == -1)
									{
										break;
									}
									else
									{
										(*(listaViviendas+validacionBuscar)).cantidadHabitaciones = cantidadHabitacionesAux;
									}
									break;
								}
								case 4:
								{
									validacionOpcion1 = utn_getNumeroEntero(&tipoViviendaAux, "\nIngrese el tipo de vivienda. \n 1-Casa \n 2- Departamento \n 3- Casilla \n 4- Rancho", "\nError, ingrese un numero valido (1-4).\n", 1, 4, 3 );
									if(validacionOpcion1 == -1)
									{
										break;
									}
									else
									{
										(*(listaViviendas+validacionBuscar)).tipoVivienda = tipoViviendaAux;
									}

									break;
								}
								case 5:
								{
									printf("\nSaliendo del menu. . . \n");
									break;
								}
								default:
								{
									printf("Opcion incorrecta.");
								}
							}

						}
					}
					else
					{
						printf("\nVivienda no encontrada..\n");
					}
				}
				else
				{
					printf("No hay viviendas ingresadas");
				}
					break;

			}
			case 3:
			{
				if(flagOpciones == 0)
				{
					utn_getNumeroEntero(&idIngresado, "Ingrese la vivienda a borrar", "\nIngrese un numero.\n", 1, 50000 , 1);
					validacionBuscar = buscarViviendaPorID(listaViviendas, largoVivienda, idIngresado);

					if(validacionBuscar != -1)
					{
						utn_getNumeroEntero(&opcionBuscar, "\nEs esa la vivienda a borrar? \n1- Si \n2- No", "\nIngrese un numero.\n", 1, 2, 1);
						if(opcionBuscar == 1)
						{
							eliminarVivienda(listaViviendas, largoVivienda, validacionBuscar);
							printf("\nVivienda eliminada.\n");
						}
					}
					else
					{
						printf("\nVivienda no encontrada..\n");
					}
				}
				else
				{
					printf("No hay viviendas ingresadas");
				}
				break;
			}
			case 4:
			{
				if(flagOpciones == 0)
				{
					ordenarViviendas(listaViviendas, largoVivienda);
					listadoViviendas(listaViviendas, largoVivienda);
				}
				else
				{
					printf("No hay viviendas ingresadas");
				}
				break;
			}
			case 5:
			{
				listadoCensistas(listaCensistas, LARGOCENSISTA);
				break;
			}
			case 6:
			{
				printf("\nSaliendo del menu. . .\n");
				break;
			}
			default:
			{
				printf("\nOpcion incorrecta.\n");
			}
		}
	}while(respuestaMenu != 6);

	/*A. ALTA VIVENDA
	B. MODIFICAR VIVIENDA: Se ingresará el idVivienda, permitiendo en un submenú modificar:
	● la calle
	● la cantidad de las personas
	● la cantidad de habitaciones
	● el tipo de vivienda
	C. BAJA VIVIENDA: Se ingresará el idVivienda y se realizará una baja lógica.
	D. LISTAR VIVENDAS: Hacer un único listado de todas las viviendas ordenados por calle y ante igualdad
	de calle por cantidad de personas.
	E. LISTAR CENSISTAS*/

	return EXIT_SUCCESS;
}
