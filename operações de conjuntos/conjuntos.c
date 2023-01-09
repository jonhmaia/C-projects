#include <stdio.h>
#include <limits.h>  // Constantes LONG_MIN e LONG_MAX
#include <stdbool.h> // Tipo primitivo (bool)
#include <stdlib.h>  // calloc() e realloc()
#include "conjuntos.h"

/// @brief Aloca um conjunto e o vetor de elementos dele
/// @return O ponteiro do conjunto criado com cardinalidade 0
Conjunto *cria_conjunto()
{
    Conjunto *p = (Conjunto *)calloc(1, sizeof(Conjunto));

    if (p == NULL)
    {
        printf("\033[1;31mErro: Nao foi possivel alocar o conjunto na memoria\033[m\n");
        exit(1);
    }

    p->elementos = (long int *)calloc(1, sizeof(long int));

    if (p->elementos == NULL)
    {
        printf("\033[1;31mErro: Nao foi possivel alocar o vetor de elementos na memoria\033[m\n");
        exit(1);
    }

    // Define o conjunto inicialmete com cardinalidade 0
    p->cardinalidade = 0;

    printf("\033[1;32mConjunto criado com sucesso\033[m\n");

    return p;
}

/// @brief Desaloca um conjunto e seus elementos
/// @param vet Ponteiro para a lista de conjuntos ja criados
/// @param numConj Ponteiro para a quantidade de conjuntos criados
/// @param pos Posicao do conjunto a ser desalocado
void libera_conjunto(Conjunto **vet, int *numConj, int pos)
{
    free(vet[pos]->elementos);
    vet[pos]->elementos = (long int *)calloc(1, sizeof(long int));
    if (vet[pos]->elementos == NULL)
    {
        printf("\033[1;31mErro: Nao foi possivel remover o vetor de elementos na memoria\033[m\n");
        exit(1);
    }
    vet[pos]->cardinalidade = 0;
    printf("\033[1;32mConjunto apagado com sucesso\033[m\n");
}

/// @brief Verifica se um conjunto é vazio
/// @param conj Ponteiro para um conjunto
/// @return true: se o conjunto é vazio; false: se Nao é vazio
bool verifica_se_vazio(Conjunto *conj)
{
    if (conj->cardinalidade == 0)
        return true;
    else
        return false;
}

/// @brief Verifica se um elemento 'x' esta inserido em um dado conjunto
/// @param conj Ponteiro para um conjunto
/// @param x Número (long int) qualquer
/// @return true: se 'x' esta no conjunto; false: se 'x' Nao esta no conjunto
bool procura_elemento(Conjunto *conj, long int x)
{
    for (int i = 0; i < conj->cardinalidade; i++)
    {
        if (conj->elementos[i] == x)
            return true;
    }

    return false;
}

/// @brief Tenta inserir um elemento 'x' em um dado conjunto
/// @param conj Ponteiro para um conjunto
/// @param x Número (long int) qualquer
/// @return true: se conseguir inserir o novo elemento; false: se nao conseguir inserir
bool insere_elemento(Conjunto *conj, long int x)
{
    // Verifica se o elemento 'x' é um (long int) valido
    if (x > LONG_MAX || x < LONG_MIN)
    {
        printf("\033[1;33mO elemento a ser inserido Nao é um (long int) valido\033[m\n");
        return false;
    }

    // Verifica se o elemento 'x' ja esta inserido no conjunto
    if (procura_elemento(conj, x))
    {
        printf("\033[1;33mO elemento %ld ja esta no conjunto\033[m\n", x);
        return false;
    }

    // Verifica se o conjunto atingiu a cardinalidade maxima (10)
    if (conj->cardinalidade >= 10)
    {
        printf("\033[1;33mElemento Nao pode ser inserido, pois o conjunto atingiu a cardinalidade maxima\033[m\n");
        return false;
    }

    // Se todos os testes forem validos a cardinalidade é incrementada ...
    conj->cardinalidade++;
    // ... e o vetor de elementos é realocado com um elemento a mais
    conj->elementos = (long int *)realloc(conj->elementos, conj->cardinalidade * sizeof(long int));

    if (conj->elementos == NULL)
    {
        printf("\033[1;31mErro: Nao foi possivel alocar espaco na memoria para o novo elemento\033[m\n");
        exit(1);
    }

    // Elemento 'x' é atribuido à última posicao do vetor de elementos
    conj->elementos[conj->cardinalidade - 1] = x;

    printf("\033[1;32mElemento inserido com sucesso no conjunto\033[m\n");

    return true;
}

