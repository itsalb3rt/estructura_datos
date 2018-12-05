/**
* Solo se utilizaron elementos de la libreria estandar de C++
* Albert E. Hidalgo Taveras
* 02.08.2018
*  numeros.cpp
**/
#include<iostream>
#include<string>
#include<sstream>


using namespace std;

//utilitario
/**
* Borrar de la consola lo que este encima de la funcion
**/
void BorraPantalla(){
    //Esto solo funciona en windows
    system ("cls");
};
/**
* se utiliza generalmente para que el usuario vea el resultado
* de lo que ha hecho y indicarle que para continuar pulse una tecla
**/
void pausar_ejecucion()
{
    //Esto solo funciona en windows
    system("pause");
}

//fin utilitario

// clase manejo de la cadena
class Cadena
{
private:
    string cadena_original;
    string cadena_esteroides;

public:
    Cadena(string);
    void normal();
    void invertido();
    void vocales();
    void consonantes();
    void mayuscula();
    void minuscula();
};

Cadena::Cadena(string _cadena)
{
    cadena_original = _cadena;
}

void Cadena::normal()
{
    cout<<"Cadena normal" <<endl;
    cout<<cadena_original <<endl;

}
/**
* Un ciclo en reversa para invertir el texto
**/
void Cadena::invertido()
{
    int tamano = cadena_original.length();
    string cadena_invertida;

    cadena_esteroides = cadena_original;

    for(int i= tamano; i>0; i--)
    {
        cadena_invertida =cadena_invertida+cadena_esteroides.substr((i-1), 1);
    }
    cout<<"Cadena invertida" <<endl;
    cout<<cadena_invertida <<endl;

}
/**
* Compara cada caracter para encontrar las NO vocales (consonantes)
**/
void Cadena::consonantes()
{
    int tamano = cadena_original.length();
    cadena_esteroides = cadena_original;
    cout<<"Consonantes de la cadena: ";
    for(int i = 0; i < tamano; i++)
    {
        if(tolower(cadena_esteroides[i]) != 'a' && tolower(cadena_esteroides[i]) != 'e' && tolower(cadena_esteroides[i]) != 'i' && tolower(cadena_esteroides[i]) != 'o' && tolower(cadena_esteroides[i]) != 'u')
        {
            cout<<cadena_esteroides[i];
        }
    }
    cout<<"\n";
}
/**
* Compara cada caracter durante el ciclo para ver que este
* dentro de las vocales
**/
void Cadena::vocales()
{
    int tamano = cadena_original.length();
    cout<<"vocales de la cadena: ";
    for(int i = 0; i < tamano; i++)
    {
        if(tolower(cadena_original[i]) == 'a' || tolower(cadena_original[i]) == 'e' || tolower(cadena_original[i]) == 'i' || tolower(cadena_original[i]) == 'o' || tolower(cadena_original[i]) == 'u')
        {
            cout<<cadena_original[i];
        }
    }
    cout<<"\n";
}

void Cadena::mayuscula()
{
    cadena_esteroides = cadena_original;
    for(int i = 0; i < cadena_original.length(); i++)
    {
        cadena_esteroides[i] = toupper(cadena_esteroides[i]);
    }
    cout<<"Cadena mayuscula" <<endl;
    cout<< cadena_esteroides <<endl;
}

void Cadena::minuscula()
{
    cadena_esteroides = cadena_original;
    for(int i = 0; i < cadena_esteroides.length(); i++)
    {
        cadena_esteroides[i] = tolower(cadena_esteroides[i]);
    }
    cout<<"Cadena minuscula" <<endl;
    cout<< cadena_esteroides <<endl;
}
//fin de los metodos de la clase cadena

/**
* Muestra las opciones diponibles del menu y retorna la
* opcion deseada al usuario, se utiliza para pasarle la
* opcion a un ciclo que mantiene el programa en ejecucion
**/
int menu(string _cadena)
{
    int opcion_menu;
    cout<<"\t\t Elija una opcion para realizar sobre la cadena: " + _cadena << endl;
    cout<<"1  Normal" << endl;
    cout<<"2  Inversa" << endl;
    cout<<"3  Vocales" << endl;
    cout<<"4  Consonantes" << endl;
    cout<<"5  Mayuscula" << endl;
    cout<<"6  Minuscula" << endl;
    cout<<"--------------" << endl;
    cout<<"0  Salir" << endl;
    cin>>opcion_menu;
    return opcion_menu;

}
/**
* Obtiene la cadena escrita por el usuario, retorna dicha cadena
**/
string obtener_cadena()
{
    string cadena;
    cout<<"Ingrese una cadena de texto: ";
    getline(cin,cadena); //Getline para procesar varias palabras
    return cadena;
}

int main()
{
    int opcion_menu;
    string cadena;

    cadena = obtener_cadena();

    //Clase para manejar la cadena
    Cadena nueva_cadena = Cadena(cadena);

    //Esconu, no estandar pero es solo visual
    BorraPantalla ();

    do
    {
        BorraPantalla ();
        opcion_menu = menu(cadena);
        //Opciones del menu
        switch(opcion_menu)
        {
        case 1:
            nueva_cadena.normal();
            pausar_ejecucion();
            break;
        case 2:
            nueva_cadena.invertido();
            pausar_ejecucion();
            break;
        case 3:
            nueva_cadena.vocales();
            pausar_ejecucion();
            break;
        case 4:
            nueva_cadena.consonantes();
            pausar_ejecucion();
            break;
        case 5:
            nueva_cadena.mayuscula();
            pausar_ejecucion();
            break;
        case 6:
            nueva_cadena.minuscula();
            pausar_ejecucion();
            break;
        }
    }
    while(opcion_menu != 0);

    //fin
    cin.ignore();
    return 0;
}
