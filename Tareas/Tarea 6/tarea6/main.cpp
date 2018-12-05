#include <iostream>
#include <vector>
#include <iomanip>
#include <list>
#include <deque>

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
--------------------------Estudiantes-----------------------------
**/
class Estudiante {
private:
    int idMatricula;
    string nombre;
    int cedula;
    int nota;
    int edad;
    int idSexo;
    int idCategoria;

public:
    //Getters
    int getIdMatricula() const {
        return idMatricula;
    }
    string getNombre() const {
        return nombre;
    }
    int getCedula() const {
        return cedula;
    }
    int getNota() const {
        return nota;
    }
    int getEdad() const {
        return edad;
    }
    int getIdSexo() const {
        return idSexo;
    }
    int getIdCategoria() const {
        return idCategoria;
    }
    //Setters
    void setIdMatricula(int _matricula) {
        idMatricula = _matricula;
    }
    void setNombre(string _nombre) {
        nombre = _nombre;
    }
    void setCedula(int _cedula) {
        cedula = _cedula;
    }
    void setNota(int _nota) {
        nota = _nota;
    }
    void setEdad(int _edad) {
        edad = _edad;
    }
    void setIdSexo(int _sexo) {
        idSexo = _sexo;
    }
    void setIdCategoria(int _categoria) {
        idCategoria = _categoria;
    }

};

void listar_estudiantes(vector<Estudiante> &listado_estudiantes) {
    vector<Estudiante>::iterator it;

    for ( it = listado_estudiantes.begin(); it != listado_estudiantes.end(); ++it ) {
        cout<< it->getNombre() <<setw(5) <<it->getNota() << endl;
    }

}

void insertar_estudiante(vector<Estudiante>& listado_estudiantes) {
    Estudiante *est;
    est = new Estudiante;
    int matricula,cedula,nota,edad,id_sexo,id_categoria;
    string nombre;

    cout<<"Ingrese la matricula: ";
    cin>>matricula;
    cout<<"Ingrese nombre: ";
    getline(cin,nombre);
    getline(cin,nombre);
    cout<<"Ingrese cedula (solo numeros): ";
    cin>>cedula;
    cout<<"Ingrese Nota: ";
    cin>>nota;
    cout<<"Ingrese la edad: ";
    cin>>edad;
    cout<<"Ingrese el ID del sexo(1 Masculino, 2 Femenino, 3 otro): ";
    cin>>id_sexo;
    cout<<"Ingrese ID Categoria: ";
    cin>>id_categoria;

    est->setIdMatricula(matricula);
    est->setNombre(nombre);
    est->setCedula(cedula);
    est->setNota(nota);
    est->setEdad(edad);
    est->setIdSexo(id_sexo);
    est->setIdCategoria(id_categoria);

    listado_estudiantes.push_back(*est);
}

