#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <stdio.h>
#include <string.h>
#define abs(a) ((a)>0?(a):-(a))
#define sgn(a) ((a)?(a)>0?1:-1:0)
#define divide(a,b) (sgn((a)/(b))*abs(a)/abs(b))
#define mod(a,b) (sgn((a)%(b))*(abs(a)%abs(b)))
using namespace std;
map<string,string> def;
string getPar(string src)
{
    return def.count(src)?def[src]=getPar(def[src]):src;
}
string tolower(string a)
{
    string ret=a;
    for (int i=0;i<(int)ret.size();i++)
        if (ret[i]>='A'&&ret[i]<='Z')
            ret[i]+='a'-'A';
    return ret;
}
int GetValue(const string& a)
{
    string tmp=getPar(a);
    if (tmp[0]>='0'&&tmp[0]<='9')
    {
        int ret;
        sscanf(a.c_str(),"%d",&ret);
        return ret;
    }
    else
        return 0;
}
string ToString(int a)
{
    char ret[15];
    sprintf(ret,"%d",a);
    return ret;
}
int GetPriority(string a)
{
    if (a=="#")
        return 5;
    if (a=="^")
        return 4;
    if (a=="*"||a=="/"||a=="%")
        return 3;
    if (a=="+"||a=="-")
        return 2;
    if (a=="(")
        return 1;
    return 1<<30;
}
int fast_pow(int a,int b)
{
    if (b==0)
        return 1;
    else
    {
        int tmp=fast_pow(a,b>>1);
        return (b&1?a:1)*tmp*tmp;
    }
}
int CalculateExpression(string a)
{
    vector<string> suffix;
    stack<string> st1;
    bool first;
    string sign;
    a="("+a+")";
    for (int pos=0;pos<(int)a.size();pos++)
        if ((a[pos]>='a'&&a[pos]<='z')||(a[pos]>='0'&&a[pos]<='9'))
        {
            int tpos=pos;
            while (pos<(int)a.size()&&((a[pos]>='a'&&a[pos]<='z')||(a[pos]>='0'&&a[pos]<='9')))
                pos++;
            suffix.push_back(ToString(GetValue(a.substr(tpos,pos-tpos))));
            pos--;
            if (sign!="")
            {
                suffix.push_back(sign);
                sign="";
            }
            first=false;
        }
        else if (a[pos]=='(')
        {
            st1.push("(");
            first=true;
        }
        else if (a[pos]==')')
        {
            while (st1.top()!="(")
            {
                suffix.push_back(st1.top());
                st1.pop();
            }
            st1.pop();
        }
        else if ((a[pos]=='+'||a[pos]=='-')&&first)
            sign=a[pos]=='+'?"":"#";
        else
        {
            if (!st1.empty()&&GetPriority(a.substr(pos,1))<GetPriority(st1.top()))
            {
                suffix.push_back(st1.top());
                st1.pop();
            }
            st1.push(a.substr(pos,1));
            first=true;
        }
    stack<int> st2;
    for (int idx=0;idx<(int)suffix.size();idx++)
    {
        string c=suffix[idx];
        if (c[0]>='0'&&c[0]<='9')
            st2.push(GetValue(c));
        else
        {
            int v1=st2.top();
            st2.pop();
            if (c=="#")
                st2.push(-v1);
            else
            {
                int v2=st2.top();
                st2.pop();
                if (c=="^")
                    st2.push(fast_pow(v2,v1));
                else if (c=="*")
                    st2.push(v2*v1);
                else if (c=="/")
                    st2.push(divide(v2,v1));
                else if (c=="%")
                    st2.push(mod(v2,v1));
                else if (c=="+")
                    st2.push(v2+v1);
                else if (c=="-")
                    st2.push(v2-v1);
            }
        }
    }
    return st2.top();
}
int main()
{
    string op;
    while (cin>>op)
        if (op=="define")
        {
            string s1,s2;
            cin>>s1>>s2;
            s1=tolower(s1);
            s2=tolower(s2);
            if (!def.count(s1)&&getPar(s2)!=s1)
                def[s1]=s2;
        }
        else
        {
            string exp;
            cin>>exp;
            cout<<CalculateExpression(tolower(exp))<<endl;
        }
    return 0;
}
