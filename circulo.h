#ifndef CIRCULO_H
#define CIRCULO_H

typedef void *Circulo;

Circulo criaCirculo(int i, double x, double y, double raio, const char *corb, const char *corp);

double areaCirculo(Circulo t);

double rotaciona(Circulo t, double graus);

void moveCirculo(Circulo t, double dx, double dy);

double translada(Circulo t, double angulo, double extensão);

void toSvg(Circulo t, char buf[], int lenBuf);

double xCirculo(Circulo c);

double yCirculo(Circulo c);

double raioCirculo(Circulo c);

const char* corCirculoP(Circulo c);

const char* corCirculoB(Circulo c);

void novaCorCirculoP(Circulo c, const char *novaCor);

void novaCorCirculoB(Circulo c, const char *novaCor);

Circulo clonaCirculo(Circulo c);

#endif