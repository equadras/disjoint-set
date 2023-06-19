#include <stdio.h>
#include <stdlib.h>
#include "disjoint_set.h"

// typedef struct Nodo {
//     int dado;
//     struct Nodo* proximo;
// } Nodo;

// typedef struct Conjunto {
//     Nodo* membros;
// } Conjunto;


// criando conjuntos com um elemento só
// criar uma lista nova, com um elemento.

int main() {
    int numVertices;

    printf("Digite o número de vértices do grafo: ");
    scanf("%d", &numVertices);

    int** matrizAdjacencia = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        matrizAdjacencia[i] = (int*)malloc(numVertices * sizeof(int));
    }

    printf("Digite a matriz de adjacência:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &matrizAdjacencia[i][j]);
        }
    }

    Lista* conjuntos = (Lista*)malloc(numVertices * sizeof(Lista));
    for (int i = 0; i < numVertices; i++) {
        int aux = i + 1;
        criarConjunto(&conjuntos[i], &aux);
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matrizAdjacencia[i][j] == 1) {
                int aux1 = i + 1;
                int aux2 = j + 1;
                printf("%d - %d\n", i, j);
                unirConjuntos(conjuntos, numVertices, aux1, aux2);
            }
        }
    }

    printf("\nConjuntos Conexos:\n");
    mostrarConjuntos(conjuntos, numVertices);

    for (int i = 0; i < numVertices; i++) {
        free(matrizAdjacencia[i]);
    }
    free(matrizAdjacencia);
    free(conjuntos);

    return 0;
}

