#include <cstdio>
#include <iostream>
using namespace std;
int cnt,k,a[502][502],dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1},m,n;
char c[502][502];
void dfs(int x,int y)
{
	int i;
	if (x<1||x>n||y<1||y>m||c[x][y]!='.'||a[x][y])
		return;
	a[x][y]=++cnt;
	for (i=1;i<=4;i++)
		dfs(x+dx[i],y+dy[i]);
}
int main()
{
	int i,j;
	bool f=false;
	cin>>n>>m>>k;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			cin>>c[i][j];
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
			if (c[i][j]=='.')
			{
				dfs(i,j);
				f=true;
				break;
			}
		if (f)
			break;
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
			if (c[i][j]=='.'&&a[i][j]>cnt-k)
			{
				cout<<'X';
			}
			else
				cout<<c[i][j];
		cout<<endl;
	}
	return 0;
}
