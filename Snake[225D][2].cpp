#include <iostream>
#include <string.h>
#include <queue>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
struct state
{
	int x,y,mask;
};
int dist[16][16][70000],x[11],y[11],vst[16][16];
char mp[16][16];
const int dx[5]={0,-1,0,1,0},dy[5]={0,0,1,0,-1};
int getdir(int x1,int y1,int x2,int y2)
{
	if (x2==x1-1)
		return 0;
	if (y2==y1+1)
		return 1;
	if (x2==x1+1)
		return 2;
	if (y2==y1-1)
		return 3;
}
int main()
{
	int n,m,k=0,i,j,sx,sy,mask=0,tag=0,ans=1000000000,tx,ty;
	char t;
	queue<state> q;
	cin>>n>>m;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			cin>>t;
			mp[i][j]=(t=='#'||t=='@'?t:'.');
			if (t>='1'&&t<='9')
			{
				x[t-'0']=i;
				y[t-'0']=j;
				k=max(k,t-'0');
				if (t=='1')
				{
					sx=i;
					sy=j;
				}
			}
			else if (t=='@')
			{
				tx=i;
				ty=j;
			}
		}
	for (i=1;i<k;i++)
		mask=(mask<<2)^getdir(x[i],y[i],x[i+1],y[i+1]);
	memset(dist,-1,sizeof(dist));
	dist[sx][sy][mask]=0;
	q.push((state){sx,sy,mask});
	mask=(1<<(((k-1)<<1)-1))^(1<<(((k-1)<<1)-2));
	while (!q.empty())
	{
		state f=q.front();
		q.pop();
		int tm=f.mask;
		x[1]=f.x;
		y[1]=f.y;
		vst[x[1]][y[1]]=++tag;
		for (i=2;i<=k;i++)
		{
			int dir=((f.mask&mask)>>(2*k-4))+1;
			f.mask<<=2;
			x[i]=x[i-1]+dx[dir];
			y[i]=y[i-1]+dy[dir];
			if (i!=k)
				vst[x[i]][y[i]]=tag;
		}
		for (i=1;i<=4;i++)
		{
			int ox=f.x+dx[i],oy=f.y+dy[i];
			if (ox&&ox<=n&&oy&&oy<=m&&mp[ox][oy]!='#'&&vst[ox][oy]!=tag)
			{
				state gen;
				gen.x=ox;
				gen.y=oy;
				gen.mask=(tm>>2)^(((i-1)^2)<<(k*2-4));
				if (dist[ox][oy][gen.mask]==-1)
				{
					q.push(gen);
					dist[ox][oy][gen.mask]=dist[x[1]][y[1]][tm]+1;
					if (mp[ox][oy]=='@')
					{
						cout<<dist[ox][oy][gen.mask];
						return 0;
					}
				}
			}
		}
	}
	for (i=0;i<1<<12;i++)
		if (~dist[tx][ty][i])
			ans=max(ans,dist[tx][ty][i]);
	cout<<(ans==1000000000?-1:ans);
	return 0;
}
