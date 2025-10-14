#include <stdio.h>
#include "arquivo.h"
#include "circulo.h"
#include "retangulo.h"


void lerArquivoGeo(){
FILE *fp = fopen("entrada/entrada.txt", "r");
    if(fp == NULL){
        printf("Erro na abertura do arquivo");
    }

    char forma;

while (fscanf(fp, " %c", &forma) == 1) {
    if(forma == "c"){
        int i;
        double x, y, raio;
        char corb[20], corp[20];
        fscanf(fp, "%d %lf %lf %lf %s %s", &i, &x, &y, &raio, corb, corp);

        Circulo c = criaCirculoColorido(i, x, y, raio, corb, corp);

    }

     if(forma == "r"){
        int i;
        double x, y, largura, altura;
        char corb[20], corp[20];
        fscanf(fp, "%d %lf %lf %lf %s %s", &i, &x, &y, &largura, &altura, corb, corp);

        Circulo c = criaCirculoColorido(i, x, y, largura, altura, corb, corp);

    }
}

fclose(fp);
}