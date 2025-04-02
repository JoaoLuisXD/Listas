/*
CRIA LISTAHET
parametros:
return: retorna uma lista vazia (NULL).
*/
Listahet * cria_listahet()
{
    return NULL;
}

/*
LIBERA LISTAHEt
parametros:
cabeca_lista = cabeca da lista.
p = variável utilizada para percorrer a lista.
temp = variável temporária usada para auxiliar a liberação da lista, guardando o ponteiro para o proxímo elemento,
enquanto o anterior é excluído.
return NULL no final, para ter certeza que não retorne nada.
*/

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


/*RETIRA LISTAHET
parametros:
cabeca_lista = cabeca da lista.
id = chave primaria que identifica unicamente um objeto da lista.
p = variável utilizada para percorrer a lista.
anterior = um elemento anterior à lista, inicialmente valendo NULL.
*/


Listahet * retira_listahet(Listahet * cabeca_lista, int id)
{
    Listahet * p = cabeca_lista;
    Listahet * anterior = NULL;
    // PERCORRENDO A LISTA, VERIFICANDO SE EU ACHEI O ELEMENTO QUE ESTOU PROCURANDO.
    while(p != NULL)
    {
        // SE ENCONTREI O ID DO ELEMENTO QUE ESTOU PROCURANDO, PARO A EXECUÇÃO DO IF COM UM BREAK.
        if(p->id == id)
        {
            break;
        }
        // SE NÃO ENCONTREI O ELEMENTO QUE ESTOU PROCURANDO.
        // O ANTERIOR, QUE ANTES VALIA NULL, AGORA RECEBE P (CABEÇA DA LISTA).
        // E O P (CABEÇA DA LISTA), RECEBE P->PROX (PROXIMO ELEMENTO DA LISTA).
        // OU SEJA CASO NÃO ENCONTRE, PASSE PARA O PRÓXIMO ELEMENTO, ATÉ ACHAR O QUE ESTOU PROCURANDO.
        else
        {
            anterior = p;
            p = p->prox;
        }
    }
    // SE P FOR DIFERENTE DE NULO, A LISTA NÃO É VAZIA.
    if(p != NULL)
    {
        // SE O ANTERIOR FOR IGUAL A NULL, SIGNIFICA QUE DURANTE O PASSEIO NA LISTA, A CONDIÇÃO PAROU NO PRIMEIRO CASO. OU SEJA, O ELEMENTO QUE ESTOU BUSCANDO, ESTÁ LOGO NA CABECA DA LISTA, POIS DECLARAMOS (ANTERIOR) INICIALMENTE COMO SENDO NULL, E ELE SÓ PASSA A SER DIFERENTE DE NULL, QUANDO NÃO ESTÁ NO INICIO DA LISTA. SABENDO QUE O ELEMENTO QUE ESTOU BUSCANDO ESTÁ NO INICIO, P = P->PROX, PARA GUARDAR LOGO A REFERÊNCIA DO PRÓXIMO ELEMENTO DA LISTA.
        if(anterior == NULL)
        p = p->prox;

        // SE O CASO ANTERIOR NÃO ACONTECER SIGNIFICA QUE O ELEMENTO QUE ESTOU BUSCANDO ESTÁ NO MEIO OU NO FIM DA LISTA, NESSE SEGUNDO CASO, FAÇO COM QUE O ANTERIOR->PROX (PRÓXIMO ELEMENTO QUE O ANTERIOR IRÁ APONTAR) SEJA P->PROX(PRÓXIMO ELEMENTO QUE O P VAI APONTAR). ASSIM FAZENDO UM SALTO SOBRE O P(ELEMENTO QUE SERÁ EXCLUÍDO), ASSIM JÁ GUARDANDO A REFERÊNCIA PRO PRÓXIMO ELEMENTO DA LISTA.
        else 
        anterior->prox = p->prox;
    }
    
    // AGORA RETIRANDO O ELEMENTO DA LISTA, PRIMEIRO LIBERO A INFORMAÇÃO QUE ESTÁ NO ELEMENTO (P->INFO), E DEPOIS LIBERO O ELEMENTO DA LISTA. NO FIM RETORNO A CABEÇA DA LISTA.
    free(p->info);
    free(p);
    return cabeca_lista;
}

/*
VERIFICA LISTAHET VAZIA
parametros:
cabeca_lista = cabeca da lista.
return: comparando a cabeça da lista com NULL, retorna uma boleana. 1 = true | 0 = false.
*/
int verifica_listahet_vazia(Listahet * cabeca_lista)
{
    return cabeca_lista == NULL;
}


/*
BUSCA LISTAHET
parametros:
cabeca_lista = cabeca da lista.
id = chave primaria que identifica unicamente um objeto da lista.
p = variável utilizada para percorrer a lista.
*/


Listahet * busca_listahet(Listahet * cabeca_lista, int id)
{
    Listahet * p = cabeca_lista;
    while(p != NULL) // PERCORRE A LISTA ENQUANTO NÃO FOR VAZIA.
    {
        // SE O ID DO ELEMENTO DA LISTA FOR IGUAL AO ID QUE ESTOU PROCURANDO, SIGNIFICA QUE ENCONTREI O ELEMENTO.
        if(p->id == id) 
        {
            printf("ELEMENTO ENCONTRADO\n");
            return p; // RETORNO O ELEMENTO ENCONTRADO.
        }
        p = p->prox; // ENQUANTO PERCORRO A LISTA, VOU PASSANDO A CABECA DA LISTA PARA O PRÓXIMO ELEMENTO DA MESMA.
    }

    //SE A CONDIÇÃO ANTERIOR NÃO FOR ATENDIDA, O ELEMENTO NÃO SE ENCONTRA NA LISTA.
    printf("O ELEMENTO NAO ESTA NA LISTA\n"); 

    return NULL; //RETURN NULL PARA GARANTIR QUE A FUNÇÃO RETORNE NADA.
}


/*IMPRIME LISTAHET
parametros:
cabeca_lista = cabeca da lista.
*/


void imprime_listahet(Listahet * cabeca_lista)
{
    if(cabeca_lista != NULL) //VERIFICA SE A CABECA DA LISTA NÃO É VAZIA.
    {
        while(cabeca_lista != NULL)// CASO NÃO SEJA VAZIA, PERCORRO A LISTA ATÉ QUE NÃO ENCONTRAR MAIS NENHUM ELEMENTO.
        {
            switch (cabeca_lista->tipo)//DEPENDENDO DO TIPO DA MINHA LISTA, EU EXIBO INFORMAÇÕES DIFERENTES.
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
            
                default: //CASO NÃO TENHA NENHUM TIPO IGUAL AOS QUE TEM NO SWITCH.
                    printf("tipo nao definido");
                    break;
            }
            cabeca_lista = cabeca_lista->prox; //ENQUANTO PERCORRO, VOU PASSANDO PARA O PRÓXIMO ELEMENTO DA LISTA.
        }
    }
}
    