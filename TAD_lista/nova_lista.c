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
int conta_lista(Plista cabeca_lista);
void imprime_lista(Plista cabeca_lista);
int main()
{
    float n;
    Plista primeira = cria_lista();
    primeira = insere_lista(primeira,1);
    primeira = insere_lista(primeira,2);
    primeira = insere_lista(primeira,3);
    primeira = insere_lista(primeira,4);
    primeira = insere_lista(primeira,5);
    imprime_lista(primeira);

    printf("\n%d\n",conta_lista(primeira));

    printf("\nDIGITE UM VALOR PARA PROCURAR: ");
    scanf("%f",&n);
   
    Plista encontrou = busca_lista(primeira,n);
    if(encontrou != NULL)
    {
        printf("\n%f\n",encontrou->info);
    }
    else printf("NAO ENCONTROU\n");


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
Plista concatena (Plista cabeca_lista_um, Plista cabeca_lista_dois)
{
    Plista percorre = cabeca_lista_um;
    while (percorre->prox != NULL)
    {
        percorre->prox = cabeca_lista_dois;
    }
    return cabeca_lista_um;
}
int conta_lista(Plista cabeca_lista)
{
    Plista percorre = cabeca_lista;
    int cont=0;
    while(percorre != NULL)
    {
        cont++;
        percorre = percorre->prox;
    }
    return cont;
}
void imprime_lista(Plista cabeca_lista)
{
    Plista percorre = cabeca_lista;
    while(percorre != NULL)
    {
        printf("%f\n",percorre->info);
        percorre = percorre->prox;
    }
}
