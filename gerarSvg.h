#ifndef GERAR_SVG_H
#define GERAR_SVG_H
#include <stdio.h>
#include "tipos.h"
#include "carregador.h"
#include "pilha.h"
#include "formas.h"


FILE *criaArquivoSvg(CARREGADOR *cesq, CARREGADOR *cdir, PILHA *e, char *nomeArquivo);

void fechaArquivoSvg(FILE *fp);

void marcarEsmagados(FILE *svg, PILHA *e);

void dimensoesDisp(double x, double y, double dx, double dy, FILE *svg);

void reportaDadosSvg(void *forma, TipoForma tipo, FILE *svg);

void asterisco(FILE *svg, double x, double y);

#endif
