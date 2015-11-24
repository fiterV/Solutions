#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define MAX_N 1000
using namespace std;
vector<int> adj[2*MAX_N+1];
int vst[2*MAX_N+1];
queue<int> mp;
int main()
{
	ios::sync_with_stdio(false);
	int n,m,i,j;
	char t;
	cin>>n>>m;
	memset(vst,-1,sizeof(vst));
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			cin>>t;
			if (t=='#')
			{
				adj[i].push_back(MAX_N+j);
				adj[MAX_N+j].push_back(i);
			}
		}
	mp.push(1);
	vst[1]=0;
	while (!mp.empty())
	{
		int a=mp.front();
		mp.pop();
		for (i=0;i<adj[a].size();i++)
			if (vst[adj[a][i]]==-1)
			{
				vst[adj[a][i]]=vst[a]+1;
				mp.push(adj[a][i]);
			}
	}
	if (vst[n]!=-1)
		cout<<vst[n];
	else
		cout<<-1;
	return 0;
}
