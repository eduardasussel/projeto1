#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct noForma {
    void *forma;
    int id;
    TipoForma tipo;
    struct noForma *prox;
} NOFORMA;

typedef struct arena {
    NOFORMA *formas;
} ARENA;


ARENA *criaArena() {
    ARENA *a = malloc(sizeof(ARENA));
    a->topo = NULL;
    return a;
}

void pushArena(ARENA *a, void *forma, int id, TipoForma tipo) {
    NOFORMA *novo = malloc(sizeof(NOFORMA));
    novo->forma = forma;
    novo->id = id;
    novo->tipo = tipo;
    novo->prox = a->formas;
    a->formas = novo;
}
