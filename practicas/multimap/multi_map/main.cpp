#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int,string>map1,map2;

    map1.insert(make_pair(1,"Albert"));
    map1.insert(make_pair(2,"Eduardo"));
    map2.insert(make_pair(3,"Yanibel"));
    map2.insert(make_pair(4,"Giant"));

    cout<<"map1 size: " <<map1.size() <<endl;
    cout<<"map2 size: " <<map2.size() <<endl;

    return 0;
}
