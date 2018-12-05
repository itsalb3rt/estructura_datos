/*
 *  esconu.cpp
 *  esconu
 *
 *  Entrada Salida Consola Universal
 *  Version 1.0 para Microsoft Windows
 *
 *  Creado por Andrés Enrique Linares Félix el 01/04/2015.
 *  Copyright (c) 2015 CLIC, s.a. All rights reserved.
 *
 *  Se autoriza la utilizacion, copia, distribucion y
 *  modificacion de este software para cualquier fin
 *  siempre y cuando se acepte tal como se distribuye,
 *  sin garantias ni soporte de ningun tipo por parte del
 *  autor.
 *
 *  El usuario tambien acepta las licencias de terceros
 *  correspondientes a los componenetes del software no
 *  escritos por el autor, utilizados en este software,
 *  enumerados a continuacion:
 *
 *  iostream.h
 *  conio.h
 *  windows.h
 *
 */

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

enum
{
    NEGRO,
    ROJO,
    VERDE,
    AMARILLO,
    AZUL,
    MAGENTA,
    CIAN,
    BLANCO,
    NEGROCLARO,
    ROJOCLARO,
    VERDECLARO,
    AMARILLOCLARO,
    AZULCLARO,
    MAGENTACLARO,
    CIANCLARO,
    BLANCOCLARO,
    PREESTABLECIDO
};



void CoordenadaXY (int x, int y)
{
    /*
        Posiciona el cursor de texto en la columna correspondiente al valor
        entero del parametro x, y en la fila correspondiente al parametro y.
        La funcion asume que la terminal solo dispone de 80 columnas y 24
        filas, por lo que cualquier valor fuera de esos limites se asume
        como columna 1 y fila 1.
    */

    COORD coordenada;

    if (x < 1 || x > 80 || y < 1 || y > 24)
    {
        x = 1;
        y = 1;
    }

    coordenada.X = x;
    coordenada.Y = y;
    SetConsoleCursorPosition (GetStdHandle ( STD_OUTPUT_HANDLE),
                              coordenada);
}

void BorraPantalla ()
{
    /*
        Limpia el contenido visible de la terminal y coloca el cursor en la
        la esquina superior izquierda (columna 1, fila 1).
    */
    system ("cls");
    CoordenadaXY (1, 1);

}


void ColorTexto (int color)
{
    /*
        Cambia el color del texo en la terminal a uno de los
        16 colores soportados del estandar ANSI.  La enumeracion de los
        colores comienza en 0 y termina en 15.

        Los colores se corresponden con la enumeracion definida en esta
        biblioteca, de la siguiente manera:

        0 --> NEGRO                  8 --> NEGROCLARO
        1 --> ROJO                   9 --> ROJOCLARO
        2 --> VERDE                 10 --> VERDECLARO
        3 --> AMARILLO              11 --> AMARILLOCLARO
        4 --> AZUL                  12 --> AZULCLARO
        5 --> MAGENTA               13 --> MAGENTACLARO
        6 --> CIAN                  14 --> CIANCLARO
        7 --> BLANCO                15 --> BLANCOCLARO
                            Otro valor --> PREESTABLECIDO

        Nota, cualquier otro valor (PREESTABLECIDO) reestablece el valor del
        color seleccionado para la terminal, cualquiera que este sea.
    */

    int valorColor;

    switch (color)
    {
        case  0 : valorColor =  0; break;
        case  1 : valorColor =  4; break;
        case  2 : valorColor =  2; break;
        case  3 : valorColor =  6; break;
        case  4 : valorColor =  1; break;
        case  5 : valorColor =  5; break;
        case  6 : valorColor =  3; break;
        case  7 : valorColor =  7; break;
        case  8 : valorColor =  8; break;
        case  9 : valorColor = 12; break;
        case 10 : valorColor = 10; break;
        case 11 : valorColor = 14; break;
        case 12 : valorColor =  9; break;
        case 13 : valorColor = 13; break;
        case 14 : valorColor = 11; break;
        case 15 : valorColor = 15; break;
        default : valorColor = 7;
    }

    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), valorColor);
}


void ColorFondoTexto (int color)
{
    /*
        Cambia el color del fondo del texo en la terminal a uno de los
        16 colores soportados del estandar ANSI.  La enumeracion de los
        colores comienza en 0 y termina en 15.

        Los colores se corresponden con la enumeracion definida en esta
        biblioteca, de la siguiente manera:

        0 --> NEGRO                  8 --> NEGROCLARO
        1 --> ROJO                   9 --> ROJOCLARO
        2 --> VERDE                 10 --> VERDECLARO
        3 --> AMARILLO              11 --> AMARILLOCLARO
        4 --> AZUL                  12 --> AZULCLARO
        5 --> MAGENTA               13 --> MAGENTACLARO
        6 --> CIAN                  14 --> CIANCLARO
        7 --> BLANCO                15 --> BLANCOCLARO
                            Otro valor --> PREESTABLECIDO

        Nota, cualquier otro valor (PREESTABLECIDO) reestablece el valor del
        color seleccionado para la terminal, cualquiera que este sea.
    */

    CONSOLE_SCREEN_BUFFER_INFO Informacion;
    int valorColor;

    switch (color)
    {
        case  0 : valorColor =  0; break;
        case  1 : valorColor =  4; break;
        case  2 : valorColor =  2; break;
        case  3 : valorColor =  6; break;
        case  4 : valorColor =  1; break;
        case  5 : valorColor =  5; break;
        case  6 : valorColor =  3; break;
        case  7 : valorColor =  7; break;
        case  8 : valorColor =  8; break;
        case  9 : valorColor = 12; break;
        case 10 : valorColor = 10; break;
        case 11 : valorColor = 14; break;
        case 12 : valorColor =  9; break;
        case 13 : valorColor = 13; break;
        case 14 : valorColor = 11; break;
        case 15 : valorColor = 15; break;
        default : valorColor = 7;
    }

    GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Informacion);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            (Informacion.wAttributes & 0x0F) | (valorColor << 4));
}



void Parpadeo()
{
    /*
        Cambia el modo de la terminal a caracteres parpadentes a partir
        de la llamada a la funcion.
    */

    //Funcion no implementada en la version para Windows.
}



void NoParpadeo()
{
    /*
        Cambia el modo de la terminal a caracteres NO parpadentes a partir
        de la llamada a la funcion.
    */

    //Funcion no implementada en la version para Windows.
}




int LeeCaracter ()
{
    /*
        No fue necesario inplementar la funcion. Solo se hizo un
        wrap a la funcion getch() existente.
    */

    int caracter;
    caracter = getch();
    return caracter;
}



int LeeCaracterEco ()
{
    /*
        No fue necesario inplementar la funcion. Solo se hizo un
        wrap a la funcion getche() existente.
    */

    int caracter;
    caracter = getche();
    return caracter;
}


void TeclaPresionada (string mensaje)
{
    /*
        Despliega la cadena de caracteres del parametro "mensaje" y
        espera a que se presione una tecla cuyo valor no es retornado.
    */

    cout << mensaje;
    LeeCaracter ();
}


void Bip ()
{
    /*
        Escribe en consola el caracter "007" correspondiente a la campana.
    */

    cout << "\007";
}

