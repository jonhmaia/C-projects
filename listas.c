#include <stdlib.h>
#include <stdio.h>

typedef struct no {
	int dado;
	int chave;
	struct no* prox;
}No;

typedef struct head {
	No* inicio;
	int tamanho;
} Head;

Head* criarListaVazia();
Head* criarListaChave(int valor);
No* criaNo(int valor);
void insereComecoLista(Head* lista, int valor);
void removeComecoLista(Head* lista);
void insereFinalLista(Head* lista, int valor);
void removeFinalLista(Head* lista);
void liberaLista(Head* lista);
Head* contatenaListas(Head* lista1, Head* lista2);
int tamanhoLista(Head *lista);

Head* criarListaVazia() {
	Head* lista;

	lista = (Head*) malloc(sizeof(Head));
	if (lista == NULL) exit(1);

	lista->inicio = NULL;
	lista->tamanho = 0;

	return lista;
}

Head* criarListaChave(int valor) {
	Head *lista;

	lista = (Head*) malloc(sizeof(Head));
	if (lista == NULL) exit(1);

	lista->inicio = criaNo(valor);
	lista->tamanho = 1;

	return lista;
}

No* criaNo(int valor) {
	No* no;
	
	no = (No*) malloc(sizeof(No));
	if (no == NULL) exit(1);

	no->dado = valor;
	no->prox = NULL;

	return no;
}

void insereComecoLista(Head* lista, int valor) {
	No* no = criaNo(valor);
	
	if (lista->tamanho == 0) {
		lista->inicio = no;
		lista->tamanho++;
	} else {
		No* aux = lista->inicio;
		no->prox = aux;
		lista->inicio = no;
		lista->tamanho++;        
	}

}

void removeComecoLista(Head* lista) {
	if (lista->tamanho > 0) {
		No *aux = lista->inicio;
		lista->inicio = lista->inicio->prox;
		lista->tamanho--;
		free(aux);
	} else {
		exit(1);
	}
}

void insereFinalLista(Head* lista, int valor) {
	No* no = criaNo(valor);

	if (lista->tamanho == 0) {
		lista->inicio = no;
		lista->tamanho++;
	} else {
		No* aux = lista->inicio;

		while (aux->prox != NULL) {
			aux = aux->prox;
		}

		aux->prox = no;
		lista->tamanho++;
	}
}

void removeFinalLista(Head* lista) {
	if (lista->tamanho <= 0) exit(1);
	No* aux = lista->inicio;
	No* anterior;

	while (aux->prox != NULL) {
		anterior = aux;
		aux = aux->prox;
	}

	anterior->prox = NULL;
	lista->tamanho--;
	free(aux);
}

void printLista(Head* lista) {
	if (lista->tamanho <= 0) exit(1);
	No* aux = lista->inicio;

	while (aux->prox != NULL) { 
		printf("%d, ", aux->dado);
		aux = aux->prox;
	}
	printf("%d\n", aux->dado);
}

void liberaLista(Head* lista) {
	No* aux = lista->inicio;
	No* anterior;

	while (aux->prox != NULL) {
		anterior = aux;
		aux = aux->prox;
		free(anterior);
	}

	free(lista);
}

Head* contatenaListas(Head* lista1, Head* lista2) {
	Head* lista3 = criarListaVazia();

	if (lista1->tamanho == 0 && lista2->tamanho == 0) {
		return lista3;
	} 
	if (lista1->tamanho == 0) {
		lista3 = lista2;
		return lista3;
	}
	if (lista2->tamanho == 0) {
		lista3 = lista1;
		return lista3;
	}
	
	No* aux; 
	
	aux = lista1->inicio; 
	while(aux->prox != NULL){
		insereFinalLista(lista3, aux->dado);
        aux = aux->prox;
	}
	insereFinalLista(lista3, aux->dado);

	aux = lista2->inicio;
	while(aux->prox != NULL){
		insereFinalLista(lista3, aux->dado);
        aux = aux->prox;
	}
	insereFinalLista(lista3, aux->dado);
	
	return lista3;
}

int tamanhoLista(Head *lista) {
	return lista->tamanho;
}

int main() {
	Head* lista1 = criarListaVazia();

	printf("\n\033[1;32mInserção no começo!\n");
	printf("--------------------\033[m\n");

	insereComecoLista(lista1, 1); // 1
	printLista(lista1);
	insereComecoLista(lista1, 2); // 2, 1
	printLista(lista1);
	insereComecoLista(lista1, 3); // 3, 2, 1
	printLista(lista1);
	insereComecoLista(lista1, 4); // 4, 3, 2, 1
	printLista(lista1);
	printf("Tamanho lista1: %d\n", tamanhoLista(lista1));

	printf("\n\033[1;32mInserção no final!\n");
	printf("--------------------\033[m\n");
	
	insereFinalLista(lista1, 5); // 4, 3, 2, 1, 5
	printLista(lista1);
	insereFinalLista(lista1, 6); // 4, 3, 2, 1, 5, 6
	printLista(lista1);
	insereFinalLista(lista1, 7); // 4, 3, 2, 1, 5, 6, 7
	printLista(lista1);
	insereFinalLista(lista1, 8); // 4, 3, 2, 1, 5, 6, 7, 8
	printLista(lista1);
	printf("Tamanho lista1: %d\n", tamanhoLista(lista1));

	printf("\n\033[1;31mRemoção no começo!\n");
	printf("--------------------\033[m\n");

	removeComecoLista(lista1); // 3, 2, 1, 5, 6, 7, 8
	printLista(lista1);
	removeComecoLista(lista1); // 2, 1, 5, 6, 7, 8
	printLista(lista1);
	removeComecoLista(lista1); // 1, 5, 6, 7, 8
	printLista(lista1);
	printf("Tamanho lista1: %d\n", tamanhoLista(lista1));

	printf("\n\033[1;31mRemoção no final!\n");
	printf("--------------------\033[m\n");
	
	removeFinalLista(lista1); // 1, 5, 6, 7
	printLista(lista1);
	removeFinalLista(lista1); // 1, 5, 6
	printLista(lista1);
	printf("Tamanho lista1: %d\n", tamanhoLista(lista1));

	printf("\n--------------------\n");
	printf("Lista 2\n");
	printf("--------------------\n");

	int valor;
	printf("Digite o primeiro valor da lista2 (inteiro): ");
	scanf("%d", &valor);
	
	Head *lista2 = criarListaChave(valor);
	
	printf("\n\033[1;34mConcatenar!\n");
	printf("--------------------\033[m\n");

	Head *lista3 = contatenaListas(lista1, lista2);
	printLista(lista3); // 1, 5, 6, valor
	printf("Tamanho lista3: %d\n", tamanhoLista(lista3));

	liberaLista(lista1);
	liberaLista(lista2);
	liberaLista(lista3);
	
	return 0;
}