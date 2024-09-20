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

int busca_chave(int k, hash_t *t1, hash_t *t2) {

    if (t1[h1(k)].status == 0)  // se a posição da chave k calculada por h1(k) estiver vazia
        return -1;              // indica que a chave não foi encontrada devido ao tratamento de colisão na inclusão e exclusão

    if (t1[h1(k)].k == k)       // se a chave está na T1
        return h1(k);           // retorna a posição da chave na T1
    
    if (t2[h2(k)].k == k)       // se a chave está na T2
        return h2(k);           // retorna a posição da chave na T2

    return -1;
}

void insere_chave(int k, hash_t *t1, hash_t *t2) {
    int posicao;

    posicao = busca_chave(k, t1, t2);   // busca a chave nas tabelas

    if (posicao == -1) {                // caso não seja uma chave duplicada/já inserida 
        if (t1[h1(k)].status != 1) {    // caso a posição em T1 esteja vazia
            t1[h1(k)].k = k;            // nova chave é inserida na T1
            t1[h1(k)].status = 1;       // status da posição é atualizado
        }
        else {                          // se houver colisão em T1
            int k2 = t1[h1(k)].k;       // variável auxiliar recebe o valor de chave de T1 que será movido para T2
            t2[h2(k2)].k = k2;          // chave que estava em T1 é movida para T2
            t2[h2(k2)].status = 1;      // status da posição é atualizado
            t1[h1(k)].k = k;            // nova chave é inserida na T1
        }    
    } 
    return; 
}

void exclui_chave(int k, hash_t *t1, hash_t *t2) {
    int posicao;

    posicao = busca_chave(k, t1, t2);   // busca a chave nas tabelas

    if (posicao != -1) {                // se a chave foi encontrada
        if (t1[h1(k)].k == k) {         // se a chave estiver na T1
            t1[h1(k)].k = 0;            // chave é excluída da T1
            t1[h1(k)].status = -1;      // status da posição é atualizado para indicar a exclusão
        } 
        else {                          // se a chave estiver na T2
            t2[h2(k)].k = 0;            // chave é excluída da T2
            t2[h2(k)].status = -1;      // status da posição é atualizado para indicar a exclusão
        }
    }
    return;
}