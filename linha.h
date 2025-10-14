#ifndef LINHA_H
#define LINHA_H


typedef void *Linha;

Linha criaLinha(int i, double x1, double y1, double x2, double y2, char *corp);


double area(Linha t);

double rotaciona(Linha t, double graus);

double move(Linha t, double dx, double dy);

double translada(Linha t, double angulo, double extensão);

void toSvg(Linha t, char buf[], int lenBuf);

#endif