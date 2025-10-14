#ifndef TEXTO_H
#define TEXTO_H


typedef void *Texto;

Texto criaTexto(int i, double x, double y, char *corb, char *corp, char *a, char txto[50]);

double area(Texto t);

double rotaciona(Texto t, double graus);

double move(Texto t, double dx, double dy);

double translada(Texto t, double angulo, double extensão);

void toSvg(Texto t, char buf[], int lenBuf);

#endif