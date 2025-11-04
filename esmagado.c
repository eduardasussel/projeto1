#include <stdio.h>
#include <stdlib.h>
#include "esmagado.h"
#include "arena.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "formas.h"
#include "gerarSvg.h"

typedef struct eForma {
    void *forma;
    int id;
    TipoForma tipo;
    struct eForma *prox;
} EFORMA;

struct esmagado {
    EFORMA *topo;
};

ESMAGADO *criaEsmagado() {
    ESMAGADO *e = malloc(sizeof(ESMAGADO));
    if (!e) {
        printf("Erro ao alocar pilha de formas esmagadas!\n");
        exit(1);
    }
    e->topo = NULL;
    return e;
}

void pushEsmagado(ESMAGADO *e, void *forma, int id, TipoForma tipo) {
    if (!e) return;

    EFORMA *novo = malloc(sizeof(EFORMA));
    if (!novo) {
        printf("Erro ao alocar forma esmagada!\n");
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

double calculo(ESMAGADO *e, FILE *svg) {
    if (!e) return 0.0;
    double aTotal = 0.0;

    while (e->topo != NULL) {
        EFORMA *node = e->topo;

        double area = 0.0;
        switch (node->tipo) {
            case CIRCULO:
                area = areaCirculo((Circulo) node->forma);
                break;
            case RETANGULO:
                area = areaRetangulo((Retangulo) node->forma);
                break;
            case TEXTO:
            case LINHA:
                area = 0.0;
                break;
        }

        double cx = 0.0, cy = 0.0;
        centro(node->forma, node->tipo, &cx, &cy);
        if (svg) asterisco(svg, cx, cy); 

        aTotal += area;
        popEsmagado(e);
    }

    return aTotal;
}
