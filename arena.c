#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arena.h"

typedef struct forma {
    void *forma;
    int id;
    TipoForma tipo;
    struct forma *prox;
} FORMA;

typedef struct arena {
    FORMA *topo;
} ARENA;


ARENA *criaArena() {
    ARENA *a = malloc(sizeof(ARENA));
    if (!a) return NULL;
    a->topo = NULL;
    return a;
}

void pushArena(ARENA *a, void *forma, int id, TipoForma tipo) {
    if (!a) return;
    FORMA *novo = malloc(sizeof(FORMA));
    if (!novo) return;

    novo->forma = forma;
    novo->id = id;
    novo->tipo = tipo;
    novo->prox = a->topo;
    a->topo = novo;
}

void *popArena(ARENA *a) {
    if (!a || !a->topo) return NULL;

    FORMA *topo = a->topo;
    void *forma = topo->forma;

    a->topo = topo->prox;
    free(topo);

    return forma;
}

int nFormas(ARENA *a) {
    if (!a) return 0;
    int count = 0;
    FORMA *atual = a->topo;
    while (atual) {
        count++;
        atual = atual->prox;
    }
    return count;
}

double areaForma(void *forma, TipoForma tipo) {
    switch (tipo) {
        case CIRCULO:    return areaCirculo((Circulo) forma);
        case RETANGULO:  return areaRetangulo((Retangulo) forma);
        case TEXTO:      return 0.0;
        case LINHA:      return 0.0;
        default:         return 0.0;
    }
}

int sobreporCirRet(Circulo c, Retangulo r) {
    double cx = xCirculo(c);
    double cy = yCirculo(c);
    double raio = raioCirculo(c);

    double x1 = xRetangulo(r);
    double y1 = yRetangulo(r);
    double w = larRetangulo(r);
    double h = altRetangulo(r);

    double pertoX = cx < x1 ? x1 : (cx > x1 + w ? x1 + w : cx);
    double pertoY = cy < y1 ? y1 : (cy > y1 + h ? y1 + h : cy);

    double dx = cx - pertoX;
    double dy = cy - pertoY;

    return (dx * dx + dy * dy) <= (raio * raio);
}

int sobreporCirculos(Circulo c1, Circulo c2) {
    double dx = xCirculo(c1) - xCirculo(c2);
    double dy = yCirculo(c1) - yCirculo(c2);
    double dist = sqrt(dx * dx + dy * dy);
    return dist <= (raioCirculo(c1) + raioCirculo(c2));
}

void analisaArena(ARENA *a, PILHA *c, ESMAGADO *e) {
    if (!a || !a->topo) return;

    FORMA *atual = a->topo;
    while (atual && atual->prox) {
        FORMA *proximo = atual->prox;

        int sobrepoe = 0;

        if (atual->tipo == CIRCULO && proximo->tipo == CIRCULO)
            sobrepoe = sobreporCirculos((Circulo) atual->forma, (Circulo) proximo->forma);

        else if (atual->tipo == CIRCULO && proximo->tipo == RETANGULO)
            sobrepoe = sobreporCirRet((Circulo) atual->forma, (Retangulo) proximo->forma);

        else if (atual->tipo == RETANGULO && proximo->tipo == CIRCULO)
            sobrepoe = sobreporCirRet((Circulo) proximo->forma, (Retangulo) atual->forma);

        if (sobrepoe) {
            push(c, atual->forma, atual->tipo);
            pushEsmagado(e, atual->forma, atual->id, atual->tipo);
        }

        atual = proximo;
    }
}
