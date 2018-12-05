/**
* Albert Eduardo Hidalgo Taveras
* 25/09/2018
**/

#include <iostream>
#include <stack>
#include <algorithm>

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

class Estudiante {

private:
    string nombre,cedula;
    int matricula;
    float calificacion;

public:
    //se dejo con un destructor por defecto
    void anadir(int _matricula,string _nombre,string _cedula,float _calificacion);
    void insertar();
    void borrar();
    void listar();
    void listar_inverso();
    void promedio();
    int getMatricula() const {
        return matricula;
    }
    float getCalificacion() const {
        return calificacion;
    }

};
/**
* Este metodo es utilizado para asignarle los datos a cada una de las propiedades
* de esta manera el objeto con todas sus propiedades asignadas se almacenan
* en el vector de estudiantes
**/
void Estudiante::anadir(int _matricula,string _nombre,string _cedula,float _calificacion) {
    matricula = _matricula;
    nombre = _nombre;
    cedula = _cedula;
    calificacion = _calificacion;
}
/**
* Lista los estudiantes, es utilizado por el vecto junto a un
* iterador
**/
void Estudiante::listar() {
    cout << matricula <<" "  << nombre <<" " << cedula <<" " << calificacion << endl;

}
/**
* Muestra las opciones diponibles del menu y retorna la
* opcion deseada al usuario, se utiliza para pasarle la
* opcion a un ciclo que mantiene el programa en ejecucion
**/
int menu() {
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

int main() {
    //Creando un vector de tipo estudiante
    stack<Estudiante> lista_estudiantes;

    string nombre,cedula;
    int matricula,opcion_menu,matricula_eliminar;
    float calificacion;

    Estudiante *est;
    //Nuevo objeto de tipo estudiante
    est = new Estudiante;

    BorraPantalla ();

    do {
        BorraPantalla ();
        opcion_menu = menu();
        //Opciones del menu
        switch(opcion_menu) {
        case 1:
            //Insertar nuevo
            cout<<"Digite el nombre: ";
            getline(cin,nombre);
            getline(cin,nombre);
            cout<<"Digite matricula: ";
            cin>>matricula;
            cout<<"Digite la cedula con guiones: ";
            cin>>cedula;
            cout<<"Digite la nota: ";
            cin>>calificacion;

            est->anadir(matricula,nombre,cedula,calificacion);
            cin.get(); //Limpiando el buffer

            //Agregando nuevo estudiante al vector
            lista_estudiantes.push(*est);

            pausar_ejecucion();
            break;
        case 2:

            break;
        case 3:
            //eliminar estudiante

            pausar_ejecucion();

            break;
        case 4:
            //Listar normal
        {
            if(lista_estudiantes.size() > 0) {
                cout << "MATRICULA |" << " NOMBRE |" << " CEDULA | " << " CALIFICACION | " <<endl;
                for ( int it = 0; it < lista_estudiantes.size(); ++it ){
                    est->listar();
                    lista_estudiantes.pop();
                }

            } else
                cout<<"No se ha registrado ningun estudiante" <<endl;

            pausar_ejecucion();
        }
        break;
        case 5:
            //Listar inverso
            break;
        case 6:
            //Promedio
            break;
        }
    } while(opcion_menu != 7);

    return 0;
}
