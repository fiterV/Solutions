#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct team
{
	string name;
	int scr,jsq,sq;
};
team t[51];
int n;
void add(const string &s,int src,int mis)
{
	int i;
	for (i=1;i<=n;i++)
		if (t[i].name==s)
		{
			if (src>mis)
				t[i].scr+=3;
			else if (src==mis)
				t[i].scr+=1;
			t[i].jsq+=src-mis;
			t[i].sq+=src;
			return;
		}
}
bool cmp(team a,team b)
{
	return a.scr>b.scr||a.scr==b.scr&&a.jsq>b.jsq||a.scr==b.scr&&a.jsq==b.jsq&&a.sq>b.sq;
}
bool lux(team a,team b)
{
	return a.name<b.name;
}
int main()
{
	int i,s1,s2;
	string s,t1,t2;
	cin>>n;
	for (i=1;i<=n;i++)
		cin>>t[i].name;
	for (i=1;i<=n*(n-1)/2;i++)
	{
		cin>>s;
		t1=s.substr(0,s.find_first_of('-'));
		t2=s.substr(s.find_first_of('-')+1);
		cin>>s;
		s1=atoi(s.substr(0,s.find_first_of(':')).c_str());
		s2=atoi(s.substr(s.find_first_of(':')+1).c_str());
		add(t1,s1,s2);
		add(t2,s2,s1);
	}
	sort(t+1,t+n+1,cmp);
	sort(t+1,t+n/2+1,lux);
	for (i=1;i<=n/2;i++)
		cout<<t[i].name<<endl;
	return 0;
}
