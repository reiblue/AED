#include <iostream>
#include <math.h>

using namespace std;

struct aluno{
    int chave;
};

struct hashTable{
    int TSIZE;
    aluno **itens;
};

struct ha{
    int item[15];
    int TABLE_SIZE = 15;
};

struct Hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

/// @brief Hash perfeito
/// @param k 
/// @return 
int h(int k){
    return (int(log2(k-1)))%15;
}


Hash* criaHash(int TABLE_SIZE) {
    Hash* ha = new Hash;
    if (ha != nullptr) {
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = new aluno*[TABLE_SIZE]();
        if (ha->itens == NULL) {
            delete ha;
            return nullptr;
        }
        ha->qtd = 0;
    }
    return ha;
}

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave) % TABLE_SIZE;
}

//==============================================
// Insere e busca com tratamento de colisão: Endereçamento Aberto
//==============================================
int sondagemLinear(int pos, int i, int TABLE_SIZE){
    return ((pos + i)) % TABLE_SIZE;
}

int sondagemQuadratica(int pos, int i, int TABLE_SIZE){
    pos = pos + 2*i + 5*i*i;// hash + (c1 * i) + (c2 * i^2)
    return (pos) % TABLE_SIZE;
}

int duploHash(int H1, int chave, int i, int TABLE_SIZE){
    int H2 = chaveDivisao(chave,TABLE_SIZE-1) + 1;
    return ((H1 + i*H2)) % TABLE_SIZE;
}



int insereHash_EnderAberto(Hash* ha, int chave){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    
    //int chave = valorString(al.nome);


    int i, pos, newPos;
    pos = chaveDivisao(chave,ha->TABLE_SIZE);
    for(i=0; i < ha->TABLE_SIZE; i++){
        //newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
        //newPos = sondagemQuadratica(pos,i,ha->TABLE_SIZE);
        newPos = duploHash(pos,chave,i,ha->TABLE_SIZE);

        //função de hash perfeita
        //newPos = h(chave);

        if(ha->itens[newPos] == NULL){
            aluno* novo;
            novo = new aluno;
            novo->chave = chave;
            if(novo == NULL)
                return 0;
                
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}



int main(){

    int soma = log2(2);

    int S[] = {16385, 2, 17, 3, 33, 513, 8193, 1025, 65, 5, 129,  2049, 9, 257, 4097};

    cout << h(17) << endl;

    

    /*aluno* novo = new aluno;

    hashTable *table;

    table->itens = new aluno*[4]();*/

    //cout << (25 & 0x7FFFFFFF) << endl;

    Hash *h = criaHash(15);

    //h->TABLE_SIZE = 15;

    for(int i=0; i<15; i++)
        insereHash_EnderAberto(h, S[i]);



    /*for(int i = 0; i < h->TABLE_SIZE; i++)
        if(h->itens[i] != nullptr)
            cout << "tabela[" << i << "]: " << h->itens[i]->chave << endl;*/


    ha h2;

    //imprime hash perfeito
    for(int i = 0; i < h2.TABLE_SIZE; i++)
        if(h->itens[i] != nullptr)
            cout << "tabela[" << i << "]: " << h->itens[i]->chave << endl;


    return 0;
}