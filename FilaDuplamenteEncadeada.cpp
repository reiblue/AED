#include <iostream>

using namespace std;

struct FilaDupla
{    
    FilaDupla *prox =  NULL;
    FilaDupla *ant = NULL;
    int info;
};

struct DescritorFilaDupla
{
    FilaDupla *head;
    FilaDupla *tail;
    FilaDupla *fila = NULL;
};

//Complexidade O(n)
bool contido(int k, DescritorFilaDupla *L)
{
    FilaDupla *f = L->fila;

    while(f != NULL)
    {
        if(f->info == k)
        {
            return true;
        }
        f = f->prox;
    }

    return false;
}

void inserir(int k, DescritorFilaDupla *L)
{
    FilaDupla *i = L->fila;
    FilaDupla *ant = NULL;

    while(i != NULL)
    {
        ant = i;
        i = i->prox;
        
    }

    if(L->fila != NULL)
    {
        i = new FilaDupla;
        i->info =  k;
        i->ant = ant;
        ant->prox = i;
        L->tail = i;
        
    }else
    {
        i = new FilaDupla;
        i->info =  k;        
        L->head = i;
        L->tail = i;
        L->fila = i;
    }
}

void remover(DescritorFilaDupla *L)
{    
    L->fila = L->fila->prox;
    L->head = L->fila;
    L->fila->ant = NULL;

}

int main()
{

    DescritorFilaDupla des;

    inserir(10, &des);
    inserir(20, &des);
    inserir(30, &des);
    inserir(40, &des);
    inserir(50, &des);

    remover(&des);



    cout << "Fim Programa..." << endl;

    return 0;
}