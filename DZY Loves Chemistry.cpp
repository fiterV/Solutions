#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[101];
bool vst[101];
void dfs(int k)
{
	int i;
	vst[k]=true;
	for (i=0;i<adj[k].size();i++)
		if (!vst[adj[k][i]])
			dfs(adj[k][i]);
}
int main()
{
	int n,m,i,x,y,cnt=0;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (i=1;i<=n;i++)
		if (!vst[i])
		{
			dfs(i);
			cnt++;
		}
	cout<<(1LL<<n-cnt);
	return 0;
}
