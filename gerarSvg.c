#include <stdio.h>
#include <string.h>
#include "gerarSvg.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "disparador.h"

typedef enum { CIRCULO, RETANGULO, LINHA, TEXTO } TipoForma;

void criaArquivo(FILE *fp){
    FILE *fp = fopen("dadosFormas.svg", "w");
    if(fp == NULL){
        printf("Erro na criação do arquivo");
    } 

    fclose(fp);
}

void dimensoesDisp(double x, double y, double dx, double dy, FILE *svg){
    if (svg == NULL) return;

    double largura = dx - x;
    double altura = dy - y;

    fprintf(svg, "<rect x=\"%.2f\" y=\"%.2f\" width=\"%.2f\" height=\"%.2f\" "
                 "fill=\"none\" stroke=\"red\" stroke-dasharray=\"4\"/>\n",
            x, y, largura, altura);
    
    fflush(svg);
}

void reportaDadosSvg(void *forma, TipoForma tipo, FILE *svg){
    if (forma == NULL || svg == NULL) return;

    switch (tipo) {

        case CIRCULO: {
            Circulo c = (Circulo) forma;
            fprintf(svg, 
                "Círculo (id=%d): x=%.2lf, y=%.2lf, r=%.2lf, corb=%s, corp=%s\n",
                idCirculo(c), 
                xCirculo(c), 
                yCirculo(c), 
                raioCirculo(c), 
                corbCirculo(c), 
                corpCirculo(c)
            );
            break;
        }

        case RETANGULO: {
            Retangulo r = (Retangulo) forma;
            fprintf(svg, 
                "Retângulo (id=%d): x=%.2lf, y=%.2lf, largura=%.2lf, altura=%.2lf, corb=%s, corp=%s\n",
                idRetangulo(r),
                xRetangulo(r),
                yRetangulo(r),
                larRetangulo(r),
                altRetangulo(r),
                corbRetangulo(r),
                corpRetangulo(r)
            );
            break;
        }

        case LINHA: {
            Linha l = (Linha) forma;
            fprintf(svg, 
                "Linha (id=%d): (x1=%.2lf, y1=%.2lf) → (x2=%.2lf, y2=%.2lf), cor=%s\n",
                idLinha(l),
                x1Linha(l),
                y1Linha(l),
                x2Linha(l),
                y2Linha(l),
                corLinha(l)
            );
            break;
        }

        case TEXTO: {
            Texto t = (Texto) forma;
            fprintf(svg, 
                "Texto (id=%d): x=%.2lf, y=%.2lf, corb=%s, corp=%s, a=%c, conteúdo=\"%s\"\n",
                idTexto(t),
                xTexto(t),
                yTexto(t),
                corTextoB(t),
                corTextoP(t),
                svgoTextoB(t),
                aTexto(t)
            );
            break;
        }

        default:

            break;
    }
}

