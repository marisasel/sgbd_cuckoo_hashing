#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"
#include "auxiliar.h"

void inicializa_saida(saida_t *saida) {
    register int i;

    for (i = 0; i < M; i++) { 
        saida[i].k = 0;                 // inicializa a chave com 0 em todas as posições
        strcpy(saida[i].tabela, "T0");  // inicializa tabela como 'T0' em todas as posições
        saida[i].posicao = 0;           // inicializa a posição com 0 em todas as posições
    }
    return;
}

int compara_chaves(const void *a, const void *b) {
    saida_t *saidaA = (saida_t *)a;
    saida_t *saidaB = (saida_t *)b;

    // compara as chaves 'k'
    return (saidaA->k - saidaB->k);
}

void gera_saida(hash_t *t1, hash_t *t2) {

    register int i;
    int tam = 0;
    saida_t *saida;

    saida = (saida_t *)malloc(2 * M * sizeof(saida_t));
    if (saida == NULL) {
        fprintf(stderr, "Erro ao alocar memória para saida\n");
        return;
    }
    inicializa_saida(saida);

    // percorre as tabelas e preenche a saída
    for (i = 0; i < M; i++) { 
        if (t1[i].status == 1) {
            saida[tam].k = t1[i].k;
            strcpy(saida[tam].tabela, "T1");
            saida[tam].posicao = i;
            tam++;
        }
        if (t2[i].status == 1) {
            saida[tam].k = t2[i].k;
            strcpy(saida[tam].tabela, "T2");
            saida[tam].posicao = i;
            tam++;
        }
    }
    
    // ordena a saída pela chave 'k' usando quicksort
    qsort(saida, tam, sizeof(saida_t), compara_chaves);

    for (i = 0; i < tam; i++) {
        printf("%d,%s,%d\n", saida[i].k, saida[i].tabela,saida[i].posicao);
    }

    free(saida);

    return;
}