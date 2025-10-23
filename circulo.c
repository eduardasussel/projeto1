#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"

#define PI 3.14159

typedef struct {
    int i;
    double x;
    double y;
    double raio;
    char corb[20];
    char corp[20];
} CIRCULOS;

Circulo criaCirculo(int i, double x, double y, double raio, const char *corb, const char *corp) {
    CIRCULOS *c = malloc(sizeof(CIRCULOS));
    if (!c) {
        printf("Erro ao alocar círculo!");
        exit(1);
    }

    c->i = i;
    c->x = x;
    c->y = y;
    c->raio = raio;

    
    strncpy(c->corb, corb, sizeof(c->corb) - 1);
    c->corb[sizeof(c->corb) - 1] = '\0';

    strncpy(c->corp, corp, sizeof(c->corp) - 1);
    c->corp[sizeof(c->corp) - 1] = '\0';

    return (Circulo)c;
}

void movecirculo(Circulo c, double dx, double dy) {
    CIRCULOS *cir = (CIRCULOS *) c;
    cir->x += dx;
    cir->y += dy;
}

double areaCirculo(Circulo c){
    CIRCULOS *cir = (CIRCULOS *) c;
    return PI * cir->raio * cir->raio; 
}

int iCirculo(Circulo c){
    CIRCULOS *cir = (CIRCULOS *) c;
    return cir->i;
}

double xCirculo(Circulo c){
    CIRCULOS *cir = (CIRCULOS *) c;
    return cir->x;
}

double yCirculo(Circulo c){
    CIRCULOS *cir = (CIRCULOS *) c;
    return cir->y;
}

double raioCirculo(Circulo c){
    CIRCULOS *cir = (CIRCULOS *) c;
    return cir->raio;
}

const char* corCirculoP(Circulo c) {
    CIRCULOS *cir = (CIRCULOS *) c;
    return cir->corp;
}

const char* corCirculoB(Circulo c) {
    CIRCULOS *cir = (CIRCULOS *) c;
    return cir->corb;
}

void novaCorCirculoP(Circulo c, const char *novaCor){
    CIRCULOS *cir = (CIRCULOS *) c;
    strcpy(cir->corb, novaCor);
}

void novaCorCirculoB(Circulo c, const char *novaCor){
    CIRCULOS *cir = (CIRCULOS *) c;
    strcpy(cir->corp, novaCor);
}

Circulo clonaCirculo(Circulo c) {
    CIRCULOS *cir = (CIRCULOS*) c;
    return criaCirculoColorido(cir->i, cir->x, cir->y, cir->raio, cir->corb, cir->corp);
}