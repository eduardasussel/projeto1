#include <stdio.h>
#include <string.h>
#include "gerarTxt.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "disparador.h"

// Cria e retorna o arquivo .txt para escrita
FILE *criaArquivoTxt(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro na criação do arquivo de texto!\n");
        return NULL;
    }
    return arquivo;
}

void reportaDadosTxt(void *forma, TipoForma tipo, FILE *txt) {
    if (forma == NULL || txt == NULL) return;

    switch (tipo) {
        case CIRCULO: {
            Circulo c = (Circulo) forma;
            fprintf(txt,
                "Círculo (id=%d): x=%.2lf, y=%.2lf, r=%.2lf, corb=%s, corp=%s\n",
                iCirculo(c),
                xCirculo(c),
                yCirculo(c),
                raioCirculo(c),
                corCirculoB(c),
                corCirculoP(c)
            );
            break;
        }

        case RETANGULO: {
            Retangulo r = (Retangulo) forma;
            fprintf(txt,
                "Retângulo (id=%d): x=%.2lf, y=%.2lf, largura=%.2lf, altura=%.2lf, corb=%s, corp=%s\n",
                iRetangulo(r),
                xRetangulo(r),
                yRetangulo(r),
                larRetangulo(r),
                altRetangulo(r),
                corRetanguloB(r),
                corRetanguloP(r)
            );
            break;
        }

        case LINHA: {
            Linha l = (Linha) forma;
            fprintf(txt,
                "Linha (id=%d): (x1=%.2lf, y1=%.2lf) → (x2=%.2lf, y2=%.2lf), cor=%s\n",
                iLinha(l),
                x1Linha(l),
                y1Linha(l),
                x2Linha(l),
                y2Linha(l),
                corLinha(l)
            );
            break;
        }

        case TEXTO: {
            Texto t = (Texto) forma;
            fprintf(txt,
                "Texto (id=%d): x=%.2lf, y=%.2lf, corb=%s, corp=%s, alinhamento=%s, conteudo=\"%s\"\n",
                iTexto(t),
                xTexto(t),
                yTexto(t),
                corTextoB(t),
                corTextoP(t),
                aTexto(t),
                txtoTexto(t)
            );
            break;
        }

        default:
            break;
    }
}

void fechaArquivoTxt(FILE *txt) {
    if (txt != NULL) {
        fclose(txt);
    }
}
