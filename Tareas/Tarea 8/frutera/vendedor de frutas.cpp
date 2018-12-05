//programa de dos vendedores de frutas
//HENCH POR:HENDY TINEO
//FECHA: 01/05/14
 #include <iostream> 
 #include <string>            //Plantila estandar para los string
 #include <set>               //Plantila estandar set

using  namespace  std ; 

class VenFru{
      private:
             //INICIO
             int lSegEnt;

             //Uso de set
             string         Nombre;
             set<string>    Set1;      
             set<string>    Set2;      
             set<string>    Set3;
             set<string>    Set4;
             set<string>    Set5;
             set<string>    Set6;
             set<string>    Set7;
             set<string>    Set8;
             string A,B,VA,VB; 
       public:  
                   
void Menu(){
             
             int cont=0,cont1=0,cont2=0,cont3=0,venta,opc,op,op1,op2,op3,op4,op5,op6;
             //Union
       
       
             Set1.insert("Mango");
             Set1.insert("Manzana");
             Set1.insert("Pera");
             Set1.insert("Uva");
             Set1.insert("Zapote"); 
             Set1.insert("Melon"); 
             Set1.insert("Aguacate"); 
             Set1.insert("Nipero"); 
     
             Set2.insert("Manzana");
             Set2.insert("Uva");
             Set2.insert("Limon");
             Set2.insert("Pina");
             Set2.insert("Lechoza"); 
             Set1.insert("Aguacate"); 
             Set1.insert("Nipero");   
     
      do{
              cout <<"\n\n\t<<<<<<<<< MENU DE VENTAS >>>>>>>>>";
              cout <<"\n\n\tDigine la Opcion: #1  Para Asignar fruta al vendedor A";
              cout <<"\n\n\tDigine la Opcion: #2  Para Asignar fruta al vendedor B";
              cout <<"\n\n\tDigine la Opcion: #3  Para Ver nombre de frutas vendedor A";
              cout <<"\n\n\tDigine la Opcion: #4  Para Ver nombre de frutas vendedor B";
              cout <<"\n\n\tDigine la Opcion: #5  Para Ver cantidad de frutas vendita por A";
              cout <<"\n\n\tDigine la Opcion: #6  Para Ver cantidad de frutas vendita por B";
              cout <<"\n\n\tDigine la Opcion: #7  Para Ver cantidad de frutas que vende A Y B";
              cout <<"\n\n\tDigine la Opcion: #8  Para Ver fruta que vende A Y B NO";
              cout <<"\n\n\tDigine la Opcion: #9  Para Ver fruta que vende B Y A NO";
              cout <<"\n\n\tDigine la Opcion: #10 Para Comprar frutas que vende A  ";
              cout <<"\n\n\tDigine la Opcion: #11 Para Comprar frutas que vende B  ";
              cout <<"\n\n\tDigine la Opcion: #12 Ver frutas vendida por A  ";
              cout <<"\n\n\tDigine la Opcion: #13 Ver frutas vendida por B  ";
              cout <<"\n\n\tDigine la Opcion: #14 Ver quien vendio mas frutas  ";
              cout <<"\n\n\tDigine la Opcion: #15 Ver cuantas frutas vendieron entre los dos";
              cout <<"\n\n\tDigine la Opcion: #0  Para SALIR: ";
        
        cin >> opc;
       
       
       
       if(opc==1){//1
          while(op!=0){
               cout <<"\n\tASIGNE FRUTAS PARA VENDEDOR A ";              
               cin>> A;
               Set1.insert( A);
               cout <<"\n\tPULSE #0 PARA SALIR: ";
               cin>> op;                      
            
                  }
                  } //1

     if(opc==2){//2
       while(op1!=0){
              cout <<"\n\tASIGNE FRUTAS PARA VENDEDOR B: ";              
              cin>> B;
              cout <<"\n\tPULSE #0 PARA SALIR: ";
              cin>> op1;                      
                Set2.insert( B);          
                  }op1=2;
                  }//2
    if(opc==3){//3
               system("cls");//system("color a2");
               cout <<"\n\n\tLAS FRUTAS QUE VENDE EL VENDEDORA A\n";
               set<string>::iterator iter4;    
       for(iter4 = Set1.begin(); iter4!= Set1.end(); iter4++) 
               {cont++; cout <<"\t"<<cont<<"-"<< *iter4 << endl;  }
              cout <<"\n\n\n";
              system("pause");
                  }
    if(opc==4){//4
              system("cls");//system("color a2");
              cout <<"\n\n\tLAS FRUTAS QUE VENDE EL VENDEDORA B\n";
             set<string>::iterator iter5;    
       for(iter5 = Set2.begin(); iter5!= Set2.end(); iter5++) 
             { cont1++; cout <<"\t"<<cont1<<"-"<< *iter5 << endl;  }
             cout <<"\n\n\n";
             system("pause");
                  }//4      
                    
     if(opc==5){//5
                system("cls");
                 cout <<"\n\n\tNUMERO DE FRUTA QUE VENDE A\n\n";
                 set<string>::iterator iter1; 
          for(iter1 = Set1.begin(); iter1 != Set1.end(); iter1++) {cont++;}//cuenta los #1
                cout <<"\t"<< cont << endl; cout <<"\n\n"; system("pause");}//5 
     if(opc==6){//6
                system("cls");
                cout <<"\n\n\tNUMERO DE FRUTA QUE VENDE B\n\n";
                set<string>::iterator iter2; 
           for(iter2 = Set2.begin(); iter2 != Set2.end(); iter2++) {cont1++;}//cuenta los #2
           
                   cout <<"\t"<< cont1 << endl; cout <<"\n\n"; system("pause");}//6
                   
     if(opc==7){//7
               system("cls");
              cout <<"\n\n\tNUMERO DE FRUTAS QUE VENDE A Y B\n\n";
              set<string>::iterator iter1; 
           for(iter1 = Set1.begin(); iter1 != Set1.end(); iter1++) {cont++;}//cuenta los #1
               set<string>::iterator iter2; 
           for(iter2 = Set2.begin(); iter2 != Set2.end(); iter2++) {cont1++;}//cuenta los #2
           
              cout <<"\t"<< cont1+cont << endl; cout <<"\n\n"; system("pause");}//7
              
   if(opc==8){//8
             system("cls");
              cout <<"\n\n\tFRUTAS QUE VENDE A  y  B NO LA VENDE\n\n";
                set_difference(Set1.begin(),Set1.end(),Set2.begin(),Set2.end(), inserter(Set3,Set3.begin()) );
                set<string>::iterator iter3;    
           for(iter3 = Set3.begin(); iter3 != Set3.end(); iter3++) 
                   {  cout <<"\t " <<*iter3 << endl; } system("pause");
           }//8        
              
   if(opc==9){//9
                 system("cls");
                   cout <<"\n\n\tFRUTAS QUE VENDE B  y  A NO LA VENDE\n\n";
                   set_difference(Set2.begin(),Set2.end(),Set1.begin(),Set1.end(), inserter(Set4,Set4.begin()) );
                   set<string>::iterator iter6;    
           for(iter6 = Set4.begin(); iter6 != Set4.end(); iter6++) 
                   {  cout <<"\t " <<*iter6 << endl; } system("pause");
           }//9 
  if(opc==10){//10
               while(op2!=0){ system("cls");//system("color b2");
                 cout <<"\n\n\tLAS FRUTAS QUE VENDE EL VENDEDORA A\n";
                 set<string>::iterator iter4;    
           for(iter4 = Set1.begin(); iter4!= Set1.end(); iter4++) 
               {cont++; cout <<"\t"<<cont<<"-"<< *iter4 << endl;  }
               cout <<"\n\tCOMPRAR FRUTA VENDEDOR A ";              
               cin>> VA;
               Set5.insert( VA);    
               cout <<"\n\tPULSE #0 PARA SALIR: ";
               cin>> op2; cont2++;
                  }  
                   } //op2=1;//10   
             
  if(opc==11){//11
               while(op3!=0){ system("cls");//system("color b2");
                   cout <<"\n\n\tLAS FRUTAS QUE VENDE EL VENDEDORA B\n";
                set<string>::iterator iter5;    
           for(iter5 = Set2.begin(); iter5!= Set2.end(); iter5++) 
                { cont1++; cout <<"\t"<<cont1<<"-"<< *iter5 << endl;  }
                 cout <<"\n\tCOMPRAR FRUTA VENDEDOR B ";              
                 cin>> VB;
                Set6.insert( VB); 
                    cout <<"\n\tPULSE #0 PARA SALIR: ";
               cin>> op3; cont3++;           
            
                  }  
                   } op3=1;//11   
                                                                                           
  if(opc==12){//12 
                            
               system("cls");
               cout <<"\n\tFRUTAS VENDIDAS POR A\n ";  
               set_difference(Set1.begin(),Set1.end(),Set5.begin(),Set5.end(), inserter(Set7,Set7.begin()) );
               set<string>::iterator iter7;    
           for(iter7 = Set5.begin(); iter7 != Set5.end(); iter7++) 
                   {  cout <<"\t " <<*iter7 << endl; } system("pause"); 
                            } //12 
  if(opc==13){//13 
                            
               system("cls");
               cout <<"\n\tFRUTAS VENDIDAS POR B\n ";  
               set_difference(Set2.begin(),Set2.end(),Set6.begin(),Set6.end(), inserter(Set7,Set7.begin()) );
               set<string>::iterator iter8;    
           for(iter8 = Set6.begin(); iter8 != Set6.end(); iter8++) 
                   {  cout <<"\t " <<*iter8 << endl; } system("pause"); 
                            } //13  
                            
                            
     if(opc==14){//14 
                    system("cls");
               if(cont2>cont3){  cout <<"\n\tEL VENDEDOR A VENDIO MAS FRUTAS\n"; }else 
               if(cont2<cont3) {cout <<"\n\tEL VENDEDOR B VENDIO MAS FRUTAS\n "; }else 
               cout <<"\n\tEL VENDEDOR B Y A VENDIERON LA MISMA CANTIDAD\n ";
                  system("pause"); }//14                       
                            
   if(opc==15){//15
                 system("cls");
                venta=cont2+cont3;
            cout <<"\n\tLAS CANTIDAD DE  FRUTAS VENDIDAS POR A Y B FUERON\n\t "<< venta<<"\n "; 
                   
                           system("pause");  }//15                              
                              
                   
           cont1=0;cont=0;                
        }while(opc!=0);
        
        cin.get(); //   getch();
        cin.get(); //   getch();
          } //INICIO
 
            
};
main(){
       VenFru ov;
       ov.Menu();
       
       }
