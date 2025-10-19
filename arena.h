#ifndef ARENA_H
#define ARENA_H
#include "pilha.h"

typedef struct arena ARENA;
typedef enum { CIRCULO, RETANGULO, TEXTO, LINHA } TipoForma;

ARENA *criaArena();

void pushArena(ARENA *a, void *forma, int id, TipoForma tipo);

void *popArena(ARENA *a);

int nFormas(ARENA *a);

void analisaArena(ARENA *a, PILHA *c);

#endif
