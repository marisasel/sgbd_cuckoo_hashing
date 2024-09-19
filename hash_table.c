#include <stdio.h>
#include <math.h> 
#include "hash_table.h"

void inicializa_tabelas(hash_t *t1, hash_t *t2) {
    register int i;

    for (i = 0; i < M; i++) { 
        t1[i].k = t2[i].k = 0;              // inicializa as tabelas com 0 em todas as posições
        t1[i].status = t2[i].status = 0;    // inicializa os status com nulo (0), indicando que as posições nunca foram ocupadas
    }
    return;
}

int h1(int k) {
    int posicao;

    posicao = k % M;    
    return posicao;
}

int h2(int k) {
    int posicao;

    posicao = floor(M * (k * 0.9 - floor(k * 0.9)));
    return posicao;
}

void insere_chave(int k, hash_t *t1, hash_t *t2) {

    if ((t1[h1(k)].status != 1) && (t1[h1(k)].k != k)) {  // inclusão na T1 de chave não duplicada em espaço vazio
        t1[h1(k)].k = k;            // nova chave é inserida na T1
        t1[h1(k)].status = 1;       // status da posição é atualizado
    }
    else {                          // se houver colisão em T1
        int k2 = t1[h1(k)].k;       // variável auxiliar recebe o valor de chave de T1 que será movido para T2
        t2[h2(k2)].k = k2;          // chave que estava em T1 é movida para T2
        t2[h2(k2)].status = 1;      // status da posição é atualizado
        t1[h1(k)].k = k;            // nova chave é inserida na T1
    }
    return;
}

void exclui_chave(int k, hash_t *t1, hash_t *t2) {

    if ((t2[h2(k)].status == 1) && (t2[h2(k)].k == k)) {  // se a chave estiver na T2
        t2[h2(k)].k = 0;            // chave é excluída da T2
        t2[h2(k)].status = -1;      // status da posição é atualizado
    }
    if ((t1[h1(k)].status == 1) && (t1[h1(k)].k == k)) {  // se a chave estiver na T1
        t1[h1(k)].k = 0;            // chave é excluída da T1
        t1[h1(k)].status = -1;      // status da posição é atualizado
    }
    return;
}

int busca_chave(int k, hash_t *t1, hash_t *t2) {

    if ((t1[h1(k)].k == k) && (t1[h1(k)].status == 1)) {  // se a chave está na T1
        printf("Chave %d encontrada na T1, na posição %d.\n", k, h1(k));
        return h1(k);   // retorna a posição da chave na T1
    }
    if ((t2[h2(k)].k != k) && (t2[h2(k)].status == 1)) {  // se a chave está na T2
        printf("Chave %d encontrada na T2, na posição %d.\n", k, h2(k));
        return h2(k);   // retorna a posição da chave na T2
    }
    printf("Chave inexistente.\n");
    return -1;  // indica que a chave não foi encontrada
}