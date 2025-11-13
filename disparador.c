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
#include "gerarSvg.h"

typedef struct disparador {
    double dx;
    double dy;
    int id;
    TipoForma tipo;
    void *forma;
    struct carregador *cesqencaixado;
    struct carregador *cdirencaixado;
} disparador_s;

typedef struct forma {
    void *forma;
    int id;
    TipoForma tipo;
    struct forma *prox;
} FORMA_STRUCT;

typedef struct carregador {
    FORMA_STRUCT *topo;
} CARREGADOR_STRUCT;

typedef disparador_s *DisparadorImpl;

DISPARADOR criaDisparador(double dx, double dy) {
    DisparadorImpl d = malloc(sizeof(*d));
    if (!d) {
        printf("Erro ao alocar disparador!\n");
        exit(1);
    }
    d->dx = dx;
    d->dy = dy;
    d->id = -1;
    d->tipo = -1;
    d->forma = NULL;
    d->cesqencaixado = NULL;
    d->cdirencaixado = NULL;
    return (DISPARADOR)d;
}

void posicionarDis(DISPARADOR d, double dx, double dy) {
    if (!d) return;
    DisparadorImpl s = (DisparadorImpl)d;
    s->dx = dx;
    s->dy = dy;
}

void encaixarCarregador(DISPARADOR d, CARREGADOR cesq, CARREGADOR cdir) {
    if (!d) return;
    DisparadorImpl s = (DisparadorImpl)d;
    s->cesqencaixado = (struct carregador*)cesq;
    s->cdirencaixado = (struct carregador*)cdir;
}

void *pushDisparador(DISPARADOR d, void *novaforma, int id, TipoForma tipo) {
    if (!d) return NULL;
    DisparadorImpl s = (DisparadorImpl)d;
    s->forma = novaforma;
    s->id = id;
    s->tipo = tipo;
    return novaforma;
}

void *popDisparador(DISPARADOR d) {
    if (!d) return NULL;
    DisparadorImpl s = (DisparadorImpl)d;
    if (!s->forma) return NULL;
    void *ret = s->forma;
    s->forma = NULL;
    return ret;
}

void botoes(DISPARADOR d, char botao, int n, FILE **txt) {
    if (!d) {
        printf("Disparador não inicializado!\n");
        return;
    }

    DisparadorImpl s = (DisparadorImpl)d;
    CARREGADOR cesq = (CARREGADOR)s->cesqencaixado;
    CARREGADOR cdir = (CARREGADOR)s->cdirencaixado;

    if (!cesq || !cdir) {
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

    printf("[DEBUG] botoes(): botao=%c n=%d cesq=%p cdir=%p\n", botao, n, cesq, cdir);
    printf("[DEBUG] botoes(): cesq->topo=%p cdir->topo=%p\n",
       cesq ? ((CARREGADOR_STRUCT*)cesq)->topo : NULL,
       cdir ? ((CARREGADOR_STRUCT*)cdir)->topo : NULL);

    for (int i = 0; i < n; i++) {
        void *novaforma = NULL;
        int id;
        TipoForma tipo;

        if (botao == 'e') {
            novaforma = popCarregador(cesq, &id, &tipo);
        } else {
            novaforma = popCarregador(cdir, &id, &tipo);
        }

        if (!novaforma) {
            printf("Carregador %c vazio!\n", botao);
            break;
        }

        if (s->forma != NULL) {
            void *atual = popDisparador(d);
            pushCarregador((botao == 'e') ? cdir : cesq, atual, s->id, s->tipo);
        }

        pushDisparador(d, novaforma, id, tipo);
    }

    if (s->forma != NULL) {
        reportaDadosTxt(s->forma, s->tipo, *txt);
    }
}


void disparar(DISPARADOR d, ARENA *a, PILHA *chao, ESMAGADO *e, double dx, double dy, char dd, FILE **txt, FILE **svg) {
    if (!d) return;
    DisparadorImpl s = (DisparadorImpl)d;
    if (!s->forma || !a) return;

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

    void *forma = s->forma;

    switch (s->tipo) {
        case CIRCULO: {
            Circulo c = (Circulo) forma;
            novoXCirculo(c, xCirculo(c) + dx);
            novoYCirculo(c, yCirculo(c) + dy);
            reportaDadosTxt(forma, s->tipo, *txt);
            if (dd == 'v') dimensoesDisp(xCirculo(c) - dx, yCirculo(c) - dy, xCirculo(c), yCirculo(c), *svg);
            break;
        }
        case RETANGULO: {
            Retangulo r = (Retangulo) forma;
            novoXRetangulo(r, xRetangulo(r) + dx);
            novoYRetangulo(r, yRetangulo(r) + dy);
            reportaDadosTxt(forma, s->tipo, *txt);
            if (dd == 'v') dimensoesDisp(xRetangulo(r) - dx, yRetangulo(r) - dy, xRetangulo(r), yRetangulo(r), *svg);
            break;
        }
        case TEXTO: {
            Texto t = (Texto) forma;
            novoXTexto(t, xTexto(t) + dx);
            novoYTexto(t, yTexto(t) + dy);
            reportaDadosTxt(forma, s->tipo, *txt);
            if (dd == 'v') dimensoesDisp(xTexto(t) - dx, yTexto(t) - dy, xTexto(t), yTexto(t), *svg);
            break;
        }
        case LINHA: {
            Linha l = (Linha) forma;
            novoX1Linha(l, x1Linha(l) + dx);
            novoY1Linha(l, y1Linha(l) + dy);
            novoX2Linha(l, x2Linha(l) + dx);
            novoY2Linha(l, y2Linha(l) + dy);
            reportaDadosTxt(forma, s->tipo, *txt);
            if (dd == 'v') dimensoesDisp(x1Linha(l) - dx, y1Linha(l) - dy, x2Linha(l), y2Linha(l), *svg);
            break;
        }
        default:
            break;
    }

    pushArena(a, forma, s->id, s->tipo);
    if (nFormas(a) >= 2) {
        analisaArena(a, chao, e);
    }

    s->forma = NULL;
}
