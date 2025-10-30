#ifndef GERARSVG_H
#define GERARSVG_H

void criaArquivo();

void dimensoesDisp(double x, double y, double dx, double dy, FILE *svg);

void reportaDadosSvg(void *forma, TipoForma tipo, FILE *svg);

#endif