#ifndef DISPARADOR_H
#define DISPARADOR_H
#include "pilha.h"

typedef struct pilha CESQ;
typedef struct pilha CDIR;
typedef struct pilha DISPARADOR;

void posicionarDis(DISPARADOR *d, double dx, double dy);

void colocarCarregadorC(PILHA *p, CESQ *ce, int n);

void encaixarCarregadores(DISPARADOR *d, CESQ *ce, CDIR *cd);

void botoes(DISPARADOR *d, char botao, int n);

void disparar(DISPARADOR *d, int i, double dx, double dy);

void rajada(DISPARADOR *d, char botao, double dx, double dy, double ix, double iy);

double Calculo(double esmagada);


#endif