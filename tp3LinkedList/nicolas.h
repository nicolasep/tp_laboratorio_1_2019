#ifndef NICOLAS_H_INCLUDED
#define NICOLAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validaPalabra(char palabra[]);
int getcharS(char palabra[],char mensaje[], char mensajeError[],int tamPalabra);
int validaTamPalabra(char palabra[],int tamPalabra);
int validaNumero(char numero[]);
int getNumero(char mensaje[],char mensajeError[]);

#endif // NICOLAS_H_INCLUDED
