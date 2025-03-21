#ifndef __TAD_LISTA_HET_H__
    #define __TAD_LISTA_HET_H__

#define RET 0
#define CIR 1
#define TRI 2

#include <stdio.h>

struct listahet
{
    int id;
    int tipo;
    void * info;
    struct lista_het * prox;
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
Listahet * libera_listahet(Listahet * cabeca_lista);
Listahet * insere_listahet(Listahet * cabeca_lista, int id, int tipo, void * info);
void * cria_elemento_listahet(int tipo);
Listahet * retira_listahet(Listahet * cabeca_lista, int id);
int verifica_listahet_vazia(Listahet * cabeca_lista);
Listahet * busca_listahet(Listahet * cabeca_lista, int id);
void imprime_listahet(Listahet * cabeca_lista);


    #include "TAD_lista_het.c"
#endif







