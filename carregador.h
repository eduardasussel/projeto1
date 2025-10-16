#ifndef CARREGADOR_H
#define CARREGADOR_H
#include "pilha.h"


typedef struct carregador CARREGADOR;

CARREGADOR *criaCarregador();

int carregadorChao(CARREGADOR *c, PILHA *chao, int n);

void *popCarregador(CARREGADOR *c);

void *pushCarregador(CARREGADOR *c, void *novaforma);

#endif