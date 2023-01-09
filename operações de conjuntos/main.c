#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "conjuntos.h"

int main()
{
    // Numero de conjuntos
    int numeroConjuntos;

    // lista de ponteiros para conjuntos
    Conjunto **lista_conjuntos;

    printf("==============================================\n");
    printf("Quantos conjuntos deseja criar?\n");
    scanf("%d", &numeroConjuntos);
    printf("==============================================\n");

    // Aloco a lista de ponteiros para conjuntos
    lista_conjuntos = (Conjunto **)malloc(numeroConjuntos * sizeof(Conjunto *));
    if (lista_conjuntos == NULL)
    {
        printf("Erro na alocacao da lista de conjuntos\n");
        exit(1);
    }

    for (int i = 0; i < numeroConjuntos; i++)
    {
        lista_conjuntos[i] = cria_conjunto();
    }
    printf("==============================================\n");

    while (true)
    {
        // Operacao a ser realizada
        int op;
        int pos; // Posicao do conjunto que estou procurando no vetor de Conjuntos
		int pos2;
		long int x;
        Conjunto *aux = NULL;

        printf("Qual operacao deseja realizar?\n");
        printf("1) Verificar se um conjunto esta vazio\n");
        printf("2) Inclur um elemento em um conjunto\n");
        printf("3) Excluir um elemento de um conjunto\n");
        printf("4) Ver a cardinalidade de um conjunto\n");
        printf("5) Imprimir um conjunto\n");
        printf("6) Criar um novo conjunto\n");
        printf("7) Imprimir quantidade de conjuntos\n");
        printf("8) Ver se o elemento pertence ao conjunto\n");
        printf("9) A quantidades de elementos maiores que um certo valor e o maximo\n");
        printf("10) A quantidade de elementos menores que um certo valor e o minimo\n");
        printf("11) Verificar se dois conjuntos sao identicos\n");
        printf("12) Verificar se um conjunto e subconjunto de outro\n");
        printf("13) Conferir o conjunto complemento de um conjunto em relacao a outro\n");
        printf("14) Mostrar um conjunto em ordem\n");
        printf("15) Copiar um conjunto para outro\n");
        printf("16) Excluir conjunto\n");
        printf("17) Interseccao entre dois conjuntos\n");
        printf("18) Uniao entre dois conjuntos\n");
        printf("-1) Encerrar programa\n");
        scanf("%d", &op);
        printf("==============================================\n");


        switch (op)
        {
        case 1:

            printf("Qual conjunto deseja verificar se e VAZIO (comecando do 0)?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("\033[1;33mEscolha um conjunto entre 0 e %d\n\033[m", numeroConjuntos);
                }
            }

            if (verifica_se_vazio(lista_conjuntos[pos]))
                printf("Conjunto vazio\n");
            else
                printf("Conjunto nao vazio\n");

            printf("==============================================\n");

            break;
        case 2:

            printf("Qual conjunto deseja adicionar elementos (comecando do 0)?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("\033[1;33mEscolha um conjunto entre 0 e %d\n\033[m", numeroConjuntos);
                }
            }
            int quantElementosConjunto; // Quantidade de elementos em um conjunto 'pos'
            printf("Quantos elementos deseja colocar no conjunto %d?\n", pos);
            scanf("%d", &quantElementosConjunto);

            // Se o conjunto for vazio...
            if (quantElementosConjunto == 0)
                printf("Nenhum elemento foi inserido no conjunto\n");
            else
            {
                printf("Digite os elementos que quer colocar no conjunto %d:\n", pos);

                // For que insere os elementos digitados no conjunto pos
                for (int j = 0; j < quantElementosConjunto; j++)
                {
                    long int valor;
                    scanf("%ld", &valor);
                    insere_elemento(lista_conjuntos[pos], valor);
                }
            }
            printf("==============================================\n");

            break;
        case 3:
            printf("Qual conjunto deseja remover um elemento (comecando do 0)?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("\033[1;33mEscolha um conjunto entre 0 e %d\n\033[m", numeroConjuntos);
                }
            }
            long int valor;
            printf("Qual elemento deseja remover?\n");
            scanf("%ld", &valor);
            retira_elemento(lista_conjuntos[pos], valor);

            printf("==============================================\n");
            break;
        case 4:
            printf("Qual conjunto deseja ver a cardinalidade (comecando do 0)?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("\033[1;33mEscolha um conjunto entre 0 e %d\n\033[m", numeroConjuntos);
                }
            }
            printf("A cardinalidade do conjunto %d e: %d\n", pos, cardinalidade_conjunto(lista_conjuntos[pos]));
            printf("==============================================\n");
            break;
        case 5:
            printf("Qual conjunto deseja printar (comecando do 0)?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("\033[1;33mEscolha um conjunto entre 0 e %d\n\033[m", numeroConjuntos);
                }
            }
            print_conjunto(lista_conjuntos[pos]);
            printf("==============================================\n");
            break;

        case 6:
            numeroConjuntos++;

            // Realoco a lista de ponteiros para conjuntos
            lista_conjuntos = (Conjunto **)realloc(lista_conjuntos, numeroConjuntos * sizeof(Conjunto *));
            if (lista_conjuntos == NULL)
            {
                printf("Erro na alocacao da lista de conjuntos\n");
                exit(1);
            }
            lista_conjuntos[numeroConjuntos - 1] = cria_conjunto();

            printf("==============================================\n");

            break;
        case 7:
            printf("A quantidade de conjuntos e: %d\n", numeroConjuntos);
            printf("==============================================\n");

            break;
        case 8:
            printf("Qual conjunto deseja verificar?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("\033[1;33mEscolha um conjunto entre 0 e %d\n\033[m", numeroConjuntos);
                }
            }
            printf("Digite o numero que deseja verificar: \n");
            
            scanf("%ld", &x);

            pertence(lista_conjuntos[pos], x);
            if (pertence(lista_conjuntos[pos], x) == 10)
            {
                printf("\033[1;32mO ELEMENTO PERTENCE AO CONJUNTO\033[m\n");
            }
            else
                printf("\033[1;31mO ELEMENTO NAO PERTENCE AO CONJUNTO\033[m\n");
            printf("==============================================\n");
			break;
        case 9:
            printf("Qual conjunto deseja verificar?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("\033[1;33mEscolha um conjunto entre 0 e %d\n\033[m", numeroConjuntos);
                }
            }
            
            printf("Digite o numero que deseja verificar: \n");
            scanf("%ld", &x);
            N_maior(lista_conjuntos[pos], x);
            max(lista_conjuntos[pos]);
            printf("==============================================\n");
			break;
        case 10:
            printf("Qual conjunto deseja verificar?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("\033[1;33mEscolha um conjunto entre 0 e %d\n\033[m", numeroConjuntos);
                }
            }
            
            printf("Digite o numero que deseja verificar: \n");
            scanf("%ld", &x);
            N_menor(lista_conjuntos[pos], x);
            min(lista_conjuntos[pos]);
            printf("==============================================\n");
			break;
        case 11:
            printf("Digite o primeiro conjunto(comecando do 0): \n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }

            printf("Digite outro conjunto (comecando do 0): \n");
            
            while (true)
            {
                scanf("%d", &pos2);

                if (pos2 >= 0 && pos2 <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }
            igualdade(lista_conjuntos[pos], lista_conjuntos[pos2]);

            printf("==============================================\n");

            break;
        case 12:
            printf("Digite o primeiro conjunto(comecando do 0): \n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }

            printf("Digite outro conjunto (comecando do 0): \n");
            
            while (true)
            {
                scanf("%d", &pos2);

                if (pos2 >= 0 && pos2 <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }

            if (eh_subconjunto(lista_conjuntos[pos], lista_conjuntos[pos2])) {
                printf("\033[1;32mE SUBCONJUNTO\n\033[m");
            } else {
                printf("\033[1;31mNAO E SUBCONJUNTO\n\033[m");
            }

            printf("==============================================\n");
            break;
        case 13:
            printf("Digite o primeiro conjunto(comecando do 0): \n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }

            printf("Digite outro conjunto (comecando do 0): \n");
            
            while (true)
            {
                scanf("%d", &pos2);

                if (pos2 >= 0 && pos2 <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }
            printf("\033[1;32mCOMPLEMENTO:\n\033[m");
            aux = complemento(lista_conjuntos[pos], lista_conjuntos[pos2]);
            print_conjunto(aux);

            break;
        case 14:
            printf("Qual conjunto deseja ordenar (comecando do 0)?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("\033[1;33mEscolha um conjunto entre 0 e %d\n\033[m", numeroConjuntos);
                }
            }

            printf("Digite 1 para ordem crescente ou 2 para ordem decrescente:\n");
            int ordem;
            while (true)
            {
                scanf("%d", &ordem);

                if (ordem == 1 || ordem == 2)
                {
                    break;
                }
                else
                {
                    printf("\033[1;Digite 1 para ordem crescente ou 2 para ordem decrescente:\n");
                }
            }

            ordena_conjunto(lista_conjuntos[pos], ordem);
            printf("==============================================\n");

            break;

        case 15:
            printf("De qual conjunto deseja copiar (comecando do 0)?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }

            printf("Para qual conjunto deseja copiar (comecando do 0)?\n");
            
            while (true)
            {
                scanf("%d", &pos2);

                if (pos2 >= 0 && pos2 <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }

            copia_conjunto(lista_conjuntos[pos], lista_conjuntos[pos2]);
            printf("==============================================\n");

            break;

        case 16:
            printf("Qual conjunto deseja excluir (comecando do 0)?\n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }

            libera_conjunto(lista_conjuntos, &numeroConjuntos, pos);

            printf("==============================================\n");

            break;
        case 17:
            printf("Digite o primeiro conjunto(comecando do 0): \n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }

            printf("Digite outro conjunto (comecando do 0): \n");
            
            while (true)
            {
                scanf("%d", &pos2);

                if (pos2 >= 0 && pos2 <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }
;
            aux = interseccao(lista_conjuntos[pos], lista_conjuntos[pos2]);
            printf("\033[1;32mINTERSECCAO:\n\033[m");
            if (aux->cardinalidade <= 0) 
                printf("\033[1;31mVAZIO\n\033[m");
            else 
                print_conjunto(aux);
            break;
        case 18:
            printf("Digite o primeiro conjunto(comecando do 0): \n");
            while (true)
            {
                scanf("%d", &pos);

                if (pos >= 0 && pos <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }

            printf("Digite outro conjunto (comecando do 0): \n");
            
            while (true)
            {
                scanf("%d", &pos2);

                if (pos2 >= 0 && pos2 <= numeroConjuntos)
                {
                    break;
                }
                else
                {
                    printf("Escolha um conjunto entre 0 e %d\n", numeroConjuntos);
                }
            }

            aux = uniao(lista_conjuntos[pos], lista_conjuntos[pos2]);
            printf("\033[1;32mUNIAO:\n\033[m");
            if (aux->cardinalidade <= 0) 
                printf("\033[1;31mVAZIO\n\033[m");
            else 
                print_conjunto(aux);
            break;
        case -1:
            for (int i = 0; i < numeroConjuntos; i++)
            {
                free(lista_conjuntos[i]->elementos);
                free(lista_conjuntos[i]);
            }

            free(lista_conjuntos);
            exit(1);
            break;

        default:
            printf("\033[1;33mEscolha uma opcao valida\033[m\n");
            printf("==============================================\n");
            break;
        }
    }

    return 0;
}