#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"


typedef struct {
    int i;
    double x;
    double y;
    char corb[20];
    char corp[20];
    char *a;
    char txto[50];
} TEXTOS;


Texto criaTexto(int i, double x, double y, char a, char *corb, char *corp, char txto[50]) {
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

int iTexto(Texto t){
    TEXTOS *tex = (TEXTOS *) t;
    return tex->i;
}

double xTexto(Texto t){
    TEXTOS *tex = (TEXTOS *) t;
    return tex->x;
}

double yTexto(Texto t){
    TEXTOS *tex = (TEXTOS *) t;
    return tex->y;
}

const char* corTextoP(Texto t) {
    TEXTOS *tex = (TEXTOS *) t;
    return tex->corp;
}

const char* corTextoB(Texto t) {
    TEXTOS *tex = (TEXTOS *) t;
    return tex->corb;
}

const char *aTexto(Texto t) {
    TEXTOS *tex = (TEXTOS *) t;
    return tex->a;
}

const char* txtoTexto(Texto t) {
    TEXTOS *tex = (TEXTOS *) t;
    return tex->txto;
}

void novoXTexto(Texto t, double x){
    TEXTOS *tex = (TEXTOS *) t;
    tex->x = x; 
}

void novoYTexto(Texto t, double y){
    TEXTOS *tex = (TEXTOS *) t;
    tex->y = y; 
}
