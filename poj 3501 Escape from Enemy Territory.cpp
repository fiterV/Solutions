#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int x,y,xi,yi,xr,yr,dist[1001][1001],dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0},len[1001][1001];
int check(int dis)
{
	int i;
	queue<pair<int,int> > q;
	memset(len,-1,sizeof(len));
	len[xi][yi]=0;
	q.push(make_pair(xi,yi));
	while (!q.empty())
	{
		pair<int,int> f=q.front();
		q.pop();
		if (f.first==xr&&f.second==yr)
			return len[xr][yr];
		for (i=1;i<=4;i++)
		{
			int ox=f.first+dx[i],oy=f.second+dy[i];
			if (ox>0&&ox<=x&&oy>0&&oy<=y&&len[ox][oy]==-1&&dist[ox][oy]>=dis)
			{
				q.push(make_pair(ox,oy));
				len[ox][oy]=len[f.first][f.second]+1;
			}
		}
	}
	return len[xr][yr];
}
int main()
{
	int tc,n,i,t1,t2,l,r,m;
	scanf("%d",&tc);
	while (tc--)
	{
		queue<pair<int,int> > q;
		scanf("%d%d%d%d%d%d%d",&n,&x,&y,&xi,&yi,&xr,&yr);
		xi++;yi++;xr++;yr++;
		memset(dist,-1,sizeof(dist));
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&t1,&t2);
			q.push(make_pair(t1+1,t2+1));
			dist[t1+1][t2+1]=0;
		}
		while (!q.empty())
		{
			pair<int,int> f=q.front();
			q.pop();
			for (i=1;i<=4;i++)
			{
				int ox=f.first+dx[i],oy=f.second+dy[i];
				if (ox>0&&ox<=x&&oy>0&&oy<=y&&dist[ox][oy]==-1)
				{
					q.push(make_pair(ox,oy));
					dist[ox][oy]=dist[f.first][f.second]+1;
				}
			}
		}
		l=0;
		r=x+y;
		while (l+1<r)
		{
			m=(l+r)/2;
			if (check(m)==-1)
				r=m;
			else
				l=m;
		}
		printf("%d %d\n",l,check(l));
	}
	return 0;
}
