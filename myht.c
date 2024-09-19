/*  T1 - INFO7011 - DESEMPENHO DE SGBD - UFPR
 *  Orientação: prof. Dr. Eduardo Almeida
 *  Autora: Marisa Sel Franco                   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include "hash_table.h"
#include "auxiliar.h"

int main() {
    char operacao;
    int chave;
    hash_t *t1, *t2;

    t1 = (hash_t *)malloc(M * sizeof(hash_t));
    t2 = (hash_t *)malloc(M * sizeof(hash_t));
    if (t1 == NULL || t2 == NULL) {
        fprintf(stderr, "Erro ao alocar memória para T1 ou T2.\n");
        exit(-1);
    }

    // inicializa as tabelas hash
    inicializa_tabelas(t1, t2);

    // lê as entradas e faz as operações
    while (scanf(" %c %d", &operacao, &chave) != EOF) {
        if (operacao == 'i') {
            insere_chave(chave, t1, t2);  // faz a inserção da chave
        } 
        if (operacao == 'r') {
            exclui_chave(chave, t1, t2);  // faz a exclusão da chave
        }
        if (operacao != 'i' && operacao != 'r') { 
            fprintf(stderr, "Erro: operação inválida. São aceitos os códigos 'i' para inserção e 'r' para remoção de valores. O programa será encerrado.\n");
            exit(-2);
        }
    }
    
    // gera a saída
    gera_saida(t1, t2);

    // libera a memória
    free(t1);
    free(t2);
    
    return 0;
}