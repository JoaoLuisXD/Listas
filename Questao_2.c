/*Questão 2:
Implemente uma função chamada processa que recebe um vetor
de inteiros, seu tamanho e dois callbacks: um para aplicar 
uma transformação em cada elemento do vetor e outro para 
definir uma condição de exibição na tela. O programa deve 
modificar os elementos do vetor conforme o primeiro callback
e imprimir apenas aqueles que satisfazem o segundo callback.
Teste a função com diferentes combinações, como dobrar os 
valores e exibir apenas os números divisíveis por 5, ou calcular
o quadrado e exibir apenas os maiores que 50.
*/

#include <stdio.h>
#include <stdlib.h>

int dobra(int n);
int div_cinco(int n);
int maior_cinquenta(int n);
void processa(int *vet,int tam, int(*transforma)(int), int(*verifica)(int));



int main()
{
    int vetor[] = {15,2,35,4,5};
    processa(vetor,5,dobra,maior_cinquenta);
    return 0;
}

int dobra(int n)
{
    return n*2;
}
int div_cinco(int n)
{
    return n%5 == 0;
}
int maior_cinquenta(int n)
{
    return n>50;
}
void processa(int *vet,int tam, int(*transforma)(int), int(*verifica)(int))
{
    for(int i=0;i<tam;i++)
    {
        vet[i] = transforma(vet[i]);

        if(verifica(vet[i]))
        {
            printf("%d\n",vet[i]);
        }
    }
}