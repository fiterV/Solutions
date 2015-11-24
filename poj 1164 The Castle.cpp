#include <stdio.h>
#define max(a,b) (a>b?a:b)
bool adjr[52][52],adjc[52][52],vst[52][52];
int cnt,n,m,mp[2501];
void dfs(int x,int y)
{
	if (x&&y&&x<=n&&y<=m)
	{
		vst[x][y]=true;
		mp[cnt]++;
		if (!adjr[x][y]&&!vst[x-1][y])
			dfs(x-1,y);
		if (!adjc[x][y+1]&&!vst[x][y+1])
			dfs(x,y+1);
		if (!adjr[x+1][y]&&!vst[x+1][y])
			dfs(x+1,y);
		if (!adjc[x][y]&&!vst[x][y-1])
			dfs(x,y-1);
	}
}
int main()
{
	int i,j,t,mx=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			scanf("%d",&t);
			adjc[i][j]|=t&1;
			adjr[i][j]|=t&2;
			adjc[i][j+1]|=t&4;
			adjr[i+1][j]|=t&8;
		}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (!vst[i][j])
			{
				cnt++;
				dfs(i,j);
			}
	printf("%d\n",cnt);
	for (i=1;i<=cnt;i++)
		mx=max(mx,mp[i]);
	printf("%d",mx);
	return 0;
}
