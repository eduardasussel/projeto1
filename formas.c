#include <stdio.h>
#include "formas.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"

int idForma(void *forma, TipoForma tipo) {
    switch (tipo) {
        case CIRCULO:   return iCirculo(forma);
        case RETANGULO: return iRetangulo(forma);
        case TEXTO:     return iTexto(forma);
        case LINHA:     return iLinha(forma);
        default:        return -1;
    }
}

TipoForma tipoForma(void *forma) {
    return -1;
}

void centro(void *forma, TipoForma tipo, double *cx, double *cy) {
    switch (tipo) {
        case CIRCULO: {
            Circulo c = (Circulo) forma;
            *cx = xCirculo(c);
            *cy = yCirculo(c);
            break;
        }
        case RETANGULO: {
            Retangulo r = (Retangulo) forma;
            *cx = xRetangulo(r) + larRetangulo(r) / 2.0;
            *cy = yRetangulo(r) + altRetangulo(r) / 2.0;
            break;
        }
        case LINHA: {
            Linha l = (Linha) forma;
            *cx = (x1Linha(l) + x2Linha(l)) / 2.0;
            *cy = (y1Linha(l) + y2Linha(l)) / 2.0;
            break;
        }
        case TEXTO: {
            Texto t = (Texto) forma;
            *cx = xTexto(t);
            *cy = yTexto(t);
            break;
        }
        default:
            *cx = *cy = 0;
            break;
    }
}

void asterisco(FILE *svg, double x, double y){

    if (!svg) return;
    fprintf(svg,
        "<text x=\"%.2f\" y=\"%.2f\" fill=\"red\" font-size=\"12\" "
        "text-anchor=\"middle\" dominant-baseline=\"middle\">*</text>\n",
        x, y
    );
}