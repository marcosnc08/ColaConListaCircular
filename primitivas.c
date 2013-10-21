#include <stdio.h>
#include <stdlib.h>

#include "primitivas.h"
#include "global.h"

void crear_cola(t_lista *p)
{
    *p = NULL;
}

int insertar_cola(t_lista *p, const t_info *d)
{
    t_nodo *nue = (t_nodo *)malloc(sizeof(t_nodo));
    if(nue == NULL)
        return 500;
    nue->info = *d;

    if(*p == NULL)
    {
        *p = nue;
        nue->sig = nue;
        return 1;
    }

    nue->sig = (*p)->sig;
    (*p)->sig = nue;
    *p = nue;
    return 1;
}

int sacar_de_cola(t_lista *p, t_info *d)
{
    t_nodo *aux;

    if(*p == NULL)
        return 0;

    //*d = (*p)->sig->info;
    aux = (*p)->sig;
    *d = aux->info;

    if(aux == *p)
    {
        free(aux);
        *p = NULL;
    }

    aux = aux->sig;

    free(aux);
    return 1;
}

int ver_primero_cola(const t_lista *p, t_info *d)
{
    if(*p == NULL)
        return 500;

    *d = (*p)->sig->info;
    return 1;
}

int cola_llena(const t_lista *p)
{
    //CORREGIR
    t_nodo *aux = (t_nodo *)malloc(sizeof(t_nodo));
    if(aux == NULL)
        return 0;
    return 1;
}

int vaciar_cola(t_lista *p)
{
    //CORREGIR
    if((*p)->sig == NULL)
        return 0;

    while(*p)
    {
        t_nodo *aux;
        aux = (*p)->sig;
        (*p)->sig = aux->sig;
        free(aux);
    }
    return 1;
}

int cola_vacia(const t_lista *p)
{
    //CORREGIR
    if(*p == NULL)
        return 1;
    return 0;
}
