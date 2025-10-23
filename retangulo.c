#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"


typedef struct {
    int i;
    double x;
    double y;
    double largura;
    double altura;
    char corb[20];
    char corp[20];
} RETANGULOS;


Retangulo criaRetangulo(int i, double x, double y, double largura, double altura, char *corb, char *corp) {
    RETANGULOS *r = malloc(sizeof(RETANGULOS));
    if (!r) {
        printf("Erro ao alocar retangulo!\n");
        exit(1);
    }

    r->i = i;
    r->x = x;
    r->y = y;
    r->largura = largura;
    r->altura = altura;
    strcpy(r->corb, corb);
    strcpy(r->corp, corp);
    return r; 
}

void moveRetangulo(Retangulo r, double dx, double dy) {
    RETANGULOS *ret = (RETANGULOS *) r;
    ret->x += dx;
    ret->y += dy;
}

double areaRetangulo(Retangulo r){
    RETANGULOS *ret = (RETANGULOS *) r;
    return ret->largura * ret->altura;
}

int iRetangulo(Retangulo r){
    RETANGULOS *ret = (RETANGULOS *) r;
    return ret->i;
}

double xRetangulo(Retangulo r){
    RETANGULOS *ret = (RETANGULOS *) r;
    return ret->x;
}

double yRetangulo(Retangulo r){
    RETANGULOS *ret = (RETANGULOS *) r;
    return ret->y;
}

double larRetangulo(Retangulo r){
    RETANGULOS *ret = (RETANGULOS *) r;
    return ret->largura;
}

double altRetangulo(Retangulo r){
    RETANGULOS *ret = (RETANGULOS *) r;
    return ret->altura;
}

const char* corRetanguloP(Retangulo r) {
    RETANGULOS *ret = (RETANGULOS *) r;
    return ret->corp;
}

const char* corRetanguloB(Retangulo r) {
    RETANGULOS *ret = (RETANGULOS *) r;
    return ret->corb;
}

void novaCorRetanguloP(Retangulo r, const char *novaCor){
    RETANGULOS *ret = (RETANGULOS *) r;
    strcpy(ret->corb, novaCor);
}

void novaCorRetanguloB(Retangulo r, const char *novaCor){
    RETANGULOS *ret = (RETANGULOS *) r;
    strcpy(ret->corp, novaCor);
}

Retangulo clonaRetangulo(Retangulo r) {
    RETANGULOS *ret = (RETANGULOS*) r;
    return criaRetangulo(ret->i, ret->x, ret->y, ret->largura, ret->altura, ret->corb, ret->corp);
}

double PegaAreaRet(Retangulo r){
    RETANGULOS *ret = (RETANGULOS *) r;
    return ret->largura * ret->altura;
}