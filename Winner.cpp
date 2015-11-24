#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
pair<string,int> bak[1001];
map<string,int> mp;
set<string> s;
int main()
{
	int n,i,mx=-100000000;
	map<string,int>::iterator it;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>bak[i].first>>bak[i].second;
		mp[bak[i].first]+=bak[i].second;
	}
	for (it=mp.begin();it!=mp.end();it++)
		if (it->second>mx)
		{
			mx=it->second;
			s.clear();
			s.insert(it->first);
		}
		else if (it->second==mx)
			s.insert(it->first);
	mp.clear();
	for (i=1;i<=n;i++)
		if (s.count(bak[i].first))
		{
			mp[bak[i].first]+=bak[i].second;
			if (mp[bak[i].first]>=mx)
			{
				cout<<bak[i].first;
				return 0;
			}
		}
}
