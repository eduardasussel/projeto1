#ifndef PILHA_H
#define PILHA_H

typedef struct pilha PILHA;

PILHA *criaPilha();

void push(PILHA *p, void *i);

void *pop(PILHA *p);

#endif