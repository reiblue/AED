#include <iostream>
using namespace std;

struct LDEC  //lista duplamente encadeada circular
{    
    //LDE* inicio;
    int info;
    LDEC* prox = NULL;
    LDEC* ant = NULL;
};

struct Descritor
{
    LDEC *lista = NULL;
    LDEC *primeiro = NULL;
};

/// @brief considere a inserção sempre no final da lista
/// @param K valor
/// @param L ponteiro
void inserir(int K, Descritor* L)
{
    //LDEC *l = L->lista; //Pega o endereço de memória atual

    if(L->lista == NULL)
    {
        L->lista = new LDEC;
        L->lista->info = K;
        L->lista->ant = L->lista ;
        L->lista->prox = L->lista ;
        L->primeiro = L->lista;
    }else
    {
       LDEC novo;
       novo.info = K;
       novo.ant = L->primeiro->ant;
       novo.prox = L->primeiro;
       L->primeiro->ant = &novo;
       L->primeiro->ant->ant = &novo;
       
        
    }
}
/*
void remover(int K, Descritor* L)
{
    LDEC *encontar = L->lista;

    while(encontar != NULL)
    {
        if(encontar->info == K)
        {

            if(encontar->ant == NULL)
            {
                L = L->prox;
            }else
                encontar->ant = encontar->prox;

            cout << "Encontrado" << endl;
            break;
        }
            
        else
            encontar = encontar->prox;
    }
}

bool contido(int K, Descritor* L)
{
    LDEC *encontar = L;

    while(encontar != NULL)
    {
        if(encontar->info == K)
        {     
            cout << "Encontrado" << endl;
            return true;
        }  

        encontar = encontar->prox;
    }

    return false;
}*/

int main()
{
    
    Descritor list;

    //list.info = 10;
    LDEC p;

    p.info = 10;


    inserir(20, &list);
    inserir(30, &list);
    inserir(40, &list);

/*
    remover(40, &list);
    //removerLSE(10, &listSimples);

    if(contido(20, &list))
        cout << "Elemento 20 encontrado" << endl;
    else
        cout << "Elemento 20 não econtrado" << endl;

    */

    

    cout << endl << endl << "Listas duplamente encadeadas" << endl;

    cout << "Fim";
    cout << endl << endl;

    return 0;
}