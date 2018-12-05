/**
* Albert Eduardo Hidalgo Taveras
* 20/09/2018
**/
#include <iostream>
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

/**
* Muestra las opciones diponibles del menu y retorna la
* opcion deseada al usuario, se utiliza para pasarle la
* opcion a un ciclo que mantiene el programa en ejecucion
**/
int menu()
{
    int opcion_menu;
    cout<<"\t\t Registro de Alumnos"<< endl;
    cout<<"1 -> ANADIR" << endl;
    cout<<"2 -> INSERTAR" << endl;
    cout<<"3 -> BORRAR" << endl;
    cout<<"4 -> LISTAR" << endl;
    cout<<"5 -> LISTAR INVERSO" << endl;
    cout<<"6 -> PROMEDIO" << endl;
    cout<<"7 -> SALIR" << endl;
    cin>>opcion_menu;
    return opcion_menu;

}
//Interfaz de datos
class Node
{
private:
    int calificacion; //numero entero que se guardara en cada nodo
    string nombre_estudiante;
    string cedula;
    int matricula;
    Node *prev;
    Node *next;

    friend class LinkedList; // "Herencia"
};
/**
* Esta clase facilita las operaciones de insertar
* y eliminar elementos de los nodos
**/
class LinkedList
{
public:
    LinkedList();
    ~LinkedList(); //Para las clases que asignan valores a memoria dinamicamente se debe crear un destructor
    int getFront() const; //Devuelve el numero entero del primer nodo
    int getBack() const; //Devuelve el ultimo nodo de la lista
    void addFront(int _matricula,string _nombre_estudiante,string _cedula,int _calificacion); //Se anade al principio
    void addBack(int _matricula,string _nombre_estudiante,string _cedula,int _calificacion); //Se anade al final
    void removeFront();//Elimina el primer nodo
    void removeBack(); //Elimina el ultimo nodo de la lista
    void printReverse(); //Imprime en orden reverso la lista
    void printForward(); //Imprimir los valores normal
    void delete_item(int _matricula); //Elimina un item por su matricula
    float promedio();
private:
    Node *header; //Nodo centinela
    Node *trailer;// Nodo centinela

};


int main()
{
    int matricula,nota;
    string nombre,cedula;

    LinkedList ll;
    ll.addFront(100166816,"ALBERT HIDALGO","056-0173604-3",90);
    ll.addFront(100297890,"YANIBEL GUTIERREZ","402-8989300-3",96);

    int opcion_menu,matricula_eliminar;

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
            cout<<"Digite el nombre: ";
            getline(cin,nombre);
            getline(cin,nombre);
            cout<<"Digite matricula: ";
            cin>>matricula;
            cout<<"Digite la cedula con guiones: ";
            cin>>cedula;
            cout<<"Digite la nota: ";
            cin>>nota;
            ll.addFront(matricula,nombre,cedula,nota);
            pausar_ejecucion();
            break;
        case 4:
            ll.printForward();
            pausar_ejecucion();
            break;
        case 3:
            cout<<"Digite la matricula para eliminar: ";
            cin>>matricula_eliminar;
            ll.delete_item(matricula_eliminar);
            pausar_ejecucion();
        case 5:
            ll.printReverse();
            pausar_ejecucion();
            break;
        case 6:
            cout<<"El promedio es: " <<ll.promedio() <<endl;
            pausar_ejecucion();
        }
    }
    while(opcion_menu != 7);

    return 0;
}
//Implementacion metodos
LinkedList::LinkedList()
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
}

//Retorna el primer nodo
int LinkedList::getFront() const
{
    return header->next->calificacion;
}
//Retorna el ultimo nodo
int LinkedList::getBack() const
{
    return trailer->prev->calificacion;
}

void LinkedList::addFront(int _matricula,string _nombre_estudiante,string _cedula,int _calificacion)
{
    Node *nd = new Node;

    nd->matricula = _matricula;
    nd->nombre_estudiante = _nombre_estudiante;
    nd->cedula = _cedula;
    nd->calificacion = _calificacion;

    nd->prev = header;
    nd->next = header->next;//Nodo head

    //Cambiando los valores de los punteros con el nuevo nodo
    header->next->prev = nd;
    header->next = nd;
}

void LinkedList::addBack(int _matricula,string _nombre_estudiante,string _cedula,int _calificacion)
{
    Node *nd = new Node;

    nd->matricula = _matricula;
    nd->nombre_estudiante = _nombre_estudiante;
    nd->cedula = _cedula;
    nd->calificacion = _calificacion;

    nd->prev = trailer->prev;
    nd->next = trailer;

    //Cambiando los valores del trailer
    trailer->prev->next = nd;
    trailer->prev = nd;
}

void LinkedList::removeFront()
{
    Node *nd = header->next->next;

    delete header->next;

    //Actualizando el nodo siguiente
    header->next = nd;
    nd->prev = header;
}

void LinkedList::removeBack()
{
    Node *nd = trailer->prev->prev;

    delete trailer->prev;

    //Actualizando el nodo anterior
    trailer->prev = nd;
    nd->next = trailer;
}
void LinkedList::printReverse()
{
    Node *nd = trailer->prev;
    cout<<"MATRICULA" <<" | " <<"NOMBRE ESTUDIANTE" << " | " << "CEDULA" <<" | " << " CALIFICACION " <<endl;
    cout<<endl;
    while(nd != header)
    {
        cout<<nd->matricula <<" | " << nd->nombre_estudiante <<" | " <<nd->cedula <<" | " << nd->calificacion <<endl;
        nd = nd->prev;
    }
}

void LinkedList::printForward()
{
    Node *nd = header->next;
    cout<<"MATRICULA" <<" | " <<"NOMBRE ESTUDIANTE" << " | " << "CEDULA" <<" | " << " CALIFICACION " <<endl;
    cout<<endl;
    while(nd != trailer)
    {
        cout<<nd->matricula <<" | " << nd->nombre_estudiante <<" | " <<nd->cedula <<" | " << nd->calificacion <<endl;
        nd = nd->next;
    }
}

void LinkedList::delete_item(int _matricula)
{

    Node *nd = header->next;

    while(nd != trailer)
    {
        if(nd->matricula == _matricula)
        {
            cout<<nd->matricula <<" " << nd->nombre_estudiante <<" " <<nd->cedula <<" " << nd->calificacion <<endl;
        }

        nd = nd->next;
    }

}

float LinkedList::promedio()
{
    Node *nd = header->next;
    float suma = 0;
    int contador = 0;

    while(nd != trailer)
    {
        suma += nd->calificacion;
        nd = nd->next;
        contador++;
    }
    return suma/contador;
}

LinkedList::~LinkedList()
{
    while(header->next != trailer)
    {
        removeFront();
    }

    delete header;
    delete trailer;
} //Para las clases que asignan valores a memoria dinamicamente se debe crear un destructor


