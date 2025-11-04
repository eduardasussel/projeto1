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
    char corb[20];
} LINHAS;

Linha criaLinha(int i, double x1, double y1, double x2, double y2, char *corb) {
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
    strcpy(l->corb, corb);
    return l;
}

void moveLinha(Linha l, double dx, double dy) {
    LINHAS *lin = (LINHAS *) l;
    lin->x1 += dx;
    lin->y1 += dy;
    lin->x2 += dx;
    lin->y2 += dy;
}

const char* corLinhaB(Linha l) {
    LINHAS *lin = (LINHAS *) l;
    return lin->corb;
}

void novaCorLinhaP(Linha l, const char *novaCor){
    LINHAS *lin = (LINHAS *) l;
    strcpy(lin->corb, novaCor);
}

Linha clonaLinha(Linha l) {
    LINHAS *lin = (LINHAS*) l;
    return criaLinha(lin->i, lin->x1, lin->y1, lin->x2, lin->y2, lin->corb);
}

int iLinha(Linha l){
    LINHAS *lin = (LINHAS *) l;
    return lin->i;
}

double x1Linha(Linha l){
    LINHAS *lin = (LINHAS *) l;
    return lin->x1;
}

double x2Linha(Linha l){
    LINHAS *lin = (LINHAS *) l;
    return lin->x2;
}
double y1Linha(Linha l){
    LINHAS *lin = (LINHAS *) l;
    return lin->y1;
}

double y2Linha(Linha l){
    LINHAS *lin = (LINHAS *) l;
    return lin->y2;
}

const char* corLinha(Linha l) {
    LINHAS *lin = (LINHAS *) l;
    return lin->corb;
}

void novoX1Linha(Linha l, double x1){
    LINHAS *lin = (LINHAS *) l;
    lin->x1 = x1; 
}

void novoY1Linha(Linha l, double y1){
    LINHAS *lin = (LINHAS *) l;
    lin->y1 = y1; 
}

void novoX2Linha(Linha l, double x2){
    LINHAS *lin = (LINHAS *) l;
    lin->x2 = x2; 
}

void novoY2Linha(Linha l, double y1){
    LINHAS *lin = (LINHAS *) l;
    lin->y2 = y1; 
}