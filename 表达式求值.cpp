#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;
int priority[256];
int val(string a)
{
    int ret;
    sscanf(a.c_str(),"%d",&ret);
    return ret;
}
int main()
{
    int i;
    string a,partstr;
    cin>>a;
    stack<string> st1;
    vector<string> suffix;
    priority['+']=1;
    priority['*']=2;
    for (i=0;i<(int)a.size();i++)
        if (a[i]>='0'&&a[i]<='9')
            partstr+=a.substr(i,1);
        else
        {
            suffix.push_back(partstr);
            partstr="";
            if (!st1.empty()&&priority[(int)a[i]]<=priority[(int)st1.top()[0]])
            {
                suffix.push_back(st1.top());
                st1.pop();
            }
            st1.push(a.substr(i,1));
        }
    if (partstr!="")
        suffix.push_back(partstr);
    while (!st1.empty())
    {
        suffix.push_back(st1.top());
        st1.pop();
    }
    stack<int> st2;
    for (i=0;i<(int)suffix.size();i++)
        if (suffix[i]=="+"||suffix[i]=="*")
        {
            int t1=st2.top();
            st2.pop();
            int t2=st2.top();
            st2.pop();
            if (suffix[i]=="+")
                st2.push((t2+t1)%10000);
            else
                st2.push((t2*t1)%10000);
        }
        else
            st2.push(val(suffix[i]));
    cout<<st2.top();
    return 0;
}
