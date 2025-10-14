#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"


typedef struct {
    int i;
    double x, y, raio;
    char corb[20];
    char corp[20];
} CIRCULOS;


Circulo criaCirculo(int i, double x, double y, double raio, char *corb, char *corp) {
    CIRCULOS *c = malloc(sizeof(CIRCULOS));
    if (!c) {
        printf("Erro ao alocar círculo!\n");
        exit(1);
    }

    c->i = i;
    c->x = x;
    c->y = y;
    c->raio = raio;
    strcpy(c->corb, corb);
    strcpy(c->corp, corp);
    return c;
}