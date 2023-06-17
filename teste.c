#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dado;
    struct Nodo* proximo;
} Nodo;

typedef struct Conjunto {
    Nodo* membros;
} Conjunto;

Conjunto criarConjunto(int x) {
    Conjunto novoConjunto;
    novoConjunto.membros = (Nodo*)malloc(sizeof(Nodo));
    novoConjunto.membros->dado = x;
    novoConjunto.membros->proximo = NULL;
    return novoConjunto;
}

Conjunto* encontrarConjunto(Conjunto* conjuntos, int numVertices, int x) {
    for (int i = 0; i < numVertices; i++) {
        Nodo* nodoAtual = conjuntos[i].membros;
        while (nodoAtual != NULL) {
            if (nodoAtual->dado == x) {
                return &conjuntos[i];
            }
            nodoAtual = nodoAtual->proximo;
        }
    }
    return NULL;
}

void unirConjuntos(Conjunto* conjuntos, int numVertices, int x, int y) {
    Conjunto* conjuntoX = encontrarConjunto(conjuntos, numVertices, x);
    Conjunto* conjuntoY = encontrarConjunto(conjuntos, numVertices, y);

    if (conjuntoX != conjuntoY) {
        Nodo* nodoAtual = conjuntoY->membros;
        while (nodoAtual != NULL) {
            Nodo* proximoNodo = nodoAtual->proximo;
            nodoAtual->proximo = conjuntoX->membros;
            conjuntoX->membros = nodoAtual;
            nodoAtual = proximoNodo;
        }
    }
}

void mostrarConjuntos(Conjunto* conjuntos, int numVertices) {
    int* visitados = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        visitados[i] = 0;
    }

    for (int i = 0; i < numVertices; i++) {
        if (visitados[i] == 0) {
            printf("Conjunto %d: ", i + 1);
            Nodo* nodoAtual = conjuntos[i].membros;
            while (nodoAtual != NULL) {
                printf("%d ", nodoAtual->dado);
                visitados[nodoAtual->dado - 1] = 1;
                nodoAtual = nodoAtual->proximo;
            }
            printf("\n");
        }
    }

    free(visitados);
}

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

    Conjunto* conjuntos = (Conjunto*)malloc(numVertices * sizeof(Conjunto));
    for (int i = 0; i < numVertices; i++) {
        conjuntos[i] = criarConjunto(i + 1);
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matrizAdjacencia[i][j] == 1) {
                unirConjuntos(conjuntos, numVertices, i + 1, j + 1);
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

