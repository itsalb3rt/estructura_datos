
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
    set<string> Set1;
    set<string> Set2;
    set<string> Set3;
    set<string> Set4;
    set<string> todas_ventas_a;
    set<string> todas_ventas_b;
    set<string> Set7;
    set<string> Set8;
    string A,B,venta_a,venta_b;

    int opcion,operacion_0 = 1,operacion_1 = 1,operacion_2 = 1,operacion_3 = 1;

    Set1.insert("Mango");
    Set1.insert("Manzana");
    Set1.insert("Pera");
    Set1.insert("Uva");
    Set1.insert("Zapote");

    Set2.insert("Manzana");
    Set2.insert("Uva");
    Set2.insert("Limon");
    Set2.insert("Pina");
    Set2.insert("Lechoza");

    do {
        limpiar_pantalla();
        cout <<" MENU";
        cout <<"\n[1]  Anadir fruta al vendedor A";
        cout <<"\n[2]  Anadir fruta al vendedor B";
        cout <<"\n[3]  Ver nombre de frutas vendedor A";
        cout <<"\n[4]  Ver nombre de frutas vendedor B";
        cout <<"\n[5]  Cantidad de frutas vendidas por A";
        cout <<"\n[6]  Cantidad de frutas vendidas por B";
        cout <<"\n[7]  Cantidad de frutas que vende A Y B";
        cout <<"\n[8]  Frutas que vende A Y B NO";
        cout <<"\n[9]  Fruta que vende B Y A NO";
        cout <<"\n[10] Comprar frutas al vendedor A";
        cout <<"\n[11] Comprar frutas al vendedor B";
        cout <<"\n[12] Ventas del vendedor A  ";
        cout <<"\n[13] Ventas del vendedor B  ";
        cout <<"\n[14] Ver quien vendio mas frutas  ";
        cout <<"\n[15] Ver el total de ventas de ambos";
        cout <<"\n[16] Ver % de ventas";
        cout <<"\n\[0]  Para SALIR: ";

        cin >> opcion;

        switch(opcion) {
        case 1: {
            limpiar_pantalla();
            while(operacion_0!=0) {
                cout <<"\nASIGNE FRUTAS PARA VENDEDOR A ";
                cin>> A;
                Set1.insert(A);
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
                Set2.insert( B);
            }
            operacion_1=2;
        }
        operacion_1 = 1;
        break;
        case 3: {
            int cont;
            limpiar_pantalla();
            cout <<"\n\nLAS FRUTAS QUE VENDE EL VENDEDORA A\n";
            set<string>::iterator iter4;
            for(iter4 = Set1.begin(); iter4!= Set1.end(); iter4++) {
                cont++;
                cout <<""<<cont<<"-"<< *iter4 << endl;
            }
            cout <<endl;
            system("pause");
        }
        break;
        case 4: {
            limpiar_pantalla();
            int cont1 = 0;
            cout <<"\n\nLAS FRUTAS QUE VENDE EL VENDEDORA B\n";
            set<string>::iterator iter5;
            for(iter5 = Set2.begin(); iter5!= Set2.end(); iter5++) {
                cont1++;
                cout <<""<<cont1<<"-"<< *iter5 << endl;
            }
            cout <<endl;
            system("pause");
        }
        break;
        case 5: {
            int cont = 0;
            limpiar_pantalla();;
            cout <<"\nNUMERO DE FRUTA QUE VENDE A\n\n";
            set<string>::iterator iter1;
            for(iter1 = Set1.begin(); iter1 != Set1.end(); iter1++) {
                cont++;   //cuenta los #1
            }
            cout <<""<< cont << endl;
            cout <<"\n\n";
            system("pause");
        }
        break;
        case 6: {
            int cont1= 0;
            limpiar_pantalla();
            cout <<"\nNUMERO DE FRUTA QUE VENDE B\n\n";
            set<string>::iterator iter2;
            for(iter2 = Set2.begin(); iter2 != Set2.end(); iter2++) {
                cont1++;//cuenta los #2
            }

            cout <<""<< cont1 << endl;
            system("pause");
        }
        break;
        case 7: {
            int cont = 0,cont1 = 0;
            limpiar_pantalla();
            cout <<"Numero de frutas de ambos vendedores A Y B" <<endl;
            set<string>::iterator iter1;
            for(iter1 = Set1.begin(); iter1 != Set1.end(); iter1++) {
                cont++;   //cuenta los #1
            }
            set<string>::iterator iter2;
            for(iter2 = Set2.begin(); iter2 != Set2.end(); iter2++) {
                cont1++;   //cuenta los #2
            }

            cout << cont1+cont << endl;
            cout <<endl;
            system("pause");
        }
        break;
        case 8: {
            limpiar_pantalla();
            cout<<endl;
            cout <<"Frutas que vende A  que  B no vende" <<endl;
            set_difference(Set1.begin(),Set1.end(),Set2.begin(),Set2.end(), inserter(Set3,Set3.begin()) );
            set<string>::iterator iter3;
            for(iter3 = Set3.begin(); iter3 != Set3.end(); iter3++) {
                cout <<" " <<*iter3 << endl;
            }
            system("pause");
        }
        break;
        case 9: {
            limpiar_pantalla();
            cout<<endl;
            cout <<"Frutas que vende B  que  A no vende\n\n";
            set_difference(Set2.begin(),Set2.end(),Set1.begin(),Set1.end(), inserter(Set4,Set4.begin()) );
            set<string>::iterator iter6;
            for(iter6 = Set4.begin(); iter6 != Set4.end(); iter6++) {
                cout <<" " <<*iter6 << endl;
            }
            system("pause");
        }
        break;
        case 10: {
            while(operacion_2!=0) {
                int cont = 0,cont2 = 0;
                limpiar_pantalla();
                cout <<"Frutas en venta A\n";
                set<string>::iterator iter4;
                for(iter4 = Set1.begin(); iter4!= Set1.end(); iter4++) {
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
        case 11: {
            while(operacion_3!=0) {
                int cont1 = 0,cont3 = 0;
                limpiar_pantalla();
                cout <<"\n\nFrutas en venta B\n";
                set<string>::iterator iter5;
                for(iter5 = Set2.begin(); iter5!= Set2.end(); iter5++) {
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
        case 12: {
            limpiar_pantalla();
            cout <<"Frutas vendidas por A" <<endl;
            set_difference(Set1.begin(),Set1.end(),todas_ventas_a.begin(),todas_ventas_a.end(), inserter(Set7,Set7.begin()) );
            set<string>::iterator iter7;
            for(iter7 = todas_ventas_a.begin(); iter7 != todas_ventas_a.end(); iter7++) {
                cout <<" " <<*iter7 << endl;
            }
            system("pause");
        }
        break;
        case 13: {
            limpiar_pantalla();
            cout <<"Frutas vendidas po B " <<endl;
            set_difference(Set2.begin(),Set2.end(),todas_ventas_b.begin(),todas_ventas_b.end(), inserter(Set7,Set7.begin()) );
            set<string>::iterator iter8;
            for(iter8 = todas_ventas_b.begin(); iter8 != todas_ventas_b.end(); iter8++) {
                cout <<" " <<*iter8 << endl;
            }
            system("pause");
        }
        break;
        case 14: {
            limpiar_pantalla();

            if(todas_ventas_a.size() > todas_ventas_b.size()) {
                cout <<"El vendedor A ha vendido mas frutas: " <<todas_ventas_a.size()<<endl;
            } else if(todas_ventas_a.size()< todas_ventas_b.size()) {
                cout <<"El vendedor B ha vendido mas frutas: " <<todas_ventas_b.size()<<endl;
            } else
                cout <<"Ambos vendedores han vendido la misma cantidad" <<endl;
            system("pause");
        }
        break;
        case 15: {
            limpiar_pantalla();
            int ventas=todas_ventas_a.size() + todas_ventas_b.size();
            cout <<"\nCantidad de frutas A Y B FUERON\n "<< ventas<<"\n ";

            system("pause");
        }
        break;
        case 16: {

            limpiar_pantalla();
            int ventas_a = todas_ventas_a.size();
            int ventas_b = todas_ventas_b.size();
            int ventas_totales = ventas_a + ventas_b;
            float resultado_porciento_a = 0;
            float resultado_porciento_b = 0;

            cout <<"\nTotal de ventas \n "<< ventas_totales<<endl;
            if(ventas_a > 0 ) {
                resultado_porciento_a = ventas_a / ventas_totales;
                cout<<"A) Ventas totales: " << ventas_a << ". porciento ventas : " << resultado_porciento_a * 100 <<endl;
            }

            if(ventas_b > 0 ) {
                resultado_porciento_b = ventas_b / ventas_totales;
                cout<<"B) Ventas totales: " <<ventas_b<< ". porciento ventas : " << resultado_porciento_b * 100 <<endl;
            }

            system("pause");
        }
        break;

        }
    } while(opcion!=0);

    cin.get();
    cin.get();

    return 0;
}