/// @brief Troca a posicao de dois elementos em um vetor
/// @param vet Vetor qualquer
/// @param i Posicao do 1º elemento
/// @param j Posicao do 2º elemento
void swap(long int *vet, int i, int j)
{
    long int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

/// @brief Tenta retirar um elemento 'x' de um dado conjunto
/// @param conj Ponteiro para um conjunto
/// @param x Número (long int) qualquer
/// @return true: se conseguir retirar o elemento; false: se nao conseguir retirar
bool retira_elemento(Conjunto *conj, long int x)
{
    // Itera pelo conjunto buscando o elemento 'x'
    for (int i = 0; i < conj->cardinalidade; i++)
    {
        // Se encontrar 'x' ...
        if (conj->elementos[i] == x)
        {
            for (int k = i; k < conj->cardinalidade - 1; k++)
            {
                // ... troca os elementos do conjunto de forma a deixar ...
                // ... o elemento 'x' ao final (para ser excluido com realloc)
                swap(conj->elementos, k, k + 1);
            }

            // Cardinalidade é decrementada ...
            conj->cardinalidade--;
            // ... e o vetor de elementos é realocado com um elemento a menos
            conj->elementos = (long int *)realloc(conj->elementos, conj->cardinalidade * sizeof(long int));

            if (conj->elementos == NULL)
            {
                printf("\033[1;31mErro: Nao foi possivel desalocar espaco na memoria\033[m\n");
                exit(1);
            }

            printf("\033[1;32mElemento retirado com sucesso do conjunto\033[m\n");

            return true;
        }
    }

    printf("\033[1;31mNao foi possivel retirar o elemento %ld do conjunto\033[m\n", x);

    return false;
}

/// @param conj Ponteiro para um conjunto
/// @return A cardinalidade do conjunto
int cardinalidade_conjunto(Conjunto *conj)
{
    return conj->cardinalidade;
}
/**
 * @brief verifica se um determinado elemento esta contido em um conjunto
 *
 * @param conjunto
 * @param elemento
 * @return int
 */
int pertence(Conjunto *conj, int elemento)
{
    int i;
    int a = 10;
    for (i = 0; i < conj->cardinalidade; i++)
    {

        if (conj->elementos[i] == elemento)
        {
            return a;
        }
    }
    return 0;
}
void ordena(Conjunto *conj)
{
    int i;
    int j;
    int temp;

    for (i = 1; i < conj->cardinalidade; i++)
    {
        temp = conj->elementos[i];
        j = i - 1;

        while (j >= 0 && conj->elementos[j] > temp)
        {
            conj->elementos[j + 1] = conj->elementos[j];
            j--;
        }

        conj->elementos[j + 1] = temp;
    }
}
// retorna o maior elemento de um conjunto
/**
 * @brief retorna o maior elemento de um conjunto
 *
 * @param o conjunto
 */
void max(Conjunto *conj1)
{
    int i;

    if (conj1->cardinalidade == 0)
    {
        printf("\033[1;31mERROR: CONJUNTO VAZIO NAO TEM ELEMENTO MAXIMO\033[m\n");
        return;
    }

    long int maior = conj1->elementos[0];
    for (i = 0; i < conj1->cardinalidade; i++)
    {
        if (conj1->elementos[i] > maior)
        {
            maior = conj1->elementos[i];
        }
    }
    printf("\033[1;32mELEMENTO MAXIMO %ld\033[m\n", maior);
}
// retorna o menor elemento de um conjunto
/**
 * @brief retorna o menor elemento de um conjunto
 *
 * @param conjunto
 */
void min(Conjunto *conj1)
{
    int i;

    if (conj1->cardinalidade == 0)
    {
        printf("\033[1;31mERROR: CONJUNTO VAZIO NAO TEM ELEMENTO MINIMO\033[m\n");
        return;
    }

    long int menor = conj1->elementos[0];
    for (i = 0; i < conj1->cardinalidade; i++)
    {
        if (conj1->elementos[i] < menor)
        {
            menor = conj1->elementos[i];
        }
    }
    printf("\033[1;32mELEMENTO MINIMO %ld\033[m\n", menor);
}
// qtd de elementos maiores que um numero
/**
 * @brief compara se os elementos de um conjunto sao maiores que um numero qualquer
 *
 * @param conjunto
 * @param numero
 */
void N_maior(Conjunto *conj, int pivo)
{
    int i, j = 0;
    for (i = 0; i < conj->cardinalidade; i++)
    {
        if (conj->elementos[i] > pivo)
        {
            j++;
        }
    }
    printf("\033[1;32mNUMERO DE ELEMENTOS MAIORES QUE %d: %d\n\033[m", pivo, j);
}
// qtd de elementos menores que um numero
/**
 * @brief compara se os elementos de um conjunto sao menores que um numero qualquer
 *
 * @param conjunto
 * @param numero
 */
void N_menor(Conjunto *conj, int pivo)
{
    int i, j = 0;
    for (i = 0; i < conj->cardinalidade; i++)
    {
        if (conj->elementos[i] < pivo)
        {
            j++;
        }
    }
    printf("\033[1;32mNUMERO DE ELEMENTOS MENORES QUE %d: %d\n\033[m", pivo, j);
}
/**
 * @brief ordena em ordem crescente um conjunto
 *
 * @param conjunto
 */

/**
 * @brief compara dois conjuntos e verifica se eles sao identicos
 *
 * @param conjunto1
 * @param conjunto2
 * @return bool
 */
void igualdade(Conjunto *conj1, Conjunto *conj2)
{
    int i;
    int j = 0;
    ordena(conj1);
    ordena(conj2);
    if (conj1->cardinalidade != conj2->cardinalidade)
    {
        printf("\033[1;31mCONJUNTOS DIFERENTES\033[m\n");
    }
    else if (conj1->cardinalidade == conj2->cardinalidade)
    {

        for (i = 0; i < conj1->cardinalidade; i++)
        {
            if (conj1->elementos[i] != conj2->elementos[i])
            {
                j++;
            }
            else
            {
                j = 0;
            }
        }
        if (j == 0)
        {
            printf("\033[1;32mCONJUNTOS IDENTICOS\033[m\n");
        }
        else
        {
            printf("\033[1;31mCONJUNTOS DIFERENTES\033[m\n");
        }
    }
}
/**
 * @brief mostra o conjunto no terminal
 *
 * @param conjunto
 */
void print_conjunto(Conjunto *conj)
{

    for (int i = 0; i < conj->cardinalidade; i++)
    {
        printf("\033[1;34m%ld\033[m ", conj->elementos[i]);
    }

    printf("\n");
}

/// @brief Mostra um dado conjunto em ordem crescente ou decrescente
/// @param conj Ponteiro para um conjunto
/// @param ordem 1: ordem crescente; 2: ordem decrescente
void ordena_conjunto(Conjunto *conj, int ordem)
{
    // Trata os dois casos especiais de cardinalidade 0 e 1
    if (conj->cardinalidade == 0)
    {
        printf("\033[1;33mImpossivel ordenar conjunto vazio\033[m\n");
        return;
    }
    else
    {
        long int num = conj->elementos[0];

        if (conj->cardinalidade == 1)
        {
            printf("\033[1;32mConjunto ordenado com sucesso\033[m\n");
            printf("%ld\n", num);
            return;
        }
    }

    // Ordena conjunto usando Insertion Sort (a ordem nao importa, mas facilita)
    for (int i = 1; i < conj->cardinalidade; i++)
    {
        long int temp = conj->elementos[i];
        int j = i - 1;

        while (j >= 0 && conj->elementos[j] > temp)
        {
            conj->elementos[j + 1] = conj->elementos[j];
            j--;
        }

        conj->elementos[j + 1] = temp;
    }

    printf("\033[1;32mConjunto ordenado com sucesso em ordem ");

    if (ordem == 1)
    {
        printf("crescente\033[m\n");

        for (int i = 0; i < conj->cardinalidade; i++)
        {
            printf("\033[1;34m%ld ", conj->elementos[i]);
        }
    }
    else if (ordem == 2)
    {
        printf("decrescente\033[m\n");

        for (int i = conj->cardinalidade - 1; i >= 0; i--)
        {
            printf("\033[1;34m%ld ", conj->elementos[i]);
        }
    }
    else
    {
        printf("\033[1;31mErro: digite 1 para ordem crescente ou 2 para ordem decrescente\033[m\n");
    }

    printf("\033[m\n");
}

/// @brief Tenta copiar os elementos de um conjunto1 para um conjunto2
/// @param conj1 Ponteiro para um conjunto inicial
/// @param conj2 Ponteiro para um conjunto final
void copia_conjunto(Conjunto *conj1, Conjunto *conj2)
{
    conj2->cardinalidade = conj1->cardinalidade;
    free(conj2->elementos);
    conj2->elementos = (long int *)calloc(conj2->cardinalidade <= 0 ? 1 : conj2->cardinalidade, sizeof(long int));

    if (conj2->elementos == NULL)
    {
        printf("\033[1;31mErro: Nao foi possivel alocar o vetor de elementos na memoria\033[m\n");
        exit(1);
    }

    for (int i = 0; i < conj1->cardinalidade; i++)
    {
        conj2->elementos[i] = conj1->elementos[i];
    }

    printf("\033[1;32mConjunto copiado com sucesso\033[m\n");
}

void _insere_elemento(Conjunto *conj, long int x)
{
    // Verifica se o elemento 'x' é um (long int) valido
    if (x > LONG_MAX || x < LONG_MIN)
    {
        return;
    }
    // Verifica se o elemento 'x' ja esta inserido no conjunto
    if (procura_elemento(conj, x))
    {
        return;
    }
    // Verifica se o conjunto atingiu a cardinalidade maxima (10)
    if (conj->cardinalidade >= 10)
    {
        return;
    }
    // Se todos os testes forem validos a cardinalidade é incrementada ...
    conj->cardinalidade++;
    // ... e o vetor de elementos é realocado com um elemento a mais
    conj->elementos = (long int *)realloc(conj->elementos, conj->cardinalidade * sizeof(long int));
    if (conj->elementos == NULL)
    {
        exit(1);
    }
    // Elemento 'x' é atribuido à última posicao do vetor de elementos
    conj->elementos[conj->cardinalidade - 1] = x;
    return;
}

/**
 * @brief verifica se um Conjunto c1 é um sibconjunto de outro Conjunto c2
 * @param c1
 * @param c2
 * @return true se c1 é subconjunto de c2
 * @return false se c1 nao é subconjunto de c2
 */
bool eh_subconjunto(Conjunto *c1, Conjunto *c2)
{
    // se a cardinalidde de c1 for maior, nao tem como ele ser um subconjunto de c2
    if (c1->cardinalidade > c2->cardinalidade)
        return false;
    int i, j, ans = 0;
    for (i = 0; i < c1->cardinalidade; i++)
    {
        for (j = 0; j < c2->cardinalidade; j++)
        {
            if (c1->elementos[i] == c2->elementos[j])
            {
                ans++;
                break;
            }
        }
    }
    // se todos elementos de c1 estiverem em c2 entao é um subconjunto
    return ans == c1->cardinalidade;
}

/**
 * @brief
 *
 * @param c1
 * @param c2
 * @return Conjunto* retorna um ponteiro para o conjunto complemento para que c1 seja c2
 */
Conjunto *complemento(Conjunto *c1, Conjunto *c2)
{
    Conjunto *ans = cria_conjunto();

    if (!eh_subconjunto(c1, c2))
    {
        printf("\033[1;33mCONJUNTO VAZIO\n\033[m");
        return ans;
    }

    int i, j, k = 0;
    long int nums[10];
    for (i = 0; i < c2->cardinalidade; i++)
    {
        bool eh_complemento = true;
        for (j = 0; j < c1->cardinalidade; j++)
        {
            if (c2->elementos[i] == c1->elementos[j])
            {
                eh_complemento = false;
                break;
            }
        }
        if (eh_complemento)
        {
            nums[k] = c2->elementos[i];
            k++;
        }
    }

    for (i = 0; i < k; i++)
    {
        _insere_elemento(ans, nums[i]);
    }

    return ans;
}

/**
 * @brief retorna a interseccao entre c1 e c2
 *
 * @param c1
 * @param c2
 * @return Conjunto*
 */
Conjunto *interseccao(Conjunto *c1, Conjunto *c2)
{
    Conjunto *ans = (Conjunto *)calloc(1, sizeof(Conjunto));
    if (ans == NULL)
    {
        printf("\033[1;31mErro: Nao foi possivel alocar o conjunto na memoria\033[m\n");
        exit(1);
    }

    ans->elementos = (long int *)calloc(1, sizeof(long int));

    if (ans->elementos == NULL)
    {
        printf("\033[1;31mErro: Nao foi possivel alocar o vetor de elementos na memoria\033[m\n");
        exit(1);
    }

    int i, j;
    for (i = 0; i < c1->cardinalidade; i++)
    {
        for (j = 0; j < c2->cardinalidade; j++)
        {
            if (c1->elementos[i] == c2->elementos[j])
            {
                _insere_elemento(ans, c1->elementos[i]);
            }
        }
    }
    return ans;
}

Conjunto *uniao(Conjunto *c1, Conjunto *c2)
{
    Conjunto *ans = (Conjunto *)calloc(1, sizeof(Conjunto));
    if (ans == NULL)
    {
        printf("\033[1;31mErro: Nao foi possivel alocar o conjunto na memoria\033[m\n");
        exit(1);
    }

    ans->elementos = (long int *)calloc(1, sizeof(long int));

    if (ans->elementos == NULL)
    {
        printf("\033[1;31mErro: Nao foi possivel alocar o vetor de elementos na memoria\033[m\n");
        exit(1);
    }

    int x = c1->cardinalidade + c2->cardinalidade - interseccao(c1, c2)->cardinalidade;
    if (x <= 10)
    {
        int i;
        for (i = 0; i < c1->cardinalidade; i++)
        {
            _insere_elemento(ans, c1->elementos[i]);
        }
        for (i = 0; i < c2->cardinalidade; i++)
        {
            _insere_elemento(ans, c2->elementos[i]);
        }
    }

    return ans;
}