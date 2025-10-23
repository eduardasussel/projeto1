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