#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
map<string,int> mp;
set<int> s[17];
int ans,cur,n,chs,st;
string nm[17];
void dfs(int k)
{
	int i;
	bool can=true;
	if (k>n)
	{
		if (cur>ans)
		{
			chs=st;
			ans=cur;
		}
		return;
	}
	for (i=1;i<=k;i++)
		if ((st&(1<<(i-1)))&&s[k].count(i))
		{
			can=false;
			break;
		}
	if (can)
	{
		st|=1<<(k-1);
		cur++;
		dfs(k+1);
	}
	cur--;
	st^=1<<(k-1);
	dfs(k+1);
}
int main()
{
	int m,i;
	string t1,t2;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>nm[i];
		mp[nm[i]]=i;
	}
	for (i=1;i<=m;i++)
	{
		cin>>t1>>t2;
		s[mp[t1]].insert(mp[t2]);
		s[mp[t2]].insert(mp[t1]);
	}
	dfs(1);
	cout<<ans<<endl;
	for (i=1;i<=n;i++)
		if (chs&(1<<(i-1)))
			cout<<nm[i]<<endl;
	return 0;
}
