#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"


typedef struct {
    int i;
    double x;
    double y;
    double raio;
    char *a;
    char corb[20];
    char corp[20];
    char txto[50];
} TEXTOS;


Texto criaTexto(int i, double x, double y, char *a, char *corb, char *corp, char *txto) {
    TEXTOS *t = malloc(sizeof(TEXTOS));
    if (!t) {
        printf("Erro ao alocar texto!\n");
        exit(1);
    }

    t->i = i;
    t->x = x;
    t->y = y;
    t->a = "a";
    strcpy(t->corb, corb);
    strcpy(t->corp, corp);
    strcpy(t->txto, txto);
    return t;
}

void moveTexto(Texto t, double dx, double dy) {
    TEXTOS *tex = (TEXTOS *) t;
    tex->x += dx;
    tex->y += dy;
}