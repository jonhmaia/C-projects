#include "complexos.h"
#include <math.h>


int main(void) {
    Complexo *z1, *z2, *z3;

    z1 = COMPLEXOcria(3, 4);
    z2 = COMPLEXOcria(sqrt(2), sqrt(2));
    printf("Numeros complexos a operar: z1 e z2\n");
    COMPLEXOmostra(z1);
    COMPLEXOmostra(z2);

    printf("\nAdição: z1 + z2\n");
    z3 = COMPLEXOadiciona(z1, z2);
    COMPLEXOmostra(z3);

    printf("\nConjugado de z2: z2*\n");
    z3 = COMPLEXOconjuga(z2);
    COMPLEXOmostra(z3);

    printf("\nMultiplicação: z1 * z2\n");
    z3 = COMPLEXOmultiplica(z1, z2);
    COMPLEXOmostra(z3);

    printf("\nMagnitude de z2:\n%.2f\n", COMPLEXOmagnitude(z2));
    printf("\nÂngulo de z2:\n%.2f (graus)\n", COMPLEXOangulo(z2)*180/M_PI);

    printf("\nPotência: z1 ^ 0\n");
    z3 = COMPLEXOpotencia1(z1, 0);
    COMPLEXOmostra(z3);

    printf("\nPotência: z1 ^ 1\n");
    z3 = COMPLEXOpotencia1(z1, 1);
    COMPLEXOmostra(z3);

    printf("\nPotência: z1 ^ 5\n");
    z3 = COMPLEXOpotencia1(z1, 5);
    COMPLEXOmostra(z3);

    printf("\nPotência: z1 ^ -5\n");
    z3 = COMPLEXOpotencia1(z1, -5);
    COMPLEXOmostra(z3);

    // Caso especial: Potencia complexa do numero complexo
    printf("\nPotência: i ^ i\n");
    COMPLEXOatribui(z2, 0.0, 1.0); // z2 = 0.0 + 1.0i
    z3 = COMPLEXOpotencia2(z2, z2);
    COMPLEXOmostra(z3);



    return(0);
}