#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct state;
queue<state> q;
const int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
int n,m,dist[26][26][26][26];
char mp[26][26];
struct state
{
	int ra,ca,rg,cg,steps;
	state(int _ra,int _ca,int _rg,int _cg,int _s){ra=_ra;ca=_ca;rg=_rg;cg=_cg;steps=_s;}
	void expand()
	{
		int i;
		for (i=1;i<=4;i++)
		{
			int oax=ra+dx[i],oay=ca+dy[i];
			if (oax>0&&oax<=n&&oay>0&&oay<=m&&mp[oax][oay]!='X')
			{
				int ogx=rg,ogy=cg;
				if (oay<ogy&&mp[ogx][ogy-1]!='X')
					ogy--;
				else if (ogy<oay&&mp[ogx][ogy+1]!='X')
					ogy++;
				else if (oax<ogx&&mp[ogx-1][ogy]!='X')
					ogx--;
				else if (ogx<oax&&mp[ogx+1][ogy]!='X')
					ogx++;
				if (ogx>0&&ogx<=n&&ogy>0&&ogy<=m&&(oax!=ogx||oay!=ogy)&&dist[oax][oay][ogx][ogy]==-1||steps+1<dist[oax][oay][ogx][ogy])
				{
					q.push(state(oax,oay,ogx,ogy,steps+1));
					dist[oax][oay][ogx][ogy]=steps+1;
				}
			}
		}
	}
};
int main()
{
	int i,j,ax,ay,gx,gy,px,py;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	memset(dist,-1,sizeof(dist));
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			if (mp[i][j]=='A')
			{
				ax=i;
				ay=j;
			}
			if (mp[i][j]=='G')
			{
				gx=i;
				gy=j;
			}
			if (mp[i][j]=='P')
			{
				px=i;
				py=j;
			}
		}
	q.push(state(ax,ay,gx,gy,0));
	while (!q.empty())
	{
		state t=q.front();
		q.pop();
		if (t.ra==px&&t.ca==py)
		{
			printf("%d",t.steps);
			return 0;
		}
		t.expand();
	}
	printf("-1");
	return 0;
}
