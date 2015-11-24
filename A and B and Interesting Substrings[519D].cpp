#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
vector<int> pos[26];
int val[26];
long long sm[100001];
int main()
{
	string s;
	int i,k,c,p;
	long long cnt=0;
	ios::sync_with_stdio(false);
	for (i=0;i<26;i++)
		cin>>val[i];
	cin>>s;
	for (i=0;i<(int)s.size();i++)
	{
		pos[s[i]-'a'].push_back(i);
		sm[i+1]=val[s[i]-'a']+sm[i];
	}
	for (k=0;k<26;k++)
	{
		map<long long,int> mp;
		for (c=0;c<(int)pos[k].size();c++)
		{
			p=pos[k][c];
			cnt+=mp[sm[p]];
			mp[sm[p+1]]++;
		}
	}
	cout<<cnt;
	return 0;
}
