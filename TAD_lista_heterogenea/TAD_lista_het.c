/*
CRIA LISTAHET
parametros:
return: retorna uma lista vazia (NULL).
*/
Listahet * cria_listahet()
{
    return NULL;
}
Listahet * libera_listahet(Listahet * cabeca_lista)
{
    Listahet * p = cabeca_lista;
    while (p != NULL)
    {
        Listahet * temp = p->prox;
        free(p->info);
        free(p);
        p = temp;
    }
    return NULL;
}



/*
INSERE LISTAHET
parametros:
cabeca_lista = cabeca da lista.
id = chave primaria que identifica unicamente um objeto da lista.
tipo = inteiro definido que indentifica o tipo guardado na lista.
info = ponteiro void que guarda o endereço para a estrutura que guarda as informações de um tipo específico.
return = retorna o ponteiro para a cabeca da lista.
*/
Listahet * insere_listahet(Listahet * cabeca_lista, int id, int tipo, void * info)
{
    Listahet * novo = (Listahet*)malloc(sizeof(Listahet));
    novo->id = id;
    novo->tipo = tipo;
    novo->info = info;
    novo->prox = cabeca_lista;
    return novo;
}

/*
CRIA ELEMENTO LISTAHET
parametros:
tipo: recebendo o tipo, para cada caso de criação, dependendo se é triângulo, círculo ou retangulo
utilizando o switch case. 
return: retorna o tipo de lista criado, com suas pròprias características.
*/



void* cria_elemento_listahet(int tipo){

    switch(tipo){
        case RET:
            Retangulo* ptr1 = (Retangulo*)malloc(sizeof(Retangulo));
            printf("CRIANDO UM RETANGULO:\n");
            printf("DIGITE A BASE: ");
            scanf("%f%*c", &ptr1->base);
            printf("DIGITE A ALTURA: ");
            scanf("%f%*c", &ptr1->altura);
            return (void*)ptr1;
        break;
        case CIR:
            Circulo* ptr2 = (Circulo*)malloc(sizeof(Circulo));
            printf("CRIANDO UM CIRCULO:\n");
            printf("DIGITE O RAIO: ");
            scanf("%f%*c", &ptr2->raio);
            return (void*)ptr2;
        break;
        case TRI:
            Triangulo* ptr3 = (Triangulo*)malloc(sizeof(Triangulo));
            printf("CRIANDO UM TRIANGULO:\n");
            printf("DIGITE A BASE: ");
            scanf("%f%*c", &ptr3->base);
            printf("DIGITE A ALTURA: ");
            scanf("%f%*c", &ptr3->altura);
            return (void*)ptr3;
        break;
        default:
            printf("\nTipo indefinido!!!\n");
            return NULL;
    }
}


Listahet * retira_listahet(Listahet * cabeca_lista, int id)
{
    Listahet * p = cabeca_lista;
    Listahet * anterior = NULL;
    Listahet * atual = cabeca_lista;
    while(p != NULL)
    {
        if(p->id == id)
        {
            break;
        }
        else
        {
            anterior = p;
            p = p->prox;
        }
    }
    if(p != NULL)
    {
        // ESTA NA CABECA DA LISTA.
        if(anterior == NULL)
        p = p->prox;

        // ESTA NO MEIO OU NO FINAL DA LISTA.
        else 
        anterior->prox = p->prox;
    }
    
    // RETIRANDO O ELEMENTO DA LISTA E RETORNANDO A CABECA DA LISTA NO FINAL.
    free(p->info);
    free(p);
    return cabeca_lista;
}


int verifica_listahet_vazia(Listahet * cabeca_lista)
{
    return cabeca_lista == NULL;
}
Listahet * busca_listahet(Listahet * cabeca_lista, int id)
{
    Listahet * p = cabeca_lista;
    while(p != NULL)
    {
        if(p->id == id)
        {
            printf("ELEMENTO ENCONTRADO\n");
            return p;
        }
        p = p->prox;
    }
    printf("O ELEMENTO NAO ESTA NA LISTA\n");
    return NULL;
}

void imprime_listahet(Listahet * cabeca_lista)
{
    if(cabeca_lista != NULL)
    {
        for( ; cabeca_lista != NULL; cabeca_lista = cabeca_lista->prox)
        {
            switch (cabeca_lista->tipo)
            {
                case RET:
                    Retangulo* ret = (Retangulo*)cabeca_lista->info; 
                    printf("=====RETANGULO=====\n");
                    printf("base %.2f\n", ret->base);
                    printf("altura %.2f\n", ret->altura);
                    printf("===================\n\n");
                    break;

                case CIR:
                    Circulo* cir = (Circulo*)cabeca_lista->info; 
                    printf("=====CIRCULO=====\n");
                    printf("base %.2f\n", cir->raio);
                    printf("=================\n\n");
                    break;

                case TRI:
                    Triangulo* tri = (Triangulo*)cabeca_lista->info; 
                    printf("=====TRIANGULO=====\n");
                    printf("base %.2f\n", tri->base);
                    printf("altura %.2f\n", tri->altura);
                    printf("===================\n\n");    
                    break;
            
                default:
                    printf("tipo nao definido");
                    break;
            }
        }
    }
}
    