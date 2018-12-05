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
    int data; //numero entero que se guardara en cada nodo
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
    void addFront(int dt); //Se anade al principio
    void addBack(int dt); //Se anade al final
    void removeFront();//Elimina el primer nodo
    void removeBack(); //Elimina el ultimo nodo de la lista
    void printReverse(); //Imprime en orden reverso la lista
    void printForward(); //Imprimir los valores normal
private:
    Node *header; //Nodo centinela
    Node *trailer;// Nodo centinela

};


int main()
{
    LinkedList ll;
    ll.addFront(5);
    ll.addFront(25);
    ll.addFront(3);
    ll.addFront(80);
    ll.addBack(21);
    ll.addBack(24);

    ll.printReverse();

    cout<<"\n " << ll.getFront() <<endl;
    cout<<"\n " << ll.getBack() <<endl;
    /*
    int opcion_menu;

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
            pausar_ejecucion();
            break;
        }
    }
    while(opcion_menu != 7);
        */
    return 0;
}

LinkedList::LinkedList()
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
}


int LinkedList::getFront() const
{
    return header->next->data;
}

int LinkedList::getBack() const
{
    return trailer->prev->data;
}

void LinkedList::addFront(int dt)
{
    Node *nd = new Node;
    nd->data = dt;
    nd->prev = header;
    nd->next = header->next;//Nodo head

    //Cambiando los valores de los punteros con el nuevo nodo
    header->next->prev = nd;
    header->next = nd;
}

void LinkedList::addBack(int dt)
{
    Node *nd = new Node;
    nd->data = dt;
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

    while(nd != header)
    {
        cout<< nd->data << " ";
        nd = nd->prev;
    }
}

void LinkedList::printForward()
{
    Node *nd = header->next;

    while(nd != trailer)
    {
        cout<< nd->data << " ";
        nd = nd->next;
    }
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

