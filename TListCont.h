class TListCont{
private:
    /// @brief capacidade máxima de elementos do vetor em inteiro
    int m; 

    /// @brief índice do ultimo Nó da lista em inteiro
    int ultimo;

    /// @brief vetor que armazena a lista em float
    float *X; 

public:
    TListCont(int tam);
    float Consulta(int k);
    void Atribui(int k, float val);
    void Inserek(int k, float val);//insere antes de x k
    void InsereUlt(float val); // insere ultimo no
    void Eliminak(int k); // elimina No x k
    void EliminaUlt(); // elimina ultimo No
    void PrintList();
    int BuscaIndice(float k);
    ~TListCont();

};