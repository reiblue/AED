#include <iostream>

using namespace std;

const int TSIZE = 15;

struct No{
    int valor;
    No* prox;
};

struct THash{
    No* tabela[TSIZE];
};

int chaveDivisao(int chave){
    return (chave) % TSIZE;
}

void removerHashEncadeado(THash* T, int chave){
    int posicao = chaveDivisao(chave);

    No* ant = nullptr;
    No* primeiro = T->tabela[posicao]; 

    while(T->tabela[posicao] != nullptr)
    {
        if(T->tabela[posicao]->valor == chave)
        {
            if(ant == nullptr){
                T->tabela[posicao] = T->tabela[posicao]->prox;
                primeiro = T->tabela[posicao];
            }
            else
                ant->prox = T->tabela[posicao]->prox;
            
            break;
        }else
        {
            ant = T->tabela[posicao];
            T->tabela[posicao] = T->tabela[posicao]->prox;
        }
            
    }

    T->tabela[posicao] = primeiro;
}

bool buscarHashEncadeado(THash* T, int chave){
    int posicao = chaveDivisao(chave);
    THash* aux = T;

    while(aux->tabela[posicao] != nullptr)
    {
        if(aux->tabela[posicao]->valor == chave)
            return true;
        else
            aux->tabela[posicao] = aux->tabela[posicao]->prox;
    }

    return false;
    
}

void inserirHashEncadeado(THash* table, int chave){
    int posicao = chaveDivisao(chave);
    No* novo = new No;
    novo->valor = chave;
    novo->prox = table->tabela[posicao];
    table->tabela[posicao] = novo; 
}


int main(){

    THash* t = new THash;

    inserirHashEncadeado(t, 10);
    inserirHashEncadeado(t, 100);
    inserirHashEncadeado(t,1000);
    int val = 0;

    do{
        cout << "Digite o valor para inserir: ";
        cin >> val;
        if(val>-1)
            inserirHashEncadeado(t,val);

    }while ( val >-1);
    

    int ValorBusca;
    cout << "Digite o valor da busca: ";
    cin >> ValorBusca;

    removerHashEncadeado(t, 10);

    if(buscarHashEncadeado(t, ValorBusca))
        cout << "Encontrado" << endl;
    else
        cout << "Não encontrado" << endl;

    return 0;
}