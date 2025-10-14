#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    void *i;
    struct elemento *prox;
} ELEMENTO;

typedef struct pilha {
    ELEMENTO *topo;
} PILHA;

PILHA *criaPilha() {
    PILHA *p = malloc(sizeof(PILHA));
    p->topo = NULL;
    return p;
}

void push(PILHA *p, void *i) {
    ELEMENTO *novo = malloc(sizeof(ELEMENTO));
    novo->i = i;
    novo->prox = p->topo;
    p->topo = novo;
}

void *pop(PILHA *p) {
    if (p->topo == NULL)
        return NULL;

    ELEMENTO *removido = p->topo;
    void *i = removido->i;
    p->topo = removido->prox;
    free(removido);
    return i;
}