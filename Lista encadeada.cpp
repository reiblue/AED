#include <iostream>
//#include <stblib.h>
#include <string>
#include <vector>

using namespace std;

typedef struct
{
   int cod;
   int quant;
   string nome;
}Lista;



int main()
{

    vector<int> lis = {0,1,2,3,4,5,6,7,8,9};

    for(int i; i<lis.size(); i++)
    {
        cout << "i: " << lis[i] << "\t";
    }
        cout << "Teste" << endl;

    return 1;
}

