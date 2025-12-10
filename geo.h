#ifndef GEO_H
#define GEO_H

#include "pilha.h"

void inicializaGeo();

void registrarFormaGeo(void *forma, int id, TipoForma tipo);

void* buscaFormaGeo(int id, TipoForma *tipo);

#endif
