#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<string> > ans;
map<string,int> id;
string _tolower(string src)
{
    string ret=src;
    for (int i=0;i<ret.size();i++)
        if (ret[i]>='A'&&ret[i]<='Z')
            ret[i]+='a'-'A';
    return ret;
}
string produce(string src)
{
    string ret=_tolower(src);
    if (ret.size()>=10&&ret.substr(ret.size()-10)=="@bmail.com")
    {
        string tmp;
        bool f=false;
        for (int i=0;i<ret.size();i++)
        {
            if (ret[i]!='.'||f)
                tmp+=ret.substr(i,1);
            if (ret[i]=='@')
                f=true;
        }
        ret=tmp;
        if (ret.find('+')!=-1)
            ret=ret.substr(0,ret.find('+'))+ret.substr(ret.find('@'));
    }
    return ret;
}
int main()
{
    int n,i,j;
    string t;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>t;
        string tar=produce(t);
        if (id.count(tar))
            ans[id[tar]].push_back(t);
        else
        {
            ans.push_back(vector<string>());
            ans[ans.size()-1].push_back(t);
            id[tar]=ans.size()-1;
        }
    }
    cout<<ans.size()<<endl;
    for (i=0;i<ans.size();i++)
    {
        cout<<ans[i].size()<<" ";
        for (j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
