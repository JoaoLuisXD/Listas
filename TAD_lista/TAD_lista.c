#ifndef __TAD_LISTA_C__
#define __TAD_LISTA_C__


LLista cria_lista()
{
    return NULL;
}
LLista insere_lista(LLista cabeca_lista, float valor)
{
    LLista novo = (LLista)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = cabeca_lista;
    return novo;
}
void imprime_lista(LLista cabeca_lista)
{
    LLista p;
    for(p = cabeca_lista; p != NULL; p = p->prox)
    {
        printf("Elemento %.2f\n",p->info);
    }
}
LLista remove_elemento(LLista cabeca_lista, float valor)
{
    LLista p = cabeca_lista;
    LLista aux = NULL;
    while(p != NULL && p->info != valor)
    {
        aux = p;
        p = p->prox;
    }
    if(p == NULL)
    {
        return cabeca_lista; // cabeca da lista e nula
    }
    if(aux == NULL)
    {
        cabeca_lista = p->prox;
    }
    else
    {
        aux->prox = p->prox;
    }
    free(p);
    return cabeca_lista;

}
LLista busca_elemento(LLista cabeca_listsa, float valor)
{
    LLista p = cabeca_listsa;
    while(p != NULL)
    {
        if(p->info == valor)
        {
            return p;
        }
        p = p->prox;
    }
    return NULL;
}





#endif