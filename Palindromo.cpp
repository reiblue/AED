#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct LDE  //lista duplamente encadeada
{    
    //LDE* inicio;
    char info = NULL;
    LDE* prox = NULL;
    LDE* ant = NULL;
};

/// @brief considere a inserção sempre no final da lista
/// @param K valor
/// @param L ponteiro
void inseirLDE(char K, LDE* L)
{
    LDE *ultimo = L; //Pega o endereço de memória atual
    LDE *ant = L;

    if(ultimo->info == NULL)
    {
        ultimo->info = K;
        ultimo->ant = NULL;
    }else{
        

        while (ultimo->prox != NULL) //percorre o endereço de memória até o último valor nulo 
        {
            ant = ultimo->prox;
            ultimo = ultimo->prox;    //guarda o endereço de memória do último não nulo
            
        }   
        
        ultimo->prox = new LDE; //aloca memoria para o valor do proximo elemento a ser adicionado
        ultimo->prox->info = K; //atribui um valor ao elemento adicionamdo
        ultimo->prox->ant = ant;
    }
}


int main()
{

    LDE *lista;

    lista = new LDE;

    inseirLDE('R', lista);
    inseirLDE('E', lista);
    inseirLDE('V', lista);
    inseirLDE('I', lista);
    inseirLDE('V', lista);
    inseirLDE('E', lista);
    inseirLDE('R', lista);
    inseirLDE('R', lista);


    LDE *listaFim = lista;
    while (listaFim->prox != NULL)
    {
        listaFim = listaFim->prox;
    }


    bool palindromo = true;
    while (lista != NULL)
    {
        if(lista->info != listaFim->info)
        {
            palindromo = false;
            break;
        }else{
            lista = lista->prox;
            listaFim = listaFim->ant;
        }
    }
    
    if(palindromo)
        cout << "Palindromo verdadeiro" << endl;
    else
        cout << "Palindromo Falso" << endl;
    



    return 0;
}