#include <stdio.h>
#include <stdlib.h>
struct lista{
    int info;
    struct lista * prox;
};
typedef struct lista Lista;
Lista * cria_lista(); // função cria uma lista vazia
Lista * insere_lista(Lista * lista_atual, int valor);
void imprime_lista(Lista * lista_atual);
int lista_vazia(Lista * lista_atual);
Lista * busca_lista(Lista * lista_atual, int valor);
Lista * exclui_lista(Lista * lista_atual, int valor);
void libera_lista(Lista *lista_atual);
Lista * maximo_lista(Lista *lista_atual);
Lista * ordena_lista(Lista *Lista_atual);
int main()
{
    int n;
    Lista * prim;
    prim = cria_lista();
    prim = insere_lista(prim , 1);
    prim = insere_lista(prim , 2);
    prim = insere_lista(prim , 3);
    prim = insere_lista(prim , 4);
    lista_vazia(prim);
    imprime_lista(prim);
    printf("DIGITE UM ELEMENTO PARA BUSCAR NA LISTA: ");
    scanf("%d",&n);
    
    if(busca_lista(prim , n))
    {
        printf("O ELEMENTRO %d ESTA NA LISTA\n",n);
    }
    else printf("ESTE ELEMENTO NAO ESTA NA LISTA\n");
    

    return 0;
}
Lista * cria_lista()
{
    return NULL;
}
Lista * insere_lista(Lista * lista_atual, int valor)
{
    Lista * novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = lista_atual;
    return novo;
}
void imprime_lista(Lista * lista_atual)
{
    Lista * p; // variavel |p| para percorrer a lista
    for(p = lista_atual; p != NULL; p = p->prox)
    {
        printf("Elemento: %d\n", p->info);
    }
}
int lista_vazia(Lista * lista_atual)
{
    if(lista_atual == NULL)
    {
        return 1;
    }
    return 0;
}
Lista * busca_lista(Lista * lista_atual, int valor)
{
    Lista *p;
    for(p = lista_atual; p != NULL; p = p->prox)
    {
        if(p->info == valor)
        {
            return p; // achou o elemento
        }
    }
    return NULL; // não achou o elemento
}
Lista * exclui_lista(Lista * lista_atual, int valor)
{
    Lista * lista_anterior = NULL;
    Lista * p = lista_atual;
    while (p != NULL && p->info != valor)
    {
        lista_anterior = p;
        p = p->prox;
    }
    if(p == NULL)
    {
        return lista_atual;
    }
    if(lista_anterior == NULL)
    {
        p = p->prox;
    }
    else
    {
        lista_anterior->prox = p->prox;
    }
    free(p);
    return lista_atual;

}
void libera_lista(Lista *lista_atual)
{
    Lista * p = lista_atual;
    while(p != NULL)
    {
        Lista * temp = p->prox;
        free(p);
        p = temp;
    }
}
Lista * maximo_lista(Lista *lista_atual)
{
    Lista * maior = lista_atual;
    
    if(lista_atual != lista_vazia(lista_atual))
    {
        Lista * p = lista_atual;

        while(p != NULL)
        {
            if(maior->info > p->info)
            {
                maior = p;
            }
            p = p->prox;
        }
        return maior;
    }
    return NULL;
    
}
Lista * ordena_lista(Lista *lista_atual)
{
    Lista* lista_ordenada = cria_lista(); // cria uma nova lista vazia

    while(lista_atual != lista_vazia(lista_atual))
    {
        Lista * maior = maximo_lista(lista_atual);

        lista_ordenada = insere_lista(lista_ordenada, maior->info);

        lista_atual = exclui_lista(lista_atual, maior->info);
    }
    return lista_ordenada;
}
