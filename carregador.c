#include <stdio.h>
#include <stdlib.h>
#include "carregador.h"
#include "pilha.h"

typedef enum { CIRCULO, RETANGULO, TEXTO, LINHA } TipoForma;

typedef struct forma{
    void *forma;
    int id;  
    TipoForma tipo;
    struct forma *prox;
} FORMA;

typedef FORMA *PONT;

typedef struct carregador {
    FORMA *topo;
} CARREGADOR;


CARREGADOR *criaCarregador() {
    CARREGADOR *c = malloc(sizeof(CARREGADOR));
    c->topo = NULL;
    return c;
}

int carregadorChao(CARREGADOR *c, PILHA *chao, int n, FILE *txt) {
    for (int i = 0; i < n; i++) {
        FORMA *fchao = pop(chao);
        if (!fchao) return 0;

        PONT novo = malloc(sizeof(FORMA));
        if (!novo) return 0;

        novo->forma = fchao->forma;
        novo->id = fchao->id;
        novo->tipo = fchao->tipo;

        novo->prox = c->topo;
        c->topo = novo;

        if (txt != NULL)
            reportaDados(fchao->forma, fchao->tipo, txt);
    }

    return 1;
}


void pushCarregador(CARREGADOR *c, void *novaforma, int id, TipoForma tipo){
    if (!c) return;
    FORMA *novo = malloc(sizeof(FORMA));
    if (!novo) return;
    novo->forma = novaforma;
    novo->id = id;
    novo->tipo = tipo;
    novo->prox = c->topo;
    c->topo = novo;
}

void *popCarregador(CARREGADOR *c, int *id, TipoForma tipo) {
    if (!c || !c->topo) return NULL;

    FORMA *removido = c->topo;
    void *forma = removido->forma;

    if (id) *id = removido->id;
    if (tipo) tipo = removido->tipo;

    c->topo = removido->prox;
    free(removido);

    return forma;
}