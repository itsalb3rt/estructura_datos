/**
* Solo se utilizaron elementos de la libreria estandar de C++
* Albert E. Hidalgo Taveras
* 01.08.2018
* leer_cadena.cpp
**/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


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
/**
* Se creo una clase para el procesamiento de los numeros
* de esta manera se tiene todo encapsulado
**/
class Numero
{
private:
    vector<int> numeros;
    void ordenar();

public:
    int numero;
    void digitar_numeros();
    void normal();
    void inversa();
    void pares();
    void impares();
    void promedio();
    void inverso_negativo();
    bool buscar(int numero_buscar);
    void borrar();
    //Setters y getters
    void setNumero(int _numero);

};

//Setters

void Numero::setNumero(int _numero)
{
    numeros.push_back(_numero);
}

//Otros metodos
void Numero::digitar_numeros()
{
    do
    {
        cout<<"Digite un numero y pulse enter, introduzca 0 para salir: ";
        cin>>numero;

        //de no condicionar esto insertara el 0
        if(numero != 0)
        {
            setNumero(numero);
        }

    }
    while(numero != 0);

}

void Numero::normal()
{
    cout<<"Numeros ingresados" <<endl;
    ordenar();
    if(numeros.size() != 0)
    {
        for(int i = 0; i<numeros.size(); i++)
        {
            cout<<i <<" -> "<<numeros[i]<<endl;
        }
    }
    else
        cout <<"No ha digitado ningun numero" <<endl;

}

void Numero::pares()
{
    cout<<"Numeros pares" <<endl;
    for(int i = 0; i<numeros.size(); i++)
    {
        if(numeros[i]%2 == 0 )
            cout<<i <<" -> "<<numeros[i]<<endl;
    }
}

void Numero::impares()
{
    cout<<"Numeros impares" <<endl;
    for(int i = 0; i<numeros.size(); i++)
    {
        if(numeros[i]%2 != 0 )
            cout<<i <<" -> "<<numeros[i]<<endl;
    }
}

void Numero::promedio()
{
    int suma;

    for(int i = 0; i<numeros.size(); i++)
    {
        suma = suma + numeros[i];
    }
    cout<< "El promedio es: " <<suma / numeros.size();

}
/**
* Elimina un item del listado por su indice
**/
void Numero::borrar()
{
    string confirmacion;
    int numero_borrar;

    cout<<"Digite el numero que desea borrar: ";
    cin>>numero_borrar;

    cout<<"Escriba 'si' para borrar " <<numero_borrar <<" de la lista, o escriba 'no' para cancelar: ";
    cin>>confirmacion;

    if(confirmacion == "si")
    {
        if(buscar(numero_borrar))
        {
            vector<int> :: iterator index;
            index=lower_bound(numeros.begin(),numeros.end(),numero_borrar);
            numeros.erase(numeros.begin() + (index - numeros.begin()));
            cout<<"Borrado" <<endl;
        }
        else
        {
            cout<<"Este numero no existe en la lista" <<endl;
        }
    }
}
/**
* Ordena el vector de menor a mayor,
* esto se utiliza para la busqueda binaria
*
* private
**/
void Numero::ordenar()
{

    //Ordenar vector
    sort( numeros.begin(), numeros.end() );
}
/**
* Busqueda binaria
* Return boolean
**/
bool Numero::buscar(int numero_buscar)
{
    //Para realizar la busqueda binaria los items deben estar odenados
    ordenar();

    if(std::binary_search (numeros.begin(), numeros.end(), numero_buscar))
        return true;
    else
        return false;

}

int menu()
{
    int opcion_menu;
    cout<<"\t\t Elija una opcion"<< endl;
    cout<<"1  Insertar numeros" << endl;
    cout<<"2  Normal" << endl;
    //cout<<"3  Inverso" << endl;
    cout<<"4  Pares" << endl;
    cout<<"5  Impares" << endl;
    cout<<"6  Promedio" << endl;
    //cout<<"7  Inverso negativo" << endl;
    cout<<"--------------" << endl;
    cout<<"8 Buscar numero"<<endl;
    cout<<"9 Borrar numero"<<endl;
    cout<<"--------------" << endl;
    cout<<"0  Salir" << endl;
    cin>>opcion_menu;
    return opcion_menu;

}

int main()
{
    int opcion_menu;
    int numero;
    //intancia clase nuemros
    Numero nuevo_numero = Numero();

    do
    {
        BorraPantalla();

        opcion_menu = menu();
        //Opciones del menu
        switch(opcion_menu)
        {
        case 1:
            nuevo_numero.digitar_numeros();
            pausar_ejecucion();
            break;
        case 2:
            nuevo_numero.normal();
            pausar_ejecucion();
            break;
        case 3:
            pausar_ejecucion();
            break;
        case 4:
            nuevo_numero.pares();
            pausar_ejecucion();
            break;
        case 5:
            nuevo_numero.impares();
            pausar_ejecucion();
            break;
        case 6:
            nuevo_numero.promedio();
            pausar_ejecucion();
            break;
        case 8:
            cout<<"Digite el numero que desea buscar: ";
            cin>>numero;
            if(nuevo_numero.buscar(numero))
                cout << "El numero " <<numero <<" esta en la lista";
            else
                cout << numero <<" no esta en la lista";
            pausar_ejecucion();
            break;
        case 9:
            nuevo_numero.borrar();
            pausar_ejecucion();
            break;
        default:
            BorraPantalla();
            cout<<opcion_menu <<" no es una opcion valida" <<endl;
        }
    }
    while(opcion_menu != 0);

    return 0;
}
