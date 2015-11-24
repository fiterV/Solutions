#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
queue<pair<int,int> > q;
int dist[2001][2001],dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
int main()
{
	int n,m,k,i,j,x,y,mxx,mxy,mxv=0;
	scanf("%d%d%d",&n,&m,&k);
	memset(dist,-1,sizeof(dist));
	for (i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		q.push(make_pair(x,y));
		dist[x][y]=0;
	}
	while (!q.empty())
	{
		pair<int,int> f=q.front();
		q.pop();
		for (i=1;i<=4;i++)
		{
			int ox=f.first+dx[i],oy=f.second+dy[i];
			if (ox&&ox<=n&&oy&&oy<=m&&dist[ox][oy]==-1)
			{
				dist[ox][oy]=dist[f.first][f.second]+1;
				q.push(make_pair(ox,oy));
			}
		}
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (dist[i][j]>mxv)
			{
				mxv=dist[i][j];
				mxx=i;
				mxy=j;
			}
	printf("%d %d",mxx,mxy);
	return 0;
}
