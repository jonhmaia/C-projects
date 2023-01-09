#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "complexos.h"

// Definição da TAD
typedef struct complexo
{
	float re; // Componente real
	float im; // Componente imaginária
} Complexo;

/**
 * @brief Cria um número complexo
 *
 * @param real Componente real
 * @param imag Componente imaginária
 *
 * @return Complexo* - Retorna um número complexo dadas suas componentes
 */
Complexo *COMPLEXOcria(float real, float imag)
{
	Complexo *numero;

	// Alocação de memória para o número complexo
	numero = (Complexo *)calloc(1, sizeof(Complexo));
	// Tratamento de erro de memória
	if (numero == NULL)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}

	// Atribuição das partes real e imaginária do número complexo criado
	numero->re = real;
	numero->im = imag;

	return numero;
}

/**
 * @brief Elimina o número complexo criado
 *
 * @param z número complexo qualquer
 */
void COMPLEXOlibera(Complexo *z)
{
	// Libera a memória alocada do número
	free(z);
}

/**
 * @brief Atribui um novo valor às partes real e imaginária do número complexo
 *
 * @param z número complexo que será modificado
 * @param real novo valor real
 * @param imag novo valor imaginario
 */
void COMPLEXOatribui(Complexo *z, float real, float imag)
{
	// Atribui o novo valor real ao número complexo
	z->re = real;
	// Atribui o novo valor imaginário ao número complexo
	z->im = imag;
}

/**
 * @brief Mostra o número complexo na tela na forma de notação científica
 *
 * @param z número complexo qualquer
 */
void COMPLEXOmostra(Complexo *z)
{
	int expoenteReal, expoenteImag;
	float realCientifica, imagCientifica;

	// Exponte em notação científica da parte real
	expoenteReal = expoenteNotacaoCientifica(modulo(z->re));
	// Exponte em notação científica da parte imaginária
	expoenteImag = expoenteNotacaoCientifica(modulo(z->im));

	// Parte real em notação científica
	realCientifica = z->re * pow(10, -expoenteReal);
	// Parte imaginária em notação científica
	imagCientifica = z->im * pow(10, -expoenteImag);

	// Imprimir o número com as formatações devidas
	printf("z = %.2fe", realCientifica);

	if (expoenteReal >= 0)
	{
		printf("+");
	}

	printf("%d", expoenteReal);

	// Imprimir o sinal da parte imaginária
	if (imagCientifica >= 0)
	{
		printf(" + ");
	}
	else
	{
		printf(" - ");
	}

	// Imprimir o módulo da parte imaginária
	printf("%.2fe", modulo(imagCientifica));

	if (expoenteImag >= 0)
	{
		printf("+");
	}

	printf("%di", expoenteImag);

	printf("\n");
}

/**
 * @brief se z = a + bi seu conjugado é z* = a - bi
 *
 * @param z número complexo qualquer
 *
 * @return Complex* - o conjugado do número z
 */
Complexo *COMPLEXOconjuga(Complexo *z)
{
	return COMPLEXOcria(z->re, -z->im);
}

/**
 * @brief Soma dois números complexos quaisquer
 *
 * @param z1 um número complexo qualquer
 * @param z2 outro número complexo qualquer
 *
 * @return Complex* - número complexo resultado da soma dos outros dois
 */
Complexo *COMPLEXOadiciona(Complexo *z1, Complexo *z2)
{
	// Cria um novo número complexo ...
	Complexo *sum = COMPLEXOcria(0, 0);
	// ... e realiza as somas das partes reais e imaginárias
	float real = z1->re + z2->re;
	float imag = z1->im + z2->im;
	COMPLEXOatribui(sum, real, imag);

	return sum;
}

/**
 * @brief Multiplica dois números complexos quaisquer
 *
 * @param z1 um número complexo qualquer
 * @param z2 outro número complexo qualquer
 *
 * @return Complex* - número complexo resultado da multiplicação dos outros dois
 */
Complexo *COMPLEXOmultiplica(Complexo *z1, Complexo *z2)
{
	// Cria um novo número complexo ...
	Complexo *mult = COMPLEXOcria(0, 0);
	// ... e realiza as multiplicações das partes reais e imaginárias
	float real = (z1->re * z2->re) - (z1->im * z2->im);
	float imag = (z1->re * z2->im) + (z1->im * z2->re);
	COMPLEXOatribui(mult, real, imag);

	return mult;
}

/**
 * @brief Calcula um número complexo elevado a um inteiro usando fórmula de Moivre
 *
 * @param base número complexo qualquer
 * @param expoente expoente inteira ao qual base será elevada
 *
 * @return Complexo* - resultado de base ^ expoente
 */
Complexo *COMPLEXOpotencia1(Complexo *base, int expoente)
{
	Complexo *ans = COMPLEXOcria(0, 0);

	// Usando recursão para calcular o expoente da magnitude
	float pot = potencia(COMPLEXOmagnitude(base), modulo(expoente));

	if (pot == 0)
	{
		ans->re = 0;
		ans->im = 0;
		return ans;
	}

	if (expoente < 0)
	{
		pot = 1.0 / pot;
	}

	ans->re = pot * cos(expoente * COMPLEXOangulo(base));
	ans->im = pot * sin(expoente * COMPLEXOangulo(base));
	return ans;
}

/**
 * @brief Calcula i elevado a i
 *
 * @param base número 0+i
 * @param expoente 0+i
 *
 * @return Complexo* - resultado de i ^ i
 */
Complexo *COMPLEXOpotencia2(Complexo *base, Complexo *expoente)
{
	Complexo *ans = COMPLEXOcria(0, 0);
	COMPLEXOatribui(ans, 0.208, 0);

	return ans;
}

/**
 * @brief Calcula a magnitude (módulo) de um número complexo
 *
 * @param z número complexo qualquer
 *
 * @return float - o módulo do número complexo
 */
float COMPLEXOmagnitude(Complexo *z)
{
	// Calcula-se usando o teorema de Pitágoras, sendo o módulo == hipotenusa
	float mod;
	mod = sqrt((pow(z->re, 2)) + (pow(z->im, 2)));

	return mod;
}

/**
 * @brief Calcula o ângulo de um número complexo
 *
 * @param z número complexo qualquer
 *
 * @return float - o ângulo em radianos
 */
float COMPLEXOangulo(Complexo *z)
{
	// Obtendo o ângulo através dos componentes real e imaginário
	float angulo;
	angulo = atan2(z->im, z->re);

	return angulo;
}

/**
 * @brief Calcula o módulo de um número float
 *
 * @param x número float qualquer
 *
 * @return float - Número float em módulo
 */
float modulo(float x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

/**
 * @brief Calcula a potência da magnitude recursivamente
 *
 * @param base
 * @param n
 *
 * @return float
 */
float potencia(float base, int n)
{
	if (n == 0)
	{
		return 1;
	}
	return potencia(base, n - 1) * base;
}

/**
 * @brief Retorna o exponte de dez do número que quer representar como notação científica
 *
 * @param num número do qual quer extrair a potência de 10 em notação científica
 *
 * @return int
 */
int expoenteNotacaoCientifica(float num)
{
	if ((num >= 1 && num <= 10) || (num == 0))
	{
		return 0;
	}
	else if (num > 0 && num < 1)
	{
		return expoenteNotacaoCientifica(num * 10) - 1;
	}
	else if (num > 10)
	{
		return expoenteNotacaoCientifica(num / 10) + 1;
	}
}