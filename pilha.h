#ifndef PILHA_H
#define PILHA_H
#include "tipos.h"

typedef void *PILHA;
typedef void *NO; 

PILHA criaPilha();
void push(PILHA *p, void *forma, TipoForma tipo);
NO pop(PILHA *p);
int pilhaTamanho(PILHA *p);


NO topoPilha(PILHA *p);
NO proxNo(NO *n);
void *getInfoNo(NO *n);
TipoForma getTipoNo(NO *n);

#endif

