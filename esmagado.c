#include <stdio.h>
#include <stdlib.h>
#include "esmagado.h"
#include "arena.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"

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

double calculo(ESMAGADO *e){
    EFORMA *forma = e->topo;
    double area = 0;
    double aTotal = 0;

    while(forma !=NULL){
        switch (forma->tipo) {
        case CIRCULO:
        area = areaCirculo(forma->forma);
        break;

        case RETANGULO:
        area = areaRetangulo(forma->forma);
        break;

        case TEXTO:
        area = 0;
        break;

        case LINHA:
        area = 0;
        break;
    }

    popEsmagado(e);

        forma = forma->prox;
        aTotal += area;
    }
    
    return aTotal;
}