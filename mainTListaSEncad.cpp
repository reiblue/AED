#include <string>
#include "TListaSEncad.cpp"
#include <iostream>

//using namespace drozdek;
using namespace std;

int main()
{

    TListaSEncad *list = new TListaSEncad() ;

    list->InserePrimeiro(10);

    list->Inicio();

    list->Atribui(20);

    list->InsereUltimo(30);
    list->InsereUltimo(40);
    list->InsereUltimo(50);
    list->InsereUltimo(60);
    list->InsereUltimo(70);
    list->InsereUltimo(80);
    list->InsereUltimo(90);
    list->InsereUltimo(100);

    list->InserePrimeiro(10);
    list->InserePrimeiro(5);
    list->InserePrimeiro(1);

    list->EliminaPrimeiro();
    list->Elimina();
    list->Elimina(20);


    cout << list->Consulta() << endl;

    

    cout << "----------------------------------------" << endl;
    cout << endl << endl << "Fim de programa" << endl;
    cout << "#########################################" << endl << endl;
    return 0;
}