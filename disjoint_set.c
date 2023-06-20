#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Lista* criarConjunto(int* x) {
    Lista* novoConjunto = malloc(sizeof(Lista));
    novoConjunto->cabeca = (Elemento*)malloc(sizeof(Elemento));
    novoConjunto->cabeca->info = *x;
    novoConjunto->cabeca->proximo = NULL;
    return novoConjunto;
}

Lista* encontrarConjunto(Lista* conjuntos, int numVertices, int* x) {
    for (int i = 0; i < numVertices; i++) {
        Elemento* nodoAtual = conjuntos[i].cabeca;
        while (nodoAtual != NULL) {
            if (*nodoAtual->info == *x) {
                return &conjuntos[i];
            }
            nodoAtual = nodoAtual->proximo;
        }
    }
    return NULL;
}

void destruirConjunto(Lista* conjuntos, int indice) {
    if (indice >= 0 && indice < sizeof(conjuntos) / sizeof(conjuntos[0])) {
        Lista* conjunto = &conjuntos[indice];
        Elemento* nodoAtual = conjunto->cabeca;
        while (nodoAtual != NULL) {
            Elemento* proximo = nodoAtual->proximo;
            free(nodoAtual->info);
            free(nodoAtual);
            nodoAtual = proximo;
        }
        inicializa_lista(conjunto, sizeof(int));
    } else {
        printf("Invalid conjunto index.\n");
    }
}

void unirConjuntos(Lista* conjuntos, int numVertices, int* x, int* y) {
    Lista* conjuntoX = encontrarConjunto(conjuntos, numVertices, x);
    Lista* conjuntoY = encontrarConjunto(conjuntos, numVertices, y);

    if (conjuntoX != conjuntoY) {
        Elemento* nodoAtual = conjuntoY->cabeca;
        while (nodoAtual != NULL) {
            Elemento* proximoNodo = nodoAtual->proximo;
            nodoAtual->proximo = conjuntoX->cabeca;
            conjuntoX->cabeca= nodoAtual;
            nodoAtual = proximoNodo;
        }
    }
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
                printf("%d ", *nodoAtual->info);
                visitados[*nodoAtual->info - 1] = 1;
                nodoAtual = nodoAtual->proximo;
            }
            printf("\n");
        }
    }

    free(visitados);
}