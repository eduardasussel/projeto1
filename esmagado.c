#include <stdio.h>
#include <stdlib.h>
#include "esmagado.h"
#include "arena.h"

typedef struct eForma {
    void *forma;
    int id;
    TipoForma tipo;
    struct eForma *prox;
} EFORMA;

struct esmagado {
    ESMAGADO *topo;
};

ESMAGADO *criaEsmagado() {
    ESMAGADO *e = malloc(sizeof(ESMAGADO));
    if (!e) {
        printf("Erro ao alocar essa pilha!\n");
        exit(1);
    }
    e->topo = NULL;
    return e;
}

void pushEsmagado(ESMAGADO *e, void *forma, int id, TipoForma tipo) {
    if (!e) return;

    EFORMA *novo = malloc(sizeof(ESMAGADO));
    if (!novo) {
        printf("Erro ao alocar forma!\n");
        exit(1);
    }

    novo->forma = forma;
    novo->id = id;
    novo->tipo = tipo;
    novo->prox = e->topo;

    e->topo = novo;
}

void *popEsmagado(ESMAGADO *e) {
    if (!e || !e->topo) return NULL;

    EFORMA *removido = e->topo;
    void *forma = removido->forma;

    e->topo = removido->prox;
    free(removido);

    return forma;
}