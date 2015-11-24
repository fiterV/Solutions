#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int c;
    c=a.find("WUB");
    while (c!=-1)
    {
          a.replace(c,3," ");
          c=a.find("WUB");
    }
    c=a.find("  ");
    while (c!=-1)
    {
          a.replace(c,2," ");
          c=a.find("  ");
    }
    if (a[0]==' ') a=a.substr(1);
    if (a[(int)a.size()-1]==' ') a=a.substr(0,(int)a.size()-1);
    cout<<a<<endl;
    return 0;
}
