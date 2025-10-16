#include <stdio.h>
#include "disparador.h"
#include "pilha.h"

typedef struct {
    double dx;
    double dy;
    void *forma;
    CARREGADOR *cesqencaixado;
    CARREGADOR *cdirencaixado;
} DISPARADOR;


DISPARADOR *criaDispadarador(double dx, double dy) {
    DISPARADOR *d = malloc(sizeof(DISPARADOR));
    d->dx = dx;
    d->dy = dy;
    d->forma = NULL;
    d->cesqencaixado = NULL;
    d->cdirencaixado = NULL;

    return d;
}

void posicionarDisparador(DISPARADOR *d, double dx, double dy) {
    if (!d) return;
    d->dx = dx;
    d->dy = dy;
}

void encaixarCarregador(DISPARADOR *d, CARREGADOR *cesq, CARREGADOR *cdir) {
    if (!d) return;
    d->cesqencaixado = cesq;
    d->cdirencaixado = cdir;
}

void *popDisparador(DISPARADOR *d){
    if (!d || !d->forma) return NULL;
    void *formaRemovida = d->forma;
    d->forma = NULL; 
    return formaRemovida;
}

void *pushDisparador(DISPARADOR *d, void *novaforma){
    if (!d) return;
    d->forma = novaforma;
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
