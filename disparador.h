#ifndef DISPARADOR_H
#define DISPARADOR_H
#include "pilha.h"
#include "carregador.h"


typedef struct disparador DISPARADOR;

void CriaDisparador(double dx, double dy);

void posicionarDis(DISPARADOR *d, double dx, double dy);
   
void colocarCarregadorC(DISPARADOR *p, CESQ *ce, int n);

void encaixarCarregadores(DISPARADOR *d, CESQ *ce, CDIR *cd);

void botoes(DISPARADOR *d, char botao, int n);

void disparar(DISPARADOR *d, int i, double dx, double dy);

void rajada(DISPARADOR *d, char botao, double dx, double dy, double ix, double iy);

double Calculo(double esmagada);

#endif