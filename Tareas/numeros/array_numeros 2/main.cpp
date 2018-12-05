/**
* Albert E. Hidalgo Taveras
* 04.08.2018
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
* Se creo una clase para el procesamiento de los numeros
* de esta manera se tiene todo encapsulado
**/
class Numero
{
private:
    int numeros[100];
    int copia_numeros[100]; //Utilizada para ordernar
    void copiar_arreglo();


public:
    int numero;
    void ordenar();
    void digitar_numeros();
    void normal();
    void inverso();
    void pares();
    void impares();
    void promedio();
    void mayores_al_promedio();
    void menores_al_promedio();
    void promedio_pares();
    void promedio_impares();
    void inverso_negativo();
    void multiplos_cinco();
    void multiplos_siete();
    void moda();
    int buscar(int numero_buscar);
    void borrar();
    int posiciones();
    //Setters y getters
    void setNumero(int _numero,int index);

};

//Setters

void Numero::setNumero(int _numero,int index)
{
    numeros[index] = _numero;
}

//Otros metodos
int Numero::posiciones()
{
    int contador = 0;
    for(int i = 0; contador < 100; i++)
    {
        if(numeros[contador]== 0)
        {
            break;
        }
        else
        {
            contador++;
        }

    }
    return contador;

}
void Numero::digitar_numeros()
{
    do
    {
        int index = posiciones();
        cout<<"Digite un numero y pulse enter, introduzca 0 para salir: ";
        cin>>numero;

        //de no condicionar esto insertara el 0
        if(numero != 0)
        {
            setNumero(numero,index);
        }

    }
    while(numero != 0);

}

void Numero::normal()
{
    cout<<"Numeros ingresados" <<endl;
    int index = posiciones();
    if(index != 0)
    {
        for(int i = 0; i<index; i++)
        {
            cout<<i <<" -> "<<numeros[i]<<endl;
        }
    }
    else
        cout <<"No ha digitado ningun numero" <<endl;

}

void Numero::inverso()
{
    cout<<"Numeros ingresados" <<endl;
    int index = posiciones();
    if(index != 0)
    {
        for(int i = (index - 1); i > -1; i--)
        {
            cout<<i <<" -> "<<numeros[i]<<endl;
        }
    }
    else
        cout <<"No ha digitado ningun numero" <<endl;
}

void Numero::inverso_negativo()
{
    cout<<"Numeros ingresados" <<endl;
    int index = posiciones();
    if(index != 0)
    {
        for(int i = (index - 1); i > -1; i--)
        {
            cout<<i <<" -> "<<numeros[i] * -1 <<endl;
        }
    }
    else
        cout <<"No ha digitado ningun numero" <<endl;
}
void Numero::pares()
{
    int index = posiciones();
    cout<<"Numeros pares" <<endl;
    for(int i = 0; i<index; i++)
    {
        if(numeros[i]%2 == 0 )
            cout<<i <<" -> "<<numeros[i]<<endl;
    }
}

void Numero::impares()
{
    int index = posiciones();
    cout<<"Numeros impares" <<endl;
    for(int i = 0; i<index; i++)
    {
        if(numeros[i]%2 != 0 )
            cout<<i <<" -> "<<numeros[i]<<endl;
    }
}

void Numero::promedio()
{
    float suma;
    int index = posiciones();
    if(index != 0)
    {
        for(int i = 0; i<index; i++)
        {
            suma = suma + numeros[i];
        }
        cout<< "El promedio es: " <<suma / index <<endl;
    }

}

void Numero::promedio_pares()
{
    float suma,contador_pares = 0;
    int index = posiciones();
    if(index != 0)
    {
        for(int i = 0; i<index; i++)
        {
            if(numeros[i]%2 == 0)
            {
                suma = suma + numeros[i];
                contador_pares++;
            }

        }
        cout<< "El promedio de los pares es: " <<suma / contador_pares <<endl;
    }

}

