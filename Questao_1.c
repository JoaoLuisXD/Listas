/*Questão 1:
Crie uma função chamada transforma que recebe um vetor de 
inteiros, seu tamanho e um callback que realiza uma operação 
matemática sobre cada elemento do vetor. O vetor deve ser 
modificado diretamente pela função. Teste transforma com 
diferentes callbacks, como dobrar os valores, calcular o 
quadrado de cada número e inverter o sinal dos elementos.
*/

#include <stdio.h>
#include <stdlib.h>

int dobra(int n);
int quadrado(int n);
int inverte(int n);
void transforma (int *v, int tam, int(*verifica)(int));


int main()
{
    int vet[] = {1,2,3,4,5};
    transforma(vet,5,dobra);
    printf("\n");
    transforma(vet,5,quadrado);
    printf("\n");
    transforma(vet,5,inverte);
    
    return 0;
}

int dobra(int n)
{
    return n*2;
}
int quadrado(int n)
{
    return n*n;
}
int inverte(int n)
{
    return n*(-1);
}
void transforma (int *v, int tam, int(*verifica)(int))
{
    for(int i = 0; i < tam; i++)
    {
        printf("| %d |",verifica(v[i]));
    }
}


