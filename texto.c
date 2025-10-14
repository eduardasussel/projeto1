#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"


typedef struct {
    int i;
    double x;
    double y;
    double raio;
    char corb[20];
    char corp[20];
    char *a;
    char txto[50];
} TEXTOS;


Texto criaTexto(int i, double x, double y, double raio, char *corb, char *corp, char *txto) {
    TEXTOS *t = malloc(sizeof(TEXTOS));
    if (!t) {
        printf("Erro ao alocar círculo!\n");
        exit(1);
    }

    t->i = i;
    t->x = x;
    t->y = y;
    strcpy(t->corb, corb);
    strcpy(t->corp, corp);
    t->a = "a";
    strcpy(t->txto, txto);
    return t;
}