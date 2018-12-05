/**
* Se incluyo la clase string y algorithm porque
* no hay forma de hacerlo sin ayuda de esto, al menos no una forma
* corta.
**/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
* Esta funcion resuleve el lio, recibe 2 cadenas y iterra sobre ellas, realiza
* una que otra operacion matematica distinta que la suma
* pero es algo que no es dificil de entender
**/
string suma(string cadena1, string cadena2)
{
    //algunas variables
    string resultado = "";
    int n1 = cadena1.length(), n2 = cadena2.length();
    int diff = n2 - n1;
    int restante = 0;

// Verificano que cadena2 es mas grande
    if (cadena1.length() > cadena2.length())
        swap(cadena1, cadena2);

// Calcula la longitud de ambas cadenas


// Iterando desde el final de la cadena, osea al revez el for
    for (int i=n1-1; i>=0; i--)
    {
// Hacer matemáticas escolares, computar la suma de
// dígitos actuales y las guarda
        int sum = ((cadena1[i]-'0') + (cadena2[i+diff]-'0') + restante);
        resultado.push_back(sum%10 + '0');
        restante = sum/10;
    }

// Agrega los digitos restantes de cadena2 []
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((cadena2[i]-'0')+restante);
        resultado.push_back(sum%10 + '0');
        restante = sum/10;
    }

// agrega lo que falta al numero
    if (restante)
        resultado.push_back(restante+'0');

// cadena de resultados inversa
    reverse(resultado.begin(), resultado.end());

    return resultado;
}
int main()
{
    string numero1,numero2 ;
    cout<<"Digite 1 numero: " <<endl;
    cin>>numero1;
    cout<<"Digite otro numero: "<<endl;
    cin>>numero2;
    cout <<"El resultado es: "<< suma(numero1, numero2);
    return 0;
}

