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