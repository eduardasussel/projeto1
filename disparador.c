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
#include "gerarTxt.h"
#include "gerarSvg.h"
#include "esmagado.h" 


typedef struct disparador {
    double dx;
    double dy;
    int id;
    TipoForma tipo;
    void *forma;
    struct carregador *cesqencaixado;
    struct carregador *cdirencaixado;
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

void botoes(DISPARADOR *d, char botao, int n, CARREGADOR *cesq, CARREGADOR *cdir, FILE **txt) {
    if (!d || !cesq || !cdir) {
        printf("Disparador ou carregadores não inicializados!\n");
        return;
    }

    if (d->cesqencaixado == NULL || d->cdirencaixado == NULL) {
        printf("Carregadores não encaixados!\n");
        return;
    }

    if (*txt == NULL) {
        *txt = fopen("saida.txt", "a");
        if (!*txt) {
            printf("Erro ao abrir arquivo de saída!\n");
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        void *novaforma = NULL;
        int id;
        TipoForma tipo;

        if (botao == 'e') {
            novaforma = popCarregador(cesq, &id, &tipo);
        } else if (botao == 'd') {
            novaforma = popCarregador(cdir, &id, &tipo);
        }

        if (!novaforma) {
            printf("Carregador %c vazio!\n", botao);
            break;
        }

        if (d->forma != NULL) {
            void *atual = popDisparador(d);
            pushCarregador((botao == 'e') ? cdir : cesq, atual, d->id, d->tipo);
        }

        pushDisparador(d, novaforma, id, tipo);
    }

    if (d->forma != NULL) {
        reportaDadosTxt(d->forma, d->tipo, *txt);
    }
}


void disparar(DISPARADOR *d, ARENA *a, PILHA *chao, ESMAGADO *e, double dx, double dy, char dd, FILE **txt, FILE **svg) {
    if (!d || !d->forma || !a) return;

    if (*txt == NULL) {
        *txt = fopen("saida.txt", "a");
        if (!*txt) {
            printf("Erro ao abrir arquivo TXT!\n");
            return;
        }
    }

    if (dd == 'v' && *svg == NULL) {
        *svg = fopen("saida.svg", "a");
        if (!*svg) {
            printf("Erro ao abrir arquivo SVG!\n");
            return;
        }
    }

    void *forma = d->forma;

    switch (d->tipo) {
        case CIRCULO: {
            Circulo c = (Circulo) forma;
            novoXCirculo(c, xCirculo(c) + dx);
            novoYCirculo(c, yCirculo(c) + dy);
            reportaDadosTxt(forma, d->tipo, *txt);
            if (dd == 'v') dimensoesDisp(xCirculo(c) - dx, yCirculo(c) - dy, xCirculo(c), yCirculo(c), *svg);
            break;
        }

        case RETANGULO: {
            Retangulo r = (Retangulo) forma;
            novoXRetangulo(r, xRetangulo(r) + dx);
            novoYRetangulo(r, yRetangulo(r) + dy);
            reportaDadosTxt(forma, d->tipo, *txt);
            if (dd == 'v') dimensoesDisp(xRetangulo(r) - dx, yRetangulo(r) - dy, xRetangulo(r), yRetangulo(r), *svg);
            break;
        }

        case TEXTO: {
            Texto t = (Texto) forma;
            novoXTexto(t, xTexto(t) + dx);
            novoYTexto(t, yTexto(t) + dy);
            reportaDadosTxt(forma, d->tipo, *txt);
            if (dd == 'v') dimensoesDisp(xTexto(t) - dx, yTexto(t) - dy, xTexto(t), yTexto(t), *svg);
            break;
        }

        case LINHA: {
            Linha l = (Linha) forma;
            novoX1Linha(l, x1Linha(l) + dx);
            novoY1Linha(l, y1Linha(l) + dy);
            novoX2Linha(l, x2Linha(l) + dx);
            novoY2Linha(l, y2Linha(l) + dy);
            reportaDadosTxt(forma, d->tipo, *txt);
            if (dd == 'v') dimensoesDisp(x1Linha(l) - dx, y1Linha(l) - dy, x2Linha(l), y2Linha(l), *svg);
            break;
        }

        default:
            break;
    }

    pushArena(a, forma, d->id, d->tipo);
    
   if (nFormas(a) >= 2) {
    analisaArena(a, chao, e);
}

    d->forma = NULL;
}
