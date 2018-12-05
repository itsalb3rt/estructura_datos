/**
* Albert Eduardo Hidalgo Taveras
* 25/09/2018
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>

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
* Se utilizo una expresion regular para validar que la variable sea numerica
**/
bool es_numeric(string _cadena) {
    regex regex_pattern("-?[0-9]+.?[0-9]+");
    if(regex_match(_cadena,regex_pattern)) {
        return true;
    } else {
        return false;
    }
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
    vector<Estudiante> lista_estudiantes;
    string nombre,cedula;
    int matricula,opcion_menu,matricula_eliminar;
    float calificacion;
    string calificacion_entrada;

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

            do {
                cout<<"Digite una nota valida (Solo numeros): ";
                cin>>calificacion_entrada;
            } while(!es_numeric(calificacion_entrada));

            calificacion = strtof((calificacion_entrada).c_str(),0);

            est->anadir(matricula,nombre,cedula,calificacion);
            cin.get(); //Limpiando el buffer

            //Agregando nuevo estudiante al vector
            lista_estudiantes.push_back(*est);

            pausar_ejecucion();
            break;
        case 2:
            //Anadir un elemento en una posicion especifica
        {
            if(lista_estudiantes.size() > 0) {
                int contador = 1,posicion;
                vector<Estudiante>::iterator it;
                cout <<"N. | " << " MATRICULA |" << " NOMBRE |" << " CEDULA | " << " CALIFICACION | " <<endl;
                for ( it = lista_estudiantes.begin(); it != lista_estudiantes.end(); ++it ) {
                    cout<< contador << " -> ";
                    it->listar();
                    contador++;
                }

                cout<<"Digite el numero donde desea insertar un nuevo estudiante: ";
                cin>>posicion;

                BorraPantalla();

                cout<<"Rellene los siguientes datos: " <<endl;
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

                /*
                * Agregando nuevo estudiante al vector
                * se resta 1 a la posicion porque el usuario insertara una posicion
                * hipotetica ya que el contador comenzara en 1 y no en 0 por lo que
                * el usuario ve una posicion mas de lo que realmente hay
                */
                lista_estudiantes.insert(lista_estudiantes.begin()+ (posicion - 1), *est);

                cout<<endl;
                cout<<"Insertado!" <<endl;

            } else
                cout<<"No se ha registrado ningun estudiante" <<endl;

            pausar_ejecucion();
        }
        break;
        case 3:
            //eliminar estudiante
        {
            if(lista_estudiantes.size() > 0 ) {
                cout<<"Ingrese la matricula del estudiante a eliminar: ";
                cin>>matricula_eliminar;

                bool encontrado = false;
                vector <Estudiante>::iterator it3;
                for (it3 = lista_estudiantes.begin(); it3 != lista_estudiantes.end(); ++it3) {
                    if (it3->getMatricula() == matricula_eliminar) {
                        it3 = lista_estudiantes.erase(it3); //Despues de borrar, it3 apunta ahora a la siguiente ubicacion.
                        --it3; //ir a la ubicacion anterior debido a ++it3 es el final del ciclo for.
                        encontrado = true;
                        cout<<"Eliminado!" <<endl;
                    }
                }

                if (!encontrado) {
                    cout << "La matricula: " <<matricula_eliminar <<" no existe!" << endl;
                }

            } else
                cout<<"No se ha registrado ningun estudiante" <<endl;
        }
        pausar_ejecucion();

        break;
        case 4:
            //Listar normal
        {
            if(lista_estudiantes.size() > 0) {
                vector<Estudiante>::iterator it;
                cout << "MATRICULA |" << " NOMBRE |" << " CEDULA | " << " CALIFICACION | " <<endl;
                for ( it = lista_estudiantes.begin(); it != lista_estudiantes.end(); ++it )
                    it->listar();
            } else
                cout<<"No se ha registrado ningun estudiante" <<endl;

            pausar_ejecucion();
        }
        break;
        case 5:
            //Listar inverso
        {
            if(lista_estudiantes.size() > 0) {
                vector<Estudiante>::iterator itInverso;
                cout << "MATRICULA |" << " NOMBRE |" << " CEDULA | " << " CALIFICACION | " <<endl;
                for ( itInverso = (lista_estudiantes.end() - 1); itInverso != (lista_estudiantes.begin()- 1); --itInverso )
                    itInverso->listar();
            } else
                cout<<"No se ha registrado ningun estudiante" <<endl;

            pausar_ejecucion();
        }
        break;
        case 6:
            //Promedio
        {
            if(lista_estudiantes.size() > 0) {
                vector<Estudiante>::iterator it;
                float suma = 0;
                int contador = 0;

                for ( it = lista_estudiantes.begin(); it != lista_estudiantes.end(); ++it ) {
                    suma += it->getCalificacion();
                    contador++;
                }

                cout<<"El promedio es: " <<suma/contador <<endl;
            } else
                cout<<"No se ha registrado ningun estudiante" <<endl;

            pausar_ejecucion();
        }

        }
    } while(opcion_menu != 7);

    return 0;
}
