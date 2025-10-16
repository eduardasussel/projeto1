#include <stdio.h>
#include <string.h>
#include "arquivo.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "pilha.h"
#include "disparador.h"
#include "carregador.h"


void lerArquivoGeo(const char *arqg, PILHA *chao){
FILE *fp = fopen(arqg, "r");
    if(fp == NULL){
        printf("Erro na abertura do arquivo");
    }

    char forma;

while (fscanf(fp, " %c", &forma) == 1) {
    if (forma =='c') {
        int i;
        double x, y, raio;
        char corb[20], corp[20];
        fscanf(fp, "%d %lf %lf %lf %s %s", &i, &x, &y, &raio, corb, corp);

        Circulo c = criaCirculo(i, x, y, raio, corb, corp);

        push(chao, c);
    }

     if(forma =='r') {
        int i;
        double x, y, largura, altura;
        char corb[20], corp[20];
        fscanf(fp, "%d %lf %lf %lf %lf %s %s", &i, &x, &y, &largura, &altura, corb, corp);

        Retangulo r = criaRetangulo(i, x, y, largura, altura, corb, corp);

        push(chao, r);
    }

    if(forma == 't') {
        int i;
        double x, y;
        char a, corb[20], corp[20], txto[50];
        fscanf(fp, "%d %lf %lf %c %s %s %s", &i, &x, &y, a, corb, corp, txto);

        Texto t = criaTexto(i, x, y, a, corb, corp, txto);

        push(chao, t);
    }

    if(forma == 'l'){
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

void lerArquivoQry(const char *arqq, PILHA *chao){
    FILE *fq = fopen(arqq, "r");
    if(fq == NULL){
        printf("Erro na abertura do arquivo");
    }

    char comando[4];
    DISPARADOR *d;

    while (fscanf(fq, " %s", &comando) == 1) {
     if (strcmp(comando, "pd") == 0) {
        double dx, dy;
        fscanf(fq, "%lf %lf", &dx, &dy);

        if (d == NULL){
                d = criaDisparador(dx, dy);

            } else {
                posicionarDisparador(d, dx, dy);
            }

    }

    CARREGADOR *cesq;
    CARREGADOR *cdir;
    
     if (strcmp(comando, "lc") == 0) {

        int n;
        fscanf(fq, "%d", &n);
        
        if (cesq == NULL){
                cesq = criaCarregador();

            } else {
                    carregadorChao(cesq, chao, n);
            }
    }

    if (strcmp(comando, "atch") == 0) {

        int n;
        fscanf(fq, "%d", &n);

        if (cesq == NULL){
                cdir = criaCarregador();

            } else {
                    encaixarCarregador(d,cesq, cdir);
    }
            }

    if (strcmp(comando, "shft") == 0) {

        char botao;
        int n;
        fscanf(fq, "%c %d", &botao, &n);

        botoes(d, botao, n, cesq, cdir);

        }
    
    
}
 fclose(fq);
}