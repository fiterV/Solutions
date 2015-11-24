#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    cin>>a;
    long long r=0;
    int c,i;
    for (i=0;i<a.size();i++)
        if (a[i]=='^') c=i;
    for (i=0;i<a.size();i++)
        if (a[i]!='=') r+=(c-i)*(a[i]-48);
    if (r>0) cout<<"left"; else if (r) cout<<"right"; else cout<<"balance";
    return 0;
}
