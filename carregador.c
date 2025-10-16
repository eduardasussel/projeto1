#include <stdio.h>
#include <stdlib.h>
#include "carregador.h"
#include "pilha.h"

typedef struct forma{
    void *forma;
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

int carregadorChao(CARREGADOR *c, PILHA *chao, int n){
      for (int i = 0 ; i < n; i++){
        void *fc = pop(chao);
        if (!fc) return 0;

        PONT novo = malloc(sizeof(FORMA));
            if(!novo) return 0;

        novo->forma = fc;
        novo->prox = c->topo;
        c->topo = novo;

      }
        return 1;
}

void *popCarregador(CARREGADOR *c) {
    if (!c->topo) return NULL;
    FORMA *removido = c->topo;
    void *forma = removido->forma;
    c->topo = removido->prox;
    free(removido);
    return forma;
}

void *pushCarregador(CARREGADOR *c, void *novaforma){
    FORMA *novo = malloc(sizeof(FORMA));
    novo->forma = novaforma;
    novo->prox = c->topo;
    c->topo = novo;
}