/** Albert E Hidalgo Taveras
*** Matrices */
#include <iostream>

using namespace std;

void BorraPantalla() {
    system ("cls");
};
void pausar_ejecucion() {
    system("pause");
}

void calcular_matriz_inversa(float (&matriz)[2][2],float (&matriz_inversa)[2][2],float &determinante) {
    determinante = (matriz[0][0] * matriz[1][1]) - (matriz[1][0] * matriz[0][1]) ; //(A1 x B2) - (B1 x A2)
    cout<<"\nDeterminante: "<<determinante <<"\n\n";

    if(determinante != 0) {
        cout<<"Matriz normal" <<endl;
        cout <<"| " <<matriz[0][0]<<" | "<<matriz[0][1] <<" |" << endl; //A1 | B1
        cout <<"| " <<matriz[1][0]<<" | "<<matriz[1][1] <<" |" << endl; //A2 | B2

        matriz_inversa[0][0]= matriz[1][1];
        matriz_inversa[0][1] = matriz[0][1] * -1;
        matriz_inversa[1][0] = matriz[1][0] * -1;
        matriz_inversa[1][1]= matriz[0][0];

        cout<<"Matriz Inversa" <<endl;
        cout <<"| " <<matriz_inversa[0][0] /determinante <<" | " <<matriz_inversa[0][1]  /determinante<<" |" << endl;
        cout <<"| " <<matriz_inversa[1][0]  /determinante <<" | " <<matriz_inversa[1][1]  /determinante<<" |" << endl;

    } else
        cout<<"La matriz no tiene inversa ya que la determinante es 0"<<endl;
}
void suma_diagonal_principal(float (&matriz)[2][2]) {
    cout<<"Suma diagonal principal" <<endl;
    cout <<"| " <<matriz[0][0]<<" | "<<matriz[0][1] <<" |" << endl; //A1 | B1
    cout <<"| " <<matriz[1][0]<<" | "<<matriz[1][1] <<" |" <<"\n\n"; //A2 | B2
    cout<<"Suma diagonal principal: " <<matriz[0][0] + matriz[1][1] <<endl;
}
void suma_diagonal_segundaria(float (&matriz)[2][2]) {
    cout<<"Suma diagonal secundaria" <<endl;
    cout <<"| " <<matriz[0][0]<<" | "<<matriz[0][1] <<" |" << endl; //A1 | B1
    cout <<"| " <<matriz[1][0]<<" | "<<matriz[1][1] <<" |" << "\n\n"; //A2 | B2
    cout<<"Suma diagonal secundaria: " <<matriz[1][0] + matriz[0][1] <<endl;
}

int menu_principal() {
    int opcion_menu;
    cout<<"1 -> SUMA DIAGONAL PRINCIPAL ( A1 + B2)" << endl;
    cout<<"2 -> SUMA DIAGONAL SECUNDARIA ( A2 + B1)" << endl;
    cout<<"3 -> SUMAR PARES" << endl;
    cout<<"4 -> SUMAR IMPARES" << endl;
    cout<<"5 -> SUMAR NUMEROS PRIMOS" << endl;
    cout<<"6 -> MATRIZ INVERSA" << endl;
    cout<<"0 -> SALIR" << endl;
    cin>>opcion_menu;
    return opcion_menu;
}

int main() {
    float matriz[2][2],matriz_inversa[2][2],determinante = 0,suma = 0,pares= 2;
    int opcion_menu;


    cout<<"\n\n| A1 | B1 |" <<endl;
    cout<<"| A2 | B2 |\n\n";

    cout<<"Digite el valor para A1: ";
    cin>>matriz[0][0];
    if((matriz[0][0] % pares) == 0) suma += matriz[0][0];
    cout<<"Digite el valor para B1: ";
    cin>>matriz[0][1];
    if((matriz[0][1] % pares) == 0) suma += matriz[0][0];
    cout<<"Digite el valor para A2: ";
    cin>>matriz[1][0];
    if((matriz[1][0] % pares) == 0) suma += matriz[0][0];
    cout<<"Digite el valor para B2: ";
    cin>>matriz[1][1];
    if((matriz[1][1] % pares) == 0) suma += matriz[0][0];

    do {
        BorraPantalla();
        opcion_menu = menu_principal();
        switch(opcion_menu) {
        case 1:
            BorraPantalla();
            suma_diagonal_principal(matriz);
            pausar_ejecucion();
            break;
            case 2:
            BorraPantalla();
            suma_diagonal_segundaria(matriz);
            pausar_ejecucion();
            break;
            case 3:
                cout<<"La suma de los pares es: " <<suma;
                break;
        case 6:
            BorraPantalla();
            calcular_matriz_inversa(matriz,matriz_inversa,determinante);
            pausar_ejecucion();
            break;
        }
    } while(opcion_menu != 0);

    return 0;
}
