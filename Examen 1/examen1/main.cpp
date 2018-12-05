#include <iostream>
#include <list>

using namespace std;

class Estudiante {

private:
    string nombre;
    int nota;

public:
    string getNombre() const {
        return nombre;
    };
    int getNota() const {
        return nota;
    };
    void setNombre(string _nombre) {
        nombre = _nombre;
    };
    void setNota(int _nota) {
        nota = _nota;
    };

};
void moda(list<Estudiante>& estudiantes) {
    list<Estudiante>::iterator it;
    list<Estudiante>::iterator it2;

    int index = (estudiantes.size() - 1),numero_actual,contador_moda = 0,contador = 0;
    int moda[index],numero_moda[index];
    int mayor_numero = 0;
    int moda_final = 0;

    for ( it = estudiantes.begin(); it != estudiantes.end(); ++it ) {

        numero_actual = it->getNota();
        for ( it2 = estudiantes.begin(); it2 != estudiantes.end(); ++it2 ) {
            if(it2->getNota() == numero_actual) {
                contador_moda++;
            }
        }
        moda[contador] = contador_moda;
        numero_moda[contador] = numero_actual;
        contador_moda=0;
        contador++;
    }

    for(int x = 0; x < index; x++) {
        if(moda[x] > moda_final) {
            moda_final = moda[x];
            numero_actual = numero_moda[x];
        }

    }
    if(moda_final < 2) {
        cout<<"No hay ninguna moda.";
    } else {
        cout<<numero_actual <<" Repite: "<<moda_final;
    }
}

void menor_nota(list<Estudiante>& estudiantes) {
    list<Estudiante>::iterator it;
    int menor = 100;
    string nombre;
    int tamano = estudiantes.size();
    for ( it = estudiantes.begin(); it != estudiantes.end(); ++it ) {
        if(it->getNota() < menor) {
            nombre = it->getNombre();
            menor = it->getNota();
        }
    }
    cout <<nombre <<" " <<menor;

}
void mayor_nota(list<Estudiante>& estudiantes) {
    list<Estudiante>::iterator it;
    int mayor = 0;
    string nombre;
    int tamano = estudiantes.size();
    for ( it = estudiantes.begin(); it != estudiantes.end(); ++it ) {
        if(it->getNota() > mayor) {
            nombre = it->getNombre();
            mayor = it->getNota();
        }
    }
    cout <<nombre <<" " <<mayor <<endl;

}
void ultimo(list<Estudiante>& estudiantes) {
    list<Estudiante>::iterator it;
    int contador = 1;
    int tamano = estudiantes.size();
    for ( it = estudiantes.begin(); it != estudiantes.end(); ++it ) {
        if(tamano == contador)
            cout<<it->getNombre() <<" " <<it->getNota();

        contador++;
    }
}

void imprimir_antepenultimo(list<Estudiante>& estudiantes) {
    list<Estudiante>::iterator it;

    int contador = 1;
    int tamano = estudiantes.size();

    for ( it = estudiantes.begin(); it != estudiantes.end(); ++it ) {
        if(tamano == (contador + 1)) {
            cout<<it->getNombre() <<" " <<it->getNota();
            break;
        } else {
            contador++;
        }

    }
}

void promedio_impares(list<Estudiante>& estudiantes) {
    list<Estudiante>::iterator it;

    float suma = 0;
    int contador = 0;

    for ( it = estudiantes.begin(); it != estudiantes.end(); ++it ) {
        if((it->getNota() % 2) == 0) {
            suma += it->getNota();
            contador++;
        }
    }
    if(suma == 0){
        cout<<"No hay notas pares";
    }else{
        cout<<suma / contador;
    }

}

int main() {
    list<Estudiante>lista_estudiantes;

    Estudiante *estudiante;
    estudiante = new Estudiante;
    //1
    estudiante->setNombre("11");
    estudiante->setNota(11);

    lista_estudiantes.push_back(*estudiante);
    //2
    estudiante->setNombre("22");
    estudiante->setNota(22);

    lista_estudiantes.push_back(*estudiante);
    //3
    estudiante->setNombre("11");
    estudiante->setNota(11);

    lista_estudiantes.push_back(*estudiante);
    //4
    estudiante->setNombre("22");
    estudiante->setNota(22);

    lista_estudiantes.push_back(*estudiante);
    //5
    estudiante->setNombre("55");
    estudiante->setNota(55);

    lista_estudiantes.push_back(*estudiante);

    //promedio pares
    cout<<endl;
    cout<<"Lista Promedio pares:" <<endl;
    promedio_impares(lista_estudiantes);
    cout<<endl;

    //imprimir penultimo
    cout<<endl;
    cout<<"Ante Penultimo" <<endl;
    imprimir_antepenultimo(lista_estudiantes);
    cout<<endl;
    //imprimir ultimo
    cout<<endl;
    cout<<"Ultimo" <<endl;
    ultimo(lista_estudiantes);
    cout<<endl;
    //imprimir el mayor
    cout<<endl;
    cout<<"Mayor" <<endl;
    mayor_nota(lista_estudiantes);
    cout<<endl;
    //imprimir el menor

    cout<<endl;
    cout<<"Menor" <<endl;
    menor_nota(lista_estudiantes);
    cout<<endl;
    //imprimir moda

    cout<<endl;
    cout<<"Moda" <<endl;
    moda(lista_estudiantes);
    cout<<endl;
    return 0;
}
