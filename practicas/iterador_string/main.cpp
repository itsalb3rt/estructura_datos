/**
* Los iteradores mueren luego se utilizan
* no puedes comparar un string con un iterador
* se puede comparar caracteres (comillas simples) con iteradores
**/
#include <iostream>

using namespace std;

int main()
{
    string cad;
    cad = "Si es de la UASD, es bueno";
    string::iterator iter1(cad.begin()),iter2(cad.end());
    cout<<endl <<endl;
    //Normal
    cout<<"Normal" <<endl;
    while(iter1 != iter2)
    {
        cout<<*iter1;
        ++iter1;
    }
    cout<<endl <<endl;

    //Inverso
    string::iterator iter3(cad.begin()),iter4(cad.end());
    cout<<"Inverso" <<endl;
    while(iter3 != iter4)
    {
        --iter4;
        cout<<*iter4;

    }
    cout<<endl <<endl;
    //palabra por palabra
    string::iterator iter5(cad.begin()),iter6(cad.end());
    cout<<"Palabra por palabra" <<endl;
    while(iter5 != iter6)
    {
        if(*iter5 == ' '){
            cout<<endl;
        }else{
            cout<<*iter5;
        }
        iter5++;
    }
    cin.get();

    return 0;
}
