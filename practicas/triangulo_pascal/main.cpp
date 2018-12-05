#include <iostream>
using namespace std;
//El que entriegues quitale los comentarios si quieres o colocaselos a tu estilo :P att: Albert
int main()
{
    int filas, arreglo[50];
    //Asignamos 1 para iniciar el arreglo
    arreglo[0] = 1;

    cout << "Cantidad de filas ";
    cin >> filas;

    //Iteramos sobre la cantidad de filas que quiere el usuario
    for(int i = 0; i < filas; i++)
    {
        /**
        * Creamos los espacios que hacen que
        * todo se vea como una piramide,
        * mientras menos numeros mas espacios a la izquierda
        **/
        for(int espacio = 1; espacio <= filas-i; espacio++)
            cout <<"  "; //2 espacios, con 1 queda feo

        //Calculamos los numeros que se mostraran dependiento la cantidad de filas que se quieren
        for(int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
                arreglo[i] = 1;
            else
                arreglo[i] = arreglo[i]*(i-j+1)/j;

            cout << arreglo[i] << "   ";
        }
        //Nueva linea despues de cada fila para seguir escribiendo como una piramide
        cout << endl;
    }

    return 0;
}
