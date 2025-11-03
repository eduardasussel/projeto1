#ifndef RETANGULO_H
#define RETANGULO_H


typedef void *Retangulo;

Retangulo criaRetangulo(int i, double x, double y, double largura, double altura, char *corb, char *corp);

double areaRetangulo(Retangulo r);

double rotaciona(Retangulo t, double graus);

void moveRetangulo(Retangulo t, double dx, double dy);

double translada(Retangulo t, double angulo, double extensao);

void toSvg(Retangulo t, char buf[], int lenBuf);

int iRetangulo(Retangulo r);

double xRetangulo(Retangulo r);

double yRetangulo(Retangulo r);

double larRetangulo(Retangulo r);

double altRetangulo(Retangulo r);

const char* corRetanguloP(Retangulo r);

const char* corRetanguloB(Retangulo r);

void novaCorRetanguloP(Retangulo r, const char *novaCor);

void novaCorRetanguloB(Retangulo r, const char *novaCor);

Retangulo clonaRetangulo(Retangulo r);

#endif