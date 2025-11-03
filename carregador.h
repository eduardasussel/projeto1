#ifndef CARREGADOR_H
#define CARREGADOR_H
#include "pilha.h"

typedef enum { CIRCULO, RETANGULO, TEXTO, LINHA } TipoForma;

typedef struct carregador CARREGADOR;

CARREGADOR *criaCarregador();

int carregadorChao(CARREGADOR *c, PILHA *chao, int n, FILE *txt);

void *popCarregador(CARREGADOR *cesq, int *i, TipoForma tipo);

void *pushCarregador(CARREGADOR *c, void *forma, int id, TipoForma tipo);

#endif