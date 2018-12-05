#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    set<int> set1;
    set<int> set2;
    set<int> set3;
    set<int> interseccion;
    set<int> diferencia;

    set1.insert(1);
    set1.insert(2);
    set1.insert(3);

    set2.insert(3);
    set2.insert(4);
    set2.insert(5);


    set<int>::iterator it;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),inserter(set3,set3.begin()));

    set<int>::iterator it2;
    cout<<"UNION" <<endl;
    for ( it2 = set3.begin(); it2 != set3.end(); ++it2 )
        cout<<*it2 <<",";

    //Interseccion
    cout<<endl;
    cout<<"INTERSECCION" <<endl;

    set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(interseccion,interseccion.begin()));

    set<int>::iterator it4;
    for ( it4 = interseccion.begin(); it4 != interseccion.end(); ++it4 )
        cout<<*it4;

    //diferencia
    cout<<endl;
    cout<<"DIFERENCIA" <<endl;
     set_difference(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(diferencia,diferencia.begin()));

    set<int>::iterator it5;
    for ( it5 = diferencia.begin(); it5 != diferencia.end(); ++it5 )
        cout<<*it5 <<" ";


    return 0;
}
