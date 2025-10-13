#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "ponto.h"


typedef void *Triangulo;

Triangulo criaTriangulo(Ponto v1, Ponto v2, Ponto v3);

Triangulo criaTrianguloColorido(Ponto v1, Ponto v2, Ponto v3, char *corPreench, char *corBorda);

Ponto gotAncora(Triangulo t);

double area(Triangulo t);

double rotaciona(Triangulo t, double graus);

double move(Triangulo t, double dx, double dy);

double translada(Triangulo t, double angulo, double extensão);

void toSvg(Triangulo t, char buf[], int lenBuf);

