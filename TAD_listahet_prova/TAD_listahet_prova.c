#include <stdlib.h>

Listagen * cria_lista(){
    return NULL;
}

void *cria_elemento(int tipo){
    switch (tipo)
    {
    case 1:
        Listatel * ptr1 = (Listatel*)malloc(sizeof(Listatel));
        scanf("%s%*c",&ptr1->nome);
        scanf("%d%*c",&ptr1->num);
        return (void*)ptr1;
    case 2:
        Listaalu * ptr2 = (Listaalu*)malloc(sizeof(Listaalu));
        scanf("%s%*c",&ptr2->nome);
        scanf("%d%*c",&ptr2->idade);
        return (void*)ptr2;
    case 3:
        Listaimg * ptr3 = (Listaimg*)malloc(sizeof(Listaimg));
        scanf("%f%*c",&ptr3->altura);
        scanf("%f%*c",&ptr3->largura);
        return (void*)ptr3;    
    default:
        printf("nao definido");
        break;
    }
}

Listagen * insere(Listagen * cabeca_lista, int tipo, int id, void * info){
    Listagen * novo = (Listagen*)malloc(sizeof(Listagen));
    novo->ID = id;
    novo->tipo = tipo;
    novo->info = info;
    novo->prox = cabeca_lista;
    return novo;
}

Listagen * retira(Listagen * cabeca_lista, void * info){
    Listagen * p = cabeca_lista;
    Listagen * anterior = NULL;
    while (p != NULL)
    {
        if(p->info == info)
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
        p = p->prox;
    }
    else
    {
        anterior->prox = p->prox;
    }
free(p->info);
free(p);
return cabeca_lista;
    
}

Listagen* libera(Listagen* cabeca_lista, void* info){
    Listagen* p = cabeca_lista;
    if(cabeca_lista!=NULL){
        while (p!=NULL)
        {
            Listagen* temp = p->prox;
            free(p->info);
            free(p);
            p = temp;
        }
    }
    return NULL;
    

}

void imprime(Listagen* cabeca_lista, int tipo){
    if(cabeca_lista != NULL){
        switch (tipo)
        {
        case 1:
            Listatel* tel = (Listatel*)cabeca_lista->info;
            printf("\n===Lista telefonica===\n");
            printf("Nome: %s\n",tel->nome);
            printf("Numero: %d\n",tel->num);
            printf("======================\n");
            
            break;
            
        case 2:
            Listaalu* luno = (Listaalu*)cabeca_lista->info;
            printf("\n===Lista alunos===\n");
            printf("Nome do aluno: %s\n",luno->nome);
            printf("Idade: %d", luno->idade);
            printf("==================\n");
            
            break;
            
        case 3:
            Listaimg* img = (Listaimg*)cabeca_lista->info;
            printf("\n===Lista imagens===\n");
            printf("Largura: %.2f\n",img->largura);
            printf("Altura: %.2f\n",img->altura);
            printf("===================\n");
            break;
        
        default:
            break;
        }
    }
}