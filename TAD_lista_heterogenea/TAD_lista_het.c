/*
CRIA LISTAHET
parametros:
return: retorna uma lista vazia (NULL).
*/
Listahet * cria_listahet()
{
    return NULL;
}
Listahet * libera_listahet(Listahet * cabeca_lista);



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
    Listahet * novo = Listahet*(malloc)sizeof(Listahet);
    novo->id = id;
    novo->tipo = tipo;
    novo->info = info;
    novo->prox = cabeca_lista;
    return novo;
}
void * cria_elemento_listahet(int tipo)
{
    switch (tipo)
    {
    case RET:
    {
        Retangulo * ptr = (Retangulo*)malloc(sizeof(Retangulo));
        printf("CRIANDO UM RETANGULO:\n");
        printf("DIGITE A BASE DO RETANGULO: ");
        scanf("%f%*c",&ptr->base);
        printf("DIGITE A ALTURA DO RETANGULO: ");
        scanf("%f%*c",&ptr->altura);
        return (void*)ptr;
    }
    
    case CIR:
    {
    Circulo * ptr = (Circulo*)malloc(sizeof(Circulo));
        printf("CRIANDO UM CIRCULO:\n");
        printf("DIGITE O RAIO DO CIRCULO: ");
        scanf("%f%*c",&ptr->raio);
        return (void*)ptr;
    }

    case TRI:
    {
        Triangulo * ptr = (Triangulo*)malloc(sizeof(Triangulo));
        printf("CRIANDO UM TRIANGULO:\n");
        printf("DIGITE A BASE DO TRIANGULO: ");
        scanf("%f%*c",&ptr->base);
        printf("DIGITE A ALTURA DO TRIANGULO: ");
        scanf("%f%*c",&ptr->altura);
        return (void*)ptr;
    }
    
    default:
    printf("indefinido\n");
    return NULL;
    }
}
Listahet * retira_listahet(Listahet * cabeca_lista, int id);
int verifica_listahet_vazia(Listahet * cabeca_lista);
Listahet * busca_listahet(Listahet * cabeca_lista, int id);
void imprime_listahet(Listahet * cabeca_lista);