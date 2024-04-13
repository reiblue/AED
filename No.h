class No
{
    private:
        float info; // informação real do No
        No *prox; // ponteiro para o próximo No
    public:
        No();
        float consultaInfo();
        No* consultaProx();
        void atribInfo(float val);
        void atribProx(No *p);
        void elimina();
        ~No();
};