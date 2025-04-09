Lista * cria_lista()
{
    return NULL;
}
int verifica_lista(Lista * cabeca_lista)
{
    return cabeca_lista == NULL;
}
Lista * libera_lista(Lista * cabeca_lista)
{
    Lista * p = cabeca_lista;
    while (p != NULL)
    {
        Lista * temp = p->prox;
        free(p->info);
        free(p);
        p = temp;
    }
    
}
Lista * insere_lista(Lista * cabeca_lista, void * info, int(*verifica)(void*, void*))
{
    Lista * novo = (Lista*)malloc(sizeof(Lista));
    Lista * p = cabeca_lista;
    Lista * anterior = NULL;
    novo->info = info;

    while (p != NULL)
    {
        if(verifica(novo->info,info))
        {
            break;
        }
        anterior = p;
        p = p->prox;
    }
    if(anterior == NULL && p == NULL)
    {
        novo->prox = NULL;
        cabeca_lista = novo;
    }
    else if(anterior == NULL && p != NULL)
    {
        novo->prox = cabeca_lista;
        cabeca_lista = novo;
    }
    else if(anterior != NULL && p != NULL)
    {
        novo->prox = p;
        anterior->prox = novo;
    }
    else if(anterior != NULL && p == NULL)
    {
        novo->prox = NULL;
        anterior->prox = novo;
    }
    return cabeca_lista;
    
}
Lista * retira_lista(Lista * cabeca_lista, void * info, int(*verifica)(void*, void*))
{
    Lista * p = cabeca_lista;
    Lista * anterior = NULL;
    while (p != NULL)
    {
        if(verifica(p->info,info))
        {
            break;
        }
        else
        {
            anterior = p;
        }
        p = p->prox;
    }

    if(p == NULL)
    {
        return cabeca_lista;
    }
    if(anterior == NULL)
    {
        cabeca_lista = p->prox;
    }
    else
    {
        anterior->prox = p->prox;
    }
    
    free(p->info);
    free(p);
    return cabeca_lista;
}
Lista * busca_elemento(Lista * cabeca_lista, void * info, int(*verifica)(void*,void*))
{
    Lista * p = cabeca_lista;
    while (p != NULL)
    {
        if(verifica(p->info,info))
        {
            return p;
            printf("achou");
        }
        p = p->prox;
    }
    printf("nao achou");
    return NULL;
    
}
void imprime_lista(Lista * cabeca_lista, void(*imprime)(void*))
{
    while (cabeca_lista != NULL)
    {
        imprime(cabeca_lista->info);
        cabeca_lista = cabeca_lista->prox;
    }
}