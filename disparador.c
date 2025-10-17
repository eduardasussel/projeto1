#include <stdio.h>
#include "disparador.h"
#include "pilha.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"


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

void *pushDisparador(DISPARADOR *d, void *novaforma, TipoForma tipo){
    if (!d) return;
    d->forma = novaforma;
    d->tipo = tipo;
}

void *popDisparador(DISPARADOR *d){
    if (!d || !d->forma) return NULL;
    void *formaRemovida = d->forma;
    d->forma = NULL;
    return formaRemovida;
}

void botoes(DISPARADOR *d, char botao, int n, CARREGADOR *cesq, CARREGADOR *cdir){
    if (d->cesqencaixado == NULL || d->cdirencaixado == NULL) {
        printf("Carregadores não encaixados!\n");
        return;
    }

    for (int i = 0; i < n; i++) {

        if (botao == 'e') {
            void *novaforma = popCarregador(cesq);

            if (novaforma == NULL) {
                printf("Carregador esquerdo vazio!\n");
                break;
            }

            if (d->forma != NULL) {
                void *atualforma = popDisparador(d);
                pushCarregador(cdir, atualforma);
            }

            pushDisparador(d, novaforma);

        } else if (botao == 'd') {
            void *novaforma = popCarregador(cdir);

            if (novaforma == NULL) {
                printf("Carregador direito vazio!\n");
                break;
            }

            if (d->forma != NULL) {
                void *atualforma = popDisparador(d);
                pushCarregador(cesq, atualforma);
            }

            pushDisparador(d, novaforma);

        } else {
            printf("Botão inválido! Use 'e' ou 'd'.\n");
            return;
        }
    }
}


void disparar(DISPARADOR *d, double dx, double dy) {
    if (!d || !d->forma) {
        printf("Nenhuma forma no disparador para disparar!\n");
        return;
    }

    switch (d->tipo) {
        case CIRCULO: {
            Circulo c = d->forma;
            moveCirculo(c, dx, dy);
            break;
        }
        case RETANGULO: {
            Retangulo r = d->forma;
            moveRetangulo(r, dx, dy);
            break;
        }
        case TEXTO: {
            Texto t = d->forma;
            moveTexto(t, dx, dy);
            break;
        }
        case LINHA: {
            Linha l = d->forma;
            moveLinha(l, dx, dy);
            break;
        }
        default:
            break;
    }

    popDisparador(d);
}

