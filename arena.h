#ifndef ARENA_H
#define ARENA_H

#include "pilha.h"
#include "esmagado.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "tipos.h" 

typedef struct arena ARENA;

ARENA *criaArena();

void pushArena(ARENA *a, void *forma, int id, TipoForma tipo);

void *popArena(ARENA *a);

int nFormas(ARENA *a);

void analisaArena(ARENA *a, PILHA *c, ESMAGADO *e);

#endif
