#include <iostream>
#include <math.h>

using namespace std;

const int TSIZE = 16;

struct THash{
    int tabela[TSIZE];
};

int chaveDivisao(int chave, int i = 0){
    return chave % (TSIZE-i);
}

int sondagemLinear(int i, int posicao){
    return (posicao + i) % TSIZE;
}

int sondagemQuadratica(int i, int posicao){
    return (posicao + (i*i)) % TSIZE;
}

int sondagemQuadraticaLivro(int i, int posicao){
    return (posicao + (int( pow(-1, i)) * int (pow((i+1)/2, 2)))) % TSIZE;    
}

/*int duploHash(int H1, int i){
    return (H1 + (i*(H1+1))) % TSIZE;
}*/

int h1(int chave){
    return chave % TSIZE;
}

int hashSalto(int chave){
    int x = chave*2 % 11;
    return chave % 2 == 0 ? chave+1 : chave;
}

int h2(int chave, int i){
    return (h1(chave) + hashSalto(chave)*i) % TSIZE;
}

bool inserirEndAberto(THash* T, int chave){

    bool incluido = false;

    for(int i=0; i<TSIZE; i++){
        //int posicao = sondagemLinear(i, chaveDivisao(chave));
        //int posicao = duploHash(chaveDivisao(chave), i);
        int posicao = h2(chave, i);

        if(T->tabela[posicao] == NULL){                    
            T->tabela[posicao] = chave;
            incluido = true;
            break;
        }
    }

    return incluido;
}



void removerEndAberto(THash* T, int chave){ 
    for(int i=0; i<TSIZE; i++){
        //int posicao = sondagemLinear(i, chaveDivisao(chave));
        int posicao = h2(h1(chave), i);

        if(T->tabela[posicao] != NULL){
            if(T->tabela[posicao] == chave){
                T->tabela[posicao] = NULL;
                break;
            }
        }
    }
}

bool buscarEndAberto(THash* T, int chave){
bool encontrado = false;

    for(int i=0; i<TSIZE; i++){
        //int posicao = sondagemLinear(i, chaveDivisao(chave));
        int posicao = h2(h1(chave), i);

        if(T->tabela[posicao] != 0){
            if(T->tabela[posicao] == chave){
                encontrado = true;
                break;
            }
        }
    }

    return encontrado;
}

int main(){

    THash* t = new THash;

    int val = 0;

    int v = int(35.555);

    do{
        cout << "Digite o valor para inserir: ";
        cin >> val;
        if(val>-1)
            if(!inserirEndAberto(t,val)){
                cout << "Tabela cheia" << endl;
                break;
            }

    }while ( val >-1);

    cout << "Digite o valor que deseja remover: ";
    cin >> val;

    removerEndAberto(t, val);

    for(int i=0;i<TSIZE;i++){
        cout << "Tabela[" << i << "]: ";

        if(t->tabela[i] == NULL)
            cout << "vazio";
        else
            cout << t->tabela[i] << ";";
        
        cout << endl;
    }

    cout <<endl;

    cout << "Digite o valor que deseja procurar: ";
    cin >> val;

    if(buscarEndAberto(t,val))
        cout << "Valor encontrado!";
    else
        cout << "Valor não encontrado!";

    cout << endl;
    return 0;
}