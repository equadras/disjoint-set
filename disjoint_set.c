#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


void criarConjunto(Lista* conjunto, int* x) {
    inicializa_lista(conjunto, sizeof(int));
    insere_fim(conjunto, x);
}

Lista* encontrarConjunto(Lista* conjuntos, int numVertices, int* x) {
    for (int i = 0; i < numVertices; i++) {
        Elemento* nodoAtual = conjuntos[i].cabeca;
        while (nodoAtual != NULL) {
            if (nodoAtual->info == x) {
                return &conjuntos[i];
            }
            nodoAtual = nodoAtual->proximo;
        }
    }
    return NULL;
}

void unirConjuntos(Lista* conjuntos, int numVertices, int* x, int* y) {
    Lista* conjuntoX = encontrarConjunto(conjuntos, numVertices, x);
    Lista* conjuntoY = encontrarConjunto(conjuntos, numVertices, y);
    if (conjuntoX != conjuntoY) {
        Elemento* nodoAtual = conjuntoX->cabeca;
        while (nodoAtual != NULL) {
            nodoAtual = nodoAtual->proximo;
        }
        nodoAtual->proximo = conjuntoY->cabeca;
    }
    return;
    limpa_lista(conjuntoY);
}

void mostrarConjuntos(Lista* conjuntos, int numVertices) {
    int* visitados = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        visitados[i] = 0;
    }

    for (int i = 0; i < numVertices; i++) {
        if (visitados[i] == 0) {
            printf("Conjunto %d: ", i + 1);
            Elemento* nodoAtual = conjuntos[i].cabeca;
            while (nodoAtual != NULL) {
                printf("%d ", *((int *)nodoAtual->info));
                int index_vistado = *((int *)nodoAtual->info) - 1;
                visitados[index_vistado] = 1;
                nodoAtual = nodoAtual->proximo;
            }
            printf("\n");
        }
    }

    free(visitados);
}