#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
map<string,int> mp;
map<int,string> ins;
vector<string> str;
bool cd[16][16];
int cnt(int k)
{
	int t=0;
	while (k)
	{
		t+=k%2;
		k/=2;
	}
	return t;
}
int main()
{
	int n,m,i,j,ans=0,stt;
	string t1,t2;
	bool f;
	cin>>n>>m;
	for (i=0;i<n;i++)
	{
		cin>>t1;
		mp[t1]=i;
		ins[i]=t1;
	}
	for (i=0;i<m;i++)
	{
		cin>>t1>>t2;
		cd[mp[t1]][mp[t2]]=cd[mp[t2]][mp[t1]]=true;
	}
	for (stt=0;stt<(1<<n);stt++)
	{
		if (cnt(stt)<=cnt(ans))
			continue;
		f=true;
		for (i=0;i<n-1;i++)
			for (j=i+1;j<n;j++)
				if ((stt&(1<<i))&&(stt&(1<<j))&&cd[i][j])
					f=false;
		if (f)
			ans=stt;
	}
	cout<<cnt(ans)<<endl;
	for (i=0;i<n;i++)
		if (ans&(1<<i))
			str.push_back(ins[i]);
	sort(str.begin(),str.end());
	for (i=0;i<str.size();i++)
		cout<<str[i]<<endl;
	return 0;
}
