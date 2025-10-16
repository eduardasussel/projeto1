#include <stdio.h>
#include "disparador.h"
#include "pilha.h"

typedef struct {
    double dx;
    double dy;
    void *forma;
    CARREGADOR *cesqencaixado;
    CARREGADOR *cdirencaixado;
} DISPARADOR;


DISPARADOR *criaDispadarador(double dx, double dy) {
    DISPARADOR *d = malloc(sizeof(DISPARADOR));
    d->dx = dx;
    d->dy = dy;
    d->forma = NULL;
    d->cesqencaixado = NULL;
    d->cdirencaixado = NULL;

    return d;
}

void posicionarDisparador(DISPARADOR *d, double dx, double dy) {
    d->dx = dx;
    d->dy = dy;
}

void encaixarCarregador(DISPARADOR *d, CARREGADOR *cesq, CARREGADOR *cdir) {
    d->cesqencaixado = cesq;
    d->cdirencaixado = cdir;
}