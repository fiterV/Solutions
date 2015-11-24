#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> splitstring(string src,string sp)
{
    int pos=0;
    vector<string> ret;
    while (src.find(sp,pos)!=-1)
    {
        int tmp=src.find(sp,pos);
        ret.push_back(src.substr(pos,tmp-pos));
        pos=tmp+sp.size();
    }
    if (pos<src.size())
        ret.push_back(src.substr(pos,src.size()-pos));
    return ret;
}
bool namecmp(const vector<string>& a,const vector<string>& b)
{
    int pos=0;
    while (true)
    {
        if (a[pos]!=b[pos])
            return a[pos]<b[pos];
        pos++;
    }
}
string parsename(string src)
{
    vector<string> res=splitstring(src," ");
    for (int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    cout<<endl;
    res.push_back("and");
    int pos=0,lastpos=-1,autcnt=0;
    vector<vector<string> > aut;
    while (pos<res.size())
    {
        if (res[pos]=="and")
        {
            aut.push_back(vector<string>());
            aut[autcnt].push_back(res[pos-1]);
            for (int i=lastpos+1;i<=pos-2;i++)
                aut[autcnt].push_back(res[i]);
            autcnt++;
            lastpos=pos;
        }
        pos++;
    }
    sort(aut.begin(),aut.end(),namecmp);
    string ret;
    for (int i=0;i<aut.size();i++)
    {
        ret+=aut[i][0]+" ";
        for (int j=1;j<aut[i].size();j++)
            ret+=aut[i][j].substr(0,1)+". ";
        if (ret[ret.size()-1]==' ')
            ret=ret.substr(0,ret.size()-1);
        ret+=", ";
    }
    ret=ret.substr(0,ret.size()-2);
    return ret;
}
struct object
{
    string type,answer;
    map<string,string> fields;
    void build()
    {
        string ret;
        ret+=parsename(fields["author"])+" "+fields["title"];
        if (type=="book")
        {
            if (fields.count("volume"))
                ret+=", Vol. "+fields["volume"];
            ret+=" -- "+fields["publisher"]+", "+fields["year"];
        }
        else if (type=="article")
        {
            ret+=" // "+fields["journal"];
            if (fields.count("volume"))
                ret+=", "+fields["volume"];
            if (fields.count("number"))
                ret+=" ("+fields["number"]+")";
            ret+=" -- "+fields["year"];
            if (fields.count("pages"))
                ret+=" -- "+fields["pages"];
        }
        answer=ret;
    }
};
object refs[101];
int main()
{
    string tmp;
    int curnum=0;
    freopen("bibtex.in","r",stdin);
    while (getline(cin,tmp))
    {
        curnum++;
        refs[curnum].type=tmp.substr(1);
        getline(cin,tmp);
        while (true)
        {
            getline(cin,tmp);
            if (tmp=="}")
                break;
            tmp=tmp.substr(4);
            if (tmp[tmp.size()-1]==',')
                tmp=tmp.substr(0,tmp.size()-1);
            tmp=tmp.substr(0,tmp.size()-1);
            int idx=tmp.find(" ");
            string fie=tmp.substr(0,idx),value=tmp.substr(idx+4);
            refs[curnum].fields[fie]=value;
        }
        refs[curnum].build();
    }
    for (int i=1;i<=curnum;i++)
        cout<<"["<<i<<"]"<<" "<<refs[i].answer<<endl;
    return 0;
}