void Numero::promedio_impares()
{
    float suma,contador_impares = 0,promedio;
    int index = posiciones();
    if(index != 0)
    {
        for(int i = 0; i<index; i++)
        {
            if(numeros[i]%2 != 0)
            {
                suma = suma + numeros[i];
                contador_impares++;
            }

        }
        promedio = suma / contador_impares;
        cout<< "El promedio de los impares es: " <<promedio <<endl;
    }

}

void Numero::mayores_al_promedio()
{
    float suma,promedio;
    int index = posiciones();
    if(index != 0)
    {
        for(int i = 0; i<index; i++)
        {
            suma = suma + numeros[i];
        }
        promedio = suma / index;
        cout<< "El promedio es: " <<promedio<<endl;
        cout<< "Mayores al promedio" <<endl;
        ordenar();
        for(int j = 0; j < index; j++)
        {
            if(copia_numeros[j] > promedio )
            {
                cout<<copia_numeros[j] <<endl;
            }
        }

    }

}

void Numero::menores_al_promedio()
{
    float suma,promedio;
    int index = posiciones();
    if(index != 0)
    {
        for(int i = 0; i<index; i++)
        {
            suma = suma + numeros[i];
        }
        promedio = suma / index;
        cout<< "El promedio es: " <<promedio<<endl;
        cout<< "Menores al promedio" <<endl;
        ordenar();
        for(int j = 0; j < index; j++)
        {
            if(copia_numeros[j] < promedio )
            {
                cout<<copia_numeros[j] <<endl;
            }
        }

    }

}
/**
* Elimina un item del listado
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
        if(buscar(numero_borrar) != -1)
        {
            int index_eliminar = buscar(numero_borrar),index = posiciones();

            //Limpiando el array copia
            for(int i= 0; i < 100; i++)
            {
                copia_numeros[i] = '\0';
            }

            //Excluyendo el numero que se pretende eliminar
            for(int i = 0; i < index; i++)
            {
                if(numeros[i] != numero_borrar)  //Cuando el numero a borrar no es igual al actual
                {
                    copia_numeros[i] = numeros[i];
                }
                else
                {
                    for(int j = (i+1); j < index; j++) //Cuando se encuentra el numero a borrar
                    {
                        copia_numeros[j-1] = numeros[j];
                    }
                    break;
                }
            }

            //vaciando el arreglo original
            for(int i= 0; i < 100; i++)
            {
                numeros[i] = '\0';
            }
            //copiando el nuevo arregl al original
            for(int i = 0; i < index; i++)
            {
                numeros[i] = copia_numeros[i];
            }

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
**/
void Numero::ordenar()
{
    copiar_arreglo(); //Realiza una copia para trabajar sobre ella
    int temp;
    int tamano = posiciones();
    for(int i=0; i<tamano; i++)
    {
        for(int j=i+1; j<tamano; j++)
        {
            if(copia_numeros[i]>copia_numeros[j]) //Ve si el numero en la posicion actual es mayor al de la posicion siguiente, J sera mayor en todos los casos
            {
                temp=copia_numeros[i];
                copia_numeros[i]=copia_numeros[j];
                copia_numeros[j]=temp;
            }
        }
    }

}
/**
* Realiza una copia al arreglo original para ordenarlos
* de esta manera se mantiene la entrada original del usuario
**/
void Numero::copiar_arreglo()
{
    int tamano = posiciones();
    for(int i = 0; i < tamano; i++)
    {
        copia_numeros[i] = numeros[i];
    }
}
/**
* Busqueda binaria
* Return el index del elemento o -1 si no lo encuentra
* se utilizo el -1 y no otro valor porque un indice jamas sera -1
**/
int Numero::buscar(int numero_buscar)
{
    //Para realizar la busqueda binaria los items deben estar odenados
    ordenar();

    int indice_inferior = 0;
    int indice_superior = posiciones();
    int mitad;

    while (indice_inferior <= indice_superior)
    {
        int mitad = (indice_inferior + indice_superior) / 2;
        if (copia_numeros[mitad] == numero_buscar)
            return mitad;
        else if (copia_numeros[mitad] > numero_buscar)
            indice_superior = mitad - 1;
        else
            indice_inferior = mitad + 1;
    }
    return -1;

}

