#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct forma {
    void *item;
    struct forma *prox;
} FORMA;

typedef FORMA *PONT;

typedef struct arena {
    FORMA *topo;
} ARENA;


ARENA *criaArena() {
    ARENA *a = malloc(sizeof(ARENA));
    a->topo = NULL;
    return a;
}

void pushArena(ARENA *a, void *novoitem){
    FORMA *novo = malloc(sizeof(FORMA));
    novo->item = novoitem;
    novo->prox = a->topo;
    a->topo = novo;
}