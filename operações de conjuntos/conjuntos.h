#include <stdio.h>
#include <limits.h> // Constantes LONG_MIN e LONG_MAX
#include <stdbool.h> // Tipo primitivo (bool)
#include <stdlib.h> // calloc() e realloc()

// Crio o objeto Conjunto com os elementos (vetor alocado dinamicamente) e a cardinalidade atual 
typedef struct conjunto {
	long int* elementos;
	int cardinalidade;
} Conjunto;

Conjunto* cria_conjunto();
void libera_conjunto(Conjunto** vet, int* numConj, int pos);
bool verifica_se_vazio(Conjunto* conj);
bool procura_elemento(Conjunto* conj, long int x);
bool insere_elemento(Conjunto* conj, long int x);
bool retira_elemento(Conjunto* conj, long int x);
int cardinalidade_conjunto(Conjunto* conj);
void ordena_conjunto(Conjunto* conj, int ordem);
void copia_conjunto(Conjunto* conj1, Conjunto* conj2);
void max(Conjunto *conj1);
void min(Conjunto *conj1);
void N_maior(Conjunto *conj, int pivo);
void N_menor(Conjunto *conj, int pivo);
void ordena(Conjunto *conj);
void igualdade(Conjunto *conj1, Conjunto *conj2);
int pertence(Conjunto *conj, int elemento);
void print_conjunto(Conjunto *conj);
Conjunto* interseccao(Conjunto *c1, Conjunto *c2);
Conjunto* complemento(Conjunto *c1, Conjunto *c2);
bool eh_subconjunto(Conjunto *c1, Conjunto *c2);
Conjunto* uniao(Conjunto *c1, Conjunto *c2);