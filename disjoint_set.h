#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void criarConjunto(Lista* conjunto, int* x);
Lista* encontrarConjunto(Lista* conjuntos, int numVertices, int x);
void unirConjuntos(Lista* conjuntos, int numVertices, int x, int y);
void mostrarConjuntos(Lista* conjuntos, int numVertices);