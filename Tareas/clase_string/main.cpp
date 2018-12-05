/**
* Albert Eduardo Hidalgo Taveras
* 16/09/2018

Ver si  existen palabras palindromas
**/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//utilitario
/**
* Borrar de la consola lo que este encima de la funcion
**/
void BorraPantalla()
{
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

class Cadena
{
private:
    string cadena;
    string voltear_palabra(string _palabra);

public:
    Cadena(string);
    string getCadena();
    void normal();
    void vocales();
    void consonantes();
    int cantidad_palabras();
    void cantidad_vocales();
    void cantidad_consonantes();
    void cantidad_digitos();
    void inverso();
    void cantidad_mayusculas();
    void cantidad_minusculas();
    void cantidad_espacios();
    void palabras_vertical();
    void inverso_por_palabra();
    void palindromo();
    void palabra_mas_larga();
    void palabras_repetidas();
};
Cadena::Cadena(string _cadena)
{
    cadena = _cadena;
}
string Cadena::getCadena()
{
    return cadena;
}

string Cadena::voltear_palabra(string _palabra)
{
    string::iterator t;
    string palabra;
    for ( t = (_palabra.end()); t!= (_palabra.begin() - 1); --t)
        palabra += *t;
    return palabra;
}

void Cadena::cantidad_digitos()
{
    cout<<"Cantidad Digitos: " <<cadena.length() <<endl;
}

/**
* Compara cada caracter para encontrar las NO vocales (consonantes)
**/
void Cadena::consonantes()
{
    int tamano = cadena.length();
    string cadena_esteroides = cadena;
    cout<<"Consonantes de la cadena: ";
    for(int i = 0; i < tamano; i++)
    {
        if(tolower(cadena_esteroides[i]) != 'a' && tolower(cadena_esteroides[i]) != 'e' && tolower(cadena_esteroides[i]) != 'i' && tolower(cadena_esteroides[i]) != 'o' && tolower(cadena_esteroides[i]) != 'u' && cadena_esteroides[i] != ' ' )
        {
            cout<<cadena_esteroides[i];
        }
    }
    cout<<"\n";
}

void Cadena::inverso()
{
    string::iterator t;
    cout<<"\n Cadena invertida \n";
    for ( t = (cadena.end()); t!= (cadena.begin() - 1); --t)
        cout << *t;
    cout << '\n';
}

/**
* Compara cada caracter durante el ciclo para ver que este
* dentro de las vocales
**/
void Cadena::vocales()
{
    int tamano = cadena.length();
    cout<<"vocales de la cadena: ";
    for(int i = 0; i < tamano; i++)
    {
        if(tolower(cadena[i]) == 'a' || tolower(cadena[i]) == 'e' || tolower(cadena[i]) == 'i' || tolower(cadena[i]) == 'o' || tolower(cadena[i]) == 'u')
        {
            cout<<cadena[i];
        }
    }
    cout<<"\n";
}

void Cadena::cantidad_vocales()
{
    int tamano = cadena.length(),contador = 0;
    cout<<"Cantidad de vocales: ";
    for(int i = 0; i < tamano; i++)
    {
        if(tolower(cadena[i]) == 'a' || tolower(cadena[i]) == 'e' || tolower(cadena[i]) == 'i' || tolower(cadena[i]) == 'o' || tolower(cadena[i]) == 'u')
        {
            contador++;
        }
    }
    cout<<contador;
    cout<<"\n";
}
void Cadena::cantidad_consonantes()
{
    int tamano = cadena.length(),contador=0;
    string cadena_esteroides = cadena;
    cout<<"Cantidad de consonantes: ";
    for(int i = 0; i < tamano; i++)
    {
        if(tolower(cadena_esteroides[i]) != 'a' && tolower(cadena_esteroides[i]) != 'e' && tolower(cadena_esteroides[i]) != 'i' && tolower(cadena_esteroides[i]) != 'o' && tolower(cadena_esteroides[i]) != 'u' && cadena_esteroides[i] != ' ')
        {
            contador++;
        }
    }
    cout<<contador;
    cout<<"\n";
}
int Cadena::cantidad_palabras()
{
    string::iterator t;
    int contador = 1;//Se inicializa en 1 porque la ultima palabra no la contaria
    for ( t = cadena.begin(); t!= cadena.end(); ++t)
    {
        if(*t == ' ')
        {
            contador++;
        }
    }
    return contador;
}

void Cadena::cantidad_mayusculas()
{
    string::iterator t;
    int contador = 0;
    for ( t = cadena.begin(); t!= cadena.end(); ++t)
    {
        if(*t >='A' && *t <= 'Z')
        {
            contador++;
        }
    }
    cout<<"Cantidad de mayusculas: "<<contador <<endl;
}
void Cadena::cantidad_minusculas()
{
    string::iterator t;
    int contador = 0;
    for ( t = cadena.begin(); t!= cadena.end(); ++t)
    {
        if(*t >='a' && *t <= 'z')
        {
            contador++;
        }
    }
    cout<<"Cantidad de mayusculas: "<<contador <<endl;
}

void Cadena::cantidad_espacios()
{
    string::iterator t;
    int contador = 0;
    for ( t = cadena.begin(); t!= cadena.end(); ++t)
    {
        if(*t == ' ')
        {
            contador++;
        }
    }
    cout<<"Cantidad de espacios: "<<contador <<endl;
}

void Cadena::palabras_vertical()
{
    string::iterator t;

    cout<<"Palabras en vertical" <<endl;
    for ( t = cadena.begin(); t!= cadena.end(); ++t)
    {
        if(*t == ' ')
        {
            cout<<endl;
        }
        else
        {
            cout<<*t;
        }
    }
    cout<<endl;
}

void Cadena::inverso_por_palabra()
{
    string::iterator t;
    string palabra,copia_cadena;
    copia_cadena = cadena;
    copia_cadena.insert(cadena.length()," ");

    for ( t = copia_cadena.begin(); t!= copia_cadena.end(); ++t)
    {
        if(*t == ' ')
        {
            cout<<Cadena::voltear_palabra(palabra);
            palabra="";
        }
        else
        {
            palabra += *t;
        }
    }
    cout<<endl;
}

void Cadena::palindromo()
{
    int contador = 0;
    string::iterator t;
    string palabra,copia_cadena,palabra_alrevez,cadena_geniona,cadena_inversa;
    copia_cadena = cadena;
    copia_cadena.insert(cadena.length()," ");


    for ( t = copia_cadena.begin(); t!= copia_cadena.end(); ++t)
    {
        if(*t == ' ')
        {
            palabra_alrevez = Cadena::voltear_palabra(palabra);
            palabra_alrevez.replace(0,1,"");
            if(palabra == palabra_alrevez && palabra.length() > 1)
            {
                cout<<palabra <<" Es palindroma" <<endl;
                contador++;
            }
            palabra_alrevez = "";
            palabra="";
        }
        else
        {
            palabra += *t;
        }
    }

    copia_cadena = "";

    //Removiendo el espacio que se agrega al inicio
    copia_cadena.replace(0,1,"");

    if(copia_cadena == cadena)
    {
        cout<<"La oracion es palindroma: " <<cadena <<endl;
    }
    cout<<"Total de: " <<contador << " palindromas" <<endl;

}

void Cadena::palabra_mas_larga()
{
    string::iterator t;
    string palabra,copia_cadena,palabra_larga;
    int cantidad_caracteres = 0;
    copia_cadena = cadena;
    copia_cadena.insert(cadena.length()," ");

    for ( t = copia_cadena.begin(); t!= copia_cadena.end(); ++t)
    {
        if(*t == ' ')
        {
            if(palabra.length() > cantidad_caracteres)
            {
                palabra_larga = palabra;
                cantidad_caracteres = palabra.length();
            }
            palabra="";
        }
        else
        {
            palabra += *t;
        }
    }
    cout<<"Palabra mas larga: " <<palabra_larga <<" con " <<cantidad_caracteres << " caracteres." <<endl;
}

void Cadena::palabras_repetidas()
{
    vector<string> palabras_cadena;
    vector<int> cantidad_palabras;

    int contador = 0;
    string::iterator t;
    string palabra,copia_cadena,palabra_alrevez;
    copia_cadena = cadena;
    copia_cadena.insert(cadena.length()," ");



    for ( t = copia_cadena.begin(); t!= copia_cadena.end(); ++t)
    {
        if(*t == ' ')
        {
            palabras_cadena.push_back(palabra);
            palabra="";
        }
        else
        {
            palabra += *t;
        }
    }
    for(int i = 0; i<palabras_cadena.size(); i++){
        for(int j = 0; j < palabras_cadena.size(); j++){
            if(palabras_cadena[i] == palabras_cadena[j]){
                contador++;
            }
        }
        cantidad_palabras.push_back(contador);
        contador = 0;
    }

    for(int x = 0; x < cantidad_palabras.size(); x++){
        if(cantidad_palabras[x] > 1){
            cout<<palabras_cadena[x] <<" - "<<cantidad_palabras[x] <<endl;
        }
    }


}
/**
* Muestra las opciones diponibles del menu y retorna la
* opcion deseada al usuario, se utiliza para pasarle la
* opcion a un ciclo que mantiene el programa en ejecucion
**/
int menu()
{
    int opcion_menu;
    cout<<"\t\t Elija una opcion para realizar sobre la cadena"<< endl;
    cout<<"1  Normal" << endl;
    cout<<"2  Mostrar vocales" << endl;
    cout<<"3  Mostrar solo consonantes" << endl;
    cout<<"4  Cantidad palabras" << endl;
    cout<<"5  Cantidad vocales" << endl;
    cout<<"6  Cantidad consonantes" << endl;
    cout<<"7  Cantidad digitos" << endl;
    cout<<"8  Mostrar cadena inverso" << endl;
    cout<<"9  Cantidad mayusculas" << endl;
    cout<<"10  Cantidad minusculas" << endl;
    cout<<"11 Cantidad espacios" << endl;
    cout<<"12 Palabras en vertical" << endl;
    cout<<"13 Palabras inverso" << endl;
    cout<<"14 Palabras Palindromo" << endl;
    cout<<"15 Palabras mas larga" << endl;
    cout<<"16 Palabras repetidas" << endl;
    cout<<"--------------" << endl;
    cout<<"0  Salir" << endl;
    cin>>opcion_menu;
    return opcion_menu;

}
int main()
{
    int opcion_menu;

    //Clase para manejar la cadena
    Cadena nueva_cadena = Cadena("asi somos y somos asi en estos tiempos somos");

    //Esconu, no estandar pero es solo visual
    BorraPantalla ();

    do
    {
        BorraPantalla ();
        opcion_menu = menu();
        //Opciones del menu
        switch(opcion_menu)
        {
        case 1:
            cout<<nueva_cadena.getCadena() <<endl;
            pausar_ejecucion();
            break;
        case 2:
            nueva_cadena.vocales();
            pausar_ejecucion();
            break;
        case 3:
            nueva_cadena.consonantes();
            pausar_ejecucion();
            break;
        case 4:
            cout<<endl <<"La cadena tiene: " <<nueva_cadena.cantidad_palabras() <<" palabras" <<endl;
            pausar_ejecucion();
            break;
        case 5:
            nueva_cadena.cantidad_vocales();
            pausar_ejecucion();
            break;
        case 6:
            nueva_cadena.cantidad_consonantes();
            pausar_ejecucion();
            break;
        case 7:
            nueva_cadena.cantidad_digitos();
            pausar_ejecucion();
            break;
        case 8:
            nueva_cadena.inverso();
            pausar_ejecucion();
            break;
        case 9:
            nueva_cadena.cantidad_mayusculas();
            pausar_ejecucion();
            break;
        case 10:
            nueva_cadena.cantidad_minusculas();
            pausar_ejecucion();
            break;
        case 11:
            nueva_cadena.cantidad_espacios();
            pausar_ejecucion();
            break;
        case 12:
            nueva_cadena.palabras_vertical();
            pausar_ejecucion();
            break;
        case 13:
            nueva_cadena.inverso_por_palabra();
            pausar_ejecucion();
            break;
        case 14:
            nueva_cadena.palindromo();
            pausar_ejecucion();
            break;
        case 15:
            nueva_cadena.palabra_mas_larga();
            pausar_ejecucion();
            break;
        case 16:
            nueva_cadena.palabras_repetidas();
            pausar_ejecucion();
            break;
        }
    }
    while(opcion_menu != 0);

    return 0;
}
