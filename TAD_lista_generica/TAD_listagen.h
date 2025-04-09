#ifndef __TAD_LISTAGEN_H__
    #define __TAD_LISTAGEN_H__

    #include <stdio.h>
    #include <stdlib.h>

    struct lista
    {
        void * info;
        struct lista * prox;
    };
    typedef struct lista Lista;


    Lista * cria_lista();
    int verifica_lista(Lista * cabeca_lista);
    Lista * libera_lista(Lista * cabeca_lista);
    Lista * insere_lista(Lista * cabeca_lista, void * info, int(*verifica)(void*, void*));
    Lista * retira_lista(Lista * cabeca_lista, void * info, int(*verifica)(void*, void*));
    Lista * busca_elemento(Lista * cabeca_lista, void * info, int(*verifica)(void*,void*));
    void imprime_lista(Lista * cabeca_lista, void(*imprime)(void*));
    
    


    #include "TAD_listagen.c"
#endif