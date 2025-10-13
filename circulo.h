#ifndef CIRCULO_H
#define CIRCULO_H


typedef void *Circulo;

Circulo criaCirculo(int i, double x, double y, double raio);

Circulo criaCirculoColorido(int i, double x, double y, double raio, char *corb, char *corp);

double area(Circulo t);

double rotaciona(Circulo t, double graus);

double move(Circulo t, double dx, double dy);

double translada(Circulo t, double angulo, double extensão);

void toSvg(Circulo t, char buf[], int lenBuf);

#endif