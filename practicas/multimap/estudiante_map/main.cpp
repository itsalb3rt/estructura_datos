#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string,string>map1;

    map1.insert(make_pair("100166816","Albert Hidalgo")); //Key Value
    map1.insert(make_pair("100297867","Yanibel Gutierrez"));

    cout<<"100166816 " <<map1["100166816"] <<endl;

    return 0;
}
