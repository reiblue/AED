#include <string>
#include <iostream>
#include "TListCont.h"

//using namespace drozdek;
using namespace std;

/// @brief Instancia o tamanho, define o indice do último elemento e inicializa o vetor float[m]
/// @param tam Tamanho do indice
TListCont::TListCont(int tam)
{
    m = tam;
    ultimo = -1;
    X = new float[m];
}

/// @brief Destroi o vetor
TListCont::~TListCont()
{
    delete [] X;
}

/// @brief Retorna o valor na posição indicada
/// @param k inteiro correspondente a posição indicada
/// @return valor float correspondente a posição indicada
float TListCont::Consulta(int k)
{
    if(k >= 0 && k <= ultimo)
        return X[k];
    else
    {
        cout << "Indice invalido!" << endl;
        exit(1);
    }
}


void TListCont::Atribui(int k, float val)
{
    if(k >= 0 && k <= ultimo)
        X[k] = val;
    else
    {
        cout << "Indice invalido!" << endl;
        exit(2);
    }
}

/// @brief Insere um novo elemento e empurra os demais
/// @param k Valor do indice que será empurrado
/// @param val Novo valor que será inserido
void TListCont::Inserek(int k, float val)
{ 
    // insere No contendo val antes do No x k
    if(ultimo == (m - 1))
    {
        cout << "Vetor Cheio!" << endl;
        exit(3);
    }

    if(k >= 0 && k <= ultimo)
    {
        //empurra todo mundo para a próxima posição
        for(int i = ultimo; i >= k; i--)
            X[i+1] = X[i];

        X[k] = val;
        ultimo = ultimo + 1;
    }
    else 
    {
        cout << "Indice invalido!" << endl;
        exit(4);
    }
}

/// @brief Insere no vetor na última posição
/// @param val 
void TListCont::InsereUlt(float val)
{
    // insere No contendo val como ultimo No da lista
    if(ultimo == (m - 1))
    {
        cout << "Vetor Cheio!" << endl;
        exit(3);
    }
        ultimo = ultimo + 1;
        X[ultimo] = val;
}

/// @brief Elimina o indice referido e puxa todos os demais elementos
/// @param k indice
void TListCont::Eliminak(int k)
{ 
    // elimina No x k
    if(k >= 0 && k <= ultimo)
    {
    for(int i = k; i <= ultimo-1; i++)
        X[i] = X[i+1];

    ultimo = ultimo - 1;
    }else
    {
        cout << "Indice invalido!" << endl;
        exit(5);
    }
}

/// @brief Atualiza o indice do vetor para último--
void TListCont::EliminaUlt()
{ 
    // elimina o ultimo No da lista
    if(ultimo == -1)
    {
        cout << "Lista Vazia!" << endl;
        exit(6);
    }
    ultimo--;
}

/// @brief Exibe em modo texto o vetor e o indice
void TListCont::PrintList()
{
    for(int i=0; i< this->m; i++)
    {
        cout << "Val[" << i << "] : " << this->X[i] << ";" << endl;
    }

    //cout << "---------------" << endl;
    cout << endl << "m : " << this->m << ";" << endl;
    cout << "último : " << this->ultimo << endl;
    cout << "----------------" << endl << endl;
}

int TListCont::BuscaIndice(float k)
{

    int valor = -1;
    for(int i=0; i<this->ultimo;i++)
    {
        if(X[i] == k)
        {
            valor = i;
            break;
        }
    }

    return valor;
}




