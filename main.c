#include <stdio.h>
#include "TAD_lista/TAD_lista.h"
int main()
{
    LLista l = cria_lista();
    l = insere_lista(l,1);
    l = insere_lista(l,2);
    l = insere_lista(l,3);
    l = insere_lista(l,4);
    l = insere_lista(l,5);
    imprime_lista(l);
    int n;
    printf("Digite um numero que queira buscar: ");
    scanf("%d",&n);
    LLista encontrado = busca_elemento(l,n);
    if(encontrado != NULL)
    {
        printf("Numero %.2f foi encontrado com sucesso!!\n",encontrado->info);
    }
    else printf("Numero nao encontrado\n");
    n = 0;
    printf("\nDigite agora um numero que deseja excluir: ");
    scanf("%d",&n);
    printf("\nLista antes de excluir: \n");
    imprime_lista(l);
    l = remove_elemento(l,n);
    printf("\nLista apos excluir: \n");
    imprime_lista(l);
    return 0;
}