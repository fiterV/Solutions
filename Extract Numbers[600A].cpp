#include <iostream>
#include <vector>
using namespace std;
void print(const vector<string>& src)
{
    if ((int)src.size()==0)
        cout<<'-'<<endl;
    else
    {
        cout<<"\"";
        for (int i=0;i<(int)src.size();i++)
            cout<<src[i]<<(i==(int)src.size()-1?"":",");
        cout<<"\""<<endl;
    }
}
int main()
{
    string s;
    vector<string> seq,seq1,seq2;
    int lastpos=-1;
    cin>>s;
    s+=',';
    for (int i=0;i<(int)s.size();i++)
        if (s[i]==','||s[i]==';')
        {
            seq.push_back(s.substr(lastpos+1,i-lastpos-1));
            lastpos=i;
        }
    for (int i=0;i<(int)seq.size();i++)
    {
        int j;
        for (j=0;j<(int)seq[i].size();j++)
            if (seq[i][j]<'0'||seq[i][j]>'9')
                break;
        if (seq[i]!=""&&j==(int)seq[i].size()&&seq[i][0]!='0'||seq[i]=="0")
            seq1.push_back(seq[i]);
        else
            seq2.push_back(seq[i]);
    }
    print(seq1);
    print(seq2);
    return 0;
}
