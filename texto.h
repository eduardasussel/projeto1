#ifndef TEXTO_H
#define TEXTO_H


typedef void *Texto;

Texto criaTexto(int i, double x, double y, char *corb, char *corp, char *a, char txto[50]);

double area(Texto t);

double rotaciona(Texto t, double graus);

void move(Texto t, double dx, double dy);

double translada(Texto t, double angulo, double extensão);

void toSvg(Texto t, char buf[], int lenBuf);

int iTexto(Texto t);

double xTexto(Texto t);

double yTexto(Texto t);

const char* corTextoP(Texto r);

const char* corTextoB(Texto r);

char aTexto(Texto t);

const char* txtoTexto(Texto t) ;



#endif