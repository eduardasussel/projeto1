#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linha.h"

typedef struct {
    int i;
    double x1;
    double y1;
    double x2;
    double y2;
    char corp[20];
} LINHAS;

Linha criaLinha(int i, double x1, double y1, double x2, double y2, char *corp) {
    LINHAS *l = malloc(sizeof(LINHAS));
    if (!l) {
        printf("Erro ao alocar linha!\n");
        exit(1);
    }

    l->i = i;
    l->x1 = x1;
    l->y1 = y1;
    l->x2 = x2;
    l->y2 = y2;
    strcpy(l->corp, corp);
    return l;
}

void moveLinha(Linha l, double dx, double dy) {
    LINHAS *lin = (LINHAS *) l;
    lin->x1 += dx;
    lin->y1 += dy;
    lin->x2 += dx;
    lin->y2 += dy;
}