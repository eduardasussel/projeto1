#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    void *forma;
    TipoForma tipo;
    struct no *prox;
} NO;

typedef struct pilha {
    NO *topo;
} PILHA;

PILHA *criaPilha() {
    PILHA *p = malloc(sizeof(PILHA));
    if (!p) return NULL;
    p->topo = NULL;
    return p;
}

void push(PILHA *p, void *forma, TipoForma tipo) {
    if (!p) return;

    NO *novo = malloc(sizeof(NO));
    if (!novo) return;

    novo->forma = forma;
    novo->tipo = tipo;
    novo->prox = p->topo;
    p->topo = novo;
}

void *pop(PILHA *p) {
    if (!p || !p->topo) return NULL;

    NO *removido = p->topo;
    void *forma = removido->forma;

    p->topo = removido->prox;
    free(removido);

    return forma;
}

int pilhaTamanho(PILHA *p) {
    if (!p) return 0;

    NO *atual = p->topo;
    int tam = 0;
    while (atual) {
        tam++;
        atual = atual->prox;
    }
    return tam;
}

// Funções auxiliares
NO *topoPilha(PILHA *p) {
    if (!p) return NULL;
    return p->topo;
}

NO *proxNo(NO *n) {
    if (!n) return NULL;
    return n->prox;
}

void *getInfoNo(NO *n) {
    if (!n) return NULL;
    return n->forma;
}

TipoForma getTipoNo(NO *n) {
    if (!n) return -1;
    return n->tipo;
}
