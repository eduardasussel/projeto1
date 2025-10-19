#ifndef ESMAGADO_H
#define ESMAGADO_H

typedef struct esmagado ESMAGADO;
typedef enum { CIRCULO, RETANGULO, TEXTO, LINHA } TipoForma;

ESMAGADO *criaEsmagado();

void pushEsmagado(ESMAGADO *e, void *forma, int id, TipoForma tipo);

void *popEsmagado(ESMAGADO *e);

#endif