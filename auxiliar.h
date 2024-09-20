#ifndef __AUXILIAR__
#define __AUXILIAR__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"

#define M 11

typedef struct saida_t {
    int k;          // armazena o valor da chave
    char tabela[3]; // armezena a tabela: "T1" ou "T2"
    int posicao;    // armazena a posição na qual o valor está armazenado na tabela
} saida_t;

void inicializa_saida(saida_t *saida);
int compara_chaves(const void *a, const void *b);
void gera_saida(hash_t *t1, hash_t *t2);

#endif