#ifndef DISPARADOR_H
#define DISPARADOR_H
#include "pilha.h"
#include "carregador.h"
#include "arena.h"


typedef struct disparador DISPARADOR;

DISPARADOR *criaDisparador(double dx, double dy);

void posicionarDis(DISPARADOR *d, double dx, double dy);
   
void encaixarCarregador(DISPARADOR *d, CARREGADOR *cesq, CARREGADOR *cdir);

void botoes(DISPARADOR *d, char botao, int n, CARREGADOR *cesq, CARREGADOR *cdir);

void *popDisparador(DISPARADOR *d);

void *pushDisparador(DISPARADOR *d, void *novaforma, int id, TipoForma tipo);

void disparar(DISPARADOR *d, ARENA *a, PILHA *chao, double dx, double dy, char dd, FILE *txt, FILE *svg);

void botoes(DISPARADOR *d, char botao, int n, CARREGADOR *cesq, CARREGADOR *cdir, FILE *txt);

#endif

#endif