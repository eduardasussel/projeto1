#ifndef DISPARADOR_H
#define DISPARADOR_H

#include <stdio.h>
#include "pilha.h"
#include "carregador.h"
#include "arena.h"
#include "tipos.h"
#include "esmagado.h"

typedef void *DISPARADOR;

DISPARADOR criaDisparador(double dx, double dy);

void posicionarDis(DISPARADOR d, double dx, double dy);

void encaixarCarregador(DISPARADOR d, CARREGADOR cesq, CARREGADOR cdir);

void *pushDisparador(DISPARADOR d, void *novaforma, int id, TipoForma tipo);

void *popDisparador(DISPARADOR d);

void botoes(DISPARADOR d, char botao, int n, FILE **txt);

void disparar(DISPARADOR d, ARENA *a, PILHA *chao, ESMAGADO *e, double dx, double dy, char dd, FILE **txt, FILE **svg);

#endif

