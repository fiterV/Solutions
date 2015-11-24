#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
int mnt[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int val(string a)
{
    int ret;
    sscanf(a.c_str(),"%d",&ret);
    return ret;
}
bool iscurrent(string date)
{
    int day=val(date.substr(0,2)),month=val(date.substr(3,2)),year=val(date.substr(6));
    return date[0]>='0'&&date[0]<='9'&&date[1]>='0'&&date[1]<='9'&&date[2]=='-'&&
    date[3]>='0'&&date[3]<='9'&&date[4]>='0'&&date[4]<='9'&&date[5]=='-'&&
    date[6]>='0'&&date[6]<='9'&&date[7]>='0'&&date[7]<='9'&&date[8]>='0'&&
    date[8]<='9'&&date[9]>='0'&&date[9]<='9'&&month>=1&&month<=12&&day>=1&&day<=mnt[month]&&
    year>=2013&&year<=2015;
}
int main()
{
    string s,ans;
    map<string,int> mp;
    cin>>s;
    for (int i=0;i<s.size()-9;i++)
        if (iscurrent(s.substr(i,10)))
            mp[s.substr(i,10)]++;
    for (map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
        if (ans==""||mp[ans]<it->second)
            ans=it->first;
    cout<<ans;
    return 0;
}
