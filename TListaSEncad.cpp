#include <string>
#include <iostream>
#include "TListaSEncad.h"

//using namespace drozdek;
using namespace std;

TListaSEncad::TListaSEncad()
{
    primeiro = NULL;
    it = NULL;
}

float TListaSEncad::Consulta()
{
    if(it != NULL)
        return it->consultaInfo();
    else
    {
        cout << "Erro: No invalido!" << endl;
        exit(1);
    }
}

void TListaSEncad::Atribui(float val)
{
    if(it != NULL)
        it->atribInfo(val);
    else
        cout << "Erro: No invalido!" << endl;
}

bool TListaSEncad::Busca(float val)
{
    No *p;
    for(p = primeiro; p != NULL; p = p->consultaProx())
    {
        if(p->consultaInfo() == val)
            return true;
    }
    return false;

}

void TListaSEncad::Inicio()
{
    it = primeiro;
}

void TListaSEncad::ProximoNo()
{
    it = it->consultaProx();
}

bool TListaSEncad::FimDaLista()
{
    return (it == NULL);
}

TListaSEncad::~TListaSEncad()
{
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->consultaProx();
        delete p;
        p = t;
    }
}

void TListaSEncad::InserePrimeiro(float val)
{ 
    // insere Nó contendo val no início da lista
    No *p = new No(); // cria No apontado por p

    p->atribInfo(val);
    p->atribProx(primeiro);
    primeiro = p;

}

void TListaSEncad::InsereUltimo(float val)
{    

    No *i = it;

    while(i->consultaProx() != NULL)
        i = i->consultaProx();

    No *p = new No(); 

    p->atribInfo(val);
    i->atribProx(p);
    
}

void TListaSEncad::Elimina()
{
    No *i = it;

    while(i->consultaProx()->consultaProx() != NULL)
        i = i->consultaProx();
    
    i->elimina();

}

void TListaSEncad::Elimina(float valor)
{
    No *i = primeiro;

    while(i->consultaProx()->consultaInfo() != valor)
        i = i->consultaProx();
    

    i->atribProx(i->consultaProx()->consultaProx());    
}



void TListaSEncad::EliminaPrimeiro()
{ 
    // elimina primeiro No
    No *p;

    if(primeiro != NULL)
    { // se lista não está vazia
        if(primeiro == it)
            it = primeiro->consultaProx();

        p = primeiro; //p aponta para o No a ser excluído

        // pri passa a apontar para o atual segundo
        primeiro = p->consultaProx();
        delete p;
    } // exclui o 1º No
    else
        Rotina_Erro(1);
}

int TListaSEncad::Rotina_Erro(int valor)
{
    return valor;
}


