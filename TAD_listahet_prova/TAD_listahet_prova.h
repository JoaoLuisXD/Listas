#ifndef __TAD_LISTAHET_PROVA_H__
    #define __TAD_LISTAHET_PROVA_H__


#include <stdio.h>



#define TEL 1
#define ALU 2
#define IMG 3


struct listagen
{
    int ID;
    int tipo;
    void * info;
    struct listagen * prox;
};
typedef struct listagen Listagen;

struct listatel
{
    char nome[100];
    int num;
};
typedef struct listatel Listatel;

struct listaimg
{
    float largura;
    float altura;
};
typedef struct listaimg Listaimg;

struct listaalu
{
    char* nome[100];
    int idade;
};
typedef struct listaalu Listaalu;

Listagen * cria_lista();
void *cria_elemento(int tipo);
Listagen * insere(Listagen * cabeca_lista, int tipo, int id, void * info);
Listagen * retira(Listagen * cabeca_lista, void * info);
Listagen * libera(Listagen * cabeca_lista, void * info);
void imprime(Listagen * cabeca_lista, int tipo);




#include "TAD_listahet_prova.c"
#endif


