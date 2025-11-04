#ifndef ESMAGADO_H
#define ESMAGADO_H
#include "tipos.h"

typedef struct esmagado ESMAGADO;

ESMAGADO *criaEsmagado();

void pushEsmagado(ESMAGADO *e3, void *forma, int id, TipoForma tipo);

void *popEsmagado(ESMAGADO *e);

double calculo(ESMAGADO *e, FILE *svg);

#endif