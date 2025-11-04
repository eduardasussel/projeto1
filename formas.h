#ifndef FORMAS_H
#define FORMAS_H
#include "tipos.h"

int idForma(void *forma, TipoForma tipo);

TipoForma tipoForma(void *forma);

void centro(void *forma, TipoForma tipo, double *cx, double *cy);

void asterisco(FILE *svg, double cx, double cy);

#endif