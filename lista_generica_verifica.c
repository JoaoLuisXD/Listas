#include <stdio.h>
#include <stdlib.h>

int impar(int A);
int par(int A);
int primo(int A);
void imprime(int *v, int tam, int (*verifica)(int));

int main()
{
    int vet[] = {1, 2, 10, 25, 33, 40};
    int tam = 6;
    printf("pares: \n");
    imprime(vet, 6, par);
    printf("\n");
    printf("impares: \n");
    imprime(vet, 6, impar);
    printf("\n");
    printf("primos: \n");
    imprime(vet, 6, primo);
    return 0;
}
int impar(int A)
{
    if (A % 2 != 0)
    {
        return 1;
    }
    return 0;
}
int par(int A)
{
    if (A % 2 == 0)
    {
        return 1;
    }
    return 0;
}
int primo(int A)
{
    int cont = 0;
    for (int i = 1; i <= A; i++)
    {
        if (A % i == 0)
        {
            cont++;
        }
    }
    if (cont == 2)
    {
        return 1;
    }
    return 0;
}
void imprime(int *v, int tam, int (*verifica)(int))
{
    for (int i = 0; i < tam; i++)
    {
        if (verifica(v[i]))
        {
            printf("| %d | ", v[i]);
        }
    }
}