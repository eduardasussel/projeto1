#include <stdio.h>
#include <string.h>
#include "arquivo.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "disparador.h"

typedef enum { CIRCULO, RETANGULO, LINHA, TEXTO } TipoForma;

void criaArquivo(FILE *fp){
    FILE *fp = fopen("dadosFormas.txt", "w");
    if(fp == NULL){
        printf("Erro na criação do arquivo");
    }

    fclose(fp);
}

void reportaDados(void *forma, TipoForma tipo, FILE *txt){
    if (forma == NULL || txt == NULL) return;

    switch (tipo) {

        case CIRCULO: {
            Circulo c = (Circulo) forma;
            fprintf(txt, 
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
            fprintf(txt, 
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
            fprintf(txt, 
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
            fprintf(txt, 
                "Texto (id=%d): x=%.2lf, y=%.2lf, corb=%s, corp=%s, a=%c, conteúdo=\"%s\"\n",
                idTexto(t),
                xTexto(t),
                yTexto(t),
                corTextoB(t),
                corTextoP(t),
                txtoTextoB(t),
                aTexto(t)
            );
            break;
        }

        default:

            break;
    }
}