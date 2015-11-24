#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
char mp[1001][1001];
int dist[1001][1001],dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
queue<pair<int,int> > q;
int main()
{
	int n,m,i,j,d,ans=0;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(dist,-1,sizeof(dist));
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			if (mp[i][j]=='E')
			{
				q.push(make_pair(i,j));
				dist[i][j]=0;
			}
		}
	while (!q.empty())
	{
		pair<int,int> f=q.front();
		q.pop();
		for (i=1;i<=4;i++)
		{
			int ox=f.first+dx[i],oy=f.second+dy[i];
			if (ox>0&&ox<=n&&oy>0&&oy<=m&&mp[ox][oy]!='T'&&dist[ox][oy]==-1)
			{
				dist[ox][oy]=dist[f.first][f.second]+1;
				if (mp[ox][oy]=='S')
					d=dist[ox][oy];
				q.push(make_pair(ox,oy));
			}
		}
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (dist[i][j]!=-1&&dist[i][j]<=d&&mp[i][j]>='0'&&mp[i][j]<='9')
				ans+=mp[i][j]-'0';
	cout<<ans;
	return 0;
}
