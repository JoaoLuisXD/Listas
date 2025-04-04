#ifndef __TAD_LISTAHET_ESTUDO_H__
    #define __TAD_LISTAHET_ESTUDO_H__

    #define RET 0
    #define CIR 1
    #define TRI 2


    #include <stdio.h>
    #include <stdlib.h>

    struct listahet
    {
        int id;
        int tipo;
        void *info;
        struct listahet * prox;
    };
    typedef struct listahet Listahet;


    struct retangulo
    {
        float base;
        float altura;
    };
    typedef struct retangulo Retangulo;

    struct circulo
    {
        float raio;
    };
    typedef struct circulo Circulo;

    struct triangulo
    {
        float base;
        float altura;
    };
    typedef struct triangulo Triangulo;

    Listahet * cria_listahet();
    Listahet * insere_listahet(Listahet * cabeca_lista, int id, int tipo, void *info);
    Listahet * libera_listahet(Listahet * cabeca_lista);
    Listahet * busca_listahet(Listahet * cabeca_lista, int id);
    void * cria_elemento(int tipo);
    void * retira_elemento(Listahet * cabeca_lista, int id);
    void  imprime_listahet(Listahet * cabeca_lista);



    #include "TAD_listahet_estudo.c"
#endif