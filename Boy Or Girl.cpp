#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    string s;
    cin>>s;
    set<char> e;
    int i;
    for (i=0;i<s.size();i++)
        e.insert(s[i]);
    if (e.size()%2) cout<<"IGNORE HIM!"; else cout<<"CHAT WITH HER!";
    return 0;
}
