#include <iostream>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;
const int MOD1=171,MOD2=181,MOD3=191;
struct HashValue
{
    int h1,h2,h3;
    HashValue()
    {
    }
    HashValue(int _h1,int _h2,int _h3):h1(_h1),h2(_h2),h3(_h3)
    {
    }
    bool operator<(const HashValue& b)const
    {
        if (h1!=b.h1)
            return h1<b.h1;
        if (h2!=b.h2)
            return h2<b.h2;
        return h3<b.h3;
    }
};
struct Tree
{
    set<HashValue> children;
    Tree()
    {
    }
    HashValue hash()
    {
        HashValue ret(1,1,1);
        for (set<HashValue>::iterator it=children.begin();it!=children.end();it++)
        {
            ret.h1=ret.h1*MOD1+it->h1;
            ret.h2=ret.h2*MOD2+it->h2;
            ret.h3=ret.h3*MOD3+it->h3;
        }
        return ret;
    }
};
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        stack<Tree> st;
        cin>>n;
        while (n--)
        {
            string op;
            cin>>op;
            if (op=="PUSH")
                st.push(Tree());
            else if (op=="DUP")
                st.push(st.top());
            else if (op=="UNION")
            {
                Tree t1=st.top();
                st.pop();
                Tree t2=st.top();
                st.pop();
                Tree t3;
                set_union(t1.children.begin(),t1.children.end(),t2.children.begin(),t2.children.end(),inserter(t3.children,t3.children.begin()));
                st.push(t3);
            }
            else if (op=="INTERSECT")
            {
                Tree t1=st.top();
                st.pop();
                Tree t2=st.top();
                st.pop();
                Tree t3;
                set_intersection(t1.children.begin(),t1.children.end(),t2.children.begin(),t2.children.end(),inserter(t3.children,t3.children.begin()));
                st.push(t3);
            }
            else if (op=="ADD")
            {
                Tree t1=st.top();
                st.pop();
                Tree t2=st.top();
                st.pop();
                t2.children.insert(t1.hash());
                st.push(t2);
            }
            cout<<st.top().children.size()<<endl;
        }
        cout<<"***"<<endl;
    }
    return 0;
}
