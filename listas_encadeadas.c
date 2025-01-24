#include <stdio.h>
#include <stdlib.h>
struct lista{
    int info;
    struct lista * prox;
};
typedef struct lista Lista;
Lista * cria_lista(); // função cria uma lista vazia
Lista * insere_lista(Lista * nova_lista, int valor);
void imprime_lista(Lista * nova_lista);
int lista_vazia(Lista * nova_lista);
Lista * busca_lista(Lista * nova_lista, int valor);
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
Lista * insere_lista(Lista * nova_lista, int valor)
{
    Lista * novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = nova_lista;
    return novo;
}
void imprime_lista(Lista * nova_lista)
{
    Lista * p; // variavel |p| para percorrer a lista
    for(p = nova_lista; p != NULL; p = p->prox)
    {
        printf("Elemento: %d\n", p->info);
    }
}
int lista_vazia(Lista * nova_lista)
{
    if(nova_lista == NULL)
    {
        return 1;
    }
    return 0;
}
Lista * busca_lista(Lista * nova_lista, int valor)
{
    Lista *p;
    for(p = nova_lista; p != NULL; p = p->prox)
    {
        if(p->info == valor)
        {
            return p; // achou o elemento
        }
    }
    return NULL; // não achou o elemento
}
