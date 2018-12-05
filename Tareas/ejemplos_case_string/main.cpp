#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s ("Esto es una cadena"),s2 ("Esta es otra cadena");
    //Cadena normal
    cout<<"Cadena normal \n";
    cout<<s;

    //substr
    cout<<"\n substr----->"<<s.substr(0,4);

    //Pointer to internal buffer
    cout<<"\n c_str----->"<<s.c_str();

    //length
    cout<<"\n lenth ----->" <<s.length();

    //resize
    s.resize(20,'!');
    cout<<"\n resize 20----->" <<s;

    //empty
    cout<<"\n empty----->"<<s.empty();

    //Asignacion
    s = s2;
    cout<<"\n asignacion ----->"<<s;

    //concatenar cadenas
    s = "Esto es una cadena";
    s += s2;

    cout<<"\n concatenando----->"<<s;

    //sumando cadenas
    s = "Esto es una cadena";
    cout<<"\n sumando cadenas ----->"<<s+s2;

    //Iteradores
    string::iterator t;

    //being
    cout<<"\n \n Iteradores \n";
    cout<<"\n begin \n";
    for ( t = s.begin(); t!= s.end(); ++t)
        cout << *t <<' ';
    cout << '\n';

    //end
    cout<<"\n end \n";
     for ( t = (s.end()); t!= (s.begin() - 1); --t)
        cout << *t <<' ';
    cout << '\n';

    //Insertar, eliminar y remplazar
    cout<<"\n insertar \n";

    s.insert(s.length()," esto fue insertado al final");
    cout<<s;
    //Eliminando
    s.replace(18,30," ahora reemplaze lo que inserte");
    cout<<"\n Reemplazando lo que se inserto \n";
    cout<<s;

    //comparacion
    s = "Esto es una cadena";
    cout<<"\n \n comparaciones de cadenas \n";
    if(s != s2)
        cout<<"Cadena 1 y no son distintas";

        //Buscar
    cout<<"\n \n bucando en la cadena \n";
    if(s.find("una"))
        cout<<"La palabra 'una' esta dentro de la cadena: "<< s;



    return 0;
}
