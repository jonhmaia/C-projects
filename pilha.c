#include <stdio.h>
#include <stdlib.h>

// TAD - Variaveis globais
typedef struct no No;
typedef struct head Head;

// Estruturas de dados
struct no
{
    int data;
    struct no *prox;
};

struct head
{
    No *inicio;
};

// Prototipos
No *criaFila(int *data);
void insereElemento(Head *h, int *data);
int removeElemento(Head *h);
void mostraPilha(Head *h);

// Programa principal
int main()
{
    Head *h = NULL;
    int a;

    h = (Head *)malloc(sizeof(Head));
    h->inicio = NULL;
    a = 10;
    insereElemento(h, &a);
    a = 20;
    insereElemento(h, &a);
    a = 30;
    insereElemento(h, &a);
    a = 40;
    insereElemento(h, &a);
    a = 50;
    insereElemento(h, &a);
    mostraPilha(h);
    removeElemento(h);
    mostraPilha(h);
    removeElemento(h);
    mostraPilha(h);

    return (EXIT_SUCCESS);
}

No *criaPilha(int *data)
{
    No *no = NULL;

    no = (No *)malloc(sizeof(No));
    if (no)
    {
        no->data = *data;
        no->prox = NULL;
    }

    return no;
}

void insereElemento(Head *h, int *data)
{
    No *x = criaPilha(data);

    if (h == NULL || x == NULL)
        return;
    if (h->inicio == NULL)
        h->inicio = x;
    else
    {
        No *aux = h->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;

        aux->prox = x;
    }
}

int removeElemento(Head *h)
{
    No *aux = h->inicio;
    No *anterior = NULL;
    int data;

    // Se a pilha estiver vazia não tem como remover elemento
    if (h == NULL)
    {
        return 0;
    }

    // Itera pela lista até o último elemento
    while (aux->prox != NULL)
    {
        anterior = aux;
        aux = aux->prox;
    }

    // Se for removido o único elemento restante não existe anterior
    if (anterior != NULL)
    {
        anterior->prox = aux->prox;
    }

    // Valor do nó excluído
    data = aux->data;
    // Desaloca nó
    free(aux);

    return data;
}

void mostraPilha(Head *h)
{
    No *aux = h->inicio;

    // Se a pilha estiver vazia não tem como remover elemento
    if (h == NULL)
    {
        return;
    }

    // Itera ao contrário na lista
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->prox;
    }

    printf("\n");
}
