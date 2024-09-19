#ifndef __HASHTABLE__
#define __HASHTABLE__

#include <stdio.h>
#include <stdbool.h>  
#include <math.h> 

#define M 11

typedef struct hash_t {
    int k;      // armazena o valor da chave
    int status; // -1 significa chave excluída da posição, 0 significa nulo (posição nunca ocupada) e 1 significa posição ocupada
} hash_t;

void inicializa_tabelas(hash_t *t1, hash_t *t2);
int h1(int k);
int h2(int k);
void insere_chave(int k, hash_t *t1, hash_t *t2);
void exclui_chave(int k, hash_t *t1, hash_t *t2); 
int busca_chave(int k, hash_t *t1, hash_t *t2);
void gera_saida(hash_t *t1, hash_t *t2);

#endif