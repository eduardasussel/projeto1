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