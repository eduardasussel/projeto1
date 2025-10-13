#include "empilhar.h"
#include "pilha.h"
#include <stdio.h>

void Empilhar(PONTO *p, int i) {
    static PILHA *minhaPilha = NULL;

    if (minhaPilha == NULL)
        minhaPilha = criaPilha();

    push(minhaPilha, p); 
}