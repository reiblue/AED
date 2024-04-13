#include <iostream>
#include "TListCont.cpp"

int main()
{

    TListCont list(10);

    list.PrintList();

    list.InsereUlt(1);
    list.Inserek(0,2);
    list.Inserek(0,3);
    list.Inserek(0,4);
    list.Inserek(0,5);
    list.Inserek(0,6);
    list.Inserek(0,7);
    list.Inserek(0,8);
    list.Inserek(0,9);
    list.Inserek(0,10); 
    

    list.PrintList();

    list.EliminaUlt();
    list.Eliminak(0);
    

    list.PrintList();

    cout << "Valor na posição 5: " << list.Consulta(5) << endl;

    cout << "O valor 2 está no indice : " << list.BuscaIndice(2) << endl;
 

    cout << endl << endl;

    return 0;
}