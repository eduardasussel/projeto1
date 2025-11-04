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
#include "arena.h"
#include "esmagado.h"


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

        push(chao, c, CIRCULO);
    }

     if(forma =='r') {
        int i;
        double x, y, largura, altura;
        char corb[20], corp[20];
        fscanf(fp, "%d %lf %lf %lf %lf %s %s", &i, &x, &y, &largura, &altura, corb, corp);

        Retangulo r = criaRetangulo(i, x, y, largura, altura, corb, corp);

        push(chao, r, RETANGULO);
    }

    if(forma == 't') {
        int i;
        double x, y;
        char a, corb[20], corp[20], txto[50];
        fscanf(fp, "%d %lf %lf %c %s %s %s", &i, &x, &y, &a, corb, corp, txto);

        Texto t = criaTexto(i, x, y, a, corb, corp, txto);

        push(chao, t, TEXTO);
    }

    if(forma == 'l'){
        int i;
        double x1, y1, x2, y2;
        char corp[20];
        fscanf(fp, "%d %lf %lf %lf %lf %s", &i, &x1, &y1, &x2, &y2, corp);

        Linha l = criaLinha(i, x1, y1, x2, y2, corp);

         push(chao, l, LINHA);
    }
}

fclose(fp);
}

void lerArquivoQry(const char *arqq, PILHA *chao) {
    FILE *fq = fopen(arqq, "r");
    if (!fq) {
        printf("Erro na abertura do arquivo QRY\n");
        return;
    }

    char comando[10];
    DISPARADOR *d = NULL;
    CARREGADOR *cesq = NULL;
    CARREGADOR *cdir = NULL;
    ARENA *a = NULL;
    FILE *txt = NULL;
    FILE *svg = NULL;

    while (fscanf(fq, " %s", comando) == 1) {

        if (strcmp(comando, "pd") == 0) {
            double dx, dy;
            fscanf(fq, "%lf %lf", &dx, &dy);

            if (!d) {
                d = criaDisparador(dx, dy);
            } else {
                posicionarDis(d, dx, dy);
            }
        }

        else if (strcmp(comando, "lc") == 0) {
            int n;
            fscanf(fq, "%d", &n);

            if (!cesq) cesq = criaCarregador();

            if (!txt) txt = fopen("saida.txt", "w");
            
            carregadorChao(cesq, chao, n, txt);
        }

        else if (strcmp(comando, "atch") == 0) {
            if (!cdir) cdir = criaCarregador();
            encaixarCarregador(d, cesq, cdir);
        }

        else if (strcmp(comando, "shft") == 0) {
            char botao;
            int n;
            fscanf(fq, " %c %d", &botao, &n);

            botoes(d, botao, n, cesq, cdir, &txt);
        }

        else if (strcmp(comando, "dsp") == 0) {
            double dx, dy;
            char dd;
            fscanf(fq, "%lf %lf %c", &dx, &dy, &dd);

            disparar(d, a, chao, dx, dy, dd, &txt, &svg);
        }

        else if (strcmp(comando, "rjd") == 0) {
            char lado;
            double dx, dy, ix, iy;
            fscanf(fq, " %c %lf %lf %lf %lf", &lado, &dx, &dy, &ix, &iy);

            CARREGADOR *c = (lado == 'e') ? cesq : cdir;

            if (c && d) {
                int i = 0;
                while (!carregadorVazio(c)) {
                    double deslocX = dx + i * ix;
                    double deslocY = dy + i * iy;

                    botoes(d, lado, 1, cesq, cdir, &txt);
                    disparar(d, a, chao, deslocX, deslocY, 'n', &txt, &svg);

                    i++;
                }
            } else {
                printf("Carregador ou disparador não inicializado!\n");
            }
        }

        else if (strcmp(comando, "calc") == 0) {
            ESMAGADO *e = criaEsmagado();
            calculo(e, svg);
        }
    }

    if (txt) fclose(txt);
    if (svg) fclose(svg);
    if (fq) fclose(fq);
}
