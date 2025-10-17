#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"

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

double area(Circulo t) {
    CIRCULOS *c = (CIRCULOS *) t;
    return 3.14159 * c->raio * c->raio;
}

void movecirculo(Circulo c, double dx, double dy) {
    CIRCULOS *cir = (CIRCULOS *) c;
    cir->x += dx;
    cir->y += dy;
}