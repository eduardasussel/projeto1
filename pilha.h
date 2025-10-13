#ifndef PILHA_H
#define PILHA_H

typedef struct pilha PILHA;
typedef struct ponto PONTO;

PILHA *criaPilha();
void push(PILHA *p, PONTO *ponto);
PONTO *pop(PILHA *p);

#endif