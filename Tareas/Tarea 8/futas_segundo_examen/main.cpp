
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using  namespace  std ;
//utilitario

void limpiar_pantalla() {
    system("cls");
}
main() {
    string Nombre;
    set<string> vendedor_a;
    set<string> vendedor_b;
    set<string> vendedor_c;
    set<string> Set3;
    set<string> Set4;
    set<string> todas_ventas_a;
    set<string> todas_ventas_b;
    set<string> todas_ventas_c;
    set<string> Set7;
    set<string> Set8;
    set<string> Set9;
    string A,B,venta_a,venta_b,venta_c;

    int opcion,operacion_0 = 1,operacion_1 = 1,operacion_2 = 1,operacion_3 = 1,operacion_4 = 1;
/*
    vendedor_a.insert("mango");
    vendedor_a.insert("manzana");
    vendedor_a.insert("pera");
    vendedor_a.insert("uva");
    vendedor_a.insert("zapote");

    vendedor_b.insert("manzana");
    vendedor_b.insert("uva");
    vendedor_b.insert("limon");
    vendedor_b.insert("pina");
    vendedor_b.insert("lechoza");

    vendedor_c.insert("manzana");
    vendedor_c.insert("melon");
    vendedor_c.insert("melocoton");
    vendedor_c.insert("kiwi");
    vendedor_c.insert("mamon");
*/
    do {
        limpiar_pantalla();
        cout <<" MENU";
        cout <<"\n[1]  Anadir fruta al vendedor A";
        cout <<"\n[2]  Anadir fruta al vendedor B";
        cout <<"\n[3]  Anadir fruta al vendedor C";
        cout <<"\n[4]  Ver nombre de frutas vendedor A";
        cout <<"\n[5]  Ver nombre de frutas vendedor B";
        cout <<"\n[6]  Ver nombre de frutas vendedor C";
        cout <<"\n[7]  Cantidad de frutas vendidas por A";
        cout <<"\n[8]  Cantidad de frutas vendidas por B";
        cout <<"\n[9]  Cantidad de frutas vendidas por C";
        cout <<"\n[10] Cantidad de frutas que vende A, B y C";
        cout <<"\n[11] Frutas que vende A que B y C NO";
        cout <<"\n[12] Fruta que vende B que A y C NO";
        cout <<"\n[13] Fruta que vende C que A y B NO";
        cout <<"\n[14] Comprar frutas al vendedor A";
        cout <<"\n[15] Comprar frutas al vendedor B";
        cout <<"\n[16] Comprar frutas al vendedor C";
        cout <<"\n[17] Ventas del vendedor A  ";
        cout <<"\n[18] Ventas del vendedor B  ";
        cout <<"\n[19] Ventas del vendedor C  ";
        cout <<"\n[20] Ver quien vendio mas frutas  ";
        cout <<"\n[21] Ver el total de ventas de todos";
        cout <<"\n[22] Ver % de ventas";
        cout <<"\n[23] Moda de frutas";
        cout<<endl;
        cout<<"---------------------------------";
        cout<<endl;
        cout <<"\n\[0] Para SALIR: ";

        cin >> opcion;

        switch(opcion) {
        case 1: {
            limpiar_pantalla();
            while(operacion_0!=0) {
                cout <<"\nASIGNE FRUTAS PARA VENDEDOR A ";
                cin>> A;
                vendedor_a.insert(A);
                cout <<"\nIngrese 0 y pulse enter para salir: ";
                cin>> operacion_0;
            }
        }
        operacion_0 = 1;
        break;
        case 2: {
            limpiar_pantalla();
            while(operacion_1!=0) {
                cout <<"\nASIGNE FRUTAS PARA VENDEDOR B: ";
                cin>> B;
                cout <<"\nIngrese 0 y pulse enter para salir: ";
                cin>> operacion_1;
                vendedor_b.insert( B);
            }
            operacion_1=2;
        }
        operacion_1 = 1;
        break;
        case 3: {
            limpiar_pantalla();
            while(operacion_1!=0) {
                cout <<"\nASIGNE FRUTAS PARA VENDEDOR B: ";
                cin>> B;
                cout <<"\nIngrese 0 y pulse enter para salir: ";
                cin>> operacion_1;
                vendedor_c.insert( B);
            }
            operacion_1=2;
        }
        operacion_1 = 1;
        break;
        case 4: {
            int cont;
            limpiar_pantalla();
            cout <<"\n\nLAS FRUTAS QUE VENDE EL VENDEDORA A\n";
            set<string>::iterator iter4;
            for(iter4 = vendedor_a.begin(); iter4!= vendedor_a.end(); iter4++) {
                cont++;
                cout <<""<<cont<<"-"<< *iter4 << endl;
            }
            cout <<endl;
            system("pause");
        }
        break;
        case 5: {
            limpiar_pantalla();
            int cont1 = 0;
            cout <<"\n\nLAS FRUTAS QUE VENDE EL VENDEDORA B\n";
            set<string>::iterator iter5;
            for(iter5 = vendedor_b.begin(); iter5!= vendedor_b.end(); iter5++) {
                cont1++;
                cout <<""<<cont1<<"-"<< *iter5 << endl;
            }
            cout <<endl;
            system("pause");
        }
        break;
        case 6: {
            limpiar_pantalla();
            int cont1 = 0;
            cout <<"\n\nLAS FRUTAS QUE VENDE EL VENDEDORA C\n";
            set<string>::iterator iter5;
            for(iter5 = vendedor_c.begin(); iter5!= vendedor_c.end(); iter5++) {
                cont1++;
                cout <<""<<cont1<<"-"<< *iter5 << endl;
            }
            cout <<endl;
            system("pause");
        }
        break;
        case 7: {
            int cont = 0;
            limpiar_pantalla();;
            cout <<"\nNUMERO DE FRUTA QUE VENDE A\n\n";
            set<string>::iterator iter1;
            for(iter1 = vendedor_a.begin(); iter1 != vendedor_a.end(); iter1++) {
                cont++;   //cuenta los #1
            }
            cout <<""<< cont << endl;
            cout <<"\n\n";
            system("pause");
        }
        break;
        case 8: {
            int cont1= 0;
            limpiar_pantalla();
            cout <<"\nNUMERO DE FRUTA QUE VENDE B\n\n";
            set<string>::iterator iter2;
            for(iter2 = vendedor_b.begin(); iter2 != vendedor_b.end(); iter2++) {
                cont1++;//cuenta los #2
            }

            cout <<""<< cont1 << endl;
            system("pause");
        }
        break;
        case 9: {
            int cont1= 0;
            limpiar_pantalla();
            cout <<"\nNUMERO DE FRUTA QUE VENDE C\n\n";
            set<string>::iterator iter2;
            for(iter2 = vendedor_c.begin(); iter2 != vendedor_c.end(); iter2++) {
                cont1++;//cuenta los #2
            }

            cout <<""<< cont1 << endl;
            system("pause");
        }
        break;
        case 10: {
            int cont = 0;
            limpiar_pantalla();
            cout <<"Numero de frutas de todos los vendedores" <<endl;
            set<string>::iterator iter1;
            for(iter1 = vendedor_a.begin(); iter1 != vendedor_a.end(); iter1++) {
                cont++;   //cuenta los #1
            }
            set<string>::iterator iter2;
            for(iter2 = vendedor_b.begin(); iter2 != vendedor_b.end(); iter2++) {
                cont++;   //cuenta los #2
            }
            set<string>::iterator iter3;
            for(iter3 = vendedor_c.begin(); iter3 != vendedor_c.end(); iter3++) {
                cont++;   //cuenta los #2
            }

            cout << cont << endl;
            cout <<endl;
            system("pause");
        }
        break;
        case 11: {
            limpiar_pantalla();
            set<string> Setc1; //pa salir del paso y contar las frutas que tiene A y C no tiene.... examen
            set<string>iguales;
            cout<<endl;
            cout <<"Frutas que vende A  que  B y C no vende" <<endl;

            set_difference(vendedor_a.begin(),vendedor_a.end(),vendedor_b.begin(),vendedor_b.end(), inserter(Set3,Set3.begin()) );
            set_difference(Set3.begin(),Set3.end(),vendedor_c.begin(),vendedor_c.end(), inserter(Setc1,Setc1.begin()) );

            set_intersection(Set3.begin(),Set3.end(),Setc1.begin(),Setc1.end(),inserter(iguales,iguales.begin()));

            set<string>::iterator iter3;
            for(iter3 = iguales.begin(); iter3 != iguales.end(); iter3++) {
                cout <<" " <<*iter3 << endl;
            }

            system("pause");
        }
        break;
        case 12: {
            limpiar_pantalla();
            set<string> Setc1; //pa salir del paso y contar las frutas que tiene A y C no tiene.... examen
            set<string>iguales;
            cout<<endl;
            cout <<"Frutas que vende B  que  A y C no vende\n\n";
            set_difference(vendedor_b.begin(),vendedor_b.end(),vendedor_a.begin(),vendedor_a.end(), inserter(Set4,Set4.begin()) );
            set_difference(Set4.begin(),Set4.end(),vendedor_c.begin(),vendedor_c.end(), inserter(Setc1,Setc1.begin()) );

            set_intersection(Set4.begin(),Set4.end(),Setc1.begin(),Setc1.end(),inserter(iguales,iguales.begin()));

            set<string>::iterator iter6;
            for(iter6 = iguales.begin(); iter6 != iguales.end(); iter6++) {
                cout <<" " <<*iter6 << endl;
            }
            system("pause");
        }
        break;
        case 13: {
            limpiar_pantalla();
            set<string> Setc1; //pa salir del paso y contar las frutas que tiene A y C no tiene.... examen
            set<string>iguales;
            cout<<endl;
            cout <<"Frutas que vende C  que  A y B no vende\n\n";
            set_difference(vendedor_c.begin(),vendedor_c.end(),vendedor_a.begin(),vendedor_a.end(), inserter(Set4,Set4.begin()) );
            set_difference(Set4.begin(),Set4.end(),vendedor_b.begin(),vendedor_b.end(), inserter(Setc1,Setc1.begin()) );

            set_intersection(Set4.begin(),Set4.end(),Setc1.begin(),Setc1.end(),inserter(iguales,iguales.begin()));

            set<string>::iterator iter7;
            for(iter7 = iguales.begin(); iter7 != iguales.end(); iter7++) {
                cout <<" " <<*iter7 << endl;
            }
            system("pause");
        }
        break;
        case 14: {
            while(operacion_2!=0) {
                int cont = 0,cont2 = 0;
                limpiar_pantalla();
                cout <<"Frutas en venta A\n";
                set<string>::iterator iter4;
                for(iter4 = vendedor_a.begin(); iter4!= vendedor_a.end(); iter4++) {
                    cont++;
                    cout <<""<<cont<<"-"<< *iter4 << endl;
                }
                cout <<"\nDigite el numero de la fruta a comprar: ";
                cin>> venta_a;
                todas_ventas_a.insert(venta_a);
                cout <<"\nIngrese 0 y pulse enter para salir: ";
                cin>> operacion_2;
                cont2++;
            }
        }
        operacion_2 = 1;
        break;
        case 15: {
            while(operacion_3!=0) {
                int cont1 = 0,cont3 = 0;
                limpiar_pantalla();
                cout <<"\n\nFrutas en venta B\n";
                set<string>::iterator iter5;
                for(iter5 = vendedor_b.begin(); iter5!= vendedor_b.end(); iter5++) {
                    cont1++;
                    cout <<""<<cont1<<"-"<< *iter5 << endl;
                }
                cout <<"\nDigite el numero de la fruta a comprar: ";
                cin>> venta_b;
                todas_ventas_b.insert(venta_b);
                cout <<"\nIngrese 0 y pulse enter para salir: ";
                cin>> operacion_3;
                cont3++;

            }
        }
        operacion_3 = 1;
        break;
        case 16: {
            while(operacion_4!=0) {
                int cont1 = 0,cont3 = 0;
                limpiar_pantalla();
                cout <<"\n\nFrutas en venta C\n";
                set<string>::iterator iter5;
                for(iter5 = vendedor_c.begin(); iter5!= vendedor_c.end(); iter5++) {
                    cont1++;
                    cout <<""<<cont1<<"-"<< *iter5 << endl;
                }
                cout <<"\nDigite el numero de la fruta a comprar: ";
                cin>> venta_c;
                todas_ventas_c.insert(venta_c);
                cout <<"\nIngrese 0 y pulse enter para salir: ";
                cin>> operacion_4;
                cont3++;

            }
        }
        operacion_4 = 1;
        break;
        case 17: {
            limpiar_pantalla();
            cout <<"Frutas vendidas por A" <<endl;
            set_difference(vendedor_a.begin(),vendedor_a.end(),todas_ventas_a.begin(),todas_ventas_a.end(), inserter(Set7,Set7.begin()) );
            set<string>::iterator iter7;
            for(iter7 = todas_ventas_a.begin(); iter7 != todas_ventas_a.end(); iter7++) {
                cout <<" " <<*iter7 << endl;
            }
            system("pause");
        }
        break;
        case 18: {
            limpiar_pantalla();
            cout <<"Frutas vendidas po B " <<endl;
            set_difference(vendedor_b.begin(),vendedor_b.end(),todas_ventas_b.begin(),todas_ventas_b.end(), inserter(Set7,Set7.begin()) );
            set<string>::iterator iter8;
            for(iter8 = todas_ventas_b.begin(); iter8 != todas_ventas_b.end(); iter8++) {
                cout <<" " <<*iter8 << endl;
            }
            system("pause");
        }
        break;
        case 19: {
            limpiar_pantalla();
            cout <<"Frutas vendidas po C " <<endl;
            set_difference(vendedor_c.begin(),vendedor_c.end(),todas_ventas_c.begin(),todas_ventas_c.end(), inserter(Set9,Set9.begin()) );
            set<string>::iterator iter9;
            for(iter9 = todas_ventas_c.begin(); iter9 != todas_ventas_c.end(); iter9++) {
                cout <<" " <<*iter9 << endl;
            }
            system("pause");
        }
        break;
        case 20: {
            limpiar_pantalla();

            if(todas_ventas_a.size() > todas_ventas_b.size() && todas_ventas_a.size() > todas_ventas_c.size()) {
                cout <<"El vendedor A ha vendido mas frutas: " <<todas_ventas_a.size()<<endl;
            } else if(todas_ventas_b.size() > todas_ventas_a.size() && todas_ventas_b.size() > todas_ventas_c.size()) {
                cout <<"El vendedor B ha vendido mas frutas: " <<todas_ventas_b.size()<<endl;
            } else if(todas_ventas_c.size() > todas_ventas_a.size() && todas_ventas_c.size() > todas_ventas_b.size()) {
                cout <<"El vendedor C ha vendido mas frutas: " <<todas_ventas_c.size()<<endl;
            } else
                cout <<"Todos los vendedores han vendido la misma cantidad" <<endl;
            system("pause");
        }
        break;
        case 21: {
            limpiar_pantalla();
            int ventas=todas_ventas_a.size() + todas_ventas_b.size() + todas_ventas_c.size();
            cout <<"\nCantidad de frutas A, B y C FUERON\n "<< ventas<<"\n ";

            system("pause");
        }
        break;
        case 22: {

            limpiar_pantalla();
            int ventas_a = todas_ventas_a.size();
            int ventas_b = todas_ventas_b.size();
            int ventas_c = todas_ventas_c.size();
            float resultado_porciento_a = 0;
            float resultado_porciento_b = 0;
            float resultado_porciento_c = 0;
            int ventas_totales = ventas_a + ventas_b + ventas_c;

            cout <<"\nTotal de ventas \n "<< ventas_totales<<endl;
            if(ventas_a > 0 ) {
                resultado_porciento_a = ventas_a / ventas_totales;
                cout<<"A) Ventas totales: " << ventas_a << ". porciento ventas : " << (resultado_porciento_a / ventas_totales) <<endl;
            }

            if(ventas_b > 0 ) {
                resultado_porciento_b = ventas_b / ventas_totales;
                cout<<"B) Ventas totales: " <<ventas_b<< ". porciento ventas : " << (resultado_porciento_b / ventas_totales) <<endl;
            }

            if(ventas_c > 0 ) {
                resultado_porciento_c = ventas_c / ventas_totales;
                cout<<"C) Ventas totales: " <<ventas_c<< ". porciento ventas : " << (resultado_porciento_c / ventas_totales) <<endl;
            }

            system("pause");
        }
        break;
        case 23:
            cout<<"Muy pronto" <<endl;
            break;
        }
    } while(opcion!=0);

    cin.get();
    cin.get();

    return 0;
}
