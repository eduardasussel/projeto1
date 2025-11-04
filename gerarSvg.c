#include <stdio.h>
#include <string.h>
#include "gerarSvg.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "disparador.h"
#include "formas.h" 
#include "pilha.h"


FILE *criaArquivoSvg(CARREGADOR *cesq, CARREGADOR *cdir, PILHA *e, char *nomeArquivo) {
    FILE *svg = fopen(nomeArquivo, "w");
    if (!svg) {
        printf("Erro ao criar arquivo SVG!\n");
        return NULL;
    }

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
    return svg;
}

void fechaArquivoSvg(FILE *svg) {
    if (svg) {
        fprintf(svg, "</svg>\n");
        fclose(svg);
    }
}

void marcarEsmagados(FILE *svg, PILHA *e) {
    if (!svg || !e) return;

    NO *atual = topoPilha(e);
while (atual) {
    double cx, cy;
    TipoForma tipo = getTipoNo(atual);
    void *forma = getInfoNo(atual);
    centro(forma, tipo, &cx, &cy);
    asterisco(svg, cx, cy);
    atual = proxNo(atual);
}
}



void dimensoesDisp(double x, double y, double dx, double dy, FILE *svg) {
    if (!svg) return;

    double largura = dx - x;
    double altura = dy - y;

    fprintf(svg,
        "<rect x=\"%.2f\" y=\"%.2f\" width=\"%.2f\" height=\"%.2f\" "
        "fill=\"none\" stroke=\"red\" stroke-dasharray=\"4\" />\n",
        x, y, largura, altura
    );
    fflush(svg);
}

void reportaDadosSvg(void *forma, TipoForma tipo, FILE *svg) {
    if (!forma || !svg) return;

    switch (tipo) {
        case CIRCULO: {
            Circulo c = (Circulo) forma;
            fprintf(svg,
                "<circle cx=\"%.2lf\" cy=\"%.2lf\" r=\"%.2lf\" "
                "stroke=\"%s\" fill=\"%s\" />\n",
                xCirculo(c),
                yCirculo(c),
                raioCirculo(c),
                corCirculoB(c),
                corCirculoP(c)
            );
            break;
        }

        case RETANGULO: {
            Retangulo r = (Retangulo) forma;
            fprintf(svg,
                "<rect x=\"%.2lf\" y=\"%.2lf\" width=\"%.2lf\" height=\"%.2lf\" "
                "stroke=\"%s\" fill=\"%s\" />\n",
                xRetangulo(r),
                yRetangulo(r),
                larRetangulo(r),
                altRetangulo(r),
                corRetanguloB(r),
                corRetanguloP(r)
            );
            break;
        }

        case LINHA: {
            Linha l = (Linha) forma;
            fprintf(svg,
                "<line x1=\"%.2lf\" y1=\"%.2lf\" x2=\"%.2lf\" y2=\"%.2lf\" "
                "stroke=\"%s\" />\n",
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
                "<text x=\"%.2lf\" y=\"%.2lf\" fill=\"%s\" stroke=\"%s\">%s</text>\n",
                xTexto(t),
                yTexto(t),
                corTextoP(t),
                corTextoB(t),
                txtoTexto(t)
            );
            break;
        }

        default:
            break;
    }
}

