#include <iostream>
using namespace std;




struct LDE  //lista duplamente encadeada
{    
    //LDE* inicio;
    int info = NULL;
    LDE* prox = NULL;
    LDE* ant = NULL;
};

struct LSE //lista simplesmente encadeada
{
    LSE* inicio;
    int info = NULL;
    LSE* prox = NULL;
};

/// @brief considere a inserção sempre no final da lista
/// @param K valor
/// @param L ponteiro da lista
void inserirLSE(int K, LSE* L)
{
    LSE *ultimo = L; //Pega o endereço de memória atual
    
    while (ultimo->prox != NULL) //percorre o endereço de memória até o último valor nulo    
        ultimo = ultimo->prox;    //guarda o endereço de memória do último não nulo
    
    ultimo->prox = new LSE; //aloca memoria para o valor do proximo elemento a ser adicionado
    ultimo->prox->info = K; //atribui um valor ao elemento adicionamdo 
    
}


void removerLSE(int K, LSE *L)
{

    LSE *encontar = L;
    LSE *anterior = NULL;

    while(encontar != NULL)
    {
        if(encontar->info == K)
        {

            if(anterior == NULL)
            {
                L = L->prox;
            }else
                anterior->prox = encontar->prox;

            cout << "Encontrado" << endl;
            break;
        }else
            anterior = encontar;
            encontar = encontar->prox;
    }

}

/// @brief Verifica se está contido o valor na lista
/// @param K valor
/// @param L ponteiro
/// @return contido: true ;  não contido: false
bool contidoLSE(int K, LSE* L)
{
    LSE *encontar = L;

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
}

/// @brief considere a inserção sempre no final da lista
/// @param K valor
/// @param L ponteiro
void inseirLDE(int K, LDE* L)
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

void removerLDE(int K, LDE* L)
{
    LDE *encontar = L;

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

bool contidoLDE(int K, LDE* L)
{
    LDE *encontar = L;

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
}

/*
int main()
{
    
    LSE listSimples;

    listSimples.info = 10;

    
    

    inserirLSE(20, &listSimples);
    inserirLSE(30, &listSimples);
    inserirLSE(40, &listSimples);


    removerLSE(40, &listSimples);
    //removerLSE(10, &listSimples);

    if(contidoLSE(20, &listSimples))
        cout << "Elemento 20 encontrado" << endl;
    else
        cout << "Elemento 20 não econtrado" << endl;

    if(contidoLSE(50, &listSimples))
        cout << "Elemento 50 encontrado" << endl;
    else
        cout << "Elemento 50 não econtrado" << endl;

    cout << endl << endl << "Listas duplamente encadeadas" << endl;

    LDE listDupla;
    listDupla.info = 10;

    inseirLDE(10, &listDupla);

    cout << "Fim";
    cout << endl << endl;

    return 0;
}*/