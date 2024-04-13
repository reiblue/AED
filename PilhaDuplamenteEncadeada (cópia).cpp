#include <iostream>

using namespace std;

struct PilhaDupla
{    
    PilhaDupla *prox =  NULL;
    PilhaDupla *ant = NULL;
    int info;
};

struct Descritor
{
    PilhaDupla *head;
    PilhaDupla *tail;
    PilhaDupla *fila = NULL;
};

//Complexidade O(n)
bool contido(int k, Descritor *L)
{
    PilhaDupla *f = L->fila;

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

void inserir(int k, Descritor *L)
{
    PilhaDupla *i = L->fila;
    PilhaDupla *ant = NULL;

    while(i != NULL)
    {
        ant = i;
        i = i->prox;
        
    }

    if(L->fila != NULL)
    {
        i = new PilhaDupla;
        i->info =  k;
        i->ant = ant;
        ant->prox = i;
        L->tail = i;
        
    }else
    {
        i = new PilhaDupla;
        i->info =  k;        
        L->head = i;
        L->tail = i;
        L->fila = i;
    }
}

void remover(Descritor *L)
{      

    PilhaDupla *p = L->tail->ant;
    L->tail = p;
    p->prox = NULL;

}

int main()
{

    Descritor des;

    inserir(10, &des);
    inserir(20, &des);
    inserir(30, &des);
    inserir(40, &des);
    inserir(50, &des);

    remover(&des);



    cout << "Fim Programa..." << endl;

    return 0;
}