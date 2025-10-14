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
    l->x1 = x2;
    l->y1 = y2;
    strcpy(l->corp, corp);
    return l;
}