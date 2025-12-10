#include "geo.h"
#include "pilha.h"

static PILHA *geoStorage = NULL;

void inicializaGeo() {
    geoStorage = criaPilha();
}

void registrarFormaGeo(void *forma, int id, TipoForma tipo) {
    push(geoStorage, forma, tipo);
}

void* buscaFormaGeo(int id, TipoForma *tipo) {
    NO *p = geoStorage->topo;

    while (p != NULL) {
        if (p->id == id) {
            *tipo = p->tipo;
            return p->forma;
        }
        p = p->prox;
    }

    return NULL;
}
