#include <stdio.h>
#include "./TAD_lista_heterogenea/TAD_lista_het.h"
int main()
{

    Listahet * minha_lista = cria_listahet();
    
    minha_lista = insere_listahet(minha_lista, 1, RET, cria_elemento_listahet(RET));
    minha_lista = insere_listahet(minha_lista, 2, CIR, cria_elemento_listahet(CIR));
    minha_lista = insere_listahet(minha_lista, 3, TRI, cria_elemento_listahet(TRI));
    printf("\n");
    imprime_listahet(minha_lista);
    printf("\n");
    printf("digite o id do elemento que queira procurar: ");
    int n;
    scanf("%d%*c",&n);
    busca_listahet(minha_lista,n);
    libera_listahet(minha_lista);
    

    return 0;
}