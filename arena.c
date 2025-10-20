#include <stdio.h>
#include <stdlib.h>
#include "arena.h"
#include "pilha.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "esmagado.h"

typedef struct aForma {
    void *forma;
    int id;
    TipoForma tipo;
    struct aForma *prox;
} AFORMA;

struct arena {
    AFORMA *topo;
    int nformas;
};

ARENA *criaArena() {
    ARENA *a = malloc(sizeof(ARENA));
    if (!a) {
        printf("Erro ao alocar arena!\n");
        exit(1);
    }
    a->topo = NULL;
    a->nformas = 0;
    return a;
}

void pushArena(ARENA *a, void *forma, int id, TipoForma tipo) {
    if (!a) return;

    AFORMA *novo = malloc(sizeof(AFORMA));
    if (!novo) {
        printf("Erro ao alocar forma na arena!\n");
        exit(1);
    }

    novo->forma = forma;
    novo->id = id;
    novo->tipo = tipo;
    novo->prox = a->topo;

    a->topo = novo;
    a->nformas++;
}

void *popArena(ARENA *a) {
    if (!a || !a->topo) return NULL;

    AFORMA *removido = a->topo;
    void *forma = removido->forma;

    a->topo = removido->prox;
    free(removido);
    a->nformas--;

    return forma;
}

int nFormas(ARENA *a) {
    if (!a) return 0;
    return a->nformas;
}

double areaForma(void *forma, TipoForma tipo){
    double area = 0.0;

    switch (tipo) {
        case CIRCULO: {
                area = areaCirculo((Circulo) forma);
            break;
        }

        case RETANGULO: {
                area = areaCirculo((Retangulo)forma);
            break;
        }

        case LINHA:
        case TEXTO:

        default:
        area = 0;
        break;

    }
    return area;

}

int sobreporRetangulos(Retangulo r1, Retangulo r2) {
    double x1 = xRetangulo(r1);
    double y1 = yRetangulo(r1);
    double largura1 = larRetangulo(r1);
    double altura1 = altRetangulo(r1);

    double x2 = xRetangulo(r2);
    double y2 = yRetangulo(r2);
    double largura2 = larRetangulo(r2);
    double altura2 = altRetangulo(r2);

    if (x1 + largura1 < x2) return 0; 
    if (x2 + largura2 < x1) return 0;
    if (y1 + largura1 < y2) return 0; 
    if (y2 + largura2 < y1) return 0;
    return 1;
}

int sobreporCirculos(Circulo c1, Circulo c2) {
    double x1 = xCirculo(c1);
    double y1 = yCirculo(c1);
    double raio1 = raioCirculo(c1);

    double x2 = xCirculo(c2);
    double y2 = yCirculo(c2);
    double raio2 = raioCirculo(c2);

   double distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

   if(distancia <= raio1 + raio2){
    return 1;

   } else {
    return 0;
   }
   
}

int sobreporCirRet(Circulo c, Retangulo r) {
    double x1 = xCirculo(c);
    double y1 = yCirculo(c);
    double raio = raioCirculo(c);

    double x2 = xRetangulo(r);
    double y2 = yRetangulo(r);
    double largura = larRetangulo(r);
    double altura = altRetangulo(r);

    double pertoX = x1;
    if(x1 < x2){
        pertoX = x2;
    } else if(x1 > x2 + largura){
        pertoX = x2 + largura;
    }

    double pertoY = x1;
    if(y1 < y2){
        pertoY = y2;
    } else if(y1 > y2 + altura){
        pertoY = y2 + altura;
    }

    double distancia = sqrt(pow(x1 - pertoX, 2) + pow(y1 - pertoY, 2));

    if(distancia <= raio){
        return 1;
    } else {
        return 0;
    }

}

int sobrepor(void *forma1, TipoForma tipo1, void *forma2, TipoForma tipo2){
    
    if (tipo1 == CIRCULO && tipo2 == CIRCULO){
        return sobreporCirculos(forma1, forma2);
    }

    if (tipo1 == RETANGULO && tipo2 == RETANGULO){
        return sobreporRetangulos(forma1, forma2);
    }

    if ((tipo1 == CIRCULO && tipo2 == RETANGULO) || (tipo1 == RETANGULO && tipo2 == CIRCULO)){
        if (tipo1 == CIRCULO){
            return sobreporCirRet(forma1, forma2);

        } else {
            return sobreporCirRet(forma2, forma1);
        }
    }

    return 0;
}

const char *PegaCorP(void *forma1, TipoForma tipo1){
    switch(tipo1) {
        case CIRCULO:   return corCirculoP(forma1);
        case RETANGULO: return corRetanguloP(forma1);
        case TEXTO:     return corTextoP(forma1);
        case LINHA:     return corLinhaP(forma1);
        default: return NULL;
    }
}

const char *PegaCorB(void *forma1, TipoForma tipo1){
    switch(tipo1) {
        case CIRCULO:   return corCirculoB(forma1);
        case RETANGULO: return corRetanguloB(forma1);
        case TEXTO:     return corTextoB(forma1);
        case LINHA:     return corLinhaB(forma1);
        default: return NULL;
    }
}

void MudaCorB(void *forma2, TipoForma tipo2, const char *novaCor){
    switch(tipo2) {
        case CIRCULO:   novaCorCirculoP(forma2, novaCor); break;
        case RETANGULO: novaCorRetanguloP(forma2, novaCor); break;
        case TEXTO:     novaCorTextoP(forma2, novaCor); break;
        case LINHA:     novaCorLinhaP(forma2, novaCor); break;
    }
}

void MudaCorP(void *forma2, TipoForma tipo2, const char *novaCor){
    switch(tipo2) {
        case CIRCULO:   novaCorCirculoB(forma2, novaCor); break;
        case RETANGULO: novaCorRetanguloB(forma2, novaCor); break;
        case TEXTO:     novaCorTextoB(forma2, novaCor); break;
        case LINHA:     novaCorLinhaB(forma2, novaCor); break;
    }
}

void *clonaForma(void *forma, TipoForma tipo) {
    switch (tipo) {
        case CIRCULO:   return clonaCirculo(forma);
        case RETANGULO: return clonaRetangulo(forma);
        case TEXTO:     return clonaTexto(forma);
        case LINHA:     return clonaLinha(forma);
        default: return NULL;
    }
}


void analisaArena(ARENA *a, PILHA *c, ESMAGADO *e){
    AFORMA *forma1 = a->topo;
    AFORMA *forma2 = a->topo->prox;


    double area1 = areaForma(forma1->forma, forma1->tipo);
    double area2 = areaForma(forma2->forma, forma2->tipo);

    int sobrepoe = sobrepor(forma1->forma, forma1->tipo, forma2->forma, forma2->tipo);

    if(sobrepoe){
        if (area1 < area2){
            pushEsmagado(e, forma1->forma, forma1->id, forma1->tipo);
            push(c, forma2->forma);

        } else if (area1 >= area2){
            const char *novaCorP = pegaCorP(forma1->forma, forma1->tipo);
            const char *novaCorB = pegaCorB(forma1->forma, forma1->tipo);
            mudaCorB(forma2->forma, forma2->tipo, novaCorP);

            push(c, forma1->forma);
            push(c, forma2->forma);

            void *clone = clonaForma(forma1->forma, forma1->tipo);

            MudaCorB(clone, forma1->tipo, novaCorP);
            MudaCorP(clone, forma1->tipo, novaCorB);

            push(c, clone);
        }

    } else {
        push(c, forma1->forma);
        push(c, forma2->forma);

    }

    popArena(a);
    popArena(a);

}