#include <stdlib.h>
#include <stdio.h>

struct lista
{
    float info;
    struct lista * prox;
};
typedef struct lista Lista;
typedef Lista * LLista;

LLista cria_lista();
LLista insere_lista(LLista cabeca_lista, float valor);
LLista remove_elemento(LLista cabeca_lista, float valor);
LLista busca_elemento(LLista cabeca_listsa, float valor);
void imprime_lista(LLista cabeca_lista);

#include "TAD_lista.c"