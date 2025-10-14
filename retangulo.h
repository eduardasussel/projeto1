#ifndef RETANGULO_H
#define RETANGULO_H


typedef void *Retangulo;

Retangulo criaRetangulo(int i, double x, double y, double largura, double altura, char *corb, char *corp);

double area(Retangulo t);

double rotaciona(Retangulo t, double graus);

double move(Retangulo t, double dx, double dy);

double translada(Retangulo t, double angulo, double extensão);

void toSvg(Retangulo t, char buf[], int lenBuf);

#endif