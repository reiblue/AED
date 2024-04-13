#include "No.cpp"

class TListaSEncad{
private: 
    /// @brief Próximo nó
    No *it; //ponteiro auxiliar para percorrer a lista

    /// @brief Primeiro nó
    No *primeiro; // ponteiro para o primeiro No da lista
public:
    

    /// @brief Construtor
    TListaSEncad();

    /// @brief Destrutor
    ~TListaSEncad();

    
    /// @brief Inseri o primeiro valor
    /// @param val 
    void InserePrimeiro(float val);

    void InsereUltimo(float val);

    void Elimina();

    void Elimina(float valor);

    void EliminaPrimeiro();

    int Rotina_Erro(int valor);

    /// @brief 
    /// @return 
    float Consulta();

    /// @brief 
    /// @param val 
    void Atribui(float val);

    /// @brief operações para percorrer a lista,
    /// @param val 
    /// @return 
    bool Busca(float val);
    
    /// @brief coloca o ponteiro it no início
    void Inicio(); // 


    /// @brief avança o ponteiro it
    void ProximoNo(); // 


    /// @brief verifica se it está no final
    /// @return 
    bool FimDaLista(); // 

    int teste;
    
};