void eliminar_estudiante(vector<Estudiante>& lista_estudiantes) {
    int matricula_eliminar;
    if(lista_estudiantes.size() > 0 ) {
        cout<<"Ingrese la matricula del estudiante a eliminar: ";
        cin>>matricula_eliminar;

        bool encontrado = false;
        vector <Estudiante>::iterator it3;
        for (it3 = lista_estudiantes.begin(); it3 != lista_estudiantes.end(); ++it3) {
            if (it3->getIdMatricula() == matricula_eliminar) {
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

void promedio_notas_estudiantes(vector<Estudiante>& lista_estudiantes) {

    if(lista_estudiantes.size() > 0) {
        vector<Estudiante>::iterator it;
        float suma = 0;
        int contador = 0;

        for ( it = lista_estudiantes.begin(); it != lista_estudiantes.end(); ++it ) {
            suma += it->getNota();
            contador++;
        }

        cout<<"El promedio es: " <<suma/contador <<endl;
    } else
        cout<<"No se ha registrado ningun estudiante" <<endl;

}
/**
--------------------------SEXO-----------------------------
**/
class Sexo {
private:
    int idSexo;
    string nombre;

public:
    //Getters
    int getIdSexo() const {
        return idSexo;
    }
    string getNombre() const {
        return nombre;
    }
    //Setters
    void setIdSexo(int _idSexo) {
        idSexo = _idSexo;
    }
    void setNombre(string _nombre) {
        nombre = _nombre;
    }
};

void insertar_sexo(list<Sexo>& lista_sexo) {
    Sexo *sexo;
    sexo = new Sexo;

    int id_sexo;
    string nombre;

    cout<<"ID Sexo: ";
    cin>>id_sexo;
    cout<<"Nombre Sexo: ";
    getline(cin,nombre);
    getline(cin,nombre);

    sexo->setIdSexo(id_sexo);
    sexo->setNombre(nombre);
    lista_sexo.push_back(*sexo);

}

void listar_sexo(list<Sexo>& listado_sexo) {
    list<Sexo>::iterator it;

    for ( it = listado_sexo.begin(); it != listado_sexo.end(); ++it ) {
        cout<< it->getIdSexo() <<" " <<it->getNombre() << endl;
    }

}

void eliminar_sexo(list<Sexo>& lista_sexo) {
    int id_sexo_eliminar;
    if(lista_sexo.size() > 0 ) {
        cout<<"Ingrese el ID del sexo a eliminar: ";
        cin>>id_sexo_eliminar;

        bool encontrado = false;
        list <Sexo>::iterator it3;
        for (it3 = lista_sexo.begin(); it3 != lista_sexo.end(); ++it3) {
            if (it3->getIdSexo() == id_sexo_eliminar) {
                it3 = lista_sexo.erase(it3); //Despues de borrar, it3 apunta ahora a la siguiente ubicacion.
                --it3; //ir a la ubicacion anterior debido a ++it3 es el final del ciclo for.
                encontrado = true;
                cout<<"Eliminado!" <<endl;
            }
        }

        if (!encontrado) {
            cout << "El ID: " <<id_sexo_eliminar <<" no existe!" << endl;
        }

    } else
        cout<<"No se ha registrado ningun sexo" <<endl;
}

/**
--------------------------Categoria-----------------------------
**/
class Categoria {
private:
    int idCategoria;
    string nombre;
    float pago;
public:
    //Getters
    int getIdCategoria()const {
        return idCategoria;
    }
    string getNombre() const {
        return nombre;
    }
    float getPago() const {
        return pago;
    }
    //Setters
    void setIdCategoria(int _idCategoria) {
        idCategoria = _idCategoria;
    }
    void setNombre(string _nombre) {
        nombre = _nombre;
    }
    void setPago(float _pago) {
        pago = _pago;
    }
};

void insertar_categoria(deque<Categoria>& lista_categorias) {
    Categoria *categoria;
    categoria = new Categoria;

    int id_categoria;
    string nombre;
    float pago;

    cout<<"ID Categoria: ";
    cin>>id_categoria;
    cout<<"Nombre categoria: ";
    getline(cin,nombre);
    getline(cin,nombre);
    cout<<"Monto: ";
    cin>>pago;

    categoria->setIdCategoria(id_categoria);
    categoria->setNombre(nombre);
    categoria->setPago(pago);
    lista_categorias.push_back(*categoria);

}

void listar_categoria(deque<Categoria>& listado_categoria) {
    deque<Categoria>::iterator it;

    for ( it = listado_categoria.begin(); it != listado_categoria.end(); ++it ) {
        cout<< it->getIdCategoria() <<" " <<it->getNombre() <<" " <<it->getPago() << endl;
    }

}

void eliminar_categoria(deque<Categoria>& lista_categoria) {
    int id_categoria_eliminar;
    if(lista_categoria.size() > 0 ) {
        cout<<"Ingrese el ID del sexo a eliminar: ";
        cin>>id_categoria_eliminar;

        bool encontrado = false;
        deque <Categoria>::iterator it3;
        for (it3 = lista_categoria.begin(); it3 != lista_categoria.end(); ++it3) {
            if (it3->getIdCategoria() == id_categoria_eliminar) {
                it3 = lista_categoria.erase(it3); //Despues de borrar, it3 apunta ahora a la siguiente ubicacion.
                --it3; //ir a la ubicacion anterior debido a ++it3 es el final del ciclo for.
                encontrado = true;
                cout<<"Eliminado!" <<endl;
            }
        }

        if (!encontrado) {
            cout << "El ID: " <<id_categoria_eliminar <<" no existe!" << endl;
        }

    } else
        cout<<"No se ha registrado ningun sexo" <<endl;
}



int menu_principal() {
    int opcion_menu;
    cout<<"\t\t Registro de algo"<< endl;
    cout<<"1 -> ESTUDIANTES" << endl;
    cout<<"2 -> SEXO" << endl;
    cout<<"3 -> CATEGORIAS" << endl;
    cout<<"7 -> SALIR" << endl;
    cin>>opcion_menu;
    return opcion_menu;
}

int menu_estudiantes() {
    int opcion_menu;
    cout<<"\t\t Registro de Estudiantes"<< endl;
    cout<<"1 -> ANADIR" << endl;
    cout<<"3 -> BORRAR" << endl;
    cout<<"4 -> LISTAR" << endl;
    cout<<"5 -> PROMEDIO" << endl;
    cout<<"7 -> SALIR AL MENU PRINCIPAL" << endl;
    cin>>opcion_menu;
    return opcion_menu;
}



int menu_sexo() {
    int opcion_menu;
    cout<<"\t\t Registro de Sexo"<< endl;
    cout<<"1 -> ANADIR" << endl;
    cout<<"3 -> BORRAR" << endl;
    cout<<"4 -> LISTAR" << endl;
    cout<<"7 -> SALIR AL MENU PRINCIPAL" << endl;
    cin>>opcion_menu;
    return opcion_menu;
}

int menu_categoria() {
int opcion_menu;
    cout<<"\t\t Registro de Categoria"<< endl;
    cout<<"1 -> ANADIR" << endl;
    cout<<"3 -> BORRAR" << endl;
    cout<<"4 -> LISTAR" << endl;
    cout<<"7 -> SALIR AL MENU PRINCIPAL" << endl;
    cin>>opcion_menu;
    return opcion_menu;
}
int main() {
    //Categoria
    deque<Categoria>lista_categorias;
    Categoria *categoria;
    categoria = new Categoria;
    //1
    categoria->setIdCategoria(1);
    categoria->setNombre("Bajo");
    categoria->setPago(5000);

    lista_categorias.push_back(*categoria);

    //2
    categoria->setIdCategoria(2);
    categoria->setNombre("Medio");
    categoria->setPago(20000);

    lista_categorias.push_back(*categoria);

    //3
    categoria->setIdCategoria(3);
    categoria->setNombre("Medio Alto");
    categoria->setPago(30000);

    lista_categorias.push_back(*categoria);


    //Sexo
    list<Sexo>list_sexo;
    Sexo *sexo;
    sexo = new Sexo;

    sexo->setIdSexo(1);
    sexo->setNombre("Masculino");
    list_sexo.push_back(*sexo);

    sexo->setIdSexo(2);
    sexo->setNombre("Femenino");
    list_sexo.push_back(*sexo);

    sexo->setIdSexo(3);
    sexo->setNombre("Otro");
    list_sexo.push_back(*sexo);

    //Estudiantes
    vector<Estudiante>estudiantes;
    Estudiante *est;
    est = new Estudiante;

    //1
    est->setIdMatricula(100166816);
    est->setNombre("Albert Hidalgo");
    est->setCedula(05601736043);
    est->setNota(99);
    est->setEdad(25);
    est->setIdSexo(1);
    est->setIdCategoria(1);

    estudiantes.push_back(*est);
    //2
    est->setIdMatricula(1002919878);
    est->setNombre("Yanibel Gutierrez");
    est->setCedula(40201736043);
    est->setNota(100);
    est->setEdad(24);
    est->setIdSexo(2);
    est->setIdCategoria(1);

    estudiantes.push_back(*est);

    BorraPantalla ();
    //Algunas variables
    int opcion_menu_principal,opcion_menu_estudiante,opcion_menu_sexo,opcion_menu_categoria;

    do {
        opcion_menu_principal = menu_principal();
        BorraPantalla ();

        switch(opcion_menu_principal) {
        case 1:
            //Estudiantes

            do {
                BorraPantalla();
                opcion_menu_estudiante = menu_estudiantes();

                switch(opcion_menu_estudiante) {
                case 1:
                    //Insertar estudiantes
                    insertar_estudiante(estudiantes);
                    pausar_ejecucion();
                    break;
                case 3:
                    //Eliminar estudiante
                    eliminar_estudiante(estudiantes);
                    break;
                case 4:
                    //Listar estudiantes
                    listar_estudiantes(estudiantes);
                    pausar_ejecucion();
                    break;
                case 5:
                    //Promedio
                    promedio_notas_estudiantes(estudiantes);
                    pausar_ejecucion();
                    break;
                }
            } while(opcion_menu_estudiante != 7);
            BorraPantalla();
            break;
        //Sexo
        case 2:
            do {
                BorraPantalla();
                opcion_menu_sexo = menu_sexo();

                switch(opcion_menu_sexo) {
                case 1:
                    //Insertar sexo
                    insertar_sexo(list_sexo);
                    pausar_ejecucion();
                    break;
                case 3:
                    //eliminar sexo
                    eliminar_sexo(list_sexo);
                    pausar_ejecucion();
                    break;
                case 4:
                    //Listar sexo
                    listar_sexo(list_sexo);
                    pausar_ejecucion();
                    break;
                }
            } while(opcion_menu_sexo != 7);
            BorraPantalla();
            break;
        case 3:
            //sexo
                do {
                BorraPantalla();
                opcion_menu_categoria = menu_categoria();

                switch(opcion_menu_categoria) {
                case 1:
                    //Insertar categoria
                    insertar_categoria(lista_categorias);
                    pausar_ejecucion();
                    break;
                case 3:
                    //eliminar categoria
                    eliminar_categoria(lista_categorias);
                    pausar_ejecucion();
                    break;
                case 4:
                    //Listar categoria
                    listar_categoria(lista_categorias);
                    pausar_ejecucion();
                    break;
                }
            } while(opcion_menu_categoria != 7);
            BorraPantalla();
            break;
        }
    } while(opcion_menu_principal != 7);


    return 0;
}
