#include <stdio.h>
#include <string.h>
#include "arquivo.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "pilha.h"


void lerArquivoGeo(){
FILE *fp = fopen("entrada/entrada.txt", "r");
    if(fp == NULL){
        printf("Erro na abertura do arquivo");
    }

    PILHA *chao = criaPilha();
    char forma;

while (fscanf(fp, " %c", &forma) == 1) {
    if (forma, 'c') {
        int i;
        double x, y, raio;
        char corb[20], corp[20];
        fscanf(fp, "%d %lf %lf %lf %s %s", &i, &x, &y, &raio, corb, corp);

        Circulo c = criaCirculo(i, x, y, raio, corb, corp);

        push(chao, c);
    }

     if(forma, "r") {
        int i;
        double x, y, largura, altura;
        char corb[20], corp[20];
        fscanf(fp, "%d %lf %lf %lf %lf %s %s", &i, &x, &y, &largura, &altura, corb, corp);

        Retangulo r = criaRetangulo(i, x, y, largura, altura, corb, corp);

        push(chao, r);
    }

    if(forma, "t") {
        int i;
        double x, y;
        char a, corb[20], corp[20], txto[50];
        fscanf(fp, "%d %lf %lf %c %s %s %s", &i, &x, &y, a, corb, corp, txto);

        Texto t = criaTexto(i, x, y, a, corb, corp, txto);

        push(chao, t);
    }

    if(strcmp(forma, "l") == 0){
        int i;
        double x1, y1, x2, y2;
        char corp[20];
        fscanf(fp, "%d %lf %lf %lf %lf %s", &i, &x1, &y1, &x2, &y2, corp);

        Linha l = criaLinha(i, x1, y1, x2, y2, corp);

         push(chao, l);
    }
}

fclose(fp);
}