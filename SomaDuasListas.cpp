#include <iostream>
#include "ListaDuplamenteEncadeada.cpp"
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{

    LDE *lista1 =  new LDE;
    LDE *lista2 = new LDE;
/*
    char* str1 = "141";
    int res1 = atoi(str1);
    cout << "atoi(" << str1 << ") is " << res1 << "\n";
*/

    //int valorTeste = pow(10.0, 3.0);

    //cout << "10^3: " << valorTeste << endl;
    
    for(int i=1; i<=5; i++)
        inseirLDE(i, lista1);
    
    for(int i=1; i<=7; i++)
        inseirLDE(i, lista2);

    
    int L3 = NULL;
    int decimal = 0;

    while(lista1 != NULL || lista2 != NULL)
    {
        int L1 = NULL, L2 = NULL;

        if(lista1 != NULL)
        {
            L1 = lista1->info;
            lista1 = lista1->prox;
        }
            
        
        if(lista2 != NULL)
        {
            L2 = lista2->info;
            lista2 = lista2->prox;
        }
            

        if(L1 != NULL && L2 != NULL)
        {
            int valor = 0;
            valor = (L1 + L2) *  pow(10, decimal);
            L3 += valor;
        }
            
        else
        {
            if(L2 != NULL)
            {
                L3 += L2 * pow(10, decimal);
            }else if(L1 != NULL)
            {
                L3 += L1 * pow(10, decimal);
            }
        }

         
        
        decimal++;
    }

    cout << "Valor soma: " << L3 << endl;



    return 0;
}