void Numero::multiplos_cinco()
{
    cout<<"Multiplos de 5" <<endl;
    int index = posiciones();
    if(index != 0)
    {
        for(int i = 0; i<index; i++)
        {
            if(numeros[i]%5 == 0)
            {
                cout<<numeros[i] <<endl;
            }
        }
    }
    else
        cout <<"No ha digitado ningun numero" <<endl;
}

void Numero::multiplos_siete()
{
    cout<<"Multiplos de 7" <<endl;
    int index = posiciones();
    if(index != 0)
    {
        for(int i = 0; i<index; i++)
        {
            if(numeros[i]%7 == 0)
            {
                cout<<numeros[i] <<endl;
            }
        }
    }
    else
        cout <<"No ha digitado ningun numero" <<endl;
}

void Numero::moda()
{
    int index = posiciones(),numero_actual,contador_moda = 0;
    int moda[index];

    for(int i = 0; i < index; i++)
    {
        numero_actual = numeros[i];
        for(int j = 0; j < index; j++)
        {
            if(numeros[j] == numero_actual)
            {
                contador_moda++;
            }
        }
        moda[i] = contador_moda;
        contador_moda=0;
    }
    cout<<"\n" <<"Moda" <<endl;
    for(int x = 0; x < index; x++){
        cout<<moda[x] <<endl;
    }


}

//Main

int menu()
{
    int opcion_menu;
    cout<<"\t\t Elija una opcion"<< endl;
    cout<<"1  Insertar numeros" << endl;
    cout<<"2  Normal" << endl;
    cout<<"3  Inverso" << endl;
    cout<<"4  Pares" << endl;
    cout<<"5  Impares" << endl;
    cout<<"6  Promedio" << endl;
    cout<<"7  Inverso negativo" << endl;
    cout<<"--------------" << endl;
    cout<<"10  Multiplo de 5" << endl;
    cout<<"11  Multiplo de 7" << endl;
    cout<<"--------------" << endl;
    cout<<"12 Mayores al promedio" << endl;
    cout<<"13 Menores al promedio" << endl;
    cout<<"14 Promedio de los pares" << endl;
    cout<<"15 Promedio de los impares" << endl;
    cout<<"--------------" << endl;
    cout<<"16 Moda" << endl;
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
            nuevo_numero.ordenar();
            pausar_ejecucion();
            break;
        case 3:
            nuevo_numero.inverso();
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
        case 7:
            nuevo_numero.inverso_negativo();
            pausar_ejecucion();
            break;
        case 8:
            cout<<"Digite el numero que desea buscar: ";
            cin>>numero;
            if(nuevo_numero.buscar(numero) != -1)
                cout << "El numero " <<numero <<" esta en la lista";
            else
                cout << numero <<" no esta en la lista";
            pausar_ejecucion();
            break;
        case 9:
            nuevo_numero.borrar();
            pausar_ejecucion();
            break;
        case 10:
            nuevo_numero.multiplos_cinco();
            pausar_ejecucion();
            break;
        case 11:
            nuevo_numero.multiplos_siete();
            pausar_ejecucion();
            break;
        case 12:
            nuevo_numero.mayores_al_promedio();
            pausar_ejecucion();
            break;
        case 13:
            nuevo_numero.menores_al_promedio();
            pausar_ejecucion();
            break;
        case 14:
            nuevo_numero.promedio_pares();
            pausar_ejecucion();
            break;
        case 15:
            nuevo_numero.promedio_impares();
            pausar_ejecucion();
            break;
        case 16:
            nuevo_numero.moda();
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
