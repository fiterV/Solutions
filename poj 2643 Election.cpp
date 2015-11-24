#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string,string> mp1;
map<string,int> mp2;
int main()
{
	int n,m,i,mx=0;
	string s1,s2,wn;
	bool f=false;
	cin>>n;
	getchar();
	for (i=1;i<=n;i++)
	{
		getline(cin,s1);
		getline(cin,s2);
		mp1[s1]=s2;
		mp2[s1]=0;
	}
	cin>>m;
	getchar();
	for (i=1;i<=m;i++)
	{
		getline(cin,s1);
		mp2[s1]++;
		if (mp2[s1]>mx){mx=mp2[s1];f=true;wn=mp1[s1];}
		else if (mp2[s1]==mx) f=false;
	}
	if (f)
		cout<<wn;
	else
		cout<<"tie";
	return 0;
}
