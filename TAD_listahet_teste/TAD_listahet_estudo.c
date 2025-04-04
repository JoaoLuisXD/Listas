
Listahet * cria_listahet()
{
    return NULL;
}
Listahet * insere_listahet(Listahet * cabeca_lista, int id, int tipo, void *info)
{
    Listahet *novo = (Listahet*)malloc(sizeof(Listahet));

    novo->id = id;
    novo->tipo = tipo;
    novo->info = info;
    novo->prox = cabeca_lista;
    return novo;
}
Listahet * libera_listahet(Listahet * cabeca_lista)
{
    Listahet * p = cabeca_lista;
    while(p != NULL)
    {
        Listahet * temp = p->prox;
        free(p->info);
        free(p);
        p = temp;
    }
    return NULL;
}
Listahet * busca_listahet(Listahet * cabeca_lista, int id)
{
    Listahet * p = cabeca_lista;
    while (p != NULL)
    {
        if(p->id == id)
        {
            return p;
            printf("encontrou\n");
        }
        p = p->prox;
    }
    printf("nao encontrou\n");
    return NULL;
}
void * cria_elemento(int tipo)
{
    switch (tipo)
    {
    case RET:
    Retangulo * ptr1 = (Retangulo*)malloc(sizeof(Retangulo));
    printf("base: ");
    scanf("%f%*c",&ptr1->base);
    printf("altura: ");
    scanf("%f%*c",&ptr1->altura);
    return (void*)ptr1;

    case CIR:
    Circulo * ptr2 = (Circulo*)malloc(sizeof(Circulo));
    printf("raio: ");
    scanf("%f%*c",&ptr2->raio);
    return (void*)ptr2;

    case TRI:
    Triangulo * ptr3 = (Triangulo*)malloc(sizeof(Triangulo));
    printf("base: ");
    scanf("%f%*c",&ptr3->base);
    printf("altura: ");
    scanf("%f%*c",&ptr3->altura);
    return (void*)ptr3;

    default:
        printf("tipo indefinido\n");
        return NULL;
    }
}
void * retira_elemento(Listahet * cabeca_lista, int id)
{
    Listahet * p = cabeca_lista;
    Listahet * anterior = NULL;
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



void imprime_listahet(Listahet * cabeca_lista)
{
    if(cabeca_lista != NULL)
    {
        while (cabeca_lista != NULL)
        {
            switch (cabeca_lista->tipo)
            {
            case RET:
                Retangulo * ptr1 = (Retangulo*)cabeca_lista->info;
                printf("base: %f\n",ptr1->base);
                printf("altura: %f\n",ptr1->altura);
                break;
            case CIR:
                Circulo * ptr2 = (Circulo*)cabeca_lista->info;
                printf("raio: %f\n",ptr2->raio);
                break;  
            case TRI:
                Triangulo * ptr3 = (Triangulo*)cabeca_lista->info;
                printf("base: %f\n",ptr3->base);
                printf("altura: %f\n",ptr3->altura);
                break;
            default:
                break;
            }
            cabeca_lista = cabeca_lista->prox;
        }
    }
     
}