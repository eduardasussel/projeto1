#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    void *forma;
    TipoForma tipo;
    struct no *prox;
} NO_STRUCT;

typedef struct pilha {
    NO_STRUCT *topo;
} PILHA_STRUCT;

PILHA criaPilha() {
    PILHA_STRUCT *p = malloc(sizeof(PILHA_STRUCT));
    if (!p) return NULL;
    p->topo = NULL;
    return (PILHA)p;
}

void push(PILHA p, void *forma, TipoForma tipo) {
    PILHA_STRUCT *pilha = (PILHA_STRUCT *)p;
    if (!pilha) return;

    NO_STRUCT *novo = malloc(sizeof(NO_STRUCT));
    if (!novo) return;

    novo->forma = forma;
    novo->tipo = tipo;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

NO pop(PILHA p) {
    PILHA_STRUCT *pilha = (PILHA_STRUCT *)p;
    if (!pilha || !pilha->topo) return NULL;

    NO_STRUCT *removido = pilha->topo;
    pilha->topo = removido->prox;
    return (NO)removido;
}

int pilhaTamanho(PILHA p) {
    PILHA_STRUCT *pilha = (PILHA_STRUCT *)p;
    if (!pilha) return 0;

    int tam = 0;
    NO_STRUCT *atual = pilha->topo;
    while (atual) {
        tam++;
        atual = atual->prox;
    }
    return tam;
}

NO topoPilha(PILHA p) {
    PILHA_STRUCT *pilha = (PILHA_STRUCT *)p;
    if (!pilha) return NULL;
    return (NO)pilha->topo;
}


NO proxNo(NO *n) {
    NO_STRUCT *no = (NO_STRUCT *)n;
    if (!no) return NULL;
    return (NO)no->prox;
}

void *getInfoNo(NO *n) {
    NO_STRUCT *no = (NO_STRUCT *)n;
    if (!no) return NULL;
    return no->forma;
}

TipoForma getTipoNo(NO *n) {
    NO_STRUCT *no = (NO_STRUCT *)n;
    if (!no) return -1;
    return no->tipo;
}
