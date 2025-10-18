#ifndef ARENA_H
#define ARENA_H


typedef struct arena ARENA;

ARENA *criaArena();

void pushArena(ARENA *a, void *novoitem, int id, TipoForma tipo);

#endif