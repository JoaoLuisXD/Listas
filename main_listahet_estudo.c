#include "TAD_listahet_teste/TAD_listahet_estudo.h"

int main()
{
    Listahet * minha_lista = cria_listahet();
    minha_lista = insere_listahet (minha_lista,0,RET,cria_elemento(RET));
    minha_lista = insere_listahet (minha_lista,1,CIR,cria_elemento(CIR));
    minha_lista = insere_listahet (minha_lista,2,TRI,cria_elemento(TRI));
    imprime_listahet(minha_lista);
    return 0;
}