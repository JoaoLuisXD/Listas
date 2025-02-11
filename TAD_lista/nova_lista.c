#include <stdio.h>
#include <stdlib.h>
struct lista
{
    float info;
    struct lista * prox;
};
typedef struct lista Lista;
typedef Lista * Plista;

Plista cria_lista();
Plista insere_lista(Plista cabeca_lista, float valor);
Plista remove_lista (Plista cabeca_lista, float valor);
Plista busca_lista (Plista cabeca_lista, float valor);

int main()
{
    float n;
    Plista primeira = cria_lista();
    primeira = insere_lista(primeira,1);
    primeira = insere_lista(primeira,2);
    primeira = insere_lista(primeira,3);
    primeira = insere_lista(primeira,4);
    primeira = insere_lista(primeira,5);
    printf("DIGITE UM VALOR PARA PROCURAR: ");
    scanf("%f",&n);
   
    Plista encontrou = busca_lista(primeira,3);
    if(encontrou != NULL)
    {
        printf("%f",encontrou->info);
    }
    else printf("NAO ENCONTROU");
    return 0;
}

Plista cria_lista()
{
    return NULL;
}
Plista insere_lista(Plista cabeca_lista, float valor)
{
    Plista novo = (Plista)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = cabeca_lista;
    return novo;
}
Plista remove_lista (Plista cabeca_lista, float valor)
{
    Plista aux = NULL;
    Plista percorre = cabeca_lista;
    while(percorre != NULL && percorre->info != valor)
    {
        aux = percorre;
        percorre->prox;
    }
    if(percorre == NULL)
    {
        return cabeca_lista;
    }
    if(aux == NULL)
    {
        cabeca_lista = percorre->prox;
    }
    else
    {
        aux->prox = percorre->prox;
    }
    free(percorre);
    return cabeca_lista;
}    
Plista busca_lista (Plista cabeca_lista, float valor)
{
    Plista percorre = cabeca_lista;
    for(percorre = cabeca_lista ; percorre != NULL ; percorre = percorre->prox)
    {
        if(percorre->info == valor)
        {
            return percorre;
        }
    }
    return NULL;
}