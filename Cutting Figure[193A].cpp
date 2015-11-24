#include <stdio.h>
#include <string.h>
bool mp[51][51],vst[51][51];
int n,m;
void dfs(int x,int y)
{
	if (x<=0||x>n||y<=0||y>m||vst[x][y]||!mp[x][y])
		return;
	vst[x][y]=true;
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
}
bool isconnected()
{
	int i,j;
	bool f=false;
	memset(vst,false,sizeof(vst));
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
			if (mp[i][j])
			{
				dfs(i,j);
				f=true;
				break;
			}
		if (f)
			break;
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (mp[i][j]&&!vst[i][j])
				return false;
	return true;
}
int main()
{
	int i,j,cnt=0;
	char t;
	scanf("%d%d",&n,&m);
	getchar();
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			scanf("%c",&t);
			if (t=='#')
			{
				mp[i][j]=true;
				cnt++;
			}
		}
		getchar();
	}
	if (cnt<=2)
	{
		printf("-1");
		return 0;
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (mp[i][j])
			{
				mp[i][j]=false;
				if (!isconnected())
				{
					printf("1");
					return 0;
				}
				mp[i][j]=true;
			}
	printf("2");
	return 0;
}
