/**
* Metro Santo Domingo
* Albert Eduardo Hidalgo Taveras
* Hecho el sabado 1 de diciembre en 3 horas y 43 min (Incluyenmdo investigacion)
**/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void BorraPantalla()
{
    system ("cls");
};
void pausar_ejecucion()
{
    system("pause");
}

bool verificar_estacion_valida(string estacion1, string estacion2)
{

    if( atoi(estacion1.c_str()) < 1  || atoi(estacion1.c_str()) > 15 || atoi(estacion2.c_str()) < 1 || atoi(estacion2.c_str()) > 14 )
    {
        cout <<endl;
        cout<< "Estacion invalida" <<endl;
        pausar_ejecucion();
        return false;
    }
    else
    {
        return true;
    }
}

int menu_principal()
{
    int opcion_menu;
    cout<<"1 -> LINEA 1" << endl;
    cout<<"2 -> LINEA 2" << endl;
    cout<<"0 -> SALIR" << endl;
    cin>>opcion_menu;
    return opcion_menu;
}
int main ()
{

    struct datosEstacion
    {
        string id;
        string nombre;
        float km;
        float velocidad = 80.0; //km*h
    };
    int opcion_menu;
    do
    {
        BorraPantalla();
        opcion_menu = menu_principal();
        switch(opcion_menu)
        {
        case 1:
        {
            BorraPantalla();

            struct datosEstacion *linea1;

            linea1= new datosEstacion[16];

            linea1->id = "1";
            linea1->nombre ="Mamá Tingó (Villa Mella, cerca de la Av. Charles de Gaulle)";
            linea1->km=0;

            (linea1+1)->id="2";
            (linea1+1)->nombre="Gregorio Urbano Gilbert (Ensanche La Paz)";
            (linea1+1)->km=0.91;

            (linea1+2)->id = "3";
            (linea1+2)->nombre = "Gregorio Luperón (Sol de Luz, Cerros de Buena Vista)";
            (linea1+2)->km=0.91;

            (linea1+3)->id = "4";
            (linea1+3)->nombre = "José Francisco Peña Gómez (Los Guaricanos)";
            (linea1+3)->km=0.91;

            (linea1+4)->id = "5";
            (linea1+4)->nombre = "Hermanas Mirabal (Parque Mirador Norte)";
            (linea1+4)->km=0.91;

            (linea1+5)->id = "6";
            (linea1+5)->nombre = "Máximo Gómez (La Isabela)";
            (linea1+5)->km=0.91;

            (linea1+6)->id = "7";
            (linea1+6)->nombre = "Los Taínos (Villas Agrícolas, Av. Nicolás de Ovando)";
            (linea1+6)->km=0.91;

            (linea1+7)->id = "8";
            (linea1+7)->nombre = "Pedro Livio Cedeño (Cementerio Nacional)";
            (linea1+7)->km=0.91;

            (linea1+8)->id = "9";
            (linea1+8)->nombre = "Manuel Arturo Peña Batlle (Villa Juana)";
            (linea1+8)->km=0.91;

            (linea1+9)->id = "10";
            (linea1+9)->nombre = "Juan Pablo Duarte (Centro Olímpico, Av. John F. Kennedy)";
            (linea1+9)->km=0.91;

            (linea1+10)->id = "11";
            (linea1+10)->nombre = "Juan Bosch (Av. 27 de Febrero)";
            (linea1+10)->km=0.91;

            (linea1+11)->id = "12";
            (linea1+11)->nombre = "Casandra Damirón (Teatro Nacional y Plaza de la Cultura)";
            (linea1+11)->km=0.91;

            (linea1+12)->id = "13";
            (linea1+12)->nombre = "Joaquín Balaguer (Ministerio de Educación)";
            (linea1+12)->km=0.91;

            (linea1+13)->id = "14";
            (linea1+13)->nombre = "Amín Abel (UASD)";
            (linea1+13)->km=0.91;

            (linea1+14)->id = "15";
            (linea1+14)->nombre = "Francisco Alberto Caamaño (Universidad Domínico Americana)";
            (linea1+14)->km=0.91;

            (linea1+15)->id = "16";
            (linea1+15)->nombre = "Centro de los Héroes";
            (linea1+15)->km=0.91;



            cout<<"***Estaciones del metro de la linea 1***"<<endl;

            int numEstaciones= 15; //esto porque solo llené tres, luego tu completas con 6
            for (int i=0 ; i < numEstaciones; i++ )
            {
                cout<<"[ID: "<<(linea1+i)->id<<"] NOMBRE: "<<(linea1+i)->nombre<<endl;
            }
            cout<<endl;
            string estacion1;
            string estacion2;

            cout<<"Ingrese el numero de la estacion uno (punto de partida)"<<endl;
            cin >> estacion1;
            cout<<"Ingrese l numero de la estacion dos (punto de llegada)"<<endl;
            cin >> estacion2;


            if(!verificar_estacion_valida(estacion1, estacion2))
            {
                break;
            }

            int estacionUno;
            int estacionDos;

            for (int i=0 ; i < numEstaciones; i++ )
            {
                if(estacion1.compare((linea1+i)->id)==0)
                    estacionUno = i;
                if(estacion2.compare((linea1+i)->id)==0)
                    estacionDos = i;
            }
            cout<<endl;

            //Saber en que direccion va el pasajero
            int estaciones_recorridas;
            if(estacionDos < estacionUno)
            {
                estaciones_recorridas = estacionUno - estacionDos;
            }
            else
            {
                estaciones_recorridas = estacionDos - estacionUno;
            }

            cout<<"Estaciones recorridas: " <<estaciones_recorridas <<endl;
            cout <<"Estacion 1 es " << (linea1+estacionUno)->nombre << endl;
            cout <<"Estacion 2 es " << (linea1+estacionDos)->nombre << endl;

            cout<<endl;
            float tiempo = ((linea1+estacionDos)->km * estaciones_recorridas)  / (linea1+estacionDos)->velocidad ;
            tiempo = tiempo * 60;


            cout <<"El metro va a una velocidad constante de: " <<(linea1+estacionUno)->velocidad <<"km/h" <<endl;
            cout <<"Tiempo (minutos): " << tiempo <<endl;
            cout <<"Distancia total recorrida " << (linea1+estacionDos)->km * estaciones_recorridas << " KM" <<endl;
            cout<<endl;
            delete[] linea1;

            pausar_ejecucion();
        }

        break;
        case 2:
        {
            BorraPantalla();

            struct datosEstacion *linea2;

            linea2= new datosEstacion[14];

            linea2->id = "1";
            linea2->nombre ="María Montez (Av. Gregorio Luperón)";
            linea2->km=0;

            (linea2+1)->id="2";
            (linea2+1)->nombre="Pedro Francisco Bono (Av. Nuñez de Cáceres)";
            (linea2+1)->km=2.42;

            (linea2+2)->id = "3";
            (linea2+2)->nombre = "Francisco Gregorio Billini (Calle Dr. Defilló)";
            (linea2+2)->km=2.42;

            (linea2+3)->id = "4";
            (linea2+3)->nombre = "Ulises F. Espaillat (Av. Winston Churchill)";
            (linea2+3)->km=2.42;

            (linea2+4)->id = "5";
            (linea2+4)->nombre = "Pedro Mir (Av. Abraham Lincoln)";
            (linea2+4)->km=2.42;

            (linea2+5)->id = "6";
            (linea2+5)->nombre = "Freddy Beras Goico (Av. Lope de Vega)";
            (linea2+5)->km=2.42;

            (linea2+6)->id = "7";
            (linea2+6)->nombre = "Juan Ulises García (Av. Ortega y Gasset)";
            (linea2+6)->km=2.42;

            (linea2+7)->id = "8";
            (linea2+7)->nombre = "Juan Pablo Duarte (Centro Olímpico, Av. John F. Kennedy)";
            (linea2+7)->km=2.42;

            (linea2+8)->id = "9";
            (linea2+8)->nombre = "Coronel Rafael Tomas Fernández (Av. San Martín)";
            (linea2+8)->km=2.42;

            (linea2+9)->id = "10";
            (linea2+9)->nombre = "Mauricio Baez (Escuela Rep. Dominicana)";
            (linea2+9)->km=2.42;

            (linea2+10)->id = "11";
            (linea2+10)->nombre = "Ramón Cáceres (Av. Duarte)";
            (linea2+10)->km=2.42;

            (linea2+11)->id = "12";
            (linea2+11)->nombre = "Horacio Vásquez (Calle Josefa Brea)";
            (linea2+11)->km=2.42;

            (linea2+12)->id = "13";
            (linea2+12)->nombre = "Manuel de Jesús Abreu Galvan (Calle Julio de Peña Valdez)";
            (linea2+12)->km=2.42;

            (linea2+13)->id = "14";
            (linea2+13)->nombre = "Eduardo Brito (Av. Francisco del Rosario Sánchez)";
            (linea2+13)->km=2.42;



            cout<<"***Estaciones del metro de la linea 1***"<<endl;

            int numEstaciones= 13; //esto porque solo llené tres, luego tu completas con 6
            for (int i=0 ; i < numEstaciones; i++ )
            {
                cout<<"[ID: "<<(linea2+i)->id<<"] NOMBRE: "<<(linea2+i)->nombre<<endl;
            }
            cout<<endl;
            string estacion1;
            string estacion2;

            cout<<"Ingrese el numero de la estacion uno (punto de partida)"<<endl;
            cin >> estacion1;
            cout<<"Ingrese l numero de la estacion dos (punto de llegada)"<<endl;
            cin >> estacion2;

            if(!verificar_estacion_valida(estacion1, estacion2))
            {
                break;
            }


            int estacionUno;
            int estacionDos;

            for (int i=0 ; i < numEstaciones; i++ )
            {
                if(estacion1.compare((linea2+i)->id)==0)
                    estacionUno = i;
                if(estacion2.compare((linea2+i)->id)==0)
                    estacionDos = i;
            }
            cout<<endl;

            //Saber en que direccion va el pasajero
            int estaciones_recorridas;
            if(estacionDos < estacionUno)
            {
                estaciones_recorridas = estacionUno - estacionDos;
            }
            else
            {
                estaciones_recorridas = estacionDos - estacionUno;
            }

            cout<<"Estaciones recorridas: " <<estaciones_recorridas <<endl;
            cout <<"Estacion 1 es " << (linea2+estacionUno)->nombre << endl;
            cout <<"Estacion 2 es " << (linea2+estacionDos)->nombre << endl;

            cout<<endl;
            float tiempo = ((linea2+estacionDos)->km * estaciones_recorridas)  / (linea2+estacionDos)->velocidad ;
            tiempo = tiempo * 60;


            cout <<"El metro va a una velocidad constante de: " <<(linea2+estacionUno)->velocidad <<"km/h" <<endl;
            cout <<"Tiempo (minutos): " << tiempo <<endl;
            cout <<"Distancia total recorrida " << (linea2+estacionDos)->km * estaciones_recorridas << " KM" <<endl;
            cout<<endl;
            delete[] linea2;

            pausar_ejecucion();
        }
        break;
        }
    }
    while(opcion_menu != 0);

    return 0;
}
