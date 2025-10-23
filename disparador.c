#include <stdio.h>
#include <stdlib.h>
#include "disparador.h"
#include "carregador.h"
#include "pilha.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "gerarTxt.h"

typedef enum { CIRCULO, RETANGULO, TEXTO, LINHA } TipoForma;

typedef struct {
    double dx;
    double dy;
    int id;  
    TipoForma tipo;
    void *forma;
    CARREGADOR *cesqencaixado;
    CARREGADOR *cdirencaixado;
} DISPARADOR;




DISPARADOR *criaDisparador(double dx, double dy) {
    DISPARADOR *d = malloc(sizeof(DISPARADOR));
    if (!d) {
        printf("Erro ao alocar disparador!\n");
        exit(1);
    }
    d->dx = dx;
    d->dy = dy;
    d->forma = NULL;
    d->cesqencaixado = NULL;
    d->cdirencaixado = NULL;
    return d;
}

void posicionarDis(DISPARADOR *d, double dx, double dy) {
    if (!d) return;
    d->dx = dx;
    d->dy = dy;
}

void encaixarCarregador(DISPARADOR *d, CARREGADOR *cesq, CARREGADOR *cdir) {
    if (!d) return;
    d->cesqencaixado = cesq;
    d->cdirencaixado = cdir;
}

void *pushDisparador(DISPARADOR *d, void *novaforma, int id, TipoForma tipo) {
    if (!d) return NULL;
    d->forma = novaforma;
    d->id = id;
    d->tipo = tipo;
    return novaforma;
}

void *popDisparador(DISPARADOR *d) {
    if (!d || !d->forma) return NULL;
    void *formaRemovida = d->forma;
    d->forma = NULL;
    return formaRemovida;
}

void botoes(DISPARADOR *d, char botao, int n, CARREGADOR *cesq, CARREGADOR *cdir, FILE *txt) {
    if (!d || !cesq || !cdir) {
        printf("Disparador ou carregadores não inicializados!\n");
        return;
    }

    if (d->cesqencaixado == NULL || d->cdirencaixado == NULL) {
        printf("Carregadores não encaixados!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        void *novaforma = NULL;
        int id;
        TipoForma tipo;

        if (botao == 'e') {
            novaforma = popCarregador(cesq, &id, &tipo);
        } 
        else if (botao == 'd') {
            novaforma = popCarregador(cdir, &id, &tipo);
        }

        if (!novaforma) {
            printf("Carregador %c vazio!\n", botao);
            break;
        }

        if (d->forma != NULL) {
            void *atualforma = popDisparador(d);
            pushCarregador((botao == 'e') ? cdir : cesq, atualforma, d->id, d->tipo);
        }

        pushDisparador(d, novaforma, id, tipo);
    }

    if (d->forma != NULL) {
        if (!txt) {
            txt = fopen("saida.txt", "a");
            if (!txt) {
                printf("Erro ao abrir arquivo de saída!\n");
                return;
            }
        }

        reportaDados(d->forma, d->tipo, txt);
    }
}


void disparar(DISPARADOR *d, ARENA *a, PILHA *chao, double dx, double dy, FILE *txt) {
    if (!d || !d->forma || !a) return;

    void *forma = d->forma; 

    switch (d->tipo) {
        case CIRCULO: {
            Circulo c = (Circulo) forma;
            double x = xCirculo(c);
            double y = yCirculo(c);
            setXCirculo(c, x + dx);
            setYCirculo(c, y + dy);

    reportaDados(forma, d->tipo, txt);
            break;
        }

        case RETANGULO: {
            Retangulo r = (Retangulo) forma;
            double x = xRetangulo(r);
            double y = yRetangulo(r);
            setXRetangulo(r, x + dx);
            setYRetangulo(r, y + dy);
           reportaDados(forma, d->tipo, txt);
        }

        case TEXTO: {
            Texto t = (Texto) forma;
            double x = xTexto(t);
            double y = yTexto(t);
            setXTexto(t, x + dx);
            setYTexto(t, y + dy);
            reportaDados(forma, d->tipo, txt);
        }

        case LINHA: {
            Linha l = (Linha) forma;
            double x1 = x1Linha(l);
            double y1 = y1Linha(l);
            double x2 = x2Linha(l);
            double y2 = y2Linha(l);
            setX1Linha(l, x1 + dx);
            setY1Linha(l, y1 + dy);
            setX2Linha(l, x2 + dx);
            setY2Linha(l, y2 + dy);
            reportaDados(forma, d->tipo, txt);
        }
        
        pushArena(a, forma, d->id, d->tipo);

        if (nFormas(a) == 2) {
            analisaArena(a, chao);
        }

        default:
            break;
    }

    pushArena(a, forma, d->id, d->tipo);

    d->forma = NULL;
}
