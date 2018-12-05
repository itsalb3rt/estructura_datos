#include <iostream>
#include <queue>
using namespace std;

//utilitario
/**
* Borrar de la consola lo que este encima de la funcion
**/
void BorraPantalla() {
    //Esto solo funciona en windows
    system ("cls");
};
/**
* se utiliza generalmente para que el usuario vea el resultado
* de lo que ha hecho y indicarle que para continuar pulse una tecla
**/
void pausar_ejecucion() {
    //Esto solo funciona en windows
    system("pause");
}

//fin utilitario

/**
* Muestra las opciones diponibles del menu y retorna la
* opcion deseada al usuario, se utiliza para pasarle la
* opcion a un ciclo que mantiene el programa en ejecucion
**/
int menu() {
    int opcion_menu;
    cout<<"\t\t Almacenando datos en Queue"<< endl;
    cout<<"1 -> ANADIR (push)" << endl;
    cout<<"2 -> BORRAR (pop)" << endl;
    cout<<"3 -> VER SI ESTA VACIO (empty)" << endl;
    cout<<"4 -> LISTAR" << endl;
    cout<<"5 -> VER PRIMER ELEMENTO(Front)" << endl;
    cout<<"6 -> VER ULTIMO ELEMENTO(Back)" << endl;
    cout<<"8 -> TAMANO(size)" << endl;
    cout<<"7 -> SALIR" << endl;
    cin>>opcion_menu;
    return opcion_menu;

}

void insertar(queue<string>& stack_data,string value) {
    stack_data.push(value);
}
/**
* Muestra los datos de la variable por fererencia [parametro 1]
* y guarda temporalmente sus valores en otra variable por referencia [segundo parametro]
**/
void listar( queue<string>& stack_data,queue<string>& temp_stack) {

    while(!stack_data.empty()) {
        cout<<" -> " <<stack_data.front() <<endl;
        temp_stack.push(stack_data.front());
        stack_data.pop();
    }

    while(!temp_stack.empty()) {
        stack_data.push(temp_stack.front());
        temp_stack.pop();
    }
}
/**
* Recibe por referencia una variable con los datos, otra variable temporal y el valor a eliminar
**/
void eliminar(queue<string>& stack_data,queue<string>& temp_stack,string delete_value) {

    bool confirmar_eliminado = false;
    //Copiando el queue
    while(!stack_data.empty()) {
        if(stack_data.front() != delete_value) {
            temp_stack.push(stack_data.front());
        } else {
            confirmar_eliminado = true;
        }
        stack_data.pop();
    }

    while(!stack_data.empty())
        stack_data.pop();

    //Copiando los elementos nuevamente

    while(!temp_stack.empty()) {
        stack_data.push(temp_stack.front());
        temp_stack.pop();
    }
    if(confirmar_eliminado)
        cout<<"Eliminado!" <<endl;
    else
        cout<<delete_value <<" no esta en la lista." <<endl;
}

int main() {
    queue<string>datos;
    queue<string>temp; //Usado en eliminar
    string nombre;
    int opcion_menu;


    do {
        BorraPantalla();
        opcion_menu = menu();
        switch(opcion_menu) {

        case 1:
            BorraPantalla();
            cout<<"Digite el nombre: ";
            cin>>nombre;
            insertar(datos,nombre);
            break;
        case 2:
            cout<<"Digite el nombre a eliminar: ";
            cin>>nombre;
            eliminar(datos,temp,nombre);
            pausar_ejecucion();
            break;
        case 3:
            cout<<"Empty: ";
            if(datos.empty())
                cout<<"Esta vacio" <<endl;
            else
                cout<<"El Queue tiene datos." <<endl;
            pausar_ejecucion();
            break;
        case 4:
            BorraPantalla();
            cout<<"Lista de datos: " <<endl;
            listar(datos,temp);
            pausar_ejecucion();
            break;
        case 5:
            if(datos.size() > 0)
                cout<<"Dato del Front: " <<datos.front() <<endl;
            else
                cout<<"No hay datos para mostrar." <<endl;
            pausar_ejecucion();
            break;
        case 6:
            if(datos.size() > 0)
                cout<<"Dato del Back: " <<datos.back() <<endl;
            else
                cout<<"No hay datos para mostrar." <<endl;
            pausar_ejecucion();
            break;
        case 8:
            cout<<"Size: " <<datos.size() <<endl;
            pausar_ejecucion();
            break;
        }

    } while(opcion_menu != 7);

    return 0;
}
