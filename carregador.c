#include <stdio.h>
#include <stdlib.h>
#include "carregador.h"
#include "pilha.h"
#include "gerarTxt.h"
#include "tipos.h"

typedef struct forma {
    void *forma;
    int id;
    TipoForma tipo;
    struct forma *prox;
} FORMA_STRUCT;

typedef struct carregador {
    FORMA_STRUCT *topo;
} CARREGADOR_STRUCT;

CARREGADOR criaCarregador() {
    CARREGADOR_STRUCT *c = malloc(sizeof(CARREGADOR_STRUCT));
    if (!c) {
        return NULL;
    }
    c->topo = NULL;
    return (CARREGADOR)c;
}


int carregadorChao(CARREGADOR c, PILHA chao, int idBase, FILE *txt) {
    if (!c || !chao) {
        return 0;
    }

    CARREGADOR_STRUCT *carregador = (CARREGADOR_STRUCT *)c;

    NO n = pop(chao);
    if (!n) {
        return 0;
    }

    void *forma = getInfoNo(n);
    TipoForma tipo = getTipoNo(n);


    FORMA_STRUCT *novo = malloc(sizeof(FORMA_STRUCT));
    if (!novo) {
        return 0;
    }

    novo->forma = forma;
    novo->id = idBase + 1;
    novo->tipo = tipo;
    novo->prox = carregador->topo;
    carregador->topo = novo;

    if (txt != NULL)
        reportaDadosTxt(forma, tipo, txt);

    free(n);
    
    return 1;
}


void pushCarregador(CARREGADOR c, void *forma, int id, TipoForma tipo) {
    if (!c) return;
    CARREGADOR_STRUCT *carregador = (CARREGADOR_STRUCT *)c;

    FORMA_STRUCT *novo = malloc(sizeof(FORMA_STRUCT));
    if (!novo) return;

    novo->forma = forma;
    novo->id = id;
    novo->tipo = tipo;
    novo->prox = carregador->topo;
    carregador->topo = novo;
}

void *popCarregador(CARREGADOR c, int *id, TipoForma *tipo){
    if (!c) return NULL;
    CARREGADOR_STRUCT *carregador = (CARREGADOR_STRUCT *)c;

    if (!carregador->topo) return NULL;

    printf("[DEBUG popCarregador] topo=%p\n", (void*)carregador->topo);


    FORMA_STRUCT *removido = carregador->topo;
    void *forma = removido->forma;

    if (id) *id = removido->id;
    if (tipo) *tipo = removido->tipo;

    carregador->topo = removido->prox;
    free(removido);

    return forma;
}

int carregadorVazio(CARREGADOR c) {
    if (!c) return 1;
    CARREGADOR_STRUCT *carregador = (CARREGADOR_STRUCT *)c;
    return (carregador->topo == NULL);
}