#ifndef CARREGADOR_H
#define CARREGADOR_H
#include "pilha.h"
#include "tipos.h"

typedef void *CARREGADOR;

CARREGADOR criaCarregador();

int carregadorChao(CARREGADOR *c, PILHA *chao, int idBase, FILE *txt);

int carregadorVazio(CARREGADOR *c);

void *popCarregador(CARREGADOR *c, int *id, TipoForma *tipo);

void pushCarregador(CARREGADOR *c, void *forma, int id, TipoForma tipo);

#endif