#include <stdio.h>
#include "disparador.h"
#include "pilha.h"

typedef struct {
    double dx;
    double dy;
    void *forma;
} DISPARADOR;

DISPARADOR *criaDispadarador(double dx, double dy) {
    DISPARADOR *d = malloc(sizeof(DISPARADOR));
    d->dx = dx;
    d->dy = dy;
    d->forma = NULL;
    return d;
}

void posicionarDisparador(DISPARADOR *d, double dx, double dy) {
    d->dx = dx;
    d->dy = dy;
}