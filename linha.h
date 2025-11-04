#ifndef LINHA_H
#define LINHA_H

typedef void *Linha;

Linha criaLinha(int i, double x1, double y1, double x2, double y2, char *corp);

double area(Linha t);

double rotaciona(Linha t, double graus);

void moveLinha(Linha t, double dx, double dy);

double translada(Linha t, double angulo, double extensao);

void toSvg(Linha t, char buf[], int lenBuf);

int iLinha(Linha i);

double x1Linha(Linha l);

double x2Linha(Linha l);

double y1Linha(Linha l);

double y2Linha(Linha l);

const char* corLinha(Linha l);

void novoX1Linha(Linha l, double x1);

void novoY1Linha(Linha l, double y1);

void novoX2Linha(Linha l, double x1);

void novoY2Linha(Linha l, double y1);

#endif