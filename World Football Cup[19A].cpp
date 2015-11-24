#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;
map<string,int> ftm,jsq,sq;
pair<int,pair<int,pair<int,string> > > p[51];
string win[26];
int main()
{
	int n,i,s1,s2;
	string t,t1,t2,y;
	char x;
	map<string,int>::iterator it;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>t;
		ftm[t]=0;
		jsq[t]=0;
		sq[t]=0;
	}
	for (i=1;i<=(n*(n-1)/2);i++)
	{
		cin>>t;
		t1=t.substr(0,t.find_first_of('-'));
		t2=t.substr(t.find_first_of('-')+1);
		cin>>t;
		s1=atoi(t.substr(0,t.find_first_of(':')).c_str());
		s2=atoi(t.substr(t.find_first_of(':')+1).c_str());
		if (s1>s2)
			ftm[t1]+=3;
		else if (s1==s2)
		{
			ftm[t1]+=1;
			ftm[t2]+=1;
		}
		else
			ftm[t2]+=3;
		jsq[t1]+=s1;
		jsq[t1]-=s2;
		jsq[t2]-=s1;
		jsq[t2]+=s2;
		sq[t1]+=s1;
		sq[t2]+=s2;
	}
	for (it=ftm.begin(),i=1;it!=ftm.end();it++,i++)
	{
		p[i].first=it->second;
		p[i].second.second.second=it->first;
	}
	for (it=jsq.begin(),i=1;it!=jsq.end();it++,i++)
		p[i].second.first=it->second;
	for (it=sq.begin(),i=1;it!=sq.end();it++,i++)
		p[i].second.second.first=it->second;
	sort(p+1,p+n+1);
	for (i=n/2+1;i<=n;i++)
		win[i-n/2]=p[i].second.second.second;
	sort(win+1,win+n/2+1);
	for (i=1;i<=n/2;i++)
		cout<<win[i]<<endl;
	return 0;
}
