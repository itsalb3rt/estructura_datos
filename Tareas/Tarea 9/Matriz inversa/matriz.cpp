/**
* Albert Eduardo Hidalgo Taveras
* Matrices
*/
#include<iostream>
using namespace std;

main() {
    int A1,B1,DP,DS,total,digagonal_principal;
    int A2,B2;
    int ResDia;
    int OpcMen;
    string a;

    do {

        cout<<endl;
        cout<<"[1] inversa de una matriz 2*2 y el determinante"<<endl;
        cout<<endl;
        cout<<"[0] Salir"<<endl;

        while(!(cin>>OpcMen)) {

            cin>>a;
            cout<<"Esta opcion no es valida" <<endl;
            cout<<"Diquite la opcion deceada: "<<endl;
        }

        switch(OpcMen) {

        case 1:
            cout<<"Digite la primera fila (A1,B1)" <<endl;
            cout<<endl;
            cin>>A1>>B1;
            cout<<"Diguite la segunda fila (A2,B2)"<<endl;
            cin>>A2>>B2;

            DP=A1*B2;
            DS=A2*B1;

            ResDia=DP-DS;

            if(ResDia==0)
                cout<<"No tiene inversa"<<endl;
            else {
                total=A1/ResDia;
                A1=B2/ResDia;
                B2=total;
                A2=(-A2)/ResDia;
                B1=(-B1)/ResDia;
                cout<<"============================\n";
                cout<<"La inversa de esta matriz es\n";
                cout<<"=============================\n";
                cout<<A1<<"  "<<B1<<endl<<endl;
                cout<<A2<<"  "<<B2<<endl<<endl;

                digagonal_principal=+A1+B2;
                cout<<"La suma de la Diagonal Principal es: "<<digagonal_principal;
                cout<<endl;
            }
            break;

        }
    } while(OpcMen!=0);

    return 0;
}




