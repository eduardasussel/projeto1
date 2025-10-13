#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int i;
    struct elemento *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct{
    PONT topo;
} PILHA;

PILHA *criaPilha() {
    PILHA *p = malloc(sizeof(PILHA));
    p->topo = NULL;
    return p;
}