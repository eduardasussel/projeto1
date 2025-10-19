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


void disparar(DISPARADOR *d, ARENA *a, double dx, double dy, FILE *txt) {
    if (!d || !d->forma || !a) return;

    void *forma = d->forma; 

    switch (d->tipo) {
        case CIRCULO: {
            Circulo c = (Circulo) forma;
            double x = getXCirculo(c);
            double y = getYCirculo(c);
            setXCirculo(c, x + dx);
            setYCirculo(c, y + dy);
            if (txt)
                fprintf(txt, "CIRCULO %d -> Nova pos: (%.2lf, %.2lf)\n", d->id, x + dx, y + dy);
            break;
        }

        case RETANGULO: {
            Retangulo r = (Retangulo) forma;
            double x = getXRetangulo(r);
            double y = getYRetangulo(r);
            setXRetangulo(r, x + dx);
            setYRetangulo(r, y + dy);
            if (txt)
                fprintf(txt, "RETANGULO %d -> Nova pos: (%.2lf, %.2lf)\n", d->id, x + dx, y + dy);
            break;
        }

        case TEXTO: {
            Texto t = (Texto) forma;
            double x = getXTexto(t);
            double y = getYTexto(t);
            setXTexto(t, x + dx);
            setYTexto(t, y + dy);
            if (txt)
                fprintf(txt, "TEXTO %d -> Nova pos: (%.2lf, %.2lf)\n", d->id, x + dx, y + dy);
            break;
        }

        case LINHA: {
            Linha l = (Linha) forma;
            double x1 = getX1Linha(l);
            double y1 = getY1Linha(l);
            double x2 = getX2Linha(l);
            double y2 = getY2Linha(l);
            setX1Linha(l, x1 + dx);
            setY1Linha(l, y1 + dy);
            setX2Linha(l, x2 + dx);
            setY2Linha(l, y2 + dy);
            if (txt)
                fprintf(txt, "LINHA %d -> Nova pos: (%.2lf, %.2lf)-(%.2lf, %.2lf)\n", 
                        d->id, x1 + dx, y1 + dy, x2 + dx, y2 + dy);
            break;
        }
        
        pushArena(a, forma, id, tipo);

        if (nFormas(a) == 2) {
            analisaArena(a, chao);
        }

        default:
            break;
    }

    pushArena(a, forma, d->id, d->tipo);

    d->forma = NULL;
}
