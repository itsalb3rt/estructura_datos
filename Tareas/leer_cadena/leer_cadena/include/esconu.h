/*
 *  esconu.h
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
 *  correspondientes a los componentes del software no
 *  escritos por el autor, utilizados en este software,
 *  enumerados a continuacion:
 *
 *  iostream.h
 *  conio.h
 *  windows.h
 *
 */

#ifndef ESCONU_H
#define ESCONU_H

#include "esconu.cpp"

void CoordenadaXY (int, int);
void BorraPantalla ();
void ColorTexto (int);
void ColorFondoTexto (int);
void Parpadeo();
void NoParpadeo();
int  LeeCaracter ();
int  LeeCaracterEco ();
void PresionaTecla (string);
void Bip ();

#endif
