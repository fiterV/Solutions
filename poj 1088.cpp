#include <stdio.h>
#define max(a,b) (a>b?a:b)
int r,c,h[101][101],dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0},dp[101][101];
int dfs(int x,int y,int d)
{
	int i,ox,oy,rec=0;
	if (dp[x][y])
		return dp[x][y]+d;
	for (i=1;i<=4;i++)
	{
		ox=x+dx[i];
		oy=y+dy[i];
		if (ox&&oy&&ox<=r&&oy<=c&&h[ox][oy]>h[x][y])
			rec=max(rec,dfs(ox,oy,d)+1);
	}
	dp[x][y]=rec-d;
	return rec;
}
int main()
{
	int i,j,ans=0;
	scanf("%d%d",&r,&c);
	for (i=1;i<=r;i++)
		for (j=1;j<=c;j++)
			scanf("%d",&h[i][j]);
	for (i=1;i<=r;i++)
		for (j=1;j<=c;j++)
			ans=max(ans,dfs(i,j,1)+1);
	printf("%d",ans);
	return 0;
}
